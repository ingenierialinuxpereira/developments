#include<stdio.h>
#include<iostream.h>
#include<stdlib.h>
#include<raton.h>
#include<grafico.h>

int main ()
{
 iniciarmodografico();
 mostrarraton();
 leerraton();
 //rectangle(100,100,180,120);
// outtextxy(105,105,"HOLA");
 setfillstyle(1,6);
 bar3d(100,100,180,120,5,8);
 outtextxy(125,106,"CLICK");
// getch();
 //closegraph();
 while(!kbhit())
 {
 leerraton();
 if(MouseX>=100&&MouseY>=100&&MouseY<=120&&MouseB==1)
  outtextxy(200,200,"HAZ HECHO CLICK EN EL BOTON");
 delay(15);

 //cout<<MouseX;
}
 closegraph();
 return 0;
}


