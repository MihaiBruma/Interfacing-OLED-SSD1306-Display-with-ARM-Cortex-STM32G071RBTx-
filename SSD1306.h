/*
 * SSD1306.h
 *
 *  Created on: Jan 11, 2023
 *      Author: Mihai
 */

#ifndef _SSD1306_H_
#define _SSD1306_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define SSD1306_WIDTH	128
#define SSD1306_HEIGHT	64

#define SSD1306_I2C_ADDRESS (0x3C << 1)
#define SSD1306_I2C_BUS hi2c1

#define SSD1306_SPI_BUS hspi2

/* The following "raw" color names are kept for backwards client compatability
 * They can be disabled by predefining this macro before including the Adafruit
 * header client code will then need to be modified to use the scoped enum
 * values directly
 */
#ifndef NO_ADAFRUIT_SSD1306_COLOR_COMPATIBILITY
#define BLACK SSD1306_BLACK     //< Draw 'off' pixels
#define WHITE SSD1306_WHITE     //< Draw 'on' pixels
#define INVERSE SSD1306_INVERSE //< Invert pixels
#endif
/* fit into the SSD1306_ naming scheme */
#define SSD1306_BLACK 0   //< Draw 'off' pixels
#define SSD1306_WHITE 1   //< Draw 'on' pixels
#define SSD1306_INVERSE 2 //< Invert pixels

/* Screen orientation */
#define SSD1306_HORIZONTAL_MODE1 0
#define SSD1306_VERTICAL 1
#define SSD1306_HORIZONTAL_MODE2 2

#define SSD1306_MEMORYMODE 0x20          //< See datasheet
#define SSD1306_COLUMNADDR 0x21          //< See datasheet
#define SSD1306_PAGEADDR 0x22            //< See datasheet
#define SSD1306_SETCONTRAST 0x81         //< See datasheet
#define SSD1306_CHARGEPUMP 0x8D          //< See datasheet
#define SSD1306_SEGREMAP 0xA0            //< See datasheet
#define SSD1306_DISPLAYALLON_RESUME 0xA4 //< See datasheet
#define SSD1306_DISPLAYALLON 0xA5        //< Not currently used
#define SSD1306_NORMALDISPLAY 0xA6       //< See datasheet
#define SSD1306_INVERTDISPLAY 0xA7       //< See datasheet
#define SSD1306_SETMULTIPLEX 0xA8        //< See datasheet
#define SSD1306_DISPLAYOFF 0xAE          //< See datasheet
#define SSD1306_DISPLAYON 0xAF           //< See datasheet
#define SSD1306_COMSCANINC 0xC0          //< Not currently used
#define SSD1306_COMSCANDEC 0xC8          //< See datasheet
#define SSD1306_SETDISPLAYOFFSET 0xD3    //< See datasheet
#define SSD1306_SETDISPLAYCLOCKDIV 0xD5  //< See datasheet
#define SSD1306_SETPRECHARGE 0xD9        //< See datasheet
#define SSD1306_SETCOMPINS 0xDA          //< See datasheet
#define SSD1306_SETVCOMDETECT 0xDB       //< See datasheet

#define SSD1306_SETLOWCOLUMN 0x00  		 //< Not currently used
#define SSD1306_SETHIGHCOLUMN 0x10 		 //< Not currently used
#define SSD1306_SETSTARTLINE 0x40  		 //< See datasheet

#define SSD1306_EXTERNALVCC 0x01  		 //< External display voltage source
#define SSD1306_SWITCHCAPVCC 0x02 		 //< Gen. display voltage from 3.3V

#define SSD1306_RIGHT_HORIZONTAL_SCROLL 0x26              //< Init rt scroll
#define SSD1306_LEFT_HORIZONTAL_SCROLL 0x27               //< Init left scroll
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29 //< Init diag scroll
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A  //< Init diag scroll
#define SSD1306_DEACTIVATE_SCROLL 0x2E                    //< Stop scroll
#define SSD1306_ACTIVATE_SCROLL 0x2F                      //< Start scroll
#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3             //< Set scroll range

bool SSD1306_init(void);
void SSD1306_draw_pixel(int16_t x, int16_t y, uint16_t color);
void SSD1306_display_clear(void);
void SSD1306_draw_fast_hline(int16_t x, int16_t y, int16_t w, uint16_t color);
void SSD1306_draw_fast_hline_internal(int16_t x, int16_t y, int16_t w, uint16_t color);
void SSD1306_draw_fast_vline(int16_t x, int16_t y, int16_t h, uint16_t color);
void SSD1306_draw_fast_vline_internal(int16_t x, int16_t __y, int16_t __h, uint16_t color);
bool SSD1306_get_pixel(int16_t x, int16_t y);
uint8_t* SSD1306_get_buffer(void);
void SSD1306_display_repaint(void);
void SSD1306_start_scroll_right(uint8_t start, uint8_t stop);
void SSD1306_start_scroll_left(uint8_t start, uint8_t stop);
void SSD1306_start_scroll_diagright(uint8_t start, uint8_t stop);
void SSD1306_start_scroll_diagleft(uint8_t start, uint8_t stop);
void SSD1306_stop_scroll(void);
void SSD1306_display_invert(bool i);
void SSD1306_set_contrast(uint8_t contrast);
void SSD1306_set_rotation(uint8_t rot);
uint8_t SSD1306_get_rotation(void);

#endif // __SSD1306_H_
