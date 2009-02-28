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

#include "MAX6675.h"
#include "lcd.h"



int main (void)
{

        
  //MAX6675Init();                      // Initialization (polling)
  lcd_init(LCD_DISP_ON);

  lcd_puts("Hello World");

  while (1)
  {
    lcd_puts("Hello World");
               
  }
}
