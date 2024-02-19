#include"stm32f4xx.h"

#define USART3_EN (1U<<18)
#define PB10_AF7 (7U<<8)
#define PB11_AF7 (7U<<12)
#define PB10_MODER (2U<<20)
#define PB11_MODER (2U<<22)
#define TXRX_EN (3U<<2)
#define USART3_E (1U<<13)
#define SR_RXNE (1U<<5)
#define SR_TC (1U<<6)
#define SR_TXE (1U<<7)


void USART3_init(void);
void USART3_write(int c);
char USART3_read(void);

int main (void)
{
	char c;
	USART3_init();
	while (1)
	{
		c = USART3_read();
		USART3_write(c);
	}
}

/* initialize UART4 to transmit at 9600 Baud */
void USART3_init(void)
{
	RCC->AHB1ENR |= 1;

	RCC->APB1ENR |= USART3_EN;/* Enable USART3 clock */

	GPIOB->AFR[1] |= PB10_AF7;
	GPIOB->AFR[1] |= PB11_AF7;

	GPIOB->MODER |= PB10_MODER;
	GPIOB->MODER |= PB11_MODER;
	USART3->BRR = 0x0683; /* 9600 baud @ 16 MHz */

	USART3->CR1 = TXRX_EN;
//enable Tx, Rx, 8-bit data
	USART3->CR2 = 0x0000; // 1 stop bit
	USART3->CR3 = 0x0000; /* no flow control */
	USART3->CR1 |= USART3_E;
}
/* Write a character to UART4 */
void USART3_write (int ch) {
while (!(USART3->SR & SR_RXNE)) {} // wait until Tx buffer empty
USART3->DR = (ch & 0xFF);
}
/* Read a character from UART4 */
char USART3_read(void) {
while (!(USART3->SR & SR_TC)) {} // wait until char arrives
return USART3->DR;
}
