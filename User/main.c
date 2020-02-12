#include "stm32f10x.h"
#include <string.h>
#include "delay.h"
#include "led.h"
#include "OLED_I2C.h"
#include "motor.h"
#include "usart.h"
#include "../systemtime/systemtime.h"
extern const unsigned char gImage_sy[];

int main(void)
{
	int i = 0;
	u16 len;
  u8 flash = 0;
	LED_Init();
	delay_init();
	I2C_Configuration();
	OLED_Init();
	Moto_Init();
	uart_init(115200);
	SystemTimeInit();
		OLED_Fill(0xFF);//全屏点亮
		delay_us(2);
		OLED_Fill(0x00);//全屏灭
		delay_us(2);
		for(i=0;i<5;i++)
		{
			OLED_ShowCN(22+i*16,0,i);//测试显示中文
		}
		delay_us(2);
		OLED_ShowStr(0,3,"HelTec Automation",1);//测试6*8字符
		WriteCmd(0xa7); //--set normal display
		OLED_ShowStr(0,4,"Hello Tech",1);				//测试8*16字符
		WriteCmd(0xa6); //--set normal display
		OLED_ShowStr(0,5,"Hello Test",1);				//测试8*16字符
//		while(1);
		delay_us(2);
		OLED_CLS();//清屏
		OLED_OFF();//测试OLED休眠
		delay_us(2);
		OLED_ON();//测试OLED休眠后唤醒
		OLED_DrawBMP(0,0,64,8,(unsigned char *)gImage_sy);//测试BMP位图显示
		delay_us(2);
		printf("ok\n%s,%s",__DATE__,__TIME__);
		//OLED_ShowStr(65,3,"HelTe",1);//测试6*8字符
	while(1)
	{
		if(systemtime.msec1flag == 1)// ---------------------------------1Ms到了
		{
			systemtime.msec1flag = 0;
		}
		
		if(systemtime.msec10flag == 1)// ---------------------------------10Ms到了
		{
			systemtime.msec10flag = 0;
		}
		
		if(systemtime.msec100flag == 1)// ---------------------------------100Ms到了
		{
			systemtime.msec100flag = 0;
		if(USART_RX_STA&0x8000)
		{ 
			OLED_CLS();//清屏
			len=USART_RX_STA&0x3FFF;//得到此次接收到的数据长度
			printf("%d",len);
			if(len<600)OLED_DrawBMP(0,0,64,8,(unsigned char *)USART_RX_BUF);//测试BMP位图显示
			else 			 OLED_DrawBMP(0,0,128,8,(unsigned char *)USART_RX_BUF);//测试BMP位图显示
	
//				while(USART_RX_BUF[i]!=';')
//				{
//					printf("[%d]=%x\n",i,USART_RX_BUF[i]);
//					i++;
//				}
				switch(USART_RX_BUF[0])
				{                                       
					case 'L':printf("\r\n反转\r\n");Motorcw(5,256);break;
					case 'R':printf("\r\n正转\r\n");Motorccw(5,256);break;
					case 'S':printf("\r\n暂停\r\n");MotorStop();break;
					default : break;
				}
        //                printf("\r\n\r\n");//插入换行
				USART_RX_STA=0;
				memset(USART_RX_BUF,'\0',USART_REC_LEN);
		}
			if(flash<10)
			{
				if(flash<5)
				{
					GPIO_SetBits(GPIOB,GPIO_Pin_5);
					GPIO_ResetBits(GPIOE,GPIO_Pin_5);
				}
				else
				{
					GPIO_ResetBits(GPIOB,GPIO_Pin_5);
					GPIO_SetBits(GPIOE,GPIO_Pin_5);
				}
				flash++;
			}
			else flash = 0;
			
		}
		

		if(systemtime.msec1000flag == 1)// 1000Ms到了
		{
				systemtime.msec1000flag = 0;
			
				
		}//	if(systemtime.msec1000flag == 1)// 1000Ms到了
		
	}//while(1)

}
