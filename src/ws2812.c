#include "../include/ws2812.h"


uint8_t red_val;
uint8_t green_val = 0;
uint8_t blue_val = 0;

uint8_t colour = 0xff;

enum {
    GREEN = 0,
    YELLOW,
    BLUE,
    WHITE,
    RED,
    PURPLE,
    LAST_OF_US,
};

static uint8_t pixel_array[16];
static uint8_t game_arrow_array[16] = 
{1, 0, 0, 0,
 1, 0, 1, 0,
 0, 0, 1, 1,
 1, 1, 1, 0
};

static uint8_t T_array[16] = 
{1, 1, 1, 1,
 0, 0, 1, 0,
 0, 1, 0, 0,
 0, 0, 1, 0
};

static uint8_t O_array[16] = 
{1, 1, 1, 1,
 1, 0, 0, 1,
 1, 0, 0, 1,
 1, 1, 1, 1
};

static uint8_t M_array[16] = 
{1, 1, 0, 1,
 1, 1, 0, 1,
 1, 0, 0, 1,
 1, 0, 0, 1
};

static uint8_t E_array[16] = 
{1, 1, 1, 1,
 0, 1, 1, 1,
 1, 0, 0, 0,
 1, 1, 1, 1
};

static uint8_t K_array[16] = 
{1, 0, 1, 1,
 0, 0, 1, 1,
 1, 0, 1, 0,
 1, 0, 0, 1
};



static uint8_t game_array[16];
static int counter;
static bool game_init = true;

// horrible temporary hack to avoid changing pattern code
static uint8_t *current_strip_out;
static bool current_strip_4color;

static inline void put_pixel(uint32_t pixel_grb) {
    *current_strip_out++ = pixel_grb & 0xffu;
    *current_strip_out++ = (pixel_grb >> 8u) & 0xffu;
    *current_strip_out++ = (pixel_grb >> 16u) & 0xffu;
    if (current_strip_4color) {
        *current_strip_out++ = 0; // todo adjust?
    }
}

static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b) {
    return
            ((uint32_t) (r) << 8) |
            ((uint32_t) (g) << 16) |
            (uint32_t) (b);
}

void pattern_snakes(uint len, uint t) {
    for (uint i = 0; i < len; ++i) {
        uint x = (i + (t >> 1)) % 64;
        if (x < 10)
            put_pixel(urgb_u32(0xff, 0, 0));
        else if (x >= 15 && x < 25)
            put_pixel(urgb_u32(0, 0xff, 0));
        else if (x >= 30 && x < 40)
            put_pixel(urgb_u32(0, 0, 0xff));
        else 
            put_pixel(0);
    }
}

void pattern_random(uint len, uint t) {
  
    if (t % 8)
        return;
    for (int i = 0; i < len; ++i)
        put_pixel(rand());

}

void pattern_sparkle(uint len, uint t) {
 if (LED_RANDOM){
    if (t % 8)
        return;
    for (int i = 0; i < len; ++i)
        put_pixel(rand() % 16 ? 0 : 0xffffffff);
 }
}

void pattern_greys(uint len, uint t) {
    int max = 100; // let's not draw too much current!
    t %= max;

    red_val = (uint8_t)((adc_result & 0x0F) & 0x0f);
    green_val = (uint8_t)(((adc_result & 0xF0) >> 4) & 0x0f);
    blue_val = (uint8_t)(((adc_result & 0xF00) >> 8) & 0x0f);

    for (int i = 0; i < len; ++i) {
        put_pixel(urgb_u32(red_val, blue_val, green_val));
    }
}


void pattern_setPixels(uint len, uint t) {
    int max = 100; // let's not draw too much current!
    t %= max;
    uint8_t pixel_colour;
    static bool set_array_pixel;
    static bool unpush_button_detect;
    if (button_green) 
    {
        pixel_colour = GREEN;
        if (unpush_button_detect) {
            set_array_pixel = 1;
            unpush_button_detect = false;
        }
    }
    else if (button_yellow)    
    {
        pixel_colour = YELLOW;
        if (unpush_button_detect) {
            set_array_pixel = 1;
            unpush_button_detect = false;
        }
    }
    else if (button_blue) 
    {
        pixel_colour = BLUE;
        if (unpush_button_detect) {
            set_array_pixel = 1;
            unpush_button_detect = false;
        }
    }
    else if (button_white) 
    {
        pixel_colour = WHITE;
        if (unpush_button_detect) {
            set_array_pixel = 1;
            unpush_button_detect = false;
        }
    }
    else {
        set_array_pixel = 0;
        unpush_button_detect = true;
    }

    if (button_green) colour = GREEN;
    if (button_yellow) colour = YELLOW;
    if (button_blue) colour = BLUE;
    if (button_white) colour = WHITE;

    if(true == set_array_pixel) {
        pixel_array[counter] = colour;
        set_array_pixel= 0;
        ++counter;
        if(counter==len)counter = 0; 
    }


    for (int i = 0; i < len; ++i) {

    switch (pixel_array[i])
        {
        case GREEN:
        red_val = (uint8_t)0x00;
        green_val = (uint8_t)0x0f;
        blue_val = (uint8_t)0x00;
        break;
        case YELLOW:
        red_val = (uint8_t)0x1f;
        green_val = (uint8_t)0x0f;
        blue_val = (uint8_t)0x00;
        break; 
        case BLUE:
        red_val = (uint8_t)0x00;
        green_val = (uint8_t)0x00;
        blue_val = (uint8_t)0x0f;
        break;
        case WHITE:
        // BLANK  
        red_val = (uint8_t)0x00;
        green_val = (uint8_t)0x00;
        blue_val = (uint8_t)0x00;
        break; 
        default:
        // RED
        red_val = (uint8_t)0x0f;
        green_val = (uint8_t)0x00;
        blue_val = (uint8_t)0x00;
        break;
        }
    put_pixel(urgb_u32(red_val, blue_val, green_val));
    }


}

void pattern_adcSnake(uint len, uint t) {
    int max = 100; // let's not draw too much current!
    t %= max;
    uint8_t pixel_colour;
    static bool set_array_pixel;
    static bool unpush_button_detect;

    static uint8_t number_of_pixels; 

    number_of_pixels = (uint8_t) (adc_result >> 8);

    for (int i = 0; i < len; ++i) {

    if(number_of_pixels <= i){
    red_val = (uint8_t)0x0f;
    green_val = (uint8_t)0x00;
    blue_val = (uint8_t)0x00;
    } else {
    red_val = (uint8_t)0x00;
    green_val = (uint8_t)0x00;
    blue_val = (uint8_t)0x00;
    }
        
    put_pixel(urgb_u32(red_val, blue_val, green_val));
    }


}


void pattern_singleColour(uint len, uint t) {
    int max = 100; // let's not draw too much current!
    t %= max;
    int test = 0;

    switch (colour)
    {
    case GREEN:
        red_val = (uint8_t)0x00;
        green_val = (uint8_t)0x0f;
        blue_val = (uint8_t)0x00;
        break;
    case YELLOW:
        red_val = (uint8_t)0x1f;
        green_val = (uint8_t)0x0f;
        blue_val = (uint8_t)0x00;
        break; 
    case BLUE:
        red_val = (uint8_t)0x00;
        green_val = (uint8_t)0x00;
        blue_val = (uint8_t)0x0f;
        break;
    case WHITE:
        red_val = (uint8_t)0x1f;
        green_val = (uint8_t)0x1f;
        blue_val = (uint8_t)0x1f;
        break; 
    default:
        // RED
        red_val = (uint8_t)0x0f;
        green_val = (uint8_t)0x00;
        blue_val = (uint8_t)0x00;
        test = 1;
        break;
    }

    for (int i = 0; i < len; ++i) {

        if (test){

            if(i == 15)
            {
            //GREEN
            put_pixel(urgb_u32(0x00, 0x00, 0x0f));
            }
            else if (i == 14)
            {
            //YELLOW                    
            put_pixel(urgb_u32(0x1f, 0x00, 0x0f));
            }
            else if (i == 13)
            {
            //BLUE                    
            put_pixel(urgb_u32(0x00, 0x0f, 0x00));
            }
            else if (i == 12)
            {                
            //WHITE
            put_pixel(urgb_u32(0x1f, 0x1f, 0x1f));
            }
            else {
            put_pixel(urgb_u32(red_val, blue_val, green_val));
            }

        }  else {      
        put_pixel(urgb_u32(red_val, blue_val, green_val));
        }
    }

}


void pattern_GameColour(uint len, uint t) {
    int max = 100; // let's not draw too much current!
    t %= max;
    int test = 0;
    static bool start_game;
    static int random_colour;
    static bool colour_timer_start;
    int pushed_button;

    static bool lock_1;

    static bool test_correct_flag;

    static uint32_t timer;
    
    static int test_2;

    if (true == game_init)
    {
        for (int i = 0; i < len; ++i) {
            if(1 == game_arrow_array[i]) put_pixel(urgb_u32(0x1f, 0x1f, 0x1f));
        else                         put_pixel(urgb_u32(0x00, 0x00, 0x00));
        }
    }
    if (button_white) {
        if(lock_1 == false) start_game = true;
    }

    if(true == start_game){
        start_game = false;
        lock_1 = true;
        game_init = false;
        random_colour = rand() % 3;
        colour_timer_start = set_lcd_colour(len, random_colour);   
    }

    //play 3,2,1
    //set random colour

    //start timer
    if (colour_timer_start)
    {

    while(timer < 1000)
    {
        if (button_green) pushed_button = 0;
        else if (button_yellow) pushed_button = 1;
        else if (button_blue) pushed_button = 2;
        else pushed_button = 0xff;

        if (random_colour == pushed_button)            
        {
            test_2 = 100;
            colour_timer_start = false;
            test_correct_flag = true;
            break;
            // CORRECT!
        }
    timer++; 
        // else if (((random_colour != GREEN)&&(random_colour != YELLOW)&&(random_colour != BLUE))
        // && (((pushed_button != GREEN)&&(pushed_button != YELLOW)&&(pushed_button != BLUE))))
        // {
        //     test_2 = 200;
        //     // CORRECT!
        // }
        // else
        // {
        //     // WRONG!
        //     test_2 = 999;        
           
        // }
    }
    lock_1 = false; 
    timer = 0;
    }
     

}


void pattern_solid(uint len, uint t) {
    t = 1;
    for (int i = 0; i < len; ++i) {
        put_pixel(t * 0x10101);
    }
}

int level = 8;

void pattern_TOM(uint len, uint t) {

    for (int i = 0; i < len; ++i) {
    switch (TOM_letter)
    {
    case 0: // T
        if(true == T_array[i]){
        put_pixel(urgb_u32(0x1f, 0x1f, 0x1f));
        }
        else{
        put_pixel(urgb_u32(0x00, 0x00, 0x00));
        }
        break;
    case 1: // O
        if(true == O_array[i]){
        put_pixel(urgb_u32(0x1f, 0x1f, 0x1f));
        }
        else{
        put_pixel(urgb_u32(0x00, 0x00, 0x00));
        }
        break;
    case 2: // M
        if(true == M_array[i]){
        put_pixel(urgb_u32(0x1f, 0x1f, 0x1f));
        }
        else{
        put_pixel(urgb_u32(0x00, 0x00, 0x00));
        }
        break;
    case 3: // E
        if(true == E_array[i]){
        put_pixel(urgb_u32(0x1f, 0x1f, 0x1f));
        }
        else{
        put_pixel(urgb_u32(0x00, 0x00, 0x00));
        }
        break;
    case 4: // K
        if(true == K_array[i]){
        put_pixel(urgb_u32(0x1f, 0x1f, 0x1f));
        }
        else{
        put_pixel(urgb_u32(0x00, 0x00, 0x00));
        }
        break;     
    default:
        break;
    }
   }
    
}

typedef void (*pattern)(uint len, uint t);
const struct {
    pattern pat;
    const char *name;
} pattern_table[] = {
    {pattern_greys,   "Greys"},
    {pattern_singleColour,   "Colour"},
    {pattern_sparkle, "Sparkles"},
    {pattern_random,  "Random data"},
    {pattern_GameColour,  "GAME!"},
    {pattern_setPixels,  "set diffrent pixels"},
    {pattern_adcSnake,  "Adc Snakeee"},
    {pattern_TOM, "TOM!"},
};

#define VALUE_PLANE_COUNT (8 + FRAC_BITS)
// we store value (8 bits + fractional bits of a single color (R/G/B/W) value) for multiple
// strips of pixels, in bit planes. bit plane N has the Nth bit of each strip of pixels.
typedef struct {
    // stored MSB first
    uint32_t planes[VALUE_PLANE_COUNT];
} value_bits_t;

// Add FRAC_BITS planes of e to s and store in d
void add_error(value_bits_t *d, const value_bits_t *s, const value_bits_t *e) {
    uint32_t carry_plane = 0;
    // add the FRAC_BITS low planes
    for (int p = VALUE_PLANE_COUNT - 1; p >= 8; p--) {
        uint32_t e_plane = e->planes[p];
        uint32_t s_plane = s->planes[p];
        d->planes[p] = (e_plane ^ s_plane) ^ carry_plane;
        carry_plane = (e_plane & s_plane) | (carry_plane & (s_plane ^ e_plane));
    }
    // then just ripple carry through the non fractional bits
    for (int p = 7; p >= 0; p--) {
        uint32_t s_plane = s->planes[p];
        d->planes[p] = s_plane ^ carry_plane;
        carry_plane &= s_plane;
    }
}

typedef struct {
    uint8_t *data;
    uint data_len;
    uint frac_brightness; // 256 = *1.0;
} strip_t;

// takes 8 bit color values, multiply by brightness and store in bit planes
void transform_strips(strip_t **strips, uint num_strips, value_bits_t *values, uint value_length,
                       uint frac_brightness) {
    for (uint v = 0; v < value_length; v++) {
        memset(&values[v], 0, sizeof(values[v]));
        for (int i = 0; i < num_strips; i++) {
            if (v < strips[i]->data_len) {
                // todo clamp?
                uint32_t value = (strips[i]->data[v] * strips[i]->frac_brightness) >> 8u;
                value = (value * frac_brightness) >> 8u;
                for (int j = 0; j < VALUE_PLANE_COUNT && value; j++, value >>= 1u) {
                    if (value & 1u) values[v].planes[VALUE_PLANE_COUNT - 1 - j] |= 1u << i;
                }
            }
        }
    }
}

void dither_values(const value_bits_t *colors, value_bits_t *state, const value_bits_t *old_state, uint value_length) {
    for (uint i = 0; i < value_length; i++) {
        add_error(state + i, colors + i, old_state + i);
    }
}

// requested colors * 4 to allow for RGBW
static value_bits_t colors[NUM_PIXELS * 4];
// double buffer the state of the pixel strip, since we update next version in parallel with DMAing out old version
static value_bits_t states[2][NUM_PIXELS * 4];

// example - strip 0 is RGB only
static uint8_t strip0_data[NUM_PIXELS * 3];
// example - strip 1 is RGBW
static uint8_t strip1_data[NUM_PIXELS * 4];

strip_t strip0 = {
        .data = strip0_data,
        .data_len = sizeof(strip0_data),
        .frac_brightness = 0x40,
};

strip_t strip1 = {
        .data = strip1_data,
        .data_len = sizeof(strip1_data),
        .frac_brightness = 0x100,
};

strip_t *strips[] = {
        &strip0,
        &strip1,
};

// bit plane content dma channel
#define DMA_CHANNEL 0
// chain channel for configuring main dma channel to output from disjoint 8 word fragments of memory
#define DMA_CB_CHANNEL 1

#define DMA_CHANNEL_MASK (1u << DMA_CHANNEL)
#define DMA_CB_CHANNEL_MASK (1u << DMA_CB_CHANNEL)
#define DMA_CHANNELS_MASK (DMA_CHANNEL_MASK | DMA_CB_CHANNEL_MASK)

// start of each value fragment (+1 for NULL terminator)
static uintptr_t fragment_start[NUM_PIXELS * 4 + 1];

// posted when it is safe to output a new set of values
static struct semaphore reset_delay_complete_sem;
// alarm handle for handling delay
alarm_id_t reset_delay_alarm_id;

int64_t reset_delay_complete(alarm_id_t id, void *user_data) {
    reset_delay_alarm_id = 0;
    sem_release(&reset_delay_complete_sem);
    // no repeat
    return 0;
}

void __isr dma_complete_handler() {
    if (dma_hw->ints0 & DMA_CHANNEL_MASK) {
        // clear IRQ
        dma_hw->ints0 = DMA_CHANNEL_MASK;
        // when the dma is complete we start the reset delay timer
        if (reset_delay_alarm_id) cancel_alarm(reset_delay_alarm_id);
        reset_delay_alarm_id = add_alarm_in_us(400, reset_delay_complete, NULL, true);
    }
}

void dma_init(PIO pio, uint sm) {
    dma_claim_mask(DMA_CHANNELS_MASK);

    // main DMA channel outputs 8 word fragments, and then chains back to the chain channel
    dma_channel_config channel_config = dma_channel_get_default_config(DMA_CHANNEL);
    channel_config_set_dreq(&channel_config, pio_get_dreq(pio, sm, true));
    channel_config_set_chain_to(&channel_config, DMA_CB_CHANNEL);
    channel_config_set_irq_quiet(&channel_config, true);
    dma_channel_configure(DMA_CHANNEL,
                          &channel_config,
                          &pio->txf[sm],
                          NULL, // set by chain
                          8, // 8 words for 8 bit planes
                          false);

    // chain channel sends single word pointer to start of fragment each time
    dma_channel_config chain_config = dma_channel_get_default_config(DMA_CB_CHANNEL);
    dma_channel_configure(DMA_CB_CHANNEL,
                          &chain_config,
                          &dma_channel_hw_addr(
                                  DMA_CHANNEL)->al3_read_addr_trig,  // ch DMA config (target "ring" buffer size 4) - this is (read_addr trigger)
                          NULL, // set later
                          1,
                          false);

    irq_set_exclusive_handler(DMA_IRQ_0, dma_complete_handler);
    dma_channel_set_irq0_enabled(DMA_CHANNEL, true);
    irq_set_enabled(DMA_IRQ_0, true);
}

void output_strips_dma(value_bits_t *bits, uint value_length) {
    for (uint i = 0; i < value_length; i++) {
        fragment_start[i] = (uintptr_t) bits[i].planes; // MSB first
    }
    fragment_start[value_length] = 0;
    dma_channel_hw_addr(DMA_CB_CHANNEL)->al3_read_addr_trig = (uintptr_t) fragment_start;
}


void ws2812_dma_init(){

    PIO pio = pio0;
    int sm = 0;

    uint offset = pio_add_program(pio, &ws2812_parallel_program);
    ws2812_parallel_program_init(pio, sm, offset, WS2812_PIN_BASE, count_of(strips), 800000);
    sem_init(&reset_delay_complete_sem, 1, 1); // initially posted so we don't block first time
    dma_init(pio, sm);

}


void led_ws2812(){

    //uint8_t red_val = -0 (uint8_t)((adc_result & 0xFF) >> 8);
    static bool LCD_PIXELS_init;
    int t = 0;
    while (true) {

        if (button_green) colour = GREEN;
        if (button_yellow) colour = YELLOW;
        if (button_blue) colour = BLUE;
        if (button_white) colour = WHITE;

        int pat = rand() % count_of(pattern_table);

        if (BOARD_STATE == LCD_BUTTONS) pat = 0;
        else if (BOARD_STATE == LCD_COLORS) pat = 1;
        else if (BOARD_STATE == BUZZER_BUTTONS) pat = 2;
        else if (BOARD_STATE == BUZZER_NUTES) pat = 3;
        else if (BOARD_STATE == GAME) {                      
            pat = 4;
        }
        else if (BOARD_STATE == LCD_PIXELS) {
            pat = 5;
            if(true == LCD_PIXELS_init)
            {
                LCD_PIXELS_init = false;
                for(int i= 0; i<16; i++){
                    pixel_array[i] = WHITE;   
                    } 
                counter = 0;
            }
        }
        else if (BOARD_STATE == ADC_SNAKE) pat = 6;
        else if (BOARD_STATE == IDLE) pat = 7;
      

        if(BOARD_STATE != LCD_PIXELS) LCD_PIXELS_init = true;
        if(BOARD_STATE != GAME)    game_init = true;


        int dir = (rand() >> 30) & 1 ? 1 : -1;
        if (rand() & 1) dir = 0;
        puts(pattern_table[pat].name);
        puts(dir == 1 ? "(forward)" : dir ? "(backward)" : "(still)");
        int brightness = 0x200;
        uint current = 0;
        for (int i = 0; i < 10; ++i) {

            current_strip_out = strip0.data;
            current_strip_4color = false;
            pattern_table[pat].pat(NUM_PIXELS, t);
            current_strip_out = strip1.data;
            current_strip_4color = true;
            transform_strips(strips, count_of(strips), colors, NUM_PIXELS * 4, brightness);
            dither_values(colors, states[current], states[current ^ 1], NUM_PIXELS * 4);
            sem_acquire_blocking(&reset_delay_complete_sem);
            output_strips_dma(states[current], NUM_PIXELS * 4);

            current ^= 1;
            t += dir;
            // brightness++;
            // if (brightness == (0x20 << FRAC_BITS)) brightness = 0;
        }
        memset(&states, 0, sizeof(states)); // clear out errors     
                // & 0x0f for minimum brightness of LED 
       
        //vTaskDelay(10/portTICK_PERIOD_MS);
    }

}


bool set_lcd_colour(uint num_pixels, int colour){

        switch (colour)
            {
            case 0: //GREEN:
                red_val = (uint8_t)0x00;
                green_val = (uint8_t)0x0f;
                blue_val = (uint8_t)0x00;
                break;
            case 1: //YELLOW:
                red_val = (uint8_t)0x1f;
                green_val = (uint8_t)0x0f;
                blue_val = (uint8_t)0x00;
                break; 
            case 2: //BLUE:
                red_val = (uint8_t)0x00;
                green_val = (uint8_t)0x00;
                blue_val = (uint8_t)0x0f;
                break;
            // case WHITE:
            //     red_val = (uint8_t)0x1f;
            //     green_val = (uint8_t)0x1f;
            //     blue_val = (uint8_t)0x1f;
            //     break; 
            // case RED:
            //     red_val = (uint8_t)0x1f;
            //     green_val = (uint8_t)0x00;
            //     blue_val = (uint8_t)0x00;
            //     break; 
            // case PURPLE:
            //     red_val = (uint8_t)0x1c;
            //     green_val = (uint8_t)0x00;
            //     blue_val = (uint8_t)0x1c;
            //     break; 

            default:
                // RED
                red_val = (uint8_t)0x0f;
                green_val = (uint8_t)0x00;
                blue_val = (uint8_t)0x00;
                break;
        }

    for (int i = 0; i < num_pixels; ++i) {

        put_pixel(urgb_u32(red_val, blue_val, green_val));
       
    }
    return true;
}