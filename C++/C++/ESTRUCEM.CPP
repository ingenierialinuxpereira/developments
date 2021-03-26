#include "conio.h"
#include "stdio.h"
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

void main()
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