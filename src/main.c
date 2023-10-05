#include "../include/main.h"
#include "../include/dio.h"


int main() {

    stdio_init_all();

    leds_init();
    buttons_init();

    xTaskCreate(blink_led, "Blink_led_task", 256, NULL, 1, NULL);
    vTaskStartScheduler();
    return 0;
}

void blink_led(){

    bool test1;
    bool test2;
    bool test3; 
    

    while (true) {
        printf("Set ON LED\n");
        //gpio_put(LED_PIN, 1);

        test();

        // vTaskDelay(500 / portTICK_PERIOD_MS);
        // printf("Set OFF LED\n");     
        // gpio_put(LED_PIN, 0);  
        // vTaskDelay(500 / portTICK_PERIOD_MS);

    }
}


void test(){

        bool test1;
        bool test2;
        bool test3; 

        test1 = gpio_get(BLACK_ONE_BUTTON_PIN);
        test2 = gpio_get(BLACK_TWO_BUTTON_PIN);
        test3 = gpio_get(BLACK_THREE_BUTTON_PIN);

        if (test1) gpio_put(LED_BUTTON_1, 1);
        else gpio_put(LED_BUTTON_1, 0);

        if (test2) gpio_put(LED_BUTTON_2, 1);
        else gpio_put(LED_BUTTON_2, 0);

        if (test3) gpio_put(LED_BUTTON_3, 1);
        else gpio_put(LED_BUTTON_3, 0);

}