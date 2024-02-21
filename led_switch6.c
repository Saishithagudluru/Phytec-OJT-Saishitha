#include <stdio.h>
#include <unistd.h>
#include <mraa.h>

#define LED1_PIN 61 // PC13
#define LED2_PIN 62 // PC17
#define LED3_PIN 63 // PC19
#define SWITCH_PIN 35 // PC12

int main() {
    mraa_init();

    // Initialize GPIO pins
    mraa_gpio_context led1 = mraa_gpio_init(LED1_PIN);
    mraa_gpio_context led2 = mraa_gpio_init(LED2_PIN);
    mraa_gpio_context led3 = mraa_gpio_init(LED3_PIN);
    mraa_gpio_context switch_pin = mraa_gpio_init(SWITCH_PIN);

    // Set GPIO directions
    mraa_gpio_dir(led1, MRAA_GPIO_OUT);
    mraa_gpio_dir(led2, MRAA_GPIO_OUT);
    mraa_gpio_dir(led3, MRAA_GPIO_OUT);
    mraa_gpio_dir(switch_pin, MRAA_GPIO_IN);

    // Initialize variables
    int ledCount = 0;
    int switchPressCount = 0;
    mraa_result_t result;
    mraa_gpio_context button;
    button = mraa_gpio_init(SWITCH_PIN);

    // Main loop
    while (1) {
        // Read switch state
        int switchState = mraa_gpio_read(switch_pin);

        if (switchState == 1) {
            // Switch is pressed
            switchPressCount++;

            // Increment ledCount to cycle through LEDs
            ledCount = (ledCount + 1) % 3;

            // Turn off all LEDs
            mraa_gpio_write(led1, 0);
            mraa_gpio_write(led2, 0);
            mraa_gpio_write(led3, 0);

            // Turn on the corresponding LED
            if (ledCount == 0)
                mraa_gpio_write(led1, 1);
            else if (ledCount == 1)
                mraa_gpio_write(led2, 1);
            else if (ledCount == 2)
                mraa_gpio_write(led3, 1);

            // Print the number of times switch pressed
            printf("Switch pressed %d time(s)\n", switchPressCount);

            // Wait for switch release
            while (mraa_gpio_read(switch_pin) == 1) {
                // Wait for the switch to be released
                usleep(10000); // 10 ms delay
            }
        }

        // Delay to debounce and reduce CPU usage
        usleep(10000); // 10 ms delay
    }

    // Cleanup
    mraa_gpio_close(led1);
    mraa_gpio_close(led2);
    mraa_gpio_close(led3);
    mraa_gpio_close(switch_pin);
    mraa_deinit();

    return 0;
}

