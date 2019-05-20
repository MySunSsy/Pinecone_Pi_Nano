/**
  ******************************************************************************
  * @file    iic.c
  * @author  PineconePi
  * @version V1.0.0
  * @date    20-December-2018
  * @brief  This file is used to Configure hardware IIC 
  * @License:GNU General Public License v3.0         
  ******************************************************************************
  * @attention
  *To operate IIC-related registers in host mode, P_SW2 = 0x80 is required. 
  *After  settings are completed, you must P_SW2 = 0x00
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
	/********************* ʾ��������iic.c�ļ�ĩβ************************/
	
#include "iic.h"
#include "intrins.h"
/********************* IIC�˿���************************/
sbit    SDA         =   P1^4;
sbit    SCL         =   P1^5;
/********************* IIC�ӻ�ģʽ��ر���************************/
bit isda;                                       //�豸��ַ��־
bit isma;                                       //�洢��ַ��־
unsigned char addr;
unsigned char pdata buffer[256];
//========================================================================
// ����: void IIC_host_Slave_machine(unsigned char host_Slave_machine)
// ����: ����IICģʽ��
// ����: host_Slave_machine������ģʽ��ӻ�ģʽ
//       
//       
// ����: 
// �汾: VER1.0.0
// ����: 2018-12-20
// ����: PineconePi
// ��ע:
//	
//	
//	
//	
//	
//========================================================================
void IIC_host_Slave_machine(unsigned char host_Slave_machine)
{
	if(host_Slave_machine==host_machine)
	{
		I2CCFG = 0xe0;                              //ʹ��I2C����ģʽ
    I2CMSST = 0x00;
	}
	else if(host_Slave_machine==Slave_machine)
	{
		 P_SW2 = 0x80; 				//����Ӳ��IIC�Ĵ���������P_SW2Ϊ1
		I2CCFG = 0x81;                              //ʹ��I2C�ӻ�ģʽ
    I2CSLADR = IIC_Slave_machine_address;       //���ôӻ��豸��ַΪ5A
    I2CSLST = 0x00;
    I2CSLCR = 0x00;                             //��ֹ�ӻ�ģʽ�ж�
	}
}
//========================================================================
// ����: void handle_Slave_machine()
// ����: IIC�ӻ�ģʽ��������
// ����:
//       
//       
// ����: 
// �汾: VER1.0.0
// ����: 2018-12-20
// ����: PineconePi
// ��ע:
//	
//	
//	
//	
//	
//========================================================================
void handle_Slave_machine()
{
	  isda = 1;                                   //�û�������ʼ��
    isma = 1;
    addr = 0;
    I2CTXD = buffer[addr];
	     if (I2CSLST & 0x40)
        {
            I2CSLST &= ~0x40;                   //����START�¼�
        }
        else if (I2CSLST & 0x20)
        {
            I2CSLST &= ~0x20;                   //����RECV�¼�
            if (isda)
            {
                isda = 0;                       //����RECV�¼���RECV DEVICE ADDR��
            }
            else if (isma)
            {
                isma = 0;                       //����RECV�¼���RECV MEMORY ADDR��
                addr = I2CRXD;
                I2CTXD = buffer[addr];
            }
            else
            {
                buffer[addr++] = I2CRXD;        //����RECV�¼���RECV DATA��
            }
        }
        else if (I2CSLST & 0x10)
        {
            I2CSLST &= ~0x10;                   //����SEND�¼�
            if (I2CSLST & 0x02)
            {
                I2CTXD = 0xff;
            }
            else
            {
                I2CTXD = buffer[++addr];
            }
        }
        else if (I2CSLST & 0x08)
        {
            I2CSLST &= ~0x08;                   //����STOP�¼�
            isda = 1;
            isma = 1;
        }
	
}
//========================================================================
// ����:  IIC����ģʽ��ش�����
// ����:  IIC����ģʽ��ش�������
// ����:
//       
//       
// ����: 
// �汾: VER1.0.0
// ����: 2018-12-20
// ����: PineconePi
// ��ע:
//	
//	
//	
//	
//	
//========================================================================
void Wait()
{
    while (!(I2CMSST & 0x40));
    I2CMSST &= ~0x40;
}

void Start()
{
    I2CMSCR = 0x01;                             //����START����
    Wait();
}

void SendData(char dat)
{
    I2CTXD = dat;                               //д���ݵ����ݻ�����
    I2CMSCR = 0x02;                             //����SEND����
    Wait();
}

void RecvACK()
{
    I2CMSCR = 0x03;                             //���Ͷ�ACK����
    Wait();
}

char RecvData()
{
    I2CMSCR = 0x04;                             //����RECV����
    Wait();
    return I2CRXD;
}

void SendACK()
{
    I2CMSST = 0x00;                             //����ACK�ź�
    I2CMSCR = 0x05;                             //����ACK����
    Wait();
}

void SendNAK()
{
    I2CMSST = 0x01;                             //����NAK�ź�
    I2CMSCR = 0x05;                             //����ACK����
    Wait();
}

void Stop()
{
    I2CMSCR = 0x06;                             //����STOP����
    Wait();
}

void wait_device()
{
    int i;

    for (i=0; i<3000; i++)
    {
        _nop_();
        _nop_();
        _nop_();
        _nop_();
    }
}
//========================================================================
// ����:  IIC����ģʽ��ش�����ʾ��
// ����:  IIC����ģʽ��ش�����ʾ����
// ����:     
// ����: 
// �汾: VER1.0.0
// ����: 2018-12-20
// ����: PineconePi
// ʾ����
//    P_SW2 = 0x80;																	
//    IIC_host_Slave_machine��host_machine);       //����Ϊ����ģʽ
//    Start();                                    //������ʼ����
//    SendData(0xa0);                             //�����豸��ַ+д����
//    RecvACK();
//    SendData(0x00);                             //���ʹ洢��ַ���ֽ�
//    RecvACK();
//    SendData(0x00);                             //���ʹ洢��ַ���ֽ�
//    RecvACK();
//    SendData(0x12);                             //д��������1
//    RecvACK();
//    SendData(0x78);                             //д��������2
//    RecvACK();
//    Stop();                                     //����ֹͣ����
//    Delay();                                    //�ȴ��豸д����
//    Start();                                    //������ʼ����
//    SendData(0xa0);                             //�����豸��ַ+д����
//    RecvACK();
//    SendData(0x00);                             //���ʹ洢��ַ���ֽ�
//    RecvACK();
//    SendData(0x00);                             //���ʹ洢��ַ���ֽ�
//    RecvACK();
//    Start();                                    //������ʼ����
//    SendData(0xa1);                             //�����豸��ַ+������
//    RecvACK();
//    P0 = RecvData();                            //��ȡ����1
//    SendACK();
//    P2 = RecvData();                            //��ȡ����2
//    SendNAK();
//    Stop();                                     //����ֹͣ����
//    P_SW2 = 0x00;
//========================================================================