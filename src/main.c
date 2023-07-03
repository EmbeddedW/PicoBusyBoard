#include "../include/main.h"

void blink_led();


int main() {


    xTaskCreate(blink_led, "Blink_led_task", 256, NULL, 1, NULL);
    vTaskStartScheduler();
    return 0;
}

void blink_led(){

    const uint LED_PIN = 0;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true) {
        gpio_put(LED_PIN, 1);
        vTaskDelay(500 / portTICK_PERIOD_MS);     
        gpio_put(LED_PIN, 0);  
        vTaskDelay(500 / portTICK_PERIOD_MS);

    }
}
