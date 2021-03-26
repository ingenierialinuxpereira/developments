#include<conio.h>
#include<stdio.h>
#include<iostream.h>
#include<dos.h>
unsigned int Ratonx,Ratony,Ratonb;// ratonx guarda coordenada x...
				 // raton y coordenada y
				 // ratonb guarda los botones

void mostrarraton();
void esconderraton();
void leerraton();

//se empiezan a realizar las funciones:

void mostrarraton()
{
   asm mov ax,0x1
   asm int 0x33
 }

void esconderraton()
{
 asm mov ax,0x2
 asm int 0x33
}
void leerraton()
{
 asm mov ax,0x3
 asm int 0x33
 asm mov Ratonb,bx
 asm mov Ratonx,cx
 asm mov Ratony,dx
}


 int main()
 {
  mostrarraton();
  while(!kbhit())
  {
   clrscr();
   leerraton();
   cout<<"("<<Ratonx<<","<<Ratony<<")\n";
   if(Ratonb==1)
   cout<<"BOTON IZQUIERDO PRESIONADO";
   else
    if(Ratonb==2)
    cout<<"BOTON DERECHO PRESIONADO";
   else
    if(Ratonb==3)
    cout<<"AMBOS BOTONES PRESIONADO";
   else
    cout<<"NINGUN BOTON PRESIONADO";
   delay(30);
  }
  return 0;
 }

