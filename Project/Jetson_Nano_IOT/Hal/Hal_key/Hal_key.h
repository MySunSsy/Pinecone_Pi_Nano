#ifndef __HAL_KEY_H__
#define __HAL_KEY_H__
#include <stdint.h>
#include <intrins.h>
#define LONGPRESS 4				//���峤�����ü���ʱ��	
sbit	SETKEY = P0^0;			//K2,�๦�ܰ���(�̰�,����)

void delay1ms(unsigned char ms);//��ʱ����
void setkeyscan();				//���ü���ɨ���жϺ���
void pro_sklp();				//�������ù��ܼ��Ĵ�����
void pro_sksp();				//�̰����ù��ܼ��Ĵ�����

#endif