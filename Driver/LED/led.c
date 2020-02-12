#include "led.h"
#include "stm32f10x.h"

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStr;//GPIO_Init函数 第二参数定义结构体
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//始能时钟GPIOB
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);//始能时钟GPIOE
	
	GPIO_InitStr.GPIO_Mode = GPIO_Mode_Out_PP; 
	GPIO_InitStr.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStr.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStr);//初始化GPIOB
	GPIO_SetBits(GPIOB,GPIO_Pin_5);//初始化GPIOB Pin5高电平
	
	GPIO_InitStr.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStr.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStr.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE,&GPIO_InitStr);  //初始化GPIOE
	GPIO_SetBits(GPIOE,GPIO_Pin_5);	//初始化GPIOE Pin5高电平

}
