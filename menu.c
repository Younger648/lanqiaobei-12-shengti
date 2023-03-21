#include "head.h"



char scon = 1;


void menu()//菜单函数
{
	if(scon == 1)//菜单1，温度显示模式
	ds18b20_show();
	
	else if(scon == 2)//菜单2，温度参考模式
	ds18b20_refer_show();

}



void menu_key()
{
	key_scon(4);
	if(C1 == 0)
	{
		Delay5ms();
		if(C1 == 0)
		{
			scon++;
			if(scon == 3)
	    scon = 1;
		}
		while(C1 == 0);
	}
	

}













