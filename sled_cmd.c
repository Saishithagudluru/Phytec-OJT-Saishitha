#include<common.h>
#include<command.h>
#include<errno.h>
#include<dm.h>
#include<asm/gpio.h>
#include<sled.h>

int led_set ( const char * state , int gpio_num)
{
	int retval=0;
	retval=led_init(gpio_num);
	if(retval < 0)
	{
		return retval;
	}

	if( !strcmp(state,"on"))
	{
		led_on(gpio_num);
	}
	else if(!strcmp(state,"off"))
	{
		led_off(gpio_num);
	}
	else if(!strcmp(state,"toggle"))
	{
		led_toggle(gpio_num);
	}
	else if(!strcmp(state,"blink"))
	{
		led_blink(gpio_num);
	}

	led_deinit(gpio_num);
return 0;
}

static int do_sled_cmd(cmd_tbl_t* cmdtp , int flag , int argc , char *const argv[])
{
	int gpio_num;
	const char * pin, *state =NULL;
	if(argc<2)
	{
		goto usage;
	}
	pin = argv[1];
	state = argv[2];

	if(!strcmp(pin,"PC13"))
	{
		gpio_num = 77;
		led_set(state, gpio_num);
	}
	else if(!strcmp(pin,"PC17"))
	{
		gpio_num = 81;
		led_set(state, gpio_num);
	}	
	else if(!strcmp(pin,"PC19"))
	{
		gpio_num = 83;
		led_set(state, gpio_num);
	}
	else
		printf("Available User leds are only --PC13,PC17, PC19 \n");

	return 0;
usage:
	return CMD_RET_USAGE;
}


U_BOOT_CMD(sled_cmd, 3,0, do_sled_cmd,"<pin> <on/off/toggle/blink>\n","eg;PC19 on\n");





