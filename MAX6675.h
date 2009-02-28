#ifndef MAX6675_H
#define MAX6675_H


#include <inttypes.h>

void MAX6675Init(void);

uint16_t MAX6675ReadTemp(void);

void MAX6675RequestTemp(void);

#endif // MAX6675_H
