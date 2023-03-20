#include "head.h"

uint temp;






/*******************************配置ds18b20带小数点******************************************/

void ds18b20_config_dot()
{
	uchar LSB , HSB;
	
	init_ds18b20();
	Delay_OneWire(10000);
	
	Write_DS18B20(0xcc);
	Write_DS18B20(0x44);
	Delay_OneWire(10000);
	
	init_ds18b20();
	Delay_OneWire(1000);
	
	Write_DS18B20(0xcc);
	Write_DS18B20(0xbe);
	Delay_OneWire(10000);
	
	LSB = Read_DS18B20();
	HSB = Read_DS18B20();
	
	temp = HSB;
	temp = (temp << 8) | LSB;
	
	if((temp & 0x800) == 0x0000)
	{
		temp >>= 4;
		temp = temp * 10;
	  temp = temp + (LSB & 0x0f) * 0.625;
	}
}





//void ds18b20_show()
//{
//	






//}









































/*****************************************配置ds18b20不带小数点**********************************************************/









//void ds18b20_config_nodot()
//{
//	uchar LSB , HSB;
//	init_ds18b20();
//	Delay_OneWire(10000);
//	
//	Write_DS18B20(0xcc);
//  Write_DS18B20(0x80);
//	Delay_OneWire(10000);
//	
//	init_ds18b20();
//	Delay_OneWire(10000);

//	Write_DS18B20(0xcc);
//  Write_DS18B20(0xbe);
//	Delay_OneWire(10000);
//	
//	LSB = Read_DS18B20();
//	HSB = Read_DS18B20();
//	
//	temp = HSB;
//	temp = (temp << 8) | LSB;
//	temp >>= 4;
//	

//}










