#include <SPI_defs.h>
#include <intrins.h>
#include <stdint.h>

#define WREN  0x06 // Write Enable
#define WRDI  0x04 // Write Disable
#define WRITE 0x02 // Write
#define READ  0x03 // Read

extern void delay(uint8_t);

/*sbit SOR     = P1^7; //ROM Serial Output
	sbit SCLKR   = P1^5; //ROM Serial Clock
	sbit ROM_CSL = P1^6; //ROM Chip Select
	sbit SIR     = P1^4; //ROM Serial Input*/


//write to FLASH - byte 



void nop_delay(uint16_t Parametr)
{
	uint16_t ix;
//	uint8_t EaTmp_0;
 // EaTmp_0 = EA;
	//EA = 0;
	for(ix = 0; ix < Parametr; ix++);//{
	//_nop_();
	//}
//	EA = EaTmp_0;
}

void flash_ext_byte_wr(uint8_t Byte)
{
uint8_t ix;
for (ix = 0; ix < 8; ix++)
	{
   Byte <<= 1;
   SIR = CY; 
   nop_delay(1);
	 SCLKR = 1;
	 nop_delay(1);
	 SCLKR = 0;
   nop_delay(1);		
	}
}

//write to FLASH - array

void flash_ext_wr(
	uint8_t AddressTo,                // Initial adrres FLASH, 
	uint8_t *AddressFrom             // Initial adress XDATA
	//uint8_t Quantity                  // Quantity writing bytes
)
{
  uint8_t ix;
  uint8_t Byte_Tmp;
	
	ROM_CSL = 1;
	SCLKR   = 0;
	
	//for(ix = 0; ix < Quantity; ix++) 
//	{
		//Step-1 .................
		ROM_CSL = 0;
		flash_ext_byte_wr(WREN);  //Write Enable 0x06
		//ROM_CSL = 1;
		
		//Step-2 .................
		//ROM_CSL = 0;
		flash_ext_byte_wr(WRITE);       //0x02
		flash_ext_byte_wr(AddressTo);   //0x00
		Byte_Tmp = *AddressFrom;
		flash_ext_byte_wr(*AddressFrom++);
		//ROM_CSL = 1;
		
		//Step-3 .................
		//ROM_CSL = 0;
		flash_ext_byte_wr(WRDI);        //0x04
		ROM_CSL = 1;
		nop_delay(4000);
		
//	}
}

uint8_t flash_ext_rd(
	uint8_t AddressFrom
	)
{
	uint8_t fl;
	ROM_CSL = 0;
	flash_ext_byte_wr(READ);
	flash_ext_byte_wr(AddressFrom);
	fl = SOR;
	ROM_CSL = 1;
	nop_delay(1000);
	return(fl);
	
}
	

