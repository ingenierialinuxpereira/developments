/*#include<stdio.h>
#include<conio.h>
#include <string.h>
#include <io.h>
#include<dos.h>
#include<stdlib.h>*/


#include <sys\stat.h>
#include <string.h>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include<stdlib.h>
#include<conio.h>


void crear();
void leer();
void abrir();
void main()
{
int f,fco,opc;
while(opc!=5)
{
printf("1.crear");
printf("2.abrir");
printf("4.leer");
printf("5.salir");
printf("Elija:");
scanf("%d",&opc);
switch(opc)
{
case 1:crear();break;
case 2:printf("falta");
case 4:printf("falta");
case 5:printf("saliendo...");break;
}
}
getch();
}
void crear()
{
int f,fco;
char nom[40];
char cad[10];
printf("digite el nombre del archivo");scanf("%s",&nom);
printf("la cadena");scanf("%s",&cad);

 f=40;
 clrscr();

 _fmode =O_BINARY ;

if ((fco = creat (nom, 0)) == -1)
{
printf("Error de creacion");
getch();
exit(1);
}
write(fco,cad,f);
close (fco);
}

