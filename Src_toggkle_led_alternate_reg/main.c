
#include"stm32f4xx.h"
void delayms(int n);
#define GPIOA_EN (1<<0)
#define PA5_MOD (0x01<<10)
int main()
{
	RCC->AHB1ENR |= GPIOA_EN;
	GPIOA->MODER |= PA5_MOD;
	while(1)
	{
		GPIOA->BSRR =0x00000020;
		delayms(500);
		GPIOA->BSRR =0x00200000;
		delayms(500);

	}
}
void delayms(int n)
{
	int i;
	for(;n>0;n--)
		for(i=0;i<3195;i++);
}
