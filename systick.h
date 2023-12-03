
   /******************************************************************************
 *
 * [FILE NAME]: <SysTick.h>
 *
 * [AUTHOR]: <Abdelrhman Hesham>
 *
 * [DATE CREATED]: <14/11/2023>
 *
 * [DESCRIPTION]: <Header file for Systick>
 *
 *******************************************************************************/


#ifndef SYSTICK_H
#define SYSTICK_H

#include "Std_Types.h"

#define SYSTICK_PRIORITY_MASK  (0x1FFFFFFF)
#define SYSTICK_INTERRUPT_PRIORITY  (3)
#define SYSTICK_PRIORITY_BITS_POS   (29)

#define CURRENT_REG (0)
#define TIME_IN_SEC (15999999)
#define DIV_FOR_MILLI (1000)
#define CLEAR_REG (0x0)
#define MASK_FOR_INTERRUPT_AND_ENABLE (0x07)


 /*************************** Function Prototypes*************************
 Service Name: Systick_Init
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Tick_Time - Time in miliseconds
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Setup the SysTick Timer configuration to count in miliseconds:
*              - Set the Reload value
*              - Enable SysTick Timer with System clock 16Mhz
*              - Enable SysTick Timer Interrupt and set its priority
************************************************************************************/	

void Systick_Init(uint16 Tick_Time);

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

void SysTick_Stop(void);

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
void SysTick_SetCallBack(void (*FuncPointer)(void));




#endif