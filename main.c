#include <c8051F340.h>
#include <stdio.h>
#include "SPI_Defs.h"
#include <stdint.h>
#include <intrins.h>
#include <flash.h>
#include <DAC.h>

extern void SPI_DDS_Write(uint16_t);
extern void delay(uint16_t);
extern void devide(unsigned int);
extern void vivod(unsigned int);


	 uint16_t Reset 	= 0x2100;
   uint16_t DisReset= 0x2000;
	 uint16_t Phase   = 0xC000;
	 uint16_t F0RWL   = 0x4000;					//30Hz LSB
	 uint16_t F0RWM   = 0x4000;					//30Hz MSB
	 uint16_t fc      = 0x0040;
	 uint8_t fl;
	 uint16_t fm;
	 
	 /*Frequencies
   0.1Hz = 0x000A; F0RWL = 0x400A ; F0RWM = 0x4000 ;
   2.0Hz = 0x00C8; F0RWL = 0x40C8 ; F0RWM = 0x4000 ;
	 3.0Hz = 0x012C; F0RWL = 0x412C ; F0RWM = 0x4000 ;
	10.0Hz = 0x03E8; F0RWL = 0x43E8 ; F0RWM = 0x4000 ;
	20.0Hz = 0x07D0; F0RWL = 0x47D0 ; F0RWM = 0x4000 ;
	25.0Hz = 0x09C4; F0RWL = 0x49C4 ; F0RWM = 0x4000 ;
	30.0Hz = 0x0BB8; F0RWL = 0x4BB8 ; F0RWM = 0x4000 ;
	49.5Hz = 0x1356; F0RWL = 0x4356 ; F0RWM = 0x4001 ;
	50.0Hz = 0x1388; F0RWL = 0x4388 ; F0RWM = 0x4001 ;
	50.5Hz = 0x13BA; F0RWL = 0x43BA ; F0RWM = 0x4001 ;
 100.0Hz = 0x2710; F0RWL = 0x4710 ; F0RWM = 0x4002 ;
 210.0Hz = 0x5208; F0RWL = 0x4208 ; F0RWM = 0x4005 ;
*/

 //uint16_t freq[0x000A, 0x00C8, 0x012C, 0x03E8]
	uint8_t freq[2] = {0x55};
 
 
// uint8_t WREN  = 0x06; //Enable write operation
// uint8_t WRDI  = 0x04; 
// uint8_t RDSR  = 0x05;
// uint8_t READ  = 0x03; 
// uint8_t WRITE = 0x02;
// uint8_t ADDR  = 0x01; //Something Addres



	uint8_t byteRead;
	unsigned int  cnt;
	uint16_t c2;
	bit 					BUSY;
	bit           WEL;
	


	

void main(void)
{

	
	Device_Init();	//Init Serial Port	
	devide(0);
	vivod(2); 	
	//P4 = 0x30;
	V0RR_MSRL = 1;
	V0_MSRL   = 0;
	V0_VRFL   = 1;
	TSD_A0H   = 1;	
	SIMI_ONL  = 1; //Enable MUX1 & MUX2

	ROM_CSL = 0;
while(1){	
flash_ext_wr(0x01, freq);
	//delay(1000);
		fl = flash_ext_rd(0x01);}
//	F0RWL |= fl;

	DACD(0x0000);	
	DACOS(0x8000);
	F0RWL += fl;
		
	PG_CSL = 0;
	SPI_DDS_Write(Reset);
	SPI_DDS_Write(F0RWL);
	SPI_DDS_Write(F0RWM);
	SPI_DDS_Write(Phase);
	SPI_DDS_Write(DisReset);
	PG_CSL = 1;	
while(1);
}