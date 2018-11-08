int delay(int N) //delay milisecond
{
	int i,j;
	for(i=0;i<=N;i++)
		for(j=0;i<=125;j++);
}
int main()
{
	int i,j,led1,led2;
	int x[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10}; //khai bao mang gom cac ma hex cho den sang tu 0->9
	int P[4]={P0,P1,P2,P3};
	int so=52;
	led1=so/10; //lay gia tri hang chuc gan vao led 1
	led2=so%10; //lay gia tri hang don vi gan vao led 2

	while (1)
	(
			P3=0xFF;
			P0=x[led1];
			delay(1000);
			P1=x[led1];
			P0=x[led2];
			delay(1000);
			P0=0xFF;
			P2=x[led1];
			P1=x[led2];
			delay(1000);
			P1=0xFF;
			P3=x[led1];
			P2=x[led2];
			delay(1000);
			P2=0xFF;
			P3=x[led2];

	)
}

