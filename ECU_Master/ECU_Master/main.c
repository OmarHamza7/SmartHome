/*
 * ECU_Master.c
 *
 * Created: 6/28/2021 6:09:10 PM
 * Author : omarh
 */ 

#include <avr/io.h>
#include "Std_Types.h"
#include "Utilites.h"
#include "Dio_Int.h"
#include "Dio_Reg.h"
#include "SPI_Int.h"
#include "UART_INTERFACE.h"
#include <util/delay.h>




int main(void)
{
	u8 Sending_data; // data come from the user
	
    SPI_initMaster();   // initialization of SPI communication protocol
	
	UART_Init();	// initialization of UART communication protocol
	
    while (1) 
    {
		Sending_data = UART_RecieveByte();  // accepting data from user to Master ECU
		
		SPI_sendByte(Sending_data);  // Sending data from the Master ECU to the Slave 
		
    }
}

