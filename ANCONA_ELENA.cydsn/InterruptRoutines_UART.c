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

#define IDLE 1
#define HEADER 2
#define RED 3
#define GREEN 4
#define BLUE 5
#define TAIL 6

CY_ISR(Custom_UART_IRS)
{
    int state=IDLE; 
    if (UART_ReadRxStatus()== UART_RX_STS_FIFO_NOTEMPTY)
    {
 
        char recived=UART_ReadRxData();
       
        {
            switch (state)
            {
            case IDLE:
                if (recived=='v')
                {
                    UART_PutString("RGB LED Program $$$\r\n");
                }
                else if (recived==0xA0)
                {
                    Timer_Start();
                    Timer_WriteCounter(255);
                    state++;
                }
            break;
          
            case HEADER:
                    Timer_WriteCounter(255);
                    int RedByte=UART_ReadRxData();
                    state++;
                if (Timer_ReadPeriod()==0)
                {
                        state=IDLE;
                }
            break;
                    
            case RED:
                    Timer_WriteCounter(255);
                    int GreenByte=UART_ReadRxData();
                    state++;
                if (Timer_ReadPeriod()==0)
                {
                        state=IDLE;
                }
            break;
            
            case GREEN:
                    Timer_WriteCounter(255);
                    int BlueByte=UART_ReadRxData();
                    state++;
                if (Timer_ReadPeriod()==0)
                {
                        state=IDLE;
                }
            break;        
                
            case BLUE:
                    Timer_WriteCounter(255);
                if (recived==0xC0)
                {
                        state++;
                        Timer_Stop();
                }
                if (Timer_ReadPeriod()==0)
                {
                        state=IDLE;
                }

            break;   
                
                case TAIL:
                //Set the RGB LED with the bytes from the UART
                PWM_RG_WriteCompare1(GreenByte);
                PWM_RG_WriteCompare2(RedByte); 
                PWM_B_WriteCompare(BlueByte);

                    state=IDLE;
            break;
            }
        }
    }
}

