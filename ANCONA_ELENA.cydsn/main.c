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

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    //Start UART
    UART_Start();
    
    //Start PWM
    PWM_RG_Start();
    PWM_B_Start();
    
    //Set the RGB LED OFF at power on
    PWM_RG_WriteCompare1(0);
    PWM_RG_WriteCompare2(0); 
    PWM_B_WriteCompare(0); 
    
    isr_UART_StartEx(Custom_UART_IRS);
      

    for(;;)
    {
       
    }
 }

