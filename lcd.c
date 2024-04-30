#include "lcd.h"
#include "forts.h"
/******************************************************************************
      ����˵����LCDд��8λ����
      ������ݣ�dat д�������
      ����ֵ��  ��
******************************************************************************/
void LCD_WR_DATA08(uint8_t dat)
{
	LCD_CS_Clr();
	HAL_SPI_Transmit(&hspi1,&dat,1,0xffff);
	LCD_CS_Set();
}
/******************************************************************************
      ����˵����LCDд��16λ����
      ������ݣ�dat д�������
      ����ֵ��  ��
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
      ����˵����LCDд������
      ������ݣ�dat д�������
      ����ֵ��  ��
******************************************************************************/
void LCD_WR_REG(uint8_t dat)
{
	LCD_DC_Clr();
	LCD_WR_DATA08(dat);
	LCD_DC_Set();
}
/******************************************************************************
      ����˵����������ʼ�ͽ�����ַ
      ������ݣ�x1,x2 �����е���ʼ�ͽ�����ַ
                y1,y2 �����е���ʼ�ͽ�����ַ
      ����ֵ��  ��
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
      ����˵����LCD��ʼ��
      ������ݣ���
      ����ֵ��  ��
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
      ����˵������ָ�����������ɫ
      ������ݣ�xsta,ysta   ��ʼ����
                xend,yend   ��ֹ����
								color       Ҫ������ɫ
      ����ֵ��  ��
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
      ����˵������ָ��λ�û���
      ������ݣ�x,y ��������
                color �����ɫ
      ����ֵ��  ��
******************************************************************************/
void LCD_DrawPoint(uint16_t x,uint16_t y,uint16_t color)
{
	LCD_Address_Set(x,y,x,y);
	LCD_WR_DATA16(color);
} 
/******************************************************************************
      ����˵��������
      ������ݣ�x1,y1   ��ʼ����
                x2,y2   ��ֹ����
                color   �ߵ���ɫ
      ����ֵ��  ��
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
      ����˵����������
      ������ݣ�x1,y1   ��ʼ����
                x2,y2   ��ֹ����
                color   ���ε���ɫ
      ����ֵ��  ��
******************************************************************************/
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,uint16_t color)
{
	LCD_DrawLine(x1,y1,x2,y1,color);
	LCD_DrawLine(x1,y1,x1,y2,color);
	LCD_DrawLine(x1,y2,x2,y2,color);
	LCD_DrawLine(x2,y1,x2,y2,color);
}
/******************************************************************************
      ����˵������Բ
      ������ݣ�x0,y0   Բ������
                r       �뾶
                color   Բ����ɫ
      ����ֵ��  ��
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
		if((a*a+b*b)>(r*r))//�ж�Ҫ���ĵ��Ƿ��Զ
		{
			b--;
		}
	}
}
/******************************************************************************
      ����˵������ʾ����12x12����
      ������ݣ�x,y��ʾ����
                *s Ҫ��ʾ�ĺ���
                fc �ֵ���ɫ
                bc �ֵı���ɫ
                sizey �ֺ�
                mode:  0�ǵ���ģʽ  1����ģʽ
      ����ֵ��  ��
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
					if(!mode)//�ǵ��ӷ�ʽ
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
					else//���ӷ�ʽ
					{
						if(tfont12[k].Msk[i]&(0x01<<j))	LCD_DrawPoint(x,y,fc);//��һ����
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
		continue;  //���ҵ���Ӧ�����ֿ������˳�����ֹ��������ظ�ȡģ����Ӱ��
	}
} 

/******************************************************************************
      ����˵������ʾ����16x16����
      ������ݣ�x,y��ʾ����
                *s Ҫ��ʾ�ĺ���
                fc �ֵ���ɫ
                bc �ֵı���ɫ
                sizey �ֺ�
                mode:  0�ǵ���ģʽ  1����ģʽ
      ����ֵ��  ��
******************************************************************************/
void LCD_ShowChinese16x16(uint16_t x,uint16_t y,uint8_t *s,uint16_t fc,uint16_t bc,uint16_t sizey,uint16_t mode)
{
	uint16_t x0=x,m=0;
  uint16_t TypefaceNum=(sizey/8+((sizey%8)?1:0))*sizey;
	uint16_t HZnum=sizeof(tfont16)/sizeof(typFNT_GB16);	//ͳ�ƺ�����Ŀ
	for(uint16_t k=0;k<HZnum;k++) 
	{
		if ((tfont16[k].Index[0]==*(s))&&(tfont16[k].Index[1]==*(s+1)))
		{ 	
			LCD_Address_Set(x,y,x+sizey-1,y+sizey-1);
			for(uint16_t i=0;i<TypefaceNum;i++)
			{
				for(uint16_t j=0;j<8;j++)
				{	
					if(!mode)//�ǵ��ӷ�ʽ
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
					else//���ӷ�ʽ
					{
						if(tfont16[k].Msk[i]&(0x01<<j))	LCD_DrawPoint(x,y,fc);//��һ����
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
		continue;  //���ҵ���Ӧ�����ֿ������˳�����ֹ��������ظ�ȡģ����Ӱ��
	}
} 


/******************************************************************************
      ����˵������ʾ����24x24����
      ������ݣ�x,y��ʾ����
                *s Ҫ��ʾ�ĺ���
                fc �ֵ���ɫ
                bc �ֵı���ɫ
                sizey �ֺ�
                mode:  0�ǵ���ģʽ  1����ģʽ
      ����ֵ��  ��
******************************************************************************/
void LCD_ShowChinese24x24(uint16_t x,uint16_t y,uint8_t *s,uint16_t fc,uint16_t bc,uint16_t sizey,uint16_t mode)
{
	uint16_t x0=x,m=0;
	uint16_t TypefaceNum=(sizey/8+((sizey%8)?1:0))*sizey;
	uint16_t HZnum=sizeof(tfont24)/sizeof(typFNT_GB24);	//ͳ�ƺ�����Ŀ
	for(uint16_t k=0;k<HZnum;k++) 
	{
		if ((tfont24[k].Index[0]==*(s))&&(tfont24[k].Index[1]==*(s+1)))
		{ 	
			LCD_Address_Set(x,y,x+sizey-1,y+sizey-1);
			for(uint16_t i=0;i<TypefaceNum;i++)
			{
				for(uint16_t j=0;j<8;j++)
				{	
					if(!mode)//�ǵ��ӷ�ʽ
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
					else//���ӷ�ʽ
					{
						if(tfont24[k].Msk[i]&(0x01<<j))	LCD_DrawPoint(x,y,fc);//��һ����
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
		continue;  //���ҵ���Ӧ�����ֿ������˳�����ֹ��������ظ�ȡģ����Ӱ��
	}
} 

/******************************************************************************
      ����˵������ʾ����32x32����
      ������ݣ�x,y��ʾ����
                *s Ҫ��ʾ�ĺ���
                fc �ֵ���ɫ
                bc �ֵı���ɫ
                sizey �ֺ�
                mode:  0�ǵ���ģʽ  1����ģʽ
      ����ֵ��  ��
******************************************************************************/
void LCD_ShowChinese32x32(uint16_t x,uint16_t y,uint8_t *s,uint16_t fc,uint16_t bc,uint16_t sizey,uint16_t mode)
{
	uint16_t  x0=x,m=0;
	uint16_t TypefaceNum=(sizey/8+((sizey%8)?1:0))*sizey;
	uint16_t HZnum=sizeof(tfont32)/sizeof(typFNT_GB32);	//ͳ�ƺ�����Ŀ
	for(uint16_t k=0;k<HZnum;k++) 
	{
		if ((tfont32[k].Index[0]==*(s))&&(tfont32[k].Index[1]==*(s+1)))
		{ 	
			LCD_Address_Set(x,y,x+sizey-1,y+sizey-1);
			for(uint16_t i=0;i<TypefaceNum;i++)
			{
				for(uint16_t j=0;j<8;j++)
				{	
					if(!mode)//�ǵ��ӷ�ʽ
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
					else//���ӷ�ʽ
					{
						if(tfont32[k].Msk[i]&(0x01<<j))	LCD_DrawPoint(x,y,fc);//��һ����
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
		continue;  //���ҵ���Ӧ�����ֿ������˳�����ֹ��������ظ�ȡģ����Ӱ��
	}
}
/******************************************************************************
      ����˵������ʾ���ִ�
      ������ݣ�x,y��ʾ����
                *s Ҫ��ʾ�ĺ��ִ�
                fc �ֵ���ɫ
                bc �ֵı���ɫ
                sizey �ֺ� ��ѡ 16 24 32
                mode:  0�ǵ���ģʽ  1����ģʽ
      ����ֵ��  ��
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
      ����˵������ʾ�����ַ�
      ������ݣ�x,y��ʾ����
                num Ҫ��ʾ���ַ�
                fc �ֵ���ɫ
                bc �ֵı���ɫ
                sizey �ֺ�
                mode:  0�ǵ���ģʽ  1����ģʽ
      ����ֵ��  ��
******************************************************************************/
void LCD_ShowChar(uint16_t x,uint16_t y,uint16_t num,uint16_t fc,uint16_t bc,uint16_t sizey,uint16_t mode)
{
	uint16_t x0=x,m=0,temp=0;
	uint16_t sizex=sizey/2;
	uint16_t TypefaceNum=(sizex/8+((sizex%8)?1:0))*sizey;
	num=num-' ';    //�õ�ƫ�ƺ��ֵ
	LCD_Address_Set(x,y,x+sizex-1,y+sizey-1);  //���ù��λ�� 
	for(uint16_t i=0;i<TypefaceNum;i++)
	{ 
		if(sizey==12)temp=ascii_1206[num][i];		       //����6x12����
		else if(sizey==16)temp=ascii_1608[num][i];		 //����8x16����
		else if(sizey==24)temp=ascii_2412[num][i];		 //����12x24����
		else if(sizey==32)temp=ascii_3216[num][i];		 //����16x32����
		else return;
		for(uint16_t t=0;t<8;t++)
		{
			if(!mode)//�ǵ���ģʽ
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
			else//����ģʽ
			{
				if(temp&(0x01<<t))LCD_DrawPoint(x,y,fc);//��һ����
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
      ����˵������ʾ�ַ���
      ������ݣ�x,y��ʾ����
                *p Ҫ��ʾ���ַ���
                fc �ֵ���ɫ
                bc �ֵı���ɫ
                sizey �ֺ�
                mode:  0�ǵ���ģʽ  1����ģʽ
      ����ֵ��  ��
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
      ����˵����������
      ������ݣ�m������nָ��
      ����ֵ��  ��
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
      ����˵������ʾ��������
      ������ݣ�x,y��ʾ����
                num Ҫ��ʾ��������
                len Ҫ��ʾ��λ��
                fc �ֵ���ɫ
                bc �ֵı���ɫ
                sizey �ֺ�
      ����ֵ��  ��
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
      ����˵������ʾ��λС������
      ������ݣ�x,y��ʾ����
                num Ҫ��ʾС������
                len Ҫ��ʾ��λ��
                fc �ֵ���ɫ
                bc �ֵı���ɫ
                sizey �ֺ�
      ����ֵ��  ��
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
      ����˵������ʾͼƬ
      ������ݣ�x,y�������
                length ͼƬ����
                width  ͼƬ���
                pic[]  ͼƬ����    
      ����ֵ��  ��
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

