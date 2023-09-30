#include "../include/main.h"

void buttons_init();
void blink_led();


const uint LED_PIN = 25;

const uint GREEN_BUTTON_PIN = 2;
const uint YELLOW_BUTTON_PIN = 3;
const uint BLUE_BUTTON_PIN = 4;
const uint WHITE_BUTTON_PIN = 5;

const uint BLACK_ONE_BUTTON_PIN = 6;
const uint BLACK_TWO_BUTTON_PIN = 7;
const uint BLACK_THREE_BUTTON_PIN = 8;  

int main() {

    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    buttons_init();

    xTaskCreate(blink_led, "Blink_led_task", 256, NULL, 1, NULL);
    vTaskStartScheduler();
    return 0;
}

void blink_led(){

    bool test; 

    while (true) {
        printf("Set ON LED\n");
        //gpio_put(LED_PIN, 1);

        test = gpio_get(WHITE_BUTTON_PIN);

        if (test) gpio_put(LED_PIN, 1);
        else gpio_put(LED_PIN, 0);

        // vTaskDelay(500 / portTICK_PERIOD_MS);
        // printf("Set OFF LED\n");     
        // gpio_put(LED_PIN, 0);  
        // vTaskDelay(500 / portTICK_PERIOD_MS);

    }
}

void buttons_init(){

  gpio_init(GREEN_BUTTON_PIN);
  gpio_init(YELLOW_BUTTON_PIN);
  gpio_init(BLUE_BUTTON_PIN);
  gpio_init(WHITE_BUTTON_PIN);
  
  gpio_init(BLACK_ONE_BUTTON_PIN);
  gpio_init(BLACK_TWO_BUTTON_PIN);
  gpio_init(BLACK_THREE_BUTTON_PIN);

  gpio_set_dir(GREEN_BUTTON_PIN, GPIO_IN);
  gpio_set_dir(YELLOW_BUTTON_PIN, GPIO_IN);
  gpio_set_dir(BLUE_BUTTON_PIN, GPIO_IN);
  gpio_set_dir(WHITE_BUTTON_PIN, GPIO_IN);

  gpio_set_dir(BLACK_ONE_BUTTON_PIN, GPIO_IN);
  gpio_set_dir(BLACK_TWO_BUTTON_PIN, GPIO_IN);
  gpio_set_dir(BLACK_THREE_BUTTON_PIN, GPIO_IN);
  

}