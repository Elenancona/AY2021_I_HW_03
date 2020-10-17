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

#include "InterruptRoutines_UART.h"
#include "stdio.h"
#include "UART.h"
#include "PWM_B.h"
#include "PWM_RG.h"
#include "Timer.h"

CY_ISR(Custom_UART_IRS)
{
    if (UART_ReadRxData()== UART_RX_STS_FIFO_NOTEMPTY)
    {
        
        char recived=UART_ReadRxData();
        
        {
            switch (recived)
            {
            case 'R':
            Timer_Start();
            UART_PutString("Red led ON\r\n");
            PWM_RG_WriteCompare2(0);
            
            if (Timer_ReadPeriod()==0)
            {
            UART_Stop();
            }
            
            break;
          
            case 'G':
            Timer_Stop();
            Timer_Start();
            UART_PutString("Green led ON\r\n");
            PWM_RG_WriteCompare1(0);
            
             if (Timer_ReadPeriod()==0)
            {
            UART_Stop();
            }
            break;
            
            case 'B':
            Timer_Stop();
            Timer_Start();
            UART_PutString("Blue led ON\r\n");
            PWM_B_WriteCompare(0);
            
            if (Timer_ReadPeriod()==0)
            {
            UART_Stop();
            }
            break;
            }
        }         
    
    
}


/* [] END OF FILE */
