// -------------------------------------------------- //
// This file is autogenerated by pioasm; do not edit! //
// -------------------------------------------------- //

#pragma once

#if !PICO_NO_HARDWARE
#include "hardware/pio.h"
#endif

// ----- //
// blink //
// ----- //

#define blink_wrap_target 0
#define blink_wrap 9

static const uint16_t blink_program_instructions[] = {
            //     .wrap_target
    0xf301, //  0: set    pins, 1                [19]
    0xb342, //  1: nop                           [19]
    0xb342, //  2: nop                           [19]
    0xb342, //  3: nop                           [19]
    0xb342, //  4: nop                           [19]
    0xf300, //  5: set    pins, 0                [19]
    0xb342, //  6: nop                           [19]
    0xb342, //  7: nop                           [19]
    0xb342, //  8: nop                           [19]
    0xb342, //  9: nop                           [19]
            //     .wrap
};

#if !PICO_NO_HARDWARE
static const struct pio_program blink_program = {
    .instructions = blink_program_instructions,
    .length = 10,
    .origin = -1,
};

static inline pio_sm_config blink_program_get_default_config(uint offset) {
    pio_sm_config c = pio_get_default_sm_config();
    sm_config_set_wrap(&c, offset + blink_wrap_target, offset + blink_wrap);
    return c;
}

// Helper function (for use in C program) to initialize this PIO program
void blink_program_init(PIO pio, uint sm, uint offset, uint pin, float div) {
    // sets up state machine and wrap target. This function is automatically generated in blink.pio.h
    pio_sm_config c = blink_program_get_default_config(offset);
    // allow PIO to control GPIO pin (as output)
    pio_gpio_init(pio, pin);
    // connect pin to set pin (control with 'set' instruction)
    sm_config_set_set_pins(&c, pin, 1);
    // set the pin direction to output (in PIO)
    pio_sm_set_consecutive_pindirs(pio, sm, pin, 1, true);
    // set the clock divider for state machine
    sm_config_set_clkdiv(&c, div);
    // load configuration and jump to start of the program
    pio_sm_init(pio, sm, offset, &c);
}

#endif
