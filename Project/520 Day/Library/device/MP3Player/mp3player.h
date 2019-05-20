/**
  ******************************************************************************
  * @file    mp3player.h
  * @author  PineconePi
  * @version V1.0.0
  * @date    20-December-2018
  * @brief  This article will be used for  driving  MP3 Player.
  * @License:GNU General Public License v3.0         
  ******************************************************************************
  * @attention
  *	include library/system/uart uart.c & uaet.h
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
#ifndef _MP3PLAYER_H_
#define _MP3PLAYER_H_

#include "system.h"

#define CMD_Lastsong 0x01
#define CMD_Nextsong 0x02
#define CMD_Songnum 0x03
#define CMD_Volume_up 0x04
#define CMD_Volume_down 0x05
#define CMD_Volume 0x06
#define CMD_EQ 0x07
#define CMD_Songnum_Loop 0x08 //ָ������ѭ��
#define CMD_PlayDevice 0x09
#define CMD_Sleep 0x0A
#define CMD_1 0x0B
#define CMD_Reset 0x0C
#define CMD_Play 0x0D
#define CMD_Pause 0x0E
#define CMD_Foldernum 0x0F
#define CMD_BigSound 0x10

#define CMD_AllLoop 0x11
#define CMD_FolderSongnum 0x12
#define CMD_PlayAD 0x13
#define CMD_Stop 0x16
#define CMD_LoopPlay 0x19 //ȫ��ѭ������


#define ENABLE 1	 //������
#define DISABLE 0	 //�رշ���
void Mp3_Init();  //��ʼ��MP3
void SendCMD(unsigned char CMD ,unsigned char feedback , unsigned int dat);  //���Ϳ�������

#endif