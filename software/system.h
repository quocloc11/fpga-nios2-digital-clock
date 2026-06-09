/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_qsys_0' in SOPC Builder design 'nios_sys'
 * SOPC Builder design path: D:/dongho_project/nios_sys.sopcinfo
 *
 * Generated: Wed Apr 15 19:20:52 ICT 2026
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x40820
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x13
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x20020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x13
#define ALT_CPU_NAME "nios2_qsys_0"
#define ALT_CPU_RESET_ADDR 0x20000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x40820
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x13
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x20020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x13
#define NIOS2_RESET_ADDR 0x20000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_TIMER
#define __ALTERA_AVALON_UART
#define __ALTERA_NIOS2_QSYS


/*
 * LCD_BLON configuration
 *
 */

#define ALT_MODULE_CLASS_LCD_BLON altera_avalon_pio
#define LCD_BLON_BASE 0x41120
#define LCD_BLON_BIT_CLEARING_EDGE_REGISTER 0
#define LCD_BLON_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LCD_BLON_CAPTURE 0
#define LCD_BLON_DATA_WIDTH 1
#define LCD_BLON_DO_TEST_BENCH_WIRING 0
#define LCD_BLON_DRIVEN_SIM_VALUE 0
#define LCD_BLON_EDGE_TYPE "NONE"
#define LCD_BLON_FREQ 50000000
#define LCD_BLON_HAS_IN 0
#define LCD_BLON_HAS_OUT 1
#define LCD_BLON_HAS_TRI 0
#define LCD_BLON_IRQ -1
#define LCD_BLON_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LCD_BLON_IRQ_TYPE "NONE"
#define LCD_BLON_NAME "/dev/LCD_BLON"
#define LCD_BLON_RESET_VALUE 0
#define LCD_BLON_SPAN 16
#define LCD_BLON_TYPE "altera_avalon_pio"


/*
 * LCD_D configuration
 *
 */

#define ALT_MODULE_CLASS_LCD_D altera_avalon_pio
#define LCD_D_BASE 0x410e0
#define LCD_D_BIT_CLEARING_EDGE_REGISTER 0
#define LCD_D_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LCD_D_CAPTURE 0
#define LCD_D_DATA_WIDTH 8
#define LCD_D_DO_TEST_BENCH_WIRING 0
#define LCD_D_DRIVEN_SIM_VALUE 0
#define LCD_D_EDGE_TYPE "NONE"
#define LCD_D_FREQ 50000000
#define LCD_D_HAS_IN 0
#define LCD_D_HAS_OUT 1
#define LCD_D_HAS_TRI 0
#define LCD_D_IRQ -1
#define LCD_D_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LCD_D_IRQ_TYPE "NONE"
#define LCD_D_NAME "/dev/LCD_D"
#define LCD_D_RESET_VALUE 0
#define LCD_D_SPAN 16
#define LCD_D_TYPE "altera_avalon_pio"


/*
 * LCD_EN configuration
 *
 */

#define ALT_MODULE_CLASS_LCD_EN altera_avalon_pio
#define LCD_EN_BASE 0x41110
#define LCD_EN_BIT_CLEARING_EDGE_REGISTER 0
#define LCD_EN_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LCD_EN_CAPTURE 0
#define LCD_EN_DATA_WIDTH 1
#define LCD_EN_DO_TEST_BENCH_WIRING 0
#define LCD_EN_DRIVEN_SIM_VALUE 0
#define LCD_EN_EDGE_TYPE "NONE"
#define LCD_EN_FREQ 50000000
#define LCD_EN_HAS_IN 0
#define LCD_EN_HAS_OUT 1
#define LCD_EN_HAS_TRI 0
#define LCD_EN_IRQ -1
#define LCD_EN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LCD_EN_IRQ_TYPE "NONE"
#define LCD_EN_NAME "/dev/LCD_EN"
#define LCD_EN_RESET_VALUE 0
#define LCD_EN_SPAN 16
#define LCD_EN_TYPE "altera_avalon_pio"


/*
 * LCD_ON configuration
 *
 */

#define ALT_MODULE_CLASS_LCD_ON altera_avalon_pio
#define LCD_ON_BASE 0x41130
#define LCD_ON_BIT_CLEARING_EDGE_REGISTER 0
#define LCD_ON_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LCD_ON_CAPTURE 0
#define LCD_ON_DATA_WIDTH 1
#define LCD_ON_DO_TEST_BENCH_WIRING 0
#define LCD_ON_DRIVEN_SIM_VALUE 0
#define LCD_ON_EDGE_TYPE "NONE"
#define LCD_ON_FREQ 50000000
#define LCD_ON_HAS_IN 0
#define LCD_ON_HAS_OUT 1
#define LCD_ON_HAS_TRI 0
#define LCD_ON_IRQ -1
#define LCD_ON_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LCD_ON_IRQ_TYPE "NONE"
#define LCD_ON_NAME "/dev/LCD_ON"
#define LCD_ON_RESET_VALUE 0
#define LCD_ON_SPAN 16
#define LCD_ON_TYPE "altera_avalon_pio"


/*
 * LCD_RS configuration
 *
 */

#define ALT_MODULE_CLASS_LCD_RS altera_avalon_pio
#define LCD_RS_BASE 0x410f0
#define LCD_RS_BIT_CLEARING_EDGE_REGISTER 0
#define LCD_RS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LCD_RS_CAPTURE 0
#define LCD_RS_DATA_WIDTH 1
#define LCD_RS_DO_TEST_BENCH_WIRING 0
#define LCD_RS_DRIVEN_SIM_VALUE 0
#define LCD_RS_EDGE_TYPE "NONE"
#define LCD_RS_FREQ 50000000
#define LCD_RS_HAS_IN 0
#define LCD_RS_HAS_OUT 1
#define LCD_RS_HAS_TRI 0
#define LCD_RS_IRQ -1
#define LCD_RS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LCD_RS_IRQ_TYPE "NONE"
#define LCD_RS_NAME "/dev/LCD_RS"
#define LCD_RS_RESET_VALUE 0
#define LCD_RS_SPAN 16
#define LCD_RS_TYPE "altera_avalon_pio"


/*
 * LCD_RW configuration
 *
 */

#define ALT_MODULE_CLASS_LCD_RW altera_avalon_pio
#define LCD_RW_BASE 0x41100
#define LCD_RW_BIT_CLEARING_EDGE_REGISTER 0
#define LCD_RW_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LCD_RW_CAPTURE 0
#define LCD_RW_DATA_WIDTH 1
#define LCD_RW_DO_TEST_BENCH_WIRING 0
#define LCD_RW_DRIVEN_SIM_VALUE 0
#define LCD_RW_EDGE_TYPE "NONE"
#define LCD_RW_FREQ 50000000
#define LCD_RW_HAS_IN 0
#define LCD_RW_HAS_OUT 1
#define LCD_RW_HAS_TRI 0
#define LCD_RW_IRQ -1
#define LCD_RW_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LCD_RW_IRQ_TYPE "NONE"
#define LCD_RW_NAME "/dev/LCD_RW"
#define LCD_RW_RESET_VALUE 0
#define LCD_RW_SPAN 16
#define LCD_RW_TYPE "altera_avalon_pio"


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone IV E"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart_0"
#define ALT_STDERR_BASE 0x41148
#define ALT_STDERR_DEV jtag_uart_0
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart_0"
#define ALT_STDIN_BASE 0x41148
#define ALT_STDIN_DEV jtag_uart_0
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart_0"
#define ALT_STDOUT_BASE 0x41148
#define ALT_STDOUT_DEV jtag_uart_0
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "nios_sys"


/*
 * button configuration
 *
 */

#define ALT_MODULE_CLASS_button altera_avalon_pio
#define BUTTON_BASE 0x410a0
#define BUTTON_BIT_CLEARING_EDGE_REGISTER 0
#define BUTTON_BIT_MODIFYING_OUTPUT_REGISTER 0
#define BUTTON_CAPTURE 0
#define BUTTON_DATA_WIDTH 4
#define BUTTON_DO_TEST_BENCH_WIRING 0
#define BUTTON_DRIVEN_SIM_VALUE 0
#define BUTTON_EDGE_TYPE "NONE"
#define BUTTON_FREQ 50000000
#define BUTTON_HAS_IN 1
#define BUTTON_HAS_OUT 0
#define BUTTON_HAS_TRI 0
#define BUTTON_IRQ -1
#define BUTTON_IRQ_INTERRUPT_CONTROLLER_ID -1
#define BUTTON_IRQ_TYPE "NONE"
#define BUTTON_NAME "/dev/button"
#define BUTTON_RESET_VALUE 0
#define BUTTON_SPAN 16
#define BUTTON_TYPE "altera_avalon_pio"


/*
 * buzzer configuration
 *
 */

#define ALT_MODULE_CLASS_buzzer altera_avalon_pio
#define BUZZER_BASE 0x41070
#define BUZZER_BIT_CLEARING_EDGE_REGISTER 0
#define BUZZER_BIT_MODIFYING_OUTPUT_REGISTER 0
#define BUZZER_CAPTURE 0
#define BUZZER_DATA_WIDTH 1
#define BUZZER_DO_TEST_BENCH_WIRING 0
#define BUZZER_DRIVEN_SIM_VALUE 0
#define BUZZER_EDGE_TYPE "NONE"
#define BUZZER_FREQ 50000000
#define BUZZER_HAS_IN 0
#define BUZZER_HAS_OUT 1
#define BUZZER_HAS_TRI 0
#define BUZZER_IRQ -1
#define BUZZER_IRQ_INTERRUPT_CONTROLLER_ID -1
#define BUZZER_IRQ_TYPE "NONE"
#define BUZZER_NAME "/dev/buzzer"
#define BUZZER_RESET_VALUE 0
#define BUZZER_SPAN 16
#define BUZZER_TYPE "altera_avalon_pio"


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK TIMER_0
#define ALT_TIMESTAMP_CLK none


/*
 * hex_high configuration
 *
 */

#define ALT_MODULE_CLASS_hex_high altera_avalon_pio
#define HEX_HIGH_BASE 0x410c0
#define HEX_HIGH_BIT_CLEARING_EDGE_REGISTER 0
#define HEX_HIGH_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX_HIGH_CAPTURE 0
#define HEX_HIGH_DATA_WIDTH 32
#define HEX_HIGH_DO_TEST_BENCH_WIRING 0
#define HEX_HIGH_DRIVEN_SIM_VALUE 0
#define HEX_HIGH_EDGE_TYPE "NONE"
#define HEX_HIGH_FREQ 50000000
#define HEX_HIGH_HAS_IN 0
#define HEX_HIGH_HAS_OUT 1
#define HEX_HIGH_HAS_TRI 0
#define HEX_HIGH_IRQ -1
#define HEX_HIGH_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX_HIGH_IRQ_TYPE "NONE"
#define HEX_HIGH_NAME "/dev/hex_high"
#define HEX_HIGH_RESET_VALUE 0
#define HEX_HIGH_SPAN 16
#define HEX_HIGH_TYPE "altera_avalon_pio"


/*
 * hex_low configuration
 *
 */

#define ALT_MODULE_CLASS_hex_low altera_avalon_pio
#define HEX_LOW_BASE 0x410d0
#define HEX_LOW_BIT_CLEARING_EDGE_REGISTER 0
#define HEX_LOW_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX_LOW_CAPTURE 0
#define HEX_LOW_DATA_WIDTH 32
#define HEX_LOW_DO_TEST_BENCH_WIRING 0
#define HEX_LOW_DRIVEN_SIM_VALUE 0
#define HEX_LOW_EDGE_TYPE "NONE"
#define HEX_LOW_FREQ 50000000
#define HEX_LOW_HAS_IN 0
#define HEX_LOW_HAS_OUT 1
#define HEX_LOW_HAS_TRI 0
#define HEX_LOW_IRQ -1
#define HEX_LOW_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX_LOW_IRQ_TYPE "NONE"
#define HEX_LOW_NAME "/dev/hex_low"
#define HEX_LOW_RESET_VALUE 0
#define HEX_LOW_SPAN 16
#define HEX_LOW_TYPE "altera_avalon_pio"


/*
 * jtag_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_0 altera_avalon_jtag_uart
#define JTAG_UART_0_BASE 0x41148
#define JTAG_UART_0_IRQ 0
#define JTAG_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_0_NAME "/dev/jtag_uart_0"
#define JTAG_UART_0_READ_DEPTH 64
#define JTAG_UART_0_READ_THRESHOLD 8
#define JTAG_UART_0_SPAN 8
#define JTAG_UART_0_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_0_WRITE_DEPTH 64
#define JTAG_UART_0_WRITE_THRESHOLD 8


/*
 * key configuration
 *
 */

#define ALT_MODULE_CLASS_key altera_avalon_pio
#define KEY_BASE 0x41080
#define KEY_BIT_CLEARING_EDGE_REGISTER 0
#define KEY_BIT_MODIFYING_OUTPUT_REGISTER 0
#define KEY_CAPTURE 0
#define KEY_DATA_WIDTH 8
#define KEY_DO_TEST_BENCH_WIRING 0
#define KEY_DRIVEN_SIM_VALUE 0
#define KEY_EDGE_TYPE "NONE"
#define KEY_FREQ 50000000
#define KEY_HAS_IN 1
#define KEY_HAS_OUT 0
#define KEY_HAS_TRI 0
#define KEY_IRQ -1
#define KEY_IRQ_INTERRUPT_CONTROLLER_ID -1
#define KEY_IRQ_TYPE "NONE"
#define KEY_NAME "/dev/key"
#define KEY_RESET_VALUE 0
#define KEY_SPAN 16
#define KEY_TYPE "altera_avalon_pio"


/*
 * led configuration
 *
 */

#define ALT_MODULE_CLASS_led altera_avalon_pio
#define LED_BASE 0x41090
#define LED_BIT_CLEARING_EDGE_REGISTER 0
#define LED_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LED_CAPTURE 0
#define LED_DATA_WIDTH 32
#define LED_DO_TEST_BENCH_WIRING 0
#define LED_DRIVEN_SIM_VALUE 0
#define LED_EDGE_TYPE "NONE"
#define LED_FREQ 50000000
#define LED_HAS_IN 0
#define LED_HAS_OUT 1
#define LED_HAS_TRI 0
#define LED_IRQ -1
#define LED_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LED_IRQ_TYPE "NONE"
#define LED_NAME "/dev/led"
#define LED_RESET_VALUE 0
#define LED_SPAN 16
#define LED_TYPE "altera_avalon_pio"


/*
 * onchip_memory2_0 configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_memory2_0 altera_avalon_onchip_memory2
#define ONCHIP_MEMORY2_0_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEMORY2_0_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEMORY2_0_BASE 0x20000
#define ONCHIP_MEMORY2_0_CONTENTS_INFO ""
#define ONCHIP_MEMORY2_0_DUAL_PORT 0
#define ONCHIP_MEMORY2_0_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_0_INIT_CONTENTS_FILE "nios_sys_onchip_memory2_0"
#define ONCHIP_MEMORY2_0_INIT_MEM_CONTENT 1
#define ONCHIP_MEMORY2_0_INSTANCE_ID "NONE"
#define ONCHIP_MEMORY2_0_IRQ -1
#define ONCHIP_MEMORY2_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEMORY2_0_NAME "/dev/onchip_memory2_0"
#define ONCHIP_MEMORY2_0_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEMORY2_0_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_0_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEMORY2_0_SINGLE_CLOCK_OP 0
#define ONCHIP_MEMORY2_0_SIZE_MULTIPLE 1
#define ONCHIP_MEMORY2_0_SIZE_VALUE 81920
#define ONCHIP_MEMORY2_0_SPAN 81920
#define ONCHIP_MEMORY2_0_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEMORY2_0_WRITABLE 1


/*
 * sw_mode configuration
 *
 */

#define ALT_MODULE_CLASS_sw_mode altera_avalon_pio
#define SW_MODE_BASE 0x410b0
#define SW_MODE_BIT_CLEARING_EDGE_REGISTER 0
#define SW_MODE_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SW_MODE_CAPTURE 0
#define SW_MODE_DATA_WIDTH 4
#define SW_MODE_DO_TEST_BENCH_WIRING 0
#define SW_MODE_DRIVEN_SIM_VALUE 0
#define SW_MODE_EDGE_TYPE "NONE"
#define SW_MODE_FREQ 50000000
#define SW_MODE_HAS_IN 1
#define SW_MODE_HAS_OUT 0
#define SW_MODE_HAS_TRI 0
#define SW_MODE_IRQ -1
#define SW_MODE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SW_MODE_IRQ_TYPE "NONE"
#define SW_MODE_NAME "/dev/sw_mode"
#define SW_MODE_RESET_VALUE 0
#define SW_MODE_SPAN 16
#define SW_MODE_TYPE "altera_avalon_pio"


/*
 * timer_0 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_0 altera_avalon_timer
#define TIMER_0_ALWAYS_RUN 0
#define TIMER_0_BASE 0x41040
#define TIMER_0_COUNTER_SIZE 32
#define TIMER_0_FIXED_PERIOD 0
#define TIMER_0_FREQ 50000000
#define TIMER_0_IRQ 1
#define TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_0_LOAD_VALUE 49999
#define TIMER_0_MULT 0.0010
#define TIMER_0_NAME "/dev/timer_0"
#define TIMER_0_PERIOD 1
#define TIMER_0_PERIOD_UNITS "ms"
#define TIMER_0_RESET_OUTPUT 0
#define TIMER_0_SNAPSHOT 1
#define TIMER_0_SPAN 32
#define TIMER_0_TICKS_PER_SEC 1000.0
#define TIMER_0_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_0_TYPE "altera_avalon_timer"


/*
 * uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_uart_0 altera_avalon_uart
#define UART_0_BASE 0x41020
#define UART_0_BAUD 9600
#define UART_0_DATA_BITS 8
#define UART_0_FIXED_BAUD 1
#define UART_0_FREQ 50000000
#define UART_0_IRQ 2
#define UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define UART_0_NAME "/dev/uart_0"
#define UART_0_PARITY 'N'
#define UART_0_SIM_CHAR_STREAM ""
#define UART_0_SIM_TRUE_BAUD 0
#define UART_0_SPAN 32
#define UART_0_STOP_BITS 1
#define UART_0_SYNC_REG_DEPTH 2
#define UART_0_TYPE "altera_avalon_uart"
#define UART_0_USE_CTS_RTS 0
#define UART_0_USE_EOP_REGISTER 0

#endif /* __SYSTEM_H_ */
