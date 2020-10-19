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
#include "Interrupt_isr.h"
#include "Timer.h"
#include "InterruptRoutines_UART.h"


CY_ISR(Custom_IRS)
{
  Timer_ReadStatusRegister();
}
