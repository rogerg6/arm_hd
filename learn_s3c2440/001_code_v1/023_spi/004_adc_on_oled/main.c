#include <stdio.h>
#include "serial.h"
#include "i2c.h"
#include "spi.h"
#include "oled.h"
#include "spi_flash.h"


unsigned char at24cxx_read(unsigned char address);
void at24cxx_write(unsigned char address, unsigned char data);


void delay(int val)
{
	while (val--);
}

int main()
{
    char c;
    char str[200];
    int i;
	int address;
	int data;
	unsigned int mid, pid;
    
    uart0_init();   // 波特率115200，8N1(8个数据位，无校验位，1个停止位)
    

    SPIInit();
    OLEDInit();
    OLEDPrint(0, 0, "www.baidu.com");

    SPIFlashReadID(&mid, &pid);
    sprintf(str, "MID:%2x, PID:%2x", mid, pid);
    OLEDPrint(2, 0, str);

	/* 璇诲啓spi flash 鎿嶄綔 */
	SPIFlashInit();
	SPIFlashEraseForData(0);
	SPIFlashPageProgram(0, "SPI Flash is ok!", 17);
    SPIFlashReadData(0, str, 17);
    OLEDPrint(4, 0, str);

	Test_Adc();	/* 灏咥DC鐨勬暟鎹墦鍗板湪oled涓� */

    while (1);
    return 0;
}
