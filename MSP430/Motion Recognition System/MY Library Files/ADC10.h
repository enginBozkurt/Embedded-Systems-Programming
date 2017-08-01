#ifndef ADC10_H_
#define ADC10_H_

volatile unsigned char PORT_ADC=(BIT0);
//Chu y thach anh ngoai khong mo phong bang protues duoc
typedef enum { 	ON2_5V,		//Dien ap tham chieu noi 2.5V
		ON1_5V,		//Dien ap tham chieu noi 2.5V
		VCC,//Dien ap nguon,luu y phai loc nhieu tot cho nguon neu dung che do nay
		VeREF} Vref;



volatile unsigned char Reading_channel=0;

unsigned int ADC10_Read_Channel(unsigned char channel);	//1->16
//Che do chuyen doi lien tuc
// Neu sequence = 0 thi ghi 1 gia tri cua channel vao *pointer
// Neu sequence = 1 thi cac gia tri ghi vao cua cac channel tu channel ->A0
// Quet tu channel A(channel) ->A0 , che 1 chuyen giao 1 block
// Chu y la A(channel) dc ghi vao pointer[0]
void ADC10_DTC(unsigned char channel,unsigned int pointer[], unsigned char sequence);


void ADC10_Init(V_referans)
{
	// Set ENC=0 thi moi chinh sua duoc cac thanh ghi
	ADC10CTL0 &=~ ENC;
	// Cho cho ADC ranh
	while(ADC10CTL1 & ADC10BUSY);
	//ADC10 Control Register 0

	//Noi cac chan voi cong tuong tu
	ADC10AE0=PORT_ADC;
	// Thoi gian lay mau 64xADC10CLK,200ksps,
	ADC10CTL0 = ADC10SHT_3 + ADC10ON;
	
	switch(V_referans)
	{
		case(ON2_5V):
		{
			ADC10CTL0 |= SREF_1 + REFON + REF2_5V ;
			break;
		}
		case(ON1_5V):
		{
			ADC10CTL0|= SREF_1 + REFON ;
			break;
		}
		case(VCC):
		{
			ADC10CTL0|= SREF_0;
			break;
		}
		case(VeREF):
		{
			ADC10CTL0|= SREF_7 + REFOUT ;
			break;
		}
	}
	
	//Bien doi tung kenh
	ADC10CTL1  = CONSEQ_0;
        //Tat DTC
	ADC10DTC0=0;	
	ADC10DTC1=0;
	// Cho phep chuyen doi
	ADC10CTL0 |= ENC;
	// Bat dau chuyen doi
	ADC10CTL0 |= ADC10SC;
}

unsigned int ADC10_Read_Channel(unsigned char channel)
{
	//Neu kenh doc khac lan cuoi cung doc
	if(channel != Reading_channel)
	{
		//Disable chuyen doi
		ADC10CTL0&=~( ADC10SC + ENC );
                
		//Thay doi kenh can chuyen doi-chi dung trong che do don kenh
		ADC10CTL1 &= 0x0FFF;
		ADC10CTL1|=(channel<<12);
		Reading_channel = channel;

                //Tat co ngat
		ADC10CTL0 &= ~ADC10IFG;		
		ADC10CTL0|= (ADC10SC + ENC);
                
		//__bis_SR_register(CPUOFF + GIE); // Ngat CPU cho den khi chuyen doi xong
		while(!(ADC10CTL0 & ADC10IFG));		
		return ADC10MEM;		//Lay gia tri ADC
	}
	else	//Neu channel giong channel da doc lan truoc
	{
		ADC10CTL0 &= ~ADC10IFG;		//Tat co ngat
		ADC10CTL0|= (ADC10SC + ENC);	//Cho phep chuyen doi
		//__bis_SR_register(CPUOFF  + GIE); // Ngat CPU cho den khi chuyen doi xong
		while(!(ADC10CTL0 & ADC10IFG));		//Cho den khi chuyen doi xong
		return ADC10MEM;		//Lay gia tri ADC
	}
}

// Neu sequence = 0 thi ghi 1 gia tri cua channel vao *pointer
// Neu sequence = 1 thi cac gia tri ghi vao cua cac channel tu channel ->A0
// Quet tu channel A(channel) ->A0 , che 1 chuyen giao 1 block
// Chu y la A(channel) dc ghi vao pointer[0]

void ADC10_DTC(unsigned char channel,unsigned int pointer[], unsigned char  sequence)
{
	//Giam dien tieu thu ,dam bao an toan
	P1DIR &=~PORT_ADC;		//Chon nhap du lieu
	P1OUT &=~PORT_ADC;     	//Input
	P1REN &=~PORT_ADC;		//Khong co dien tro keo len

	// Set ENC=0 thi moi chinh sua duoc cac thanh ghi
	ADC10CTL0 &= ~ENC;
	// Cho cho ADC ranh
	while(ADC10CTL1 & ADC10BUSY);
	ADC10AE0=PORT_ADC;
	// Chon che do lay mau lap lai
	ADC10DTC0 = ADC10CT;
	// Chon so lan ghi vao trong 1 vong quet
	// Neu sequence = 0 thi cac gia tri ghi vao cua cung 1 channel
	// Neu sequence = 1 thi cac gia tri ghi vao cua cac channel tu channel ->A0
	ADC10DTC1 = sequence ? (channel+1) : 1;
	// Dia chi bien truyen qua DTC
	ADC10SA = ((unsigned int)pointer);
	// Thoi gian lay mau 1/64 ADC10CLK, Dien ap tham chieu noi 2_5V, Tu dong lay mau
	ADC10CTL0 |= ADC10SHT_3 | SREF_1 | REFON |REF2_5V|MSC|ADC10ON;
	// Chon Channel, ADC10CLK = 1/8 SMCLK , Lap lai lap lai nhieu kenh/1 kenh
	ADC10CTL1 = ((unsigned int)channel<<12) |ADC10DIV_7 | (sequence ? CONSEQ_3 : CONSEQ_2);
	// Cho phep chuyen doi
	ADC10CTL0 |= ENC;
	// Bat dau chuyen doi
	ADC10CTL0 |= ADC10SC;
}


// Muc dich de CPU ngat cho den khi den xung chuyen doi ADC xong

#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  __bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}

#endif

