void delay(void)
{
	TH0 = 0x3C ;
	TL0 = 0xB0 ;
	TR0 = 1;
	while(!TF0){}
	TR0 = 0;
	TF0 = 0;
}
void onesecond(void)
{
	char i;
	for (i=0;i<20;i++)
		delay();
}
main()
{
	unsigned char x[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
	char j;
	TMOD = 0x01;
	while(1)
	{
		for (j=0;j<10;j++)
			P0 = x[j];
			onesecond();
	}
}