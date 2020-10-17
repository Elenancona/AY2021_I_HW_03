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
        char recived=UART_ReadRxData();
        
        {
            if (recived=='R')
            {
            UART_PutString("Red led ON\r\n");
            ;
            }
            
           
            
            case 'G':
            UART_PutString("Green led ON\r\n");
            Green_LED_pin_Write(1);
            break;
            
            case 'B':
            UART_PutString("Blue led ON\r\n");
            Blue_LED_pin_Write(1);
            break;
        }
    }
}
