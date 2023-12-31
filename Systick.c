
 /******************************************************************************
 *
 * [FILE NAME]: <SysTick.c>
 *
 * [AUTHOR]: <Abdelrhman Hesham>
 *
 * [DATE CREATED]: <14/11/2023>
 *
 * [DESCRIPTION]: <Source file for Systick>
 *
 *******************************************************************************/

#include "systick.h"
#include "tm4c123gh6pm_registers.h"


/* Global pointer to function used to point upper layer functions
 * to be used in Call Back */

static void (*SysTick_Call_Back_Pointer)(void) = NULL_PTR;

/************************************************************************************
* Service Name: SysTick_Handler
* Description: SysTick Timer ISR
************************************************************************************/
/*void SysTick_Handler(void)
{
    /* Check if the Timer0_setCallBack is already called 
    if(SysTick_Call_Back_Pointer != NULL_PTR)
    {
        (*SysTick_Call_Back_Pointer)(); /* call the function in the scheduler using call-back concept
    }
    /* No need to clear the trigger flag (COUNT) bit ... it cleared automatically by the HW
}*/

/************************************************************************************
* Service Name: SysTick_Start
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Tick_Time - Time in miliseconds
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Setup the SysTick Timer configuration to count n miliseconds:
*              - Set the Reload value
*              - Enable SysTick Timer with System clock 16Mhz
*              - Enable SysTick Timer Interrupt and set its priority
************************************************************************************/
void SysTick_Start(uint16 Tick_Time)
{
    SYSTICK_CTRL_REG    = CLEAR_REG;                                                /* Disable the SysTick Timer by Clear the ENABLE Bit */
    SYSTICK_RELOAD_REG  = (TIME_IN_SEC / DIV_FOR_MILLI) *Tick_Time;                 /* Set the Reload value to count n miliseconds */
    SYSTICK_CURRENT_REG = CURRENT_REG;                                              /* Clear the Current Register value */
 
    /* Configure the SysTick Control Register 
     * Enable the SysTick Timer (ENABLE = 1)
     * Enable SysTick Interrupt (INTEN = 1)
     * Choose the clock source to be System Clock (CLK_SRC = 1) */
    SYSTICK_CTRL_REG   |= MASK_FOR_INTERRUPT_AND_ENABLE;
    /* Assign priority level 3 to the SysTick Interrupt */
    NVIC_SYSTEM_PRI3_REG =  (NVIC_SYSTEM_PRI3_REG & SYSTICK_PRIORITY_MASK) | (SYSTICK_INTERRUPT_PRIORITY << SYSTICK_PRIORITY_BITS_POS);
}

/************************************************************************************
* Service Name: SysTick_Stop
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Stop the SysTick Timer.
************************************************************************************/
void SysTick_Stop(void)
{
    SYSTICK_CTRL_REG = CLEAR_REG; /* Disable the SysTick Timer by Clear the ENABLE Bit */
}

/************************************************************************************
* Service Name: SysTick_SetCallBack
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): FuncPointer - Call Back function address
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Setup the SysTick Timer call back
************************************************************************************/
void SysTick_SetCallBack(void(*FuncPointer)(void))
{
    SysTick_Call_Back_Pointer = FuncPointer;
}
