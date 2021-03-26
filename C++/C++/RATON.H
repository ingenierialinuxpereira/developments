//Implememtacion del raton desde C++ usando rutinas de lenguaje ensamblador

#include "dos.h"
//#include "iostream.h"
//#include "conio.h"
//#include "a:grafico.h"

int x,y,boton;

//Si detectarraton devuelve -1, el raton esta presente
int detectarraton ()
{
 //La funcion 0x02 en el registro bx, con la interrupcion 0x33,
 //valida la presencia del raton y retorna el valor al registro ax
 int w;
 asm mov ax,0
 asm mov bx,0x02
 asm int 0x33
 asm mov w,ax
 return w;
}

//Una vez detectado el raton, se definen los limites del mismo
void limitarraton (int xi, int yi, int xf, int yf)
{
 //La funcion 7 en el registro ax establece, con la interrupcion 0x33, los
 //limites horizontales del raton y los guarda en los registros cx y dx
 asm mov ax,7
 asm mov cx,xi
 asm mov dx,xf
 asm int 0x33
 //La funcion 8 en el registro ax establece, con la interrupcion 0x33, los
 //limites verticales del raton y los guarda en los registros cx y dx
 asm mov ax,8
 asm mov cx,yi
 asm mov dx,yf
 asm int 0x33
}

//La funcion 1 en el registro ax, con la interrupcion 0x33, muestra
//puntero del raton.  Si se esta en modo grafico muestra el puntero que
//hay en Windows, sino, el que aparece en este editor
void mostrarraton ()
{
 asm mov ax,1
 asm int 0x33
}

//La funcion 2 en el registro ax, con la interrupcion 0x33, oculta
//el puntero del raton
void ocultarraton ()
{
 asm mov ax,2
 asm int 0x33
}

//La funcion 3 en el registro ax, con la interrupcion 0x33, lee el estado
//de los botones del raton y la posicion del mismo, y guarda el resultado
//en los registro bx para los botones, cx y dx para la posicion
void leerraton ()
{
 //int x,y,boton;
 asm mov ax,3
 //Colocamos de nuevo en cero las variables que guardaran el estado
 //del raton (bx,cx,dx)
 asm mov bx,0
 asm mov cx,0
 asm mov dx,0
 asm int 0x33
 //Si bx vale 1, se pulso el boton izquierdo, si bx vale 2 se pulso el
 //derecho, y si bx vale 4 se pulso el central
 asm mov boton,bx
 //En cx se guarda loa posicion horizontal y en dx la posicion vertical
 asm mov x,cx
 asm mov y,dx
}

//Funcion que pone el raton el una posicion determinada de la pantalla
//Recibe las posiciones en x y en y
void moverraton (int px,int py)
{
 asm mov ax,4
 //En cx guardamos la posicion x del raton
 asm mov cx,px
 //En dx guardamos la posicion y del raton
 asm mov dx,py
 asm int 0x33
}
