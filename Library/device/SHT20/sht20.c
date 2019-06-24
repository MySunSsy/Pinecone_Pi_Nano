/**
  ******************************************************************************
  * @file    sht20.c
  * @author  ThreeWater
  * @version V1.0.0
  * @date    17-June-2019
  * @brief  This article will be used for  driving sht20.
  * @License:none         
  ******************************************************************************
  * @attention
  *	The frequency of crystal oscillator is 12 Mhz.
  * using OLED_IIC_Setup() to initialize.
  * 
  * 
  *
  * 
  ******************************************************************************
	**/

#include "sht20.h"

 unsigned char sndata1[8];
 unsigned char sndata2[6];
 unsigned int SN1; 
 unsigned int SN2; 



 /**
  * @file   I2C_delay
  * @brief  �ӳ�ʱ��
  * @param  ��
  * @retval ��
  */
void I2C_delay(void)
{	
   unsigned int i=6; /* ��������Ż��ٶ�,��������͵�5����д�� */
   while(i--);
}

 /**
  * @file   I2C_Start
  * @brief  ��ʼ�ź�
  * @param  ��
  * @retval ��
  */
FunctionalState I2C_Start(void)
{
	SDA_H;
	SCL_H;
	I2C_delay();
	if(!SDA_read)return DISABLE;	/* SDA��Ϊ�͵�ƽ������æ,�˳� */
        SDA_L;
	I2C_delay();
       
	if(SDA_read) return DISABLE;	/* SDA��Ϊ�ߵ�ƽ�����߳���,�˳� */
	SDA_L;
	I2C_delay();
	return ENABLE;
}

 /**
  * @file   I2C_Stop
  * @brief  ֹͣ�ź�
  * @param  ��
  * @retval ��
  */
void I2C_Stop(void)
{
	SCL_L;
	I2C_delay();
	SDA_L;
	I2C_delay();
	SCL_H;
	I2C_delay();
	SDA_H;
	I2C_delay();
}

 /**
  * @file   I2C_Ack
  * @brief  Ӧ���ź�
  * @param  ��
  * @retval ��
  */
void I2C_Ack(void)
{	
	SCL_L;
	I2C_delay();
	SDA_L;
	I2C_delay();
	SCL_H;
	I2C_delay();
	SCL_L;
	I2C_delay();
}

 /**
  * @file   I2C_NoAck
  * @brief  ��Ӧ���ź�
  * @param  ��
  * @retval ��
  */
void I2C_NoAck(void)
{	
	SCL_L;
	I2C_delay();
	SDA_H;
	I2C_delay();
	SCL_H;
	I2C_delay();
	SCL_L;
	I2C_delay();
}

 /**
  * @file   I2C_WaitAck
  * @brief  �ȴ�Ack
  * @param  ��
  * @retval ����Ϊ:=1��ACK,=0��ACK
  */
FunctionalState I2C_WaitAck(void) 	
{
	SCL_L;
	I2C_delay();
	SDA_H;			
	I2C_delay();
	SCL_H;
	I2C_delay();
	if(SDA_read)
	{
           SCL_L;
          return DISABLE;
	}
	SCL_L;
	return ENABLE;
}

 /**
  * @file   I2C_SendByte
  * @brief  ���ݴӸ�λ����λ
  * @param  - SendByte: ���͵�����
  * @retval ��
  */
void I2C_SendByte(unsigned char SendByte) 
{
    unsigned char i=8;
    while(i--)
    {
	SCL_L;
	I2C_delay();
	if(SendByte&0x80)
	SDA_H;  
	else 
	SDA_L;   
	SendByte<<=1;
	I2C_delay();
	SCL_H;
	I2C_delay();
    }
    SCL_L;
}


 /**
  * @file   I2C_ReceiveByte
  * @brief  ���ݴӸ�λ����λ
  * @param  ��
  * @retval I2C���߷��ص�����
  */
unsigned char I2C_ReceiveByte(void)  
{ 
    unsigned char i=8;
    unsigned char ReceiveByte=0;
    SDA_H;				
    while(i--)
    {
      ReceiveByte<<=1;      
      SCL_L;
      I2C_delay();
	    SCL_H;
      I2C_delay();	
      if(SDA_read)
      {
        ReceiveByte|=0x01;
      }
    }
    SCL_L;
    return ReceiveByte;
} 



 /**
  * @file   Delay_us(����ȷ)
  * @brief  ΢����ʱ time_ms ms
  * @param  time_us ��ʱʱ��
  * @retval NO
  */
static void delay_us( unsigned short int time_us )
{
  unsigned short int i,j;
  for( i=0;i<time_us;i++ )
  {
	for(j=0;j<4;j++);
  }
}
 /**
  * @file   Delay_Ms(����ȷ)
  * @brief  ������ʱ time_ms ms
  * @param  time_ms ��ʱʱ��
  * @retval NO
  */
static void delay_ms(unsigned short int time_ms)
{
	 unsigned short int i;
  for( i=0;i<time_ms;i++ )
  {
		delay_us(11000);
  }
	
}


 /**
  * @file   SHT2x_Calc_T
  * @brief  �����¶�
  * @param  NO
  * @retval �����¶�ֵ
  */
float SHT2x_Calc_T(void)
{
	float temperatureC;
  //  unsigned char timeout=30;
    unsigned char length=0;
    unsigned char Tdata[3]={0};
    I2C_Start();
    I2C_SendByte(I2C_ADR_W); 
    I2C_WaitAck();
    I2C_SendByte(TRIG_T_MEASUREMENT_POLL);      
    I2C_WaitAck();
    delay_us(20);
    I2C_Stop();
    do
    {
	I2C_Start();
        I2C_SendByte(I2C_ADR_R);
  //      timeout--;
    }
    while(!I2C_WaitAck());
    for(length=0;length<=3;length++)
    {
	Tdata[length]=I2C_ReceiveByte();
	I2C_Ack(); 		
    };
    I2C_NoAck();		
    I2C_Stop();		
    temperatureC= (-46.85 + (175.72/65536 )*((float)((((unsigned short int)Tdata[0]<<8)+(unsigned short int)Tdata[1])&0xfffc)));
    return temperatureC;
}


 /**
  * @file   SHT2x_Calc_RH
  * @brief  ����ʪ��
  * @param  NO
  * @retval ����ʪ��ֵ
  */
float SHT2x_Calc_RH(void)
{
	float humidityRH;
  //unsigned char timeout=30;
   unsigned char length=0;
   unsigned char RHdata[3]={0};
   I2C_Start();
   I2C_SendByte(I2C_ADR_W); 
   I2C_WaitAck();
   I2C_SendByte(TRIG_RH_MEASUREMENT_POLL);      
   I2C_WaitAck();
   delay_us(20);
   I2C_Stop();
    do
    {
    I2C_Start();
    I2C_SendByte(I2C_ADR_R);
   // timeout--;
    }
    while(!I2C_WaitAck());
    for(length=0;length<=3;length++)
    {
	RHdata[length]=I2C_ReceiveByte();
	I2C_Ack(); 		
    };
    I2C_NoAck();		
    I2C_Stop();	
    humidityRH = -6.0 + 125.0/65536 * ((float)((((unsigned short int)RHdata[0]<<8)+(unsigned short int)RHdata[1])&0xfff0)); 
    return humidityRH;
}
 /**
  * @file   SHT2x_SoftReset
  * @brief  �����λ
  * @param  NO
  * @retval NO
  */
FunctionalState SHT2x_SoftReset(void)
{
    if(!I2C_Start())return DISABLE;
    I2C_SendByte(0x80); 
    if(!I2C_WaitAck()){I2C_Stop(); return DISABLE;}
    I2C_SendByte(SOFT_RESET);       
    I2C_WaitAck();	  
    I2C_Stop(); 
    delay_ms(1500);
    return ENABLE;	
}



