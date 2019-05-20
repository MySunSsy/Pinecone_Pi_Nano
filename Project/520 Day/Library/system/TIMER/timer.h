/**
  ******************************************************************************
  * @file    timer.h
  * @author  PineconePi
  * @version V1.0.0
  * @date    20-December-2018
  * @brief  This document is used for timer configuration 
  * @License:GNU General Public License v3.0         
  ******************************************************************************
  * @attention
  *
  *Timer Interrupt Processing Function in timer.c
  *  
  * 
  * 
  * 
  * 
  *
  * 
  ******************************************************************************
	**/
#ifndef	__TIMER_H
#define	__TIMER_H

#include	"system.h"

#define	Timer0						0
#define	Timer1						1
#define	Timer2						2
#define	Timer3						3
#define	Timer4						4

#define	TIM_16BitAutoReload			0
#define	TIM_16Bit					1
#define	TIM_8BitAutoReload			2
#define	TIM_16BitAutoReloadNoMask	3

#define	TIM_CLOCK_1T				0
#define	TIM_CLOCK_12T				1
#define	TIM_CLOCK_Ext				2

#define ENABLE  	1			//����
#define DISABLE  	0			//�ر�

#define PolityHigh  1	  //�����ȼ�
#define PolityLow  	0		//�����ȼ���Ĭ�ϣ�

typedef struct
{
	unsigned char	TIM_Mode;		//����ģʽ,  	TIM_16BitAutoReload,TIM_16Bit,TIM_8BitAutoReload,TIM_16BitAutoReloadNoMask
	unsigned char	TIM_Polity;		//���ȼ�����	PolityHigh,PolityLow
	unsigned char	TIM_Interrupt;	//�ж�����		ENABLE,DISABLE
	unsigned char	TIM_ClkSource;	//ʱ��Դ		TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
	unsigned char	TIM_ClkOut;		//�ɱ��ʱ�����,	ENABLE,DISABLE
	unsigned int	TIM_Value;		//װ�س�ֵ
	unsigned char	TIM_Run;		//�Ƿ�����		ENABLE,DISABLE
} TIM_InitTypeDef;

unsigned char	Timer_Inilize(unsigned char TIM, TIM_InitTypeDef *TIMx);

#endif
