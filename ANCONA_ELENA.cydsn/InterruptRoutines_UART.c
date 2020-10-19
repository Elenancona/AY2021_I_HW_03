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

extern uint8_t state;
extern uint8_t recived;

uint8_t GreenByte;
uint8_t BlueByte;
uint8_t RedByte;

CY_ISR(Custom_UART_IRS)
{
    state=IDLE; 
    if (UART_ReadRxStatus()== UART_RX_STS_FIFO_NOTEMPTY)
    {
 
        recived=UART_ReadRxData();
       
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
                    RedByte=UART_ReadRxData();
                    state++;
                
            break;
                    
            case RED:
                    Timer_WriteCounter(255);
                    GreenByte=UART_ReadRxData();
                    state++;
                
            break;
            
            case GREEN:
                    Timer_WriteCounter(255);
                    BlueByte=UART_ReadRxData();
                    state++;
                
            break;        
                
            case BLUE:
                    Timer_WriteCounter(255);
                if (recived==0xC0)
                {
                        state++;
                        Timer_Stop();
                }

            break;   

                
            }
        }
    }
}

