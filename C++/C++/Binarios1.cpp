#include<stdio.h>
#include<conio.h>

#define n 80
void main()
{
long vector[n],num,i,mod,x;
i=1;
clrscr();
printf("\n\r                         <--Ingrese un numero-->");
scanf("%ld",&num);
textcolor(WHITE);
cprintf("        \n\r          Francisco Gutierrez|Carlos Andres Ruiz|Jorge Andres Ramirez");
cprintf("\n\n\n\r                             *-->[");
while(num>=2)
{
mod=num%2;
num=(num/2);
vector[i]=mod;
textcolor(WHITE);
cprintf("%d",vector[i]);
i++;
}
vector[i]=num;
textcolor(WHITE);
cprintf("%d]<--*",vector[i]);

for(i=n;i==1;i--)
{
	if(vector[i]!=NULL)
	{
	cprintf("%d",vector[i]);
	}
}
getch();
}
