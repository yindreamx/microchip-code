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
void main()
{
	char data[10];
	//LCD Setup
	LCD_setup();
	LCD_cmd(0x80); //Set cursor
	sprintf(data,"So dem: %d",x);
	LCD_string(data);
	while(1);
}



