
#include <avr/interrupt.h>
#include "switch.h"







void SwitchOn(uint8_t ch)
{
  switch(ch)
  {
  case 1:
    SWITCH_PORT |= (1<<SWITCH_PIN_1);
	break;
  case 2:
    SWITCH_PORT |= (1<<SWITCH_PIN_2);
	break;
  case 3:
    SWITCH_PORT |= (1<<SWITCH_PIN_3);
	break;
  }



}


void SwitchOff(uint8_t ch)
{
  switch(ch)
  {
  case 1:
    SWITCH_PORT &= ~(1<<SWITCH_PIN_1);
	break;
  case 2:
    SWITCH_PORT &= ~(1<<SWITCH_PIN_2);
	break;
  case 3:
    SWITCH_PORT &= ~(1<<SWITCH_PIN_3);
	break;
  }



}


void InitSwitch(void)
{


  SWITCH_DDR |= (1<<SWITCH_PIN_1)|(1<<SWITCH_PIN_2)|(1<<SWITCH_PIN_3);


}
