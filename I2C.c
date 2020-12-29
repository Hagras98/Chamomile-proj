/*
 * I2C.c
 *
 * Created: 10/11/2020 3:37:52 AM
 *  Author: AbdEl-Rahman
 */ 
#include "I2C.h"

void I2C_init(choose_prescaler pre)
{
	u8 preS = pre;
	*TWSR = preS;
	*TWBR = (u8)((F_CPU/SCL_F)-16)/(2*preS);  // generate TWBR value for desired SCL_F vlaue
	
}

void MasterT_start(void)
{
	*TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN); // Send Start Bit and enable Twin-Wire
	while(!(*TWCR&(1<<TWINT)));   
	// wait till process is finished
	//while ((*TWSR & 0xF8) != start) ;        // Check value of TWI Status Register if a start condition has been sent . Mask pre-scaler bits.
	/**TWDR = SLA_W;                           // load slave address + R/W bit into TWDR Reg
	*TWCR = (1<<TWINT) | (1<<TWEN);          // Clear TWINT bit, data is sent immediately after TWINT is cleared 
	while (!(*TWCR & (1<<TWINT)));           // wait till process is finished 
	while ((*TWSR & 0xF8) != 0x18) ;         // SLA+W has been transmitted, ACK has been received
*/
}
void MasterR_start(void)
{
	*TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN); // Send Start Bit and enable Twin-Wire
	while(!(*TWCR&(1<<TWINT)));   
	// wait till process is finished
	//while ((*TWSR & 0xF8) != start) ;        // Check value of TWI Status Register if a start condition has been sent . Mask pre-scaler bits.
	/**TWDR = SLA_W;                           // load slave address + R/W bit into TWDR Reg
	*TWCR = (1<<TWINT) | (1<<TWEN);          // Clear TWINT bit, data is sent immediately after TWINT is cleared 
	while (!(*TWCR & (1<<TWINT)));           // wait till process is finished 
	while ((*TWSR & 0xF8) != 0x18) ;         // SLA+W has been transmitted, ACK has been received
*/
}

void MasterT_send(u8 data)
{
	*TWDR = data;                            // load data into TWDR , TWINT is 1 
	*TWCR = (1<<TWINT) | (1<<TWEN);          // Clear TWINT bit
	while (!(*TWCR & (1<<TWINT)));           // wait till precess is finished
	//while ((*TWSR & 0xF8) != 0x28) ;         // Data byte has been transmitted, ACK has been received
}

u8 MasterNak_recieve()
{
	u8 data;
	*TWCR = (1<<TWINT)|(1<<TWEN);          // Clear TWINT bit
	while (!(*TWCR & (1<<TWINT)));  
	data= *TWDR;  
	return data;        // wait till precess is finished
	//while ((*TWSR & 0xF8) != 0x28) ;         // Data byte has been transmitted, ACK has been received
}

u8 MasterAck_recieve()
{
	u8 data;
	*TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);          // Clear TWINT bit
	while (!(*TWCR & (1<<TWINT)));
	data= *TWDR;
	return data;        // wait till precess is finished
	//while ((*TWSR & 0xF8) != 0x28) ;         // Data byte has been transmitted, ACK has been received
}

void MasterT_stop(void)
{
	*TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);  // Cleat TWINT bit, Send stop bit
}

void SlaveR_init(u8 address)
{
	*TWAR = address;                                // set slave address and deny general call, LSB =0
	  while(*TWCR&(1<<TWSTO));
}

u8 SlaveR_recieve(void)
{
	*TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);         // enable sending ACK and TWI
	while (!(*TWCR & (1<<TWINT)));                  // wait till process is finished
	while ((*TWSR & 0xF8) != 0x60) ;                // Own SLA+W has been received ACK has been returned
	*TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);         // enable sending ACK and TWI
	while (!(*TWCR & (1<<TWINT)));                  // wait till process is finished
	while ((*TWSR & 0xF8) != 0x80) ;                //Previously addressed with own SLA+W, data has been received, ACK has been returned
	return *TWDR;                                   // return received data
}
