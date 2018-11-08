#include <RX89X51.H>
#define LCD_rs P2_5
#define LCD_rw P2_6
#define LCD_en P2_7
#define LCD_data P0

int LCD_busy_delay(int N)
{
	unsigned char i,j;
	for(i=1;i<N;i++)
		for(j=1;j<255;j++);
}
void LCD_cmd(unsigned char var)
{
	//Set cursor
	LCD_rs = 0;
	LCD_rw = 0;
	LCD_data = var;
	LCD_en = 1;
	LCD_en = 0;
	LCD_busy_delay(50);
}
void LCD_shift(var)
{
	LCD_rs = 0;
	LCD_rw = 0;
	LCD_data = var;
	LCD_en = 1;
	LCD_en = 0;
	LCD_busy_delay(50);
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
	LCD_busy_delay(50);
}
void LCD_string(unsigned char *var)
{
	while(*var)
		LCD_senddata(*var++);
}
void LCD_build(unsigned char loc, unsigned char *msg) //Ham nap du lieu vao CGRAM
{
	unsigned char i;
	if (loc<8)
	{
		LCD_cmd(0x40+loc*8);
		for (i=0;i<8;i++)
			LCD_senddata(msg[i]);
	}
}
 
void main()
{
	char i;
	//Khai bao mang cua custom character
	unsigned char Custom_Char1[8] = {0x00,0x00,0x00,0x0E,0x0E,0x0E,0x00,0x00};
	unsigned char Custom_Char2[8] = {0x00,0x00,0x04,0x0E,0x0E,0x0E,0x00,0x00};
	unsigned char Custom_Char3[8] = {0x00,0x04,0x04,0x0E,0x0E,0x0E,0x00,0x00};
	//LCD Setup
	LCD_setup();
	//Nap vao CGRAM
	LCD_build(0,Custom_Char1[8]);
	LCD_build(1,Custom_Char2[8]);
	LCD_build(2,Custom_Char3[8]);
	LCD_cmd(0x80); //Set cursor
	LCD_string("HEHE"); //Send string 
	while(1)
	{
		LCD_cmd(0xC9);
		for(i=0;i<3;i++)
			LCD_senddata(i);
		for(i=2;i>=0;i--)
			LCD_senddata(i);
	}
}



