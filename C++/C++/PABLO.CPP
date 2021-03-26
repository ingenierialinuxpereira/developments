#include<stdio.h>
#include<conio.h>
#include<math.h>
#define n 12
#define j 29
#define v 99
void areacirc();
void areatriangulo();
void areacuadrado();
void subareas();
void geometria();
void subvol();
void subper();
void ecuacion();
void cuadratica();
void nomina();
void conversion();
void clasedad();
void main()
{
int op;
clrscr();
while(op!=6)
{
printf("1-Conversiones");
printf("\n\r2-Ecuaciones");
printf("\n\r3-Nomina");
printf("\n\r4-Clasificacion edades");
printf("\n\r5-Geometria");
printf("\n\r6-salir");
printf("\n\rElija:");
scanf("%d",&op);
switch(op)
{
case 1:conversion();
break;
case 2:ecuacion();
break;
case 3:nomina();
break;
case 4:clasedad();
break;
case 5:geometria();
break;
case 6:printf("Saliendo...");
break;
}
}
}
void conversion()
{
int op;
clrscr();
printf("1-Angulos");
printf("\n\r2-temperaturas");
printf("\n\r3-medidas longitud");
printf("\n\r4-Salir");
printf("\n\relija:");
scanf("%d",&op);
clrscr();
}
void ecuacion()
{
int op;
clrscr();
while(op!=5)
{
printf("\n\r1-Lineales");
printf("\n\r2-Cuadraticas");
printf("\n\r3-Diferenciales");
printf("\n\r4-Sistemas de ec.");
printf("\n\r5-Salir");
printf("\n\relija:");
scanf("%d",&op);
switch(op)
{
case 1:printf("En construccion...");
break;
case 2:printf("En construccion");
break;
case 3:printf("En construccion...");
break;
case 4:printf("En construccion...");
break;
}
}
}
void nomina()
{
int s,d,o,t;
clrscr();
printf("Ingrese sueldo:");
scanf("%d",&s);
printf("valor salud en pesos:");
scanf("%d",&d);
printf("sueldo a pagar:%d\n\r",s-d);
}
void clasedad()
{
int edad;
clrscr();
printf("edad:");
scanf("%d",&edad);
if((edad>0) && (edad<=12))
{
printf("Ni¤o...\n\r");
}
if((edad>13) && (edad<=29))
printf("Joven...\n\r");
if((edad>29)&&(edad<=99))
printf("Viejo...\n\r");
}
void geometria()
{
int op;
clrscr();
while(op!=4)
{
printf("1-Areas");
printf("\n\r2-Perimetro");
printf("\n\r3-Volumenes");
printf("\n\r4-Salir");
printf("\n\relija:");
scanf("%d",&op);
switch(op)
{
case 1:subareas();
break;
case 2:subper();
break;
case 3:subvol();
break;
case 4:printf("Saliendo...");
break;
}
clrscr();
}
}
void subareas()
{
int op;
clrscr();
while(op!=4)
{printf("\n\r1-cuadrado");
printf("\n\r2-triangulo");
printf("\n\r3-circulo");
printf("\n\r4-Salir");
printf("\n\relija:");
scanf("%d",&op);
switch(op)
{
case 1:areacuadrado();
putchar(char(178));
break;
case 2:areatriangulo();
putchar(char(127));
break;
case 3:areacirc();
putchar(char(9));
break;
case 4:printf("Saliendo...");
break;
}
clrscr();
}
}
void subvol()
{
int op;
clrscr();
while(op!=4)
{printf("1-cuadrado");
printf("\n\r2-triangulo");
printf("\n\r3-circulo");
printf("\n\r4-Salir");
printf("\n\relija:");
scanf("%d",&op);
switch(op)
{
case 1:putchar(char(178));
break;
case 2:putchar(char(127));
break;
case 3:putchar(char(9));
break;
case 4:printf("Saliendo...");
break;
}
clrscr();
}
}
void subper()
{
int op;
clrscr();
while(op!=4)
{
printf("1-cuadrado");
printf("\n\r2-triangulo");
printf("\n\r3-circulo");
printf("\n\r4-Salir");
printf("\n\relija:");
scanf("%d",&op);
switch(op)
{
case 1:putchar(char(178));
break;
case 2:putchar(char(127));
break;
case 3:putchar(char(9));
break;
case 4:printf("Saliendo...");
break;
}
clrscr();
}
}
void areacirc()
{
float pi,r;
clrscr();
pi=3.1416;
r=r*r;
printf("Ingrese valor correspondiente en centimetros al radio:");
scanf("%f",&r);
printf("El area es:%fcm",pi*r);
getch();
}
void areacuadrado()
{
float l;
clrscr();
l=l*l;
printf("Ingrese valor del lado:");
scanf("%f",&l);
printf("El area es:%f",l);
getch();
}
void areatriangulo()
{
float b,h,a;
clrscr();
printf("Ingrese base en centimetros:");
scanf("%f",&b);
printf("Ingrese altura en centimetros:");
scanf("%f",&h);
a=(b*h)/2;
printf("El area es:%fcm",a);
getch();
}

