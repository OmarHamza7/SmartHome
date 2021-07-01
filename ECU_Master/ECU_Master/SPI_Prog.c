/*
 * SPI_Prog.c
 *
 *  Created on: Dec 5, 2020
 *      Author: Mohamed
 */

#include "Std_Types.h"
#include "Utilites.h"
#include "SPI_Int.h"
#include "Dio_Reg.h"
#include "Dio_Int.h"

void SPI_initMaster(void)
{
	//Configure SPI PINS
	Dio_SetPinDirection(GroupB, PIN4, OUTPUT);//SS Pin output.
	Dio_SetPinDirection(GroupB, PIN5, OUTPUT);//MOSI Pin output.
	Dio_SetPinDirection(GroupB, PIN6, INPUT);//MISO Pin input.
	Dio_SetPinDirection(GroupB, PIN7, OUTPUT);//SCK Pin output.
	//Enable SPI, Master mode, Set Clock rate to fso/4
	SET_BIT(SPCR, 4);
	SET_BIT(SPCR, 6);

}
void SPI_initSlave(void)
{
	//Configure SPI PINS
	Dio_SetPinDirection(GroupB, PIN4, INPUT);//SS Pin input.
	Dio_SetPinDirection(GroupB, PIN5, INPUT);//MOSI Pin input.
	Dio_SetPinDirection(GroupB, PIN6, OUTPUT);//MISO Pin output.
	Dio_SetPinDirection(GroupB, PIN7, INPUT);//SCK Pin input.
	//Enable SPI, Slave mode, Set Clock rate to fso/4
	SET_BIT(SPCR, 6);


}
void SPI_sendByte(u8 data)
{
	//Dio_SetPinValue(GroupB, PIN4, HIGH);//for any other slave
	SPDR = data; //send data by SPI
	while(GET_BIT(SPSR, 7)==0); //wait until SPI interrupt flag=1 (data is sent correctly)
}
u8 SPI_recieveByte(void)
{
	while(GET_BIT(SPSR, 7)==0); //wait until SPI interrupt flag=1(data is receive correctly)
	return SPDR; //return the received byte from SPI data register
}
