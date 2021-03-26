#include"conio.h"
#include"stdio.h"
#define x 5
#define y 5
#define v 5
#define h 5
void main ()
{
int m[v][h],f,c,mayor,menor,nume,xi,j,t,i,col,fil;
clrscr();
mayor=0;
fil=2;
for(f=0;f<v;f++)
{
col=30;
 for(c=0;c<h;c++)
    { gotoxy(30,5);
   //   cprintf("numero [%d][%d];",f,c);
      scanf("%d",&m[v][h]);
      gotoxy(col,fil);
      cprintf("%d",m[v][h]);
      col=col+2;
      if(mayor<m[v][h])
	mayor=m[v][h];
	if(menor>m[v][h])
	   menor=m[v][h];
    }
    fil=fil+4;
 }
    //cprintf("\%d",m[v][h]);
    cprintf("\el numero mayor es:%d",mayor);
    cprintf("\el menor es:%d",menor);
    getch();
}
