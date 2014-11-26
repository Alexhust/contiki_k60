/*
 * File:		main.c
 * Purpose:		Main process
 *
 */

#include "common.h"
#include "clock.h" 
#include "gpio.h"

#include "sys/process.h"
#include "sys/procinit.h"
#include "sys/etimer.h"
#include "sys/autostart.h"

unsigned int idle_cnt = 0;
/*unsigned char tog_num = 0;*/

PROCESS(blink_process, "Blink");
PROCESS(blink1_process, "Blink1");

/*AUTOSTART_PROCESSES(&blink_process,&blink1_process);*/
AUTOSTART_PROCESSES(&blink_process);

PROCESS_THREAD(blink_process, ev, data)
{
    PROCESS_BEGIN();
      
    while(1)
    {
        static struct etimer et;
        /*struct etimer et;*/
        
        etimer_set(&et, CLOCK_SECOND);
        /*PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));*/
        PROCESS_WAIT_EVENT_UNTIL(ev == PROCESS_EVENT_TIMER);
        
        /* toggle the GREEN led   */
        toggle(GREEN);
        printf("\n Led GREEN OFF ");
        /*tog_num++;*/
        /*if( tog_num == 5)*/
        /*{*/
            /*process_start(&blink1_process,NULL);*/
            /*tog_num = 0;*/
        /*}*/
    }
    
    PROCESS_END();
}

PROCESS_THREAD(blink1_process, ev, data)
{
    PROCESS_BEGIN();
    
    /*process_exit(&blink_process);*/
    
    while(1)
    {
        static struct etimer et;
        
        etimer_set(&et, CLOCK_SECOND);
        /*PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));*/
        PROCESS_WAIT_EVENT_UNTIL(ev == PROCESS_EVENT_TIMER);
        
        /* toggle the BLUE led   */
        toggle(BLUE);
        printf("\n Led GREEN OFF ");
    }
    
    PROCESS_END();
}


int main (void)
{
    printf(" Initialing \n");
    init_gpio();
    clock_init();
    printf("\n start test!\n");
    process_init();
    process_start(&etimer_process,NULL);
    autostart_start(autostart_processes);
    
    printf(" Processes running \n");
    while(1)
    {
        do
        {
        }while(process_run()>0);
        idle_cnt++;
    }
	return 0;
}
