#ifndef __CONFIG_H_
#define __CONFIG_H_



#define DELAY_TIME 5
#define SlaveAddrW 0xA0
#define SlaveAddrR 0xA1
#define uchar unsigned char
#define uint unsigned int
	



//�������Ŷ���
sbit SDA = P2^1;  /* ������ */
sbit SCL = P2^0;  /* ʱ���� */
sbit DQ = P1^4;  //�����߽ӿ�



#endif