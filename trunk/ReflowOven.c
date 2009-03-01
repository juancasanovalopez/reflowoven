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

	temp &= 0x0003;
	memset(tempString,0,16);
    itoa(temp*25, tempString, 10);
	if(tempString[0] == '0');
	  tempString[1] = '0';
	lcd_puts(tempString);

	lcd_puts(" ");

	_delay_ms(100.0);




               
  }
}
