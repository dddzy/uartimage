/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _MOTOR_H
#define _MOTOR_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "sys.h"
#include "delay.h"


/* Define  ------------------------------------------------------------------*/

#define Motor_RCC_Periph 		RCC_APB2Periph_GPIOE
#define Motor_Periph 				GPIOE
#define Motor_GPIO_Pin			GPIO_Pin_0 | GPIO_Pin_1 |GPIO_Pin_2 |GPIO_Pin_3

/**  MOTOR_Exported_Functions		*/

void Moto_Init(void);
void Motorcw(u16 speed,u16 num);
void Motorccw(u16 speed,u16 num);
void MotorStop(void); 


#endif /*_MOTOR_H */
