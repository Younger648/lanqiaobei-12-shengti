#include "head.h"



void HC573_config(char n)
{
	switch(n)
	{
		case 4:
			P2 = (P2 & 0xff) | 0x80;
		break;
		
		case 5:
			P2 = (P2 & 0xff) | 0xa0;
		break;
		
		case 6:
			P2 = (P2 & 0xff) | 0xc0;
		break;
	
		case 7:
			P2 = (P2 & 0xff) | 0xe0;
	  break;
	
	
	
	}


}