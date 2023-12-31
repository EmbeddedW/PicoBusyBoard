#ifndef WS2812_H
#define WS2812_H

#include "main.h"
#include "../include/dio.h"
#define IS_RGBW true

#define FRAC_BITS 4
#define NUM_PIXELS 16
#define WS2812_PIN_BASE 18

#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN
#else
// default to pin 2 if the board doesn't have a default WS2812 pin defined
#define WS2812_PIN 18
#endif

extern uint16_t adc_result;
extern bool button_white;
extern bool button_blue;
extern bool button_yellow;
extern bool button_green;
extern uint8_t board_state;
extern uint8_t TOM_letter;
extern states_t BOARD_STATE;
extern bool LED_RANDOM;
extern bool play_CORRECT;
extern bool play_WRONG;

void led_ws2812();
void ws2812_dma_init();
bool set_lcd_colour();

#endif