#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<a:grafico.h>
#include<dos.h>
#include<iostream.h>

void mostrarraton (void);  // colocamos el prototipo para mostrar raton..
void ocultarraton (void);
void leerraton    (void);
  int boton, x,y;
int main()
{
iniciarmodografico();
mostrarraton();
do
{
 leerraton();
 gotoxy(4,4);
 cout<<"("<<x<<","<<y<<")";
 }
 while(!kbhit());
 cerrarmodografico();
return 0;
}



void mostrarraton()
{
asm mov  ax,0x1     //le indica a c++ que este es el lenguaje ensamblador..
asm int 0x33
}
void ocultarraton()
{
asm mov ax,0x2
asm int 0x33
}
void leerraton()
{
asm mov ax,3
asm int 0x33
asm mov boton, bx  // asigno aboton la informacion de los botones
asm mov x, cx  // asigno a "x" la coordenada "x"
asm mov y, dx   //asigno a "y" la coordenada "y"
}

