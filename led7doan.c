int delay(int N) //delay milisecond
{
	int i,j;
	for(i=0;i<=N;i++)
		for(j=0;i<=125;j++);
}
int main()
{
	int i;
	int x[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10}; //khai bao mang gom cac ma hex cho den sang tu 0->9
	while (1)
	for(i=0;i<=9;i++)
		P0=x[i];
	delay(1000);
}

