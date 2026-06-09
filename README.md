# fpga-nios2-digital-clock
# FPGA-based Digital Clock System using Nios II Processor

## Project Overview
This project implements a fully functional digital clock system on an Altera/Intel Cyclone FPGA kit. The hardware architecture is built using Intel Quartus Prime and Qsys (Platform Designer) with a Nios II soft-core processor. The system management and control logic are programmed in Embedded C.

## Key Features
- **Real-time Clock:** Displays hours, minutes, and seconds accurately.
- **Alarm System:** Allows users to set an alarm time with a buzzer/LED indicator.
- **Dual-mode Configuration:** - *Hardware Mode:* Use on-board push-buttons with software de-bouncing logic.
  - *Serial Command Mode:* Configure time, adjust settings, and trigger commands directly from a PC keyboard via **UART Serial Terminal**.
- **LCD Interface:** Real-time data and configuration menus are rendered clearly on a 16x2 LCD screen.

## Hardware Architecture & Peripherals
- **Processor:** Nios II Soft-core Processor
- **Peripherals configured via Qsys:**
  - **JTAG UART / UART Core:** For serial communication with PC, handling keyboard input interrupts.
  - Interval Timer (for accurate time base)
  - PIO (Parallel I/O) for buttons, LEDs, and LCD interface
    
## Technologies Used
- **Software:** Intel Quartus Prime, Nios II Software Build Tools for Eclipse.
- **Languages:** Embedded C, Verilog HDL.
- **Hardware Kit:** Cyclone IV/V FPGA Board.
