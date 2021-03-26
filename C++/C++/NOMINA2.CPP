#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include<conio.h>
#include<iostream>
#include<windows.h>
#include<alloc>
#include<math.h>
#include<stdio.h>
#include<time.h>
#define FI 75
#define FD 77
#define FAR 72
#define FAB 80
#define F10 68
#define ENTER 13
#define esc 27

struct stRegistro {
   char valido;  // Campo que indica si el registro es valido S->Válido, N->Inválido
   char nombre[34];
   char apellido[2][34];
   int edad;
   char sexo[12];
   int salario;
   char dir[34];
   char telefono[10];
   char cedula[15];
};
struct stNomina {
  char valido;
   int dia;
   int mes;
   int ano;
   char cedula[15];
   int salario1;
   int auxtrans;
   int pension;
   int salud;
   int fondoempl;
   int quincena1;
   int quincena2;
   };

struct stIndice { //registro
   char cedula[15];
   long indice;
};

struct stIndices { //nomina
   char cedula[15];
   long indice;
};

// registro
void operacion(int p);
void cuadro(int x1,int y1, int x2,int y2);
void relleno(int x1,int y1, int x2,int y2);
void datos(int optr);
void menu();
void opciones();
void minicuadros();
int Menu();
void Capturar(stRegistro &reg);
void EliminarRetornoLinea(char *cad);
void Leer(FILE *fa, stRegistro &reg, char *telefono);
void Insertar(FILE *fa, stRegistro &reg);
void Mostrar(stRegistro &reg);
void ListarPorTelefonos(FILE *fa);
void ListarNatural(FILE *fa);
void novedades(FILE *fa);
void ReconstruirIndices(FILE *fa);
// Funciones para ordenar el fichero de índices:
void Intercambia(FILE *fa, long iz, long de);
char *LeeCampo(FILE *fa, long n, char *buf);
void QuickSort(FILE *fa, long inicio, long final);
int archivos(int opcion);
int pass();
int promet;

// funciones de nomina nomina
void Leernomina(FILE *fa, stNomina &reg, char *cedula);
void Insertaro(FILE *fe, stNomina &reg);
void ListarNaturale(FILE *fe);
void capturanom(stNomina &reg1);
void Mostrare(stNomina &reg);
void ListarPorcedula(FILE *fe);
void ReconstruirIndicesno(FILE *fe);
void QuickSorte(FILE *fi, long inicio, long final);
char *LeeCampos(FILE *fi, long n, char *buf);
void Totales(FILE *fe);
void Intercambian(FILE *fi, long iz, long de);

void main()
{
clrscr();
//int ingresa;
//ingresa =pass();
//if(ingresa ==1)
menu();
}
// pinta el programa
void menu()
{
cuadro (1,1,3,80);
cuadro (4,1,21,80);
relleno(6,2,20,79);
cuadro (22,1,24,80);
opciones();
}
// cuadro neutro
void cuadro(int x1,int y1,int x2,int y2)
{
int xi,yi;
textcolor(15);
for(xi=y1; xi<=y2; xi++) /* Lineas Horizontales */
{
gotoxy(xi, x1);
delay(5);
putchar(char(196));
gotoxy(xi,x2 );
delay(5);
putchar(char(196));
}
for(xi=x1; xi<=x2; xi++) /* Lineas Verticales */
{
gotoxy(y1, xi);
delay(5);
putchar(char(179));
gotoxy(y2, xi);
delay(5);
putchar(char(179));
}
gotoxy(y1, x2);
delay(5);
putchar(char(192));
gotoxy(y2, x2);
delay(5);
putchar(char(217));
gotoxy(y1, x1);
delay(5);
putchar(char(218));
gotoxy(y2, x1);
delay(5);
putchar(char(191));
}

//relleno neutro
void relleno(int x1,int y1,int x2,int y2)
{
int xi,yi;
textcolor(11);
for(xi=y1; xi<=y2; xi++) /* Relleno */
 { for (yi=x1;yi<=x2;yi++)
     {
	gotoxy(xi, yi);
	cprintf("%c",176);
      }
 }
}

// principal
void opciones()
{
time_t t;
int opc,a,x,op,z;
x=5;
gotoxy(1,80);
textcolor (WHITE);
gotoxy (2,x);  cprintf ("EMPLEADOS");
gotoxy (22,x); cprintf ("NOMINA");
gotoxy (39,x); cprintf ("REPORTES");
gotoxy (56,x); cprintf ("ACERCA DE");
gotoxy (73,x); cprintf ("SALIR");
opc=1;
promet=0;
while (promet!=1)
{
(a=getch());
t=time(NULL);
gotoxy(5,2);
cprintf("HORA: %s",ctime(&t));

switch (a)
  {
  case FD:
		switch(opc)
		{
		case 1:
		gotoxy (2,x);
		textbackground(15);
		textcolor(0);
		cprintf ("EMPLEADOS");
		textbackground(15);
		gotoxy(73,x);
		textbackground(0);
		textcolor(15);
		cprintf ("SALIR");
		gotoxy(5,23);
		cprintf ("Administraci¢n de empleados               ");
		z=1;
		operacion(z);
		opc++;
		break;
		case 2:
		gotoxy (22,x);
		textbackground(15);
		textcolor(0);
		cprintf ("NOMINA");
		textbackground(0);
		textcolor(15);
		gotoxy (2,x);
		cprintf ("EMPLEADOS");
		gotoxy(5,23);
		cprintf ("Modificaciones de la nomina                ");
		z=2;
		operacion(z);
		opc++;
		break;
		case 3:
		gotoxy (39,x);
		textbackground(15);
		textcolor(0);
		cprintf ("REPORTES");
		textbackground(0);
		textcolor(15);
		gotoxy (22,x);
		cprintf ("NOMINA");
		gotoxy(5,23);
		cprintf ("Muestra informe general de empleados                     ");
		z=3;
		operacion(z);
		opc++;
		break;
		case 4:
		gotoxy (56,x);
		textbackground(15);
		textcolor(0);
		cprintf ("ACERCA DE");
		textbackground(0);
		textcolor(15);
		gotoxy (39,x);
		cprintf ("REPORTES");
		gotoxy(5,23);
		cprintf ("Informaci¢n de nuestro programa                   ");
		z=4;
		operacion(z);
		opc++;
		break;
		case 5:
		gotoxy (73,x);
		textbackground(15);
		textcolor(0);
		cprintf ("SALIR");
		textbackground(0);
		textcolor(15);
		gotoxy (56,x);
		cprintf ("ACERCA DE");
		gotoxy(5,23);
		cprintf ("Salir del sistema F10.                  ");
		z=5;
		operacion(z);
		opc=1;
		break;
		}
		textbackground(0);
		relleno(6,2,20,79);
		break;
 case FI:
		switch(opc)
		{
		case 1:
		gotoxy (56,x);
		textbackground(15);
		textcolor(0);
		cprintf ("ACERCA DE");
		gotoxy(73,x);
		textbackground(0);
		textcolor(15);
		cprintf ("SALIR");
		gotoxy(5,23);
		cprintf ("Informaci¢n de nuestro programa                             ");
		z=4;
		operacion(z);
		opc=5;
		break;
		case 2:
		gotoxy (73,x);
		textbackground(15);
		textcolor(0);
		cprintf ("SALIR");
		textbackground(0);
		textcolor(15);
		gotoxy (2,x);
		cprintf ("EMPLEADOS");
		gotoxy(5,23);
		cprintf ("Salir del sistema F10.                               ");
		z=5;
		operacion(z);
		opc--;
		break;
		case 3:
		gotoxy (2,x);
		textbackground(15);
		textcolor(0);
		cprintf ("EMPLEADOS");
		textbackground(0);
		textcolor(15);
		gotoxy (22,x);
		cprintf ("NOMINA");
		gotoxy(5,23);
		cprintf ("Muestra informe general de empleados                      ");
		z=1;
		operacion(z);
		opc--;
		break;
		case 4:
		gotoxy (22,x);
		textbackground(15);
		textcolor(0);
		cprintf ("NOMINA");
		textbackground(0);
		textcolor(15);
		gotoxy (39,x);
		cprintf ("REPORTES");
		gotoxy(5,23);
		cprintf ("Informaci¢n nomina                                  ");
		z=2;
		operacion(z);
		opc--;
		break;
		case 5:
		gotoxy (39,x);
		textbackground(15);
		textcolor(0);
		cprintf ("REPORTES");
		textbackground(0);
		textcolor(15);
		gotoxy (56,x);
		cprintf ("ACERCA DE");
		gotoxy(5,23);
		cprintf ("Muestra informe general de empleados                    ");
		z=3;
		operacion(z);
		opc--;
		break;
	       }
	       textbackground(0);
	       relleno(6,2,20,79);
	       break;
 }
 gotoxy(2,2);cprintf("%d",opc);
 gotoxy(79,23);
}
}

// menus peque;os
void operacion(int z)
{
int op,a;
switch (z)
{
case 1: a=getch();
	if (a==ENTER)
	{cuadro(6,2,10,12);
	gotoxy(3,7);cprintf("Adicionar");
	gotoxy(3,8);cprintf("Novedades");
	gotoxy(3,9);cprintf("Consultar");
	op=1;
	while ((a=getch()) != esc)
	{switch (a)
	{case FAB:
	 switch(op)
	 { case 1:
	 gotoxy (3,7);textbackground(15);
	 textcolor(0);cprintf ("Adicionar");
	 gotoxy(3,9);textbackground(0);
	 textcolor(15);cprintf ("Consultar");
	 datos(1);
	 op++;break;
	 case 2:
	 gotoxy (3,8);textbackground(15);
	 textcolor(0);cprintf ("Novedades");
	 gotoxy(3,7);textbackground(0);
	 textcolor(15);cprintf ("Adicionar");
	 datos(2);
	 op++;break;
	 case 3:
	 gotoxy (3,9);textbackground(15);
	 textcolor(0);cprintf ("Consultar");
	 gotoxy(3,8);textbackground(0);
	 textcolor(15);cprintf ("Novedades");
	 datos(5);
	 op=1;break;
	 }
	 break;
	 case FAR:
	 switch(op)
	 {case 1:
	 gotoxy (3,8);textbackground(15);
	 textcolor(0);cprintf ("Novedades");
	 gotoxy(3,9);textbackground(0);
	 textcolor(15);cprintf ("Consultar");
	 datos(2);
	 op=3;break;
	 case 2:
	 gotoxy (3,9);textbackground(15);
	 textcolor(0);cprintf ("Consultar");
	 gotoxy(3,7);textbackground(0);
	 textcolor(15);cprintf ("Adicionar");
	 datos(5);
	 op--;break;
	 case 3:
	 gotoxy(3,7);textbackground(15);
	 textcolor(0);cprintf ("Adicionar");
	 gotoxy(3,8);textbackground(0);
	 textcolor(15);cprintf ("Novedades");
	 datos(1);
	 op--;break;
	 }
	 break;
	 } } }
	 break;
case 2: a=getch();
	 if (a==ENTER)
	 {
	 cuadro(6,22,10,39);
	 gotoxy(23,7);cprintf("Adicionar nomina");
	 gotoxy(23,8);cprintf("Listar nomina   ");
	 gotoxy(23,9);cprintf("Listar x cedula ");
	 op=1;
	 while ((a=getch()) != esc )
	 {switch (a)
	 {case FAB:
	 switch(op)
	 { case 1:
	 gotoxy (23,7);textbackground(15);
	 textcolor(0);cprintf ("Adicionar nomina");
	 gotoxy(23,9);textbackground(0);
	 textcolor(15);cprintf ("Listar x cedula ");
	 datos(7);
	 op++;break;
	 case 2:
	 gotoxy (23,8);textbackground(15);
	 textcolor(0);cprintf ("Listar nomina   ");
	 gotoxy(23,7);textbackground(0);
	 textcolor(15);cprintf ("Adicionar nomina");
	 datos(8);
	 op++;break;
	 case 3:
	 gotoxy (23,9);textbackground(15);
	 textcolor(0);cprintf ("Listar x cedula ");
	 gotoxy(23,8);textbackground(0);
	 textcolor(15);cprintf ("Listar nomina   ");
	 datos(9);
	 op=1;break;
	 }
	 break;
	 case FAR:switch(op)
	 {case 1:
	 gotoxy (23,8);textbackground(15);
	 textcolor(0);cprintf ("Listar nomina   ");
	 gotoxy(23,9);textbackground(0);
	 textcolor(15);cprintf ("Listar x cedula ");
	 datos(8);
	 op=3;break;
	 case 2:
	 gotoxy (23,9);textbackground(15);
	 textcolor(0);cprintf ("Listar x cedula ");
	 gotoxy(23,7);textbackground(0);
	 textcolor(15);cprintf ("Adicionar nomina");
	 datos(9);
	 op--;break;
	 case 3:
	 gotoxy(23,7);textbackground(15);
	 textcolor(0);cprintf ("Adicionar nomina");
	 gotoxy(23,8);textbackground(0);
	 textcolor(15);cprintf ("Listar nomina   ");
	 datos(7);
	 op--;break;
	 }
	 break; } } }
	 break;
case 3:	a=getch();
	 if (a==ENTER)
	 {
	 cuadro(6,39,10,61);
	 gotoxy(40,7);cprintf("Consulta por empleado");
	 gotoxy(40,8);cprintf("Consulta por orden   ");
	 gotoxy(40,9);cprintf("Total nomina         ");
	 op=1;
	 while ((a=getch()) != esc )
	 {switch (a)
	 {case FAB:
	 switch(op)
	 { case 1:
	 gotoxy (40,7);textbackground(15);
	 textcolor(0);cprintf ("Consulta por empleado");
	 gotoxy(40,9);textbackground(0);
	 textcolor(15);cprintf ("Total nomina         ");
	 datos(6);
	 op++;break;
	 case 2:
	 gotoxy (40,8);textbackground(15);
	 textcolor(0);cprintf ("Consulta por orden   ");
	 gotoxy(40,7);textbackground(0);
	 textcolor(15);cprintf ("Consulta por empleado");
	 datos(4);
	 op++;break;
	 case 3:
	 gotoxy (40,9);textbackground(15);
	 textcolor(0);cprintf ("Total nomina         ");
	 gotoxy(40,8);textbackground(0);
	 textcolor(15);cprintf ("Consulta por orden   ");
	 datos(13);
	 op=1;break;
	 }
	 break;
	 case FAR:
	 switch(op)
	 {case 1:
	 gotoxy (40,8);textbackground(15);
	 textcolor(0);cprintf ("Consulta por orden   ");
	 gotoxy(40,9);textbackground(0);
	 textcolor(15);cprintf ("Total nomina         ");
	 datos(4);
	 op=3;break;
	 case 2:
	 gotoxy (40,9);textbackground(15);
	 textcolor(0);cprintf ("Total nomina         ");
	 gotoxy(40,7);textbackground(0);
	 textcolor(15);cprintf ("Consulta por empleado");
	 datos(13);
	 op--;break;
	 case 3:
	 gotoxy(40,7);textbackground(15);
	 textcolor(0);cprintf ("Consulta por empleado");
	 gotoxy(40,8);textbackground(0);
	 textcolor(15);cprintf ("Consulta por orden   ");
	 datos(6);
	 op--;break;
	 }
	 break;} } }
	 break;
case 4:a=getch();
	 if (a==ENTER)
	{
	 cuadro(6,56,10,66);
	 gotoxy(57,7);cprintf("Empleados");
	 gotoxy(57,8);cprintf("Nomina   ");
	 gotoxy(57,9);cprintf("Reportes ");
	 op=1;
	 while ((a=getch()) != esc )
	 {
	 switch (a)
	 {
	 case FAB:
	 switch(op)
	 { case 1:
	 gotoxy (57,7);textbackground(15);
	 textcolor(0);cprintf ("Empleados");
	 gotoxy(57,9);textbackground(0);
	 textcolor(15);cprintf ("Reportes ");
	 datos(10);
	 op++;break;
	 case 2:
	 gotoxy (57,8);textbackground(15);
	 textcolor(0);cprintf ("Nomina   ");
	 gotoxy(57,7);textbackground(0);
	 textcolor(15);cprintf ("Empleados");
	 datos(11);
	 op++;break;
	 case 3:
	 gotoxy (57,9);textbackground(15);
	 textcolor(0);cprintf ("Reportes ");
	 gotoxy(57,8);textbackground(0);
	 textcolor(15);cprintf ("Nomina   ");
	 datos(12);
	 op=1;break;
	  }
	 break;
	 case FAR:
	 switch(op)
	 {case 1:
	 gotoxy (57,8);textbackground(15);
	 textcolor(0);cprintf ("Nomina   ");
	 gotoxy(57,9);textbackground(0);
	 textcolor(15);cprintf ("Reportes ");
	 datos(11);
	 op=3;break;
	 case 2:
	 gotoxy (57,9);textbackground(15);
	 textcolor(0);cprintf ("Reportes ");
	 gotoxy(57,7);textbackground(0);
	 textcolor(15);cprintf ("Empleados");
	 datos(12);
	 op--;break;
	 case 3:
	 gotoxy(57,7);textbackground(15);
	 textcolor(0);cprintf ("Empleados");
	 gotoxy(57,8);textbackground(0);
	 textcolor(15);cprintf ("Nomina   ");
	 datos(10);
	 op--;break;
	 }
	 break;
	 } } }
	 break;
case 5:a=getch();
	 if (a==ENTER)
	 {
	 cuadro(6,73,8,79);
	 gotoxy(74,7);cprintf("Salir");
	 while ((a=getch()) != esc )
	 {
	 switch (a)
	 {
	 case FAB: gotoxy (74,7);textbackground(15);
		   textcolor(0);cprintf ("Salir");
		   textbackground(0);
		   op=1;
		   a=getch();
		   if (a==ENTER)
		   {
		   promet=1;
		   textbackground(0);
		   relleno(6,2,20,79);
		   gotoxy(26,14);printf("PRESIONE ESCAPE PARA SALIR");
		   }
		   break;
	 case FAR: gotoxy (74,7);textbackground(15);
		   textcolor(0);cprintf ("Salir");
		   textbackground(0);
		   op=1;
		   a=getch();
		   if (a==ENTER)
		   {
		   promet=1;
		   textbackground(0);
		   relleno(6,2,20,79);
		   gotoxy(26,14);printf("PRESIONE ESCAPE PARA SALIR");
		   }
		   break;
	 } } }
	 break;
       }
}
// intermedio archivos
void datos(int optr)
{
int a;
a=getch();
if (a==ENTER)
{
archivos(optr);
//textbackground(0);
//relleno(6,2,20,79);
}
}

// realiza los cuadritos
void minicuadros()
{
textbackground(0);
relleno(6,2,20,79);
cuadro(7,18,19,61);
textbackground(17);
relleno(8,19,18,60);
textbackground(0);
}

// guarda la informacion
int archivos(int opcion)
{
char opct;
char ed[12];
   char sala[30];
   stRegistro reg;
   stNomina rego;
   stIndice ind;
   FILE *fa,*fe;
   char telefono[10];
   fa = fopen("indices.dat", "r+b");          // Este modo permite leer y escribir
   if(!fa) fa = fopen("indices.dat", "w+b");  // si el fichero no existe, lo crea.
   fe = fopen("indices.nom", "r+b");          // Este modo permite leer y escribir
   if(!fe) fe = fopen("indices.nom", "w+b");  // si el fichero no existe, lo crea.
	 switch(opcion) {
	 case 1: // Insertar registro
	 opct='s';
	 while (1)
	    {
	    minicuadros();
	    Capturar(reg);
	    gotoxy(19,18);printf("Desea ingresar otro empleado s/n ");
	    cin>>opct;
	    Insertar(fa, reg);
	    if (opct=='N' || opct=='n')
	    break;
	    }
	    //opcion='0';
	    cuadro (4,1,21,80);
	    relleno(6,2,20,79);
	    textbackground(0);
	    relleno(6,2,20,79);
	    gotoxy(21,14);printf("PRESIONE ESCAPE PARA REGRESAR AL MENU");
	    break;
	 case 2: // Novedades
	    minicuadros();
	    novedades(fa);
	    getch();
	    cuadro (4,1,21,80);
	    relleno(6,2,20,79);
	    textbackground(0);
	    relleno(6,2,20,79);
	    gotoxy(21,14);printf("PRESIONE ESCAPE PARA REGRESAR AL MENU");
	    break;
	 case 3: // Indicar archivo
	    ReconstruirIndices(fa);
	    break;
	 case 4: // Mostrar todo por orden de telefonos
	    minicuadros();
	    ListarPorTelefonos(fa);
	    minicuadros();
	    gotoxy(25,13);printf("LOS REGISTROS SE TERMINARON");
	    getch();
	    cuadro (4,1,21,80);
	    relleno(6,2,20,79);
	    textbackground(0);
	    relleno(6,2,20,79);
	    gotoxy(21,14);printf("PRESIONE ESCAPE PARA REGRESAR AL MENU");
	    break;
	 case 5: // Mostrar todo por orden natural
	    minicuadros();
	    ListarNatural(fa);
	    minicuadros();
	    gotoxy(25,13);printf("LOS REGISTROS SE TERMINARON");
	    getch();
	    cuadro (4,1,21,80);
	    relleno(6,2,20,79);
	    textbackground(0);
	    relleno(6,2,20,79);
	    gotoxy(21,14);printf("PRESIONE ESCAPE PARA REGRESAR AL MENU");
	    break;
	 case 6://Mostrar por cedula
	    minicuadros();
	    gotoxy(22,13);printf("Numero de cedula: ");
	    do {
	       fgets(reg.cedula, 10, stdin);
	       EliminarRetornoLinea(reg.cedula);
	       } while(strlen(reg.cedula) < 1);
	    Leer(fa, reg, reg.cedula);
	    minicuadros();
	    if (reg.valido=='S')
	    Mostrar(reg);
	    else
	    {
	    gotoxy(25,13);printf("REGISTRO NO EXISTE");
	    getch();}
	    cuadro (4,1,21,80);
	    relleno(6,2,20,79);
	    textbackground(0);
	    relleno(6,2,20,79);
	    gotoxy(21,14);printf("PRESIONE ESCAPE PARA REGRESAR AL MENU");
	    break;
	 case 7://nomina
	    minicuadros();
	    gotoxy(22,13);printf("Numero de cedula: ");
	    do {
	       fgets(reg.cedula, 10, stdin);
	       EliminarRetornoLinea(reg.cedula);
	       } while(strlen(reg.cedula) < 1);
	    Leer(fa, reg, reg.cedula);
	    minicuadros();
	    if (reg.valido=='S')  // permitir capturara nomina
	    {
	    capturanom(rego);
	    Insertaro(fe, rego);
	    getch();
	    }
	    else
	    {
	    gotoxy(25,13);printf("REGISTRO NO EXISTE");
	    getch();}
	    cuadro (4,1,21,80);
	    relleno(6,2,20,79);
	    textbackground(0);
	    relleno(6,2,20,79);
	    gotoxy(21,14);printf("PRESIONE ESCAPE PARA REGRESAR AL MENU");
	    break;
	 case 8: // nomina orden natural
	    minicuadros();
	    ListarNaturale(fe);
	    minicuadros();
	    gotoxy(25,13);printf("LOS REGISTROS SE TERMINARON");
	    getch();
	    cuadro (4,1,21,80);
	    relleno(6,2,20,79);
	    textbackground(0);
	    relleno(6,2,20,79);
	    gotoxy(21,14);printf("PRESIONE ESCAPE PARA REGRESAR AL MENU");
	    break;
	case 9: // nomina nro cedula
	    minicuadros();
	    gotoxy(22,13);printf("Numero de cedula: ");
	    do {
	       fgets(reg.cedula, 10, stdin);
	       EliminarRetornoLinea(reg.cedula);
	       } while(strlen(reg.cedula) < 1);
	    Leernomina(fe, rego, reg.cedula);
	    minicuadros();
	    if (rego.valido=='S')
	    Mostrare(rego);
	    else
	    {
	    gotoxy(25,13);printf("REGISTRO NO EXISTE");
	    getch();}
	    cuadro (4,1,21,80);
	    relleno(6,2,20,79);
	    textbackground(0);
	    relleno(6,2,20,79);
	    gotoxy(21,14);printf("PRESIONE ESCAPE PARA REGRESAR AL MENU");
	    break;
	case 10: minicuadros();
	     gotoxy(20,9);printf(" EN ESTE CAMPO SE  PIDEN TODOS AQUELLOS ");
	     gotoxy(20,11);printf(" DATOS  BASICOS  DE  CADA  UNO  DE  LOS ");
	     gotoxy(20,13);printf(" EMPLEADOS QUE HACEN PARTE DE LA EMPRESA");
	     gotoxy(20,10);printf("                                        ");
	     gotoxy(20,12);printf("                                        ");
	     gotoxy(32,16);printf (" PROGRAMA REALIZADO POR ");
	     gotoxy(32,17);printf ("   LINA MARCELA TORO    ");
	     gotoxy(32,18);printf (" JOHANA ANDREA ANGARITA ");
	     getch();
	    cuadro (4,1,21,80);
	    relleno(6,2,20,79);
	    textbackground(0);
	    relleno(6,2,20,79);
	    gotoxy(21,14);printf("PRESIONE ESCAPE PARA REGRESAR AL MENU");
	    break;
	case 11:minicuadros();
	     gotoxy(20,9); printf(" EN ESTE CAMPO SE  PIDEN TODOS AQUELLOS ");
	     gotoxy(20,11);printf(" DATOS  QUE  SIRVEN  PARA EL CALCULO DE ");
	     gotoxy(20,13);printf(" LA NOMINA Y SUS DESCUENTOS.            ");
	     gotoxy(20,10);printf("                                        ");
	     gotoxy(20,12);printf("                                        ");
	     gotoxy(32,16);printf (" PROGRAMA REALIZADO POR ");
	     gotoxy(32,17);printf ("   LINA MARCELA TORO    ");
	     gotoxy(32,18);printf (" JOHANA ANDREA ANGARITA ");
	     getch();
	    cuadro (4,1,21,80);
	    relleno(6,2,20,79);
	    textbackground(0);
	    relleno(6,2,20,79);
	    gotoxy(21,14);printf("PRESIONE ESCAPE PARA REGRESAR AL MENU");
	    break;
	case 12:minicuadros();
	     gotoxy(20,9); printf(" EN ESTE  CAMPO SE  MUESTRAN  TODOS LOS ");
	     gotoxy(20,11);printf(" RESULTADOS  OBTENIDOS  EN  LOS  CAMPOS ");
	     gotoxy(20,13);printf(" DE EMPLEADOS Y NOMINA.                 ");
	     gotoxy(20,10);printf("                                        ");
	     gotoxy(20,12);printf("                                        ");
	     gotoxy(32,16);printf (" PROGRAMA REALIZADO POR ");
	     gotoxy(32,17);printf ("   LINA MARCELA TORO    ");
	     gotoxy(32,18);printf (" JOHANA ANDREA ANGARITA ");
	     getch();
	    cuadro (4,1,21,80);
	    relleno(6,2,20,79);
	    textbackground(0);
	    relleno(6,2,20,79);
	    gotoxy(21,14);printf("PRESIONE ESCAPE PARA REGRESAR AL MENU");
	    break;
	case 13:minicuadros();
	    Totales(fe);
	    cuadro (4,1,21,80);
	    relleno(6,2,20,79);
	    textbackground(0);
	    relleno(6,2,20,79);
	    gotoxy(21,14);printf("PRESIONE ESCAPE PARA REGRESAR AL MENU");
	    break;
	     }
   fclose(fa);
   fclose(fe);
   return 0;
}
// Permite que el usuario introduzca un registro por pantalla
void Capturar(stRegistro &reg)
{  char opct;
   int i;
   char ed[12];
   char sala[30];
   reg.valido = 'S';
   gotoxy(19,8); printf("Nombre: ");
   fgets(reg.nombre, 34, stdin);
   EliminarRetornoLinea(reg.nombre);
   gotoxy(19,9);printf("Primer apellido: ");
   fgets(reg.apellido[0], 34, stdin);
   EliminarRetornoLinea(reg.apellido[0]);
   gotoxy(19,10);printf("Segundo apellido: ");
   fgets(reg.apellido[1], 34, stdin);
   EliminarRetornoLinea(reg.apellido[1]);
   gotoxy(19,11);printf("Direccion: ");
   fgets(reg.dir, 30, stdin);
   EliminarRetornoLinea(reg.dir);
   gotoxy(19,12);printf("Numero de Cedula: ");
   fgets(reg.cedula, 15, stdin);
   EliminarRetornoLinea(reg.cedula);
   gotoxy(19,13);printf("Telefono: ");
   fgets(reg.telefono, 10, stdin);
   EliminarRetornoLinea(reg.telefono);
   gotoxy(19,14);printf("Sexo: ");
   fgets(reg.sexo, 12, stdin);
   EliminarRetornoLinea(reg.sexo);
   gotoxy(19,15);printf("salario: ");
   fgets(sala, 30, stdin);
   EliminarRetornoLinea(sala);
   reg.salario=atoi(sala);
   gotoxy(19,16);printf("Edad: ");
   fgets(ed, 12, stdin);
   EliminarRetornoLinea(ed);
   reg.edad=atoi(ed);
}

// Elimina los caracteres de retorno de línea al final de cadena
void EliminarRetornoLinea(char *cad)
{
   int i;
   // la función fgets captura el retorno de línea, hay que eliminarlo:
   for(i = strlen(cad)-1; i >= 0 && cad[i] < ' '; i--) cad[i] = 0;//returna numero de caracteres en bits
}

// Muestra un registro en pantalla, si no está marcado como borrado
void Mostrar(stRegistro &reg)
{
   int i,x;
   if(reg.valido == 'S') {
   minicuadros();
      x=8;
      gotoxy(19,x);printf("Cedula: %s\n",reg.cedula);
      gotoxy(19,x=x+1);printf("Nombre: %s %s %s\n", reg.nombre, reg.apellido[0], reg.apellido[1]);
      gotoxy(19,x=x+1);printf("Edad: %d\n",reg.edad);
      gotoxy(19,x=x+1);printf("Sexo: %s\n",reg.sexo);
      gotoxy(19,x=x+1);printf("Salario: %d\n",reg.salario);
      gotoxy(19,x=x+1);printf("Direccion: %s\n",reg.dir);
      gotoxy(19,x=x+1);printf("Numero de telefono: %s\n", reg.telefono);
      gotoxy(19,x=x+2);printf("Presiona una tecla para continuar ");
      getch();
   }
}

// Lee el registro desde el fichero de datos con el telefono dado
void Leer(FILE *fa, stRegistro &reg, char *cedula)
{
   FILE *fi;
   stIndice ind;
   long inf, sup, n, nRegs;
   fi = fopen("indices.ind", "rb");
   fseek(fi, 0, SEEK_END);
   nRegs = ftell(fi)/sizeof(stIndice);//tama;o
   // Búsqueda binaria:
   inf = 0;
   sup = nRegs-1;
   do {
      n = inf+(sup-inf)/2;
      fseek(fi, n*sizeof(stIndice), SEEK_SET);
      fread(&ind, sizeof(stIndice), 1, fi);
      if(strcmp(ind.cedula, cedula) < 0) inf = n+1;
      else sup = n-1;
   } while(inf <= sup && strcmp(ind.cedula, cedula));
   // Si se encontr¢ el tel¢fono, lee el registro, si no muestra mensaje.
   if(!strcmp(ind.cedula, cedula)) {
      fseek(fa, ind.indice*sizeof(stRegistro), SEEK_SET);
      fread(&reg, sizeof(stRegistro), 1, fa);
    }
   fclose(fi);
}

// A¤ade un registro al archivo de datos y reconstruye los índices
void Insertar(FILE *fa, stRegistro &reg)
{  // Insertar al final:
   fseek(fa, 0, SEEK_END); // 0=? o el tama;o en bits del archivo
   fwrite(&reg, sizeof(stRegistro), 1, fa);// numero archivos que voy a;adir
   ReconstruirIndices(fa);
}
// Lista todos los registros ordenados por el número de teléfono
void ListarPorTelefonos(FILE *fa)
{
   FILE *fi;
   stIndice ind;
   stRegistro reg;
   fi = fopen("indices.ind", "rb");
   while(fread(&ind, sizeof(stIndice), 1, fi)) {
      fseek(fa, ind.indice*sizeof(stRegistro), SEEK_SET);//posicion del registro
      fread(&reg, sizeof(stRegistro), 1, fa);
      Mostrar(reg);
   }
   fclose(fi);
}

// Lista todos los registros del archivo de datos por el orden en que se
// insertaron.
void ListarNatural(FILE *fa)
{
   stRegistro reg;
   rewind(fa);
   while(fread(&reg, sizeof(stRegistro), 1, fa))
     Mostrar(reg);
     minicuadros();
}

// Reconstruye el archivo de índices
void ReconstruirIndices(FILE *fa)
{
   long n=0;
   FILE *fi;
   stRegistro reg;
   stIndice ind;
   // Crea el fichero de índices a partir del archivo de datos:
   fi = fopen("indices.ind", "w+b");
   rewind(fa);
   while(fread(&reg, sizeof(stRegistro), 1, fa)) {
      strcpy(ind.cedula, reg.cedula);// copiar
      ind.indice = n++;
      fwrite(&ind, sizeof(stIndice), 1, fi);
    }
   // Ordena usando el algoritmo Quicksort:
   QuickSort(fi, 0, n-1);//inicio indices // n-1 final
   fclose(fi);
}

// Implementación del algoritmo Quicksort para fichero de índices
void QuickSort(FILE *fi, long inicio, long final)
{
   long iz, de;
   char mitad[10];
   static char cad[10];
   iz = inicio;
   de = final;
   strcpy(mitad, LeeCampo(fi, (iz+de)/2, cad));
   do {
      while(strcmp(LeeCampo(fi, iz, cad), mitad) < 0 && iz < final) iz++;//retur < mitad
      while(strcmp(mitad, LeeCampo(fi, de, cad)) < 0 && de > inicio) de--;
      if(iz < de) Intercambia(fi, iz, de);
      if(iz <= de) {
	 iz++;
	 de--;
      }
   } while(iz <= de);
   if(inicio < de) QuickSort(fi, inicio, de);						//retroalimentacion
   if(iz < final) QuickSort(fi, iz, final);
}

char *LeeCampo(FILE *fi, long n, char *buf)
{
   stIndice ind;
   fseek(fi, n*sizeof(stIndice), SEEK_SET); 							//tama;o en bits de la mitad
   fread(&ind, sizeof(stIndice), 1, fi);
   strcpy(buf, ind.cedula);
   return buf;
}

void Intercambia(FILE *fi, long iz, long de)
{
   stIndice reg1, reg2;
   fseek(fi, iz*sizeof(stIndice), SEEK_SET);
   fread(&reg1, sizeof(stIndice), 1, fi);
   fseek(fi, de*sizeof(stIndice), SEEK_SET);
   fread(&reg2, sizeof(stIndice), 1, fi);
   fseek(fi, iz*sizeof(stIndice), SEEK_SET);
   fwrite(&reg2, sizeof(stIndice), 1, fi);
   fseek(fi, de*sizeof(stIndice), SEEK_SET);
   fwrite(&reg1, sizeof(stIndice), 1, fi);
}
/*
int pass()
{
 char *password;
   char *clave= "eevee";
   int ptr;
   clrscr();
   gotoxy(25,10);textcolor(15);
   password = getpass("Digite Su Password:"); //predeterminado captura el pass
   ptr = strcmp(password, clave);
   if (ptr == 0)
     {
     clrscr();
      gotoxy(30,12);textcolor(15);
      cprintf("B I E N V E N I D O");
      getch();
      clrscr();
      return 1;
     }
   else
     {
      clrscr();
      gotoxy(16,12);textcolor(15);
      cprintf("        MAL MUY MAL ESA NO ES GURRESITO        ");
      getch();
      return 0;
     }
     }*/


void capturanom(stNomina &reg1)
{
reg1.valido = 'S';
   //char cedu[15];
   gotoxy(19,8); printf("Cedula: ");
   cin>>reg1.cedula;
   gotoxy(19,9);printf("Dia: ");
   cin>>reg1.dia;
   gotoxy(29,9);printf("Mes: ");
   cin>>reg1.mes;
   gotoxy(40,9);printf("A¤o: ");
   cin>>reg1.ano;
   gotoxy(19,10);printf("Valor primera quincena: ");
   cin>>reg1.quincena1;
   gotoxy(19,11);printf("Valor segunda quincena: ");
   cin>>reg1.quincena2;
   reg1.salario1=reg1.quincena2 + reg1.quincena1;
   reg1.auxtrans=reg1.salario1 * 0.1;
   reg1.pension=reg1.salario1 * 0.05;
   reg1.salud=reg1.salario1 * 0.1;
   reg1.fondoempl=reg1.salario1 * 0.05;
   gotoxy(19,18);printf("Presione tecla para continuar");
  }


void Insertaro(FILE *fe, stNomina &reg)
{
   // Insertar al final:
   fseek(fe, 0, SEEK_END);
   fwrite(&reg, sizeof(stNomina), 1, fe);
   ReconstruirIndicesno(fe);
}

void ListarNaturale(FILE *fe)
{
   stNomina reg;
   rewind(fe);
   while(fread(&reg, sizeof(stNomina), 1, fe))
     Mostrare(reg);
     minicuadros();
}

void Mostrare(stNomina &reg)
{
   //if(reg.valido == 'S') {
   minicuadros();
      gotoxy(19,8);printf("Cedula: %s\n",reg.cedula);
      gotoxy(19,9);printf("Dia: %d  Mes: %d  A¤o: %d ", reg.dia, reg.mes, reg.ano);
      gotoxy(19,10);printf("Salario del mes: %d",reg.salario1);
      gotoxy(19,11);printf("Auxilio de transporte: %d",reg.auxtrans);
      gotoxy(19,12);printf("Pension: %d",reg.pension);
      gotoxy(19,13);printf("Salud: %d", reg.salud);
      gotoxy(19,14);printf("Fonde de empleados: %d", reg.fondoempl);
      gotoxy(19,16);printf("Presiona una tecla para continuar ");
      getch();
   //}
}

void novedades(FILE *fa)
{
int x;
stRegistro reg;
long totalreg,totalmuj,totalhom,Totalnom,total2,total4,total6,totalt;
total2=0;
total4=0;
total6=0;
totalt=0;
Totalnom=0;
totalreg=0;
totalmuj=0;
totalhom=0;
while(fread(&reg, sizeof(stRegistro), 1, fa))
     {
     totalreg=totalreg+1;
     if (reg.sexo[0]=='F' || reg.sexo[0]=='f')
     totalmuj=totalmuj+1;
     else
     totalhom=totalhom+1;
     Totalnom=Totalnom+reg.salario;
     if(reg.edad<=20)
     total2=total2+1;
     else
      if(reg.edad<=40)
      total4=total4+1;
      else
       if(reg.edad<=60)
       total6=total6+1;
       else
       totalt=totalt+1;
     }
gotoxy(20,8);cout<<"Existen "<<totalreg <<" registros";
gotoxy(20,9);cout<<"Hay "<<totalmuj <<" registros de mujeres";
gotoxy(20,10);cout<<"Hay "<<totalhom <<" registros de hombres";
gotoxy(20,11);cout<<"Hay un pago total de "<<Totalnom <<" en la nomina";
gotoxy(20,13);cout<<"Ocsilacion en las edades ";
x=13;
if (total2 != 0)
{gotoxy(20,x+=1);cout<<"Entre 10 - 20 anos "<<total2;}
if (total4 != 0)
{gotoxy(20,x+=1);cout<<"Entre 21 - 40 anos "<<total4;}
if (total6 != 0)
{gotoxy(20,x+=1);cout<<"Entre 41 - 60 anos "<<total6;}
if (totalt != 0)
{gotoxy(20,x+=1);cout<<"Mayores de 61 anos "<<totalt;}
}

void ListarPorcedula(FILE *fe)
{
   FILE *fo;
   stIndices ind;
   stNomina reg;
   fo = fopen("indices.nor", "rb");
   while(fread(&ind, sizeof(stIndices), 1, fo)) {
      fseek(fe, ind.indice*sizeof(stNomina), SEEK_SET);
      fread(&reg, sizeof(stNomina), 1, fe);
      Mostrare(reg);
      }
   fclose(fo);
}

// Lee el registro desde el fichero de datos con la cedula dada
void Leernomina(FILE *fe, stNomina &reg, char *cedula)
{
   FILE *fi;
   stIndices ind;
   long inf, sup, n, nRegs;
   fi = fopen("indices.nor", "rb");
   fseek(fi, 0, SEEK_END);
   nRegs = ftell(fi)/sizeof(stIndice);
   // Búsqueda binaria:
   inf = 0;
   sup = nRegs-1;
   do {
      n = inf+(sup-inf)/2;
      fseek(fi, n*sizeof(stIndices), SEEK_SET);
      fread(&ind, sizeof(stIndices), 1, fi);
      if(strcmp(ind.cedula, cedula) < 0) inf = n+1;
      else sup = n-1;
   } while(inf <= sup && strcmp(ind.cedula, cedula));
   // Si se encontr¢ el tel¢fono, lee el registro, si no muestra mensaje.
   if(!strcmp(ind.cedula, cedula)) {
      fseek(fe, ind.indice*sizeof(stNomina), SEEK_SET);
      fread(&reg, sizeof(stNomina), 1, fe);
    }
   fclose(fi);
}

void ReconstruirIndicesno(FILE *fe)
{
   long n=0;
   FILE *fi;
   stNomina reg;
   stIndices ind;
   // Crea el fichero de índices a partir del archivo de datos:
   fi = fopen("indices.nor", "w+b");
   rewind(fe);
   while(fread(&reg, sizeof(stNomina), 1, fe)) {
      strcpy(ind.cedula, reg.cedula);
      ind.indice = n++;
      fwrite(&ind, sizeof(stIndices), 1, fi);
    }
   // Ordena usando el algoritmo Quicksort:
   QuickSorte(fi, 0, n-1);
   fclose(fi);
}

// Implementación del algoritmo Quicksort para fichero de índices
void QuickSorte(FILE *fi, long inicio, long final)
{
   long iz, de;
   char mitad[10];
   static char cad[10];
   iz = inicio;
   de = final;
   strcpy(mitad, LeeCampos(fi, (iz+de)/2, cad));
   do {
      while(strcmp(LeeCampos(fi, iz, cad), mitad) < 0 && iz < final) iz++;
      while(strcmp(mitad, LeeCampos(fi, de, cad)) < 0 && de > inicio) de--;
      if(iz < de) Intercambian(fi, iz, de);
      if(iz <= de) {
	 iz++;
	 de--;
      }
   } while(iz <= de);
   if(inicio < de) QuickSorte(fi, inicio, de);
   if(iz < final) QuickSorte(fi, iz, final);
}

char *LeeCampos(FILE *fi, long n, char *buf)
{
   stIndice ind;
   fseek(fi, n*sizeof(stIndices), SEEK_SET);
   fread(&ind, sizeof(stIndices), 1, fi);
   strcpy(buf, ind.cedula);
   return buf;
}

void Intercambian(FILE *fi, long iz, long de)
{
   stIndices reg1, reg2;
   fseek(fi, iz*sizeof(stIndices), SEEK_SET);
   fread(&reg1, sizeof(stIndices), 1, fi);
   fseek(fi, de*sizeof(stIndices), SEEK_SET);
   fread(&reg2, sizeof(stIndices), 1, fi);
   fseek(fi, iz*sizeof(stIndices), SEEK_SET);
   fwrite(&reg2, sizeof(stIndices), 1, fi);
   fseek(fi, de*sizeof(stIndices), SEEK_SET);
   fwrite(&reg1, sizeof(stIndices), 1, fi);
}


void Totales(FILE *fe)
{
int x;
stNomina reg;
long ano,totalsal,totaltra,totalpen,totalsalu,totalfon,totalt;
totalsal=0;
totaltra=0;
totalpen=0;
totalsalu=0;
totalfon=0;
x=0;
gotoxy(20,12);printf("INGRESE EL ANO QUE DESEA BUSCAR ");
cin>>ano;
while(fread(&reg, sizeof(stNomina), 1, fe))
     {
     if (reg.ano==ano)
     {
     Mostrare(reg);
     totalsal=totalsal+reg.salario1;
     totaltra=totaltra+reg.auxtrans;
     totalsalu=totalsalu+reg.salud;
     totalfon=totalfon+reg.fondoempl;
     totalpen=totalpen+reg.pension;
     x=8;
     }
     }
     if(x==8)
     {minicuadros();
      gotoxy(22,9);printf("LOS VALORES DEL ANO %d SON",reg.ano);
      gotoxy(19,11);printf("Salario del ano: %d",reg.salario1);
      gotoxy(19,12);printf("Auxilio de transporte: %d",reg.auxtrans);
      gotoxy(19,13);printf("Pension: %d",reg.pension);
      gotoxy(19,14);printf("Salud: %d", reg.salud);
      gotoxy(19,15);printf("Fonde de empleados: %d", reg.fondoempl);
      gotoxy(19,17);printf("Presiona una tecla para continuar ");
      }
      else
      {
      minicuadros();
      gotoxy(19,15);printf("NO HAY REGISTROS DE EL ANO %d",reg.ano);
      }
      getch();
}
