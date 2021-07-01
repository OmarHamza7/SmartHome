/*
 * SPI_Int.h
 *
 *  Created on: Dec 5, 2020
 *      Author: Mohamed
 */

#ifndef SPI_INT_H_
#define SPI_INT_H_

#define SPCR *((volatile u8*) 0x2D)
#define SPSR *((volatile u8*) 0x2E)
#define SPDR *((volatile u8*) 0x2F)

void SPI_initMaster(void);
void SPI_initSlave(void);
void SPI_sendByte(u8 data);
u8 SPI_recieveByte(void);

#endif /* SPI_INT_H_ */
