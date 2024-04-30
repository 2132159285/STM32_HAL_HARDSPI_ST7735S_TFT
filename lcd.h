#include "stdint.h"
#include "main.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"
#include "string.h"


#ifndef LCD_H_
#define LCD_H_


#define USE_HORIZONTAL 2

#if USE_HORIZONTAL==0||USE_HORIZONTAL==1
#define LCD_W 80
#define LCD_H 160

#else
#define LCD_W 160
#define LCD_H 80
#endif

#define LCD_CS_Clr()  HAL_GPIO_WritePin(TFT_CS_GPIO_Port,TFT_CS_Pin,GPIO_PIN_RESET)
#define LCD_CS_Set()  HAL_GPIO_WritePin(TFT_CS_GPIO_Port,TFT_CS_Pin,GPIO_PIN_SET)

#define LCD_RES_Clr()  HAL_GPIO_WritePin(TFT_RES_GPIO_Port,TFT_RES_Pin,GPIO_PIN_RESET)
#define LCD_RES_Set()  HAL_GPIO_WritePin(TFT_RES_GPIO_Port,TFT_RES_Pin,GPIO_PIN_SET)

#define LCD_DC_Clr()   HAL_GPIO_WritePin(TFT_DC_GPIO_Port,TFT_DC_Pin,GPIO_PIN_RESET)
#define LCD_DC_Set()   HAL_GPIO_WritePin(TFT_DC_GPIO_Port,TFT_DC_Pin,GPIO_PIN_SET)

#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE           	 0x001F  
#define BRED             0XF81F
#define GRED 			       0XFFE0
#define GBLUE			       0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			     0XBC40 
#define BRRED 			     0XFC07 
#define GRAY  			     0X8430 
#define DARKBLUE      	 0X01CF	
#define LIGHTBLUE      	 0X7D7C	
#define GRAYBLUE       	 0X5458 
#define LIGHTGREEN     	 0X841F 
#define LGRAY 			     0XC618 
#define LGRAYBLUE        0XA651 
#define LBBLUE           0X2B12 


void LCD_WR_DATA08(uint8_t  dat);
void LCD_WR_DATA16(uint16_t dat);
void LCD_WR_REG(uint8_t dat);
void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);

void LCD_Init(void);
uint32_t mypow(uint16_t m,uint16_t n);

void LCD_Fill(uint16_t xsta,uint16_t ysta,uint16_t xend,uint16_t yend,uint16_t color);
void LCD_DrawPoint(uint16_t x,uint16_t y,uint16_t color);
void LCD_DrawLine(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color);
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,uint16_t color);
void Draw_Circle(uint16_t x0,uint16_t y0,uint16_t r,uint16_t color);
void LCD_ShowChinese12x12(uint16_t x,uint16_t y,uint8_t *s,uint16_t fc,uint16_t bc,uint16_t sizey,uint16_t mode);
void LCD_ShowChinese16x16(uint16_t x,uint16_t y,uint8_t *s,uint16_t fc,uint16_t bc,uint16_t sizey,uint16_t mode);
void LCD_ShowChinese24x24(uint16_t x,uint16_t y,uint8_t *s,uint16_t fc,uint16_t bc,uint16_t sizey,uint16_t mode);
void LCD_ShowChinese32x32(uint16_t x,uint16_t y,uint8_t *s,uint16_t fc,uint16_t bc,uint16_t sizey,uint16_t mode);
void LCD_ShowChinese(uint16_t x,uint16_t y,uint8_t *s,uint16_t fc,uint16_t bc,uint16_t sizey,uint16_t mode);
void LCD_ShowChar(uint16_t x,uint16_t y,uint16_t num,uint16_t fc,uint16_t bc,uint16_t sizey,uint16_t mode);
void LCD_ShowString(uint16_t x,uint16_t y,const uint8_t *p,uint16_t fc,uint16_t bc,uint16_t sizey,uint16_t mode);
void LCD_ShowIntNum(uint16_t x,uint16_t y,uint16_t num,uint16_t len,uint16_t fc,uint16_t bc,uint16_t sizey);
void LCD_ShowFloatNum1(uint16_t x,uint16_t y,float num,uint16_t len,uint16_t fc,uint16_t bc,uint16_t sizey);
void LCD_ShowPicture(uint16_t x,uint16_t y,uint16_t length,uint16_t width,const uint8_t pic[]);

#endif