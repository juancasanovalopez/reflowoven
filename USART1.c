// AVR306: Using the AVR UART in C
// Routines for polled USART
// Last modified: 02-06-21
// Modified by: AR

/* Includes */
#include <avr/io.h>



/* Initialize UART */
void USART_Init( unsigned int baudrate )
{
	/* Set the baud rate */
	UBRRH = (unsigned char) (baudrate>>8);                  
	UBRRL = (unsigned char) baudrate;
	
	/* Enable UART receiver and transmitter */
	UCSRB = ( ( 1 << RXEN ) | ( 1 << TXEN ) ); 
	
	/* Set frame format: 8 data 1stop */
	//UCSRC = (1<<UCSZ1)|(1<<UCSZ0);              //For devices with Extended IO
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);   //For devices without Extended IO
}


/* Read and write functions */
unsigned char USART_Receive( void )
{
	/* Wait for incomming data */
	while ( !(UCSRA & (1<<RXC)) ) 	
		;			                
	/* Return the data */
	return UDR;
}

void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !(UCSRA & (1<<UDRE)) )
		; 			                
	/* Start transmittion */
	UDR = data; 			        
}
