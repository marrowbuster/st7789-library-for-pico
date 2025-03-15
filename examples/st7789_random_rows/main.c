/*
 * Copyright (c) 2021 Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 * 
 */

#include <stdlib.h>

#include "pico/stdlib.h"
#include "pico/st7789.h"

// lcd configuration
const struct st7789_config lcd_config = {
    .spi      = SPI_INSTANCE(1),
    .gpio_din = 11,
    .gpio_clk = 10,
    .gpio_cs  = 9,
    .gpio_dc  = 8,
    .gpio_rst = 12,
    .gpio_bl  = 13,
};

#define LCD_WIDTH  240
#define LCD_HEIGHT 240

uint16_t row_pixels[LCD_WIDTH];

int main()
{
    // initialize the lcd
    st7789_init(&lcd_config, LCD_WIDTH, LCD_HEIGHT);

    // make screen black
    st7789_fill(0x0000);

    while (1) {
        // create a random y and color value
        int rand_y = rand() % LCD_HEIGHT;
        uint16_t rand_color = rand() % 0xffff;
        
        // move the cursor to the y position
        st7789_set_cursor(0, rand_y);

        // set the row pixels buffer to the color value
        for (int i = 0; i < LCD_WIDTH; i++) {
            row_pixels[i] = rand_color;
        }

        // write the row pixel values
        st7789_write(row_pixels, sizeof(row_pixels));
    }
}
