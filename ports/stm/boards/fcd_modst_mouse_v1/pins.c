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

#include "shared-bindings/board/__init__.h"

STATIC const mp_rom_map_elem_t board_module_globals_table[] = {
    // The SparkFun MicroMod spec uses a zero-based peripheral numbering scheme.
    // The 0th peripheral is the default and the "0" is omitted from the
    // peripheral name (e.g. "I2C" instead of "I2C0").
    //
    // For more details, see https://www.sparkfun.com/micromod#tech-specs

    // MicroMod built-in status LED pin
    // Requirement from the "Designing with MicroMod" SparkFun article:
    // "... every Processor Board shall include one status LED connected to a
    // pin that is not connected to the board edge."
    { MP_ROM_QSTR(MP_QSTR_LED), MP_ROM_PTR(&pin_PB03) },          // MicroMod LED (PB3)

    // MicroMod USB bus input voltage (+5V) pin
    { MP_ROM_QSTR(MP_QSTR_USB_VIN), MP_ROM_PTR(&pin_PA09) },      // MicroMod USB_VIN (PA9)

    // MicroMod +3.3V enable pin
    { MP_ROM_QSTR(MP_QSTR_P3V3_EN), MP_ROM_PTR(&pin_PC13) },      // MicroMod 3.3V_EN (PC13)

    // MicroMod battery voltage sense pin
    { MP_ROM_QSTR(MP_QSTR_BATT_VIN3), MP_ROM_PTR(&pin_PA04) },    // MicroMod BATT_VIN/3 (PA4)

    // MicroMod reset pin
    // { MP_ROM_QSTR(MP_QSTR_RESET), MP_ROM_PTR() },              // MicroMod RESET# (STM32 has a dedicated HW NRST pin)

    // MicroMod boot pin
    // { MP_ROM_QSTR(MP_QSTR_BOOT), MP_ROM_PTR() },               // MicroMod BOOT (STM32 has a dedicated HW BOOT0 pin)

    // MicroMod USB device pins
    // USB device is always used internally by CircuitPython, so skip creating
    // the pin objects for it.
    // { MP_ROM_QSTR(MP_QSTR_USB_DM), MP_ROM_PTR(&pin_PA11) },    // MicroMod USB_D- (PA11)
    // { MP_ROM_QSTR(MP_QSTR_USB_DP), MP_ROM_PTR(&pin_PA12) },    // MicroMod USB_D+ (PA12)

    // MicroMod USB host pins
    // { MP_ROM_QSTR(MP_QSTR_USBHOST_DM), MP_ROM_PTR() },         // MicroMod USBHOST_D- (not connected)
    // { MP_ROM_QSTR(MP_QSTR_USBHOST_DP), MP_ROM_PTR() },         // MicroMod USBHOST_D+ (not connected)

    // MicroMod CAN pins
    // { MP_ROM_QSTR(MP_QSTR_CAN_RX), MP_ROM_PTR() },             // MicroMod CAN_RX (not connected)
    // { MP_ROM_QSTR(MP_QSTR_CAN_TX), MP_ROM_PTR() },             // MicroMod CAN_TX (not connected)

    // Note: MicroMod UART (UART0) is not present in the edge connector pinout
    // because the primary debug serial port is exposed as a virtual serial port
    // over USB.

    // MicroMod UART1 pins
    { MP_ROM_QSTR(MP_QSTR_UART_TX1), MP_ROM_PTR(&pin_PA02) },     // MicroMod UART_TX1 | CircuitPython TX (PA2)
    { MP_ROM_QSTR(MP_QSTR_UART_RX1), MP_ROM_PTR(&pin_PA03) },     // MicroMod UART_RX1 | CircuitPython RX (PA3)
    { MP_ROM_QSTR(MP_QSTR_UART_RTS1), MP_ROM_PTR(&pin_PA01) },    // MicroMod RTS1 (PA1)
    { MP_ROM_QSTR(MP_QSTR_UART_CTS1), MP_ROM_PTR(&pin_PA00) },    // MicroMod CTS1 (PA0)

    // CircuitPython default UART pin aliases
    { MP_ROM_QSTR(MP_QSTR_TX), MP_ROM_PTR(&pin_PA02) },           // CircuitPython TX | MicroMod UART_TX1 (PA2)
    { MP_ROM_QSTR(MP_QSTR_RX), MP_ROM_PTR(&pin_PA03) },           // CircuitPython RX | MicroMod UART_RX1 (PA3)

    // MicroMod UART2 pins
    { MP_ROM_QSTR(MP_QSTR_UART_TX2), MP_ROM_PTR(&pin_PB06) },     // MicroMod UART_TX2 (PB6)
    { MP_ROM_QSTR(MP_QSTR_UART_RX2), MP_ROM_PTR(&pin_PB07) },     // MicroMod UART_RX2 (PB7)

    // MicroMod I2C pins
    { MP_ROM_QSTR(MP_QSTR_I2C_SDA), MP_ROM_PTR(&pin_PB09) },      // MicroMod I2C_SDA | CircuitPython SDA (PB9)
    { MP_ROM_QSTR(MP_QSTR_I2C_SCL), MP_ROM_PTR(&pin_PB08) },      // MicroMod I2C_SCL | CircuitPython SCL (PB8)

    // CircuitPython default I2C pin aliases
    { MP_ROM_QSTR(MP_QSTR_SDA), MP_ROM_PTR(&pin_PB09) },          // CircuitPython SDA | MicroMod I2C_SDA (PB9)
    { MP_ROM_QSTR(MP_QSTR_SCL), MP_ROM_PTR(&pin_PB08) },          // CircuitPython SCL | MicroMod I2C_SCL (PB8)

    // MicroMod I2C interrupt pin
    { MP_ROM_QSTR(MP_QSTR_I2C_INT), MP_ROM_PTR(&pin_PB05) },      // MicroMod I2C_INT (PB5)

    // MicroMod I2C1 pins
    { MP_ROM_QSTR(MP_QSTR_I2C_SDA1), MP_ROM_PTR(&pin_PB11) },     // MicroMod I2C_SDA1 (PB11)
    { MP_ROM_QSTR(MP_QSTR_I2C_SCL1), MP_ROM_PTR(&pin_PB10) },     // MicroMod I2C_SCL1 (PB10)

    // MicroMod SPI pins
    { MP_ROM_QSTR(MP_QSTR_SPI_CIPO), MP_ROM_PTR(&pin_PB14) },     // MicroMod SPI_CIPO | CircuitPython CIPO (PB14)
    { MP_ROM_QSTR(MP_QSTR_SPI_MISO), MP_ROM_PTR(&pin_PB14) },     // MicroMod SPI_MISO | CircuitPython MISO (PB14)
    { MP_ROM_QSTR(MP_QSTR_SPI_COPI), MP_ROM_PTR(&pin_PB15) },     // MicroMod SPI_COPI | CircuitPython COPI | LED_DAT (PB15)
    { MP_ROM_QSTR(MP_QSTR_SPI_MOSI), MP_ROM_PTR(&pin_PB15) },     // MicroMod SPI_MOSI | CircuitPython MOSI | LED_DAT (PB15)
    { MP_ROM_QSTR(MP_QSTR_SPI_SCK), MP_ROM_PTR(&pin_PB13) },      // MicroMod SPI_SCK  | CircuitPython SCK  | LED_CLK (PB13)
    { MP_ROM_QSTR(MP_QSTR_SPI_CS), MP_ROM_PTR(&pin_PB12) },       // MicroMod SPI_CS   | CircuitPython CS (PB12)

    // CircuitPython default SPI pin aliases
    { MP_ROM_QSTR(MP_QSTR_CIPO), MP_ROM_PTR(&pin_PB14) },         // CircuitPython CIPO | MicroMod SPI_CIPO (PB14)
    { MP_ROM_QSTR(MP_QSTR_MISO), MP_ROM_PTR(&pin_PB14) },         // CircuitPython MISO | MicroMod SPI_MISO (PB14)
    { MP_ROM_QSTR(MP_QSTR_COPI), MP_ROM_PTR(&pin_PB15) },         // CircuitPython COPI | MicroMod SPI_COPI | LED_DAT (PB15)
    { MP_ROM_QSTR(MP_QSTR_MOSI), MP_ROM_PTR(&pin_PB15) },         // CircuitPython MOSI | MicroMod SPI_MOSI | LED_DAT (PB15)
    { MP_ROM_QSTR(MP_QSTR_SCK), MP_ROM_PTR(&pin_PB13) },          // CircuitPython SCK  | MicroMod SPI_SCK  | LED_CLK (PB13)
    { MP_ROM_QSTR(MP_QSTR_CS), MP_ROM_PTR(&pin_PB12) },           // CircuitPython CS   | MicroMod SPI_CS (PB12)

    // MicroMod 2-wire serial LED pins
    { MP_ROM_QSTR(MP_QSTR_LED_DAT), MP_ROM_PTR(&pin_PB15) },      // MicroMod LED_DAT | MicroMod SPI_COPI | CircuitPython COPI (PB15)
    { MP_ROM_QSTR(MP_QSTR_LED_CLK), MP_ROM_PTR(&pin_PB13) },      // MicroMod LED_CLK | MicroMod SPI_SCK  | CircuitPython SCK (PB13)

    // MicroMod SDIO pins
    { MP_ROM_QSTR(MP_QSTR_SDIO_CLK), MP_ROM_PTR(&pin_PC12) },     // MicroMod SDIO_SCK   | SPI_SCK1 (PC12)
    { MP_ROM_QSTR(MP_QSTR_SDIO_CMD), MP_ROM_PTR(&pin_PD02) },     // MicroMod SDIO_CMD   | SPI_COPI1 | SPI_MOSI1 (PD2)
    { MP_ROM_QSTR(MP_QSTR_SDIO_DATA0), MP_ROM_PTR(&pin_PC08) },   // MicroMod SDIO_DATA0 | SPI_CIPO1 | SPI_MISO1 (PC8)
    { MP_ROM_QSTR(MP_QSTR_SDIO_DATA1), MP_ROM_PTR(&pin_PC09) },   // MicroMod SDIO_DATA1 (PC9)
    { MP_ROM_QSTR(MP_QSTR_SDIO_DATA2), MP_ROM_PTR(&pin_PC10) },   // MicroMod SDIO_DATA2 (PC10)
    { MP_ROM_QSTR(MP_QSTR_SDIO_DATA3), MP_ROM_PTR(&pin_PC11) },   // MicroMod SDIO_DATA3 | SPI_CS1 (PC11)

    // MicroMod SPI1 pins
    { MP_ROM_QSTR(MP_QSTR_SPI_CIPO1), MP_ROM_PTR(&pin_PC08) },    // MicroMod SPI_CIPO1 | SPI_MISO1 | SDIO_DATA0 (PC8)
    { MP_ROM_QSTR(MP_QSTR_SPI_MISO1), MP_ROM_PTR(&pin_PC08) },    // MicroMod SPI_MISO1 | SPI_CIPO1 | SDIO_DATA0 (PC8)
    { MP_ROM_QSTR(MP_QSTR_SPI_COPI1), MP_ROM_PTR(&pin_PD02) },    // MicroMod SPI_COPI1 | SPI_MOSI1 | SDIO_CMD (PD2)
    { MP_ROM_QSTR(MP_QSTR_SPI_MOSI1), MP_ROM_PTR(&pin_PD02) },    // MicroMod SPI_MOSI1 | SPI_COPI1 | SDIO_CMD (PD2)
    { MP_ROM_QSTR(MP_QSTR_SPI_SCK1), MP_ROM_PTR(&pin_PC12) },     // MicroMod SPI_SCK1  | SDIO_SCK (PC12)
    { MP_ROM_QSTR(MP_QSTR_SPI_CS1), MP_ROM_PTR(&pin_PC11) },      // MicroMod SPI_CS1   | SDIO_DATA3 (PC11)

    // MicroMod audio pins
    // { MP_ROM_QSTR(MP_QSTR_AUD_MCLK), MP_ROM_PTR() },           // MicroMod AUD_MCLK (not connected)
    // { MP_ROM_QSTR(MP_QSTR_AUD_OUT), MP_ROM_PTR() },            // MicroMod AUD_OUT   | I2S_OUT | PCM_OUT  | CAM_MCLK (not connected)
    // { MP_ROM_QSTR(MP_QSTR_AUD_IN), MP_ROM_PTR() },             // MicroMod AUD_IN    | I2S_IN  | PCM_IN   | CAM_PCLK (not connected)
    // { MP_ROM_QSTR(MP_QSTR_AUD_LRCLK), MP_ROM_PTR() },          // MicroMod AUD_LRCLK | I2S_WS  | PCM_SYNC | PDM_DATA (not connected)
    // { MP_ROM_QSTR(MP_QSTR_AUD_BCLK), MP_ROM_PTR() },           // MicroMod AUD_BCLK  | I2S_SCK | PCM_CLK  | PDM_CLK (not connected)

    // MicroMod I2S pins
    // { MP_ROM_QSTR(MP_QSTR_I2S_OUT), MP_ROM_PTR() },            // MicroMod I2S_OUT | AUD_OUT   | PCM_OUT  | CAM_MCLK (not connected)
    // { MP_ROM_QSTR(MP_QSTR_I2S_IN), MP_ROM_PTR() },             // MicroMod I2S_IN  | AUD_IN    | PCM_IN   | CAM_PCLK (not connected)
    // { MP_ROM_QSTR(MP_QSTR_I2S_WS), MP_ROM_PTR() },             // MicroMod I2S_WS  | AUD_LRCLK | PCM_SYNC | PDM_DATA (not connected)
    // { MP_ROM_QSTR(MP_QSTR_I2S_SCK), MP_ROM_PTR() },            // MicroMod I2S_SCK | AUD_BCLK  | PCM_CLK  | PDM_CLK (not connected)

    // MicroMod PCM pins
    // { MP_ROM_QSTR(MP_QSTR_PCM_OUT), MP_ROM_PTR() },            // MicroMod PCM_OUT  | AUD_OUT   | I2S_OUT | CAM_MCLK (not connected)
    // { MP_ROM_QSTR(MP_QSTR_PCM_IN), MP_ROM_PTR() },             // MicroMod PCM_IN   | AUD_IN    | I2S_IN  | CAM_PCLK (not connected)
    // { MP_ROM_QSTR(MP_QSTR_PCM_SYNC), MP_ROM_PTR() },           // MicroMod PCM_SYNC | AUD_LRCLK | I2S_WS  | PDM_DATA (not connected)
    // { MP_ROM_QSTR(MP_QSTR_PCM_CLK), MP_ROM_PTR() },            // MicroMod PCM_CLK  | AUD_BCLK  | I2S_SCK | PDM_CLK (not connected)

    // MicroMod PDM pins
    // { MP_ROM_QSTR(MP_QSTR_PDM_DATA), MP_ROM_PTR() },           // MicroMod PDM_DATA | AUD_LRCLK | I2S_WS  | PCM_SYNC (not connected)
    // { MP_ROM_QSTR(MP_QSTR_PDM_CLK), MP_ROM_PTR() },            // MicroMod PDM_CLK  | AUD_BCLK  | I2S_SCK | PCM_CLK (not connected)

    // MicroMod SWD pins
    { MP_ROM_QSTR(MP_QSTR_SWDIO), MP_ROM_PTR(&pin_PA13) },        // MicroMod SWDIO (PA13)
    { MP_ROM_QSTR(MP_QSTR_SWCLK), MP_ROM_PTR(&pin_PA14) },        // MicroMod SWDCK (PA14)
    // Note: SWO is disabled by default, but it can be enabled in the hardware.
    // Since SWO and the status LED share the same STM32 pin (PB3), the status
    // LED must be disconnected and PB3 must be connected to the SWO M.2 pin:
    //   1. Remove R19 to disconnect the status LED
    //   2. Install R20 to connect PB3 to the SWO M.2 pin
    // { MP_ROM_QSTR(MP_QSTR_SWO), MP_ROM_PTR(&pin_PB03) },       // MicroMod SWO | G11 (PB3)

    // MicroMod ADC pins
    { MP_ROM_QSTR(MP_QSTR_A0), MP_ROM_PTR(&pin_PB00) },           // MicroMod A0 (PB0)
    { MP_ROM_QSTR(MP_QSTR_A1), MP_ROM_PTR(&pin_PB01) },           // MicroMod A1 (PB1)

    // MicroMod PWM pins
    { MP_ROM_QSTR(MP_QSTR_PWM0), MP_ROM_PTR(&pin_PA08) },         // MicroMod PWM0 (PA8)
    { MP_ROM_QSTR(MP_QSTR_PWM1), MP_ROM_PTR(&pin_PA10) },         // MicroMod PWM1 (PA10)

    // MicroMod digital pins
    { MP_ROM_QSTR(MP_QSTR_D0), MP_ROM_PTR(&pin_PB02) },           // MicroMod D0 (PB2)
    { MP_ROM_QSTR(MP_QSTR_D1), MP_ROM_PTR(&pin_PB04) },           // MicroMod D1 | CAM_TRIG (PB4)

    // MicroMod general purpose pins
    { MP_ROM_QSTR(MP_QSTR_G0), MP_ROM_PTR(&pin_PC00) },           // MicroMod G0 | BUS0 (PC0)
    { MP_ROM_QSTR(MP_QSTR_G1), MP_ROM_PTR(&pin_PC01) },           // MicroMod G1 | BUS1 (PC1)
    { MP_ROM_QSTR(MP_QSTR_G2), MP_ROM_PTR(&pin_PC02) },           // MicroMod G2 | BUS2 (PC2)
    { MP_ROM_QSTR(MP_QSTR_G3), MP_ROM_PTR(&pin_PC03) },           // MicroMod G3 | BUS3 (PC3)
    { MP_ROM_QSTR(MP_QSTR_G4), MP_ROM_PTR(&pin_PC04) },           // MicroMod G4 | BUS4 (PC4)
    { MP_ROM_QSTR(MP_QSTR_G5), MP_ROM_PTR(&pin_PC05) },           // MicroMod G5 | BUS5 (PC5)
    { MP_ROM_QSTR(MP_QSTR_G6), MP_ROM_PTR(&pin_PC06) },           // MicroMod G6 | BUS6 (PC6)
    { MP_ROM_QSTR(MP_QSTR_G7), MP_ROM_PTR(&pin_PC07) },           // MicroMod G7 | BUS7 (PC7)
    // { MP_ROM_QSTR(MP_QSTR_G8), MP_ROM_PTR() },                 // MicroMod G8 (not connected)
    // { MP_ROM_QSTR(MP_QSTR_G9), MP_ROM_PTR() },                 // MicroMod G9  | ADC_D- | CAM_HSYNC (not connected)
    // { MP_ROM_QSTR(MP_QSTR_G10), MP_ROM_PTR() },                // MicroMod G10 | ADC_D+ | CAM_VSYNC (not connected)
    // Note: G11 is disabled by default, but it can be enabled in the hardware.
    // Since G11 and the status LED share the same STM32 pin (PB3), the status
    // LED must be disconnected and PB3 must be connected to the G11 M.2 pin:
    //   1. Remove R19 to disconnect the status LED
    //   2. Install R20 to connect PB3 to the G11 M.2 pin
    { MP_ROM_QSTR(MP_QSTR_G11), MP_ROM_PTR(&pin_PB03) },          // MicroMod G11 | SWO (PB3)

    // MicroMod 8-bit bus pins
    { MP_ROM_QSTR(MP_QSTR_BUS0), MP_ROM_PTR(&pin_PC00) },         // MicroMod BUS0 | G0 (PC0)
    { MP_ROM_QSTR(MP_QSTR_BUS1), MP_ROM_PTR(&pin_PC01) },         // MicroMod BUS1 | G1 (PC1)
    { MP_ROM_QSTR(MP_QSTR_BUS2), MP_ROM_PTR(&pin_PC02) },         // MicroMod BUS2 | G2 (PC2)
    { MP_ROM_QSTR(MP_QSTR_BUS3), MP_ROM_PTR(&pin_PC03) },         // MicroMod BUS3 | G3 (PC3)
    { MP_ROM_QSTR(MP_QSTR_BUS4), MP_ROM_PTR(&pin_PC04) },         // MicroMod BUS4 | G4 (PC4)
    { MP_ROM_QSTR(MP_QSTR_BUS5), MP_ROM_PTR(&pin_PC05) },         // MicroMod BUS5 | G5 (PC5)
    { MP_ROM_QSTR(MP_QSTR_BUS6), MP_ROM_PTR(&pin_PC06) },         // MicroMod BUS6 | G6 (PC6)
    { MP_ROM_QSTR(MP_QSTR_BUS7), MP_ROM_PTR(&pin_PC07) },         // MicroMod BUS7 | G7 (PC7)

    // MicroMod differential ADC input pins
    // { MP_ROM_QSTR(MP_QSTR_ADC_DM), MP_ROM_PTR() },             // MicroMod ADC_D- | G9  | CAM_HSYNC (not connected)
    // { MP_ROM_QSTR(MP_QSTR_ADC_DP), MP_ROM_PTR() },             // MicroMod ADC_D+ | G10 | CAM_VSYNC (not connected)

    // MicroMod camera pins
    // { MP_ROM_QSTR(MP_QSTR_CAM_MCLK), MP_ROM_PTR() },           // MicroMod CAM_MCLK  | AUD_OUT | I2S_OUT | PCM_OUT (not connected)
    // { MP_ROM_QSTR(MP_QSTR_CAM_PCLK), MP_ROM_PTR() },           // MicroMod CAM_PCLK  | AUD_IN  | I2S_IN  | PCM_IN (not connected)
    // { MP_ROM_QSTR(MP_QSTR_CAM_TRIG), MP_ROM_PTR(&pin_PB04) },  // MicroMod CAM_TRIG  | D1 (PB4)
    // { MP_ROM_QSTR(MP_QSTR_CAM_HSYNC), MP_ROM_PTR() },          // MicroMod CAM_HSYNC | ADC_D- | G9 (not connected)
    // { MP_ROM_QSTR(MP_QSTR_CAM_VSYNC), MP_ROM_PTR() },          // MicroMod CAM_VSYNC | ADC_D+ | G10 (not connected)

    // CircuitPython board objects
    { MP_ROM_QSTR(MP_QSTR_I2C), MP_ROM_PTR(&board_i2c_obj) },     // CircuitPython I2C
    { MP_ROM_QSTR(MP_QSTR_SPI), MP_ROM_PTR(&board_spi_obj) },     // CircuitPython SPI
    { MP_ROM_QSTR(MP_QSTR_UART), MP_ROM_PTR(&board_uart_obj) },   // CircuitPython UART
};
MP_DEFINE_CONST_DICT(board_module_globals, board_module_globals_table);
