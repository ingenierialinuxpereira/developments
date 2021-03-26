# include <conio.h>
# include <stdio.h>
# include <iostream.h>
# include <alloc.h>
# include <time.h>
#define ENTER 13
#define fd 77
#define fi 75
#define F10 68

void menu ();
void cuadro (int x1,int y1,int x2,int y2);
void opciones();
void coloreo(int x1,int y1,int x2,int y2);
void main ()
{
clrscr ();
menu ();
}

void menu ()
{
cuadro (1,4,24,76);
cuadro (12,30,15,50);
coloreo(6,5,21,75);
opciones();
}

void coloreo(int x1,int y1,int x2,int y2)
{
int yi,xi;

for(xi=y1;xi<=y2;xi++)
 {
  for(yi=x1;yi<=x2;yi++)
   {
    gotoxy(xi,yi);textcolor(11);
    cprintf("%c",176);
    }
   }
}
void cuadro (int x1,int y1,int x2,int y2)
{
int xi,g;
for (xi=y1; xi<=y2; xi++)
{

gotoxy (xi,x1);
putchar(char(196));
gotoxy (xi,x2);
putchar(char(196));
}
for(xi=4;xi<y2;xi++)
{
gotoxy(xi,3);
putchar(char(196));
}

for(xi=5;xi<y2;xi++)
{
gotoxy(xi,5);
putchar(char(196));
gotoxy(xi,22);
putchar(char(196));
}

for (xi=x1; xi<=x2; xi++)
{
gotoxy (y1,xi);
putchar(char(179));
gotoxy (y2,xi);
putchar(char(179));
}
gotoxy(y1,x1);
putchar(char(218));
gotoxy(y2,x2);
putchar(char(217));
gotoxy(y2,x1);
putchar(char(191));
gotoxy(y1,x2);
putchar(char(192));
}
void opciones()
{
time_t t;
int opc;
char a;
gotoxy(5,23);
textcolor(WHITE);
cprintf("Oprima la flecha derecha");
gotoxy(33,2);
textcolor(WHITE);
cprintf("CIDCA PEREIRA %c%c LENGUAJES II %c NOMINA",174,175,16);
textcolor(LIGHTBLUE);
gotoxy(31,1);
putchar(char(191));
gotoxy(31,3);
putchar(char(217));
gotoxy(31,1);
putchar(char(218));
gotoxy(31,2);
putchar(char(179));
gotoxy(76,22);
putchar(char(180));
gotoxy(4,22);
putchar(char(195));
gotoxy(76,3);
putchar(char(180));
gotoxy(76,5);
putchar(char(180));
gotoxy(4,5);
putchar(char(195));
gotoxy(4,3);
putchar(char(195));
gotoxy(67,24);
textbackground(0);
textcolor(130);
cprintf("%cPACHO%c",01,01);
textcolor(LIGHTBLUE);
gotoxy(9,4);cprintf("EMPLEADOS");
gotoxy(24,4);cprintf("NOMINA");
gotoxy(36,4);cprintf("REPORTES");
gotoxy(50,4);cprintf("ACERCA DE");
gotoxy(66,4);cprintf("SALIR");
opc=1;
gotoxy(37,22);
textcolor(WHITE);
cprintf("SOPORTE");
textcolor(BLUE);

t = time(NULL);
  gotoxy(6,2);
  cprintf("%s", ctime(&t));
while ((a=getch()) !=F10)
{
  t = time(NULL);
  gotoxy(6,2);
  textcolor(BLUE);
  cprintf("%s", ctime(&t));
  textcolor(LIGHTBLUE);
  if (a==fd)
  { switch (opc)
    {
    case 1 :  gotoxy (9,4);
	      textbackground(RED);
	      cprintf ("EMPLEADOS");
	      gotoxy(5,23);
	      printf("Administracion de empleados");
	      gotoxy(66,4);
	      textbackground(0);
	      cprintf("SALIR");
	      opc++;
	      break;
    case 2 :  gotoxy (24,4);
	      textbackground(RED);
	      cprintf ("NOMINA");
	      gotoxy(5,23);
	      printf("Administracion de n¢mina...");
	      textbackground(0);
	      gotoxy (9,4);
	      cprintf ("EMPLEADOS");
	      opc++;
	      break;
     case 3 : gotoxy (36,4);
	      textbackground(RED);
	      cprintf ("REPORTES");
	      gotoxy(5,23);
	      printf("Suministro de reportes..");
	      textbackground(0);
	      gotoxy (24,4);
	      cprintf ("NOMINA");
	      opc++;
	      break;
     case 4 : gotoxy (50,4);
	      textbackground(RED);
	      cprintf ("ACERCA DE");
	      gotoxy(5,23);
	      printf("Informacion del programa...");
	      textbackground(0);
	      gotoxy (36,4);
	      cprintf ("REPORTES");
	      opc++;
	      break;
     case 5 : gotoxy (66,4);
	      textbackground(RED);
	      cprintf ("SALIR");
	      gotoxy(5,23);
	      printf("Para salir favor oprima F10...");
	      textbackground(0);
	      gotoxy (50,4);
	      cprintf ("ACERCA DE");
	      opc=1;
	      break;
    }
    gotoxy(79,24);
  }      else
	 {
	 if(a==fi)
	   {
	 switch(opc)
	    {
	    case 1:gotoxy (50,4);
	      textbackground(RED);
	      cprintf ("ACERCA DE");
	      gotoxy(5,23);
	      printf("Informacion del programa...");
	      gotoxy(66,4);
	      textbackground(0);
	      cprintf("SALIR");
	      opc=5;
	      break;
	      case 2 :  gotoxy (66,4);
	      textbackground(RED);
	      cprintf ("SALIR");
	      gotoxy(5,23);
	      printf("Para salir favor oprima F10...");
	      textbackground(0);
	      gotoxy (9,4);
	      cprintf ("EMPLEADOS");
	      opc--;
	      break;
	      case 3 : gotoxy (9,4);
	      textbackground(RED);
	      cprintf ("EMPLEADOS");
	      gotoxy(5,23);
	      printf("Administracion de empleados");
	      textbackground(0);
	      gotoxy (24,4);
	      cprintf ("NOMINA");
	      opc--;
	      break;
	      case 4 : gotoxy (24,4);
	      textbackground(RED);
	      cprintf ("NOMINA");
	      gotoxy(5,23);
	      printf("Administracion de n¢mina..");
	      textbackground(0);
	      gotoxy (36,4);
	      cprintf ("REPORTES");
	      opc--;
	      break;
	      case 5 : gotoxy (36,4);
	      textbackground(RED);
	      cprintf ("REPORTES");
	      gotoxy(5,23);
	      printf("Suministro de reportes..");
	      textbackground(0);
	      gotoxy (50,4);
	      cprintf ("ACERCA DE");
	      opc--;
	      break;

}
gotoxy(79,24);
}
}
}
}