/**
  ******************************************************************************
  * @file    main.c
  * @author  dzy
  * @version V1.0.0
  * @date    2018-8-25
  * @brief   main function.
  ******************************************************************************
  * @attention
  *
	*		There is no
  * 
  ******************************************************************************
* */

/* Includes ------------------------------------------------------------------*/
#include "motor.h"



/* Define ------------------------------------------------------------------*/
uint16_t phasecw[4] ={0x0008,0x004,0x0002,0x0001};// D-C-B-A   
uint16_t phaseccw[4]={0x0001,0x0002,0x0004,0x0008};// A-B-C-D



/** Exported_Functions		*/
/** @defgroup 模块定义/函数声明
  * @{
  */

/**
  * @brief  简易说明        
  * @param  输入参数说明
	* @return 返回值
  * @retval 返回值类型
  */
void Moto_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(Motor_RCC_Periph,ENABLE);
	GPIO_InitStructure.GPIO_Pin = Motor_GPIO_Pin ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(Motor_Periph,&GPIO_InitStructure);
	GPIO_ResetBits(Motor_Periph,Motor_GPIO_Pin );

}

void Motorcw(u16 speed,u16 num)
{  
  uint16_t i,t;  
  for(t=0;t<num;t++)
	{
		for(i=0;i<4;i++)  
    {  
        GPIO_Write(Motor_Periph,phasecw[i]);  
        delay_ms(speed);
    }  
	}
}

void Motorccw(u16 speed,u16 num)
{  
		 uint16_t i,t;  
		for(t=0;t<num;t++)  
		{
			for(i=0;i<4;i++)  
			{  
					GPIO_Write(Motor_Periph,phaseccw[i]);  
					delay_ms(speed);
			}  		
		}

}

void MotorStop(void)  
{  
    GPIO_Write(Motor_Periph,0x0000);  
}










