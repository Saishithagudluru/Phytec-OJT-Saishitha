#include<common.h>
#include<command.h>
#include<errno.h>
#include<dm.h>
#include<asm/gpio.h>


#include<asm/gpio.h>
#include<dm/lists.h>

#include<dm/uclass-internal.h>
#include<sled.h>

struct sled_priv
{
	unsigned int gpio;
};

int led_on(int gpio_num)
{
	gpio_set_value(gpio_num,0);
	printf("state of led is : ON \n");
	return 0;
}
int led_off(int gpio_num)
{
	gpio_set_value(gpio_num,1);
	printf("state of led is : OFF \n");
	return 0;
}
int led_toggle(int gpio_num)
{
	printf("state of led is : TOGGLE \n");
	gpio_set_value(gpio_num,0);
	udelay(1000000);
	gpio_set_value(gpio_num,1);
	udelay(1000000);
	return 0;
}

int led_blink(int gpio_num)
{
	printf("state of led is : BLINK for 10 secs \n");

	for(int i=0;i<10;i++)
	{
	    gpio_set_value(gpio_num,0);
	    udelay(1000000);
	    gpio_set_value(gpio_num,1);
	    udelay(1000000);
	}
	return 0;
}

int led_init(int gpio_num)
{
	int retval=0;
	retval= gpio_request(gpio_num, "sled");
	if(retval < 0)
	{
		return retval;
	}
	retval = gpio_direction_output(gpio_num,1);
	return retval;
}

int led_deinit(int gpio_num)
{
	gpio_free(gpio_num);
	return 0;
}


int sled_set_state(struct udevice *dev, unsigned int state)
{
	switch(state)
	{
		case LED_ON:  led_init(GPIO_PC_19);
			      led_on(GPIO_PC_19); break;

		case LED_OFF: led_init(GPIO_PC_19);
			      led_off(GPIO_PC_19); break;

		case LED_TOGGLE: led_init(GPIO_PC_19);
				 led_on(GPIO_PC_19);
				 udelay(1000000);
				 led_init(GPIO_PC_19);
				 led_off(GPIO_PC_19);
				 udelay(1000000);       break;
		case LED_BLINK:  led_init(GPIO_PC_19);
				 for(int i=0;i<10;i++)
				 { 
				 led_on(GPIO_PC_19);
				 udelay(1000000);
				 led_init(GPIO_PC_19);
				 led_off(GPIO_PC_19);
				 udelay(1000000);
				 }	 break;
		default:
				 return ENOSYS;
	}
	return 0;
}


static int sled_probe(struct udevice *dev)
{
	const char *default_state;
	default_state=dev_read_string(dev, "sled-default-state");
	if( default_state)
	{
		if (!strncmp(default_state,"on",2))
			sled_set_state(dev,LED_ON);

		if (!strncmp(default_state,"off",3))
			sled_set_state(dev,LED_OFF);

		if (!strncmp(default_state,"toggle",6))
			sled_set_state(dev,LED_TOGGLE);

		if (!strncmp(default_state,"blink",5))
			sled_set_state(dev,LED_BLINK);
	}
	return 0;
}

static int sled_bind(struct udevice *parent)
{
	struct udevice *dev;
	ofnode node;
	int ret;

	dev_for_each_subnode(node, parent)
	{
		struct led_uc_plat *uc_plat;
		const char *label;
		label = ofnode_read_string(node,"label");
		if(!label)
		{
			debug("%s : node %s has no label \n",__func__,ofnode_get_name(node));
			return -EINVAL;
		}

		ret = device_bind_driver_to_node ( parent , "sled", ofnode_get_name(node),node,&dev);

		if (ret)
			return ret;

		uc_plat = dev_get_uclass_platdata(dev);
		uc_plat->label = label;

		if( ofnode_read_bool(node ,"sled-default-state"))
		{
			struct udevice *devp;
			ret = uclass_get_device_tail(dev, 0, &devp);
			if(ret)
				return ret;
		}
	}
return 0;
}


static const struct led_ops sled_ops = {
	.set_state = sled_set_state,
};

static const struct udevice_id sled_ids[]={
	{ .compatible = "sled-driver"},
	{}
};

U_BOOT_DRIVER(sled) = {
	.name = "sled",
	.id   =  UCLASS_LED,
	.of_match = sled_ids,
	.ops = &sled_ops,
	.priv_auto_alloc_size = sizeof(struct sled_priv),
	.bind = sled_bind,
	.probe = sled_probe,
};
