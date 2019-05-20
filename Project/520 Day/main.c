#include "system.h"
#include  "adc.h"
#include  "delay.h"
#include  "eeprom.h"
#include  "exti.h"
#include  "gpio.h"
#include  "iic.h"
#include  "pca.h"
#include  "pwm.h"
#include  "timer.h"
#include  "uart.h"
#include  "watchdog.h"

#include  "digitaltube.h"
#include  "hc_sr04.h"
#include  "mp3player.h"
#include  "servo.h"
#include  "ws2812b.h"
#include  "stdio.h"
unsigned char ILY_1[3]={5,2,0};//�����520
unsigned char ILY_2[3]={0x20,0x02,0x01};//8·LED��520
unsigned char ILY_3[3]={0x35,0x32,0x30};//ASCLL��520
char something_1[]={"You are beautiful!\r\n"};
char something_2[]={"If you love me,please let me know!\r\n"};
sbit key_2=P3^2;
sbit key_3=P3^3;
sbit key_4=P3^6;
sbit key_5=P3^7;
sbit led_en=P5^5;
unsigned char key2;
unsigned char key3;
unsigned char key4;
unsigned char key5;
unsigned char i;
void UartInit(void)		//520bps@24.000MHz
{
	SCON = 0x50;		//8λ����,�ɱ䲨����
	AUXR |= 0x40;		//��ʱ��1ʱ��ΪFosc,��1T
	AUXR &= 0xFE;		//����1ѡ��ʱ��1Ϊ�����ʷ�����
	TMOD &= 0x0F;		//�趨��ʱ��1Ϊ16λ�Զ���װ��ʽ
	TL1 = 0xEE;		//�趨��ʱ��ֵ
	TH1 = 0xD2;		//�趨��ʱ��ֵ
	ET1 = 0;		//��ֹ��ʱ��1�ж�
	TR1 = 1;		//������ʱ��1
}

void key_handle()
{
			if(key_2 == 0)
		{
			delay_ms(100);
			if(key_2 == 0)
			{
				Digitaltube_Enable(SMG1,ENABLE);
        Digitaltube_Enable(SMG2,ENABLE);
				led_en=1;
				Digitaltube_Display(DISABLE,ILY_1[key2]);
				key2++;
			if(key2 > 2)key2=0;
			}
		}
		if(key_3 == 0)
		{
			delay_ms(100);
			if(key_3 == 0)
			{
				Digitaltube_Enable(SMG1,DISABLE);
        Digitaltube_Enable(SMG2,DISABLE);
				led_en=0;
				P1=~ILY_2[key3];
				ES = 1;                                    
        EA = 1;
        SBUF = ILY_3[key3];                                
				while(!TI);
				TI=0;
				key3++;
			if(key3 > 2){key3=0;SBUF = 0x7c;while(!TI);TI=0;}
			}
		}
		if(key_4 == 0)
		{
			delay_ms(100);
			if(key_4 == 0)
			{
				Digitaltube_Enable(SMG1,DISABLE);
        Digitaltube_Enable(SMG2,DISABLE);
				led_en=1;
				ES = 1;                                    
        EA = 1;
				for(i=0;i<sizeof(something_1);i++)
				{
        SBUF = something_1[i];                                
				while(!TI);
				TI=0;
				}
			}
		}
		if(key_5 == 0)
		{
			delay_ms(100);
			if(key_5 == 0)
			{
				Digitaltube_Enable(SMG1,DISABLE);
        Digitaltube_Enable(SMG2,DISABLE);
				led_en=1;
				ES = 1;                                    
        EA = 1;
				for(i=0;i<sizeof(something_2);i++)
				{
        SBUF = something_2[i];                                
				while(!TI);
				TI=0;
				}
			}
		}
}

void main()
{
	UartInit();
	while(1)
	{
		key_handle();
	}
}
