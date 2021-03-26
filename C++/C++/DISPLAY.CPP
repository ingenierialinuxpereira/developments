#include <graphics.h>
#include <conio.h>
#include <iostream.h>
#include <stdlib.h>

//void IniciarGrafico ();

void IniciarGrafico()
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

int dib1()
{
  setfillstyle(1,4);
  rectangle(30,30,35,60);
  rectangle(30,65,35,95);
  rectangle(40,60,70,65);
  rectangle(40,95,70,100);
  rectangle(40,25,70,30);
  bar(75,30,80,60);
  bar(75,65,80,95);
  getch();
 return 1;
}
int dib2()
{
setfillstyle(1,4);
  rectangle(30,30,35,60);
  bar(30,65,35,95);
  bar(40,60,70,65);
  bar(40,95,70,100);
  bar(40,25,70,30);
  bar(75,30,80,60);
  rectangle(75,65,80,95);
  getch();
 return 1;
}

int dib3()
{
  setfillstyle(1,4);
  rectangle(30,30,35,60);
  rectangle(30,65,35,95);
  bar(40,60,70,65);
  bar(40,95,70,100);
  bar(40,25,70,30);
  bar(75,30,80,60);
  bar(75,65,80,95);
  getch();
 return 1;
 }
int dib4()
{
 setfillstyle(1,4);
  bar(30,30,35,60);
  rectangle(30,65,35,95);
  bar(40,60,70,65);
  rectangle(40,95,70,100);
  rectangle(40,25,70,30);
  bar(75,30,80,60);
  bar(75,65,80,95);
  getch();
 return 1;
}
int dib6()
{
  setfillstyle(1,4);
  bar(30,30,35,60);
  bar(30,65,35,95);
  bar(40,60,70,65);
  bar(40,95,70,100);
  bar(40,25,70,30);
  rectangle(75,30,80,60);
  bar(75,65,80,95);
  getch();
 return 1;
}

int dib5()
{
  setfillstyle(1,4);
  bar(30,30,35,60);
  rectangle(30,65,35,95);
  bar(40,60,70,65);
  bar(40,95,70,100);
  bar(40,25,70,30);
  rectangle(75,30,80,60);
  bar(75,65,80,95);
  getch();
 return 1;
}

int dib7()
{
 setfillstyle(1,4);
  rectangle(30,30,35,60);
  rectangle(30,65,35,95);
  rectangle(40,60,70,65);
  rectangle(40,95,70,100);
  bar(40,25,70,30);
  bar(75,30,80,60);
  bar(75,65,80,95);
  getch();
 return 1;
}

int dib8()
{
 //clrscr();
  setfillstyle(1,4);
  bar(30,30,35,60);
  bar(30,65,35,95);
  bar(40,60,70,65);
  bar(40,95,70,100);
  bar(40,25,70,30);
  bar(75,30,80,60);
  bar(75,65,80,95);
  getch();
//  closegraph();
  return 1;
}
int dib9()
{
 setfillstyle(1,4);
  bar(30,30,35,60);
  rectangle(30,65,35,95);
  bar(40,60,70,65);
  bar(40,95,70,100);
  bar(40,25,70,30);
  bar(75,30,80,60);
  bar(75,65,80,95);
  getch();
 return 1;
}
int dib0()
{
 setfillstyle(1,4);
  bar(30,30,35,60);
  bar(30,65,35,95);
  rectangle(40,60,70,65);
  bar(40,95,70,100);
  bar(40,25,70,30);
  bar(75,30,80,60);
  bar(75,65,80,95);
  getch();
 return 1;
}



int main ()
{
  int num;
  IniciarGrafico();
  //getch();
  //relleno de area**************/
  do
  {
  cleardevice();
  gotoxy(2,1);cout<<"Que numero :  ";
  gotoxy(20,1);cin>>num;
  switch(num)
  {
   case 0: dib0();break;
   case 1: dib1();break;
   case 2: dib2();break;
   case 3: dib3();break;
   case 4: dib4();break;
   case 5: dib5();break;
   case 6: dib6();break;
   case 7: dib7();break;
   case 8: dib8();break;
   case 9: dib9();break;
   //default:cout<<"Error...";getch();break;
  }
  }while(num>=0 && num<=9);
 /* setfillstyle(1,4);
  rectangle(30,30,35,60);
  rectangle(30,65,35,95);
  rectangle(40,60,70,65);
  rectangle(40,95,70,100);
  rectangle(40,25,70,30);
  rectangle(75,30,80,60);
  rectangle(75,65,80,95);*/
  closegraph();
  return 0;
}
