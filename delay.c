#include "head.h"


void Delay10us()		//@12.000MHz
{
	unsigned char i;

	_nop_();
	_nop_();
	i = 27;
	while (--i);
}

//单总线延时函数
void Delay_OneWire(uint t)  //STC89C52RC
{
	while(t--);
}


void delaySMG(uint l)
 {
  while(l--);
 }

 
 
void Delay5ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 54;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}






void Delay5us()		//@12.000MHz,iic初始化延时函数
{
	unsigned char i;

	_nop_();
	_nop_();
	i = 12;
	while (--i);
}




void Delay10ms()		//@12.000MHz    at24c02
{
	unsigned char i, j;

	i = 117;
	j = 184;
	do
	{
		while (--j);
	} while (--i);
}

