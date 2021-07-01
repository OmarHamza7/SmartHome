#include "Utilites.h"
#include "STD_TYPES.h"
#include "UART_INTERFACE.h"



void UART_Init(void)
{
	SET_BIT(UCSRB,3);
	SET_BIT(UCSRB,4);
	//Enable RX And Tx
	SET_BIT(UCSRC,7);
	SET_BIT(UCSRC,1);
	SET_BIT(UCSRC,2);
	//Setting the Frame formate: 8bits, no parity, one stop bits.

	UDRRH=0;
	UDRRL=103;

	//Setting the baud rate to 9600
	
}
void UART_SendByte(u8 Byte)
{
	while(GET_BIT(UCSRA,5)==0);
	//wait until data register is empty.

	UDR=Byte;
	//Put the data in the transmit register
	
}
u8 UART_RecieveByte(void)

{	while(GET_BIT(UCSRA,7)==0);
	//wait until the recieve is compelete

return UDR;
	//return the recieved data
	
}