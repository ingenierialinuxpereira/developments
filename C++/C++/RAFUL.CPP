# include <conio.h>
# include <stdio.h>
# include <iostream.h>
# include <stdlib.h>
# include <string.h>
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
  char valido;
   char nombre[34];
   char apellido[2][34];
   char telefono[10];
   char sexo[15];
   char cedula[10];
   long salario;
   char direccion[30];
   int edad;
};
struct stIndice
{
   char telefono[10];
   long indice;
};
struct nomina
{
char telefono[10];
long salario;
long salbruto;
};
void menu ();
void cuadro (int x1,int y1,int x2,int y2,int color);
void coloreo(int x1,int y1,int x2,int y2, int color, int tipo);
void ingreso(empleado &reg);void EliminarRetornoLinea(char *cad);
void saludo();
void desplaza(int opc);
void desplaza1(int opc);
void opciones();
void Mostrar(empleado &reg);
void Insertar(FILE *fa, empleado &reg);
void Leer(FILE *fa, empleado &reg, char *telefono);
void ReconstruirIndices(FILE *fa);
void Intercambia(FILE *fa, long iz, long de);
char *LeeCampo(FILE *fa, long n, char *buf);
void QuickSort(FILE *fa, long inicio, long final);

//int pass();
void main ()
{
clrscr ();
  empleado reg;
   FILE *fa;
   int opcion;//ingresa;
   char telefono[10];
   clrscr();
   //ingresa=pass();
  // if(ingresa == 1)
   {
   fa = fopen("indices.dat", "r+b");
   if(!fa) fa = fopen("indices.dat", "w+b");
   menu ();
   fclose(fa);
}
}


void menu ()
{
cuadro (4,1,21,80,RED);
coloreo(6,2,20,79,BLUE,219);
cuadro(22,15,24,63,RED);
cuadro(1,1,3,39,RED);
cuadro(1,40,3,80,RED);
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
    textcolor(color);
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
gotoxy (xi,x1);
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
gotoxy(7,2);cprintf("COLEGIO GENERAL RAFAEL REYES");
gotoxy(53,2);printf("NOMSOFT S.A");
gotoxy(16,23);printf("SU OPCION:");
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
	      cprintf("Administracion de n�mina   ");
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
	      printf("Administracion de n�mina  ");
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

/* ******************************************** */

void desplaza(int opc)
{
  int a,op;
  empleado reg;
  char telefono[10];
  FILE *fa;

  fa = fopen("indices.dat", "r+b");          // Este modo permite leer y escribir
  if(!fa) fa = fopen("indices.dat", "w+b");  // si el fichero no existe, lo crea.


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
// IMPLEMENTADO;
 if((a==ENTER) && (op == 2))
 {
 coloreo(9,26,20,68,BLACK,176);
 cuadro(8,25,19,67,RED);
 gotoxy(31,23);textbackground(BLACK);cprintf("Oprima enter para iniciar  ");
 ingreso(reg);
 Insertar(fa,reg);
 }

if((a==ENTER) && (op == 1))
 {
 coloreo(9,26,20,68,BLACK,176);
 cuadro(8,25,19,67,RED);
 gotoxy(31,23);textbackground(BLACK);cprintf("Oprima enter para iniciar  ");
 gotoxy(27,9);
 printf("(b�squeda por n�mero telef�nico):");
	    do
	    {
	       fgets(telefono, 10, stdin);
	       EliminarRetornoLinea(telefono);
	    }
	    while(strlen(telefono) < 1);
	    Leer(fa, reg, telefono);
	    Mostrar(reg);
	    getch();
   coloreo(6,2,20,79,BLUE,219);

	    break;

 }
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
	      {
	      case 1:gotoxy (10,8);
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
	      {
	      case 1:gotoxy (25,8);
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
	      {
	      case 1:gotoxy (37,8);
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

//******************************************************//
void desplaza1(int opc)
{
FILE *fa;
char telefono[10];
int a,op,b; empleado reg;

fa = fopen("indices.dat", "r+b");          // Este modo permite leer y escribir
if(!fa) fa = fopen("indices.dat", "w+b");  // si el fichero no existe, lo crea.



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
{  //IMPLEMENTACION
if((a==ENTER) && (op == 2))
 {
 coloreo(9,26,20,68,BLACK,176);
 cuadro(8,25,19,67,RED);
 gotoxy(31,23);textbackground(BLACK);cprintf("Oprima enter para iniciar  ");
 ingreso(reg);
 Insertar(fa,reg);
 }
if((a==ENTER) && (op == 1))
 {
 coloreo(9,26,20,68,BLACK,176);
 cuadro(8,25,19,67,RED);
 gotoxy(31,23);textbackground(BLACK);cprintf("Oprima enter para iniciar  ");
 gotoxy(27,9);
 printf("(b�squeda por n�mero telef�nico):");
	    do
	    {
	       fgets(telefono, 10, stdin);
	       EliminarRetornoLinea(telefono);
	    }
	    while(strlen(telefono) < 1);
	    Leer(fa, reg, telefono);
	    Mostrar(reg);
	    getch();
   coloreo(6,2,20,79,BLUE,219);
	    break;
  }
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
	      {
	      case 1:gotoxy (10,8);
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
	      {
	      case 1:gotoxy (25,8);
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
	      {
	      case 1:gotoxy (37,8);
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

//IMPLEMENTADO
void ingreso(empleado &reg)
{
   int i,a,opc;
   char edad[4];
   char numero[10];
   a=getch();
   gotoxy(31,23); printf("Oprima escape para abortar");
  while((a!=ESC))
    {
  gotoxy(26,9); printf("Registrar ");
   reg.valido = 'S';
  gotoxy(26,9); printf("Nombre: ");
   fgets(reg.nombre, 34, stdin);
   EliminarRetornoLinea(reg.nombre);
  gotoxy(26,10); printf("Primer apellido: ");
   fgets(reg.apellido[0], 34, stdin);
   EliminarRetornoLinea(reg.apellido[0]);
  gotoxy(26,11); printf("Segundo apellido: ");
   fgets(reg.apellido[1], 34, stdin);
   EliminarRetornoLinea(reg.apellido[1]);
  gotoxy(26,12); printf("Tel�fono: ");
   fgets(reg.telefono, 10, stdin);
   EliminarRetornoLinea(reg.telefono);
  gotoxy(26,13); printf("C�dula:");
   fgets(reg.cedula,10,stdin);
  gotoxy(26,14); printf("Direcci�n:");
   fgets(reg.direccion,30,stdin);

  gotoxy(26,15); printf("Edad:");
   fgets(edad,4,stdin);
   reg.edad = atoi(edad);

  gotoxy(26,16); printf("Sexo:");
   fgets(reg.sexo,15,stdin);

  gotoxy(26,17); printf("Salario:");
   fgets(numero,10,stdin);
   reg.salario = atoi(numero);
   coloreo(8,25,20,68,BLUE,219);
   break;
    }
if(a==ESC)
coloreo(6,2,20,79,BLUE,219);
}
//**************************************  ***//
void Mostrar(empleado &reg)
{
   int i;
   if(reg.valido == 'S')
   {
      gotoxy(26,9);
      printf("Nombre:  %s\n", reg.nombre);
      gotoxy(26,10);
      printf("Primer apellido:  %s ",reg.apellido[0]);
      gotoxy(26,11);
      printf("Segundo apellido:  %s",reg.apellido[1]);
      gotoxy(26,12);
      printf("N�mero de tel�fono: %s\n", reg.telefono);
      gotoxy(26,13);
      printf("Cedula:%s",reg.cedula);
      gotoxy(26,14);
      printf("Direccion:%s",reg.direccion);
      gotoxy(26,15);
      printf("Edad:%d",reg.edad);
      gotoxy(26,16);
      printf("Sexo:%s",reg.sexo);
      gotoxy(26,17);
      printf("Salario:%ld",reg.salario);
   }
   system("PAUSE");
}
// Lee el registro desde el fichero de datos con el tel�fono dado
void Leer
(FILE *fa, empleado &reg, char *telefono)
{
   FILE *fe;
   stIndice ind;
   long inf, sup, n, nRegs;
   fe = fopen("indices.ind", "rb");
   fseek(fe, 0, SEEK_END);
   nRegs = ftell(fe)/sizeof(stIndice);
   // B�squeda binaria:
   inf = 0 ;
   sup = nRegs-1;
   do {
      n = inf+(sup-inf)/2;
      fseek(fe, n*sizeof(stIndice), SEEK_SET);
      fread(&ind, sizeof(stIndice), 1, fe);
      if(strcmp(ind.telefono, telefono) < 0) inf = n+1;
      else sup = n-1;
   }
   while(inf <= sup && strcmp(ind.telefono, telefono));
   // Si se encontr� el tel�fono, lee el registro, si no muestra mensaje.
   if(!strcmp(ind.telefono, telefono)) {
      fseek(fa, ind.indice*sizeof(empleado), SEEK_SET);
      fread(&reg, sizeof(empleado), 1, fa);
   }
   else
   {
      reg.valido = 'N';
      gotoxy(29,12);
      printf("Registro no encontrado\n");
getch();
   coloreo(6,2,20,79,BLUE,219);
   }
   fclose(fe);
}
void Insertar(FILE *fa, empleado &reg)
{
   // Insertar al final:
   fseek(fa, 0, SEEK_END);
   fwrite(&reg, sizeof(empleado), 1, fa);
   ReconstruirIndices(fa);
}
// Reconstruye el archivo de �ndices
void ReconstruirIndices(FILE *fa)
{
   long n=0;
   FILE *fe;
   empleado reg;
   stIndice ind;

   // Crea el fichero de �ndices a partir del archivo de datos:
   fe = fopen("indices.ind", "w+b");
   rewind(fa);
   while(fread(&reg, sizeof(empleado), 1, fa)) {
      strcpy(ind.telefono, reg.telefono);
      ind.indice = n++;
      fwrite(&ind, sizeof(stIndice), 1, fe);
   }
   // Ordena usando el algoritmo Quicksort:
   QuickSort(fe, 0, n-1);
   fclose(fe);
}
// Implementaci�n del algoritmo Quicksort para fichero de �ndices
void QuickSort(FILE *fe, long inicio, long final)
{
   long iz, de;
   char mitad[10];
   static char cad[10];

   iz = inicio;
   de = final;
   strcpy(mitad, LeeCampo(fe, (iz+de)/2, cad));
   do {
      while(strcmp(LeeCampo(fe, iz, cad), mitad) < 0 && iz < final) iz++;
      while(strcmp(mitad, LeeCampo(fe, de, cad)) < 0 && de > inicio) de--;
      if(iz < de) Intercambia(fe, iz, de);
      if(iz <= de) {
	 iz++;
	 de--;
      }
   }
   while(iz <= de);
   if(inicio < de) QuickSort(fe, inicio, de);
   if(iz < final) QuickSort(fe, iz, final);
}

char *LeeCampo(FILE *fe, long n, char *buf)
{
   stIndice ind;

   fseek(fe, n*sizeof(stIndice), SEEK_SET);
   fread(&ind, sizeof(stIndice), 1, fe);
   strcpy(buf, ind.telefono);
   return buf;
}

void Intercambia(FILE *fe, long iz, long de)
{
   stIndice reg1, reg2;

   fseek(fe, iz*sizeof(stIndice), SEEK_SET);
   fread(&reg1, sizeof(stIndice), 1, fe);
   fseek(fe, de*sizeof(stIndice), SEEK_SET);
   fread(&reg2, sizeof(stIndice), 1, fe);
   fseek(fe, iz*sizeof(stIndice), SEEK_SET);
   fwrite(&reg2, sizeof(stIndice), 1, fe);
   fseek(fe, de*sizeof(stIndice), SEEK_SET);
   fwrite(&reg1, sizeof(stIndice), 1, fe);
}

void EliminarRetornoLinea(char *cad)
{
   int i;
   // la funci�n fgets captura el retorno de l�nea, hay que eliminarlo:
   for(i = strlen(cad)-1; i >= 0 && cad[i] < ' '; i--) cad[i] = 0;
}
/*int pass()
{
 char *password;
   char *clave= "agarlord";
   int ptr;
   clrscr();
   textmode(BW40);
   gotoxy(10,10);
   password = getpass("Digite Su Password:");
   ptr = strcmp(password, clave);
   if (ptr == 0)
     { cprintf("Bienvenidos\n");
      getch();

       textmode(C80);
      clrscr();
      return 1;
     }
   else
     {
      cprintf("          <----Que hacker tan frustrado que es usted petardo---->      ");
      getch();

      return 0;
     }*/
    // }