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

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    //Start UART
    UART_Start();
    UART_PutString("Send the string!\r\n");
    isr_UART_StartEx(Custom_UART_IRS);
    
    

    for(;;)
    {
       
        }
 }

