/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_ARDUINO_STM32_
#define _VARIANT_ARDUINO_STM32_

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "pins_arduino.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/
extern const PinName digitalPin[];

enum
{
  //J2 connector Left, Right side - USB side,
  PE2,  //D0
  PE3,  //D1 - BUTTON K1 (USE INPUT_PULLUP)
  PE4,  //D2 - BUTTON K0 (USE INPUT_PULLUP)
  PE5,  //D3
  PE6,  //D4
  PC13, //D5
  PC0,  //D6
  PC1,  //D7
  PC2,  //D8 - SPI2
  PC3,  //D9 - SPI2
  PA0,  //D10 - BUTTON WK_UP (USE INPUT_PULLDOWN for GP button)
  PA1,  //D11
  PA2,  //D12
  PA3,  //D13
  PA4,  //D14
  PA5,  //D15 - SPI1 (or SPI3)
  PA6,  //D16 - BUILTIN LED D2 - SPI1 (or SPI3)
  PA7,  //D17 - BUILTIN LED D3 - SPI1 (or SPI3)
  PC4,  //D18
  PC5,  //D19
  PB0,  //D20 - Flash_CS
  PB1,  //D21 - LCD_BL driver
  PE7,  //D22
  PE8,  //D23
  PE9,  //D24 - SPI2
  PE10, //D25 - SPI2
  PE11, //D26 - SPI2
  PE12, //D27
  PE13, //D28
  PE14, //D29
  PE15, //D30
  PB10, //D31 - I2C2
  PB11, //D32 - I2C2
  PB12, //D33 - SPI2
  PB13, //D34 - SPI2
  PB14, //D35 - SPI3 (or SPI1) - FLASH/NRF

  //J3 connector Left, Right side - SDIO side
  PE1,  //D36
  PE0,  //D37
  PB9,  //D38
  PB8,  //D39 - I2C1
  PB7,  //D40 - I2C1
  PB6,  //D41
  PB5,  //D42 - SPI3 (or SPI1) - FLASH/NRF
  PB3,  //D43 - SPI3 (or SPI1) - FLASH/NRF
  PD7,  //D44
  PD6,  //D45 - USART2
  PD5,  //D46 - USART2
  PD4,  //D47
  PD3,  //D48
  PD2,  //D49 - SDIO
  PD1,  //D50
  PD0,  //D51
  PC12, //D52 - SDIO
  PC11, //D53 - SDIO
  PC10, //D54 - SDIO
  PA15, //D55
  PA12, //D56 - USB DM
  PA11, //D57 - USB DP
  PA10, //D58 - RX1
  PA9,  //D59 - TX1
  PA8,  //D60
  PC9,  //D61 - SDIO
  PC8,  //D62 - SDIO
  PC7,  //D63
  PC6,  //D64
  PD15, //D65
  PD14, //D66
  PD13, //D67
  PD12, //D68
  PD11, //D69
  PD10, //D70
  PD9,  //D71 - USART3
  PD8,  //D72 - USART3
  PB15, //D73
  PA13, //D74 SWDIO (JTAG)
  PA14, //D75 SWCLK (JTAG)
  PB4,  //D76 CONNECTED TO NRF HEADER Pin 7, Winbond Flash Pin 2, NRST JTAG Pin 3
  PB2,  //D77 BOOT1 - J3

  //  PC14,	// XTAL
  //  PC15, // XTAL

  //Duplicated to have A0-A5 as F407 do not have Uno like connector
  // and to be aligned with PinMap_ADC
  PC0_2, //D78/A0
  PC1_2, //D79/A1
  PC2_2, //D80/A2 - SPI2
  PC3_2, //D81/A3 - SPI2
  PA0_2, //D82/A4 - BUTTON WK_UP (USE INPUT_PULLDOWN for GP button)
  PA1_2, //D83/A5
  PA2_2, //D84/A6
  PA3_2, //D85/A7
  PC4_2, //D86/A8
  PC5_2, //D87/A9
  PB0_2, //D88/A10 - Flash_CS
  PB1_2, //D89/A11 - LCD_BL driver
  PEND
};

enum
{
  A_START_AFTER = D77,
  A0,
  A1,
  A2,
  A3,
  A4,
  A5,
  A6,
  A7,
  A8,
  A9,
  A10,
  A11,
  AEND
};

// On-board LED pin number
#define LED_D2 PA6
#define LED_D3 PA7
#define LED_BUILTIN LED_D3 // "D3" LED
#define LED_GREEN LED_D2   // "D2" LED, ALSO RED
#define LED_BLUE LED_D2
#define LED_RED LED_BUILTIN
#define LED_ORANGE LED_D2

//On-board user button
#define BTN_WK_UP PA0
#define BTN_K0 PE3
#define BTN_K1 PE4
#define USER_BTN BTN_K1

// SPI Definitions

//define 16 channels. As many channel as digital IOs
#define SPI_CHANNELS_NUM 16
//default chip seect pin
#define BOARD_SPI_DEFAULT_SS PE11 // PE11 ;PA4:44 hardware note DAC_1 conflict
//In case SPI CS channel is not used we define a default one
#define BOARD_SPI_OWN_SS BOARD_SPI_DEFAULT_SS
#define SPI_INTERFACES_COUNT 3

#define SS BOARD_SPI_DEFAULT_SS
#define SS1 PE9
#define SS2 PE10
#define MOSI PA7
#define MISO PA6
#define SCK PA5

// I2C Definitions
#define SDA PB9
#define SCL PB8

// Timer Definitions
// Do not use timer used by PWM pin. See PinMap_PWM.
#define TIMER_TONE TIM6
#define TIMER_SERVO TIM7
#define TIMER_UART_EMULATED TIM6

// UART Definitions
#define SERIAL_UART_INSTANCE 1 //Connected to ST-Link

// Default pin used for 'Serial' instance (ex: ST-Link)
// Mandatory for Firmata
#define PIN_SERIAL_RX PA10
#define PIN_SERIAL_TX PA9

#ifdef __cplusplus
} // extern "C"
#endif
/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.

// Require connections for ST-LINK VCP on U2 pin 12 and 13.
// See UM �6.1.3 ST-LINK/V2-A VCP configuration)
#define SERIAL_PORT_MONITOR Serial
#define SERIAL_PORT_HARDWARE_OPEN Serial
#endif

#endif /* _VARIANT_ARDUINO_STM32_ */
