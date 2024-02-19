#include "main.h"
#include "MQTTClient.h"
#include "MQTTPacket.h"
#include "stdio.h"
#include "string.h"
#include "stm32f4xx_hal.h"

/* MQTT Client */
MQTTClient client;

/* MQTT Configuration */
const char *broker_address ="http://phyclouds.com:8080";
const int broker_port = 1883; // Default MQTT port
const char *client_id = "SUMcuWGc31jDxIqGoONE";
const char *topic = "v1/devices/me/telemetry";

/* LED Pin Configuration */
#define LED_PIN GPIO_PIN_5
#define LED_PORT GPIOA

/* Function Prototypes */
void connectToBroker();
void subscribeToTopic();
void messageCallback(MessageData *data);
void controlLED(bool state);
void SystemClock_Config(void);
static void MX_GPIO_Init(void);

/* Infinite Loop */
int main(void) {
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();

    connectToBroker();
    subscribeToTopic();

    MQTTClient_setCallbacks(&client, NULL, messageCallback, NULL); // Set message callback

    while (1) {
        MQTTClient_yield(&client, 1000); // Handle network operations with a timeout
    }
}

void connectToBroker() {
    // Initialize MQTT client with network settings
    int rc = MQTTClient_create(&client, broker_address, client_id, MQTTCLIENT_PERSISTENCE_NONE, NULL);
    if (rc != MQTTCLIENT_SUCCESS) {
        printf("MQTT client creation failed: %d\n", rc);
        return;
    }

    // Connect to the MQTT broker
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    conn_opts.keepAliveInterval = 60; // Set keep-alive interval
    conn_opts.cleansession = 1; // Start with a clean session

    rc = MQTTClient_connect(&client, &conn_opts);
    if (rc != MQTTCLIENT_SUCCESS) {
        printf("MQTT connection failed: %d\n", rc);
        MQTTClient_destroy(&client);
        return;
    }

    // Subscribe to the control topic
    rc = MQTTClient_subscribe(&client, topic, 0);
    if (rc != MQTTCLIENT_SUCCESS) {
        printf("MQTT subscription failed: %d\n", rc);
    }
}

void subscribeToTopic() {
    int rc = MQTTClient_subscribe(&client, topic, 0);
    if (rc != MQTTCLIENT_SUCCESS) {
        printf("MQTT subscription failed: %d\n", rc);
    } else {
        printf("Subscribed to topic: %s\n", topic);
    }
}

void messageCallback(MessageData *data) {
    bool control_state = (data->message->payloadlen > 0 && data->message->payload[0] == '1');
    controlLED(control_state);
    printf("Received control command: %s\n", control_state ? "ON" : "OFF");
}

void controlLED(bool state) {
    if (state) {
        HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_SET);
    } else {
        HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_RESET);
    }
}

void SystemClock_Config(void) {
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
    RCC_OscInitStruct.PLL.PLLM = 16;
    RCC_OscInitStruct.PLL.PLLN = 336;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
    RCC_OscInitStruct.PLL.PLLQ = 2;
    RCC_OscInitStruct.PLL.PLLR = 2;

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
        Error_Handler();
    }

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
        Error_Handler();
    }
}

static void MX_GPIO_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_InitStruct.Pin = LED_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED_PORT, &GPIO_InitStruct);
}

void Error_Handler(void) {
    __disable_irq();
    while (1) {
    }
}

#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line) {
    while (1) {
    }
}
#endif /* USE_FULL_ASSERT */
