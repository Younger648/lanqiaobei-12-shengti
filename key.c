#include "head.h"


void key_scon(uchar n)
{
	switch(n)
	{
		case 1:
			R1 = 0;
		  R2 = R3 = R4 = 1;
			C1 = C2 = C3 = C4 = 1;
		break;
	
		case 2:
			R2 = 0;
		  R1 = R3 = R4 = 1;
			C1 = C2 = C3 = C4 = 1;
		break;
	
		case 3:
			R3 = 0;
		  R1 = R2 = R4 = 1;
			C1 = C2 = C3 = C4 = 1;
		break;
	
		case 4:
			R4 = 0;
		  R1 = R2 = R3 = 1;
			C1 = C2 = C3 = C4 = 1;
		break;
	}

}





