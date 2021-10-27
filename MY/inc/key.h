
#ifndef __KEY_H
#define __KEY_H

#include "stm32f10x.h"

#define TOP GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_0)
#define BUTTOM GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_1)
#define LEFT GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)
#define RIGHT GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)
#define RESET GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)
#define STOP GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_5)

void KEY_Init(void);

#endif
/*----------------------德飞莱 技术论坛：www.doflye.net--------------------------*/
