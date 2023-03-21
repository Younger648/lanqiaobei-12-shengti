#ifndef __DS18B20_H_
#define __DS18B20_H_


extern uint temp;
extern uchar count;
extern uchar count_0;
extern uchar adree;
extern uchar dat;


void Read_DS18b20_config();
void ds18b20_show();
void ds18b20_refer_show();
void refer_key();


#endif

