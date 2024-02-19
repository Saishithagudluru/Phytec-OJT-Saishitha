#include"stm32f4xx.h"
#define PERIPH_BASE (0x40000000UL)
#define AHB1PERIPH_OFFSET (0x00020000UL)
#define AHB1PERIPH_BASE (PERIPH_BASE + AHB1PERIPH_OFFSET)
#define GPIOA_OFFSET (0x0000UL)
#define GPIOA_BASE (AHB1PERIPH_BASE + GPIOA_OFFSET)
#define RCC_OFFSET (0x3800UL)
#define RCC_BASE (AHB1PERIPH_BASE + RCC_OFFSET )
#define AHB1EN_R_OFFSET (0x30UL)
#define RCC_AHB1EN_R (*( volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))
#define MODER_OFFSET (0x00UL)
#define GPIOA_MODER (*( volatile unsigned int *)(RCC_BASE + MODER_OFFSET ))
#define ODR_OFFSET (0x014UL)
#define GPIOA_ODR (*( volatile unsigned int *)(RCC_BASE + ODR_OFFSET )))
#define GPIOA_EN (1U<<0)
#define PA5_MOD (1U<<10)
#define LED_PIN PA5_MOD

int main()
{

RCC->AHB1ENR |= GPIOA_EN;
GPIOA->MODER |= PA5_MOD;
while(1)
{
	GPIOA->ODR |= (1<<5);
	delayms(500);
	GPIOA->ODR &= ~(1<<5);
	delayms(500);

}
}
void delayms (int n)
{
int i;
for(;n>0;n--)
	for(i=0;i<3195;i++);
}
