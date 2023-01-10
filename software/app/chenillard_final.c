#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_stdio.h"
#include "sys/alt_irq.h"
#include "alt_types.h"
#include "io.h"
#include "unistd.h"

int main(){

	while(1){
		for (int led = 0; led < 7; led++)
		{
			IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE,1<<led);
			usleep(10000);
        }
        for (int led = 7; led > 0 ; led--)
		{
			IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE,1<<led);
			usleep(10000);
		}
	}
		
	return 0;		
}
