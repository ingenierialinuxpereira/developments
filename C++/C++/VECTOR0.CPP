
#include "conio.h"
#include "stdio.h"
int a[100];
void captura(int x);
void orden(int x);
void impresion (int x);
void main ()
{
textbackground(BLUE);
int comp,x;
clrscr();
gotoxy(x,7);
textcolor(WHITE);
textcolor(128);
cprintf("\n\r                   -----------------------------------");
textcolor(YELLOW);
cprintf ("\n\n\n\r                    INGRESE UN TOPE NO MAYOR A [100]:");
scanf ("%d",& comp);
captura (comp);
orden (comp);
impresion (comp);
getch();
}
void captura (int x)
{
int i,y;
for (i=0; i<x; i++)
{
textcolor(WHITE);
cprintf("\n\rIngrese componente:");
scanf ("%d", & a[i]);
}
}
void orden (int x)
{
int i,h,fr,m,fg;
for (i=0; i<x; i++)
{
 for (m=i; m<x; m++)
     do{
     fr=a[i];
     a[i]=a[m];
     a[m]=fr;
     }
     while(a[i] > a[m] && a[m]!=0);
}
}
void impresion (int x)
{
int i,h,fg;
textcolor(WHITE);
cprintf ("\n\El orden ascendente es:");
for (i=0; i<x; i++)
printf ("|%d|", a[i]);
cprintf("\n\rOprima enter para salir");
}
