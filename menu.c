#include "head.h"



char scon = 1;


void menu()//�˵�����
{
	if(scon == 1)//�˵�1���¶���ʾģʽ
	ds18b20_show();
	
	else if(scon == 2)//�˵�2���¶Ȳο�ģʽ
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













