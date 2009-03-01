#ifndef switch_H
#define switch_H



#define SWITCH_PORT PORTD
#define SWITCH_DDR  DDRD

#define SWITCH_PIN_1 PD5
#define SWITCH_PIN_2 PD6
#define SWITCH_PIN_3 PD7


void SwitchOn(uint8_t ch);
void SwitchOff(uint8_t ch);
void InitSwitch(void);



#endif // SWITCH_h

