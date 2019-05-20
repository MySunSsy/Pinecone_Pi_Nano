/**
  ******************************************************************************
  * @file    ws2812b.c
  * @author  PineconePi
  * @version V1.0.0
  * @date    20-December-2018
  * @brief  This article will be used for  driving  ws2812b.
  * @License:GNU General Public License v3.0         
  ******************************************************************************
  * @attention
  *	The frequency of crystal oscillator is 24 Mhz
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
#include "ws2812b.h"
#include "intrins.h"
 //һ�� nop 41.6666667 ns	(1T��1����������=1��ʱ�����ڣ�
unsigned char data_red[n_ws2812b] = {0};//��ͨģʽ��ɫ����
unsigned char data_green[n_ws2812b] = {0};
unsigned char data_blue[n_ws2812b] = {0};

unsigned char data_rollred[n_ws2812b+1] = {0};//rollģʽ��ɫ����
unsigned char data_rollgreen[n_ws2812b+1] = {0};
unsigned char data_rollblue[n_ws2812b+1] = {0};
//========================================================================
// ����: void Delay50us()
// ����: ��λ�ӳ١�
// ����: none.
// ����: none.
// �汾: VER1.0.0
// ����: 2018-12-20
// ��ע: 
//========================================================================
void Delay50us()		//��λ�ӳ�
{
	unsigned char i, j;

	_nop_();
	i = 2;
	j = 140;
	do
	{
		while (--j);
	} while (--i);
}
//========================================================================
// ����: void delay_ms(unsigned int ms)
// ����: ��ʱ������
// ����: ms,Ҫ��ʱ��ms��, ����ֻ֧��1~10000 (10s) ms
// ����: none.
// �汾: VER1.0.0
// ����: 2018-12-20
// ��ע: delay_ms(1000);//�ӳ�1s
//========================================================================
void delay_ms_2812b(unsigned int ms){
  unsigned int k;
	unsigned char i, j;
	for(k=0;k<ms;k++)
	{
	_nop_();
	i = 32;
	j = 40;
		do
		{
		  while (--j);
		} while (--i);
	}
	}
//========================================================================
// ����: void rgb_high()
// ����: 1�룬�ߵ�ƽ850ns �͵�ƽ400ns ���������150ns��
// ����: 
// ����: none.
// �汾: VER1.0.0
// ����: 2018-12-20
// ��ע: 
//========================================================================													   
void rgb_high()
{
	 rgb_pin = 1;
	 _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();  
	 _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();   
     rgb_pin = 0;
	 _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
}
//========================================================================
// ����: void rgb_down()
// ����: 0�룬�ߵ�ƽ400ns �͵�ƽ850ns ���������150ns��
// ����: 
// ����: none.
// �汾: VER1.0.0
// ����: 2018-12-20
// ��ע: 
//========================================================================
void rgb_down()
{
	 rgb_pin = 1;
	 _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();    

	 rgb_pin = 0;
	 _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();  
	 _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();  
}
//========================================================================
// ����: void rgb_reset()
// ����: ��λWS2812B����ʼһ���µ�����
// ����: 
// ����: none.
// �汾: VER1.0.0
// ����: 2018-12-20
// ��ע: 
//========================================================================
void rgb_reset()
{
 rgb_pin = 0;
 Delay50us();
}
//========================================================================
// ����: void ws2812b_display(unsigned char green,unsigned char red,unsigned char blue)
// ����: ����ws2812b����
// ����:  green����ɫ 0-255��red����ɫ 0-255 ��blue����ɫ 0-255��
// ����: none.
// �汾: VER1.0.0
// ����: 2018-12-20
// ��ע: 
//========================================================================
void ws2812b_display(unsigned char green,unsigned char red,unsigned char blue)

{
	  unsigned int n = 0;
	  //����greenλ
		for(n=0;n<8;n++)
		{
			green<<=n;
			if(green&0x80 == 0x80)
			{
				rgb_high();
			}
			else  
			{
			  rgb_down();
			}
		}

		//����redλ
		for(n=0;n<8;n++)
		{
			red<<=n;
			if(red&0x80 == 0x80)
			{
				rgb_high();
			}
			else  
			{
				rgb_down();
			}		
		}
		//����blueλ
	  for(n=0;n<8;n++)
		{
			blue<<=n;
			if(blue&0x80 == 0x80)
			{
				rgb_high();
			}
			else  
			{
			  rgb_down();
			}
		}
}
//========================================================================
// ����: void n_ws2812b_display(unsigned char display_mode,unsigned char green,unsigned char red,unsigned char blue)
// ����: n��ws2812b����(nȡ����n_ws2812b)
// ����: display_mode:ģʽѡ�������ws2812b.h�ж��� green����ɫ 0-255��red����ɫ 0-255 ��blue����ɫ 0-255��
// ����: none.
// �汾: VER1.0.0
// ����: 2018-12-20
// ��ע: 
//========================================================================
void n_ws2812b_display(unsigned char display_mode,unsigned char green,unsigned char red,unsigned char blue)
{
	 unsigned char j ;
	 unsigned char i ;
	 unsigned char roll_i = 0;	 //˳����ˮ
	 unsigned char rollback_i = 1;	 //������ˮ

/********************* ��ͨģʽ������� *************************/
	  if( display_mode == normal)
	  {
	  delay_ms_2812b(1);
		for(i=0;i<n_ws2812b;i++)
	  {
			  data_green[i] = green;
			  data_red[i] = red; 
			  data_blue[i] = blue;
		}
		for(i=0;i<n_ws2812b;i++)
		{
		ws2812b_display(data_green[i],data_red[i],data_blue[i]);
		}
		}
/********************* ������ˮģʽ������� *************************/
		else if( display_mode == roll)
		{
		delay_ms_2812b(1);
		for(i=0;i<=n_ws2812b;i++)
	    {
			  data_rollgreen[i] = green;
			  data_rollred[i] = red; 
			  data_rollblue[i] = blue;
		}

		for(i=0;i<=n_ws2812b;i++)
		{
		ws2812b_display(data_rollgreen[i],data_rollred[i],data_rollblue[i]);
		delay_ms_2812b(roll_delay);
		rgb_reset();
		for(i=0;i<roll_i;i++)
		{
		ws2812b_display(0,0,0);
		}
		roll_i++;
		}
		}

/********************* ������ˮģʽ������� *************************/
		else if ( display_mode ==  roll_back_1)
		{
		 delay_ms_2812b(1);
				for(i=0;i<=n_ws2812b;i++)
	    {
			  data_rollgreen[i] = green;
			  data_rollred[i] = red; 
			  data_rollblue[i] = blue;
		}

		for(j=0;j<n_ws2812b;j++)
		{
		  for(i=(n_ws2812b-rollback_i);i>0;i--)
		  {
			ws2812b_display(0,0,0);
		  }
		  ws2812b_display(data_rollgreen[i],data_rollred[i],data_rollblue[i]);
		  delay_ms_2812b(roll_delay);
		  rollback_i++;
		  if(rollback_i>n_ws2812b){rollback_i=1;}
        }
	 delay_ms_2812b(1);	 
	 n_ws2812b_display(normal,0x00,0x00,0x00);
}
/********************* ��������ˮģʽ������� *************************/
		else if ( display_mode ==  roll_back_2)
		{
		 delay_ms_2812b(1);
				for(i=0;i<=n_ws2812b;i++)
	    {
			  data_rollgreen[i] = green;
			  data_rollred[i] = red; 
			  data_rollblue[i] = blue;
		}

		for(j=n_ws2812b;j>0;j--)
		{
		  for(i=(n_ws2812b-rollback_i);i>0;i--)
		  {
			ws2812b_display(0,0,0);
		  }
		  ws2812b_display(data_rollgreen[i],data_rollred[i],data_rollblue[i]);
		  delay_ms_2812b(roll_delay);
		  rollback_i++;
		  for(i=(n_ws2812b-rollback_i+1);i>0;i--)
		  {
			ws2812b_display(0,0,0);
		  }
		  if(rollback_i>n_ws2812b){rollback_i=1;}
        }
	 delay_ms_2812b(1);	 
		for(i=0;i<clear_ws2812b;i++)
		{
		ws2812b_display(0,0,0);
		}
        }
/********************* ������ģʽ������� *************************/
		else if ( display_mode == breathe)
		{
		//δ�����
        }
}



