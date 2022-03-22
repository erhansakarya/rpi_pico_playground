#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "blink.pio.h"

int main() {
    static const uint ledPin = 25;
    static const float pioFreq = 2000; // Hz

    // choose pio instance (0 or 1)
    PIO pio = pio0;

    // get first free state machine in PIO 0
    uint sm = pio_claim_unused_sm(pio, true);

    // add pio program to PIO instuction memory. SDK will find location return with the memory offset of the program.
    uint offset = pio_add_program(pio, &blink_program);

    // calculate the pio clock divider
    float div = (float)clock_get_hz(clk_sys) / pioFreq;

    // initialize the program using the helper function in our .pio
    blink_program_init(pio, sm, offset, ledPin, div);

    // start running our PIO program in the state machine
    pio_sm_set_enabled(pio, sm, true);

    // do nothing
    while (true) {
        sleep_ms(1000);
    }
}