#ifndef USART1_H
#define USART1_H
// AVR306: Using the AVR UART in C
// Routines for polled UART
// Last modified: 02-06-21
// Modified by: AR




/* Prototypes */
void USART_Init( unsigned int baudrate );
unsigned char USART_Receive( void );
void USART_Transmit( unsigned char data );



#endif // USART1_H
