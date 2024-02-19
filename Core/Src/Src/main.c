#include "stm32f4xx_hal.h"

// Function prototypes
void SystemClock_Config(void);
void Error_Handler(void);
void initUserSwitch(void);
void toggleSignalPin(void);

GPIO_InitTypeDef GPIO_InitStruct;

int main(void) {
    HAL_Init();
    SystemClock_Config();

    // Initialize PC13 (user switch)
    initUserSwitch();

    // Configure the GPIO pin for signal control
    __HAL_RCC_GPIOA_CLK_ENABLE(); // Enable the clock for GPIOA (or choose an appropriate GPIO)
    GPIO_InitStruct.Pin = GPIO_PIN_5; // Use GPIOA_PIN_5 (you can choose a different pin)
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; // Output push-pull
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    uint8_t currentColor = 0; // Initialize to the first color

    while (1) {
        // Check if PC13 is pressed
        if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET) {
            // Wait for the user switch to be released
            while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET)
                ;

            // Toggle the signal pin to cycle through the colors
            toggleSignalPin();


            // Increment the color counter and wrap around
            currentColor = (currentColor + 1) % 7;
            // Add a delay to avoid rapid color changes (debouncing)
            HAL_Delay(200); // Adjust the delay as needed
        }
    }
}

void initUserSwitch(void) {
    __HAL_RCC_GPIOC_CLK_ENABLE(); // Enable the clock for GPIOC
    GPIO_InitStruct.Pin = GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}

void toggleSignalPin(void) {
    // Toggle the signal pin to cycle through the colors
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5); // Toggle the signal pin
}

// System Clock Configuration
void SystemClock_Config(void) {
    // Configure the system clock here
}

// Error Handler
void Error_Handler(void) {
    // Handle errors here
    while (1) {
        // Error occurred, stay in a loop
    }
}
