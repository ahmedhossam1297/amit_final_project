/*
 * slave.c
 *
 * Created: 3/18/2021 3:31:41 PM
 * Author : ahmed
 */ 



#include "LED.h"
#include "SPI.h"

int main(void)
{
	char data1 = 0;
	LED0_Init();
	LED1_Init();
	LED2_Init();

	SPI_Init();
	LED0_OFF();	
	LED1_OFF();
	LED2_OFF();
	SPI_SlaveSelect(0);

	
	while (1) /*Super loop - Infinite loop*/
	{
		data1 = SPI_Receive();
		if (data1 == 'A')
		{
			LED0_TGL();
			data1 = 0;
		}
		else if (data1 == 'B')
		{
			LED1_TGL();
			data1 = 0;
		}
		else if (data1 == 'C')
		{
			LED2_TGL();
			data1 = 0;
		}

	}
}

