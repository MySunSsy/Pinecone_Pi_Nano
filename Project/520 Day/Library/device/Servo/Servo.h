/**
  ******************************************************************************
  * @file    Servo.h
  * @author  PineconePi
  * @version V1.0.0
  * @date    20-December-2018
  * @brief  This file is used to control Servo
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
#ifndef _SERVO_H_
#define _SERVO_H_

#include "system.h"

#define Servo_Frequency 50 //50HZ ��20ms

/*PWMͨ��(���)*/
#define Servo_Channel1 0x00
#define Servo_Channel2 0x08
#define Servo_Channel3 0x10

/*������*/
#define Servo1 0
#define Servo2 1
#define Servo3 2
#define Servo4 3
#define Servo5 4
#define Servo6 5
#define Servo7 6
#define Servo8 7

//========================================================================
// �ṹ��:  Servo_Channelx
// ����: ��� ���ýṹ�塣
// ����: Servo_Channelx	(PWMͨ����	 ������Χ��1~3)
// 			 Servo_Angle		(����Ƕ�ֵ			 ������Χ��0~180 )
// ����: none.
// �汾: VER1.0.0
// ����: 2018-12-20
// ��ע: 
//
//========================================================================
typedef struct{ 
	unsigned char	Servo_Channelx;
	float Servo_Angle;
} Servo_InitTypeDef;

void Servo_Control(unsigned char Servo_Number,Servo_InitTypeDef *Servox);

#endif
