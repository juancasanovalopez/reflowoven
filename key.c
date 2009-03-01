/*This file has been prepared for Doxygen automatic documentation generation.*/
/*! \file *********************************************************************
 *  \defgroup key Key Input
 *  \brief Basic key input functiions
 *
 * Reads state of switches connected to the port pins, compares the state to
 * the previous state and stores it into a bit-field
 *
 * - File:               key.c
 * - Compiler:           GCC
 * - Supported devices:  All AVR devices
 *
 * \author               Stephan Harms: http://www.stepphanharms.de \n
 *                       Support email: avr@stephaharms.de
 *
 *****************************************************************************/

#include <avr\io.h>
#include "key.h"


unsigned char keyChangeDown;
unsigned char keyChangeUp;
unsigned char keyChangePrev;




unsigned char KeyRead(void)
{
  return (PIND & 0b00011100) >> 2;
}


void KeyChange(void)
{
  unsigned char keyNew;

  keyNew = KeyRead();

  keyChangeDown = keyNew          & (keyChangePrev ^ 0xFF);
  keyChangeUp   = (keyNew ^ 0xFF) & (keyChangePrev);

  keyChangePrev = keyNew;
}

