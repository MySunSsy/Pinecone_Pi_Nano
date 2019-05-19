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
 //One NOP 41.6666667 ns (1T: 1 machine cycle = 1 clock cycle)|һ�� nop 41.6666667 ns	(1T��1����������=1��ʱ�����ڣ�
unsigned char data_red[n_ws2812b] = {0};//Common mode color buffer|��ͨģʽ��ɫ����
unsigned char data_green[n_ws2812b] = {0};
unsigned char data_blue[n_ws2812b] = {0};

unsigned char data_rollred[n_ws2812b+1] = {0};//Roll mode color cache|rollģʽ��ɫ����
unsigned char data_rollgreen[n_ws2812b+1] = {0};
unsigned char data_rollblue[n_ws2812b+1] = {0};
//========================================================================
// Function:void Delay50us()|����: void Delay50us()
// Description:Reset delay.|����: ��λ�ӳ١�
// Parameter: none.|����: none.
// Return: none.|����: none.
// Version:VER1.0.0|�汾: VER1.0.0
// Date: 2018-12-20|����: 2018-12-20
// Note:|��ע: 
//========================================================================
void Delay50us()		//Reset delay|��λ�ӳ�
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
// Function:void delay_ms(unsigned int ms)|����: void delay_ms(unsigned int ms)
// Description:Delay function.|����: ��ʱ������
// Parameter: ms, the number of MS to be delayed, where only 1-10000 (10s) MS is supported
// ����: ms,Ҫ��ʱ��ms��, ����ֻ֧��1~10000 (10s) ms
// Return: none.|����: none.
// Version:VER1.0.0|�汾: VER1.0.0
// Date: 2018-12-20|����: 2018-12-20
// Note: delay_ms (1000); //delay 1s|��ע: delay_ms(1000);//�ӳ�1s
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
// Function:void rgb_high()|����: void rgb_high()
// Description:|����: 1 yard, 850ns high level, 400ns low level (error plus or minus 150ns)
// Parameter:|����: 
// Return: none.|����: none.
// Version:VER1.0.0|�汾: VER1.0.0
// Date: 2018-12-20|����: 2018-12-20
// Note:|��ע: 
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
// Function:void rgb_down()|����: void rgb_down()
// Description: 0 yard, 400 ns high level, 850 ns low level (error plus or minus 150 ns)|����: 0�룬�ߵ�ƽ400ns �͵�ƽ850ns ���������150ns��
// Parameter:|����: 
// Return: none.|����: none.
// Version:VER1.0.0|�汾: VER1.0.0
// Date: 2018-12-20|����: 2018-12-20
// Note:|��ע: 
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
// Function:void rgb_reset()|����: void rgb_reset()
// Description:Reset WS2812B and start a new command|����: ��λWS2812B����ʼһ���µ�����
// Parameter:|����: 
// Return: none.|����: none.
// Version:VER1.0.0|�汾: VER1.0.0
// Date: 2018-12-20|����: 2018-12-20
// Note:|��ע: 
//========================================================================
void rgb_reset()
{
 rgb_pin = 0;
 Delay50us();
}
//========================================================================
// Function:void ws2812b_display(unsigned char green,unsigned char red,unsigned char blue)|����: void ws2812b_display(unsigned char green,unsigned char red,unsigned char blue)
// Description:Single ws2812b control|����: ����ws2812b����
// Parameters: green: green 0-255, red: red 0-255, blue: blue 0-255,|����:  green����ɫ 0-255��red����ɫ 0-255 ��blue����ɫ 0-255��
// Return: none.|����: none.
// Version:VER1.0.0|�汾: VER1.0.0
// Date: 2018-12-20|����: 2018-12-20
// Note:|��ע: 
//========================================================================
void ws2812b_display(unsigned char green,unsigned char red,unsigned char blue)

{
	  unsigned int n = 0;
	  //Sending green bits|����greenλ
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

		//Sending red bits|����redλ
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
		//Sending blue bits|����blueλ
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
// Function:void n_ws2812b_display(unsigned char display_mode,unsigned char green,unsigned char red,unsigned char blue)|����: void n_ws2812b_display(unsigned char display_mode,unsigned char green,unsigned char red,unsigned char blue)
// Description:n��ws2812b����(nȡ����n_ws2812b)|����: n��ws2812b����(nȡ����n_ws2812b)
// Parameters:Display_mode: Mode selection. See ws2812b.h for details on defining green: 0-255 green, red: 0-255 red, blue: 0-255 blue.
// ����: display_mode:ģʽѡ�������ws2812b.h�ж��� green����ɫ 0-255��red����ɫ 0-255 ��blue����ɫ 0-255��
// Return: none.|����: none.
// Version:VER1.0.0|�汾: VER1.0.0
// Date: 2018-12-20|����: 2018-12-20
// Note:|��ע: 
//========================================================================
void n_ws2812b_display(unsigned char display_mode,unsigned char green,unsigned char red,unsigned char blue)
{
	 unsigned char j ;
	 unsigned char i ;
	 unsigned char roll_i = 0;	 //Consequent flow|˳����ˮ
	 unsigned char rollback_i = 1;	 //Reverse flow|������ˮ

/********************* General mode control correlation|��ͨģʽ������� *************************/
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
/********************* Control correlation of forward flow pattern|������ˮģʽ������� *************************/
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

/********************* Reverse Pipeline Mode Control Relevance|������ˮģʽ������� *************************/
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
/********************* Reverse Interval Pipeline Mode Control Relevance|��������ˮģʽ������� *************************/
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
/********************* Respiratory lamp mode control correlation|������ģʽ������� *************************/
		else if ( display_mode == breathe)
		{
		//δ�����
        }
}



