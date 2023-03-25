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
			if(mode == 0)//ģʽ1��L1����
	{
		LED_config(1,1);
	}
	else
	{
		LED_config(1,0);
	}

	
	

	if(scon == 1)//�¶���ʾ���棬L2����
	{
		LED_config(2,1);
	}
	else
	{
		LED_config(2,0);
	}


	
	
	if(scon == 2)//������ʾ���棬L3����
	{
		LED_config(3,1);
	}
	else
	{
		LED_config(3,0);
	}

	
	

	if(scon == 3)//DAC��ʾ���棬L4����
	{
		LED_config(4,1);
	}
	else
	{
		LED_config(4,0);
	}	

	
}