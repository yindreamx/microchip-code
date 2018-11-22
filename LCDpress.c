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

int press()
{
	int dem;
	if (ON==0) //Nut duoc nhan
	{ 	
		LCD_busy_delay(); //Thoi gian de mach on dinh trang thai, bat 2 trang thai truoc va sau
		if (ON!=0)
		{
			return 1;
		}
	}
	else
		return 0; //Khong co nut nhan
	

}
 
void main()
{
	char str[20];
	char dem = 0;
	TMOD = 0x01;
	LCD_setup(); //LCD Setup
	LCD_cmd(0x80); //Set cursor
	LCD_string("Dem lan: ");
	while(1)
	{
		if (press()==1)
		{
			dem = dem+1;
		}
		//Gan doan text can hien thi vao string
		LCD_cmd(0x89); 
		sprintf(str,"%d",dem);
		LCD_string(str);
		LCD_busy_delay();
	}
}



