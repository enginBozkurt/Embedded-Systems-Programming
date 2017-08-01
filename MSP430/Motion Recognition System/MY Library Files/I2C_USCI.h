#ifdef USE_I2C_USCI

#define MPU6050_ADDRESS	0x68
#define DS1307_ADDRESS	0x68
#define LM92_ADDRESS	0x48
/******************************************************************************\
*					Prototype (Prototype function)    						       *
\******************************************************************************/

void Init_I2C_USCI(unsigned char addr);
void Set_Address(unsigned char addr);
int ByteRead_I2C_USCI(unsigned char address);
unsigned char ByteWrite_I2C_USCI(unsigned char address, unsigned char Data);
unsigned char WordRead_I2C_USCI(unsigned char Addr_Data,unsigned char *Data, unsigned char Length);
/******************************************************************************\
*					Function (Function content)	                           *
\******************************************************************************/


void Init_I2C_USCI(unsigned char addr)
{
	P1SEL = BIT6 + BIT7;                     // Assign I2C pins to USCI_B0
	P1SEL2 = BIT6 + BIT7;                     // Assign I2C pins to USCI_B0
        
        
	UCB0CTL1 |= UCSWRST;                      // Enable SW reset
	UCB0CTL0 = UCMST+UCMODE_3+UCSYNC;         // I2C Master, synchronous mode
  	UCB0CTL1 = UCSSEL_2+UCSWRST;              // Use SMCLK, keep SW reset
	UCB0BR0 = 40;                             // fSCL = SMCLK/10 = ~100kHz
	UCB0BR1 = 0;
	UCB0I2CSA = addr;                         // Set slave address
	UCB0CTL1 &= ~UCSWRST;                     // Clear SW reset, resume operation       
}

void Set_Address(unsigned char addr)
{
  	UCB0CTL1 |= UCSWRST;    
  	UCB0I2CSA = addr;                     		// Set slave address
  	UCB0CTL1 &= ~UCSWRST;                 		// Clear SW reset, resume operation 	
}

int ByteRead_I2C_USCI(unsigned char address)
{ 	
	while (UCB0CTL1 & UCTXSTP);             	// I2C information is not sent
	UCB0CTL1 |= UCTR + UCTXSTT;             	// I2C TX,START

	while (!(IFG2&UCB0TXIFG));					// Sending finished
	UCB0TXBUF = address;                      	// Address saved value Seconds

	while (!(IFG2&UCB0TXIFG));					// Sending finished

	UCB0CTL1 &= ~UCTR;                      // I2C RX
	UCB0CTL1 |= UCTXSTT;                    // I2C RESTART
	IFG2 &= ~UCB0TXIFG;                     // Delete the interrupt flag USCI_B0 TX

	while (UCB0CTL1 & UCTXSTT);             // So long as I2C STT is on
	UCB0CTL1 |= UCTXSTP;                    // Send the STOP bit
	return UCB0RXBUF;
}


//Read 1 take the DS
unsigned char WordRead_I2C_USCI(unsigned char Addr_Data,unsigned char *Data,unsigned char Length)
{ 	
	unsigned char i=0;
	while (UCB0CTL1 & UCTXSTP);             // Loop until I2C STT is sent
	UCB0CTL1 |= UCTR + UCTXSTT;             // I2C TX, start condition

	while (!(IFG2&UCB0TXIFG));
	IFG2 &= ~UCB0TXIFG;                     // Clear USCI_B0 TX int flag
	if(UCB0STAT & UCNACKIFG) return UCB0STAT;	//If the error
	UCB0TXBUF = Addr_Data;                      	// Address saved value Seconds

	while (!(IFG2&UCB0TXIFG));
	if(UCB0STAT & UCNACKIFG) return UCB0STAT;	//If the error

	UCB0CTL1 &= ~UCTR;                      // I2C RX
	UCB0CTL1 |= UCTXSTT;                    // I2C start condition
	IFG2 &= ~UCB0TXIFG;
        for(i=0;i<(Length-1);i++)
        {                                        // Clear USCI_B0 TX int flag
	while (UCB0CTL1 & UCTXSTT);             // Loop until I2C STT is sent
	while (!(IFG2&UCB0RXIFG));
	IFG2 &= ~UCB0TXIFG;                     // Clear USCI_B0 TX int flag
	Data[i] = UCB0RXBUF;
	}
	while (!(IFG2&UCB0RXIFG));
	IFG2 &= ~UCB0TXIFG;                     // Clear USCI_B0 TX int flag
	UCB0CTL1 |= UCTXSTP;                    // I2C stop condition after 1st TX
	Data[Length-1] = UCB0RXBUF;
	IFG2 &= ~UCB0TXIFG;                     // Clear USCI_B0 TX int flag
	return 0;
}

unsigned char ByteWrite_I2C_USCI(unsigned char address, unsigned char data)
{
	while (UCB0CTL1 & UCTXSTP);             // Until the news is complete
	UCB0CTL1 |= UCTR + UCTXSTT;             // I2C TX, sends bit START

	while (!(IFG2&UCB0TXIFG));				// START bit for the complete sends
	if(UCB0STAT & UCNACKIFG) return UCB0STAT;	// if error then exit the function
	UCB0TXBUF = address;					// Send the address of the register to write


	while (!(IFG2&UCB0TXIFG));				// Sending finished
	if(UCB0STAT & UCNACKIFG) return UCB0STAT;	// If you want to escape
	UCB0TXBUF = data;						// Send data

	while (!(IFG2&UCB0TXIFG));				// Sending finished
	if(UCB0STAT & UCNACKIFG) return UCB0STAT;	//If error when exit function
	UCB0CTL1 |= UCTXSTP;                    // sends bit STOP
	IFG2 &= ~UCB0TXIFG;                     // Rub there USCI_B0 TX
	return 0;
}
unsigned int Read_LM92()
{
	unsigned char a;
	while (UCB0CTL1 & UCTXSTP);             // Loop until I2C STT is sent
	UCB0CTL1 |= UCTR + UCTXSTT;             // I2C TX, start condition

	while (!(IFG2&UCB0TXIFG));
	UCB0TXBUF = 0x00;                      	// Address saved value Seconds

	while (!(IFG2&UCB0TXIFG));

	UCB0CTL1 &= ~UCTR;                      // I2C RX
	UCB0CTL1 |= UCTXSTT;                    // I2C start condition
	IFG2 &= ~UCB0TXIFG;                     // Clear USCI_B0 TX int flag

	while (UCB0CTL1 & UCTXSTT);             // Loop until I2C STT is sent
	a = UCB0RXBUF;
	while (UCB0CTL1 & UCTXSTT);             // Loop until I2C STT is sent
	UCB0CTL1 |= UCTXSTP;                    // I2C stop condition after 1st TX
	return ((a<<8)|UCB0RXBUF);	
}

 
#endif




