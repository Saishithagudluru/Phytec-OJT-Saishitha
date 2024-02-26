#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <math.h>
#include "MQTTClient.h"

// MQTT Settings
#define ACCESS_TOKEN "SUMcuWGc31jDxIqGoONE"
#define MQTT_ADDRESS "tcp://phyclouds.com:1884"
#define MQTT_CLIENTID "iiscSmartSwitch"
#define MQTT_TOPIC "v1/devices/me/telemetry"
#define MQTT_QOS 1

// Global MQTT client variable
MQTTClient client;
MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;

// Function to publish data to MQTT
void publishToMQTT(char *topic, char *payload)
{
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    pubmsg.payload = payload;
    pubmsg.payloadlen = strlen(payload);
    pubmsg.qos = 1;
    pubmsg.retained = 0;
    MQTTClient_deliveryToken token;

    MQTTClient_publishMessage(client, topic, &pubmsg, &token);
    MQTTClient_waitForCompletion(client, token, 1000);

    int rc = MQTTClient_waitForCompletion(client, token, 10000);

    if (rc == MQTTCLIENT_SUCCESS)
    {
        // Print information about the published data
        printf("Published MQTT data - Topic: %s, Payload: %s\n", topic, payload);
    }
    else
    {
        fprintf(stderr, "Failed to publish file data. Return code: %d\n", rc);
    }
}

int main()
{
    // MQTT initialization
    MQTTClient_create(&client, MQTT_ADDRESS, MQTT_CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;
    conn_opts.username = ACCESS_TOKEN;

    if (MQTTClient_connect(client, &conn_opts) != MQTTCLIENT_SUCCESS)
    {
        fprintf(stderr, "Failed to connect to MQTT server\n");
        return -1;
    }

    while (1)
    {
       

        // Convert  data to JSON string
        char mqtt_payload[500];
        snprintf(mqtt_payload, sizeof(mqtt_payload), "{\"OFF\": 0, \"ON\": 1}");

        // Publish data to MQTT
        publishToMQTT(MQTT_TOPIC, mqtt_payload);

        // Print whether data is being published or not
        printf("Data %s published to MQTT\n", mqtt_payload);

        // Sleep for 3 seconds
        sleep(3);
    }

    // Cleanup MQTT resources
    MQTTClient_destroy(&client);

    return 0;
}
