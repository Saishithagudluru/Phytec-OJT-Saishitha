#include <stdio.h>
#include <unistd.h>
#include <mraa.h>

#define LED_PIN 61 // Onboard LED
#define SWITCH_PIN 35 // Onboard switch

int main() {
    mraa_init();

    // Initialize GPIO pins
    mraa_gpio_context led = mraa_gpio_init(LED_PIN);
    mraa_gpio_context switch_pin = mraa_gpio_init(SWITCH_PIN);

    // Set GPIO directions
    mraa_gpio_dir(led, MRAA_GPIO_OUT);
    mraa_gpio_dir(switch_pin, MRAA_GPIO_IN);

    // Initialize variables
    int switchPressCount = 0;
    int lastSwitchState = 0;

    // Main loop
    while (1) {
        // Read switch state
        int switchState = mraa_gpio_read(switch_pin);

        if (switchState != lastSwitchState && switchState == 1) {
            // Switch is pressed
            switchPressCount++;

            // Toggle LED based on switchPressCount
            int i;
            for (i = 0; i < switchPressCount; i++) {
                mraa_gpio_write(led, 1); // Turn LED on
                usleep(500000); // Delay for half a second
                mraa_gpio_write(led, 0); // Turn LED off
                usleep(500000); // Delay for half a second
            }

            // Print the number of times switch pressed
            printf("Switch pressed %d time(s)\n", switchPressCount);
        }

        lastSwitchState = switchState;

        // Delay to debounce and reduce CPU usage
        usleep(10000); // 10 ms delay
    }

    // Cleanup
    mraa_gpio_close(led);
    mraa_gpio_close(switch_pin);
    mraa_deinit();

    return 0;
}

