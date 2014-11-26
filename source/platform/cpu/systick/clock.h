/*
 * File:		clock.h
 * Purpose:		to realize the systick timer of K60,
                including initialzation and interrupt routine
 *
 * Notes:
 */

#ifndef _CLOCK_H
#define _CLOCK_H

#include "common.h"
#include "contiki-conf.h"

#ifdef CLOCK_CONF_SECOND
#define CLOCK_SECOND CLOCK_CONF_SECOND
#else
#define CLOCK_SECOND (clock_time_t)32
#endif

#define CLOCK_RLD  96000000/CLOCK_SECOND    //the systick interrupt per 10ms

void SysTick_handler(void);
void clock_init(void);
clock_time_t clock_time(void);
unsigned long clock_seconds(void);

/***********************************************************************/
#endif	/* _CLOCK_H */
