#include “system.h”
#include “altera_avalon_pio_regs.h"

int main(){
	while(1){
		IOWR_ALTERA_AVALON_PIO_DIRECTION(PIO_BASE,0x01);
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_BASE,0xff);
		return 0;
	}