#ifdef USE_MPU6050

long GYRO_XFilter[4],GYRO_YFilter[4],GYRO_ZFilter[4];
long ACCEL_XFilter[4],ACCEL_YFilter[4],ACCEL_ZFilter[4];
long G_Filter[4];

//Static error value of the sensor
unsigned int	TEMP_OUT = 0;
float dt = 0.00025;
float          TEMP_DegC=31;

float                           ANGLE_X=0,
                                ANGLE_Y=0,
                                ANGLE_Z=0;
signed int	
                                
                                GYRO_XOUT = 0,
				GYRO_YOUT = 0,
				GYRO_ZOUT = 0;		

signed int                      ACCEL_XOUT = 0,
				ACCEL_YOUT = 0,
				ACCEL_ZOUT = 0;
				

/******************************************************************************\
*					Address MPU6050                           *
\******************************************************************************/

#define MPU6050_ADDRESS 0x68 // Address MPU6050	0b01101000		0b10100100

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
#define MPU6050_RA_SMPLRT_DIV 0x19
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
#define MPU6050_RA_ACCEL_XOUT_H 0x3B
#define MPU6050_RA_ACCEL_XOUT_L 0x3C
#define MPU6050_RA_ACCEL_YOUT_H 0x3D
#define MPU6050_RA_ACCEL_YOUT_L 0x3E
#define MPU6050_RA_ACCEL_ZOUT_H 0x3F
#define MPU6050_RA_ACCEL_ZOUT_L 0x40
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
#define MPU6050_RA_SIGNAL_PATH_RESET 0x68
#define MPU6050_RA_MOT_DETECT_CTRL 0x69
#define MPU6050_RA_USER_CTRL 0x6A
#define MPU6050_RA_PWR_MGMT_1 0x6B
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


/******************************************************************************\
*					The pass   						       *
\******************************************************************************/
#ifndef cbi
	#define cbi(port, bit) 	   (port) &= ~(1 << (bit))
#endif
#ifndef sbi
	#define sbi(port, bit) 	   (port) |=  (1 << (bit))
#endif	

/******************************************************************************\
*					Prototype (nguyen mau ham)    						       *
\******************************************************************************/

void Setup_MPU6050();
void MPU6050_Test_I2C();				//Check Module Address
unsigned char MPU6050_Check_Registers();
void Get_Temp_Values();
void Calibrate_Gyros();					//Get the Gyro's static bias
void Get_Gyro_Values();					//Get the Gyro Value
void Get_Gyro_Rates();					//Take angle values
void Get_Accel_Values();
void Get_Accel_Decac();					//Get the clan
void Get_Accel_Angles();				//Take root from gravity acceleration
void Test_Gyro_Value();					//Test value
void Test_Gyro_Rates();
void Test_Accel_Value();

/******************************************************************************\
*					Function (noi dung ham)	                           *
\******************************************************************************/
 


void Filters_Gyro()
{
	GYRO_XFilter[3] = GYRO_XFilter[2];
	GYRO_XFilter[2] = GYRO_XFilter[1];
	GYRO_XFilter[1] = GYRO_XFilter[0];
	GYRO_XFilter[0] = GYRO_XOUT;

	GYRO_XOUT = 	 ((long)GYRO_XFilter[3]	+GYRO_XFilter[2]+GYRO_XFilter[1] +GYRO_XFilter[0])>>2;

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
void Filters_Accel()
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
	_delay_ms(1000);
        
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
	while(ByteWrite_I2C_USCI(MPU6050_RA_PWR_MGMT_1, 0x00));
	//Controls frequency of wakeups in accel low power mode plus the sensor standby modes
	while(ByteWrite_I2C_USCI(MPU6050_RA_PWR_MGMT_2, 0x00));    
	_delay_ms(1000);
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

unsigned char MPU6050_Check_Registers()
{	
}


void Get_Temp_Values()
{       
	unsigned char rData[2];
        rData[1]=ByteRead_I2C_USCI(MPU6050_RA_TEMP_OUT_H);
        rData[0]=ByteRead_I2C_USCI(MPU6050_RA_TEMP_OUT_L);	
	TEMP_OUT = ((rData[0]<<8)|rData[1]);       
}



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


//Gets raw accelerometer data, performs no processing
void Get_Accel_Values(){	
	unsigned char a[2];
        a[1] =ByteRead_I2C_USCI(MPU6050_RA_ACCEL_XOUT_H);
        a[0] =ByteRead_I2C_USCI(MPU6050_RA_ACCEL_XOUT_L);
        ACCEL_XOUT = a[0]<<8|a[1];
        
        a[1] =ByteRead_I2C_USCI(MPU6050_RA_ACCEL_YOUT_H);
        a[0] =ByteRead_I2C_USCI(MPU6050_RA_ACCEL_YOUT_L);
        ACCEL_YOUT =  a[0]<<8|a[1];
        
        a[1] =ByteRead_I2C_USCI(MPU6050_RA_ACCEL_ZOUT_H);
        a[0] =ByteRead_I2C_USCI(MPU6050_RA_ACCEL_ZOUT_L);
        ACCEL_ZOUT =  a[0]<<8|a[1];          
	Filters_Accel();
}	


void Get_Angle_filter()
{
  
}




#endif

