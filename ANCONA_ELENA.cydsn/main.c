/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "InterruptRoutines_UART.h"
#include "Interrupt_isr.h"

#define IDLE 1
#define TAIL 6

uint8_t state=IDLE;
uint8_t recived;

extern uint8_t RedByte;
extern uint8_t GreenByte;
extern uint8_t BlueByte;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    //Start UART
    UART_Start();
    
    //Start PWM
    PWM_RG_Start();
    PWM_B_Start();
    
    //Set the RGB LED OFF at power on
   
    PWM_RG_WriteCompare1(0); //Duty cicle 0% (LED OFF)
    PWM_RG_WriteCompare2(0); 
    PWM_B_WriteCompare(0); 
    
    
    //Inizializing the IRS
    isr_UART_StartEx(Custom_UART_IRS);
    isr_tc_StartEx(Custom_IRS);

    for(;;)
    {
        if (state==TAIL)
        {
            //Set the RGB LED with the bytes from the UART
                PWM_RG_WriteCompare1(GreenByte);
                PWM_RG_WriteCompare2(RedByte); 
                PWM_B_WriteCompare(BlueByte);

                        state=IDLE;
        }
       
    }
 }

