#include "head.h"



void  InitTimer0()
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x66;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	EA = 1;
	ET0 = 1;
}


void serviceTimer0() interrupt 1
{
	
	TL0 = 0x66;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	
	P0 = 0xff;

	
	HC138_config(4);

	
	mode_led();
	menu();
	
	HC138_config(5);
	jidianqi = 0;//关闭继电器，会导致数码管比较闪

	

}








