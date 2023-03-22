#include "head.h"






uchar temp_0;





/**********************************配置at24c02，（详见at24c02数据手册）*************************************************/

void write_byte_at24c02(uchar adree,uchar dat)//写地址和数据
{
	IIC_Start();
	IIC_SendByte(0XA0); 
	IIC_WaitAck();

	IIC_SendByte(adree);
	IIC_WaitAck();
	
	IIC_SendByte(dat);
	IIC_WaitAck();
	
	IIC_Stop();

}






unsigned char read_byte_at24c02(uchar adr)//读地址
{
	uchar temp;
	
	IIC_Start();
	IIC_SendByte(0XA0); 
	IIC_WaitAck();

	IIC_SendByte(adr);
	IIC_WaitAck();
	
	IIC_Start();
	IIC_SendByte(0xA1);
	IIC_WaitAck();
	
	temp = IIC_RecByte(); 
	
	IIC_Stop();

	return temp;
}



/************************at24c02发送数据********************************/


void read_at24c02_dat()
{
	
	write_byte_at24c02(0x55,0xA5);
	Delay10ms();
	temp_0 = read_byte_at24c02(0x55);
	
}





/*********************************DAC数据读出函数*************************************/

//void DAC_config(uchar chn)
//{
//	uchar val;
//	IIC_Start();
//	if()








//}




/********************************DAC显示函数************************************/
void DAC_show()
{
	static char n;
	n ++;	
	if(n == 3)
	n = 1;
	
	switch(n)
	{
		case 1:
			adree = 0;
			dat = temp_0 / 0x10;
		break;
		
		case 2:
			adree = 1;
			dat = temp_0 % 0x10;
		break;

	}
	SMG_config(SMG_adree[adree],SMG_duanma[dat]);


}




































































/*************************测试用***********************************/



void SMG()
{

	SMG_config(SMG_adree[0],SMG_duanma[0]);
	delaySMG(1000);

	SMG_config(SMG_adree[1],0xff);
	delaySMG(1000);

	SMG_config(SMG_adree[2],SMG_duanma[SMG_duanma[temp_0 / 0x10]]);
	delaySMG(1000);

	SMG_config(SMG_adree[3],SMG_duanma[SMG_duanma[temp_0 % 0x10]]);
	delaySMG(1000);

	SMG_config(SMG_adree[4],0xff);
	delaySMG(1000);

	SMG_config(SMG_adree[5],0xff);
	delaySMG(1000);

	SMG_config(SMG_adree[6],0xff);
	delaySMG(1000);

	SMG_config(SMG_adree[7],0xff);
	delaySMG(1000);


	
	SMG_config_all();
}