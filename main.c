#include "head.h"




void main()
{
	
	InitTimer0();
//	read_at24c02_dat();
//	write_pcf8591(127);
	
	while(1)
	{
//		volt = (float)read_pcf8591_dat() / 255.0f * 500.0f;
//		pcf8591_config();
//		read_pcf8591_dat();

		Read_DS18b20_config();
		mode_DAC();
		mode_key();
    menu_key();
		refer_key();


		
	}

}