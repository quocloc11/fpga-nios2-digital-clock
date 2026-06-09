#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "altera_avalon_timer_regs.h"
#include "altera_avalon_uart_regs.h"
#include "sys/alt_irq.h"
#include <stdio.h>

// ================= DỮ LIỆU THỜI GIAN =================
volatile int ss = 0, mm = 0, hh = 0;
volatile int DD = 1, MM = 1, YYYY = 2026;
int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// ================= CÁC BIẾN TRẠNG THÁI =================
volatile int toggle_1s = 0;
volatile int chaser_tick = 0;
volatile int chaser_pos = 0;
int set_time_submode = 0;

// ================= BÁO THỨC =================
volatile int alarm_hh = 0, alarm_mm = 0, alarm_ss = 0;
volatile int is_alarming = 0;

int uart_sw1 = 0, uart_sw2 = 0, uart_sw3 = 0;

unsigned char hex_lut[] = {
    0xC0, 0xF9, 0xA4, 0xB0, 0x99,
    0x92, 0x82, 0xF8, 0x80, 0x90
};
#define HEX_DASH 0xBF

// ================= HÀM UART =================
void uart_send_string(char *str) {
    int i = 0;
    while(str[i] != '\0') {
        while(!(IORD_ALTERA_AVALON_UART_STATUS(UART_0_BASE) & ALTERA_AVALON_UART_STATUS_TRDY_MSK));
        IOWR_ALTERA_AVALON_UART_TXDATA(UART_0_BASE, str[i]);
        i++;
    }
}

char uart_receive_char(void) {
    if (IORD_ALTERA_AVALON_UART_STATUS(UART_0_BASE) & ALTERA_AVALON_UART_STATUS_RRDY_MSK) {
        return (char)(IORD_ALTERA_AVALON_UART_RXDATA(UART_0_BASE) & 0xFF);
    }
    return 0;
}

// ================= HÀM LCD & TRỄ =================
void delay_ms(int ms) { volatile int i; for(i = 0; i < ms * 5000; i++); }
void delay_fast() { volatile int i; for(i = 0; i < 50; i++); }

void lcd_command(char data) {
    IOWR_ALTERA_AVALON_PIO_DATA(LCD_RS_BASE, 0);
    IOWR_ALTERA_AVALON_PIO_DATA(LCD_RW_BASE, 0);
    IOWR_ALTERA_AVALON_PIO_DATA(LCD_D_BASE, data);
    IOWR_ALTERA_AVALON_PIO_DATA(LCD_EN_BASE, 1);
    delay_fast(); IOWR_ALTERA_AVALON_PIO_DATA(LCD_EN_BASE, 0);
    if(data == 0x01) delay_ms(2); else delay_fast();
}
void lcd_data(char data) {
    IOWR_ALTERA_AVALON_PIO_DATA(LCD_RS_BASE, 1);
    IOWR_ALTERA_AVALON_PIO_DATA(LCD_RW_BASE, 0);
    IOWR_ALTERA_AVALON_PIO_DATA(LCD_D_BASE, data);
    IOWR_ALTERA_AVALON_PIO_DATA(LCD_EN_BASE, 1);
    delay_fast(); IOWR_ALTERA_AVALON_PIO_DATA(LCD_EN_BASE, 0);
    delay_fast();
}
void lcd_string(char *str) { while(*str) lcd_data(*str++); }
void lcd_init() {
    delay_ms(20); lcd_command(0x38); lcd_command(0x0C); lcd_command(0x06); lcd_command(0x01);
}

// ================= NGẮT TIMER (0.1 GIÂY) =================
void Timer_IRQ_Handler(void* context) {
    IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0);

    // Sóng đuổi 18 LED
    if(is_alarming) {
        chaser_pos++;
        if(chaser_pos >= 18) chaser_pos = 0;
    }

    chaser_tick++;
    if(chaser_tick >= 10) {
        chaser_tick = 0;
        ss++;
        toggle_1s = !toggle_1s;
        if(ss >= 60) {
            ss = 0; mm++;
            if(mm >= 60) {
                mm = 0; hh++;
                if(hh >= 24) {
                    hh = 0; DD++;
                    int max_d = days_in_month[MM];
                    if (MM == 2 && ((YYYY % 4 == 0 && YYYY % 100 != 0) || (YYYY % 400 == 0))) max_d = 29;
                    if(DD > max_d) { DD = 1; MM++; if(MM > 12) { MM = 1; YYYY++; } }
                }
            }
        }
    }
}

void Timer_Init() {
    IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE, 0);
    unsigned int period = 5000000 - 1; // 0.1s
    IOWR_ALTERA_AVALON_TIMER_PERIODL(TIMER_0_BASE, period);
    IOWR_ALTERA_AVALON_TIMER_PERIODH(TIMER_0_BASE, period >> 16);
    IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE,
        ALTERA_AVALON_TIMER_CONTROL_CONT_MSK | ALTERA_AVALON_TIMER_CONTROL_ITO_MSK | ALTERA_AVALON_TIMER_CONTROL_START_MSK);
}

// ================= HIỂN THỊ 7-SEGMENT =================
void display_time(int h, int m, int s) {
    unsigned int low = hex_lut[s%10] | (hex_lut[s/10] << 8) | (HEX_DASH << 16) | (hex_lut[m%10] << 24);
    unsigned int high = hex_lut[m/10] | (HEX_DASH << 8) | (hex_lut[h%10] << 16) | (hex_lut[h/10] << 24);
    IOWR_ALTERA_AVALON_PIO_DATA(HEX_LOW_BASE, low); IOWR_ALTERA_AVALON_PIO_DATA(HEX_HIGH_BASE, high);
}
void display_date() {
    unsigned int low = hex_lut[YYYY%10] | (hex_lut[(YYYY/10)%10] << 8) | (hex_lut[(YYYY/100)%10] << 16) | (hex_lut[(YYYY/1000)%10] << 24);
    unsigned int high = hex_lut[MM%10] | (hex_lut[MM/10] << 8) | (hex_lut[DD%10] << 16) | (hex_lut[DD/10] << 24);
    IOWR_ALTERA_AVALON_PIO_DATA(HEX_LOW_BASE, low); IOWR_ALTERA_AVALON_PIO_DATA(HEX_HIGH_BASE, high);
}

// ================= CHƯƠNG TRÌNH CHÍNH =================
int main() {
    uart_send_string("=== HE THONG BAO THUC 18 LED DE2-115 ===\r\n");
    IOWR_ALTERA_AVALON_PIO_DATA(LCD_ON_BASE, 1);
    IOWR_ALTERA_AVALON_PIO_DATA(LCD_BLON_BASE, 1);
    lcd_init();

    Timer_Init();
    alt_ic_isr_register(TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID, TIMER_0_IRQ, Timer_IRQ_Handler, NULL, NULL);

    int prev_keys = 0;
    int last_ss = -1;
    int last_display_mode = -1; // Biến theo dõi sự thay đổi màn hình
    char buf1[17], buf2[17];

    while(1) {
        int sw_raw = IORD_ALTERA_AVALON_PIO_DATA(SW_MODE_BASE);
        int key_raw = IORD_ALTERA_AVALON_PIO_DATA(KEY_BASE) & 0x0F;
        int keys = (~key_raw) & 0x0F;
        int edge = keys & ~prev_keys;
        prev_keys = keys;

        char rx_cmd = uart_receive_char();

        if(rx_cmd == '6') { uart_sw1 = !uart_sw1; uart_send_string("Toggle SW2 (Set Time)\r\n"); }
        if(rx_cmd == '7') { uart_sw2 = !uart_sw2; uart_send_string("Toggle SW3 (Set Alarm)\r\n"); }
        if(rx_cmd == '8') { uart_sw3 = !uart_sw3; uart_send_string("Toggle SW4 (Alarm En)\r\n"); }

        // SW0: 1 = Hiển thị LCD, 0 = Hiển thị 7-Segment
        int display_mode = (sw_raw & 1);
        int set_time     = (sw_raw & 2) ^ uart_sw1;
        int set_alarm    = (sw_raw & 4) ^ uart_sw2;
        int alarm_en     = (sw_raw & 8) ^ uart_sw3;

        // ===== CHỈNH GIỜ/NGÀY =====
        if(set_time) {
            if((edge & 4) || rx_cmd == '3') {
                set_time_submode = !set_time_submode;
                uart_send_string(set_time_submode ? "Mode: DATE\r\n" : "Mode: TIME\r\n");
            }
            if(set_time_submode == 0) {
                if((edge & 1) || rx_cmd == '1') hh = (hh+1)%24;
                if((edge & 2) || rx_cmd == '2') mm = (mm+1)%60;
            } else {
                if((edge & 1) || rx_cmd == '1') {
                    DD++; int max_d = days_in_month[MM];
                    if (MM == 2 && ((YYYY % 4 == 0 && YYYY % 100 != 0) || (YYYY % 400 == 0))) max_d = 29;
                    if(DD > max_d) DD = 1;
                }
                if((edge & 2) || rx_cmd == '2') MM = (MM % 12) + 1;
                if(rx_cmd == 'y') YYYY++;
            }
        }
        // ===== CHỈNH BÁO THỨC =====
        else if(set_alarm) {
            if((edge & 1) || rx_cmd == '1') alarm_hh = (alarm_hh+1)%24;
            if((edge & 2) || rx_cmd == '2') alarm_mm = (alarm_mm+1)%60;
            if((edge & 4) || rx_cmd == '3') alarm_ss = 0;
        }

        // ===== LOGIC BÁO THỨC =====
        if(alarm_en && hh==alarm_hh && mm==alarm_mm && ss==0 && !is_alarming) {
            is_alarming = 1; uart_send_string("!!! WAKE UP !!!\r\n");
        }
        if(!alarm_en) is_alarming = 0;
        if(is_alarming && ((edge & 1) || rx_cmd == '1')) is_alarming = 0;

        // ===== ĐIỀU KHIỂN BÁO THỨC (LED SÓNG ĐUỔI + CHUÔNG) =====
                if(alarm_en) {
                    if(is_alarming) {
                        // Hiệu ứng LED sóng đuổi
                        IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, (1 << chaser_pos));

                        // Chuông kêu "tít... tít..." theo nhịp 1 giây
                        IOWR_ALTERA_AVALON_PIO_DATA(BUZZER_BASE, toggle_1s);
                    } else {
                        IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x3FFFF); // Bật 18 LED chờ
                        IOWR_ALTERA_AVALON_PIO_DATA(BUZZER_BASE, 0);    // Tắt chuông
                    }
                } else {
                    IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x00000);     // Tắt LED
                    IOWR_ALTERA_AVALON_PIO_DATA(BUZZER_BASE, 0);        // Tắt chuông
                }
        // ===== XỬ LÝ CHUYỂN ĐỔI MÀN HÌNH (TRÁNH CHỚP TẮT) =====
        if (display_mode != last_display_mode) {
            lcd_command(0x01); // Xóa trắng LCD
            if (display_mode == 1) {
                // Tắt hoàn toàn 7-Segment (Xuất 0xFFFFFFFF ra các thanh ghi)
                IOWR_ALTERA_AVALON_PIO_DATA(HEX_LOW_BASE, 0xFFFFFFFF);
                IOWR_ALTERA_AVALON_PIO_DATA(HEX_HIGH_BASE, 0xFFFFFFFF);
            }
            last_display_mode = display_mode;
            last_ss = -1; // Ép màn hình cập nhật ngay lập tức
        }

        // ===== CẬP NHẬT HIỂN THỊ ĐỘC LẬP =====
        if(display_mode == 1) {
            // Mức 1: Chỉ hiển thị LCD
            if(ss != last_ss || edge || rx_cmd) {
                // Ta đã thêm khoảng trắng cố định phía sau để đảm bảo ghi đè trọn 16 ô
                if(set_time) {
                    if(set_time_submode) {
                        sprintf(buf1, "SET DATE        ");
                        sprintf(buf2, "%02d/%02d/%04d      ", DD, MM, YYYY);
                    } else {
                        sprintf(buf1, "SET TIME        ");
                        sprintf(buf2, "%02d:%02d:%02d        ", hh, mm, ss);
                    }
                } else if(set_alarm) {
                    sprintf(buf1, "ALARM %s       ", alarm_en ? "ON " : "OFF");
                    sprintf(buf2, "%02d:%02d:%02d        ", alarm_hh, alarm_mm, alarm_ss);
                } else {
                    sprintf(buf1, "%02d/%02d/%04d      ", DD, MM, YYYY);
                    if(is_alarming && toggle_1s) sprintf(buf2, "WAKE UP!!!      ");
                    else sprintf(buf2, "%02d:%02d:%02d        ", hh, mm, ss);
                }
                lcd_command(0x80); lcd_string(buf1);
                lcd_command(0xC0); lcd_string(buf2);
                last_ss = ss;
            }
        } else {
            // Mức 0: Chỉ hiển thị 7-Segment
            if(set_alarm) display_time(alarm_hh, alarm_mm, alarm_ss);
            else if(toggle_1s) display_time(hh, mm, ss);
            else display_date();
        }

        delay_ms(1);
    }
    return 0;
}
