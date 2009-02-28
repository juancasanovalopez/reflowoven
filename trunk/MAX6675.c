/***************************************************************************
 * Title:         MAX6675 K-Typ Temperatur SPI Sensor  
 * Author: 
 *
 * File Name            : "MAX7775.c"
 * Title                : MAX6675 SPI interface
 * Date                 : 2008/02/27
 * Version              : 0.1
 * Target MCU           : Any AVR with SPI
 *
 * DESCRIPTION
 * The MAX6675 is a Temperatur Sensor IC for K-Type Termocouplers. 
 *
 * \author               Stephan Harms: http://www.stepphanharms.de \n
 *                       Support email: avr@stephaharms.de
 *
 * Modified 2008-02-27 
*************************************************************************/

#include <inttypes.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include "MAX6675.h"
#include <avr/interrupt.h>



char*    TextString    = "AVR communicating via the SPI"+0x00;
char*    PtrToStrChar;                  	// Pointer to certain Character in String
char     ClearToSend   = 1;             	// String send complete bit

// Interrupt Routine Master Mode (interrupt controlled)
ISR(SPI_STC_vect)
{
        PtrToStrChar++;                 	// Point to next Char in String
        if (*PtrToStrChar != 0)         	// if end not reached
        {
                SPDR  = *PtrToStrChar;  	// send Character
        }
        else ClearToSend = 1;           	// if end reached enable transmission of next String
}


/*************************************************************************
Request a Temperatur value read for interrupt driven SPI
Input:    none
Returns:  none
*************************************************************************/
void MAX6675RequestTemp(void)
{
        if (ClearToSend == 1){                  // if no transmission is in progress
                PtrToStrChar  = TextString;     // Set Pointer to beginning of String
                                                // initiate new transmission by 
                SPDR = *PtrToStrChar;           // sending first Char of new String
                ClearToSend = 0;                // block initiation of new transmissions
        }
}



/*************************************************************************
Read the requested temperature Value from the buffer
Input:    none
Returns:  0xFFFF: ERROR
          else:   Temperatur Value * 4 [°C]
*************************************************************************/
uint16_t MAX6675ReadTemp(void)
{
        if (ClearToSend == 1){                  // if no transmission is in progress
                PtrToStrChar  = TextString;     // Set Pointer to beginning of String
                                                // initiate new transmission by 
                SPDR = *PtrToStrChar;           // sending first Char of new String
                ClearToSend = 0;                // block initiation of new transmissions
        }

		return 0;
}


/*************************************************************************
Initialize the SPI Port to communicate with MAX6675
Input:    none
Returns:  none
*************************************************************************/
void MAX6675Init(void)
{
  volatile char IOReg;
  // set PB4(/SS), PB5(MOSI), PB7(SCK) as output 
  DDRB  = (1<<PB4)|(1<<PB5)|(1<<PB7);
  // enable SPI Interrupt and SPI in Master Mode with SCK = CK/16
  SPCR  = (1<<SPIE)|(1<<SPE)|(1<<MSTR)|(1<<SPR0);
  IOReg   = SPSR;                 	// clear SPIF bit in SPSR
  IOReg   = SPDR;
  sei();
}
