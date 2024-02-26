#include <mraa.h>

void Error_Handler(void) {
    while (1) {
        // Add error handling or debugging code here
    }
}

#define LASER_PIN 12  // Define the GPIO pin for controlling the KY-008 laser module (using MRAA pin numbers)
#define USER_BUTTON_PIN 35  // Using MRAA pin numbers

void GPIO_Init(void);
void GPIO_Cleanup(void);

int main(void) {
    // Initialize MRAA
    mraa_init();

    // Initialize peripherals
    GPIO_Init();

    uint8_t laserState = 0; // Variable to track laser state
    uint8_t previousButtonState = 1;

    while (1) {
        // Read the state of the user button
        mraa_gpio_context buttonPin = mraa_gpio_init(USER_BUTTON_PIN);
        uint8_t currentButtonState = mraa_gpio_read(buttonPin);
        mraa_gpio_close(buttonPin);

        if (currentButtonState != previousButtonState && currentButtonState == 0) {
            // User button is pressed, toggle the laser state
            mraa_gpio_context laserPin = mraa_gpio_init(LASER_PIN);
            mraa_gpio_write(laserPin, laserState);
            mraa_gpio_close(laserPin);

            laserState = !laserState;
        }

        previousButtonState = currentButtonState;
    }

    // Clean up MRAA
    GPIO_Cleanup();
    mraa_deinit();

    return 0;
}

void GPIO_Init(void) {
    // GPIO initialization code remains the same
    // ...

    // Example:
     mraa_gpio_context laserPin = mraa_gpio_init(LASER_PIN);
     if (mraa_gpio_dir(laserPin, MRAA_GPIO_OUT) != MRAA_SUCCESS) {
         Error_Handler();
     }
}

void GPIO_Cleanup(void) {
    // GPIO cleanup code remains the same
    // ...

    // Example:
     mraa_gpio_context laserPin = mraa_gpio_init(LASER_PIN);
     mraa_gpio_close(laserPin);

     mraa_gpio_context buttonPin = mraa_gpio_init(USER_BUTTON_PIN);
     mraa_gpio_close(buttonPin);
}

