#ifndef __DAC_H_
#define __DAC_H_

void DAC_show();
void SMG();
void write_byte_at24c02(uchar adree,uchar dat);
unsigned char read_byte_at24c02(uchar adree);
extern uchar temp_0;




#endif

