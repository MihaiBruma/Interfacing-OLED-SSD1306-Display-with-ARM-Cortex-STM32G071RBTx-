/*
 * GFX.c
 *
 *  Created on: Jan 11, 2023
 *      Author: Mihai
 */

#include "GFX.h"
#include "font_ascii_5x7.h"

/**************************************************************************/
/*!
   @brief   Draw a single character
    @param    x   Bottom left corner x coordinate
    @param    y   Bottom left corner y coordinate
    @param    c   The 8-bit font-indexed character (likely ascii)
    @param    color 16-bit 5-6-5 Color to draw chraracter with
    @param    bg 16-bit 5-6-5 Color to fill background with (if same as color, no background)
    @param    size_x  Font magnification level in X-axis, 1 is 'original' size
    @param    size_y  Font magnification level in Y-axis, 1 is 'original' size
*/
/**************************************************************************/
void GFX_draw_char(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size_x, uint8_t size_y)
{
	int8_t i, j;
	uint8_t line;

	if((x >= WIDTH) || (y >= HEIGHT) || ((x + 6 * size_x - 1) < 0) || ((y + 8 * size_y - 1) < 0))
	{
		return;
	}

	for(i = 0; i < 5; i++)  // Char bitmap = 5 columns
	{
		line = (*(const unsigned char *)(&font[c * 5 + i]));
		for(j = 7; j >= 0; j--, line >>= 1)
		{
			if(line & 1)
			{
				if(size_x == 1 && size_y == 1)
				{
					SSD1306_draw_pixel(x + i, y + j, color);
				}
				else
				{
					GFX_draw_fill_rect(x + i * size_x, y + j * size_y, size_x, size_y, color);
				}
			}
			else if(bg != color)
			{
				if(size_x == 1 && size_y == 1)
				{
					SSD1306_draw_pixel(x + i, y + j, bg);
				}
				else
				{
					GFX_draw_fill_rect(x + i * size_x, y + j * size_y, size_x, size_y, bg);
				}
			}
		}
	}

	if(bg != color) // If opaque, draw vertical line for last column
	{
		if(size_x == 1 && size_y == 1)
		{
			SSD1306_draw_fast_vline(x + 5, y, 8, bg);
		}
		else
		{
			GFX_draw_fill_rect(x + 5 * size_x, y, size_x, 8 * size_y, bg);
		}
	}
}

/**************************************************************************/
/*!
   @brief   Draw a set of characters
    @param    x   Bottom left corner x coordinate
    @param    y   Bottom left corner y coordinate
    @param    c   The 8-bit font-indexed characters (likely ascii)
    @param    color 16-bit 5-6-5 Color to draw chraracter with
    @param    bg 16-bit 5-6-5 Color to fill background with (if same as color, no background)
    @param    size_x  Font magnification level in X-axis, 1 is 'original' size
    @param    size_y  Font magnification level in Y-axis, 1 is 'original' size
*/
/**************************************************************************/
void GFX_draw_string(int16_t x, int16_t y, unsigned char * c, uint16_t color, uint16_t bg, uint8_t size_x, uint8_t size_y)
{
	uint8_t offset = 0;
	while(*c)
	{
		GFX_draw_char(x+offset, y, *c, color, bg, size_x, size_y);
		offset += (5 + 2) * size_x;
		c++;
	}
}

/**************************************************************************/
/*!
   @brief    Fill a rectangle completely with one color. Update in subclasses if desired!
    @param    x   Top left corner x coordinate
    @param    y   Top left corner y coordinate
    @param    w   Width in pixels
    @param    h   Height in pixels
    @param    color 16-bit 5-6-5 Color to fill with
*/
/**************************************************************************/
void GFX_draw_fill_rect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
{
	for(int16_t i = x; i < x + w; i++)
	{
		SSD1306_draw_fast_vline(i, y, h, color);
	}
}
