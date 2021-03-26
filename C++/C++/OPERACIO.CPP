#include <stdio.h>
#include<conio.h>
void main()
{

float div,f,c,sum,mult,rest;
div=0;
f=c=0;
clrscr();
cprintf("\n\ringerse un numero:");
scanf("%f",&f);
cprintf("\n\ringrese un segundo numero:");
scanf("%f",&c);
sum=f+c;
div=f/c;
mult=f*c;
rest=f-c;
cprintf("\n\rla suma es:%f",sum);
cprintf("\n\rla resta es:%f",rest);
cprintf("\n\rla multiplicacion es:%f",mult);
cprintf("\n\rla division es:%f",div);
getch();
}