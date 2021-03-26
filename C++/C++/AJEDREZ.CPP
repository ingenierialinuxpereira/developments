#include <graphics.h>
#include <iostream.h>
#include <conio.h>
#include <dos.h>
					 //PACHO


#define XMAX getmaxx()
#define YMAX getmaxy()
#define POSX 50
#define POSY 50
#define DEMORAEVENTO 5

#define ANCHO 40
#define ALTO 40


int IniciarModoGrafico();
int PintarCajon(int x,int y,int color);
int PintarTablero();
int DibujarPeon(int x,int y,int ColorPeon);
int PintarFichas();

int main()
{
 if(IniciarModoGrafico()==1)
   {
    PintarTablero();
    PintarFichas();
   }
 getch();
 closegraph();
 return 1;
}

//Funcion que inicia el modo grafico retorna 0 si hay problemas
//o 1 si todo esta bien
int IniciarModoGrafico()
{
int gdriver = DETECT, gmode, errorcode;
int ban=1;
/* Se llama a la funcion que inicia el modo grafico*/
initgraph(&gdriver, &gmode, "c:\\tc\bgi\\");

/* Se mira el resultado del incio de modo grafico puede tener o no exito el inicio */
errorcode = graphresult();
/* si Ocurrio un ERROR */
if (errorcode != grOk)
{
	cout<<"Error de greficos :"<<endl<<grapherrormsg(errorcode);
	getch();
	ban=0;
}

return ban;
}


int PintarCajon(int x,int y,int color)
{
 if(color%2==0)
   setfillstyle(LTBKSLASH_FILL,DARKGRAY);
 else
   setfillstyle(SOLID_FILL,LIGHTGRAY);

 bar(POSX+x*ANCHO+1,POSY+y*ALTO+1,POSX+(x+1)*ANCHO-1,POSY+(y+1)*ALTO-1);
 delay(50);
 return 1;
}


int PintarTablero()
{
  int i,j,ban;
  for(i=0,ban=1;i<8;i++,ban++)
   for(j=0;j<8;j++,ban++)
      PintarCajon(i,j,ban);

  setcolor(WHITE);
  setlinestyle(SOLID_LINE,0,2);
  rectangle(POSX-2,POSY-2,POSX+i*ANCHO+2,POSY+i*ALTO+2);
  setcolor(LIGHTGRAY);
  rectangle(POSX-1,POSY-1,POSX+i*ANCHO+1,POSY+i*ALTO+1);

  return 1;
}

int PintarFichas()
{
 int i,j;
 for(i=0,j=70;i<8;i++,j++)
  {
   DibujarPeon(POSX+i*ANCHO-5,POSY+1*ALTO-5,15);
   DibujarPeon(POSX+i*ANCHO-5,POSY+6*ALTO-5,73);
  }
 return 1;
}

int DibujarPeon(int x,int y,int ColorPeon)
{
setfillstyle(SOLID_FILL,ColorPeon);
bar(x+17,y+32,x+33,y+38);
bar(x+22,y+25,x+28,y+38);
setcolor(ColorPeon);
pieslice(x+25,y+19,0,180,6);
line(x+18,y+22,x+32,y+22);
line(x+19,y+23,x+31,y+23);
line(x+18,y+21,x+32,y+21);
return 0;
}
