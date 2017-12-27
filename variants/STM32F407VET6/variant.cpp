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

#include "variant.h"

#ifdef __cplusplus
extern "C" {
#endif

// Pin number
const PinName digitalPin[] = {
    //J2 connector Left, Right side - USB side,
    PE_2,  //D0
    PE_3,  //D1 - BUTTON K1 (USE INPUT_PULLUP)
    PE_4,  //D2 - BUTTON K0 (USE INPUT_PULLUP)
    PE_5,  //D3
    PE_6,  //D4
    PC_13, //D5
    PC_0,  //D6
    PC_1,  //D7
    PC_2,  //D8 - SPI2
    PC_3,  //D9 - SPI2
    PA_0,  //D10 - BUTTON WK_UP (USE INPUT_PULLDOWN for GP button)
    PA_1,  //D11
    PA_2,  //D12
    PA_3,  //D13
    PA_4,  //D14
    PA_5,  //D15 - SPI1 (or SPI3)
    PA_6,  //D16 - BUILTIN LED D2 - SPI1 (or SPI3)
    PA_7,  //D17 - BUILTIN LED D3 - SPI1 (or SPI3)
    PC_4,  //D18
    PC_5,  //D19
    PB_0,  //D20 - Flash_CS
    PB_1,  //D21 - LCD_BL driver
    PE_7,  //D22
    PE_8,  //D23
    PE_9,  //D24 - SPI2
    PE_10, //D25 - SPI2
    PE_11, //D26 - SPI2
    PE_12, //D27
    PE_13, //D28
    PE_14, //D29
    PE_15, //D30
    PB_10, //D31 - I2C2
    PB_11, //D32 - I2C2
    PB_12, //D33 - SPI2
    PB_13, //D34 - SPI2
    PB_14, //D35 - SPI3 (or SPI1) - FLASH/NRF

    //J3 connector Left, Right side - SDIO side
    PE_1,  //D36
    PE_0,  //D37
    PB_9,  //D38
    PB_8,  //D39 - I2C1
    PB_7,  //D40 - I2C1
    PB_6,  //D41
    PB_5,  //D42 - SPI3 (or SPI1) - FLASH/NRF
    PB_3,  //D43 - SPI3 (or SPI1) - FLASH/NRF
    PD_7,  //D44
    PD_6,  //D45 - USART2
    PD_5,  //D46 - USART2
    PD_4,  //D47
    PD_3,  //D48
    PD_2,  //D49 - SDIO
    PD_1,  //D50
    PD_0,  //D51
    PC_12, //D52 - SDIO
    PC_11, //D53 - SDIO
    PC_10, //D54 - SDIO
    PA_15, //D55
    PA_12, //D56 - USB DM
    PA_11, //D57 - USB DP
    PA_10, //D58 - RX1
    PA_9,  //D59 - TX1
    PA_8,  //D60
    PC_9,  //D61 - SDIO
    PC_8,  //D62 - SDIO
    PC_7,  //D63
    PC_6,  //D64
    PD_15, //D65
    PD_14, //D66
    PD_13, //D67
    PD_12, //D68
    PD_11, //D69
    PD_10, //D70
    PD_9,  //D71 - USART3
    PD_8,  //D72 - USART3
    PB_15, //D73
    PA_13, //D74 SWDIO (JTAG)
    PA_14, //D75 SWCLK (JTAG)
    PB_4,  //D76 CONNECTED TO NRF HEADER Pin 7, Winbond Flash Pin 2, NRST JTAG Pin 3
    PB_2,  //D77 BOOT1 - J3

    //  PC_14,	// XTAL
    //  PC_15, // XTAL

    // PortPins duplicated to have A0-A9 as F407 do not have Uno like connector
    // Update PeripheralPins.c to match
    PC_0, //D78/A0
    PC_1, //D79/A1
    PC_2, //D80/A2 - SPI2
    PC_3, //D81/A3 - SPI2
    PA_0, //D82/A4 - BUTTON WK_UP (USE INPUT_PULLDOWN for GP button)
    PA_1, //D83/A5
    PA_2, //D84/A6
    PA_3, //D85/A7
    PC_4, //D86/A8
    PC_5, //D87/A9
    PB_0, //D88/A10 - Flash_CS
    PB_1, //D89/A11 - LCD_BL driver

    // need to add J1 (TFT connector)?
};

#ifdef __cplusplus
}
#endif

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow :
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 168000000
  *            HCLK(Hz)                       = 168000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 8000000
  *            PLL_M                          = 8
  *            PLL_N                          = 336
  *            PLL_P                          = 2
  *            PLL_Q                          = 7
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 5
  * @param  None
  * @retval None
  */
WEAK void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Enable Power Control clock */
  __HAL_RCC_PWR_CLK_ENABLE();

  /* The voltage scaling allows optimizing the power consumption when the device is
     clocked below the maximum system frequency, to update the voltage scaling value
     regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK |
                                 RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);

  /* STM32F405x/407x/415x/417x Revision Z devices: prefetch is supported  */
  if (HAL_GetREVID() == 0x1001)
  {
    /* Enable the Flash prefetch */
    __HAL_FLASH_PREFETCH_BUFFER_ENABLE();
  }
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq() / 1000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

#ifdef __cplusplus
}
#endif
