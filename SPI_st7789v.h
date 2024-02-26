/*
 * SPI_st7789v.h
 *
 *  Created on: 25 feb. 2024
 *      Author: Usuario
 */

#ifndef SPI_ST7789V_H_
#define SPI_ST7789V_H_


#endif /* SPI_ST7789V_H_ */

#pragma once

#include <stdint.h>
#include "cy_result.h"
#include "cyhal_gpio.h"

#if defined(__cplusplus)
extern "C"
{
#endif
/** Configuration structure defining the pins used to communicate with the TFT display. */
typedef struct
{
    cyhal_gpio_t MOSI;  /**< Pin for the Display Data8 signal */
    cyhal_gpio_t MISO;  /**< Pin for the Display Data9 signal */
    cyhal_gpio_t SCK;  /**< Pin for the Display Data10 signal */
    cyhal_gpio_t SS;  /**< Pin for the Display Data11 signal */
    cyhal_gpio_t dc;
    cyhal_gpio_t rst;
    uint32_t frec;
    } SPI_st7789v_pins_t;
    cy_rslt_t SPI_st7789v_init8(const SPI_st7789v_pins_t *pins);
    void SPI_st7789v_write_reset_pin(bool value);
    void SPI_st7789v_write_command(uint8_t command);
    void SPI_st7789v_write_data(uint8_t data);
    void SPI_st7789v_write_command_stream(uint8_t *data, int num);
    void SPI_st7789v_write_data_stream(uint8_t *data, int num);
    uint8_t SPI_st7789v_read_data(void);
    void SPI_st7789v_read_data_stream(uint8_t *data, int num);
    #if defined(__cplusplus)
    }
    #endif
