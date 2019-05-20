/**
  ******************************************************************************
  * @file    uart.h
  * @author  PineconePi
  * @version V1.0.0
  * @date    20-December-2018
  * @brief  This file is used to configure the serial port 
  * @License:GNU General Public License v3.0         
  ******************************************************************************
  * @attention
  *
  *Serial Interrupt Processing Function in uart.c 
  *  
  * 
  * 
  * 
  * 
  *
  * 
  ******************************************************************************
	**/
#ifndef __UART_H
#define __UART_H	 

#include	"system.h"

#define	COM_TX1_Lenth	128
#define	COM_RX1_Lenth	128
#define	COM_TX2_Lenth	128
#define	COM_RX2_Lenth	128

#define	USART1	1
#define	USART2	2

#define	UART_ShiftRight	0		//ͬ����λ���
#define	UART_8bit_BRTx	(1<<6)	//8λ����,�ɱ䲨����
#define	UART_9bit		(2<<6)	//9λ����,�̶�������
#define	UART_9bit_BRTx	(3<<6)	//9λ����,�ɱ䲨����

#define	UART1_SW_P30_P31	0
#define	UART1_SW_P36_P37	(1<<6)
#define	UART1_SW_P16_P17	(2<<6)	//����ʹ���ڲ�ʱ��
#define	UART2_SW_P10_P11	0
#define	UART2_SW_P46_P47	1


#define	TimeOutSet1		5
#define	TimeOutSet2		5

#define	BRT_Timer1	1
#define	BRT_Timer2	2

#define ENABLE  	1			//����
#define DISABLE  	0			//�ر�

#define PolityHigh  1	  //�����ȼ�
#define PolityLow  	0		//�����ȼ���Ĭ�ϣ�

typedef struct
{ 
	unsigned char	id;				//���ں�

	unsigned char	TX_read;		//���Ͷ�ָ��
	unsigned char	TX_write;		//����дָ��
	unsigned char	B_TX_busy;		//æ��־

	unsigned char 	RX_Cnt;			//�����ֽڼ���
	unsigned char	RX_TimeOut;		//���ճ�ʱ
	unsigned char	B_RX_OK;		//���տ����
} COMx_Define; 

typedef struct
{ 
	unsigned char	UART_Mode;			//ģʽ,         UART_ShiftRight,UART_8bit_BRTx,UART_9bit,UART_9bit_BRTx
	unsigned char	UART_BRT_Use;		//ʹ�ò�����,   BRT_Timer1,BRT_Timer2
	unsigned long	UART_BaudRate;		//������,       ENABLE,DISABLE
	unsigned char	Morecommunicate;	//���ͨѶ����, ENABLE,DISABLE
	unsigned char	UART_RxEnable;		//�������,   ENABLE,DISABLE
	unsigned char	BaudRateDouble;		//�����ʼӱ�, ENABLE,DISABLE
	unsigned char	UART_Interrupt;		//�жϿ���,   ENABLE,DISABLE
	unsigned char	UART_Polity;		//���ȼ�,     PolityLow,PolityHigh
	unsigned char	UART_P_SW;			//�л��˿�,   UART1_SW_P30_P31,UART1_SW_P36_P37,UART1_SW_P16_P17(����ʹ���ڲ�ʱ��)
} COMx_InitDefine; 

extern	COMx_Define	COM1,COM2;
extern	unsigned char	xdata TX1_Buffer[COM_TX1_Lenth];	//���ͻ���
extern	unsigned char 	xdata RX1_Buffer[COM_RX1_Lenth];	//���ջ���
extern	unsigned char	xdata TX2_Buffer[COM_TX2_Lenth];	//���ͻ���
extern	unsigned char 	xdata RX2_Buffer[COM_RX2_Lenth];	//���ջ���

unsigned char	USART_Configuration(unsigned char UARTx, COMx_InitDefine *COMx);
void TX1_write2buff(unsigned char dat);	//д�뷢�ͻ��壬ָ��+1
void TX2_write2buff(unsigned char dat);	//д�뷢�ͻ��壬ָ��+1
void PrintString1(unsigned char *puts);
void PrintString2(unsigned char *puts);


#endif

