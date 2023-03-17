#include <stdio.h>
#include <c8051F340.h>
#include "SPI_Defs.h"

// P4      - 0xC7
// TS_T0H  - A0 - F4^3 MX1
// TS_T1H  - A1 - F4^4 MX1
// TSD_D0H - A0 - P4^5 MX2
// TSD_D1H - A1 - P4^6 MX2
// TSD_D2H - A2 - P4^7 MX2


void devide(unsigned int i) //devide by n=2^i, i=0 to 7
	{
		 if (i == 0)
			 { 
				 P4 &= 0x1F;	//000X XXXX
			 }
		 if (i == 1)    
			 {
				 P4 |= 0x20;	//XX1X XXXX
				 P4 &= 0x3F;	//001X XXXX
			 }
		 if (i == 2) 
			 {
				 P4 |= 0x40;	//X1XX XXXX
				 P4 &= 0x5F;	//010X XXXX
			 }
		 if (i == 3)
			 {			 
				 P4 |= 0x60;	//X11X XXXX
				 P4 &= 0x7F;	//011X XXXX
			 }
		 if (i == 4) 
			 {
				 P4 |= 0x80;	//1XXX XXXX
				 P4 &= 0x9F;	//100X XXXX
			 }
		 if (i == 5) 
			 {
				 P4 |= 0xA0;	//1X1X XXXX
				 P4 &= 0xBF;	//101X XXXX
			 }
		 if (i == 6) 
			 {
				 P4 |= 0xC0;	//11XX XXXX	
				 P4 &= 0xDF;	//110X XXXX
			 }
		 if (i == 7) 
			 {
				 P4 |= 0xE0;	//111X XXXX
			 }
		}
	
	void vivod(unsigned int j) // choose n-chanel, n=2^j, j=0,1,2,3
		{
			if (j == 0) 
				{
					P4 &= 0xE7;	//XXX00XXX
				}
			if (j == 1)
				{			
					P4 |= 0x08; //XXXX1XXX
					P4 &= 0xEF;	//XXX01XXX
				}
			if (j == 2)
				{			
					P4 |= 0x10;	//XXX1XXXX
					P4 &= 0xF7; //XXX10XXX
				}
			if (j == 3)
				{			
					P4 |= 0x18; //XXX11XXX
				}
		}
			
	
	
	
	
	
	
	
	
	
