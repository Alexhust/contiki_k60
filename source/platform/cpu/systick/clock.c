#include "clock.h"
#include "contiki-conf.h"
#include "sys/etimer.h"
static volatile clock_time_t current_clock = 0;
static volatile unsigned long current_seconds = 0;
static unsigned int second_countdown = CLOCK_SECOND;

void SysTick_handler(void)
{
    SCB_ICSR |= SCB_ICSR_PENDSVCLR_MASK;
    
    current_clock++;
    
    if(etimer_pending() && (etimer_next_expiration_time() <= current_clock) )
    {
        etimer_request_poll();
    }
    if (--second_countdown == 0) 
    {
        current_seconds++;                  
        second_countdown = CLOCK_SECOND;
    }
    
}

void clock_init()
{
    SCB_SHPR3 |= SCB_SHPR3_PRI_15(8);   
    SYST_RVR |= SysTick_RVR_RELOAD(CLOCK_RLD);
    SYST_CSR |= SysTick_CSR_CLKSOURCE_MASK |
                            SysTick_CSR_ENABLE_MASK;
                                                        
    SYST_CSR |= SysTick_CSR_TICKINT_MASK;
}

clock_time_t clock_time(void)
{
  return current_clock;
}

unsigned long clock_seconds(void)
{
  return current_seconds;
} 