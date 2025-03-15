/*
 * Copyright (c) 2021 Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 * 
 */

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

    while (1) {
        // make screen black
        st7789_fill(0x0000);

        // wait 1 second
        sleep_ms(1000);

        // make screen white
        st7789_fill(0xffff);

        // wait 1 second
        sleep_ms(1000);
    }
}
