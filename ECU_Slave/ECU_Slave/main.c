/*
 * ECU_Slave.c
 *
 * Created: 6/28/2021 6:38:29 PM
 * Author : omarh
 */ 

#include <avr/io.h>
#include <avr/io.h>
#include "Std_Types.h"
#include "Utilites.h"
#include "Dio_Int.h"
#include "Dio_Reg.h"
#include "SPI_Int.h"
#include <util/delay.h>


int main(void)
{
	
	// setting output Leds
		SPI_initSlave();
		Dio_SetPinDirection(GroupA,PIN0,OUTPUT);
		Dio_SetPinDirection(GroupA,PIN1,OUTPUT);
	    Dio_SetPinDirection(GroupA,PIN2,OUTPUT);	
		
   u8 Received_Date ;
   
   	void Tog_led1()  // if led 1 off turn it on and vice verse 
   	{
	   	
	   	TOG_BIT(PORTA,0);
   	}
   	
   	void Tog_led2()  // if led 2 off turn it on and vice verse 
   	{
	   		
	   TOG_BIT(PORTA,1);	
   	}
   
   
   	void Tog_led3()   // if led 3 off turn it on and vice verse 
   	{
	   	
	   	TOG_BIT(PORTA,2);
   	}
   	
   
    while (1) 
    {
		Received_Date=SPI_recieveByte();  // data coming from Master ECU to the Slave
		
		
		// classifying the received data and making the action upon the client demands 
		
			if (Received_Date=='a')
			Tog_led1();
			

			if (Received_Date=='b')
			Tog_led2();
			
			
			if (Received_Date=='c')
			Tog_led3();
					
    }
}

