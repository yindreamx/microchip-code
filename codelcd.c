#include <REGX51.H>
#define LCD_data P0 
#define LCD_rs   P2_5 
#define LCD_rw   P2_6 
#define LCD_en   P2_7
delay (int N)	
{
	int i,j;
	for (i=0;i<=N;i++)
		for (j=0;j<=125;j++);
}
void LCD_busy_delay(int N) 
{          
	unsigned char i,j;          
	for(i=0;i<N;i++)                  
		for(j=0;j<255;j++); 
}
void LCD_command(unsigned char var)
{
	LCD_data = var;
	LCD_rs = 0;
	LCD_rw = 0;
	LCD_en = 0;
	LCD_en = 1;
	LCD_busy_delay(50);
}
void LCD_setup ()
{
	//function set
	LCD_command(0x38);
	//entry mode set
	LCD_command(0x06);
	//Display ON/OFF
	LCD_command(0x0E);
	//Clear display
	LCD_command(0x01);
	//Cursor display shift
	//LCD_command(0x10);
}
void LCD_send (unsigned char var)
{
	LCD_data = var;
	LCD_rs = 1;
	LCD_rw = 0;
	LCD_en = 0;
	LCD_en = 1;
	LCD_busy_delay(50);
}
void LCD_string (unsigned char *var)
{
	while (*var)	//still string end
	LCD_send(*var++); //send char one by one
}
void LCD_cursor (unsigned char var)
{
	LCD_data = var;
	LCD_rs = 0;
	LCD_rw = 0;
	LCD_en = 0;
	LCD_en = 1;
	LCD_busy_delay(50);
}
void LCD_custom (unsigned char vitri, unsigned char *par)
{
	unsigned char i;
	if(vitri<8)
	{
		LCD_command(0x40+(vitri*8));
		for (i=0;i<8;i++)
		{
			LCD_send(par[i]);
		}
	}
}
//void unsigned char ptr1[8]={0x00,0x04,0x02,0x1F,0x02,0x04,0x00,0x00};
	 
main ()
{
	 unsigned char i=0,add=0x80,t,vitri;
	 unsigned char char1[8]={0x03,0x07,0x0D,0x0F,0x07,0x02,0x04,0x00};
	 unsigned char char2[8]={0x18,0x1C,0x16,0x1E,0x1C,0x08,0x04,0x00};
	 LCD_setup();
	 LCD_custom(0,char1); 
	 LCD_custom(1,char2);
//	 for (i=0;i<8;i++)
//	 {
//	 	LCD_send(i);
//	 }
	 while (1)
	 {
	 	for (i=0;i<=15;i++)
		{
			vitri=add+i;
			LCD_cursor(vitri);
	 		LCD_send(0);
	 		LCD_send(1);
	 		delay(250);
	 		LCD_command(0x01);
			if (vitri==0x8F)
			{
				for (t=1;t<=14;t++)
				{
				LCD_cursor(vitri-t);
	 			LCD_send(0);
	 			LCD_send(1);
	 			delay(250);
	 			LCD_command(0x01);
				}	
	 		}
		}
	 }
}