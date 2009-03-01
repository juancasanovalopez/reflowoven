#ifndef KEY_H
#define KEY_H

/*This file has been prepared for Doxygen automatic documentation generation.*/
/*! \file *********************************************************************
 *  \defgroup key Key Input
 *  \brief Header file for key.c
 *
 * Reads state of switches connected to the port pins, compares the state to
 * the previous state and stores it into a bit-field
 *
 * - File:               key.h
 * - Compiler:           GCC
 * - Supported devices:  All AVR devices
 *
 * \author               Stephan Harms: http://www.stepphanharms.de \n
 *                       Support email: avr@stephaharms.de
 *
 *****************************************************************************/


#define KEY_RIGHT(key) ((key >> 0) & 0x01)
#define KEY_LEFT(key)  ((key >> 1) & 0x01)
//#define KEY_PREV(key)  ((key >> 3) & 0x01)
//#define KEY_NEXT(key)  ((key >> 4) & 0x01)
//#define KEY_UP(key)    ((key >> 5) & 0x01)
//#define KEY_DOWN(key)  ((key >> 0) & 0x01)

unsigned char KeyRead(void);
void KeyChange(void);


#endif //KEY_H
