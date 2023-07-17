#include "main.h"

#ifndef E220_LORA_H_
#define E220_LORA_H_	



typedef struct e220_pins{
    uint8_t m0;
    uint8_t m1;    
    uint8_t aux;
    uint8_t Rx;
    uint8_t Tx;              
} e220_pins_t;



typedef struct e220_param{

    uint16_t address;
    uint16_t key;
    uint16_t baudrate;
    uint8_t channel;   


} e220_param_t;


void e220_LoRa_init(e220_pins_t *pin_ptr);
   


#endif