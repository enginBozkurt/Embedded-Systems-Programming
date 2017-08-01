#define MPU6050_ADDRESS	0x68

#define MPU6050_RA_XG_OFFS_TC 0x00 //[7] PWR_MODE, [6:1] XG_OFFS_TC, [0] OTP_BNK_VLD
#define MPU6050_RA_YG_OFFS_TC 0x01 //[7] PWR_MODE, [6:1] YG_OFFS_TC, [0] OTP_BNK_VLD
#define MPU6050_RA_ZG_OFFS_TC 0x02 //[7] PWR_MODE, [6:1] ZG_OFFS_TC, [0] OTP_BNK_VLD
#define MPU6050_RA_X_FINE_GAIN 0x03 //[7:0] X_FINE_GAIN
#define MPU6050_RA_Y_FINE_GAIN 0x04 //[7:0] Y_FINE_GAIN
#define MPU6050_RA_Z_FINE_GAIN 0x05 //[7:0] Z_FINE_GAIN
#define MPU6050_RA_XA_OFFS_H 0x06 //[15:0] XA_OFFS
#define MPU6050_RA_XA_OFFS_L_TC 0x07
#define MPU6050_RA_YA_OFFS_H 0x08 //[15:0] YA_OFFS
#define MPU6050_RA_YA_OFFS_L_TC 0x09
#define MPU6050_RA_ZA_OFFS_H 0x0A //[15:0] ZA_OFFS
#define MPU6050_RA_ZA_OFFS_L_TC 0x0B
#define MPU6050_RA_XG_OFFS_USRH 0x13 //[15:0] XG_OFFS_USR
#define MPU6050_RA_XG_OFFS_USRL 0x14
#define MPU6050_RA_YG_OFFS_USRH 0x15 //[15:0] YG_OFFS_USR
#define MPU6050_RA_YG_OFFS_USRL 0x16
#define MPU6050_RA_ZG_OFFS_USRH 0x17 //[15:0] ZG_OFFS_USR
#define MPU6050_RA_ZG_OFFS_USRL 0x18
#define MPU6050_RA_SMPLRT_DIV 0x19			// jiroskop cikis orani(output rate) bu degerle bolunup(divide),Sample rate elde edilir
#define MPU6050_RA_CONFIG 0x1A
#define MPU6050_RA_GYRO_CONFIG 0x1B
#define MPU6050_RA_ACCEL_CONFIG 0x1C
#define MPU6050_RA_FF_THR 0x1D
#define MPU6050_RA_FF_DUR 0x1E
#define MPU6050_RA_MOT_THR 0x1F
#define MPU6050_RA_MOT_DUR 0x20
#define MPU6050_RA_ZRMOT_THR 0x21
#define MPU6050_RA_ZRMOT_DUR 0x22
#define MPU6050_RA_FIFO_EN 0x23
#define MPU6050_RA_I2C_MST_CTRL 0x24
#define MPU6050_RA_I2C_SLV0_ADDR 0x25
#define MPU6050_RA_I2C_SLV0_REG 0x26
#define MPU6050_RA_I2C_SLV0_CTRL 0x27
#define MPU6050_RA_I2C_SLV1_ADDR 0x28
#define MPU6050_RA_I2C_SLV1_REG 0x29
#define MPU6050_RA_I2C_SLV1_CTRL 0x2A
#define MPU6050_RA_I2C_SLV2_ADDR 0x2B
#define MPU6050_RA_I2C_SLV2_REG 0x2C
#define MPU6050_RA_I2C_SLV2_CTRL 0x2D
#define MPU6050_RA_I2C_SLV3_ADDR 0x2E
#define MPU6050_RA_I2C_SLV3_REG 0x2F
#define MPU6050_RA_I2C_SLV3_CTRL 0x30
#define MPU6050_RA_I2C_SLV4_ADDR 0x31
#define MPU6050_RA_I2C_SLV4_REG 0x32
#define MPU6050_RA_I2C_SLV4_DO 0x33
#define MPU6050_RA_I2C_SLV4_CTRL 0x34
#define MPU6050_RA_I2C_SLV4_DI 0x35
#define MPU6050_RA_I2C_MST_STATUS 0x36
#define MPU6050_RA_INT_PIN_CFG 0x37
#define MPU6050_RA_INT_ENABLE 0x38
#define MPU6050_RA_DMP_INT_STATUS 0x39
#define MPU6050_RA_INT_STATUS 0x3A
#define MPU6050_RA_ACCEL_XOUT_H 0x3B		//16 bitlik ivmeOlcerin x eksenindeki en guncel degeri(en yuksek bayt kýsmý)
#define MPU6050_RA_ACCEL_XOUT_L 0x3C		//16 bitlik ivmeOlcerin x eksenindeki en guncel degeri(en dusuk bayt kýsmý)
#define MPU6050_RA_ACCEL_YOUT_H 0x3D		//16 bitlik ivmeOlcerin y eksenindeki en guncel degeri(en yuksek bayt kýsmý)		 
#define MPU6050_RA_ACCEL_YOUT_L 0x3E	    //16 bitlik ivmeOlcerin y eksenindeki en guncel degeri(en dusuk bayt kýsmý)
#define MPU6050_RA_ACCEL_ZOUT_H 0x3F        //16 bitlik ivmeOlcerin z eksenindeki en guncel degeri(en yuksek bayt kýsmý)
#define MPU6050_RA_ACCEL_ZOUT_L 0x40		//16 bitlik ivmeOlcerin z eksenindeki en guncel degeri(en dusuk bayt kýsmý)
#define MPU6050_RA_TEMP_OUT_H 0x41
#define MPU6050_RA_TEMP_OUT_L 0x42
#define MPU6050_RA_GYRO_XOUT_H 0x43
#define MPU6050_RA_GYRO_XOUT_L 0x44
#define MPU6050_RA_GYRO_YOUT_H 0x45
#define MPU6050_RA_GYRO_YOUT_L 0x46
#define MPU6050_RA_GYRO_ZOUT_H 0x47
#define MPU6050_RA_GYRO_ZOUT_L 0x48
#define MPU6050_RA_EXT_SENS_DATA_00 0x49
#define MPU6050_RA_EXT_SENS_DATA_01 0x4A
#define MPU6050_RA_EXT_SENS_DATA_02 0x4B
#define MPU6050_RA_EXT_SENS_DATA_03 0x4C
#define MPU6050_RA_EXT_SENS_DATA_04 0x4D
#define MPU6050_RA_EXT_SENS_DATA_05 0x4E
#define MPU6050_RA_EXT_SENS_DATA_06 0x4F
#define MPU6050_RA_EXT_SENS_DATA_07 0x50
#define MPU6050_RA_EXT_SENS_DATA_08 0x51
#define MPU6050_RA_EXT_SENS_DATA_09 0x52
#define MPU6050_RA_EXT_SENS_DATA_10 0x53
#define MPU6050_RA_EXT_SENS_DATA_11 0x54
#define MPU6050_RA_EXT_SENS_DATA_12 0x55
#define MPU6050_RA_EXT_SENS_DATA_13 0x56
#define MPU6050_RA_EXT_SENS_DATA_14 0x57
#define MPU6050_RA_EXT_SENS_DATA_15 0x58
#define MPU6050_RA_EXT_SENS_DATA_16 0x59
#define MPU6050_RA_EXT_SENS_DATA_17 0x5A
#define MPU6050_RA_EXT_SENS_DATA_18 0x5B
#define MPU6050_RA_EXT_SENS_DATA_19 0x5C
#define MPU6050_RA_EXT_SENS_DATA_20 0x5D
#define MPU6050_RA_EXT_SENS_DATA_21 0x5E
#define MPU6050_RA_EXT_SENS_DATA_22 0x5F
#define MPU6050_RA_EXT_SENS_DATA_23 0x60
#define MPU6050_RA_MOT_DETECT_STATUS 0x61
#define MPU6050_RA_I2C_SLV0_DO 0x63
#define MPU6050_RA_I2C_SLV1_DO 0x64
#define MPU6050_RA_I2C_SLV2_DO 0x65
#define MPU6050_RA_I2C_SLV3_DO 0x66
#define MPU6050_RA_I2C_MST_DELAY_CTRL 0x67
#define MPU6050_RA_SIGNAL_PATH_RESET 0x68       //ivmeOlcer, jiroskop ve temp sensor signal path'leri resetle
#define MPU6050_RA_MOT_DETECT_CTRL 0x69
#define MPU6050_RA_USER_CTRL 0x6A
#define MPU6050_RA_PWR_MGMT_1 0x6B            //uyku modundan uyandýrmak için 0x00 deðerini yaz
#define MPU6050_RA_PWR_MGMT_2 0x6C
#define MPU6050_RA_BANK_SEL 0x6D
#define MPU6050_RA_MEM_START_ADDR 0x6E
#define MPU6050_RA_MEM_R_W 0x6F
#define MPU6050_RA_DMP_CFG_1 0x70
#define MPU6050_RA_DMP_CFG_2 0x71
#define MPU6050_RA_FIFO_COUNTH 0x72
#define MPU6050_RA_FIFO_COUNTL 0x73
#define MPU6050_RA_FIFO_R_W 0x74
#define MPU6050_RA_WHO_AM_I 0x75

unsigned long SMCLK_F=16000000;                 // Sub-System Master Clock frekansý Hz cinsinden
unsigned long BAUDRATE=9600;                   // baud rate: 1200, 2400, 4800, 9600, 19200, ..
long GYRO_XFilter[4],GYRO_YFilter[4],GYRO_ZFilter[4];
long ACCEL_XFilter[4],ACCEL_YFilter[4],ACCEL_ZFilter[4];
long G_Filter[4];

//sensör hatalarýnýn statik deðerleri
unsigned int TEMP_OUT = 0;
float dt = 0.00025;
float TEMP_DegC=31;

float ANGLE_X=0,
      ANGLE_Y=0,
      ANGLE_Z=0;

signed int GYRO_XOUT = 0,
           GYRO_YOUT = 0,
	   GYRO_ZOUT = 0;		

signed int ACCEL_XOUT = 0,
           ACCEL_YOUT = 0,
           ACCEL_ZOUT = 0;

void Init_I2C_USCI(unsigned char addr);
void Set_Address(unsigned char addr);
int ByteRead_I2C_USCI(unsigned char address);
unsigned char ByteWrite_I2C_USCI(unsigned char address, unsigned char Data);
unsigned char WordRead_I2C_USCI(unsigned char Addr_Data,unsigned char *Data, unsigned char Length);

void UART_Init();		                        //UART modülünü hazýrla
void UART_Write_Char(unsigned char data);	   	//char(karakter) gönder
void UART_Write_String(char* string);		  	//string gönder
void UART_Write_Int(unsigned long n);		   	//integer gönder
void UART_Write_Reg(char *name, int n);			//register bitleri deðeri gönder
void UART_Write_Float(float x,int coma);		//virgülden sonra en fazla 4 hane comma<=4
char UART_Read_Char();				        //karakterleri oku
void UART_Read_String(char *s);			        //string i oku
char UART_Data_Ready();					//UART Modülünün hazýr olup olmadýðýný denetle
void Setup_MPU6050();
void Get_Gyro_Values();
void Filters_Gyro();
void Filters_Accel();
void Get_Accel_Values();
void Get_Temp_Values();
void MPU6050_Test_I2C();

#include "msp430g2553.h"
#include <intrinsics.h>
#include "in430.h"


void main(void) {
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  DCOCTL=CALDCO_16MHZ;
  BCSCTL1=CALBC1_16MHZ;
    __delay_cycles(100000);

	Init_I2C_USCI(MPU6050_ADDRESS);
        MPU6050_Test_I2C();
	Setup_MPU6050();
	__delay_cycles(320000);
	
	UART_Init();
	while(1)
        {                      
                Get_Accel_Values();                
                Get_Gyro_Values(); 
               
                //Get_Angle_filter();
                // __delay_cycles(1000000);
                //dt = 0.008                
                UART_Write_Float(ACCEL_XOUT,0);                
                UART_Write_Char(' ');       
                UART_Write_Float(ACCEL_YOUT,0);               
                UART_Write_Char(' ');                                       
                UART_Write_Float(ACCEL_ZOUT,0);   
                UART_Write_Char(' ');                               
                UART_Write_Float(GYRO_XOUT,0);
                UART_Write_Char(' ');   
                UART_Write_Float(GYRO_YOUT,0);
                UART_Write_Char(' ');   
                UART_Write_Float(GYRO_ZOUT,0); 
                UART_Write_Char(10);                       
        }
}

void Init_I2C_USCI(unsigned char addr)
{
	P1SEL = BIT6 + BIT7;                     // Assign I2C pins to USCI_B0 (P1.6 SCL, P1.7 SDA)
	P1SEL2 = BIT6 + BIT7;                     // Assign I2C pins to USCI_B0
        
        
	UCB0CTL1 |= UCSWRST;                      // Enable SW reset (software reset)
	UCB0CTL0 = UCMST+UCMODE_3+UCSYNC;         // UCMST: Master mode, UCMODE_3 : I2C Mode, UCSYNC: senkron haberlesme
  	UCB0CTL1 = UCSSEL_2+UCSWRST;              // Use SMCLK, keep SW reset
	UCB0BR0 = 40;                             // fSCL = SMCLK/10 = ~100kHz
	UCB0BR1 = 0;
	UCB0I2CSA = addr;                         // Set slave address
	UCB0CTL1 &= ~UCSWRST;                     // Clear SW reset, resume operation(USCI hazýr hale getir)      
}

void Set_Address(unsigned char addr)
{
  	UCB0CTL1 |= UCSWRST;    
  	UCB0I2CSA = addr;                     		// slave address i belirle
  	UCB0CTL1 &= ~UCSWRST;                 		// Clear SW reset, resume operation 	
}
//byte oku
int ByteRead_I2C_USCI(unsigned char address)
{ 	
	while (UCB0CTL1 & UCTXSTP);             	// stop condition olustugu surece islem yapma
	UCB0CTL1 |= UCTR + UCTXSTT;             	// I2C start condition baslat(UCTR =1 transmitter mode)

	while (!(IFG2&UCB0TXIFG));					// buffer daki data shift register a gecene kadar bekle(buffer hazýr mý?)
	UCB0TXBUF = address;                      	// buffer a gonderilecek adresi kaydet

	while (!(IFG2&UCB0TXIFG));					// buffer hazýr mý?

	UCB0CTL1 &= ~UCTR;                      // I2C RX(UCTR=0 receiver mode)
	UCB0CTL1 |= UCTXSTT;                    // I2C RESTART(start condition set, Start Condition sends address of slave)
	IFG2 &= ~UCB0TXIFG;                     // USCI_B0 TX interrupt flag i temizle

	while (UCB0CTL1 & UCTXSTT);             // start condition var oldugu sürece islem yapma 
	UCB0CTL1 |= UCTXSTP;                    // stop condition biti gönder
	return UCB0RXBUF;						// buffer okunan deger don
}

//word oku
unsigned char WordRead_I2C_USCI(unsigned char Addr_Data,unsigned char *Data,unsigned char Length)
{ 	
	unsigned char i=0;
	while (UCB0CTL1 & UCTXSTP);             	// stop condition olustugu surece islem yapma
	UCB0CTL1 |= UCTR + UCTXSTT;             	// I2C TX, start condition baslat(transmit modu)

	while (!(IFG2&UCB0TXIFG));					// buffer hazýr mý?
	IFG2 &= ~UCB0TXIFG;                     	// USCI_B0 TX interrupt flag temizle
	if(UCB0STAT & UCNACKIFG) return UCB0STAT;	//eger NACK biti setlenmiþse USCI_B0 status register ý dön
	UCB0TXBUF = Addr_Data;                      // buffer a gonderilecek adresi kaydet

	while (!(IFG2&UCB0TXIFG));					// buffer hazýr mý?
	if(UCB0STAT & UCNACKIFG) return UCB0STAT;	//eger NACK biti setlenirse USCI_B0 status register ý dön

	UCB0CTL1 &= ~UCTR;                      // I2C RX(UCTR=0 receiver mode)
	UCB0CTL1 |= UCTXSTT;                    // I2C start condition
	IFG2 &= ~UCB0TXIFG;						// USCI_B0 TX interrupt flag i temizle
        for(i=0;i<(Length-1);i++)           
        {                                        
	while (UCB0CTL1 & UCTXSTT);             // start condition var oldugu sürece islem yapma
	while (!(IFG2&UCB0RXIFG));				// buffer hazýr mý?
	IFG2 &= ~UCB0TXIFG;                     // USCI_B0 TX interrupt flag temizle
	Data[i] = UCB0RXBUF;					// gonderilecek adresleri buffer a yaz
	}
	while (!(IFG2&UCB0RXIFG));				 // buffer hazýr mý?
	IFG2 &= ~UCB0TXIFG;                     // USCI_B0 TX interrupt flag temizle
	UCB0CTL1 |= UCTXSTP;                    // I2C stop condition after 1st TX
	Data[Length-1] = UCB0RXBUF;				
	IFG2 &= ~UCB0TXIFG;                     // USCI_B0 TX interrupt flag temizle
	return 0;
}

unsigned char ByteWrite_I2C_USCI(unsigned char address, unsigned char data)
{
	while (UCB0CTL1 & UCTXSTP);             // stop modundan çýkýldýðýndan emin ol
	UCB0CTL1 |= UCTR + UCTXSTT;             // I2C TX, start moduna geç(UCTR =1 transmitter mode)

	while (!(IFG2&UCB0TXIFG));				// buffer hazýr mý?
	if(UCB0STAT & UCNACKIFG) return UCB0STAT;	//eger NACK biti setlenmiþse USCI_B0 status register ý dön
	UCB0TXBUF = address;					// buffer a gonderilecek adresi kaydet


	while (!(IFG2&UCB0TXIFG));				// buffer hazýr mý?
	if(UCB0STAT & UCNACKIFG) return UCB0STAT;	//eger NACK biti setlenmiþse USCI_B0 status register ý dön
	UCB0TXBUF = data;						// buffer a gonderilecek data yý kaydet

	while (!(IFG2&UCB0TXIFG));				// buffer hazýr mý?
	if(UCB0STAT & UCNACKIFG) return UCB0STAT;	//eger NACK biti setlenmiþse USCI_B0 status register ý dön
	UCB0CTL1 |= UCTXSTP;                    // stop condition biti gönder
	IFG2 &= ~UCB0TXIFG;                     // USCI_B0 TX interrupt flag temizle
	return 0;
}
//UART hazýrla
void UART_Init()
{
	unsigned int tempfactor;					//standard baudrate yakalama için division faktörü
	WDTCTL = WDTPW + WDTHOLD; // WDT pasif
	P1SEL |= BIT1 + BIT2 ; // P1.1 = RXD, P1.2=TXD kullanýlack tx ve rx pinlerini hazýrla
	P1SEL2 |= BIT1 + BIT2;
	UCA0CTL0 =0 ;		//Parity biti yok ,önce LSB okunur,8-bit data,bir stop biti
	UCA0CTL1 |= UCSSEL_2; // SMCLK 

 	tempfactor = SMCLK_F/BAUDRATE;                        //divider factor deðeri = 104
        UCA0BR0 = (unsigned char) tempfactor&0x00FF;     //en yüksek deðerlikli byte ý
        tempfactor >>= 8;								//kesirli kýsmý UCBRSx = round( ( N – INT(N) ) × 8 )
        UCA0BR1 = (unsigned char) (tempfactor&0x00FF);   //bölme oraný nýn en yüksek deðerlikli byte ý
        UCA0MCTL |=UCBRS_5;					// Modulation UCBRSx = 5 en yakýn frekansý yakalamak için gereken mod
	UCA0CTL1 &=~ UCSWRST; 					// USCI state machine baþlat resetleme pasif
	IE2 |= UCA0RXIE; // USCI_A0 RX interrupt aktif et
	__bis_SR_register(GIE); // genel Interrupt(kesme) aktif et
}
//karakter gönder
void UART_Write_Char(unsigned char data)
{
	while (!(IFG2&UCA0TXIFG)); // Tx buffer ýn hazýr olmasýný bekle
	UCA0TXBUF = data; // sonra datayý buffer a yaz
}

//string gönder
void UART_Write_String(char* string)
{        
	while(*string) 
		{
		while (!(IFG2&UCA0TXIFG)); // Tx buffer ýn hazýr olmasýný bekle
		UCA0TXBUF= *string; // string deki ilk karakteri gönder
		string++; // sonraki karakteri al
		}	     
}

//integer1 ý ASCII string e çevirme
void UART_Write_Int(unsigned long n)
{
     unsigned char buffer[16];
     unsigned char i,j;

     if(n == 0) {
    	 UART_Write_Char('0');
          return;
     }

     for (i = 15; i > 0 && n > 0; i--) {
          buffer[i] = (n%10)+'0';          //birler basamagýný al ve '0' hex degerini alýnan kadar artýr
          n /= 10;						   //sonraki basamak a gec
     }

     for(j = i+1; j <= 15; j++) {
    	 UART_Write_Char(buffer[j]);
     }
}


//UART ile gönderilecek x reel sayýsýný ve virgülden sonraki kýsmýný göster
void UART_Write_Float(float x, int coma)
{
	unsigned long temp;
	if(coma>4)coma=4;
	// baþlangýçta sayý negatif ise
	if(x<0)
	{
		UART_Write_Char('-');			//negatif sayý için
		x*=-1;
	}
	temp = (unsigned long)x;						// tam sayýya dönüþtür
	UART_Write_Int(temp);

	x = (float)(x-temp);                  //virgülden sonra yapýlacak iþlem
	if(coma>0)
        {
          UART_Write_Char('.');	
	  while(coma>0)
	    {
		x*=10;                               
		coma--;
	    }
          temp = (unsigned long)x+1;	
	  UART_Write_Int(temp);
        }
}
char UART_Read_Char()
{
	while (!(IFG2&UCA0RXIFG)); // veri transferi bitene kadar bekle
	return UCA0RXBUF; // data transferi bitmiþse sonraki karakteri al
}

// UART üzerinden string alma
// string ifade '/0' (veya 0x00) ile sonlanýr
void UART_Read_String(char *s)
{
       *s = UART_Read_Char();
	while(*s!='\0')
	{
		s++;
		*s = UART_Read_Char();
	}
}
// USCI_A0 RX Buffer ýn tam bir karakter alýp almadýðýný kontrol et
char UART_Data_Ready()
{
	if(UCA0RXIFG) return 1;
	else return 0;
}


//ilgili register a yazýlacak deðeri bit bit iþleyerek gönder
void UART_Write_Reg(char *name, int n)
{
    int size = 8;
    int i;

    UART_Write_String((char *)"- ");
    UART_Write_String(name);
    UART_Write_String((char *)": ");

    int mask = 1 << (size - 1);

    for(i = 0; i < size; i++) {
         if((n & (mask >> i)) != 0) {
        	 UART_Write_Char('1');
         } else {
        	 UART_Write_Char('0');
         }
    }
    UART_Write_String(" (");
	UART_Write_Int(n);
	UART_Write_String(")\n\r");
}

//jiroskop deðerlerini al
void Get_Gyro_Values()
{	
        unsigned char a[2];
        a[1] =ByteRead_I2C_USCI(MPU6050_RA_GYRO_XOUT_H);
        a[0] =ByteRead_I2C_USCI(MPU6050_RA_GYRO_XOUT_L);
        GYRO_XOUT = a[0]<<8 | a[1];
        
        a[1] = ByteRead_I2C_USCI(MPU6050_RA_GYRO_YOUT_H);
        a[0] = ByteRead_I2C_USCI(MPU6050_RA_GYRO_YOUT_L);
        GYRO_YOUT = a[0]<<8 | a[1];
        
        a[1] = ByteRead_I2C_USCI(MPU6050_RA_GYRO_ZOUT_H);
        a[0] = ByteRead_I2C_USCI(MPU6050_RA_GYRO_ZOUT_L);
        GYRO_ZOUT = a[0]<<8 | a[1];
	
	Filters_Gyro();
}


//ivmeÖlçer deðerlerini al
void Get_Accel_Values(){	
	unsigned char a[2];										// 2 elemanlý bir dizi tanýmla
        a[1] =ByteRead_I2C_USCI(MPU6050_RA_ACCEL_XOUT_H);	//en yuksek baytlýk kýsmý al ve diziye aktar(x ekseni)
        a[0] =ByteRead_I2C_USCI(MPU6050_RA_ACCEL_XOUT_L);	//en dusuk baytlýk kýsmý al ve diziye aktar (x ekseni)
        ACCEL_XOUT = a[0]<<8|a[1];							//en dusuk baytlýk kýsmý 8 bit saga kaydýr ve en yuksek baytlýk kýsým ile topla
        
        a[1] =ByteRead_I2C_USCI(MPU6050_RA_ACCEL_YOUT_H);
        a[0] =ByteRead_I2C_USCI(MPU6050_RA_ACCEL_YOUT_L);
        ACCEL_YOUT =  a[0]<<8|a[1];
        
        a[1] =ByteRead_I2C_USCI(MPU6050_RA_ACCEL_ZOUT_H);
        a[0] =ByteRead_I2C_USCI(MPU6050_RA_ACCEL_ZOUT_L);
        ACCEL_ZOUT =  a[0]<<8|a[1];          
	Filters_Accel();									 //ivmeOlcer icin filtre fonksiyonunu cagýr
}	
//sýcaklýk deðerleri al
void Get_Temp_Values()
{       
	unsigned char rData[2];
        rData[1]=ByteRead_I2C_USCI(MPU6050_RA_TEMP_OUT_H);
        rData[0]=ByteRead_I2C_USCI(MPU6050_RA_TEMP_OUT_L);	
	TEMP_OUT = ((rData[0]<<8)|rData[1]);       
}

void Filters_Gyro()							//jiroskop icin filtre
{
	GYRO_XFilter[3] = GYRO_XFilter[2];
	GYRO_XFilter[2] = GYRO_XFilter[1];
	GYRO_XFilter[1] = GYRO_XFilter[0];
	GYRO_XFilter[0] = GYRO_XOUT;

	GYRO_XOUT = 	 ((long)GYRO_XFilter[3]	+GYRO_XFilter[2]+GYRO_XFilter[1] +GYRO_XFilter[0])>>2;  //4 deger toplanýp ortalamasý alýnýr(>> / 2)

	GYRO_YFilter[3] = GYRO_YFilter[2];
	GYRO_YFilter[2] = GYRO_YFilter[1];
	GYRO_YFilter[1] = GYRO_YFilter[0];
	GYRO_YFilter[0] = GYRO_YOUT;

	GYRO_YOUT = 	 ((long)GYRO_YFilter[3]
					+GYRO_YFilter[2]
					+GYRO_YFilter[1]
					+GYRO_YFilter[0])>>2;

	GYRO_ZFilter[3] = GYRO_ZFilter[2];
	GYRO_ZFilter[2] = GYRO_ZFilter[1];
	GYRO_ZFilter[1] = GYRO_ZFilter[0];
	GYRO_ZFilter[0] = GYRO_ZOUT;

	GYRO_ZOUT = 	 ((long)GYRO_ZFilter[3]
					+GYRO_ZFilter[2]
					+GYRO_ZFilter[1]
					+GYRO_ZFilter[0])>>2;
}
void Filters_Accel()						//ivmeOlcer icin filtre
{
	ACCEL_XFilter[3] = ACCEL_XFilter[2];
	ACCEL_XFilter[2] = ACCEL_XFilter[1];
	ACCEL_XFilter[1] = ACCEL_XFilter[0];
	ACCEL_XFilter[0] = ACCEL_XOUT;
	ACCEL_XOUT = (ACCEL_XFilter[3]+ACCEL_XFilter[2]+ACCEL_XFilter[1]+ACCEL_XFilter[0])>>2;

	ACCEL_YFilter[3] = ACCEL_YFilter[2];
	ACCEL_YFilter[2] = ACCEL_YFilter[1];
	ACCEL_YFilter[1] = ACCEL_YFilter[0];
	ACCEL_YFilter[0] = ACCEL_YOUT;
	ACCEL_YOUT = (ACCEL_YFilter[3]+ACCEL_YFilter[2]+ACCEL_YFilter[1]+ACCEL_YFilter[0])>>2;

	ACCEL_ZFilter[3] = ACCEL_ZFilter[2];
	ACCEL_ZFilter[2] = ACCEL_ZFilter[1];
	ACCEL_ZFilter[1] = ACCEL_ZFilter[0];
	ACCEL_ZFilter[0] = ACCEL_ZOUT;
	ACCEL_ZOUT = (ACCEL_ZFilter[3]+ACCEL_ZFilter[2]+ACCEL_ZFilter[1]+ACCEL_ZFilter[0])>>2;
}

void Setup_MPU6050()
{
	while(ByteWrite_I2C_USCI(MPU6050_RA_SIGNAL_PATH_RESET,0x07));	
	__delay_cycles(1000);
        
	//Sets sample rate to 1000/(1+99) = 10Hz
	while(ByteWrite_I2C_USCI(MPU6050_RA_SMPLRT_DIV,0));
        
	//Disable FSync, 184Hz DLPF
	while(ByteWrite_I2C_USCI(MPU6050_RA_CONFIG, 0x06));
        
	//Disable gyro self tests, scale of 250 degrees/s
	while(ByteWrite_I2C_USCI(MPU6050_RA_GYRO_CONFIG, 0x00));
        
	//Disable accel self tests, scale of +-2g, no DHPF
	while(ByteWrite_I2C_USCI(MPU6050_RA_ACCEL_CONFIG, 0x00));
	
	while(ByteWrite_I2C_USCI(MPU6050_RA_TEMP_OUT_H,0x00));
	while(ByteWrite_I2C_USCI(MPU6050_RA_TEMP_OUT_L,0x00));
	while(ByteWrite_I2C_USCI(MPU6050_RA_GYRO_XOUT_H,0x00));
	while(ByteWrite_I2C_USCI(MPU6050_RA_GYRO_XOUT_L,0x00));
	while(ByteWrite_I2C_USCI(MPU6050_RA_GYRO_YOUT_H,0x00));
	while(ByteWrite_I2C_USCI(MPU6050_RA_GYRO_YOUT_L,0x00));
	while(ByteWrite_I2C_USCI(MPU6050_RA_GYRO_ZOUT_H,0x00));
	while(ByteWrite_I2C_USCI(MPU6050_RA_GYRO_ZOUT_L,0x00));

	while(ByteWrite_I2C_USCI(MPU6050_RA_ACCEL_XOUT_H,0x00));
	while(ByteWrite_I2C_USCI(MPU6050_RA_ACCEL_XOUT_L,0x00));
	while(ByteWrite_I2C_USCI(MPU6050_RA_ACCEL_YOUT_H,0x00));
	while(ByteWrite_I2C_USCI(MPU6050_RA_ACCEL_YOUT_L,0x00));
	while(ByteWrite_I2C_USCI(MPU6050_RA_ACCEL_ZOUT_H,0x00));
	while(ByteWrite_I2C_USCI(MPU6050_RA_ACCEL_ZOUT_L,0x00));
	//Freefall threshold of <|0mg|
	while(ByteWrite_I2C_USCI( MPU6050_RA_FF_THR, 0x00));
	//Freefall duration limit of 0
	while(ByteWrite_I2C_USCI( MPU6050_RA_FF_DUR, 0x00));
	//Motion threshold of >0mg
	while(ByteWrite_I2C_USCI( MPU6050_RA_MOT_THR, 0x00));
	//Motion duration of >0s
	while(ByteWrite_I2C_USCI( MPU6050_RA_MOT_DUR, 0x00));
	//Zero motion threshold
	while(ByteWrite_I2C_USCI(MPU6050_RA_ZRMOT_THR, 0x00));
	//Zero motion duration threshold
	while(ByteWrite_I2C_USCI( MPU6050_RA_ZRMOT_DUR, 0x00));
	//Disable sensor output to FIFO buffer
	while(ByteWrite_I2C_USCI( MPU6050_RA_FIFO_EN, 0x00));
	
	//AUX I2C setup
	//Sets AUX I2C to single master control, plus other config
	while(ByteWrite_I2C_USCI( MPU6050_RA_I2C_MST_CTRL, 0x00));
	//Setup AUX I2C slaves	
 	while(ByteWrite_I2C_USCI( MPU6050_RA_I2C_SLV0_ADDR, 0x00));
 	while(ByteWrite_I2C_USCI( MPU6050_RA_I2C_SLV0_REG, 0x00));
 	while(ByteWrite_I2C_USCI( MPU6050_RA_I2C_SLV0_CTRL, 0x00));
 	while(ByteWrite_I2C_USCI(MPU6050_RA_I2C_SLV1_ADDR, 0x00));
 	while(ByteWrite_I2C_USCI( MPU6050_RA_I2C_SLV1_REG, 0x00));
 	while(ByteWrite_I2C_USCI( MPU6050_RA_I2C_SLV1_CTRL, 0x00));
 	while(ByteWrite_I2C_USCI(MPU6050_RA_I2C_SLV2_ADDR, 0x00));
 	while(ByteWrite_I2C_USCI( MPU6050_RA_I2C_SLV2_REG, 0x00));
 	while(ByteWrite_I2C_USCI( MPU6050_RA_I2C_SLV2_CTRL, 0x00));
 	while(ByteWrite_I2C_USCI(MPU6050_RA_I2C_SLV3_ADDR, 0x00));
 	while(ByteWrite_I2C_USCI(MPU6050_RA_I2C_SLV3_REG, 0x00));
 	while(ByteWrite_I2C_USCI( MPU6050_RA_I2C_SLV3_CTRL, 0x00));
 	while(ByteWrite_I2C_USCI( MPU6050_RA_I2C_SLV4_ADDR, 0x00));
 	while(ByteWrite_I2C_USCI(MPU6050_RA_I2C_SLV4_REG, 0x00));
 	while(ByteWrite_I2C_USCI(MPU6050_RA_I2C_SLV4_DO, 0x00));
 	while(ByteWrite_I2C_USCI(MPU6050_RA_I2C_SLV4_CTRL, 0x00));
 	while(ByteWrite_I2C_USCI( MPU6050_RA_I2C_SLV4_DI, 0x00));
 
 
 	//MPU6050_RA_I2C_MST_STATUS //Read-only
 	//Setup INT pin and AUX I2C pass through
	while(ByteWrite_I2C_USCI( MPU6050_RA_INT_PIN_CFG, 0x00));
	//Enable data ready interrupt
	while(ByteWrite_I2C_USCI(MPU6050_RA_INT_ENABLE, 0x01));
	
	
	
	//Slave out, dont care
	while(ByteWrite_I2C_USCI( MPU6050_RA_I2C_SLV0_DO, 0x00));
	while(ByteWrite_I2C_USCI( MPU6050_RA_I2C_SLV1_DO, 0x00));
	while(ByteWrite_I2C_USCI(MPU6050_RA_I2C_SLV2_DO, 0x00));
	while(ByteWrite_I2C_USCI(MPU6050_RA_I2C_SLV3_DO, 0x00));
	//More slave config
	while(ByteWrite_I2C_USCI( MPU6050_RA_I2C_MST_DELAY_CTRL, 0x00));
	//Reset sensor signal paths
	while(ByteWrite_I2C_USCI(MPU6050_RA_SIGNAL_PATH_RESET, 0x00));
	//Motion detection control
	while(ByteWrite_I2C_USCI(MPU6050_RA_MOT_DETECT_CTRL, 0x00));
	//Disables FIFO, AUX I2C, FIFO and I2C reset bits to 0
	while(ByteWrite_I2C_USCI(MPU6050_RA_USER_CTRL, 0x00));
	//Sets clock source to gyro reference w/ PLL
	while(ByteWrite_I2C_USCI(MPU6050_RA_PWR_MGMT_1, 0x00));                                                 //mpu6050 uykudan uyandýr
	//Controls frequency of wakeups in accel low power mode plus the sensor standby modes
	while(ByteWrite_I2C_USCI(MPU6050_RA_PWR_MGMT_2, 0x00));    
	__delay_cycles(1000);
}

void MPU6050_Test_I2C()
{
	unsigned char i;	
	i = ByteRead_I2C_USCI(MPU6050_RA_WHO_AM_I);
        
	if(i == MPU6050_ADDRESS)
	{		
		UART_Write_Char(i);
	}		
}	


#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
{
    while (!(IFG2 & UCA0TXIFG));                // USCI_A0 TX buffer hazýr mý?    
    UCA0TXBUF = UCA0RXBUF;                    // RXed karakteri geri gönder(echo)  
}


