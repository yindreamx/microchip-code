#include <REGX51.H>
#include <string.h>
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
main()
{
	SCON=0x50;
	TMOD=0x20;
	PCON=0x80;
	TH1=0xFA;
	TR1=1;
	while(1)
	{
		string("Ahihi");
	}
}