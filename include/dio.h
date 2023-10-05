#ifndef DIO_H
#define DIO_H

#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"

#define LED_PIN 25
#define LED_BUTTON_1 10
#define LED_BUTTON_2 11
#define LED_BUTTON_3 12

#define GREEN_BUTTON_PIN 2
#define YELLOW_BUTTON_PIN 3
#define BLUE_BUTTON_PIN 4
#define WHITE_BUTTON_PIN 5
#define BLACK_ONE_BUTTON_PIN 6
#define BLACK_TWO_BUTTON_PIN 7
#define BLACK_THREE_BUTTON_PIN 8


void buttons_init();
void leds_init();
void blink_led();


#endif