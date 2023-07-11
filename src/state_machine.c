
#include "../include/state_machine.h"

void *state_fn_ptr[SIZE] = {
    &state_entry,
    &state_run,
    &state_stop,
    &state_idle,
    &state_fail
};

void state_callback(void (*ptr)())
{
    (*ptr)();
}

void state_update(states_t state){
    state_callback(state_fn_ptr[state]); 
    //state_callback(ptr_to_state[state].ptr_to_state); 
}

void state_entry()
{
    printf("ENTRY\n");
}
void state_run()
{
    printf("RUN\n");
}
void state_stop()
{
    printf("STOP\n");    
}
void state_idle()
{
    printf("IDLE\n");

}
void state_fail()
{
    printf("FAIL\n");
}
