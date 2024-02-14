#define TIM2EN		(1U<<0)
#define CR1_CEN		(1U<<0)
#define SR_UIF          (1U<<0)

void tim2_1hz_init(void)
{
	/*Enable clock access to tim2*/
	
	/*Set prescaler value*/
	/*Set auto-reload value*/
	/*Clear counter*/
	/*Enable timer*/
	
}

void tim_delay(void)
{

       /*Wait for UIF */
	while(!(TIM2->SR & SR_UIF)){}

	/*Clear UIF*/
	TIM2->SR &=~SR_UIF;

}
