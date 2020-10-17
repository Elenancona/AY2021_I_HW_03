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
            break;
            
            if (Timer_ReadPeriod()==50)
            {   
                PWM_RG_WriteCompare2(51);
                PWM_RG_WriteCompare2(51);
                PWM_RG_WriteCompare2(51);
            }
            
            
           
                
            
            
          
            case 'G':
            Timer_Start();
            UART_PutString("Red led ON\r\n");
            PWM_RG_WriteCompare2(0);
            break;
  
            
            if (recived=='G')
            {
            Timer_Start();
            UART_PutString("Red led ON\r\n");
            PWM_RG_WriteCompare2(0);
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


/* [] END OF FILE */
