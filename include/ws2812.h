#ifndef WS2812_H
#define WS2812_H

#include "main.h"

#define IS_RGBW true
#define NUM_PIXELS 16

#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN
#else
// default to pin 2 if the board doesn't have a default WS2812 pin defined
#define WS2812_PIN 18
#endif

extern uint16_t adc_result;

void led_ws2812();

#endif