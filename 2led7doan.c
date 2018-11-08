int delay(int N) //delay milisecond
{
	int i,j;
	for(i=0;i<=N;i++)
		for(j=0;j<=125;j++);
}
int main()
{
	int i,j,led1,led2;
	int x[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10}; //khai bao mang gom cac ma hex cho den sang tu 0->9
	int so=52;
	led1=so/10; //lay gia tri hang chuc gan vao led 1
	led2=so%10; //lay gia tri hang don vi gan vao led 2
	while (1)
	{
		for(i=led1;i<=9;i++)
		{
			P0=x[i];
				for(j=led2;j<=9;j++)
				{
					P2=x[j];
					delay(1000);
				}
		}
		for(i=0;i<=9;i++)
			{
				P0=x[i];
					for(j=0;j<=9;j++)
					{
						P2=x[j];
						delay(1000);
					}
	}
}

