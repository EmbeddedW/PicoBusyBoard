#include "../include/buzzer.h"



//  1 notes
note_struct soundC[] = {
{NOTE_C5, 4}
};

//  1 notes
note_struct soundB[] = {
{NOTE_B5, 4}
};

//  1 notes
note_struct soundA[] = {
{NOTE_A5, 4}
};

//  1 notes
note_struct soundG[] = {
{NOTE_G5, 4}
};

//  88 notes
note_struct pinkPanther[] = {


  {REST,2}, {REST,4}, {REST,8}, {NOTE_DS4,8}, 
  {NOTE_E4,-4}, {REST,8}, {NOTE_FS4,8}, {NOTE_G4,-4}, {REST,8}, {NOTE_DS4,8},
  {NOTE_E4,-8}, {NOTE_FS4,8},  {NOTE_G4,-8}, {NOTE_C5,8}, {NOTE_B4,-8}, {NOTE_E4,8}, {NOTE_G4,-8}, {NOTE_B4,8},   
  {NOTE_AS4,2}, {NOTE_A4,-16}, {NOTE_G4,-16}, {NOTE_E4,-16}, {NOTE_D4,-16}, 
  {NOTE_E4,2}, {REST,4}, {REST,8}, {NOTE_DS4,4},
  //27

  {NOTE_E4,-4}, {REST,8}, {NOTE_FS4,8}, {NOTE_G4,-4}, {REST,8}, {NOTE_DS4,8},
  {NOTE_E4,-8}, {NOTE_FS4,8}, {NOTE_G4,-8}, {NOTE_C5,8}, {NOTE_B4,-8}, {NOTE_G4,8}, {NOTE_B4,-8}, {NOTE_E5,8},
  {NOTE_DS5,1},   
  {NOTE_D5,2}, {REST,4}, {REST,8}, {NOTE_DS4,8}, 
  {NOTE_E4,-4}, {REST,8}, {NOTE_FS4,8}, {NOTE_G4,-4}, {REST,8}, {NOTE_DS4,8},
  {NOTE_E4,-8}, {NOTE_FS4,8}, {NOTE_G4,-8}, {NOTE_C5,8}, {NOTE_B4,-8}, {NOTE_E4,8}, {NOTE_G4,-8}, {NOTE_B4,8},   
  //33
  
 {NOTE_AS4,2}, {NOTE_A4,-16}, {NOTE_G4,-16}, {NOTE_E4,-16}, {NOTE_D4,-16}, 
 {NOTE_E4,-4}, {REST,4},
 {REST,4}, {NOTE_E5,-8}, {NOTE_D5,8}, {NOTE_B4,-8}, {NOTE_A4,8}, {NOTE_G4,-8}, {NOTE_E4,-8},
 {NOTE_AS4,16}, {NOTE_A4,-8}, {NOTE_AS4,16}, {NOTE_A4,-8}, {NOTE_AS4,16}, {NOTE_A4,-8}, {NOTE_AS4,16}, {NOTE_A4,-8},   
 {NOTE_G4,-16}, {NOTE_E4,-16}, {NOTE_D4,-16}, {NOTE_E4,16}, {NOTE_E4,16}, {NOTE_E4,2},
 //28
  };



// 12 notes
note_struct gameOverMario[] = {
  {NOTE_C5,-4}, {NOTE_G4,-4}, {NOTE_E4,4}, //45
  {NOTE_A4,-8}, {NOTE_B4,-8}, {NOTE_A4,-8}, {NOTE_GS4,-8}, {NOTE_AS4,-8}, {NOTE_GS4,-8},
  {NOTE_G4,8}, {NOTE_D4,8}, {NOTE_E4,-2}  
 
  };


// 7 notes
note_struct lick[] = {
  {NOTE_D4,8}, {NOTE_E4,8}, {NOTE_F4,8}, {NOTE_G4,8}, {NOTE_E4,4}, {NOTE_C4,8}, {NOTE_D4,1}
 
  };




// 3 notes
note_struct turnON[] = {{NOTE_A6, 8}, {NOTE_CS7, 8}, {NOTE_E7, 8}};

// 77 notes
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


// 309 notes
note_struct Mario_melody2[] = {

  {NOTE_E5,8}, {NOTE_E5,8}, {REST,8}, {NOTE_E5,8}, {REST,8}, {NOTE_C5,8}, {NOTE_E5,8}, //1
  {NOTE_G5,4}, {REST,4}, {NOTE_G4,8}, {REST,4}, 
  {NOTE_C5,-4}, {NOTE_G4,8}, {REST,4}, {NOTE_E4,-4}, // 3
  {NOTE_A4,4}, {NOTE_B4,4}, {NOTE_AS4,8}, {NOTE_A4,4},
  {NOTE_G4,-8}, {NOTE_E5,-8}, {NOTE_G5,-8}, {NOTE_A5,4}, {NOTE_F5,8}, {NOTE_G5,8},
  {REST,8}, {NOTE_E5,4},{NOTE_C5,8}, {NOTE_D5,8}, {NOTE_B4,-4},
  {NOTE_C5,-4}, {NOTE_G4,8}, {REST,4}, {NOTE_E4,-4}, // repeats from 3
  {NOTE_A4,4}, {NOTE_B4,4}, {NOTE_AS4,8}, {NOTE_A4,4},
  {NOTE_G4,-8}, {NOTE_E5,-8}, {NOTE_G5,-8}, {NOTE_A5,4}, {NOTE_F5,8}, {NOTE_G5,8},
  {REST,8}, {NOTE_E5,4},{NOTE_C5,8}, {NOTE_D5,8}, {NOTE_B4,-4},
  //49
  
  {REST,4}, {NOTE_G5,8}, {NOTE_FS5,8}, {NOTE_F5,8}, {NOTE_DS5,4}, {NOTE_E5,8},//7
  {REST,8}, {NOTE_GS4,8}, {NOTE_A4,8}, {NOTE_C4,8}, {REST,8}, {NOTE_A4,8}, {NOTE_C5,8}, {NOTE_D5,8},
  {REST,4}, {NOTE_DS5,4}, {REST,8}, {NOTE_D5,-4},
  {NOTE_C5,2}, {REST,2},
  //20

  {REST,4}, {NOTE_G5,8}, {NOTE_FS5,8}, {NOTE_F5,8}, {NOTE_DS5,4}, {NOTE_E5,8},//repeats from 7
  {REST,8}, {NOTE_GS4,8}, {NOTE_A4,8}, {NOTE_C4,8}, {REST,8}, {NOTE_A4,8}, {NOTE_C5,8}, {NOTE_D5,8},
  {REST,4}, {NOTE_DS5,4}, {REST,8}, {NOTE_D5,-4},
  {NOTE_C5,2}, {REST,2},
  //20

  {NOTE_C5,8}, {NOTE_C5,4}, {NOTE_C5,8}, {REST,8}, {NOTE_C5,8}, {NOTE_D5,4},//11
  {NOTE_E5,8}, {NOTE_C5,4}, {NOTE_A4,8}, {NOTE_G4,2},

  {NOTE_C5,8}, {NOTE_C5,4}, {NOTE_C5,8}, {REST,8}, {NOTE_C5,8}, {NOTE_D5,8}, {NOTE_E5,8},//13
  {REST,1}, 
  {NOTE_C5,8}, {NOTE_C5,4}, {NOTE_C5,8}, {REST,8}, {NOTE_C5,8}, {NOTE_D5,4},
  {NOTE_E5,8}, {NOTE_C5,4}, {NOTE_A4,8}, {NOTE_G4,2},
  {NOTE_E5,8}, {NOTE_E5,8}, {REST,8}, {NOTE_E5,8}, {REST,8}, {NOTE_C5,8}, {NOTE_E5,4},
  {NOTE_G5,4}, {REST,4}, {NOTE_G4,4}, {REST,4}, 
  {NOTE_C5,-4}, {NOTE_G4,8}, {REST,4}, {NOTE_E4,-4}, // 19
  //43
  
  {NOTE_A4,4}, {NOTE_B4,4}, {NOTE_AS4,8}, {NOTE_A4,4},
  {NOTE_G4,-8}, {NOTE_E5,-8}, {NOTE_G5,-8}, {NOTE_A5,4}, {NOTE_F5,8}, {NOTE_G5,8},
  {REST,8}, {NOTE_E5,4}, {NOTE_C5,8}, {NOTE_D5,8}, {NOTE_B4,-4},
  //15

  {NOTE_C5,-4}, {NOTE_G4,8}, {REST,4}, {NOTE_E4,-4}, // repeats from 19
  {NOTE_A4,4}, {NOTE_B4,4}, {NOTE_AS4,8}, {NOTE_A4,4},
  {NOTE_G4,-8}, {NOTE_E5,-8}, {NOTE_G5,-8}, {NOTE_A5,4}, {NOTE_F5,8}, {NOTE_G5,8},
  {REST,8}, {NOTE_E5,4}, {NOTE_C5,8}, {NOTE_D5,8}, {NOTE_B4,-4},
  //19


  {NOTE_E5,8}, {NOTE_C5,4}, {NOTE_G4,8}, {REST,4}, {NOTE_GS4,4},//23
  {NOTE_A4,8}, {NOTE_F5,4}, {NOTE_F5,8}, {NOTE_A4,2},
  {NOTE_D5,-8}, {NOTE_A5,-8}, {NOTE_A5,-8}, {NOTE_A5,-8}, {NOTE_G5,-8}, {NOTE_F5,-8},
  //15


  {NOTE_E5,8}, {NOTE_C5,4}, {NOTE_A4,8}, {NOTE_G4,2}, //26
  {NOTE_E5,8}, {NOTE_C5,4}, {NOTE_G4,8}, {REST,4}, {NOTE_GS4,4},
  {NOTE_A4,8}, {NOTE_F5,4}, {NOTE_F5,8}, {NOTE_A4,2},
  {NOTE_B4,8}, {NOTE_F5,4}, {NOTE_F5,8}, {NOTE_F5,-8}, {NOTE_E5,-8}, {NOTE_D5,-8},
  {NOTE_C5,8}, {NOTE_E4,4}, {NOTE_E4,8}, {NOTE_C4,2},
  //23

 {NOTE_E5,8}, {NOTE_C5,4}, {NOTE_G4,8}, {REST,4}, {NOTE_GS4,4},//repeats from 23
 {NOTE_A4,8}, {NOTE_F5,4}, {NOTE_F5,8}, {NOTE_A4,2},
 {NOTE_D5,-8}, {NOTE_A5,-8}, {NOTE_A5,-8}, {NOTE_A5,-8}, {NOTE_G5,-8}, {NOTE_F5,-8},
  //15

  {NOTE_E5,8}, {NOTE_C5,4}, {NOTE_A4,8}, {NOTE_G4,2}, //26
  {NOTE_E5,8}, {NOTE_C5,4}, {NOTE_G4,8}, {REST,4}, {NOTE_GS4,4},
  {NOTE_A4,8}, {NOTE_F5,4}, {NOTE_F5,8}, {NOTE_A4,2},
  {NOTE_B4,8}, {NOTE_F5,4}, {NOTE_F5,8}, {NOTE_F5,-8}, {NOTE_E5,-8}, {NOTE_D5,-8},
  {NOTE_C5,8}, {NOTE_E4,4}, {NOTE_E4,8}, {NOTE_C4,2},
  {NOTE_C5,8}, {NOTE_C5,4}, {NOTE_C5,8}, {REST,8}, {NOTE_C5,8}, {NOTE_D5,8}, {NOTE_E5,8},
  {REST,1},
  //31

  {NOTE_C5,8}, {NOTE_C5,4}, {NOTE_C5,8}, {REST,8}, {NOTE_C5,8}, {NOTE_D5,4}, //33
  {NOTE_E5,8}, {NOTE_C5,4}, {NOTE_A4,8}, {NOTE_G4,2},
  {NOTE_E5,8}, {NOTE_E5,8}, {REST,8}, {NOTE_E5,8}, {REST,8}, {NOTE_C5,8}, {NOTE_E5,4},
  {NOTE_G5,4}, {REST,4}, {NOTE_G4,4}, {REST,4}, 
  {NOTE_E5,8}, {NOTE_C5,4}, {NOTE_G4,8}, {REST,4}, {NOTE_GS4,4},
  {NOTE_A4,8}, {NOTE_F5,4}, {NOTE_F5,8}, {NOTE_A4,2},
  {NOTE_D5,-8}, {NOTE_A5,-8}, {NOTE_A5,-8}, {NOTE_A5,-8}, {NOTE_G5,-8}, {NOTE_F5,-8},
  //36
  
  {NOTE_E5,8}, {NOTE_C5,4}, {NOTE_A4,8}, {NOTE_G4,2}, //40
  {NOTE_E5,8}, {NOTE_C5,4}, {NOTE_G4,8}, {REST,4}, {NOTE_GS4,4},
  {NOTE_A4,8}, {NOTE_F5,4}, {NOTE_F5,8}, {NOTE_A4,2},
  {NOTE_B4,8}, {NOTE_F5,4}, {NOTE_F5,8}, {NOTE_F5,-8}, {NOTE_E5,-8}, {NOTE_D5,-8},
  {NOTE_C5,8}, {NOTE_E4,4}, {NOTE_E4,8}, {NOTE_C4,2},
  //23

};


// 26 notes
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

// 30 notes
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

// 28 notes
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


// 8 notes
note_struct test_1[] = {
  {NOTE_C4, 4},
  {NOTE_G3, 8},
  {NOTE_G3, 8},
  {NOTE_A3, 4},
  {NOTE_G3, 4},
  {REST,    4},
  {NOTE_B3, 4},
  {NOTE_C4, 4}};

// 9 notes
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


// 13 notes
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

// 26 notes
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

          //sleep_ms(duration * 0.9);

          vTaskDelay(duration * (0.9 / portTICK_PERIOD_MS));
          pwm_set_chan_level(slice_num,PWM_CHAN_A,0);
          vTaskDelay(duration * (0.1 / portTICK_PERIOD_MS));
          //sleep_ms(duration * 0.1);
      }
      else
          vTaskDelay(duration * (1 / portTICK_PERIOD_MS));
          //sleep_ms(duration * 1.0);
    }

}
