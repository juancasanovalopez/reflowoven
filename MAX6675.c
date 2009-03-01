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
#include <stdlib.h>
//#include <avr/pgmspace.h>

#include "MAX6675.h"



/* interrupt mode not implemented
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
*/


/*************************************************************************
Request a Temperatur value read for interrupt driven SPI
Input:    none
Returns:  none
*************************************************************************/
/* interrupt mode not implemented
void MAX6675RequestTemp(void)
{
        if (ClearToSend == 1){                  // if no transmission is in progress
                PtrToStrChar  = TextString;     // Set Pointer to beginning of String
                                                // initiate new transmission by 
                SPDR = *PtrToStrChar;           // sending first Char of new String
                ClearToSend = 0;                // block initiation of new transmissions
        }
}
*/


/*************************************************************************
Read the temperature Value
Input:    none
Returns:  0xFFFF: ERROR
          else:   Temperatur Value * 4 [°C]
*************************************************************************/
uint16_t MAX6675ReadTemp(void)
{
  uint16_t tempRead;
  uint8_t valRead;

  // pull SS Line low
  SPI_PORT &= ~(1<<SS_BIT);

  // start SPI data transfer
  SPDR = 0x00;

  // wait for transmision complete
  while(!(SPSR & (1<<SPIF)))
    ; // do nothing

  // copy hi byte
  valRead = SPDR;

  
  // start SPI data transfer
  SPDR = 0x00;

  // shift hi-byte
  tempRead = valRead << 5;

  // wait for transmision complete
  while(!(SPSR & (1<<SPIF)))
    ; // do nothing

  // copy hi byte
  valRead = SPDR;
  valRead &= 0b11111000;
  valRead >>= 3;

  tempRead |= valRead;

  // pull SS Line hi
  SPI_PORT |= (1<<SS_BIT);


  return tempRead;
}


/*************************************************************************
 * Initialize the SPI Port to communicate with MAX6675
 * Input:    none
 * Returns:  none
 ************************************************************************/
void MAX6675Init(void)
{
  //volatile char IOReg;

  // set /SS, MOSI, SCK as output 
  SPI_DDR  |= (1<<SS_BIT)|(1<<MOSI_BIT)|(1<<SCK_BIT);
  // enable SPI in Master Mode with SCK = CK/128
  SPCR  = (1<<SPE)|(1<<MSTR)|(1<<CPHA)|(1<<SPR0)|(1<<SPR1);
  
  //IOReg   = SPSR;                 	// clear SPIF bit in SPSR
  //IOReg   = SPDR;
}
