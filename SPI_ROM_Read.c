#include "SPI_Defs.h"
#include <stdint.h>
#include <intrins.h>

extern void delay(uint16_t);



	uint8_t byteRead;
	uint16_t Cmd;
	unsigned int  cnt;
	uint16_t c2;
	bit 	Busy;

	void shift_out8(uint8_t c1)
		{
			for (cnt = 0; cnt < 8; cnt++)
				{
					SCLK = 0;
					delay(20);
					c1 = _crol_(c1, 1); //Cyclic permutation
					SIR = c1 & 0x1;
					delay(2);
					SCLK = 1;
					delay(20);
				}
		}
	
	void shift_out16(unsigned int i1)
		{
			for (cnt = 0; cnt < 16; cnt++)
				{
					SCLKR = 0;
					delay(20);
					i1 = _irol_(i1, 1);
					SIR = i1 & 0x1;
					delay(2);
					SCLKR = 1;
					delay(20);
				}
		}
		
	uint16_t shift_in8(void)
		{
			uint8_t t1;
			t1 = 0x00;
			for (cnt = 0; cnt < 8; cnt++)
				{	
					SCLK = 0;
					delay(10000);
					t1 = t1<<1;
					t1 |= SOR;
					SCLK = 1;
					delay(10);
				}
			return t1;
		}
		
	uint16_t readByte(void)
		{
			ROM_CSL = 1;
			delay(1);
			ROM_CSL = 0;
			//Cmd = READ;
			//Addr = ADDR;
			shift_out8(READ);
			shift_out8(ADDR);
			byteRead = shift_in8();
			delay(20);
			ROM_CSL = 1;
			return byteRead;
		}
		
	bit readStatus(void)
		{
			bit stat;
			uint8_t ctmp;
			ROM_CSL = 1;
			ROM_CSL = 0;
			//Cmd = RDSR;
			shift_out8(RDSR);
			ctmp = shift_in8();
			ROM_CSL = 1;
			stat = ctmp & 0x01;
			return stat;
		}
		
	void writeByte(uint16_t c1)
		{
			//ROM_CSL = 1;
			//delay(2);
			ROM_CSL = 0;
			//Cmd = WREN;
			shift_out8(WREN);
			//ROM_CSL = 1;
			//delay(2);
			//ROM_CSL = 0;
			//Cmd = WRITE;
			//Addr = ADDR;
			shift_out8(WRITE);
			shift_out8(ADDR);
			shift_out8(c1);
			ROM_CSL = 1;
		}