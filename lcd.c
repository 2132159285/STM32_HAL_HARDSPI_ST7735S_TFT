#include "lcd.h"
#include "forts.h"
/******************************************************************************
      函数说明：LCD写入8位数据
      入口数据：dat 写入的数据
      返回值：  无
******************************************************************************/
void LCD_WR_DATA08(uint8_t dat)
{
	LCD_CS_Clr();
	HAL_SPI_Transmit(&hspi1,&dat,1,0xffff);
	LCD_CS_Set();
}
/******************************************************************************
      函数说明：LCD写入16位数据
      入口数据：dat 写入的数据
      返回值：  无
******************************************************************************/
void LCD_WR_DATA16(uint16_t dat)
{
	hspi1.Init.DataSize = SPI_DATASIZE_16BIT;
	HAL_SPI_Init(&hspi1);
	LCD_CS_Clr();
	HAL_SPI_Transmit(&hspi1,(uint8_t*)&dat,1,0xffff);
	LCD_CS_Set();
	hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
	HAL_SPI_Init(&hspi1);
}
/******************************************************************************
      函数说明：LCD写入命令
      入口数据：dat 写入的命令
      返回值：  无
******************************************************************************/
void LCD_WR_REG(uint8_t dat)
{
	LCD_DC_Clr();
	LCD_WR_DATA08(dat);
	LCD_DC_Set();
}
/******************************************************************************
      函数说明：设置起始和结束地址
      入口数据：x1,x2 设置列的起始和结束地址
                y1,y2 设置行的起始和结束地址
      返回值：  无
******************************************************************************/
void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
{
	if(USE_HORIZONTAL==0)
	{
		LCD_WR_REG(0x2a);
		LCD_WR_DATA16(x1+26);
		LCD_WR_DATA16(x2+26);
		LCD_WR_REG(0x2b);
		LCD_WR_DATA16(y1+1);
		LCD_WR_DATA16(y2+1);
		LCD_WR_REG(0x2c);
	}
	else if(USE_HORIZONTAL==1)
	{
		LCD_WR_REG(0x2a);
		LCD_WR_DATA16(x1+26);
		LCD_WR_DATA16(x2+26);
		LCD_WR_REG(0x2b);
		LCD_WR_DATA16(y1+1);
		LCD_WR_DATA16(y2+1);
		LCD_WR_REG(0x2c);
	}
	else if(USE_HORIZONTAL==2)
	{
		LCD_WR_REG(0x2a);
		LCD_WR_DATA16(x1+1);
		LCD_WR_DATA16(x2+1);
		LCD_WR_REG(0x2b);
		LCD_WR_DATA16(y1+26);
		LCD_WR_DATA16(y2+26);
		LCD_WR_REG(0x2c);
	}
	else
	{
		LCD_WR_REG(0x2a);
		LCD_WR_DATA16(x1+1);
		LCD_WR_DATA16(x2+1);
		LCD_WR_REG(0x2b);
		LCD_WR_DATA16(y1+26);
		LCD_WR_DATA16(y2+26);
		LCD_WR_REG(0x2c);
	}
}
/******************************************************************************
      函数说明：LCD初始化
      入口数据：无
      返回值：  无
******************************************************************************/
void LCD_Init(void)
{
	LCD_RES_Clr(); 
	HAL_Delay(10);
	LCD_RES_Set();
	HAL_Delay(120);
	
	LCD_WR_REG(0x11);   
	HAL_Delay(120);       
	LCD_WR_REG(0xB1);     
	LCD_WR_DATA08(0x05);   
	LCD_WR_DATA08(0x3C);   
	LCD_WR_DATA08(0x3C);   
	LCD_WR_REG(0xB2);     
	LCD_WR_DATA08(0x05);   
	LCD_WR_DATA08(0x3C);   
	LCD_WR_DATA08(0x3C);   
	LCD_WR_REG(0xB3);     
	LCD_WR_DATA08(0x05);   
	LCD_WR_DATA08(0x3C);   
	LCD_WR_DATA08(0x3C);   
	LCD_WR_DATA08(0x05);   
	LCD_WR_DATA08(0x3C);   
	LCD_WR_DATA08(0x3C);   
	LCD_WR_REG(0xB4);     
	LCD_WR_DATA08(0x03);   
	LCD_WR_REG(0xC0);     
	LCD_WR_DATA08(0xAB);   
	LCD_WR_DATA08(0x0B);   
	LCD_WR_DATA08(0x04);   
	LCD_WR_REG(0xC1);     
	LCD_WR_DATA08(0xC5);   
	LCD_WR_REG(0xC2);     
	LCD_WR_DATA08(0x0D);   
	LCD_WR_DATA08(0x00);   
	LCD_WR_REG(0xC3);     
	LCD_WR_DATA08(0x8D);   
	LCD_WR_DATA08(0x6A);   
	LCD_WR_REG(0xC4);     
	LCD_WR_DATA08(0x8D);   
	LCD_WR_DATA08(0xEE);   
	LCD_WR_REG(0xC5);     
	LCD_WR_DATA08(0x0F);   
	LCD_WR_REG(0xE0);     
	LCD_WR_DATA08(0x07);   
	LCD_WR_DATA08(0x0E);   
	LCD_WR_DATA08(0x08);   
	LCD_WR_DATA08(0x07);   
	LCD_WR_DATA08(0x10);   
	LCD_WR_DATA08(0x07);   
	LCD_WR_DATA08(0x02);   
	LCD_WR_DATA08(0x07);   
	LCD_WR_DATA08(0x09);   
	LCD_WR_DATA08(0x0F);   
	LCD_WR_DATA08(0x25);   
	LCD_WR_DATA08(0x36);   
	LCD_WR_DATA08(0x00);   
	LCD_WR_DATA08(0x08);   
	LCD_WR_DATA08(0x04);   
	LCD_WR_DATA08(0x10);   
	LCD_WR_REG(0xE1);     
	LCD_WR_DATA08(0x0A);   
	LCD_WR_DATA08(0x0D);   
	LCD_WR_DATA08(0x08);   
	LCD_WR_DATA08(0x07);   
	LCD_WR_DATA08(0x0F);   
	LCD_WR_DATA08(0x07);   
	LCD_WR_DATA08(0x02);   
	LCD_WR_DATA08(0x07);   
	LCD_WR_DATA08(0x09);   
	LCD_WR_DATA08(0x0F);   
	LCD_WR_DATA08(0x25);   
	LCD_WR_DATA08(0x35);   
	LCD_WR_DATA08(0x00);   
	LCD_WR_DATA08(0x09);   
	LCD_WR_DATA08(0x04);   
	LCD_WR_DATA08(0x10);
		 
	LCD_WR_REG(0xFC);    
	LCD_WR_DATA08(0x80);  
		
	LCD_WR_REG(0x3A);     
	LCD_WR_DATA08(0x05);   
	LCD_WR_REG(0x36);
	if(USE_HORIZONTAL==0)LCD_WR_DATA08(0x08);
	else if(USE_HORIZONTAL==1)LCD_WR_DATA08(0xC8);
	else if(USE_HORIZONTAL==2)LCD_WR_DATA08(0x78);
	else LCD_WR_DATA08(0xA8);   
	LCD_WR_REG(0x21);    
	LCD_WR_REG(0x29);     
	LCD_WR_REG(0x2A);     
	LCD_WR_DATA08(0x00);   
	LCD_WR_DATA08(0x1A);   
	LCD_WR_DATA08(0x00);   
	LCD_WR_DATA08(0x69);   
	LCD_WR_REG(0x2B);     
	LCD_WR_DATA08(0x00);   
	LCD_WR_DATA08(0x01);  
	LCD_WR_DATA08(0x00);   
	LCD_WR_DATA08(0xA0);   
	LCD_WR_REG(0x2C); 
}
/******************************************************************************
      函数说明：在指定区域填充颜色
      入口数据：xsta,ysta   起始坐标
                xend,yend   终止坐标
								color       要填充的颜色
      返回值：  无
******************************************************************************/
void LCD_Fill(uint16_t xsta,uint16_t ysta,uint16_t xend,uint16_t yend,uint16_t color)
{          
	LCD_Address_Set(xsta,ysta,xend-1,yend-1);
	
	hspi1.Init.DataSize = SPI_DATASIZE_16BIT;
	HAL_SPI_Init(&hspi1);
	LCD_CS_Clr();
	for(uint16_t i=ysta;i<yend;i++)
	{													   	 	
		for(uint16_t j=xsta;j<xend;j++)
		{
			HAL_SPI_Transmit(&hspi1,(uint8_t*)&color,1,0xffff);
		}
	}
	LCD_CS_Set();
	hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
	HAL_SPI_Init(&hspi1);	
}
/******************************************************************************
      函数说明：在指定位置画点
      入口数据：x,y 画点坐标
                color 点的颜色
      返回值：  无
******************************************************************************/
void LCD_DrawPoint(uint16_t x,uint16_t y,uint16_t color)
{
	LCD_Address_Set(x,y,x,y);
	LCD_WR_DATA16(color);
} 
/******************************************************************************
      函数说明：画线
      入口数据：x1,y1   起始坐标
                x2,y2   终止坐标
                color   线的颜色
      返回值：  无
******************************************************************************/
void LCD_DrawLine(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color)
{
	int16_t xerr=0,yerr=0,delta_x,delta_y,distance;
	int16_t incx,incy,uRow,uCol;
	delta_x=x2-x1;
	delta_y=y2-y1;
	uRow=x1;
	uCol=y1;
	if(delta_x>0)incx=1; 
	else if (delta_x==0)incx=0;
	else {incx=-1;delta_x=-delta_x;}
	if(delta_y>0)incy=1;
	else if (delta_y==0)incy=0;
	else {incy=-1;delta_y=-delta_y;}
	if(delta_x>delta_y)distance=delta_x; 
	else distance=delta_y;
	for(uint16_t t=0;t<distance+1;t++)
	{
		LCD_DrawPoint(uRow,uCol,color);
		xerr+=delta_x;
		yerr+=delta_y;
		if(xerr>distance)
		{
			xerr-=distance;
			uRow+=incx;
		}
		if(yerr>distance)
		{
			yerr-=distance;
			uCol+=incy;
		}
	}
}
/******************************************************************************
      函数说明：画矩形
      入口数据：x1,y1   起始坐标
                x2,y2   终止坐标
                color   矩形的颜色
      返回值：  无
******************************************************************************/
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,uint16_t color)
{
	LCD_DrawLine(x1,y1,x2,y1,color);
	LCD_DrawLine(x1,y1,x1,y2,color);
	LCD_DrawLine(x1,y2,x2,y2,color);
	LCD_DrawLine(x2,y1,x2,y2,color);
}
/******************************************************************************
      函数说明：画圆
      入口数据：x0,y0   圆心坐标
                r       半径
                color   圆的颜色
      返回值：  无
******************************************************************************/
void Draw_Circle(uint16_t x0,uint16_t y0,uint16_t r,uint16_t color)
{
	int a,b;
	a=0;b=r;	  
	while(a<=b)
	{
		LCD_DrawPoint(x0-b,y0-a,color);             //3           
		LCD_DrawPoint(x0+b,y0-a,color);             //0           
		LCD_DrawPoint(x0-a,y0+b,color);             //1                
		LCD_DrawPoint(x0-a,y0-b,color);             //2             
		LCD_DrawPoint(x0+b,y0+a,color);             //4               
		LCD_DrawPoint(x0+a,y0-b,color);             //5
		LCD_DrawPoint(x0+a,y0+b,color);             //6 
		LCD_DrawPoint(x0-b,y0+a,color);             //7
		a++;
		if((a*a+b*b)>(r*r))//判断要画的点是否过远
		{
			b--;
		}
	}
}
/******************************************************************************
      函数说明：显示单个12x12汉字
      入口数据：x,y显示坐标
                *s 要显示的汉字
                fc 字的颜色
                bc 字的背景色
                sizey 字号
                mode:  0非叠加模式  1叠加模式
      返回值：  无
******************************************************************************/
void LCD_ShowChinese12x12(uint16_t x,uint16_t y,uint8_t *s,uint16_t fc,uint16_t bc,uint16_t sizey,uint16_t mode)
{
	uint16_t x0=x,m=0;
	uint16_t TypefaceNum=(sizey/8+((sizey%8)?1:0))*sizey;                      
	uint16_t HZnum=sizeof(tfont12)/sizeof(typFNT_GB12);
	for(uint16_t k=0;k<HZnum;k++) 
	{
		if((tfont12[k].Index[0]==*(s))&&(tfont12[k].Index[1]==*(s+1)))
		{ 	
			LCD_Address_Set(x,y,x+sizey-1,y+sizey-1);
			for(uint16_t i=0;i<TypefaceNum;i++)
			{
				for(uint16_t j=0;j<8;j++)
				{	
					if(!mode)//非叠加方式
					{
						if(tfont12[k].Msk[i]&(0x01<<j))LCD_WR_DATA16(fc);
						else LCD_WR_DATA16(bc);
						m++;
						if(m%sizey==0)
						{
							m=0;
							break;
						}
					}
					else//叠加方式
					{
						if(tfont12[k].Msk[i]&(0x01<<j))	LCD_DrawPoint(x,y,fc);//画一个点
						x++;
						if((x-x0)==sizey)
						{
							x=x0;
							y++;
							break;
						}
					}
				}
			}
		}				  	
		continue;  //查找到对应点阵字库立即退出，防止多个汉字重复取模带来影响
	}
} 

/******************************************************************************
      函数说明：显示单个16x16汉字
      入口数据：x,y显示坐标
                *s 要显示的汉字
                fc 字的颜色
                bc 字的背景色
                sizey 字号
                mode:  0非叠加模式  1叠加模式
      返回值：  无
******************************************************************************/
void LCD_ShowChinese16x16(uint16_t x,uint16_t y,uint8_t *s,uint16_t fc,uint16_t bc,uint16_t sizey,uint16_t mode)
{
	uint16_t x0=x,m=0;
  uint16_t TypefaceNum=(sizey/8+((sizey%8)?1:0))*sizey;
	uint16_t HZnum=sizeof(tfont16)/sizeof(typFNT_GB16);	//统计汉字数目
	for(uint16_t k=0;k<HZnum;k++) 
	{
		if ((tfont16[k].Index[0]==*(s))&&(tfont16[k].Index[1]==*(s+1)))
		{ 	
			LCD_Address_Set(x,y,x+sizey-1,y+sizey-1);
			for(uint16_t i=0;i<TypefaceNum;i++)
			{
				for(uint16_t j=0;j<8;j++)
				{	
					if(!mode)//非叠加方式
					{
						if(tfont16[k].Msk[i]&(0x01<<j))LCD_WR_DATA16(fc);
						else LCD_WR_DATA16(bc);
						m++;
						if(m%sizey==0)
						{
							m=0;
							break;
						}
					}
					else//叠加方式
					{
						if(tfont16[k].Msk[i]&(0x01<<j))	LCD_DrawPoint(x,y,fc);//画一个点
						x++;
						if((x-x0)==sizey)
						{
							x=x0;
							y++;
							break;
						}
					}
				}
			}
		}				  	
		continue;  //查找到对应点阵字库立即退出，防止多个汉字重复取模带来影响
	}
} 


/******************************************************************************
      函数说明：显示单个24x24汉字
      入口数据：x,y显示坐标
                *s 要显示的汉字
                fc 字的颜色
                bc 字的背景色
                sizey 字号
                mode:  0非叠加模式  1叠加模式
      返回值：  无
******************************************************************************/
void LCD_ShowChinese24x24(uint16_t x,uint16_t y,uint8_t *s,uint16_t fc,uint16_t bc,uint16_t sizey,uint16_t mode)
{
	uint16_t x0=x,m=0;
	uint16_t TypefaceNum=(sizey/8+((sizey%8)?1:0))*sizey;
	uint16_t HZnum=sizeof(tfont24)/sizeof(typFNT_GB24);	//统计汉字数目
	for(uint16_t k=0;k<HZnum;k++) 
	{
		if ((tfont24[k].Index[0]==*(s))&&(tfont24[k].Index[1]==*(s+1)))
		{ 	
			LCD_Address_Set(x,y,x+sizey-1,y+sizey-1);
			for(uint16_t i=0;i<TypefaceNum;i++)
			{
				for(uint16_t j=0;j<8;j++)
				{	
					if(!mode)//非叠加方式
					{
						if(tfont24[k].Msk[i]&(0x01<<j))LCD_WR_DATA16(fc);
						else LCD_WR_DATA16(bc);
						m++;
						if(m%sizey==0)
						{
							m=0;
							break;
						}
					}
					else//叠加方式
					{
						if(tfont24[k].Msk[i]&(0x01<<j))	LCD_DrawPoint(x,y,fc);//画一个点
						x++;
						if((x-x0)==sizey)
						{
							x=x0;
							y++;
							break;
						}
					}
				}
			}
		}				  	
		continue;  //查找到对应点阵字库立即退出，防止多个汉字重复取模带来影响
	}
} 

/******************************************************************************
      函数说明：显示单个32x32汉字
      入口数据：x,y显示坐标
                *s 要显示的汉字
                fc 字的颜色
                bc 字的背景色
                sizey 字号
                mode:  0非叠加模式  1叠加模式
      返回值：  无
******************************************************************************/
void LCD_ShowChinese32x32(uint16_t x,uint16_t y,uint8_t *s,uint16_t fc,uint16_t bc,uint16_t sizey,uint16_t mode)
{
	uint16_t  x0=x,m=0;
	uint16_t TypefaceNum=(sizey/8+((sizey%8)?1:0))*sizey;
	uint16_t HZnum=sizeof(tfont32)/sizeof(typFNT_GB32);	//统计汉字数目
	for(uint16_t k=0;k<HZnum;k++) 
	{
		if ((tfont32[k].Index[0]==*(s))&&(tfont32[k].Index[1]==*(s+1)))
		{ 	
			LCD_Address_Set(x,y,x+sizey-1,y+sizey-1);
			for(uint16_t i=0;i<TypefaceNum;i++)
			{
				for(uint16_t j=0;j<8;j++)
				{	
					if(!mode)//非叠加方式
					{
						if(tfont32[k].Msk[i]&(0x01<<j))LCD_WR_DATA16(fc);
						else LCD_WR_DATA16(bc);
						m++;
						if(m%sizey==0)
						{
							m=0;
							break;
						}
					}
					else//叠加方式
					{
						if(tfont32[k].Msk[i]&(0x01<<j))	LCD_DrawPoint(x,y,fc);//画一个点
						x++;
						if((x-x0)==sizey)
						{
							x=x0;
							y++;
							break;
						}
					}
				}
			}
		}				  	
		continue;  //查找到对应点阵字库立即退出，防止多个汉字重复取模带来影响
	}
}
/******************************************************************************
      函数说明：显示汉字串
      入口数据：x,y显示坐标
                *s 要显示的汉字串
                fc 字的颜色
                bc 字的背景色
                sizey 字号 可选 16 24 32
                mode:  0非叠加模式  1叠加模式
      返回值：  无
******************************************************************************/
void LCD_ShowChinese(uint16_t x,uint16_t y,uint8_t *s,uint16_t fc,uint16_t bc,uint16_t sizey,uint16_t mode)
{
	while(*s!=0)
	{
		if(sizey==12) LCD_ShowChinese12x12(x,y,s,fc,bc,sizey,mode);
		else if(sizey==16) LCD_ShowChinese16x16(x,y,s,fc,bc,sizey,mode);
		else if(sizey==24) LCD_ShowChinese24x24(x,y,s,fc,bc,sizey,mode);
		else if(sizey==32) LCD_ShowChinese32x32(x,y,s,fc,bc,sizey,mode);
		else return;
		s+=2;
		x+=sizey;
	}
}
/******************************************************************************
      函数说明：显示单个字符
      入口数据：x,y显示坐标
                num 要显示的字符
                fc 字的颜色
                bc 字的背景色
                sizey 字号
                mode:  0非叠加模式  1叠加模式
      返回值：  无
******************************************************************************/
void LCD_ShowChar(uint16_t x,uint16_t y,uint16_t num,uint16_t fc,uint16_t bc,uint16_t sizey,uint16_t mode)
{
	uint16_t x0=x,m=0,temp=0;
	uint16_t sizex=sizey/2;
	uint16_t TypefaceNum=(sizex/8+((sizex%8)?1:0))*sizey;
	num=num-' ';    //得到偏移后的值
	LCD_Address_Set(x,y,x+sizex-1,y+sizey-1);  //设置光标位置 
	for(uint16_t i=0;i<TypefaceNum;i++)
	{ 
		if(sizey==12)temp=ascii_1206[num][i];		       //调用6x12字体
		else if(sizey==16)temp=ascii_1608[num][i];		 //调用8x16字体
		else if(sizey==24)temp=ascii_2412[num][i];		 //调用12x24字体
		else if(sizey==32)temp=ascii_3216[num][i];		 //调用16x32字体
		else return;
		for(uint16_t t=0;t<8;t++)
		{
			if(!mode)//非叠加模式
			{
				if(temp&(0x01<<t))LCD_WR_DATA16(fc);
				else LCD_WR_DATA16(bc);
				m++;
				if(m%sizex==0)
				{
					m=0;
					break;
				}
			}
			else//叠加模式
			{
				if(temp&(0x01<<t))LCD_DrawPoint(x,y,fc);//画一个点
				x++;
				if((x-x0)==sizex)
				{
					x=x0;
					y++;
					break;
				}
			}
		}
	}   	 	  
}


/******************************************************************************
      函数说明：显示字符串
      入口数据：x,y显示坐标
                *p 要显示的字符串
                fc 字的颜色
                bc 字的背景色
                sizey 字号
                mode:  0非叠加模式  1叠加模式
      返回值：  无
******************************************************************************/
void LCD_ShowString(uint16_t x,uint16_t y,const uint8_t *p,uint16_t fc,uint16_t bc,uint16_t sizey,uint16_t mode)
{         
	while(*p!='\0')
	{       
		LCD_ShowChar(x,y,*p,fc,bc,sizey,mode);
		x+=sizey/2;
		p++;
	}  
}


/******************************************************************************
      函数说明：幂运算
      入口数据：m底数，n指数
      返回值：  无
******************************************************************************/
uint32_t mypow(uint16_t m, uint16_t n){
    uint32_t ans = 1;
    while(n)
		{
        if(n&1)
            ans *= m; 
        m *= m;        
        n >>= 1;      
    }
    return ans;
}
/******************************************************************************
      函数说明：显示整数变量
      入口数据：x,y显示坐标
                num 要显示整数变量
                len 要显示的位数
                fc 字的颜色
                bc 字的背景色
                sizey 字号
      返回值：  无
******************************************************************************/
void LCD_ShowIntNum(uint16_t x,uint16_t y,uint16_t num,uint16_t len,uint16_t fc,uint16_t bc,uint16_t sizey)
{         	
	uint16_t temp=0;
	uint16_t enshow=0;
	uint16_t sizex=sizey/2;
	for(uint16_t t=0;t<len;t++)
	{
		temp=(num/mypow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				LCD_ShowChar(x+t*sizex,y,' ',fc,bc,sizey,0);
				continue;
			}else enshow=1; 
		 	 
		}
	 	LCD_ShowChar(x+t*sizex,y,temp+48,fc,bc,sizey,0);
	}
} 


/******************************************************************************
      函数说明：显示两位小数变量
      入口数据：x,y显示坐标
                num 要显示小数变量
                len 要显示的位数
                fc 字的颜色
                bc 字的背景色
                sizey 字号
      返回值：  无
******************************************************************************/
void LCD_ShowFloatNum1(uint16_t x,uint16_t y,float num,uint16_t len,uint16_t fc,uint16_t bc,uint16_t sizey)
{         	
	uint16_t temp=0;
	uint16_t sizex=sizey/2;
	uint16_t num1=num*100;
	for(uint16_t t=0;t<len;t++)
	{
		temp=(num1/mypow(10,len-t-1))%10;
		if(t==(len-2))
		{
			LCD_ShowChar(x+(len-2)*sizex,y,'.',fc,bc,sizey,0);
			t++;
			len+=1;
		}
	 	LCD_ShowChar(x+t*sizex,y,temp+48,fc,bc,sizey,0);
	}
}


/******************************************************************************
      函数说明：显示图片
      入口数据：x,y起点坐标
                length 图片长度
                width  图片宽度
                pic[]  图片数组    
      返回值：  无
******************************************************************************/
void LCD_ShowPicture(uint16_t x,uint16_t y,uint16_t length,uint16_t width,const uint8_t pic[])
{
	uint16_t i,j;
	uint32_t k=0;
	LCD_Address_Set(x,y,x+length-1,y+width-1);
	for(i=0;i<length;i++)
	{
		for(j=0;j<width;j++)
		{
			LCD_WR_DATA08(pic[k*2]);
			LCD_WR_DATA08(pic[k*2+1]);
			k++;
		}
	}			
}

