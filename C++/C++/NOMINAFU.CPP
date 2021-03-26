# include <conio.h>
# include<dos.h>
# include <stdio.h>
# include <iostream.h>
# include <alloc.h>
# include <time.h>
#define ENTER 13
#define fd 77
#define fi 75
#define F10 68
#define ESC 27
#define fup 72
#define fdown 80
#define cuantos 10
struct empleado
{
char codigo[25];
char nombre[40];
char apellido[40];
char direccion[50];
int telefono;
float sal_basico;
int edad;
char sexo[1];
int numero_hijos;
char estado_civil[1];
}archivo[cuantos];

void menu ();
void cuadro (int x1,int y1,int x2,int y2,int color);
void coloreo(int x1,int y1,int x2,int y2, int color, int tipo);
void ingreso();
void saludo();
void desplaza(int opc);
void desplaza1(int opc);
void opciones();

void main ()
{
clrscr ();
menu ();
}

void menu ()
{
cuadro (4,1,21,80,BROWN);
coloreo(6,2,20,79,BLUE,219);
cuadro(22,15,24,63,BLUE);
//cuadro(22,36,24,62,BROWN);
cuadro(1,1,3,35,BROWN);
cuadro(1,36,3,79,BROWN);
opciones();
}

void coloreo(int x1,int y1,int x2,int y2,int color, int tipo)
{
int yi,xi;
for(xi=y1;xi<=y2;xi++)
 {
  for(yi=x1;yi<=x2;yi++)
    {
    gotoxy(xi,yi);
    textcolor(color); delay(5);
    cprintf("%c",tipo);
    }
   }
}


void cuadro (int x1,int y1,int x2,int y2, int color)
{
int xi,g;

textcolor(color);

for (xi=y1; xi<=y2; xi++)
{
gotoxy (xi,x1);delay(15);
cprintf("%c",196);
gotoxy (xi,x2);
cprintf("%c",196);
}

for (xi=x1; xi<=x2; xi++)
{
gotoxy (y1,xi);
cprintf("%c",179);
gotoxy (y2,xi);
cprintf("%c",179);
}

gotoxy(y1,x1);
cprintf("%c",218);
gotoxy(y2,x2);
cprintf("%c",217);
gotoxy(y2,x1);
cprintf("%c",191);
gotoxy(y1,x2);
cprintf("%c",192);
}

void opciones()
{
time_t t;
int opc;
char b,a,c;
gotoxy(4,2);
textcolor(15);
cprintf("CIDCA PEREIRA IV SEM. SISTEMAS");
/*t = time(NULL);
gotoxy(37,23);
cprintf("%s", ctime(&t));*/
gotoxy(44,2);cprintf("COLEGIO GENERAL RAFAEL REYES");
gotoxy(16,23);printf("SU OPCION:");
//gotoxy(2,23);
//putchar(char(15));

gotoxy(26,23);
putchar(char(16));
gotoxy(9,5);cprintf("EMPLEADOS");
gotoxy(24,5);cprintf("NOMINA");
gotoxy(36,5);cprintf("REPORTES");
gotoxy(50,5);cprintf("ACERCA DE");
gotoxy(66,5);cprintf("SALIR");
textcolor(15);
opc=1;

while ((a=getch()) !=F10)
{textcolor(15); gotoxy(28,23);
printf("%d",opc);
  if (a==fd)
  {
    switch (opc)
    {
    case 1 :  gotoxy (9,5);
	      textbackground(RED);
	      cprintf ("EMPLEADOS");
	      gotoxy(66,5);
	      textbackground(0);
	      cprintf("SALIR");

	      gotoxy(31,23);
	      cprintf("Administracion de empleados");
	      desplaza(opc);

	      opc++;
	      coloreo(6,5,12,23,BLUE,219);

	       break;
    case 2:
	      gotoxy (24,5);
	      textbackground(RED);
	      cprintf ("NOMINA");
	      textbackground(0);
	      gotoxy(9,5);
	      cprintf("EMPLEADOS");

	      gotoxy(31,23);
	      cprintf("Administracion de n¢mina   ");
	      desplaza(opc);
	      opc++;
	      textbackground(0);
	      coloreo(6,20,12,37,BLUE,219);
	      break;
     case 3 :

	      gotoxy (36,5);
	      textbackground(RED);
	      cprintf ("REPORTES");
	      gotoxy(24,5);
	      textbackground(0);
	      cprintf("NOMINA");
	      gotoxy(31,23);
	      cprintf("Suministro de reportes  ");
	      desplaza(opc);
	      opc++;
	      textbackground(0);
	      coloreo(6,33,12,49,BLUE,219);
	      break;
     case 4 : gotoxy (50,5);
	      textbackground(RED);
	      cprintf ("ACERCA DE");

	      textbackground(0);
	      gotoxy(36,5);
	      cprintf("REPORTES");


	      gotoxy(31,23);
	      cprintf("Informacion del programa   ");
	      desplaza(opc);
	      opc++;
	      textbackground(0);
	      coloreo(6,47,12,65,BLUE,219);
	      break;
     case 5 : gotoxy (66,5);
	      textbackground(RED);
	      cprintf ("SALIR");
	      gotoxy(50,5);
	      textbackground(0);
	      cprintf("ACERCA DE");

	      gotoxy(31,23);
	      cprintf("Para salir favor oprima F10   ");
	      desplaza(opc);
	      opc=1;
	      textbackground(0);
	      coloreo(6,66,8,75,BLUE,219);



	      break;
    }
    gotoxy(79,24);
  }
    else
	 {
	 if(a==fi)
	   {
	 switch(opc)
	    {
	    case 1:gotoxy(28,23);printf("4");
	      gotoxy (50,5);
	      textbackground(RED);
	      cprintf ("ACERCA DE");
	      gotoxy(66,5);
	      textbackground(0);
	      cprintf("SALIR");

	      gotoxy(31,23);
	      printf("Informacion del programa   ");
	      desplaza1(opc);
	      opc=5;
	      textbackground(0);
	      coloreo(6,47,12,75,BLUE,219);
	      break;
	      case 2 :gotoxy(28,23);printf("5");
	      gotoxy (66,5);
	      textbackground(RED);
	      cprintf ("SALIR");
	      textbackground(0);
	      gotoxy (9,5);
	      cprintf ("EMPLEADOS");

	      gotoxy(31,23);
	      cprintf("Para salir favor oprima F10   ");
	      desplaza1(opc);
	      opc--;
	      textbackground(0);
	      coloreo(6,67,8,75,BLUE,219);
	      break;
	      case 3 :gotoxy(28,23);printf("1");
	      gotoxy (9,5);
	      textbackground(RED);
	      cprintf ("EMPLEADOS");
	      textbackground(0);
	      gotoxy (24,5);
	      cprintf ("NOMINA");
	      gotoxy(31,23);
	      cprintf("Administracion de empleados");
	      desplaza1(opc);
	      opc--;
	      textbackground(0);
	      coloreo(6,5,12,23,BLUE,219);
	      break;
	      case 4 :gotoxy(28,23);printf("2");
	      gotoxy (24,5);
	      textbackground(RED);

	      cprintf ("NOMINA");
	      gotoxy (36,5);
	      textbackground(0);
	      cprintf ("REPORTES");
	      gotoxy(31,23);
	      printf("Administracion de n¢mina  ");
	      desplaza1(opc);
	      opc--;
	      textbackground(0);
	      coloreo(6,20,12,40,BLUE,219);

	      break;
	      case 5 :gotoxy(28,23);printf("3");
	      gotoxy (36,5);
	      textbackground(RED);

	      cprintf ("REPORTES");
	      textbackground(0);
	      gotoxy (50,5);
	      cprintf ("ACERCA DE");
	      gotoxy(31,23);
	      cprintf("Suministro de reportes  ");
	      desplaza1(opc);
	      opc--;
	      textbackground(0);
	      coloreo(6,33,12,53,BLUE,219);

	      break;

}
gotoxy(80,24);
}
}
}
gotoxy(80,24);
}




void desplaza(int opc)
{ int a,op;


switch (opc)
{
case 1 : textbackground(BLUE);
	 coloreo(6,9,10,19,BROWN,219);
	 cuadro(6,9,10,19,15);
gotoxy(10,7);cprintf("Ingreso  ");
gotoxy(10,8);cprintf("Modificar");
gotoxy(10,9);cprintf("Consulta ");
op=1;
while ((a=getch()) !=ESC)
{
 saludo();

 if((a==ENTER) && (op == 1))
   ingreso();


 if (a==fdown)
 {
    switch (op)
    {
    case 1:   gotoxy (10,7);
	      textbackground(RED);
	      cprintf ("Ingreso ");
	      textbackground(BLUE);
	      gotoxy(10,9);
	      cprintf("Consulta ");
	      op++;
	      break;
    case 2:   gotoxy (10,8);
	      textbackground(RED);
	      cprintf ("Modificar");
	      textbackground(BLUE);
	      gotoxy(10,7);
	      cprintf("Ingreso ");
	      op++;
	      break;

    case 3:gotoxy (10,9);
	      textbackground(RED);
	      cprintf ("Consulta ");
	      gotoxy(10,8);
	      textbackground(BLUE);
	      cprintf("Modificar");
	      op=1;
	      break;
    } // sw
    gotoxy(80,24);
    }
 else
    {
      if(a==fup)
	      {
	      switch(op)
	      {case 1:gotoxy (10,8);
	      textbackground(RED);
	      cprintf ("Modificar");
	      textbackground(BLUE);
	      gotoxy(10,9);
	      cprintf("Consulta ");
	      op=3;
	      break;
	      case 2:gotoxy(10,9);
	      textbackground(RED);
	      cprintf("Consulta ");
	      textbackground(BLUE);
	      gotoxy(10,7);
	      cprintf("Ingreso  ");
	      op--;
	      break;
	      case 3:gotoxy(10,7);
	      textbackground(RED);
	      cprintf("Ingreso  ");
	      textbackground(BLUE);
	      gotoxy(10,8);
	      cprintf("Modificar");
	      op--;
	      break;
	      } // sw
	      } //if
   }//else
  } //wh
  break;

  case 2 :
	      textbackground(BLUE);
	      coloreo(6,24,10,34,BROWN,219);
	      cuadro(6,24,10,34,15);
gotoxy(25,7);cprintf("Novedades");
gotoxy(25,8);cprintf("Modificar");
gotoxy(25,9);cprintf("Calcular ");
op=1;
while ((a=getch()) !=ESC)
{
 if (a==fdown)
 {
    switch (op)
    {
    case 1:   gotoxy (25,7);
	      textbackground(RED);
	      cprintf ("Novedades");
	      textbackground(BLUE);
	      gotoxy(25,9);
	      cprintf("Calcular ");
	      op++;
	      break;
    case 2:   gotoxy (25,8);
	      textbackground(RED);
	      cprintf ("Modificar");
	      textbackground(BLUE);
	      gotoxy(25,7);
	      cprintf("Novedades");
	      op++;
	      break;

    case 3:   gotoxy (25,9);
	      textbackground(RED);
	      cprintf ("Calcular ");
	      gotoxy(25,8);
	      textbackground(BLUE);
	      cprintf("Modificar");
	      op=1;
	      break;
    } // sw
    gotoxy(80,24);
    }
 else
    {
      if(a==fup)
	      {
	      switch(op)
	      {case 1:gotoxy (25,8);
	      textbackground(RED);
	      cprintf ("Modificar");
	      textbackground(BLUE);
	      gotoxy(25,9);
	      cprintf("Calcular ");
	      op=3;
	      break;
	      case 2:gotoxy(25,9);
	      textbackground(RED);
	      cprintf("Calcular ");
	      textbackground(BLUE);
	      gotoxy(25,7);
	      cprintf("Novedades");
	      op--;
	      break;
	      case 3:gotoxy(25,7);
	      textbackground(RED);
	      cprintf("Novedades");
	      textbackground(BLUE);
	      gotoxy(25,8);
	      cprintf("Modificar");
	      op--;
	      break;
	      } // sw               //
	      } //if
   }//else
  } //wh
  break;


case 3:       textbackground(BLUE);
	      coloreo(6,36,10,48,BROWN,219);
	      cuadro(6,36,10,48,15);
gotoxy(37,7);cprintf("Cons/emp   ");
gotoxy(37,8);cprintf("Cons/rango ");
gotoxy(37,9);cprintf("Totales    ");
op=1;
while ((a=getch()) !=ESC)
{
 if (a==fdown)
 {
    switch (op)
    {
    case 1:   gotoxy (37,7);
	      textbackground(RED);
	      cprintf ("Cons/emp   ");
	      textbackground(BLUE);
	      gotoxy(37,9);
	      cprintf("Totales    ");
	      op++;
	      break;
    case 2:   gotoxy (37,8);
	      textbackground(RED);
	      cprintf ("Cons/rango");
	      textbackground(BLUE);
	      gotoxy(37,7);
	      cprintf("Cons/emp   ");
	      op++;
	      break;

    case 3:gotoxy (37,9);
	      textbackground(RED);
	      cprintf ("Totales    ");
	      gotoxy(37,8);
	      textbackground(BLUE);
	      cprintf("Cons/rango");
	      op=1;
	      break;
    } // sw
    gotoxy(80,24);
    }
 else
    {
      if(a==fup)
	      {
	      switch(op)
	      {case 1:gotoxy (37,8);
	      textbackground(RED);
	      cprintf ("Cons/rango");
	      textbackground(BLUE);
	      gotoxy(37,9);
	      cprintf("Totales    ");
	      op=3;
	      break;
	      case 2:gotoxy(37,9);
	      textbackground(RED);
	      cprintf("Totales    ");
	      textbackground(BLUE);
	      gotoxy(37,7);
	      cprintf("Cons/emp   ");
	      op--;
	      break;
	      case 3:gotoxy(37,7);
	      textbackground(RED);
	      cprintf("Cons/emp   ");
	      textbackground(BLUE);
	      gotoxy(37,8);
	      cprintf("Cons/rango");
	      op--;
	      break;
	      } // sw
	      } //if
   }//else
  } //wh
  break;

case 4: textbackground(BLUE);
	      coloreo(6,50,10,58,BROWN,219);
	      cuadro(6,50,10,58,15);
	      gotoxy(51,7);cprintf("Sistema");
	      gotoxy(51,8);cprintf("-------");
	      gotoxy(51,9);cprintf("Nomina ");
	      getch();
	      break;
case 5:textbackground(BLUE);
       coloreo(6,67,8,75,BROWN,219);
       cuadro(6,67,8,75,15);
       gotoxy(68,7);
       cprintf("Adios  ");
       getch();
       break;



}
gotoxy(80,24);
}
void desplaza1(int opc)
{int a,op,b;
switch (opc)
{
case 1 : textbackground(BLUE);
	 coloreo(6,50,10,58,BROWN,219);
	 cuadro(6,50,10,58,15);
	 gotoxy(51,7);cprintf("Sistema");
	 gotoxy(51,8);cprintf("-------");
	 gotoxy(51,9);cprintf("Nomina ");
	 getch();
	 break;


case 2 :      textbackground(BLUE);
	      coloreo(6,67,8,75,BROWN,219);
	      cuadro(6,67,8,75,15);
	      gotoxy(68,7);cprintf("Adios  ");
	      getch();
	      break;
case 3:
	      textbackground(BLUE);
	      coloreo(6,9,10,19,BROWN,219);
	      cuadro(6,9,10,19,15);
	      gotoxy(10,7);cprintf("Ingreso  ");
	      gotoxy(10,8);cprintf("Modificar");
	      gotoxy(10,9);cprintf("Consulta ");
op=1;
while ((a=getch()) !=ESC)
{
 if (a==fdown)
 {
    switch (op)
    {
    case 1:   gotoxy (10,7);
	      textbackground(RED);
	      cprintf ("Ingreso  ");
	      textbackground(BLUE);
	      gotoxy(10,9);
	      cprintf("Consulta ");
	      op++;
	      break;
    case 2:   gotoxy (10,8);
	      textbackground(RED);
	      cprintf ("Modificar");
	      textbackground(BLUE);
	      gotoxy(10,7);
	      cprintf("Ingreso  ");
	      op++;
	      break;

    case 3:gotoxy (10,9);
	      textbackground(RED);
	      cprintf ("Consulta ");
	      gotoxy(10,8);
	      textbackground(BLUE);
	      cprintf("Modificar");
	      op=1;
	      break;
    } // sw
    gotoxy(80,24);
    }
 else
    {
      if(a==fup)
	      {
	      switch(op)
	      {case 1:gotoxy (10,8);
	      textbackground(RED);
	      cprintf ("Modificar");
	      textbackground(BLUE);
	      gotoxy(10,9);
	      cprintf("Consulta ");
	      op=3;
	      break;
	      case 2:gotoxy(10,9);
	      textbackground(RED);
	      cprintf("Consulta ");
	      textbackground(BLUE);
	      gotoxy(10,7);
	      cprintf("Ingreso  ");
	      op--;
	      break;
	      case 3:gotoxy(10,7);
	      textbackground(RED);
	      cprintf("Ingreso  ");
	      textbackground(BLUE);
	      gotoxy(10,8);
	      cprintf("Modificar");
	      op--;
	      break;
	      } // sw
	      } //if
   }//else
   gotoxy(80,24);
  } //wh
  break;

case 4:       textbackground(BLUE);
	      coloreo(6,24,10,34,BROWN,219);
	      cuadro(6,24,10,34,15);
gotoxy(25,7);cprintf("Novedades");
gotoxy(25,8);cprintf("Modificar");
gotoxy(25,9);cprintf("Calcular ");
op=1;
while ((a=getch()) !=ESC)
{
 if (a==fdown)
 {
    switch (op)
    {
    case 1:   gotoxy (25,7);
	      textbackground(RED);
	      cprintf ("Novedades");
	      textbackground(BLUE);
	      gotoxy(25,9);
	      cprintf("Calcular ");
	      op++;
	      break;
    case 2:   gotoxy (25,8);
	      textbackground(RED);
	      cprintf ("Modificar");
	      textbackground(BLUE);
	      gotoxy(25,7);
	      cprintf("Novedades");
	      op++;
	      break;

    case 3:gotoxy (25,9);
	      textbackground(RED);
	      cprintf ("Calcular ");
	      gotoxy(25,8);
	      textbackground(BLUE);
	      cprintf("Modificar");
	      op=1;
	      break;
    } // sw
    gotoxy(80,24);
    }
 else
    {
      if(a==fup)
	      {
	      switch(op)
	      {case 1:gotoxy (25,8);
	      textbackground(RED);
	      cprintf ("Modificar");
	      textbackground(BLUE);
	      gotoxy(25,9);
	      cprintf("Calcular ");
	      op=3;
	      break;
	      case 2:gotoxy(25,9);
	      textbackground(RED);
	      cprintf("Calcular ");
	      textbackground(BLUE);
	      gotoxy(25,7);
	      cprintf("Novedades");
	      op--;
	      break;
	      case 3:gotoxy(25,7);
	      textbackground(RED);
	      cprintf("Novedades");
	      textbackground(BLUE);
	      gotoxy(25,8);
	      cprintf("Modificar");
	      op--;
	      break;
	      } // sw               //
	      } //if
   }//else
   gotoxy(80,24);
  } //wh
  break;

case 5:textbackground(BLUE);
       coloreo(6,36,10,48,BROWN,219);
       cuadro(6,36,10,48,15);
       gotoxy(37,7);
gotoxy(37,7);cprintf("Cons/emp   ");
gotoxy(37,8);cprintf("Cons/rango ");
gotoxy(37,9);cprintf("Totales    ");
op=1;
while ((a=getch()) !=ESC)
{
 if (a==fdown)
 {
    switch (op)
    {
    case 1:   gotoxy (37,7);
	      textbackground(RED);
	      cprintf ("Cons/emp");
	      textbackground(BLUE);
	      gotoxy(37,9);
	      cprintf("Totales");
	      op++;
	      break;
    case 2:   gotoxy (37,8);
	      textbackground(RED);
	      cprintf ("Cons/rango");
	      textbackground(BLUE);
	      gotoxy(37,7);
	      cprintf("Cons/emp");
	      op++;
	      break;

    case 3:gotoxy (37,9);
	      textbackground(RED);
	      cprintf ("Totales");
	      gotoxy(37,8);
	      textbackground(BLUE);
	      cprintf("Cons/rango");
	      op=1;
	      break;
    } // sw
    gotoxy(80,24);
    }
 else
    {
      if(a==fup)
	      {
	      switch(op)
	      {case 1:gotoxy (37,8);
	      textbackground(RED);
	      cprintf ("Cons/rango");
	      textbackground(BLUE);
	      gotoxy(37,9);
	      cprintf("Totales");
	      op=3;
	      break;
	      case 2:gotoxy(37,9);
	      textbackground(RED);
	      cprintf("Totales");
	      textbackground(BLUE);
	      gotoxy(37,7);
	      cprintf("Cons/emp");
	      op--;
	      break;
	      case 3:gotoxy(37,7);
	      textbackground(RED);
	      cprintf("Cons/emp");
	      textbackground(BLUE);
	      gotoxy(37,8);
	      cprintf("Cons/rango");
	      op--;
	      break;
	      } // sw
	      } //if
   }//else
   gotoxy(80,24);
  } //wh
  break;





}
gotoxy(80,24);
}


void ingreso()
{ int i,cuant;

cprintf("Cuantos empleados?");
scanf("%d",&cuant);
//cuadro(1,1,23,80,BLUE);
for(i=0;i<=cuant;i++)
{
printf("Nombre:");
scanf("%s",&archivo[i].nombre);
printf("Apellido:");scanf("%s",&archivo[i].apellido);
printf("Codigo:");scanf("%s",&archivo[i].codigo);
printf("Direccion:");scanf("%s",&archivo[i].direccion);
printf("Telefono:");scanf("%s",&archivo[i].telefono);
printf("Sexo:");scanf("%s",&archivo[i].sexo);
printf("Edad:");scanf("%d",&archivo[i].edad);
printf("Numero de hijos:");scanf("%d",&archivo[i].numero_hijos);
printf("Estado civil:");scanf("%s",&archivo[i].estado_civil);
printf("Salario_basico:");scanf("%f",&archivo[i].sal_basico);
}
}

void saludo()
{
gotoxy(70,24);cprintf("Hola");
}