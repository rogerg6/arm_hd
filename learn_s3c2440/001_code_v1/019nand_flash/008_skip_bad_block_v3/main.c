


# include "init.h"
# include "uart.h"
# include "s3c2440_soc.h"
# include "nand_flash.h"

int main(void)
{
	
	  interrupt_ctrl_init();
	  key_init();
	  led_init();
	  //timer0_init();

	//nor_flash_test();
	nand_flash_test();

	return 0;
}





/*
ÔËÐÐ½á¹û£º


*/





