#ifndef _TIM_H
#define _TIM_H

#include "sys.h"

void Tim_Init(u16 arr,u16 prer);
void System_Normal(void);
void TIM3_Int_Init(u16 arr,u16 psc);

extern u8 uart_flag ;
extern u8 time_flag;
extern u16 ManualPickTime;
#endif
