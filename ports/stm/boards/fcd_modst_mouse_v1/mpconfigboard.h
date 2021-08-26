/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2021 Flying Camp Design
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

// Micropython setup

#define MICROPY_HW_BOARD_NAME "Flying Camp Design :: ModST Mouse V1 Processor"
#define MICROPY_HW_MCU_NAME "STM32F405RG"

// Internal STM32 flash configuration
#define FLASH_SIZE (0x100000)
#define FLASH_PAGE_SIZE (0x4000)

// STM32 clock configuration
#define HSE_VALUE ((uint32_t)25000000)
#define LSE_VALUE ((uint32_t)32768)
#define BOARD_HAS_LOW_SPEED_CRYSTAL (1)

// Status LED
#define MICROPY_HW_LED_STATUS (&pin_PB03)

// On-board SPI flash
#define SPI_FLASH_MOSI_PIN (&pin_PA07)
#define SPI_FLASH_MISO_PIN (&pin_PA06)
#define SPI_FLASH_SCK_PIN (&pin_PA05)
#define SPI_FLASH_CS_PIN (&pin_PA15)

// Bootloader only
#ifdef UF2_BOOTLOADER_ENABLED
    #define BOARD_VTOR_DEFER (1) // Leave VTOR relocation to bootloader
#endif

// Default I2C interface
#define DEFAULT_I2C_BUS_SCL (&pin_PB08)
#define DEFAULT_I2C_BUS_SDA (&pin_PB09)

// Default SPI interface
#define DEFAULT_SPI_BUS_SCK (&pin_PB13)
#define DEFAULT_SPI_BUS_MOSI (&pin_PB15)
#define DEFAULT_SPI_BUS_MISO (&pin_PB14)

// Default UART interface
#define DEFAULT_UART_BUS_RX (&pin_PA03)
#define DEFAULT_UART_BUS_TX (&pin_PA02)
