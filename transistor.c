int delay(int N) //delay milisecond
{
	int i,j;
	for(i=0;i<=N;i++)
		for(j=0;j<=125;j++);
}
	sbit K0=P2^0;
	sbit K1=P2^1;
int main()
{
	
	int x[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};


	while(1)
		{
			P0=0x02;
			K0=1;
			K1=0;
			delay(10);
			P0=0x79;
			K0=0;
			K1=1;
			delay(10);
		}

}