#include "../include/main.h"
#include "../include/dio.h"
#include "../include/buzzer.h"
#include  "../include/ws2812.h"


extern note_struct turnON[];
extern note_struct wish[];
extern note_struct HappyBirday[];

extern note_struct christmas[]; // 26
extern note_struct wish[];      // 30
extern note_struct santa[];     // 28
extern note_struct Mario_melody[]; // 77



void board_buttons();
void adc_task();
void buttons_melody();

#define ADC_PIN 28

static const uint8_t PIN_PWM = 14u;
uint16_t adc_result;
uint  slice_num;

states_t BOARD_STATE;
bool LED_RANDOM;


uint board_state;

 bool button_black_1;
 bool button_black_2;
 bool button_black_3; 
 bool button_white;
 bool button_blue;
 bool button_yellow;
 bool button_green;

int main() {

    stdio_init_all();    
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_set_function(PIN_PWM, GPIO_FUNC_PWM);
    slice_num = pwm_gpio_to_slice_num(PIN_PWM); 

    leds_init();
    buttons_init();

    ws2812_dma_init();

    adc_init();
    adc_gpio_init(ADC_PIN);
    adc_select_input(2);

    xTaskCreate(board_buttons, "Blink_led_task", 256, NULL, 2, NULL);
    xTaskCreate(led_ws2812, "Led_WS2812 Controll", 256, NULL, 1, NULL);

    xTaskCreate(adc_task, "Led_WS2812 Controll", 32, NULL, 2, NULL);

    vTaskStartScheduler();
    return 0;
}

void board_buttons(){

    play_melody(slice_num, turnON, 200, 3);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    int buttons_value = IDLE;

    while (true) {

        button_black_1 = gpio_get(BLACK_ONE_BUTTON_PIN);
        button_black_2 = gpio_get(BLACK_TWO_BUTTON_PIN);
        button_black_3 = gpio_get(BLACK_THREE_BUTTON_PIN);

        button_white    = gpio_get(WHITE_BUTTON_PIN);
        button_blue     = gpio_get(BLUE_BUTTON_PIN);
        button_yellow   = gpio_get(YELLOW_BUTTON_PIN);
        button_green    = gpio_get(GREEN_BUTTON_PIN);

        buttons_value = button_black_1 | (button_black_2 << 1) | (button_black_3 << 2);

        switch (buttons_value)
        {
        case GAME:
            BOARD_STATE = GAME;
            break;
        case BUZZER_BUTTONS:
            BOARD_STATE = BUZZER_BUTTONS;
            break;        
        case BUZZER_NUTES:
            BOARD_STATE = BUZZER_NUTES;
            break;
        case LCD_COLORS:
            BOARD_STATE = LCD_COLORS;
            break;
        case LCD_BUTTONS:
            BOARD_STATE = LCD_BUTTONS;
            break;
        case IDLE:
            BOARD_STATE = IDLE;
            break;               
        default:
            BOARD_STATE = IDLE;
            break;
        }

    if(BOARD_STATE == BUZZER_NUTES)
    {
        if (button_green) play_melody(slice_num, turnON, 200, 3);
        else if (button_yellow) play_melody(slice_num, turnON, 200, 3);
        else if (button_blue) play_melody(slice_num, turnON, 200, 3);
        else if (button_white) play_melody(slice_num, turnON, 200, 3);
    } 
    else if (BOARD_STATE == BUZZER_BUTTONS)
    {
        int pat = 0;

        if (button_green) 
        {
        LED_RANDOM = 1;
        play_melody(slice_num, Mario_melody, 200, 77);
        }
        else if (button_yellow) 
        {
        LED_RANDOM = 1;
        play_melody(slice_num, turnON, 200, 3);
        }
        else if (button_blue) 
        {
        LED_RANDOM = 1;
        play_melody(slice_num, HappyBirday, 200, 26);}
        else if (button_white) {
            pat = rand() % 3;
            switch (pat)
            {
            case 0:
                LED_RANDOM = 1;
                play_melody(slice_num, christmas, 200, 26);
                break;                
            case 1:
                LED_RANDOM = 1;
                play_melody(slice_num, wish, 200, 30);
                break;
            case 2:
                LED_RANDOM = 1;
                play_melody(slice_num, santa, 200, 28);
                break;                
            
            default:
                LED_RANDOM = 0;
                break;
            }

            }

    LED_RANDOM = 0;
    }

        if (button_black_1) gpio_put(LED_BUTTON_1, 0);
        else gpio_put(LED_BUTTON_1, 1);

        if (button_black_2) gpio_put(LED_BUTTON_2, 0);
        else gpio_put(LED_BUTTON_2, 1);

        if (button_black_3) gpio_put(LED_BUTTON_3, 0);
        else gpio_put(LED_BUTTON_3, 1);

        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}


void adc_task(){


    while (true) {
        adc_result = adc_read();
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}


