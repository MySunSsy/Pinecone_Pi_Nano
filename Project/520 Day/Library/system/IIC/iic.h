/**
  ******************************************************************************
  * @file    iic.h
  * @author  PineconePi
  * @version V1.0.0
  * @date    20-December-2018
  * @brief  This file is used to Configure hardware IIC 
  * @License:GNU General Public License v3.0         
  ******************************************************************************
  * @attention
  *To operate IIC-related registers in host mode, P_SW2 = 0x80 is required. 
  *After  settings are completed, you must P_SW2 = 0x00
  *The sample program is at the end of the file iic.c
  *  
  * 
  * 
  * 
  * 
  *
  * 
  ******************************************************************************
	**/
	/********************* ʾ��������iic.c�ļ�ĩβ************************/
#ifndef _IIC_H_
#define _IIC_H_

#include "system.h"


#define host_machine 0  //����ģʽ
#define Slave_machine 1 //�ӻ�ģʽ

#define IIC_Slave_machine_address 0x5a //�ӻ��豸��ַΪ5A

 void IIC_host_Slave_machine(unsigned char host_Slave_machine);//����IICģʽ������ģʽ���ӻ�ģʽ��
 void handle_Slave_machine();//�ӻ�ģʽ������
 /********************* IIC����ģʽ��ش�����************************/
 void Wait();
 void Start();
 void SendData(char dat);
 void RecvACK();
 char RecvData();
 void SendACK();
 void SendNAK();
 void Stop();
 void wait_device();
#endif