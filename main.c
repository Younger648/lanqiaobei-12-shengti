#include "head.h"




void main()
{
	
	InitTimer0();
	
	
	while(1)
	{
		
		Read_DS18b20_config();
    menu_key();
		refer_key();
			
		
	}

}