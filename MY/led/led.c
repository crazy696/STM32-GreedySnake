/*-------------------------------------------------------------------------------
�ļ����ƣ�led.c
�ļ�����������Ӳ����������LED�˿ڣ��򿪶�Ӧ�ļĴ���        
��    ע����
---------------------------------------------------------------------------------*/
#include "led.h"
/*-------------------------------------------------------------------------------
�������ƣ�LED_Init
������������ʼ��LED��ض˿ڣ��򿪶˿�ʱ�ӣ����ö˿����  
�����������
���ز�������
��    ע����
---------------------------------------------------------------------------------*/
void LED_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	SPI_InitTypeDef  SPI1_InitStructure; 
	//��PA��ʱ��
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOA, ENABLE);  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);  
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  
	GPIO_Init(GPIOA, &GPIO_InitStructure);  
      
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//GPIO_SetBits(GPIOA,GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7); 
	
	SPI1_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI1_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_64;  
  SPI1_InitStructure.SPI_DataSize = SPI_DataSize_8b;  
  SPI1_InitStructure.SPI_Mode = SPI_Mode_Master; 
  SPI1_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;  
  SPI1_InitStructure.SPI_CPOL = SPI_CPOL_High;  
  SPI1_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
  SPI1_InitStructure.SPI_NSS = SPI_NSS_Soft;  
  SPI1_InitStructure.SPI_CRCPolynomial = 7;  
      
  SPI_I2S_DeInit(SPI1);  
      
  SPI_Init(SPI1, &SPI1_InitStructure); 
      
  SPI_Cmd(SPI1, ENABLE);    
}
/*----------------------�·��� ������̳��www.doflye.net--------------------------*/
