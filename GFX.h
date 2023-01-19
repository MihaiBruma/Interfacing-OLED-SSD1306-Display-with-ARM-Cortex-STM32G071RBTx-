/*
 * GFX.h
 *
 *  Created on: Jan 11, 2023
 *      Author: Mihai
 */

#ifndef INC_GFX_H_
#define INC_GFX_H_

#include <stdint.h>
#include "SSD1306.h"

#define WIDTH SSD1306_WIDTH
#define HEIGHT SSD1306_HEIGHT

void GFX_draw_char(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size_x, uint8_t size_y);
void GFX_draw_string(int16_t x, int16_t y, unsigned char * c, uint16_t color, uint16_t bg, uint8_t size_x, uint8_t size_y);
void GFX_draw_fill_rect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);

#endif /* INC_GFX_H_ */
