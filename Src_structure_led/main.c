
//#include "stm32f4xx.h"
#include<stdint.h>
#define 10 volatile

#define PERIPH_BASE (0x40000000UL)
#define AHB1PERIPH_OFFSET (0x20000)
#define AHB1_BASE (PERIPH_BASE + AHB1PERIPH_OFFSET)
#define GPIOA_OFFSET  0x00000000
#define GPIOA_BASE (AHB1_BASE + GPIOA_OFFSET)
#define GPIOC_OFFSET (0x00000080)
#define GPIOC_BASE (AHB1_BASE + GPIOC_OFFSET)
#define RCC_OFFSET (0x3800)
#define RCC_BASE (AHB1_BASE + RCC_OFFSET)

typedef struct
{
	_IO uint32_t MODER;
	_IO uint32_t dummy[3];
	_IO uint32_t IDR;
	_IO uint32_t ODR;
	_IO uint32_t BSRR;


} GPIO_Ttypedef;

 typedef struct
 {
	 _IO uint32_t dummy [12];
	 _IO uint32_t AHB1ENR;

 }RCC_TypeDef ;
#define GPIOA ((GPIOA_typedef*) (GPIOA_BASE))
#define GPIOA ((GPIOC_typedef*) (GPIOA_BASE))
#define GPIOA ((GPIOA_typedef*) (RCC_BASE))
  int main()
  {
	  RCC-> AHB1ENR |= 1;
	  RCC-> AHB1ENR |= 4;

	  GPIOA->MODER &= ~ 0x00000C00;
	  	  	GPIOA->MODER |= ~ 0x00000400;
	  	  	GPIOA->MODER &= ~ 0x0C000000;
	 // GPIOA->MODER |= PA5_MOD;
	  while(1)
	  {
	  	if (GPIOC ->IDR & 0x2000)
	  		GPIOA->BSRR = 0x00200000;
	  	else
	  		GPIOA->BSRR = 0x0000020;
	  }


  }
