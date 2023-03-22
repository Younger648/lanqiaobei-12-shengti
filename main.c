#include "head.h"




void main()
{
	
	InitTimer0();
	read_at24c02_dat();

	
	while(1)
	{
		
		Read_DS18b20_config();
    menu_key();
		refer_key();
			

		
	}

}