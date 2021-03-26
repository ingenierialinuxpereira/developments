#include <graphics.h>
#include <conio.h>
#include <iostream.h>
#include <stdlib.h>

//int main ()
void iniciarmodografico()
{
 int tarjeta,modo,error;
 detectgraph(&tarjeta,&modo);
 initgraph(&tarjeta,&modo,"c:\\tc\\bgi");
 error=graphresult();
 if (error)
 {
  clrscr();
  cout<<grapherrormsg(error);
  getch();
  exit(1);
 }
 else
 {
  getch();
  circle(100,200,30);
  getch();
  closegraph();
 }
 return 0;
}

