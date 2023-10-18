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

void test();

#endif