/**
  ******************************************************************************
  * @file    gpio.h
  * @author  PineconePi
  * @version V1.0.0
  * @date    20-December-2018
  * @brief  This document is used for GPIO configuration
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
#ifndef	__GPIO_H_
#define	__GPIO_H_

#include	"system.h"

#define	GPIO_PullUp		0	//����׼˫���(Ĭ��)
#define	GPIO_HighZ		1	//��������
#define	GPIO_OUT_OD		2	//��©���
#define	GPIO_OUT_PP		3	//�������

#define	GPIO_Pin_0		0x01	//IO���� Px.0
#define	GPIO_Pin_1		0x02	//IO���� Px.1
#define	GPIO_Pin_2		0x04	//IO���� Px.2
#define	GPIO_Pin_3		0x08	//IO���� Px.3
#define	GPIO_Pin_4		0x10	//IO���� Px.4
#define	GPIO_Pin_5		0x20	//IO���� Px.5
#define	GPIO_Pin_6		0x40	//IO���� Px.6
#define	GPIO_Pin_7		0x80	//IO���� Px.7
#define	GPIO_Pin_All	0xFF	//IO��������
	
#define	GPIO_P0			0		
#define	GPIO_P1			1
#define	GPIO_P2			2
#define	GPIO_P3			3
#define	GPIO_P4			4
#define	GPIO_P5			5

//========================================================================
// �ṹ��: GPIO_InitTypeDef
// ����: GPIO���ýṹ�塣
// ����: Mode,IOģʽ��GPIO_PullUp������׼˫��� , GPIO_HighZ���������� , GPIO_OUT_OD����©��� , GPIO_OUT_PP���������
//			 Pin,�˿�,(GPIO_Pin_0 ��IO���� Px.0 ��PIO_Pin_1 ��IO���� Px.1 ��PIO_Pin_2 ��IO���� Px.2 ��PIO_Pin_3 ��IO���� Px.3 ��
// 			 PIO_Pin_4 ��IO���� Px.4 ��PIO_Pin_5 ��IO���� Px.5 ��PIO_Pin_6 ��IO���� Px.6 ��PIO_Pin_7 ��IO���� Px.7 ��
//			 PIO_Pin_All ��IO�������� 
// ����: none.
// �汾: VER1.0.0
// ����: 2018-12-20
// ��ע: ͨ�����²��轫P0^0����Ϊ����׼˫���
//       GPIO_InitTypeDef GPIO_InitTypeDef;
//			 GPIO_InitTypeDef.Mode = GPIO_PullUp;//����׼˫���
//       GPIO_InitTypeDef.Pin = GPIO_Pin_0|GPIO_Pin_1;//ͬʱ����IO���� Px.0��Px.1
//			 GPIO_Inilize(GPIO_P0 ,&GPIO_InitTypeDef);//IO���� P0.0
//========================================================================
typedef struct
{
	unsigned char	Mode;		//IOģʽ
	unsigned char	Pin;		//�˿�	
} GPIO_InitTypeDef;

unsigned char	GPIO_Inilize(unsigned char GPIO, GPIO_InitTypeDef *GPIOx);

#endif