#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_stdio.h"
#include "alt_types.h"
#include "io.h"
#include "unistd.h"

int main(){

	int LedAddr = 0x01;
	IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, LedAddr);
	
	while(1){
		while (LedAddr != 0x80)
		{
			LedAddr = LedAddr << 1; // Décalage led par led
			IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE,LedAddr);
			usleep(10000);
        }
        while (LedAddr != 0x01)
		{
			LedAddr = LedAddr >> 1;
			IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE,LedAddr);
			usleep(10000);
		}
	}
		
	return 0;		
}
