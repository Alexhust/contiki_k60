#include "gpio.h"

/*
 * Initialize GPIO for Tower switches and LED's
 *
 *   PTA19 - SW1
 *   PTE26 - SW2
 *
 *   PTA10 - Blue (E4)
 *   PTA29 - Green (E3)
 *   PTA28 - Yellow (E2)
 *   PTA11 - Orange (E1)
 *
 */
void init_gpio()
{
 
    /* Turn on all port clocks */
    SIM_SCGC5 = SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTB_MASK 
               | SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTD_MASK 
               | SIM_SCGC5_PORTE_MASK; 
 
    //Set PTA19 and PTE26 (connected to SW1 and SW2) for GPIO functionality, falling IRQ,
    //   and to use internal pull-ups. (pin defaults to input state)
    PORTA_PCR19=PORT_PCR_MUX(1)|PORT_PCR_IRQC(0xA)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
    PORTE_PCR26=PORT_PCR_MUX(1)|PORT_PCR_IRQC(0xA)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;

    //Set PTA10, PTA11, PTA28, and PTA29 (connected to LED's) for GPIO functionality
    PORTA_PCR10=(0|PORT_PCR_MUX(1));
    PORTA_PCR11=(0|PORT_PCR_MUX(1));
    PORTA_PCR28=(0|PORT_PCR_MUX(1));
    PORTA_PCR29=(0|PORT_PCR_MUX(1));

    //Change PTA10, PTA11, PTA28, PTA29 to outputs
    GPIOA_PDDR=GPIO_PDDR_PDD(GPIO_PIN(10) | GPIO_PIN(11) | GPIO_PIN(28) | GPIO_PIN(29) );	
}

void turn_on(unsigned int Led_Marco)
{
    
    switch(Led_Marco)
    {
        case BLUE:
        {
            GPIOA_PDOR&=~GPIO_PDOR_PDO(GPIO_PIN(10));
            break;
        }
        case ORANGE:
        {
            GPIOA_PDOR&=~GPIO_PDOR_PDO(GPIO_PIN(11));
            break;   
        }
        case YELLOW:
        {
            GPIOA_PDOR&=~GPIO_PDOR_PDO(GPIO_PIN(28));
            break;
        }
        case GREEN:
        {
            GPIOA_PDOR&=~GPIO_PDOR_PDO(GPIO_PIN(29));
            break;
        }
        case ALL_LED:
        {
            GPIOA_PDOR&=~GPIO_PDOR_PDO(GPIO_PIN(10));
            GPIOA_PDOR&=~GPIO_PDOR_PDO(GPIO_PIN(11));
            GPIOA_PDOR&=~GPIO_PDOR_PDO(GPIO_PIN(28));
            GPIOA_PDOR&=~GPIO_PDOR_PDO(GPIO_PIN(29));
            break;    
        }        
        default:
            break;
    }
}
void turn_off(unsigned int Led_Marco)
{
    
    switch(Led_Marco)
    {
        case BLUE:
        {
            GPIOA_PDOR|=GPIO_PDOR_PDO(GPIO_PIN(10));
            break;
        }
        case ORANGE:
        {
            GPIOA_PDOR|=GPIO_PDOR_PDO(GPIO_PIN(11));
            break;   
        }
        case YELLOW:
        {
            GPIOA_PDOR|=GPIO_PDOR_PDO(GPIO_PIN(28));
            break;
        }
        case GREEN:
        {
            GPIOA_PDOR|=GPIO_PDOR_PDO(GPIO_PIN(29));
            break;
        }
        case ALL_LED:
        {
            GPIOA_PDOR|=GPIO_PDOR_PDO(GPIO_PIN(10));
            GPIOA_PDOR|=GPIO_PDOR_PDO(GPIO_PIN(11));
            GPIOA_PDOR|=GPIO_PDOR_PDO(GPIO_PIN(28));
            GPIOA_PDOR|=GPIO_PDOR_PDO(GPIO_PIN(29));
            break;    
        } 
        default:
            break;
    }
}

void toggle(unsigned int Led_Marco)
{
    
    switch(Led_Marco)
    {
        case BLUE:
        {           
            GPIOA_PTOR|=GPIO_PDOR_PDO(GPIO_PIN(10));
            break;
        }
        case ORANGE:
        {           
            GPIOA_PTOR|=GPIO_PDOR_PDO(GPIO_PIN(11));
            break;   
        }
        case YELLOW:
        {
            GPIOA_PTOR|=GPIO_PDOR_PDO(GPIO_PIN(28));
            break;
        }
        case GREEN:
        {
            GPIOA_PTOR|=GPIO_PDOR_PDO(GPIO_PIN(29));
            break;
        }
        case ALL_LED:
        {
            GPIOA_PDOR|=GPIO_PDOR_PDO(GPIO_PIN(10));
            GPIOA_PDOR|=GPIO_PDOR_PDO(GPIO_PIN(11));
            GPIOA_PDOR|=GPIO_PDOR_PDO(GPIO_PIN(28));
            GPIOA_PDOR|=GPIO_PDOR_PDO(GPIO_PIN(29));
            break;    
        } 
        default:
            break;
    }
}
    