# STM32 Bare-Metal Programming – From the Ground Up

This repository contains my code, notes, and experiments while following along with the Udemy course **“STM32 Bare-Metal Programming from the Ground Up.”**  
The purpose of this repo is to document my learning journey, organize lab exercises, and provide working examples of bare-metal embedded C programming on STM32 microcontrollers.

---

## 📚 About the Course
The course focuses on building an understanding of microcontrollers **without relying on HAL drivers** or vendor libraries. Instead, it emphasizes:
- Register-level programming
- ARM Cortex-M architecture fundamentals
- Peripheral initialization and control
- Debugging with STM32CubeIDE
- Building projects step-by-step from reset vector to functional firmware

For more information, see the [course page on Udemy](https://www.udemy.com/) *(link intentionally left generic — replace with your actual enrolled course link if you want).*

---

## 🛠️ Development Environment

- **IDE**: [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)
- **Toolchain**: GCC ARM Embedded Toolchain (bundled with STM32CubeIDE)
- **Debugger/Programmer**: ST-LINK/V2 or on-board ST-LINK (depending on the board)
- **Board(s) Used**:  
  - STM32F4 Discovery (STM32F407VG) *(update with your actual board model)*  
  - You can adapt the examples to other STM32 MCUs by adjusting startup files and linker scripts.

---

## 📂 Repository Structure

```bash
.
|-- 0_led_toggle_addr/
|-- 01_led_toggle_addr_struct/
|-- 02_gpio_output/ 
|-- 03_gpio_bsrr/
|-- 04_gpio_input/
|-- 05_uart_tx/
|-- 06_uart_printf/
|-- 07_uart_modular/
|-- 08_uart_rx/   
|-- 09_adc_single_conversion/
|-- 10_adc_continuous_conversion/
|-- 11_systick_delay/
|-- 12_timers/
|-- 13_output_compare/
|-- 14_input_capture/
|-- 15_input_interrupt/
|-- 16_uart_rx_interrupt/
|-- 17_adc_interrupt/
|-- 18_systick_interrupt/
|-- 19_timers_interrupt/
|-- chip_headers/
|-- referance_docs/
|-- README.md           # This file
|-- .gitignore          # Ignores build artifacts and IDE metadata
|__ *.ioc               # CubeMX project configuration file
