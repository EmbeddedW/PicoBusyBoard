#include "../include/buzzer.h"

extern uint slice_num;

static const uint8_t PIN_PWM = 14u;

// 3 nutes
note_struct turnON[] = {{NOTE_A6, 8}, {NOTE_CS7, 8}, {NOTE_E7, 8}};

// 77 nutes
note_struct Mario_melody[] = {
  {NOTE_E7,SPEED_1}, {NOTE_E7,SPEED_1}, {REST,SPEED_1}, {NOTE_E7, SPEED_1},
  {REST,SPEED_1}, {NOTE_C7,SPEED_1}, {NOTE_E7,SPEED_1}, //{REST,SPEED_1},
  {NOTE_G7,SPEED_1}, {REST,SPEED_1}, {REST,SPEED_1},  {REST,SPEED_1},
  {NOTE_G6,SPEED_1}, {REST,SPEED_1}, {REST,SPEED_1},  {REST,SPEED_1},

  {NOTE_C7,SPEED_1}, {REST,SPEED_1}, {REST,SPEED_1}, {NOTE_G6,SPEED_1},
  {REST,SPEED_1}, {REST,SPEED_1}, {NOTE_E6,SPEED_1}, {REST,SPEED_1},
  {REST,SPEED_1}, {NOTE_A6,SPEED_1}, {REST,SPEED_1}, {NOTE_B6,SPEED_1},
  {REST,SPEED_1}, {NOTE_AS6,SPEED_1}, {NOTE_A6,SPEED_1}, {REST,SPEED_1},

  {NOTE_G6,SPEED_2}, {NOTE_E7,SPEED_2}, {NOTE_G7,SPEED_2},
  {NOTE_A7,SPEED_1}, {REST,SPEED_1}, {NOTE_F7,SPEED_1}, {NOTE_G7,SPEED_1},
  {REST,SPEED_1}, {NOTE_E7,SPEED_1}, {REST,SPEED_1}, {NOTE_C7,SPEED_1},
  {NOTE_D7,SPEED_1}, {NOTE_B6,SPEED_1}, {REST,SPEED_1}, {REST,SPEED_1},

  {NOTE_C7,SPEED_1}, {REST,SPEED_1}, {REST,SPEED_1}, {NOTE_G6,SPEED_1},
  {REST,SPEED_1}, {REST,SPEED_1}, {NOTE_E6,SPEED_1}, {REST,SPEED_1},
  {REST,SPEED_1}, {NOTE_A6,SPEED_1}, {REST,SPEED_1}, {NOTE_B6,SPEED_1},
  {REST,SPEED_1}, {NOTE_AS6,SPEED_1}, {NOTE_A6,SPEED_1}, {REST,SPEED_1},

  {NOTE_G6,SPEED_2}, {NOTE_E7,SPEED_2}, {NOTE_G7,SPEED_2},
  {NOTE_A7,SPEED_1}, {REST,SPEED_1}, {NOTE_F7,SPEED_1}, {NOTE_G7,SPEED_1},
  {REST,SPEED_1}, {NOTE_E7,SPEED_1}, {REST,SPEED_1}, {NOTE_C7,SPEED_1},
  {NOTE_D7,SPEED_1}, {NOTE_B6,SPEED_1}, {REST,SPEED_1}, {REST,SPEED_1}
};

// 26 nutes
note_struct christmas[] = {
	{NOTE_E5,8}, {NOTE_E5,8}, {NOTE_E5,4},
	{NOTE_E5,8}, {NOTE_E5,8}, {NOTE_E5,4},
	{NOTE_E5,8}, {NOTE_G5,8}, {NOTE_C5,8}, {NOTE_D5,8},
	{NOTE_E5,2},
	{NOTE_F5,8}, {NOTE_F5,8}, {NOTE_F5,8}, {NOTE_F5,8},
	{NOTE_F5,8}, {NOTE_E5,8}, {NOTE_E5,8}, {NOTE_E5,16}, {NOTE_E5,16},
	{NOTE_E5,8}, {NOTE_D5,8}, {NOTE_D5,8}, {NOTE_E5,8},
	{NOTE_D5,4}, {NOTE_G5,4}
};

// 30 nutes
note_struct wish[] = 
{
	{NOTE_B3,4}, 
	{NOTE_F4,4}, {NOTE_F4,8}, {NOTE_G4,8}, {NOTE_F4,8}, {NOTE_E4,8},
	{NOTE_D4,4}, {NOTE_D4,4}, {NOTE_D4,4},
	{NOTE_G4,4}, {NOTE_G4,8}, {NOTE_A4,8}, {NOTE_G4,8}, {NOTE_F4,8},
	{NOTE_E4,4}, {NOTE_E4,4}, {NOTE_E4,4},
	{NOTE_A4,4}, {NOTE_A4,8}, {NOTE_B4,8}, {NOTE_A4,8}, {NOTE_G4,8},
	{NOTE_F4,4}, {NOTE_D4,4}, {NOTE_B3,8}, {NOTE_B3,8},
	{NOTE_D4,4}, {NOTE_G4,4}, {NOTE_E4,4},
	{NOTE_F4,2}
};

// 28 nutes
note_struct santa[] = {
	{NOTE_G4,8},
	{NOTE_E4,8}, {NOTE_F4,8}, {NOTE_G4,4}, {NOTE_G4,4}, {NOTE_G4,4},
	{NOTE_A4,8}, {NOTE_B4,8}, {NOTE_C5,4}, {NOTE_C5,4}, {NOTE_C5,4},
	{NOTE_E4,8}, {NOTE_F4,8}, {NOTE_G4,4}, {NOTE_G4,4}, {NOTE_G4,4},
	{NOTE_A4,8}, {NOTE_G4,8}, {NOTE_F4,4}, {NOTE_F4,2},
	{NOTE_E4,4}, {NOTE_G4,4}, {NOTE_C4,4}, {NOTE_E4,4},
	{NOTE_D4,4}, {NOTE_F4,2}, {NOTE_B3,4},
	{NOTE_C4,1}
};


// 8 nutes
note_struct test_1[] = {
  {NOTE_C4, 4},
  {NOTE_G3, 8},
  {NOTE_G3, 8},
  {NOTE_A3, 4},
  {NOTE_G3, 4},
  {REST,    4},
  {NOTE_B3, 4},
  {NOTE_C4, 4}};

// 9 nutes
  note_struct STEPS[] = {
  {NOTE_C6, 4},
  {NOTE_G5, 8},
  {NOTE_G5, 8},
  {NOTE_A5, 4},
  {NOTE_G5, 4},
  {REST,    4},
  {NOTE_B5, 4},
  {NOTE_C6, 4},
  {REST,    0}};


// 13 nutes
note_struct Nokia_melody[] = {

  {NOTE_E5,  8},
  {NOTE_D5,  8},
  {NOTE_FS4,  4},
  {NOTE_GS4,  4},
  {NOTE_CS5,  8},
  {NOTE_B4,  8},
  {NOTE_D4,  4},
  {NOTE_E4,  4},
  {NOTE_B4,  8},
  {NOTE_A4,  8},
  {NOTE_CS4,  4},
  {NOTE_E4,  4},
  {NOTE_A4,  2},
};

// 16 nutes
note_struct HappyBirday[]={
    { NOTE_C4,4 },
    { NOTE_C4,8 },
    { NOTE_D4,-4},
    { NOTE_C4,-4},
    { NOTE_F4,-4},
    { NOTE_E4,-2},
    { NOTE_C4,4},
    {NOTE_C4,8},
    {NOTE_D4,-4},
    {NOTE_C4,-4},
    {NOTE_G4,-4},
    {NOTE_F4,-2},
    {NOTE_C4,4},
    {NOTE_C4,8},
    {NOTE_C5,-4},
    {NOTE_A4,-4},
    {NOTE_F4,-4},
    {NOTE_E4,-4},
    {NOTE_D4,-4},
    {NOTE_AS4,4},
    {NOTE_AS4,8},
    {NOTE_A4,-4},
    {NOTE_F4,-4},
    {NOTE_G4,-4},
    {NOTE_F4,-2},
    {REST,0}};


static inline void pwm_calcDivTop(pwm_config *c,int frequency,int sysClock)
{
  uint  count = sysClock * 16 / frequency;
  uint  div =  count / 60000;  // to be lower than 65535*15/16 (rounding error)
  if(div < 16)
      div=16;
  c->div = div;
  c->top = count / div;
}

void  play_melody(uint slice_num,note_struct * n,uint tempo, uint nmbr_of_nutes)
{
   
    pwm_config cfg = pwm_get_default_config();

    pwm_set_chan_level(slice_num,PWM_CHAN_A,0);

    int  wholenote = (60000 * 4) / tempo;

    int loop;
    int duration;

    for(loop=0; loop < nmbr_of_nutes;loop++)
    {
      duration = n[loop].duration;
      if(duration == 0) break;

      if(duration>0)
          duration = wholenote / duration;
      else
          duration = ( 3 * wholenote / (-duration))/2;

      if(n[loop].frequency!=REST)
      {
          pwm_set_enabled(slice_num, false);
          //get new frequency
          pwm_calcDivTop(&cfg,n[loop].frequency,125000000);
          pwm_init(slice_num,&cfg,true);
          pwm_set_chan_level(slice_num,PWM_CHAN_A,cfg.top / 2);
          pwm_set_enabled(slice_num, true);

          vTaskDelay(duration * (0.9 / portTICK_PERIOD_MS));
          pwm_set_chan_level(slice_num,PWM_CHAN_A,0);
          vTaskDelay(duration * (0.1 / portTICK_PERIOD_MS));
      }
      else
          vTaskDelay(duration * (1 / portTICK_PERIOD_MS));
    }

}

void buzzer_init(){

    gpio_set_function(PIN_PWM, GPIO_FUNC_PWM);
    slice_num = pwm_gpio_to_slice_num(PIN_PWM); 

}

void buzzer(){

    play_melody(slice_num, turnON, 200, 3);

    while (true) {

    //play_melody(slice_num, wish, 200, 30);

    vTaskDelay(500 / portTICK_PERIOD_MS);
    

    }
}