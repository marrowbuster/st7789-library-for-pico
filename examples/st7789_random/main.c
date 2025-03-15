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

int main()
{
    // initialize the lcd
    st7789_init(&lcd_config, LCD_WIDTH, LCD_HEIGHT);

    // make screen black
    st7789_fill(0x0000);

    while (1) {
        // create a random x, y, and color value
        int rand_x = rand() % LCD_WIDTH;
        int rand_y = rand() % LCD_HEIGHT;
        uint16_t rand_color = rand() % 0xffff;
        
        // move the cursor to the random x and y position
        st7789_set_cursor(rand_x, rand_y);

        // put the random color as the pixel value
        st7789_put(rand_color);
    }
}
