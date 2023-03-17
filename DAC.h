#include <SPI_Defs.h>
#include <stdint.h>



	void SPI_DAC_Write(uint16_t SPI_2byte)
		
	{
		uint16_t SPI_count;
		for (SPI_count = 0; SPI_count < 16; SPI_count++)
			{
				SCLK = 0;			
				SDIH = (SPI_2byte & 0x8000);							
				SPI_2byte = (SPI_2byte << 1);				
				SCLK = 1;
		 }		
	}
	
 void DACD(uint16_t pr)
	{
		DACD_CSL = 0;
		SPI_DAC_Write(pr);
		DACD_CSL = 1;
  } 
	
	void DACOS(uint16_t pr)
	{
		DACOS_CSL = 0;
		SPI_DAC_Write(pr);
		DACOS_CSL = 1;
  } 
	