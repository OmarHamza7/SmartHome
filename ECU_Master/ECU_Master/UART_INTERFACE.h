


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_



#define UDR	*((volatile u8*)0x2C)	
#define UDRRL *((volatile u8*)0x29)
#define UCSRA *((volatile u8*)0x2B)
#define UCSRB *((volatile u8*)0x2A)
#define UCSRC  *((volatile u8*)0x40)
#define UDRRH  *((volatile u8*)0x40)


void UART_Init(void);
void UART_SendByte(u8 Byte);
u8 UART_RecieveByte(void);

#endif 