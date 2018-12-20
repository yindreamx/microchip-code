#include <REGX51.H>
#include <string.h>
char d;									  
volatile int j=0;
volatile int a[10];
void send(unsigned char x)
{
	SBUF=x;
	while(TI==0){};
	TI=0;
}
void string(char *chuoi)
{
	char i;
	for(i=0;i<strlen(chuoi);i++)
	{
		send(chuoi[i]);
	}
}
void stop() interrupt 4
{
char k;
	
	a[j]=SBUF;
	
	if(a[j]=='.')
	{
			for(k=0;k<j;k++)
		{
		send(a[k]);
		a[k]=0;		
		}
		j=0;	   
		}
	  	   	j++;
	RI=0;
}
main()
{

	SCON=0x50;
	TMOD=0x20;
	PCON=0x80;
	IE=0x90;
	TH1=0xFA;
	TR1=1;
	while(1);
}