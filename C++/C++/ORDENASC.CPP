
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
scanf ("%d",& comp);//El limite del vector lo da el usuario y se lee como comp
/*******llamado a las funciones limitadas por usuario con variable comp******/
captura (comp);
orden (comp);
impresion (comp);
/*******************fin llamado funciones******************************/
getch();
}
void captura (int x)
{
int i,y;
for (i=0; i<x; i++)
{
textcolor(WHITE);
cprintf("\n\rIngrese componente:");
scanf ("%d", & a[i]);//almacenamiento en vector
}
}
void orden (int x)
{
int i,h,fr,m,fg;
/**************Burbuja*******************/
for (i=0; i<x; i++)//Vector original
{
 for (m=i; m<x; m++) //Vector temporal
     do{
     fr=a[i];
     a[i]=a[m];
     a[m]=fr;
     }
     while(a[i] > a[m]);//Vector ordenado
}
}
void impresion (int x)
{
int i,h,fg;
textcolor(WHITE);
cprintf ("\n\El orden ascendente es:");
for (i=0; i<x; i++)
{
printf("|%d|",a[i]);
}
cprintf("\n\rOprima enter para salir");
}
