#include "main.h"

#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_	

void state_entry();
void state_run();
void state_stop();
void state_idle();
void state_fail();

typedef enum 
{
    ST_ENTRY,
    ST_RUN,
    ST_STOP,
    ST_IDLE,
    ST_FAIL,
    SIZE 
} states_t;

void state_update(states_t state);
void state_callback(void (*ptr)());



// struct ptr_to_state 
// {
//     states_t machine_states;
//     void * ptr_to_state;
// };

// struct ptr_to_state ptr_to_state[SIZE] = { 
//     {ST_ENTRY, &state_entry},
//     {ST_RUN, &state_run},
// };


#endif