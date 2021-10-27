#include <stdio.h>
#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "key.h"
#include "timer.h"
#include "beep.h"
#include "usart.h"
#include "sys.h"

#define Max7219_pinCLK PAout(5)  
#define Max7219_pinCS PAout(3)  
#define Max7219_pinDIN PAout(7) 

//左移
#define ROTATE_LEFT(x,  n) ((x) << (n)) | ((x) >> ((8*sizeof(x)) - (n)))
//右移
#define ROTATE_RIGHT(x,  n) ((x) >> (n)) | ((x) << ((8*sizeof(x)) - (n)))

u8 life = 1, top = 1, buttom = 0, left = 0, right = 0, stop = 1, count1 = 100, count2 = 125, food_flag = 1, add_flag = 0, random1, random2;
char snake[8] = {0};
char food[8] = {0};

char disp0[8] = {0xEE,0x84,0xE4,0x2E,0xEA,0xEE,0xA8,0xE8};//STOP

//分数
char disp1[10][8] = {
{0x0,0x0,0xE,0xA,0xA,0xA,0xE,0x0},//0
{0x0,0x0,0x2,0x2,0x2,0x2,0x2,0x0},//1
{0x0,0x0,0xE,0x2,0xE,0x8,0xE,0x0},//2
{0x0,0x0,0xE,0x2,0xE,0x2,0xE,0x0},//3
{0x0,0x0,0x2,0x6,0xF,0x2,0x2,0x0},//4
{0x0,0x0,0xE,0x8,0xE,0x2,0xE,0x0},//5
{0x0,0x0,0xE,0x8,0xE,0xA,0xE,0x0},//6
{0x0,0x0,0xE,0x2,0x2,0x2,0x2,0x0},//7
{0x0,0x0,0xE,0xA,0xE,0xA,0xE,0x0},//8
{0x0,0x0,0xE,0xA,0xE,0x2,0xE,0x0} //9
};

//结束动画
char disp2[5][8] = {
{0x00,0xef,0xef,0x83,0xef,0xef,0xef,0x00},
{0x00,0x7E,0x7E,0x7E,0x7E,0x7E,0x7E,0x00},
{0xFF,0x81,0xBD,0xBD,0xBD,0xBD,0x81,0xFF},
{0xFF,0xFF,0xC3,0xDB,0xDB,0xC3,0xFF,0xFF},
{0xFF,0xFF,0xFF,0xE7,0xE7,0xFF,0xFF,0xFF}
};

//蛇
char disp3[64][8] = {
{0x00,0x00,0x00,0x8,0x00,0x00,0x00,0x00},
{0x00,0x00,0x8,0x00,0x00,0x00,0x00,0x00},
{0x00,0x8,0x00,0x00,0x00,0x00,0x00,0x00},
};

 //上移
void buffer_top_move(char *buffer , int buf_len)  
{  
	int i ;  
	char tmp = buffer[0];  
	for(i = 1 ; i < buf_len ; i++)  
	{  
		buffer[i-1] = buffer[i] ;  
	}  
	buffer[buf_len-1] = tmp ;  
} 

//下移
void buffer_buttom_move(char *buffer , int buf_len)  
{  
  int i ;  
	char tmp = buffer[buf_len - 1];  
	for(i = buf_len ; i > 0 ; i--)  
	{  
		buffer[i] = buffer[i-1] ;   
	}  
	buffer[0] = tmp ;  
}  

//向max7219写数据
void Write_Max7219(unsigned char address,unsigned char dat)  
{   

	Max7219_pinCS = 0;
	SPI_I2S_SendData(SPI1, address);
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY) == RESET); 
	SPI_I2S_ReceiveData(SPI1);
	Delay_us(10);  
			
	SPI_I2S_SendData(SPI1, dat); 
  while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY) == RESET); 	
	SPI_I2S_ReceiveData(SPI1);
	Delay_us(10);  
	Max7219_pinCS = 1;
}
//设置点阵基本参数
void Init_MAX7219(void)  
{        
	Write_Max7219(0x09, 0x00);      
	Write_Max7219(0x0A, 0x03);      
	Write_Max7219(0x0B, 0x07);   
	Write_Max7219(0x0C, 0x01);  
	Write_Max7219(0x0F, 0x00);   
}
//上键
void EXTI0_IRQHandler()
{
	if(EXTI_GetITStatus(EXTI_Line0) != RESET)
	{
		if(left | right)
		{
			top = 1;
			left = right = 0;
		}
	}
	EXTI_ClearITPendingBit(EXTI_Line0);
}
//下键
void EXTI1_IRQHandler()
{
	if(EXTI_GetITStatus(EXTI_Line1) != RESET)
	{
		if(left | right)
		{
			buttom = 1;
			left = right = 0;
		}
	}
	EXTI_ClearITPendingBit(EXTI_Line1);
}
//左键
void EXTI2_IRQHandler()
{
	if(EXTI_GetITStatus(EXTI_Line2) != RESET)
	{
		if(top | buttom)
		{
			left = 1;
			top = buttom = 0;
		}
	}
	EXTI_ClearITPendingBit(EXTI_Line2);
}
//右键
void EXTI3_IRQHandler()
{
	if(EXTI_GetITStatus(EXTI_Line3) != RESET)
	{
		if(top | buttom)
		{
			right = 1;
			top = buttom = 0;
		}
	}
	EXTI_ClearITPendingBit(EXTI_Line3);
}
//stop键
void EXTI4_IRQHandler()
{
	if(EXTI_GetITStatus(EXTI_Line4) != RESET)
	{
		stop = !stop;
	}
	EXTI_ClearITPendingBit(EXTI_Line4);
}

//运动方向
void snake_direction()
{
	u8 i, j;
	for(j=0;j < 1;j++)  
	{
		if(top)
		{
			buffer_top_move(disp3[j], 8);
		}			
		if(buttom)
		{
			buffer_buttom_move(disp3[j], 8);
		}
		for(i = 1;i < 9;i++)  
		{  
			
			if(left)
			{
				disp3[j][i-1]=ROTATE_LEFT(disp3[j][i-1],1);
			}
			if(right)
			{
				disp3[j][i-1]=ROTATE_RIGHT(disp3[j][i-1],1);
			}
		}
	}
}

//画蛇
void snake_move(int n)
{
	u8 i, j;
	for(i = 1; i < 9; i++)
	{
		for(j=0; j < n; j++)
		{
			snake[i-1] |= disp3[j][i-1];
			snake[i-1] |= food[i-1];
		}
		Write_Max7219(i,snake[i-1]);
	}
		
}
//产生随机食物
void random_food()
{
	char location[8] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80};
  food[random1] |= location[random2];
}

int main(void)
{
	u8 i, j, f, g, over = 2;
	int n = 3, score, bits, ten;
	char scores[8];
	LED_Init();
  KEY_Init();
  SysTick_Init();
	BEEP_Init();   
	//TIM2_Base_Init(1000);
  //USART1_Int(9600);
	
	Delay_ms(50);  
  Init_MAX7219();

	while(life)
	{
		if(stop)
		{
			//产生随机数
			random1 = count1 % 8;
			random2 = count2 % 8;
			count1--;
			count2--;
			if(count1 <= 0)
			{
				count1 = 100;
			}
			if(count2 <= 0)
			{
				count2 = 125;
			}
			//当食物被吃
			if(food_flag)
			{
				random_food();
				food_flag = 0;
			}
			
			//蛇头食物碰撞检测
			for(f = 0; f < 8; f++)
			{
				if(food[f] != disp3[0][f])
				{
					break;
				}
			}
			if(f == 8)
			{
				BEEP_REV;
				Delay_ms(10);
				BEEP_REV;
				food_flag = 1;
				add_flag = 1;
				n++;
				for(i = 0; i < 8; i++)
				{
					food[i] = 0;
					
				}
			}
			//后面的点继承前一个点的位置
			for(j = n-1; j > 0; j-- )
			{
				for(i = 0; i < 8; i++)
				{
					disp3[j][i] = disp3[j-1][i];
				}
			}

			snake_direction();    //调整运动反方向
			snake_move(n);       //绘制蛇
			Delay_ms(200);
			LED2_REV;
			
			//吃食物后添加蛇尾
			if(add_flag)
			{
				if(top)
				{
					int i ;  
					char tmp = disp3[n-1][7];  
					for(i = 8 ; i > 0 ; i--)  
					{  
						disp3[n][i] = disp3[n-1][i-1] ;   
					}  
					disp3[n][0] = tmp ;
					add_flag = 0;
				}
				if(buttom)
				{
					int i ;  
					char tmp = disp3[n-1][0];  
					for(i = 1 ; i < 8 ; i++)  
					{  
						disp3[n][i-1] = disp3[n-1][i] ;   
					}  
					disp3[n][7] = tmp ;
					add_flag = 0;
				}
			}
			
			//蛇头蛇身碰撞检测
			if(n > 4)
			{
				for(i = 4; i < n; i++)
				{
					for(g = 0; g < 8; g++)
					{
						if(disp3[0][g] != disp3[i][g])
						{
							break;
						}
					}
					if(g== 8)
					{
						life = 0;
						break;
					}
				}
			}
			
			//清空蛇数组
			for(i = 0; i < 8; i++)
			{
				snake[i] = 0;
			}
		
		}
		//暂停图标
		else
		{
			for(i = 1; i < 9; i++)
			{
				Write_Max7219(i, disp0[i-1]);
			}	
		}
	}
	while(over--)
	{
		BEEP_REV;
		for(i = 0; i < 5; i++)
		{
			for(j = 1; j < 9; j++)
			{
				Write_Max7219(j, disp2[i][j-1]);
			}
			Delay_ms(150);
		}
	}
	score = n -3;      //计分
	ten = score % 10;  //计算十位
	bits = score / 10;  //计算个位
	for(i = 0; i < 8; i++)   //打印分数
	{
		scores[i] = disp1[ten][i] | ROTATE_RIGHT(disp1[bits][i],4);
		Write_Max7219(i,scores[i]);
	}
}




