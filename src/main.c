#include "../include/main.h"

void blink_led();


static const char MORSE_TEXT[] = "HELLO WORLD";

static const uint8_t PIN_PWM = 2u;
static const uint32_t PWM_TARGET_FREQ = 1000000ul;
static const uint16_t PWM_TARGET_NOTE_HZ = 1000u;

static const float PWM_DUTY = 0.5f;

static const uint SLP_BIT = 50u;
static const uint SLP_CHAR = 150u;
static const uint SLP_SPACE = 350u;

static const uint SLP_DOT = 50u;
static const uint SLP_DASH = 150u;

static const uint16_t SLP_WAIT = 10000u;

static uint clk_sys_hz;
static uint pwm_slice;
static uint pwm_chan;

pwm_config config; 

static void play_dot()
{
  uint16_t test = PWM_TARGET_FREQ / PWM_TARGET_NOTE_HZ - 1;  
  pwm_config_set_wrap(&config, test);
  uint16_t pwm_lvl = test * PWM_DUTY;
  pwm_set_chan_level(pwm_slice, pwm_chan, pwm_lvl); 
  
  pwm_set_enabled(pwm_slice, true);
  sleep_ms(SLP_DOT);
  pwm_set_enabled(pwm_slice, false);
}
static void play_dash()
{
  uint16_t test = PWM_TARGET_FREQ / 2000 - 1;  
  pwm_config_set_wrap(&config, test);
  uint16_t pwm_lvl = test * PWM_DUTY;
  pwm_set_chan_level(pwm_slice, pwm_chan, pwm_lvl); 

  pwm_set_enabled(pwm_slice, true);
  sleep_ms(SLP_DOT);
  pwm_set_enabled(pwm_slice, false);
}

int main() {

    stdio_init_all();

    gpio_set_function(PIN_PWM, GPIO_FUNC_PWM);
    config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, (float) clk_sys_hz / PWM_TARGET_FREQ);
  
    uint16_t pwm_wrap = PWM_TARGET_FREQ / PWM_TARGET_NOTE_HZ - 1;
    pwm_config_set_wrap(&config, pwm_wrap);

    pwm_slice = pwm_gpio_to_slice_num(PIN_PWM);
    pwm_chan = pwm_gpio_to_channel(PIN_PWM);

    uint16_t pwm_lvl = pwm_wrap * PWM_DUTY;

    pwm_init(pwm_slice, &config, false);
    pwm_set_chan_level(pwm_slice, pwm_chan, pwm_lvl); 


    xTaskCreate(blink_led, "Blink_led_task", 256, NULL, 1, NULL);
    vTaskStartScheduler();
    return 0;
}

void blink_led(){

    const uint LED_PIN = 0;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true) {
        play_dot();
        printf("Set ON LED\n");
        gpio_put(LED_PIN, 1);
        vTaskDelay(500 / portTICK_PERIOD_MS);

        play_dash();
        printf("Set OFF LED\n");     
        gpio_put(LED_PIN, 0);  
        vTaskDelay(500 / portTICK_PERIOD_MS);

    }
}
