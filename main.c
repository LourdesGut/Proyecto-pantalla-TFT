/*******************************************************************************
* File Name:   main.c
*
* Description: This is the source code for the Empty Application Example
*              for ModusToolbox.
*
* Related Document: See README.md
*
*
*******************************************************************************
* Copyright 2021-2024, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*
* This software, including source code, documentation and related
* materials ("Software") is owned by Cypress Semiconductor Corporation
* or one of its affiliates ("Cypress") and is protected by and subject to
* worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software
* source code solely for use in connection with Cypress's
* integrated circuit products.  Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/

/*******************************************************************************
* Header Files
*******************************************************************************/
#include "cyhal.h"
#include "cybsp.h"
#include "cy_pdl.h"
#include "GUI.h"
#include "SPI_st7789v.h"
#include "cy_retarget_io.h"
#include "LCDConf.h"
const SPI_st7789v_pins_t tft_pins =
{
		.MOSI = P6_0,
		.MISO = P6_1,
		.SCK = P6_2,
		.SS = P6_3,
		.dc = P9_7,
		.rst = P9_4,
		.frec= 8000000
};

/******************************************************************************
* Macros
*******************************************************************************/


/*******************************************************************************
* Global Variables
*******************************************************************************/


/*******************************************************************************
* Function Prototypes
*******************************************************************************/


/*******************************************************************************
* Function Definitions
*******************************************************************************/

/*******************************************************************************
* Function Name: main
*********************************************************************************
* Summary:
* This is the main function for CPU. It...
*    1.
*    2.
*
* Parameters:
*  void
*
* Return:
*  int
*
******************************************************************************/
extern GUI_CONST_STORAGE GUI_BITMAP bmUTN_logo;
int main(void)
{
    cy_rslt_t result;

#if defined (CY_DEVICE_SECURE)
    cyhal_wdt_t wdt_obj;

    /* Clear watchdog timer so that it doesn't trigger a reset */
    result = cyhal_wdt_init(&wdt_obj, cyhal_wdt_get_max_timeout_ms());
    CY_ASSERT(CY_RSLT_SUCCESS == result);
    cyhal_wdt_free(&wdt_obj);
#endif

    /* Initialize the device and board peripherals */
    result = cybsp_init();

    /* Board init failed. Stop program execution */
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }

    /* Enable global interrupts */
    __enable_irq();

    result = SPI_st7789v_init8(&tft_pins);
        CY_ASSERT(result == CY_RSLT_SUCCESS);

        GUI_Init();
        GUI_SetBkColor(GUI_WHITE);
        GUI_Clear();
        GUI_SetBkColor(GUI_BLACK);
        GUI_Clear();
            GUI_DispStringAt("PROYECTO FINAL", 70, 100);
            GUI_DrawRect(50, 60, 205, 180);
            GUI_Delay(5000);
            GUI_Clear();
            GUI_DispStringAt("TECNICAS", 70, 100);
            GUI_DispStringAt("DIGITALES II", 65, 130);
            GUI_DrawRect(50, 60, 200, 180);
            GUI_Delay(5000);
            GUI_Clear();

            GUI_DrawBitmap(&bmUTN_logo, 30,57);
                        GUI_SetFont(GUI_FONT_20B_1);
                        GUI_SetBkColor(GUI_BLACK);
                        GUI_Delay(7000);
                        GUI_Clear();
                        GUI_SetColor(GUI_WHITE);

            GUI_DispStringAt("Profesor:", 50, 30);
            GUI_DispStringAt("Ing. Mansilla Ruben", 50, 70);
            GUI_DrawRect( 10, 10, 230, 230);
            GUI_Delay(5000);
            GUI_Clear();
            GUI_DispStringAt("Alumnas:", 50, 30);
            GUI_DispStringAt("Gutierrez Lourdes", 50, 70);
            GUI_DispStringAt("Pacheco Rocio", 50, 110);
            GUI_DispStringAt("Veliz Nazarena", 50, 150);
            GUI_DrawRect( 10, 10, 230, 230);
            GUI_Delay(5000);
            GUI_Clear();
            for ( ; ; ){
            }

        while(1)
        {
           // Infinite loop...
        }
    }


/* [] END OF FILE */
