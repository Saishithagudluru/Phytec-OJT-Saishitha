#include "stm32f4xx.h"
void USART2_init(void);
void USART2_write(int c);
char USART2_read(void);
int main (void) {
USART2_init(); /* initialize USART2 */
while(1) { /* Loop forever */
USART2_write('Y');
USART2_write('e');
USART2_write('s');
delayMs(10); /* leave a gap between messages */
}
while(1) { /* Loop forever */
c = USART2_read();
}
void USART2_init (void) {
RCC->AHB1ENR |= 1; /* Enable GPIOA clock */
RCC->APB1ENR |= 0x20000; /* Enable USART2 clock */
/* Configure PA2 for USART2_TX */
GPIOA->AFR[0] &= ~0x0F00;
GPIOA->AFR[0] |= 0x0700; /* alt7 for USART2 */
GPIOA->MODER &= ~0x0030;
GPIOA->MODER |= 0x0020; /* enable alternate function for PA2 */
USART2->BRR = 0x0683; /* 9600 baud @ 16 MHz */
USART2->CR1 = 0x0008;/* enable Tx, 8-bit data */
USART2->CR2 = 0x0000; /* 1 stop bit */
USART2->CR3 = 0x0000; /* no flow control */
USART2->CR1 |= 0x2000;
GPIOA->MODER |= 0x00000400; /* set
pin to output mode */
/* enable USART2 */
USART2->CR1 =0x0004; /* enable Rx, 8-bit data */
//USART2->CR2 = 0x0000; /* 1 stop
//bit */
//USART2->CR3 = 0x0000; /* no flow control */
}
void delayMs(int n) {
int i;
for (; n > 0; n--)
/* Write a character to USART2 */
void USART2_write (int ch) {
while (!(USART2->SR & 0x0080)) {} // wait until Tx buffer empty
USART2->DR = (ch & 0xFF);
}
for (i = 0; i < 2000; i++) ; }
}
GPIOA->AFR[0] &= ~0xF000;
GPIOA->AFR[0] |= 0x7000; /* alt7 for USART2 */
GPIOA->MODER &= ~0x00C0;
GPIOA->MODER |= 0x0080; /* enable alternate function for PA3 */
}
/* Read a character from USART2 */
char USART2_read(void) {
while (!(USART2->SR & 0x0020)) {} // wait until char arrives
return USART2->DR;
}


delayMs(800);
}

void delayMs(int n) {
int i;
for (; n > 0; n--)
for (i = 0; i < 2000; i++) ; }
