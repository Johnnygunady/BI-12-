#include <c8051F340.h>
#include <stdint.h>
#ifndef SPI_Defs
#define SPI_Defs

sbit SDIH    = P2^0; //PG Data Input
sbit SCLK    = P2^1; //PG Serial Clock
sbit PG_CSL  = P3^0; //PG Chip Select 
sbit SOR     = P1^7; //ROM Serial Output
sbit SCLKR   = P1^5; //ROM Serial Clock
sbit ROM_CSL = P1^6; //ROM Chip Select
sbit SIR     = P1^4; //ROM Serial Input
sbit V0_VRFL = P3^5;
sbit V0DIRL  = P2^2;
sbit V0INVL  = P2^3;
sbit SIMI_ONL = P1^3;
sbit V0RR_MSRL = P2^5;
sbit V0_MSRL   = P2^4;
sbit TSD_A0H   = P3^7;
sbit DACOS_CSL = P3^2;
sbit DACD_CSL  = P3^1;

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

/*uint8_t WREN = 0x06;
uint8_t WRDI = 0x04;
uint8_t RDSR = 0x05;
uint8_t READ = 0x03;
uint8_t WRITE= 0x02;
uint8_t ADDR = 0x02; //Something Addres*/

#endif