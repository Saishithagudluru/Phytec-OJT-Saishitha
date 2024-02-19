#include "stm32f4xx.h"
#include<stdint.h>
#include"header.h"

int main()
{

	pa1_adc_init();
	start_converstion();
	while(1)
	{
		uint32_t adc_value = adc_read();
		for(volatile uint32_t delay= 0;delay < 100000;++delay);
		//sensor_value= adc_read();

	}
}
