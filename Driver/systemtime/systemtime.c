#include "..\systemtime\systemtime.h"

_systemtime systemtime ={
													0,10,10,10,//初始化时间
													0, 0, 0, 0//初始化标志位
												};




void SystemTimeInit(void)
{
	  TIM3_Int_Init(99,719);//Tim2 1ms
}

void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update))
	{
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);	
		systemtime.msec1 = 1;//1ms
		systemtime.msec1flag  = 1;//到1ms标志位
		systemtime.msec10 -=1;
		if(systemtime.msec10==0)//10ms
		{
			systemtime.msec10 = 10;
			systemtime.msec100 -=1;
			systemtime.msec10flag = 1;//到10ms标志位
			if(systemtime.msec100 == 0)//100ms
			{
				systemtime.msec100 = 10;
				systemtime.msec1000 -=1;
				systemtime.msec100flag = 1;//到100ms标志位
				if(systemtime.msec1000 == 0)//1000ms
				{
					systemtime.msec1000 = 10;
					systemtime.msec1000flag = 1;//到1000ms标志位
					
				}
			}
		}
	}
}

