#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"

#define LED2_OFF GPIO_SetBits(GPIOE,GPIO_Pin_5)
#define LED2_ON GPIO_ResetBits(GPIOE,GPIO_Pin_5)
#define LED2_REV GPIO_WriteBit(GPIOE, GPIO_Pin_5,(BitAction)(1-(GPIO_ReadOutputDataBit(GPIOE, GPIO_Pin_5))))

#define LED3_OFF GPIO_SetBits(GPIOB,GPIO_Pin_5)
#define LED3_ON GPIO_ResetBits(GPIOB,GPIO_Pin_5)
#define LED3_REV GPIO_WriteBit(GPIOB, GPIO_Pin_5,(BitAction)(1-(GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_5))))


#define X_OFF GPIO_SetBits(GPIOA,GPIO_Pin_0)
#define X_ON GPIO_ResetBits(GPIOA,GPIO_Pin_0)
#define X_REV GPIO_WriteBit(GPIOA, GPIO_Pin_0,(BitAction)(1-(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_0))))

#define Y_OFF GPIO_SetBits(GPIOA,GPIO_Pin_1)
#define Y_ON GPIO_ResetBits(GPIOA,GPIO_Pin_1)
#define Y_REV GPIO_WriteBit(GPIOA, GPIO_Pin_1,(BitAction)(1-(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_1))))

#define CLK_OFF GPIO_SetBits(GPIOA,GPIO_Pin_2)
#define CLK_ON GPIO_ResetBits(GPIOA,GPIO_Pin_2)
#define CLK_REV GPIO_WriteBit(GPIOA, GPIO_Pin_2,(BitAction)(1-(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_2))))

/*#define X4_OFF GPIO_SetBits(GPIOA,GPIO_Pin_3)
#define X4_ON GPIO_ResetBits(GPIOA,GPIO_Pin_3)
#define X4_REV GPIO_WriteBit(GPIOA, GPIO_Pin_3,(BitAction)(1-(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_3))))

#define X5_OFF GPIO_SetBits(GPIOA,GPIO_Pin_4)
#define X5_ON GPIO_ResetBits(GPIOA,GPIO_Pin_4)
#define X5_REV GPIO_WriteBit(GPIOA, GPIO_Pin_4,(BitAction)(1-(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_4))))

#define X6_OFF GPIO_SetBits(GPIOA,GPIO_Pin_5)
#define X6_ON GPIO_ResetBits(GPIOA,GPIO_Pin_5)
#define X6_REV GPIO_WriteBit(GPIOA, GPIO_Pin_5,(BitAction)(1-(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_5))))

#define X7_OFF GPIO_SetBits(GPIOA,GPIO_Pin_6)
#define X7_ON GPIO_ResetBits(GPIOA,GPIO_Pin_6)
#define X7_REV GPIO_WriteBit(GPIOA, GPIO_Pin_6,(BitAction)(1-(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_6))))

#define X8_OFF GPIO_SetBits(GPIOA,GPIO_Pin_7)
#define X8_ON GPIO_ResetBits(GPIOA,GPIO_Pin_7)
#define X8_REV GPIO_WriteBit(GPIOA, GPIO_Pin_7,(BitAction)(1-(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_7))))

#define Y1_OFF GPIO_SetBits(GPIOBF,GPIO_Pin_0)
#define Y1_ON GPIO_ResetBits(GPIOF,GPIO_Pin_0)
#define Y1_REV GPIO_WriteBit(GPIOF, GPIO_Pin_0,(BitAction)(1-(GPIO_ReadOutputDataBit(GPIOF, GPIO_Pin_0))))

#define Y2_OFF GPIO_SetBits(GPIOBF,GPIO_Pin_1)
#define Y2_ON GPIO_ResetBits(GPIOF,GPIO_Pin_1)
#define Y2_REV GPIO_WriteBit(GPIOF, GPIO_Pin_1,(BitAction)(1-(GPIO_ReadOutputDataBit(GPIOF, GPIO_Pin_1))))

#define Y3_OFF GPIO_SetBits(GPIOBF,GPIO_Pin_2)
#define Y3_ON GPIO_ResetBits(GPIOF,GPIO_Pin_2)
#define Y3_REV GPIO_WriteBit(GPIOF, GPIO_Pin_2,(BitAction)(1-(GPIO_ReadOutputDataBit(GPIOF, GPIO_Pin_2))))

#define Y4_OFF GPIO_SetBits(GPIOBF,GPIO_Pin_3)
#define Y4_ON GPIO_ResetBits(GPIOF,GPIO_Pin_3)
#define Y4_REV GPIO_WriteBit(GPIOF, GPIO_Pin_3,(BitAction)(1-(GPIO_ReadOutputDataBit(GPIOF, GPIO_Pin_3))))

#define Y5_OFF GPIO_SetBits(GPIOBF,GPIO_Pin_4)
#define Y5_ON GPIO_ResetBits(GPIOF,GPIO_Pin_4)
#define Y5_REV GPIO_WriteBit(GPIOF, GPIO_Pin_4,(BitAction)(1-(GPIO_ReadOutputDataBit(GPIOF, GPIO_Pin_4))))

#define Y6_OFF GPIO_SetBits(GPIOBF,GPIO_Pin_5)
#define Y6_ON GPIO_ResetBits(GPIOF,GPIO_Pin_5)
#define Y6_REV GPIO_WriteBit(GPIOF, GPIO_Pin_5,(BitAction)(1-(GPIO_ReadOutputDataBit(GPIOF, GPIO_Pin_5))))

#define Y7_OFF GPIO_SetBits(GPIOBF,GPIO_Pin_6)
#define Y7_ON GPIO_ResetBits(GPIOF,GPIO_Pin_6)
#define Y7_REV GPIO_WriteBit(GPIOF, GPIO_Pin_6,(BitAction)(1-(GPIO_ReadOutputDataBit(GPIOF, GPIO_Pin_6))))

#define Y8_OFF GPIO_SetBits(GPIOBF,GPIO_Pin_7)
#define Y8_ON GPIO_ResetBits(GPIOF,GPIO_Pin_7)
#define Y8_REV GPIO_WriteBit(GPIOF, GPIO_Pin_7,(BitAction)(1-(GPIO_ReadOutputDataBit(GPIOF, GPIO_Pin_7))))*/

void LED_Init(void);

#endif
/*----------------------德飞莱 技术论坛：www.doflye.net--------------------------*/
