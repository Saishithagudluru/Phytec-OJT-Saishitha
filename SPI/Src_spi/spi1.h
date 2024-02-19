

#ifndef SPI1_H_
#define SPI1_H_


#include "stm32f4xx.h"
#include "uart.h"
#include"sp1.c"
#include "adxl345.c"
#include "stdint.h"

void spi_gpio_init(void);
void spi1_config(void);
void spi1_transmit(uint8_t *data,uint32_t size);
void spi1_receive(uint8_t *data,uint32_t size);
void cs_enable(void);
void cs_disable(void);

#endif /* SPI_H_ */
