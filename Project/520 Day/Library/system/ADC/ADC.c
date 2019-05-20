/**
  ******************************************************************************
  * @file    adc.h
  * @author  PineconePi
  * @version V1.0.0
  * @date    20-December-2018
  * @brief  This file is used to configure ADC
  * @License:GNU General Public License v3.0         
  ******************************************************************************
  * @attention
  *
  *
  *  
  * 
  * 
  * 
  * 
  *
  * 
  ******************************************************************************
	**/
	
#include	"adc.h"
#include "intrins.h"

/********************* ADC�жϺ���************************/
void ADC_int (void) interrupt 5
{
	ADC_CONTR &= ~ADC_FLAG;
}
//========================================================================
// ����: void	ADC_Inilize(ADC_InitTypeDef *ADCx)
// ����: ADC��ʼ������.
// ����: ��ο�adc.h����Ľṹ�嶨��
//       
//       
// ����: 
// �汾: VER1.0.0
// ����: 2018-12-20
// ����: PineconePi
// ��ע:
//	
//	
//	
//	
//	
//========================================================================
void	ADC_Inilize(ADC_InitTypeDef *ADCx)
{
	P1M0 = 0x00;
	P1M1 |= ADCx->ADC_Px;
	ADC_CONTR = (ADC_CONTR & ~ADC_90T) | ADCx->ADC_Speed;
	if(ADCx->ADC_Power == ENABLE)	ADC_CONTR |= 0x80;
	else							ADC_CONTR &= 0x7F;
	if(ADCx->ADC_AdjResult == ADC_RES_H2L8)	ADCCFG |=  (1<<5);	//10λAD����ĸ�2λ��ADC_RES�ĵ�2λ����8λ��ADC_RESL��
	else									ADCCFG &= ~(1<<5);	//10λAD����ĸ�8λ��ADC_RES����2λ��ADC_RESL�ĵ�2λ��
	if(ADCx->ADC_Interrupt == ENABLE)	EADC = 1;			//�ж�����		ENABLE,DISABLE
	else								EADC = 0;
	if(ADCx->ADC_Polity == PolityHigh)	PADC = 1;		//���ȼ�����	PolityHigh,PolityLow
	else								PADC = 0;
}


//========================================================================
// ����: void	ADC_PowerControl(unsigned char pwr)
// ����: ADC��Դ���Ƴ���.
// ����: pwr: ��Դ����,ENABLE��DISABLE.
//       
//       
// ����: 
// �汾: VER1.0.0
// ����: 2018-12-20
// ����: PineconePi
// ��ע:
//	
//	
//	
//	
//	
//========================================================================
void	ADC_PowerControl(unsigned char pwr)
{
	if(pwr == ENABLE)	ADC_CONTR |= 0x80;
	else				ADC_CONTR &= 0x7f;
}

//========================================================================
// ����: unsigned int	Get_ADC10bitResult(unsigned char channel)
// ����: ��ѯһ��ADC���.
// ����: channel: ѡ��Ҫת����ADC.
//       
//       
// ����: ADC���.
// �汾: VER1.0.0
// ����: 2018-12-20
// ����: PineconePi
// ��ע:
//	
//	
//	
//	
//	
//========================================================================
unsigned int	Get_ADC10bitResult(unsigned char channel)	//channel = 0~7
{
	unsigned int	adc;
	unsigned char	i;

	if(channel > ADC_CH7)	return	1024;	//����,����1024,���õĳ����ж�	
	ADC_RES = 0;
	ADC_RESL = 0;

	ADC_CONTR = (ADC_CONTR & 0xe0) | ADC_START | channel; 
	_nop_();	
  _nop_();	//��ADC_CONTR������Ҫ2T֮����ܷ���

	for(i=0; i<250; i++)		//��ʱ
	{
		if(ADC_CONTR & ADC_FLAG)
		{
			ADC_CONTR &= ~ADC_FLAG;
			if(ADCCFG &  (1<<5))		//10λAD����ĸ�2λ��ADC_RES�ĵ�2λ����8λ��ADC_RESL��
			{
				adc = (unsigned int)(ADC_RES & 3);
				adc = (adc << 8) | ADC_RESL;
			}
			else		//10λAD����ĸ�8λ��ADC_RES����2λ��ADC_RESL�ĵ�2λ��
			{
				adc = (unsigned int)ADC_RES;
				adc = (adc << 2) | (ADC_RESL & 3);
			}
			return	adc;
		}
	}
	return	1024;	//����,����1024,���õĳ����ж�
}

