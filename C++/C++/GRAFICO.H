#include <graphics.h>
#include <conio.h>
#include <iostream.h>
#include <stdlib.h>

void iniciarmodografico ()
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
}

