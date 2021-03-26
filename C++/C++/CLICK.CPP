#include <graphics.h>
#include<grafico.h>
#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
#include <dos.h>

int ratonX, ratonY, ratonB; //ratony son lascoordenadas
void mostrarraton();                 //ratonx son lascoordenadas
void esconderraton();                //ratonb son los botones
void leerraton();
//muestra el raton
void mostrarraton()
{
 asm mov ax,0x1
 asm int 0x33
}
//esconde el raton
void esconderraton()
{
 asm mov ax,0x2
 asm int 0x33
}

void leerraton()
{
 asm mov ax,0x3
 asm int 0x33
 asm mov ratonB,bx
 asm mov ratonX,cx
 asm mov ratonY,dx
}

int main()
{

 iniciarmodografico();
 mostrarraton();

 while (!kbhit())
 {

  leerraton();
  gotoxy(2,5);
  cout<<"LAS COORDENADAS SON: ";
  cout<<"("<<ratonX<<", "<<ratonY<<")\n";
  if(ratonB==1)
  cout<<"Boton izquierdo presionado";
  else
   if(ratonB==2)
   cout<<"Boton derecho presionado";
   else
    if (ratonB==3)
    cout<<"Ambos botones presiondos";
    else
    cout<<"Ningun boton presionado";

 }
 return 0;

}



