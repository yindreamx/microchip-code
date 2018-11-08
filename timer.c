void delay(void)
{
	char i;
	for (i=0;i<20;i++)
	{
	TH0 = 0x3C;
	TL0 = 0xB0;
	TR0 = 1;
	while(!TF0){}
	TR0 = 0;
	TF0 = 0;
	}
}
void main()
{ 
	TMOD = 0x01;
	P0_0 = 0;
	while(1)
	{
		P0_0 = 1;
		delay();
		P0_0 = 0;
		delay();
	}
}
