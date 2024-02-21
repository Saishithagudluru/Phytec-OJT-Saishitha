#include <stdio.h>
#include <mraa.h>

#define LED1_PIN 61  // Example GPIO pin for LED1
#define LED2_PIN 62  // Example GPIO pin for LED2
#define SWITCH_PIN 35 // Example GPIO pin for the switch

int main() {
    mraa_init(); // Initialize MRAA library

    // Initialize LED and switch GPIO pins
    mraa_gpio_context led1 = mraa_gpio_init(LED1_PIN);
    mraa_gpio_context led2 = mraa_gpio_init(LED2_PIN);
    mraa_gpio_context switch_pin = mraa_gpio_init(SWITCH_PIN);

    // Set LED pins as output
    mraa_gpio_dir(led1, MRAA_GPIO_OUT);
    mraa_gpio_dir(led2, MRAA_GPIO_OUT);

    // Set switch pin as input
    mraa_gpio_dir(switch_pin, MRAA_GPIO_IN);

    int switch_state = 0; // Tracks the state of the switch
    int switch_press_count = 0; // Tracks the number of times the switch is pressed

    while (1) {
        if (mraa_gpio_read(switch_pin) == 1 && switch_state == 0) { // Check if switch is pressed and its state is not already pressed
            switch_state = 1;
            switch_press_count++;
            
            if (switch_press_count % 2 == 1) { // Toggle LED states based on switch press count
                mraa_gpio_write(led1, 1);
                mraa_gpio_write(led2, 0);
            } else {
                mraa_gpio_write(led1, 0);
                mraa_gpio_write(led2, 1);
            }

            printf("Switch pressed %d times. LED1 state: %d, LED2 state: %d\n", switch_press_count, mraa_gpio_read(led1), mraa_gpio_read(led2));
        } else if (mraa_gpio_read(switch_pin) == 0 && switch_state == 1) { // Check if switch is released and its state is currently pressed
            switch_state = 0;
        }
    }

    // Cleanup GPIO resources
    mraa_gpio_close(led1);
    mraa_gpio_close(led2);
    mraa_gpio_close(switch_pin);
    mraa_deinit(); // Deinitialize MRAA library

    return 0;
}

