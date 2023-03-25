#ifndef __DAC_H_
#define __DAC_H_


//uchar read_pcf8591_dat();
void output_volt(uchar dat);
void DAC_show();
void mode_DAC();
void mode_key();
//void SMG();
//void write_byte_at24c02(uchar adree,uchar dat);
//unsigned char read_byte_at24c02(uchar adree);
//void pcf8591_config();

extern uchar mode;


//extern uint temp_pcf8591;
//extern uchar temp_at24c02;
//extern uint volt;
extern uchar get_volt;

#endif

