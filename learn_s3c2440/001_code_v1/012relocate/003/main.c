


# include "init.h"
# include "uart.h"

char g_A = 'A'; 
unsigned char g_a = 'a';
int a = 0;
int b;

int main(void)
{
	
	uart_init();
	
	while (1)
	{
		putchar(g_A);
		g_A++;    
		putchar(g_a);
		g_a++;
		delay(1000000);
	}

	return 0;
}
