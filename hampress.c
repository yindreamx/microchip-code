#define ON P0_0
void delay(void)
{
	TH0 = 0xFF;
	TL0 = 0xCE;
	TR0 = 1;
	while(!TF0){}
	TR0 = 0;
	TF0 = 0;
}
int press()
{
	if (ON==0) //Nut duoc nhan
	{ 
		delay(); //Thoi gian de mach on dinh trang thai, bat 2 trang thai truoc va sau
		while(!ON){} //Nut duoc nha
			return 1; //Co nut nhan
	}
	else
		return 0; //Khong co nut nhan
}
int main()
{
	TMOD = 0x01;
	while(1)
	{
		
		if(press()==1)
			P1 = 1;
		else
			P1 = 0;
	}
}