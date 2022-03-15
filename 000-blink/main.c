#include "pico/stdlib.h"

int main() {
    const uint ledPin = 25;

    // initialize led pin
    gpio_init(ledPin);
    gpio_set_dir(ledPin, GPIO_OUT);

    for(;;) {
        gpio_put(ledPin, true);
        sleep_ms(1000);
        gpio_put(ledPin, false);
        sleep_ms(1000);
    }
}