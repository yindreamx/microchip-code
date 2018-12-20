#include <REGX51.H>
int dem = 0;
void ledinterrupt(void) interrupt 1
{
	TR0 = 0;
	TH0 = 0x3C;
	TL0 = 0xB0;
	dem++;
	if(dem==20) //Ngat 20 lan bat dau thuc hien lenh
	{
		P0 = !P0;
		dem = 0;
	}
	TR0 = 1;
}
main()
{
	TMOD = 0x01; //Timer 0, mode 1
	EA = 1; //Cho phep su dung ngat
	ET0 = 1; //Cho phep dung ngat timer 0
	TH0 = 0x3C;
	TL0 = 0xB0;
	TR0 = 1;
	while(1);
}