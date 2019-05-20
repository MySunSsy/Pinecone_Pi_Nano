/**
  ******************************************************************************
  * @file    exti.c
  * @author  PineconePi
  * @version V1.0.0
  * @date    20-December-2018
  * @brief  This file is used for external interrupt configuration
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
  ******************************************************************************
	**/


#include "exti.h"



/********************* INT0�жϺ��� *************************/
void Ext_INT0 (void) interrupt EXT_INT0		//���ж�ʱ�Ѿ������־
{
	//�˴�����û��߼�
}

/********************* INT1�жϺ��� *************************/
void Ext_INT1 (void) interrupt EXT_INT1		//���ж�ʱ�Ѿ������־
{
	//�˴�����û��߼�
}

/********************* INT2�жϺ��� *************************/
void Ext_INT2 (void) interrupt EXT_INT2	//
{
	//�˴�����û��߼�
}

/********************* INT3�жϺ��� *************************/
void Ext_INT3 (void) interrupt EXT_INT3
{
	//�˴�����û��߼�
}

/********************* INT4�жϺ��� *************************/
void Ext_INT4 (void) interrupt EXT_INT4
{
	//�˴�����û��߼�
}

//========================================================================
// ����: unsigned char Ext_Inilize(unsigned char EXT, EXTI_InitTypeDef *INTx)
// ����: �ⲿ�жϳ�ʼ������.
// ����: EXT,�ж���ţ�EXT_INT0���ⲿ�ж�0 , EXT_INT1���ⲿ�ж�1 , EXT_INT2���ⲿ�ж�2 , 
//       EXT_INT3���ⲿ�ж�3 �� EXT_INT4���ⲿ�ж�4
//       INTx: �ṹ����,��ο�Exti.h��Ķ���.
// ����: �ɹ�����0, �ղ�������1,���󷵻�2.
// �汾: VER1.0.0
// ����: 2018-12-20
// ��ע: ͨ�����²���ʹ��INT0
//	EXTI_InitTypeDef EXTI_InitTypeDef;
//	EXTI_InitTypeDef.EXTI_Mode = EXT_MODE_RiseFall;//�������ж�
//	EXTI_InitTypeDef.EXTI_Polity = PolityHigh;//�����ȼ�
//	EXTI_InitTypeDef.EXTI_Interrupt = ENABLE;//ʹ��
//	Ext_Inilize(EXT_INT0,&EXTI_InitTypeDef);//�������
//========================================================================
unsigned char Ext_Inilize(unsigned char EXT, EXTI_InitTypeDef *INTx)
{
	if(EXT >  EXT_INT4)	return 1;	//�ղ���
	
	if(EXT == EXT_INT0)	//���ж�0
	{
		if(INTx->EXTI_Interrupt == ENABLE)		EX0 = 1;	//�����ж�
		else									EX0 = 0;	//��ֹ�ж�
		if(INTx->EXTI_Polity == PolityHigh)		PX0 = 1;	//�����ȼ��ж�
		else									PX0 = 0;	//�����ȼ��ж�
		if(INTx->EXTI_Mode == EXT_MODE_Fall)	IT0 = 1;	//�½����ж�
		else									IT0 = 0;	//����,�½����ж�
		return	0;		//�ɹ�
	}

	if(EXT == EXT_INT1)	//���ж�1
	{
		if(INTx->EXTI_Interrupt == ENABLE)		EX1 = 1;	//�����ж�
		else									EX1 = 0;	//��ֹ�ж�
		if(INTx->EXTI_Polity == PolityHigh)		PX1 = 1;	//�����ȼ��ж�
		else									PX1 = 0;	//�����ȼ��ж�
		if(INTx->EXTI_Mode == EXT_MODE_Fall)	IT1 = 1;	//�½����ж�
		else									IT1 = 0;	//����,�½����ж�
		return	0;		//�ɹ�
	}

	if(EXT == EXT_INT2)		//���ж�2, �̶�Ϊ�½��ص����ȼ��ж�
	{
		if(INTx->EXTI_Interrupt == ENABLE)	INTCLKO |=  (1 << 4);	//�����ж�	
		else								INTCLKO &= ~(1 << 4);	//��ֹ�ж�
		return	0;		//�ɹ�
	}

	if(EXT == EXT_INT3)		//���ж�3, �̶�Ϊ�½��ص����ȼ��ж�
	{
		if(INTx->EXTI_Interrupt == ENABLE)	INTCLKO |=  (1 << 5);	//�����ж�	
		else								INTCLKO &= ~(1 << 5);	//��ֹ�ж�
		return	0;		//�ɹ�
	}

	if(EXT == EXT_INT4)		//���ж�4, �̶�Ϊ�½��ص����ȼ��ж�
	{
		if(INTx->EXTI_Interrupt == ENABLE)	INTCLKO |=  (1 << 6);	//�����ж�	
		else								INTCLKO &= ~(1 << 6);	//��ֹ�ж�
		return	0;		//�ɹ�
	}
	return 2;	//ʧ��
}