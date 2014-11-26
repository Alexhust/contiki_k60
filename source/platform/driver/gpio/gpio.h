#ifndef _GPIO_H
#define _GPIO_H

#include "common.h"

#define GPIO_PIN_MASK            0x1Fu
#define GPIO_PIN(x)              (((1)<<(x & GPIO_PIN_MASK)))

#define BLUE 1
#define GREEN 2
#define YELLOW 3
#define ORANGE 4
#define ALL_LED 5
void init_gpio();
void turn_on(unsigned int Led_Marco);
void turn_off(unsigned int Led_Marco);
void toggle(unsigned int Led_Marco);
#endif


