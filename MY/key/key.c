/*-------------------------------------------------------------------------------
文件名称：key.c
文件描述：配置按键初始化参数       
备    注：无
---------------------------------------------------------------------------------*/
#include "key.h"
/*-------------------------------------------------------------------------------
程序名称：KEY_Init
程序描述：按键引脚初始化，打开端口时钟，配置端口引脚，端口工作频率，端口输入模式 
输入参数：无
返回参数：无
备    注：无
---------------------------------------------------------------------------------*/
void KEY_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	//打开PC口时钟
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);  //初始化复用端口时钟
	//PC引脚设置	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
	//端口速度
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	//端口模式，此为输入上拉模式
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	//初始化对应的端口
  GPIO_Init(GPIOE, &GPIO_InitStructure);

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	//TOP初始化中断
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);	
	
	//BUTTOM初始化中断
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn ;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	//LEFT初始化中断
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

	//RIGHT初始化中断
	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	//STOP初始化中断
	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	//TOP使能外部中断
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource0);
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);	
	
	//BUTTOM使能外部中断
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource1);
	EXTI_InitStructure.EXTI_Line = EXTI_Line1 ;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);	
	
	//LEFT使能外部中断
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource2);
	EXTI_InitStructure.EXTI_Line = EXTI_Line2;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);	
	
	//RIGHT使能外部中断
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource3);
	EXTI_InitStructure.EXTI_Line = EXTI_Line3;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);	
	
	//STOP使能外部中断
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource4);
	EXTI_InitStructure.EXTI_Line = EXTI_Line4 ;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);	
}
/*----------------------德飞莱 技术论坛：www.doflye.net--------------------------*/
