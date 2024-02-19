#include "stm32f4xx.h"
#define TIM8EN		(1U<<1)
#define CR1_CEN		(1U<<0)
#define OC_TOGGLE	((1U<<4) | (1U<<5))
#define CCER_CC1E	(1U<<0)
#define GPIOAEN		(1U<<0)
#define AFR5_TIM	(3U<<12)
#define PIN5 (1U<<5)
#define  LED PIN5
#define DIR (1U<<4)
void tim2_pa5_output_compare(void);

int main(void)
{

	tim2_pa5_output_compare();
	while(1)
	{

	}
}

void tim2_pa5_output_compare(void)
{

	 /*Enable clock access to GPIOA*/
	RCC->AHB1ENR |=GPIOAEN;

	/*Set PA5 mode to alternate function*/
	GPIOA->MODER &=~(1U<<10);
	GPIOA->MODER |=(1U<<11);

	/*Set PA5 alternate function type to TIM2_CH1 (AF01)*/
	GPIOA->AFR[0] |=AFR5_TIM;

	/*Enable clock access to tim2*/
	RCC->APB1ENR |=TIM8EN;

	/*Set prescaler value*/
	TIM2->PSC =  1800 ;  //  16 000 000 / 1 600 = 10 000
	/*Set auto-reload value*/
	TIM2->ARR =  10000 - 1;  // 10 000 / 10 000 = 1

	/*Set output compare toggle mode ccmr1*/
	//TIM2->CCMR1 &= 0XFFFFFFFC;
	TIM2->CCMR1 |=7U<<4;

	/*Enable tim2 ch1 in compare mode ccer*/
	TIM2->CCER |=1<<0;

TIM2->CCR1 =1000; //set value for pwm counting
	/*Clear counter*/
	TIM2->CNT = 200;
	TIM2->CR1 |=DIR;
	//TIM2->CCR1 =500;

	/*Enable timer*/
	TIM2->CR1 = CR1_CEN;
}
