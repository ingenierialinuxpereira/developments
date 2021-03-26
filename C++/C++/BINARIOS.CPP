#include<stdio.h>
#include<conio.h>
#include <iostream.h>
#define n 100
void cuadro (int x1,int y1,int x2,int y2);
void octal();
void binario();
void hexadecimal();
void main()
{
int op;
clrscr();
while(op!=4)
{gotoxy(35,24);
printf("\n\r                     <PROGRAMA DE CONVERSIONES>");
gotoxy(30,3);
printf("\n\n\n\n\r                     1..Conversion binaria?");
gotoxy(30,7);
printf("\n\r                     2..Conversion octal?");
gotoxy(30,8);
printf("\n\r                     3..Conversion hexadecimal?");
gotoxy(30,9);
printf("\n\r                     4..Salir...");
gotoxy(30,10);
printf("\n\n\n\r                        Elija una opcion:<");
scanf("%d",&op);
switch(op)
{
case 1:binario();
break;
case 2:octal();
break;
case 3:hexadecimal();
break;
case 4:printf("\n\rSaliendo...");
break;
}
clrscr();
}
}

void binario()
{
int vector[n],i,mod,num,j;
i=1;
clrscr();
printf("\n\rIngrese un valor:");
scanf("%d",&num);
printf("\n\r...BINARIO...\n\r");
j=1;
while(num>=2)
{
mod=num%2;
j++;
num=(num/2);
vector[i]=mod;
i++;
}
vector[i]=mod;

for(i=j;i>0;i--)
   printf("%d",vector[i]);

getch();
}
void octal()
{
int vector[n],num,i,mod,j;
clrscr();
printf("\n\rIngrese un valor:");
scanf("%d",&num);
printf("\n\r...OCTAL...\n\r");
j=1;
i=1;
while(num>=8)
{
mod=num%8;
num=(num/8);
vector[i]=mod;
i++;
j++;
}
vector[i]=num;
for(i=j;i>0;i--)
 printf("%d",vector[i]);
getch();

}
void hexadecimal()
{
int vector[n],i,num,mod;
i=1;
clrscr();
printf("\n\rIngrese un valor:");
cin>>num;
printf("\n\r...HEXADECIMAL...\n\r");
while(num>=16)
{
mod=num%16;
num=(num/16);
vector[i]=mod;
i++;
}
vector[i]=num;

 for(;i>0;i--)
   if(vector[i]>9)
     printf("%c",vector[i]+55);
   else
     printf("%d",vector[i]);

getch();
}
