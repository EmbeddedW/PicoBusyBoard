#include "../include/main.h"


#include  "../include/ws2812.h"


void blink_led();


int main() {

    stdio_init_all();
    printf("WS2812 Smoke Test, using pin %d", WS2812_PIN);

    // todo get free sm
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);
    xTaskCreate(blink_led, "Blink_led_task", 256, NULL, 1, NULL);
    xTaskCreate(led_ws2812, "Led_WS2812 Controll", 256, NULL, 1, NULL);

    vTaskStartScheduler();
    return 0;
}

void blink_led(){

    // const uint LED_PIN = 25;
    // gpio_init(LED_PIN);
    // gpio_set_dir(LED_PIN, GPIO_OUT);


    while (true) {
        printf("Set ON LED\n");
        //gpio_put(LED_PIN, 1);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        printf("Set OFF LED\n");     
        //gpio_put(LED_PIN, 0);  
        vTaskDelay(500 / portTICK_PERIOD_MS);

    }
}



