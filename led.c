#include "head.h"

unsigned P0_DAT = 0xff;


void LED_config(unsigned char ledx,unsigned char ledx_en)
{
	if(ledx_en == 0)
		P0_DAT |= 0x01<<(ledx-1);
	else
		P0_DAT &= ~(0x01<<(ledx-1));
	
	P0 = P0_DAT;
}



void mode_led()
{
			if(mode == 0)//模式1，L1点亮
	{
		LED_config(1,1);
	}
	else
	{
		LED_config(1,0);
	}

	
	

	if(scon == 1)//温度显示界面，L2点亮
	{
		LED_config(2,1);
	}
	else
	{
		LED_config(2,0);
	}


	
	
	if(scon == 2)//参数显示界面，L3点亮
	{
		LED_config(3,1);
	}
	else
	{
		LED_config(3,0);
	}

	
	

	if(scon == 3)//DAC显示界面，L4点亮
	{
		LED_config(4,1);
	}
	else
	{
		LED_config(4,0);
	}	

	
}