#ifndef __CONFIG_H_
#define __CONFIG_H_



#define DELAY_TIME 5
#define SlaveAddrW 0xA0
#define SlaveAddrR 0xA1
#define uchar unsigned char
#define uint unsigned int
	



//总线引脚定义
sbit SDA = P2^1;  /* 数据线 */
sbit SCL = P2^0;  /* 时钟线 */
sbit DQ = P1^4;  //单总线接口



#endif