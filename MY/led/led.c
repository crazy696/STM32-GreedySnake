/*-------------------------------------------------------------------------------
文件名称：led.c
文件描述：根据硬件连接配置LED端口，打开对应的寄存器        
备    注：无
---------------------------------------------------------------------------------*/
#include "led.h"
/*-------------------------------------------------------------------------------
程序名称：LED_Init
程序描述：初始化LED相关端口，打开端口时钟，配置端口输出  
输入参数：无
返回参数：无
备    注：无
---------------------------------------------------------------------------------*/
void LED_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	SPI_InitTypeDef  SPI1_InitStructure; 
	//打开PA口时钟
	
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
/*----------------------德飞莱 技术论坛：www.doflye.net--------------------------*/
