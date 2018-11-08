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
	int i,j,time,k;

	for(k=0;k<100;k++)
	{
		i=k/10;
		j=k%10;
		for(time=0;time<=50;time++)
		{
			P0=x[i];
			K0=1;
			K1=0;
			delay(10);
			P0=x[j];
			K0=0;
			K1=1;
			delay(10);
		}

}