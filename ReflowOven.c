//***************************************************************************
// ReflowOven - main-file
//
// File Name            : "ReflowOven
// Title                : ReflowOven for SMD soldering
// Date                 : 2008/02/27
// Version              : 0.1
// Target MCU           : ATMega8
//
// DESCRIPTION
// 
//
//
// Modified 2008-02-27 
//
//**************************************************************************

#include <avr/interrupt.h>

#include "MAX6675.h"
#include "lcd.h"
#include "usart1.h"
#include "ReflowOven.h"
#include <stdlib.h>
#include <util/delay.h>
#include <string.h>


int main (void)
{
  int16_t temp;

  char tempString[16];
        

  lcd_init(LCD_DISP_ON);

  lcd_puts("Hello World");

  MAX6675Init();                      // Initialization

  //uart_init(UART_BAUD_SELECT(9600,16000000L));
  USART_Init( 103 ); /* Set the baudrate to 9,600 bps using a 16.0 MHz crystal */


  sei();

  while (1)
  {
    lcd_home();

    lcd_puts("Hello: ");

	temp = MAX6675ReadTemp();


	memset(tempString,0,16);
	itoa(temp/4, tempString, 10);
	lcd_puts(tempString);

    lcd_puts(",");

	memset(tempString,0,16);
    itoa((temp & 0x0003)*25, tempString, 10);
	if((tempString[0] == '0')||(tempString[0] == '5'))
	  tempString[1] = '0';
	lcd_puts(tempString);

	lcd_puts(" ");

	//uart_putc('T');
    USART_Transmit('T');
	USART_Transmit((temp >> 8) & 0x00FF);
	USART_Transmit(temp & 0x00FF);
	//uart_putc(10);
	//uart_putc(20);

	_delay_ms(1000.0);




               
  }
}
