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