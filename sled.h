#include<common.h>
#include<command.h>
#include<dm.h>
#include<errno.h>
#include<led.h>
#include<asm/gpio.h>

#define GPIO_PC_13 77
#define GPIO_PC_17 81
#define GPIO_PC_19 83

#define LED_ON 0
#define LED_OFF 1
#define LED_TOGGLE 2
#define LED_BLINK 3

int led_blink(int gpio_num);
int led_on(int gpio_num);
int led_off(int gpio_num);
int led_toggle(int gpio_num);
int led_init(int gpio_num);
int led_deinit(int gpio_num);

int sled_set_state(struct udevice *dev , unsigned int state);
