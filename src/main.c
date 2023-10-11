#include "../include/main.h"
#include "../include/dio.h"
#include "../include/buzzer.h"
#include  "../include/ws2812.h"


extern note_struct turnON[];
extern note_struct wish[];

uint slice_num;


int main() {

    stdio_init_all();    
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    buzzer_init();
    leds_init();
    buttons_init();

    // todo get free sm
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);
    xTaskCreate(buzzer, "Blink_led_task", 128, NULL, 2, NULL);
    xTaskCreate(led_ws2812, "Led_WS2812 Controll", 128, NULL, 3, NULL);
    xTaskCreate(dio_test, "DIO Controll", 10, NULL, 1, NULL);


    vTaskStartScheduler();
    return 0;
}


