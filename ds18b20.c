#include "head.h"

uint temp;
uchar count = 25;
uchar adree;
uchar dat;





/*******************************����ds18b20��С����******************************************/

void Read_DS18b20_config()//��С���������
 {
	 float temp2;
	 uchar LSB ,HSB;
	 
	 EA = 0;
   init_ds18b20();
   EA = 1;
	 
	 Write_DS18B20(0xcc);
   Write_DS18B20(0x44);
		
	 delaySMG(10000);
	 
	 EA = 0;
	 init_ds18b20();
	 EA = 1;
	 
	 
	 Write_DS18B20(0xcc);
   Write_DS18B20(0xbe);
		
	 LSB = Read_DS18B20();//�߰�λ
   HSB = Read_DS18B20();//�Ͱ�λ

	 temp = (HSB << 8) | LSB;
	 temp = temp * 6.25;//6.25������λС����0.625����һλС����0.0625��������

	 
	 
//		temp = HSB;
//		temp = (temp << 8) | LSB;
//		if((temp & 0x800) == 0x0000��/�ж��Ƿ�Ϊ����
//		{
//		 temp >>= 4;
//		 temp = temp * 10;
//		 temp = temp + (LSB & 0x0f) * 6.25;	
//		}
 }


 
 
 
 

/*******************************�¶�****************************************/

void ds18b20_show()
{

	static char n;
	
	n++;
	if(n == 7)
	n = 1;
		
	switch(n)
	{
		case 1:
			adree = 0;
		  dat = 12;
		break;

		case 2:
			adree = 4;
		  dat = temp / 1000;
		break;
				
		case 3:
			adree = 5;
		  dat = (temp / 100) % 10;
		break;
						
		case 4:
			adree = 5;
		  dat = 20;
		break;
								
		case 5:
			adree = 6;
		  dat = (temp % 100) / 10;
		break;
		
		case 6:
			adree = 7;
		  dat = temp % 10;
		break;

	}
    SMG_config(SMG_adree[adree],SMG_duanma[dat]);
}










/********************************�¶Ȳ���*****************************************/

void ds18b20_refer_show()
{

	static char n;
	
	n++;
	if(n == 4)
	n = 1;
		
	switch(n)
	{
		case 1:
			adree = 0;
		  dat = 16;
		break;
		
		case 2:
			adree = 6;
		  dat = count / 10;
		break;
		
		case 3:
			adree = 7;
		  dat = count % 10;
		break;

	}
    SMG_config(SMG_adree[adree],SMG_duanma[dat]);
}











/*******************************�¶Ȳ�����������*********************************/
void refer_key()
{
	
	key_scon(3);
	if(C2 == 0)
	{
		Delay5ms();
		if(C2 == 0)
		{
			count ++;		
		}
		while(C2 == 0);
	}
	




  key_scon(4);//S8�������¶ȼ�1
	if(C2 == 0)
	{
		Delay5ms();
		if(C2 == 0)
		{
			count --;
		}
		while(C2 == 0);
	}


}













