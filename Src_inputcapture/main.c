#include"stm32f4xx.h"
#define TIM2EN		(1U<<0)
#define TIM3EN		(1U<<1)
#define DIR          (0U<<4)
#define CR1_CEN		(1U<<0)
#define OC_TOGGLE	((1U<<4) | (1U<<5))
#define CCER_CC1E	(1U<<0)
//#define CCER_CC1P (1U<<1)

#define GPIOAEN		(1U<<0)
#define AFR5_TIM	(1U<<20)
#define AFR6_TIM	(1U<<25)
#define CCER_CC1S       (1U<<0)
#define SR_CC1IF     (1U<<1)
uint32_t timestamp;
void tim3_pa6_input_capture(void)
{

	/*Enable clock access to GPIOA*/
	RCC->AHB1ENR |=GPIOAEN;
	/*Set PA6 mode to alternate function*/
	GPIOA->MODER |=(2U<<12);
	/*Set PA6 alternate function type to TIM3_CH1 (AF02)*/
	GPIOA->AFR[0] |=AFR6_TIM;
        /*Enable clock access to tim3*/
	RCC->APB1ENR |=TIM3EN;
	/*Set Prescaler*/
	TIM3->PSC = 16000 -1; // 16 000 000 /16 000
	/*Set CH1 to input capture ccmr1*/
	TIM3 ->CCMR1 |= CCER_CC1S;
	TIM3->CCER = (1U<<1);
	/*Set CH1 to capture at rising edge ccer*/
	TIM3->CCER |= CCER_CC1E;
	TIM2->CCER |= (1U<<1);
	TIM2->CCER |= (0U<<3);
	//TIM2->CR1 |=DIR;

	/*Enable TIM3*/
	TIM3->CR1 = CR1_CEN;
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
	RCC->APB1ENR |=TIM2EN;

	/*Set prescaler value*/
	TIM2->PSC =  16000-1;  //  16 000 000 / 1 600 = 10 000
	/*Set auto-reload value*/
	TIM2->ARR =  2000- 1;  // 10 000 / 10 000 = 1

	/*Set output compare toggle mode ccmr1*/
	//TIM2->CCMR1 &= 0XFFFFFFFC;

	TIM2->CCMR1 |= 3U<<4;
//	TIM2->CCMR1 |=3U<<4;

	/*Enable tim2 ch1 in compare mode ccer*/
	TIM2->CCER |=1<<0;

  //  TIM2->CCR1 =1000; //set value for pwm counting
	/*Clear counter*/
	TIM2->CNT = 0;
	//TIM2->CR1 |= DIR;
	//TIM2->CCR1 =500;

	/*Enable timer*/
	TIM2->CR1 = CR1_CEN;
}
int main(void)
{


	tim2_pa5_output_compare();
	tim3_pa6_input_capture();

while(1)
	{

       		/*Wait until edge is captured*/
		while(!(TIM3->SR & SR_CC1IF)){}

		/*Read captured value*/
		timestamp =  TIM3->CCR1;

	}
}
