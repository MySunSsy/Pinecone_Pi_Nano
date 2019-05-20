/**
  ******************************************************************************
  * @file    exti.h
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
#ifndef	__EXTI_H
#define	__EXTI_H

#include	"system.h"

#define	EXT_INT0			0		//�ⲿ�ж�0
#define	EXT_INT1			2		//�ⲿ�ж�1
#define	EXT_INT2			10	//�ⲿ�ж�2
#define	EXT_INT3			11	//�ⲿ�ж�3
#define	EXT_INT4			16	//�ⲿ�ж�4

#define	EXT_MODE_RiseFall	0		//�������ж�
#define	EXT_MODE_Fall		1			//�½����ж�

#define ENABLE  	1			//�ж�����
#define DISABLE  	0			//�жϹر�

#define PolityHigh  1	  //�����ȼ�
#define PolityLow  	0		//�����ȼ���Ĭ�ϣ�

//========================================================================
// �ṹ��: EXTI_InitTypeDef
// ����: EXTI���ýṹ�塣
// ����: EXTI_Mode��EXT_MODE_RiseFall���������ж� ��EXT_MODE_Fall: �½����ж�)
//       EXTI_Polity(PolityHigh:�����ȼ� , PolityLow:�����ȼ���Ĭ�ϣ�)
//       EXTI_Interrupt(ENABLE:���� �� DISABLE����ʹ�ܣ�
// ����: none.
// �汾: VER1.0.0
// ����: 2018-12-20
// ��ע: ͨ�����²���ʹ��INT0
//	EXTI_InitTypeDef EXTI_InitTypeDef;
//	EXTI_InitTypeDef.EXTI_Mode = EXT_MODE_RiseFall;//�������ж�
//	EXTI_InitTypeDef.EXTI_Polity = PolityHigh;//�����ȼ�
//	EXTI_InitTypeDef.EXTI_Interrupt = ENABLE;//ʹ��
//	Ext_Inilize(EXT_INT0,&EXTI_InitTypeDef);//�������
//========================================================================
typedef struct
{
	unsigned char	EXTI_Mode;			//�ж�ģʽ,  	EXT_MODE_RiseFall, EXT_MODE_Fall
	unsigned char	EXTI_Polity;		//���ȼ�����	PolityHigh,PolityLow
	unsigned char	EXTI_Interrupt;		//�ж�����		ENABLE,DISABLE
} EXTI_InitTypeDef;

unsigned char	Ext_Inilize(unsigned char EXT, EXTI_InitTypeDef *INTx);

#endif
