#ifndef MAIN_H
#define MAIN_H

#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/uart.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "../PicoRGB/ws2812pio.h"
#include "hardware/pwm.h"
#include "hardware/adc.h"
#include "pico/sem.h"
#include "hardware/dma.h"
#include "hardware/irq.h"

typedef enum{

    IDLE = 0,
    BUZZER_BUTTONS,
    BUZZER_NUTES,
    LCD_COLORS,
    LCD_BUTTONS,
    LCD_PIXELS,
    ADC_SNAKE,
    GAME = 7,
} states_t;

#endif