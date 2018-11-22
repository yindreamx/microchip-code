#include <REGX51.H>
#include <stdio.h>
#define LCD_rs P2_5
#define LCD_rw P2_6
#define LCD_en P2_7
#define LCD_data P0
#define ON P1_0

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
 
void main()
{
	char str[10];
	//int dem;
	//unsigned char high, low;
	unsigned int display;
	TMOD = 0x51;
	LCD_setup(); //LCD Setup
	LCD_cmd(0x80); //Set cursor
	LCD_string("Xung:");
	TR1 = 1;

	while(1)
	{
		display = (int)TH1*256+(int)TL1;
		//Gan doan text can hien thi vao string
		sprintf(str,"%d",display);
		LCD_cmd(0x87);
		LCD_string(str);	
		
	}
}