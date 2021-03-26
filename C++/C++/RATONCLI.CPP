//#include <graphics.h>
#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
#include <dos.h>

unsigned int ratonX, ratonY, ratonB; //ratonx  y ratony son lascoordenadas, raton b son los botones

void leerraton();
void mostrarraton();          //funciones declaradas para el desempeño del programa
void esconderraton();

/*muestra el raton*/
void mostrarraton()
{
 asm mov ax,0x1 //muestra al c++ que se esta trabajando con ensamblador
 asm int 0x33
}
/*esconde el raton*/
void esconderraton()
{
 asm mov ax,0x2 //muestra al c++ que se esta trabajando con ensamblador
 asm int 0x33
}

void leerraton()
{
 asm mov ax,0x3 //muestra al c++ que se esta trabajando con ensamblador
 asm int 0x33
 asm mov ratonB,bx  //clicks del raton
 asm mov ratonX,cx   //movimiento del raton en pantalla
 asm mov ratonY,dx
}

int main()
{
 mostrarraton();// inicio del programa

 while (!kbhit())
 {
  clrscr();
  leerraton();
  cout<<"LAS COORDENADAS SON: ";
  cout<<"("<<ratonX<<", "<<ratonY<<")\n";
  if(ratonB==1)                                                      //interrupcion del raton para indicar las coordenadas del raton, y cada click accionado
  cout<<"Boton izquierdo presionado";
  else
   if(ratonB==2)
   cout<<"Boton derecho presionado";
   else
    if (ratonB==3)
    cout<<"Ambos botones presiondos";
    else
    cout<<"Ningun boton presionado";

  delay(80);
 }
 return 0;
}



