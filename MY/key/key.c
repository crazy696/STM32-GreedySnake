/*-------------------------------------------------------------------------------
�ļ����ƣ�key.c
�ļ����������ð�����ʼ������       
��    ע����
---------------------------------------------------------------------------------*/
#include "key.h"
/*-------------------------------------------------------------------------------
�������ƣ�KEY_Init
�����������������ų�ʼ�����򿪶˿�ʱ�ӣ����ö˿����ţ��˿ڹ���Ƶ�ʣ��˿�����ģʽ 
�����������
���ز�������
��    ע����
---------------------------------------------------------------------------------*/
void KEY_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	//��PC��ʱ��
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);  //��ʼ�����ö˿�ʱ��
	//PC��������	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
	//�˿��ٶ�
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	//�˿�ģʽ����Ϊ��������ģʽ
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	//��ʼ����Ӧ�Ķ˿�
  GPIO_Init(GPIOE, &GPIO_InitStructure);

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	//TOP��ʼ���ж�
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);	
	
	//BUTTOM��ʼ���ж�
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn ;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	//LEFT��ʼ���ж�
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

	//RIGHT��ʼ���ж�
	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	//STOP��ʼ���ж�
	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	//TOPʹ���ⲿ�ж�
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource0);
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);	
	
	//BUTTOMʹ���ⲿ�ж�
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource1);
	EXTI_InitStructure.EXTI_Line = EXTI_Line1 ;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);	
	
	//LEFTʹ���ⲿ�ж�
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource2);
	EXTI_InitStructure.EXTI_Line = EXTI_Line2;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);	
	
	//RIGHTʹ���ⲿ�ж�
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource3);
	EXTI_InitStructure.EXTI_Line = EXTI_Line3;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);	
	
	//STOPʹ���ⲿ�ж�
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource4);
	EXTI_InitStructure.EXTI_Line = EXTI_Line4 ;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);	
}
/*----------------------�·��� ������̳��www.doflye.net--------------------------*/
