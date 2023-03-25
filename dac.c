#include "head.h"






//uchar temp_at24c02;
//uint temp_pcf8591;
//uint volt = 341;
uchar volt1 = 0;
uchar mode = 0;


/******************************************����PCF8591************************************************/


void output_volt(uchar dat)//ʹ��DAC����̶���ѹ
{
	IIC_Start();
	IIC_SendByte(0x90);
	IIC_WaitAck();
	IIC_SendByte(0x40);//ͨ��0��adda���ŵ�ѹ������������ñ��
	IIC_WaitAck();
	IIC_SendByte(dat);
	IIC_WaitAck();
	IIC_Stop(); 
}


void mode_DAC()
{
	static uchar a;
	if(mode == 0)
	{
		uint t;
		t = count*100;
		if(temp < t)
		{
			output_volt(0);
			volt1 = 0;
			
		}
		else if(temp >= t)
		{
			output_volt(255);
			volt1 = 5;
		}

	}
	else if(mode == 1)
	{
		if(temp <= 2000)
		{
			output_volt(51);
			volt1 = 1;
		}
		else if(temp >= 4000)
		{
			output_volt(204);
			volt1 = 4;
		}
		else if(temp > 2000 && temp < 4000)
		{
			a = 0.15 * (temp / 100) - 2;
			output_volt(a * 255 / 5);
			volt1 = 0;
		}
	
	}
		
}

void mode_key()
{
	key_scon(3);
	if(C1 == 0)
	{
		Delay5ms();
		if(C1 == 0)
		{
			mode ++;
			if(mode == 2)
	    mode = 0;
		}
		while(C1 == 0);
	}
}






//uchar read_pcf8591_dat()//ʹ�û����������͹�������ʱ���õ�������
//{
//	uchar tmp;
//	
//	IIC_Start();
//	IIC_SendByte(0X90);//Ѱַд 
//	IIC_WaitAck();
//	
//	IIC_SendByte(0x43);//ͨ��1������ͨ��3��ѹ 
//	IIC_WaitAck();
//	
//	IIC_Start();
//	IIC_SendByte(0x91);//Ѱַ��
//	IIC_WaitAck();
//	
//	IIC_RecByte();
//	IIC_SendAck(0);
//	tmp = IIC_RecByte(); 
//	IIC_SendAck(1);
//	
//	IIC_Stop();

//	return tmp;

//}











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
			dat = volt1;
		break;
		
		case 3:
			adree = 5;
			dat = 20;
		break;
		
		case 4:
			adree = 6;
			dat = 0;
		break;
		
		case 5:
			adree = 7;
			dat = 0;
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

