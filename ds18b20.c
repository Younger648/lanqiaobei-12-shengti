#include "head.h"

uint temp;
uchar count = 25;
uchar adree;
uchar dat;





/*******************************配置ds18b20带小数点******************************************/

void Read_DS18b20_config()//带小数点的配置
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
		
	 LSB = Read_DS18B20();//高八位
   HSB = Read_DS18B20();//低八位

	 temp = (HSB << 8) | LSB;
	 temp = temp * 6.25;//6.25保留两位小数，0.625保留一位小数，0.0625保留整数

	 
	 
//		temp = HSB;
//		temp = (temp << 8) | LSB;
//		if((temp & 0x800) == 0x0000）/判断是否为负数
//		{
//		 temp >>= 4;
//		 temp = temp * 10;
//		 temp = temp + (LSB & 0x0f) * 6.25;	
//		}
 }


 
 
 
 

/*******************************温度****************************************/

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










/********************************温度参数*****************************************/

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











/*******************************温度参数按键控制*********************************/
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
	




  key_scon(4);//S8，按下温度减1
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













