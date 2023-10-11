#include "../include/dio.h"


void buttons_init()
{

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

void leds_init(){

    gpio_init(LED_PIN);
    gpio_init(LED_BUTTON_1);
    gpio_init(LED_BUTTON_2);
    gpio_init(LED_BUTTON_3);
    
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_set_dir(LED_BUTTON_1, GPIO_OUT);
    gpio_set_dir(LED_BUTTON_2, GPIO_OUT);
    gpio_set_dir(LED_BUTTON_3, GPIO_OUT);

}



void dio_test(){

        bool test1;
        bool test2;
        bool test3; 

    while (true) {

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

}