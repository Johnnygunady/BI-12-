#include <c8051F340.h>
#include "SPI_Defs.h"
#include <stdint.h>
 

 extern void delay(unsigned char);		


	void SPI_DDS_Write(uint16_t SPI_byte)
		
	{
		unsigned char SPI_count;
		for (SPI_count = 0; SPI_count < 16; SPI_count++)
			{
				SCLK = 1;
				//SDIH = 0;
				//delay(100);				
				SDIH = (SPI_byte & 0x8000);				
				//if (SPI_byte & 0x8000) SDIH = 1; 					
				//else SDIH = 0; 				
			  //delay(2);				
				SPI_byte = (SPI_byte << 1);				
				//delay(2);
				SCLK = 0;
				//SDIH = 1;
		 }		
	}