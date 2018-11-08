include <reg51.h>
//Ngo Hung Cuong
unsigned char a,c,d;
unsigned char i,j,t,k;
void delay(void);
void delay50ms(void);
void main()
{
	//khoi tao cho bo dinh thoi 0
	//dau tien tat tat ca cac led
	TMOD=1;
	tiep:
	P1=0xff;
	a=0xff;//tat ca cac led tat
	delay();
	for(i=0;i<8;++i)
	{
		d=0xff;
		for(j=0;j<i;++j)
			d>>=1;
		a=0xff;
		for(j=0;j<8-i;++j)
		{
			a<<=1;
			c=0;
			for(k=0;k<j;++k)
			{
				c<<=1;
				c|=1;
			}
			a|=c;
			a&=d;
			P1=a;
			delay();
		}
	}
	goto tiep;
}
void delay50ms(void)
{
	//tre khoang 50ms
	TR0=0;
	TL0=0xb0;
	TH0=0x3c;
	TF0=0;
	TR0=1;
	while(!TF0);
	TR0=0;
	TF0=0;
}
void delay(void)
{
	//tre 500ms
	for(t=0;t<10;++t)
		delay50ms();
}