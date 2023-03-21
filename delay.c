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