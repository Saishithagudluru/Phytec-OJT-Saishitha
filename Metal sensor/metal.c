#include <stdio.h>
#include <unistd.h>
#include <mraa/gpio.h>

#define GPIO_PIN_NUMBER 41 // Replace with the actual GPIO pin number for PA31
#define LED_PIN_NUMBER 61 // Replace with the actual GPIO pin number for PC13

int main() {
    mraa_init();

    // Create MRAA GPIO context
    mraa_gpio_context gpioPin = mraa_gpio_init(GPIO_PIN_NUMBER);
    mraa_gpio_context ledPin = mraa_gpio_init(LED_PIN_NUMBER);

    if (gpioPin == NULL || ledPin == NULL) {
        fprintf(stderr, "Failed to initialize GPIO pins\n");
        return 1;
    }

    // Set GPIO directions
    mraa_gpio_dir(gpioPin, MRAA_GPIO_IN);
    mraa_gpio_dir(ledPin, MRAA_GPIO_OUT);

    while (1) {
        // Read the GPIO value (0 or 1)
        int touchValue = mraa_gpio_read(gpioPin);

        if (touchValue) {
            printf("Touch detected\n");
            mraa_gpio_write(ledPin, 0); // Turn on LED
        } else {
            printf("Not detected\n");
            mraa_gpio_write(ledPin, 1); // Turn off LED
        }

        sleep(1); // Adjust the sleep duration as needed
    }

    // Cleanup and close GPIO pins when done
    mraa_gpio_write(ledPin, 0); // Turn off LED before cleanup
    mraa_gpio_close(gpioPin);
    mraa_gpio_close(ledPin);

    mraa_deinit();

    return 0;
}

