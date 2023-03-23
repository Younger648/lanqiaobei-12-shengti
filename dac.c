#include "head.h"






//uchar temp_at24c02;
//uint temp_pcf8591;
uint volt = 341;




/******************************************����PCF8591************************************************/

uchar read_pcf8591_dat()
{
	uchar tmp;
	
	IIC_Start();
	IIC_SendByte(0X90); 
	IIC_WaitAck();
	
	IIC_SendByte(0x43);
	IIC_WaitAck();
	
	IIC_Start();
	IIC_SendByte(0x91);
	IIC_WaitAck();
	
	IIC_RecByte();
	IIC_SendAck(0);
	tmp = IIC_RecByte();
	IIC_SendAck(1);
	
	IIC_Stop();

	return tmp;

}











/********************************DAC��ʾ����************************************/
void DAC_show()
{
	static char n;
	n ++;	
	if(n == 6)
	n = 1;
	
//	temp_pcf8591 = read_pcf8591();
	
	switch(n)
	{
		case 1:
			adree = 0;
			dat = 10;
		break;
		
		case 2:
			adree = 5;
			dat = volt / 100;
		break;
		
		case 3:
			adree = 5;
			dat = 20;
		break;
		
		case 4:
			adree = 6;
			dat = volt / 10 % 10;
		break;
		
		case 5:
			adree = 7;
			dat = volt % 10;
		break;

	}
	SMG_config(SMG_adree[adree],SMG_duanma[dat]);


}




































































///*************************������***********************************/



///**********************************����at24c02�������at24c02�����ֲᣩ*************************************************/

//void write_byte_at24c02(uchar adree,uchar dat)//д��ַ������
//{
//	IIC_Start();
//	IIC_SendByte(0XA0); 
//	IIC_WaitAck();

//	IIC_SendByte(adree);
//	IIC_WaitAck();
//	
//	IIC_SendByte(dat);
//	IIC_WaitAck();
//	
//	IIC_Stop();

//}






//unsigned char read_byte_at24c02(uchar adr)//����ַ
//{
//	uchar temp;
//	
//	IIC_Start();
//	IIC_SendByte(0XA0); 
//	IIC_WaitAck();

//	IIC_SendByte(adr);
//	IIC_WaitAck();
//	
//	IIC_Start();
//	IIC_SendByte(0xA1);
//	IIC_WaitAck();
//	
//	temp = IIC_RecByte(); 
//	
//	IIC_Stop();

//	return temp;
//}


///************************at24c02��������********************************/


//void read_at24c02_dat()
//{
//	
//	write_byte_at24c02(0x55,0xA5);//д��ĵ�ַ������
//	Delay10ms();
//	temp_at24c02 = read_byte_at24c02(0x55);//��ȡ�ĵ�ַ
//	
//}




/******************************************����PCF8591************************************************/



//void write_pcf8591(uchar dac)
//{
//	IIC_Start();
//	IIC_SendByte(0X90); 
//	IIC_WaitAck();

//	IIC_SendByte(0x40);
//	IIC_WaitAck();
//	
//	IIC_SendByte(dac);
//	IIC_WaitAck();
//	
//	IIC_Stop();

//}



//uint read_pcf8591(uchar channle_n)
//{
//	
//	IIC_Start();
//	IIC_SendByte(0X90); 
//	IIC_WaitAck();

//	IIC_SendByte(channle_n);
//	IIC_WaitAck();
//	
//	IIC_Start();
//	IIC_SendByte(0x91);
//	IIC_WaitAck();
//	
//	channle_n = IIC_RecByte();
//	IIC_SendAck(0);
//	channle_n = IIC_RecByte();

//	IIC_Stop();

//	return channle_n;

//}




//void pcf8591_config()
//{
//	temp_pcf8591 = read_pcf8591(1);
//	temp_pcf8591 <<= 8;
//	Delay10ms();
//	
//	temp_pcf8591 |= read_pcf8591(3);


//}




//void SMG()
//{

//	SMG_config(SMG_adree[0],SMG_duanma[0]);
//	delaySMG(1000);

//	SMG_config(SMG_adree[1],0xff);
//	delaySMG(1000);

//	SMG_config(SMG_adree[2],SMG_duanma[temp_pcf8591 / 0x1000]);
//	delaySMG(1000);

//	SMG_config(SMG_adree[3],SMG_duanma[temp_pcf8591 / 0x100 % 10]);
//	delaySMG(1000);

//	SMG_config(SMG_adree[4],0xff);
//	delaySMG(1000);

//	SMG_config(SMG_adree[5],SMG_duanma[temp_pcf8591 / 0x10 % 10]);
//	delaySMG(1000);

//	SMG_config(SMG_adree[6],SMG_duanma[temp_pcf8591 % 0x10]);
//	delaySMG(1000);

//	SMG_config(SMG_adree[7],0xff);
//	delaySMG(1000);


//	
//	SMG_config_all();
//}

