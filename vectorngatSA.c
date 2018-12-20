#include <REGX51.H>
#include <string.h>
char d;
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
	d=SBUF;
	string("OK");
	string(10);
	switch(d)               
        {                               
        	 case '1':
             P0_1=0x01;
             P0_2=0x00;
             break;
             case '2':
             P0_1=0x01;
             P0_2=0x01;
             break;
             case '3':
             P0_1=0x00;
             P0_2=0x00;
             break;
             case '4':
             P0_1=0x00;
             P0_2=0x01;
             break;             
        }
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