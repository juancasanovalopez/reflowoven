#ifndef MAX6675_H
#define MAX6675_H


#include <inttypes.h>


#define SPI_PORT   PORTB

#define SPI_DDR    DDRB

#define SS_BIT     PB1
#define MOSI_BIT   PB3

#define SCK_BIT    PB5



void MAX6675Init(void);

uint16_t MAX6675ReadTemp(void);

void MAX6675RequestTemp(void);

#endif // MAX6675_H
