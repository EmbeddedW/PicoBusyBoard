#include "../include/main.h"
#include "../include/buzzer.h"


extern note_struct turnON[];
extern note_struct wish[];

void blink_led();
static const uint8_t PIN_PWM = 14u;
const uint LED_PIN = 25;
uint  slice_num;

int main() {

    stdio_init_all();    
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_set_function(PIN_PWM, GPIO_FUNC_PWM);
    slice_num = pwm_gpio_to_slice_num(PIN_PWM); 

    xTaskCreate(blink_led, "Blink_led_task", 256, NULL, 1, NULL);
    vTaskStartScheduler();
    return 0;
}

void blink_led(){


    play_melody(slice_num, turnON, 200, 3);
    vTaskDelay(500 / portTICK_PERIOD_MS);

    while (true) {
        play_melody(slice_num, wish, 200, 30);
        printf("Set ON LED\n");
        gpio_put(LED_PIN, 1);
        vTaskDelay(500 / portTICK_PERIOD_MS);

        printf("Set OFF LED\n");     
        gpio_put(LED_PIN, 0);  
        vTaskDelay(500 / portTICK_PERIOD_MS);

    }
}
