#ifndef __SYSTEMTIME0_H__
#define __SYSTEMTIME0_H__
#include  "stm32f10x.h"
#include 	"..\tim\tim.h"
typedef struct 
{
	unsigned int msec1;   				 //1ms
	unsigned int msec10;					 //10ms
	unsigned int msec100;					 //100ms
	unsigned int msec1000;				 //1000ms = 1s
	unsigned char msec1flag;  		 //到1ms标志位
	unsigned char msec10flag;			 //到10ms标志位
	unsigned char msec100flag;		 //到100ms标志位
	unsigned char msec1000flag;		 //到1000ms = 1s标志位
}_systemtime;

extern _systemtime systemtime;


void SystemTimeInit(void);


#endif

