#include <REGX51.H>
#include <stdio.h>
#define LCD_rs P2_5
#define LCD_rw P2_6
#define LCD_en P2_7
#define LCD_data P0
#define ON P1_0
volatile int display=0;
volatile int fre;
int dem=0;

void LCD_busy_delay(void)
{
	TH0 = 0x3C;
	TL0 = 0xB0;
	TR0 = 1;
	while(!TF0){}
	TR0 = 0;
	TF0 = 0;
}
void LCD_cmd(unsigned char var)
{
	//Set cursor
	LCD_rs = 0;
	LCD_rw = 0;
	LCD_data = var;
	LCD_en = 1;
	LCD_en = 0;
	LCD_busy_delay();
}
void LCD_shift(var)
{
	LCD_rs = 0;
	LCD_rw = 0;
	LCD_data = var;
	LCD_en = 1;
	LCD_en = 0;
	LCD_busy_delay();
}
void LCD_setup()
{
	//Function Set
	LCD_cmd(0x38);
	//Entry Mode Set
	LCD_cmd(0x06);
	//Display ON/OFF Control
	LCD_cmd(0x0F);
	//Clear Display
	LCD_cmd(0x01);
}
void LCD_senddata(unsigned char var)
{
	LCD_rs = 1;
	LCD_rw = 0;
	LCD_data = var;
	LCD_en = 1;
	LCD_en = 0;
	LCD_busy_delay();
}
void LCD_string(unsigned char *var)
{
	while(*var)
		LCD_senddata(*var++);
}

void tanso(void) interrupt 1
{ 	

	TR0 = 0;
	TR1 = 0;
	TH0 = 0x3C;
	TL0 = 0xB0;
	dem++;
	display= display + ((int)TH1*256+(int)TL1);
	TH1 = 0x00;
	TL1 = 0x00;
	if (dem==20)
	{
		fre=display;
		dem=0;
		display=0;
	}
	
	TR0 = 1;
	TR1 = 1;
}
void main()
{
	char str[10];
	TMOD = 0x51;
	EA = 1;
	ET0 = 1;
	LCD_setup(); //LCD Setup
	LCD_cmd(0x80); //Set cursor
	LCD_string("Tan so: ");	
	TH0 = 0x3C;
	TL0 = 0xB0;
	TR1 = 1;
	TR0  =1;
	while(1)
	{
		sprintf(str,"%d   ",fre);
		LCD_cmd(0x87);
		LCD_string(str);	
	}
}