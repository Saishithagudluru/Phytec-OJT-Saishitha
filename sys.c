#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SWITCH_PIN "/sys/class/gpio/PC12/value"  // GPIO pin for the user switch (PC12)
#define LED_PIN "/sys/class/gpio/PD19/value"      // GPIO pin for the LED (PD19)

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int readSwitchValue() {
    FILE *fp = fopen(SWITCH_PIN, "r");
    if (fp == NULL) {
        error("Error opening switch pin");
    }

    char value;
    fscanf(fp, " %c", &value);  // Leading space to skip any leading whitespace
    fclose(fp);

    // '1' indicates the user switch is pressed, '0' indicates it is not pressed
    return (value == '1');
}

int readLEDState() {
    FILE *fp = fopen(LED_PIN, "r");
    if (fp == NULL) {
        error("Error opening LED pin");
    }

    char value;
    fscanf(fp, " %c", &value);  // Leading space to skip any leading whitespace
    fclose(fp);

    // '1' indicates the LED is ON, '0' indicates it is OFF
    return (value == '1');
}

void toggleLED(int state) {
    FILE *ledFile = fopen(LED_PIN, "w");
    if (ledFile == NULL) {
        error("Error opening LED pin");
    }

    // Set the LED pin based on the input state (1 for ON, 0 for OFF)
    fprintf(ledFile, "%d", state);

    fclose(ledFile);
}

int main() {
    // Export GPIO pin for the user switch (PC12)
    FILE *exportSwitch = fopen("/sys/class/gpio/export", "w");
    if (exportSwitch == NULL) {
        error("Error exporting switch GPIO pin");
    }

    fprintf(exportSwitch, "76");  // PC12
    fclose(exportSwitch);

    // Set the switch pin direction to in (for reading)
    FILE *directionSwitch = fopen("/sys/class/gpio/PC12/direction", "w");
    if (directionSwitch == NULL) {
        error("Error setting direction for switch GPIO pin");
    }

    fprintf(directionSwitch, "in");
    fclose(directionSwitch);

    // Export GPIO pin for the LED (PD19)
    FILE *exportLED = fopen("/sys/class/gpio/export", "w");
    if (exportLED == NULL) {
        error("Error exporting LED GPIO pin");
    }

    fprintf(exportLED, "115");  // PD19
    fclose(exportLED);

    // Set the LED pin direction to out (for writing)
    FILE *directionLED = fopen("/sys/class/gpio/PD19/direction", "w");
    if (directionLED == NULL) {
        error("Error setting direction for LED GPIO pin");
    }

    fprintf(directionLED, "out");
    fclose(directionLED);

    // Read the initial state of the LED pin
    int initialLEDState = readLEDState();

    while (1) {
        int switchState = readSwitchValue();

        if (switchState) {
            printf("Switch Pressed (PC12)\n");
            // Toggle the LED based on the initial state
            toggleLED(initialLEDState ? 0 : 1);
        } else {
            printf("Switch Not Pressed (PC12)\n");
        }

        // Adjust the sleep duration based on your sensor's update rate
        sleep(1);  // Sleep for 1 second between readings
    }

    // Unexport GPIO pins before exiting
    FILE *unexportSwitch = fopen("/sys/class/gpio/unexport", "w");
    if (unexportSwitch == NULL) {
        error("Error unexporting switch GPIO pin");
    }

    fprintf(unexportSwitch, "76");  // PC12
    fclose(unexportSwitch);

    FILE *unexportLED = fopen("/sys/class/gpio/unexport", "w");
    if (unexportLED == NULL) {
        error("Error unexporting LED GPIO pin");
    }

    fprintf(unexportLED, "115");  // PD19
    fclose(unexportLED);

    return 0;
}

