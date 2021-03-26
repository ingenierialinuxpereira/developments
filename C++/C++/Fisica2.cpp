#include <graphics.h>
#include<math.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<iostream.h>
void ventanas();
void menu();
void ecuacionacelera();
void ecuaciondesplaza();
int main(void)
{
   /* PIDIENDO AUTO DETECCION */
   int gdriver = DETECT, gmode, errorcode;
   int left1,top1,right1,bottom1;

   initgraph(&gdriver, &gmode, "");
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Error de modo grafico: %s\n", grapherrormsg(errorcode));
      printf("Presione cualquier tecla:");
      getch();
      exit(1);
    }
    ventanas();
    menu();
	  getch();
    closegraph();
    return 0;
}
/**********************************************************/
void ventanas()
{

   int xmax,xmax1,ymax1;
   int ymax, xmaxb,ymaxb;
   int left1,top1,right1,bottom1;

   cleardevice(); //limpia pantalla
/*****************************************************/
   left1 = getmaxx() / 1.5 - 116;
   top1 = getmaxy() / 1.5-68;
   right1 = getmaxx() /1.5 +260;
   bottom1 = getmaxy() /1.5 + 200;

   setfillstyle(1,17);
   bar(left1,top1,right1,bottom1);       // ventana roja
/*****************************************************/
   rectangle(0,0,310,250);
   rectangle(310,0,639,250);//ventanas de texto en color negro
   rectangle(0,479,310,250);
   gotoxy(20,7);
   printf("[");gotoxy(22,7);printf("]");
}
/******************************************************/
void menu()
{
int op;
double velocidad,tiempo,espacio,ec1,ec2,ec3,ec4,ec5,ec6,ec7;
char intervalo,a,b,c,d,e,f,g;
float x,h,i,y,y1,x1,cx,cy;
   char msg[80];
   int intervalos[6]={2-2/2,5-2/2,10-5/2,15-10/2,20-15/2,22-20/2};//operacion de cda intervalo en la ecuacion de caeleracion
   //la grafica sale al reves.
   int tie[6]={2,40,80,100,120,140};

while(op!=4)
{
outtextxy(10,55,"1-Solucion ecuacion aceleracion: ");
outtextxy(10,65,"2-Solucion ecuacion desplazamiento:");
outtextxy(10,75,"3-Grafica:");
outtextxy(10,85,"4-Salir");
outtextxy(10,101,"Elija una opcion:");
gotoxy(21,7);
cin>>op;


switch(op)
{
case 1:outtextxy(10,199,"a=Vf-Vi/t");ecuacionacelera();
break;
case 2:
gotoxy(2,25);printf("                                    ");
gotoxy(37,24);printf("  ");
gotoxy(23,18);printf("               ",ec1);
outtextxy(10,199,"         ");
outtextxy(10,199,"X=VxT    "); ecuaciondesplaza();
break;
case 3:outtextxy(10,120,"tiempo");
outtextxy(10,135,"velocidad");
outtextxy(100,120,"0");outtextxy(100,135,"0");
outtextxy(120,120,"2");outtextxy(120,135,"0");
outtextxy(140,120,"4");outtextxy(140,135,"2");
outtextxy(160,120,"6");outtextxy(160,135,"5");
outtextxy(180,120,"8");outtextxy(180,135,"10");
outtextxy(200,120,"10");outtextxy(200,135,"15");
outtextxy(220,120,"12");outtextxy(220,135,"20");
outtextxy(240,120,"14");outtextxy(240,135,"22");
outtextxy(260,120,"16");outtextxy(260,135,"22");
outtextxy(70,150,"TABLA DE DEMOSTRACION");
/**************************************************/
outtextxy(10,295,"Inervalo [a] de:2sg a 4sg");
outtextxy(10,305,"Inervalo [b] de:4sg a 6sg");
outtextxy(10,315,"Inervalo [c] de:6sg a 8sg");   //llamado a la tabla de la opcion 1 correspondiente a los intervalos
outtextxy(10,325,"Inervalo [d] de:8sg a 10sg");
outtextxy(10,335,"Inervalo [e] de:10sg a 12sg");
outtextxy(10,345,"Inervalo [f] de:12sg a 14sg");
outtextxy(10,355,"Inervalo [g] de:14sg a 16sg");
gotoxy(59,4);printf("        ");
gotoxy(55,5);printf("    ");
gotoxy(63,7);printf("                ");
/***********************************************/

for(x=0;x<=5;x++)
      {
	x1=intervalos[x];
	y1=tie[x];
	cx=(intervalos[x+1]-intervalos[x]) / 10;
	cy=(tie[x+1]-tie[x]) / 10;
	cx=cx*(-1);
	while( x1<=intervalos[x+1] &&  y1<= tie[x+1])

	{
	   moverel(x1, y1);
	   putpixel(430+x1,270+y1, YELLOW);
	   x1=x1+cx;
	   y1=y1+cy;

	 }
       }

 outtextxy(320,400,"Grafica en base a los iontervalos");
 outtextxy(320,420,"de ejemplo de opcion 1");
	outtextxy(445,360,"");break;
case 4: outtextxy(90,180,"OPRIMA ENTER");break;
}
}
}
/***********************************************************/
void ecuacionacelera()
{
float op,velocidad,tiempo,espacio,t,v1,v2;
double ec1,ac,ec2,ec3,ec4,ec5,ec6,ec7;
char intervalo,a,b,c,d,e,f,g,res;

outtextxy(10,120,"tiempo");
outtextxy(10,135,"velocidad");
outtextxy(100,120,"0");outtextxy(100,135,"0");
outtextxy(120,120,"2");outtextxy(120,135,"0");
outtextxy(140,120,"4");outtextxy(140,135,"2");
outtextxy(160,120,"6");outtextxy(160,135,"5");
outtextxy(180,120,"8");outtextxy(180,135,"10");
outtextxy(200,120,"10");outtextxy(200,135,"15");
outtextxy(220,120,"12");outtextxy(220,135,"20");
outtextxy(240,120,"14");outtextxy(240,135,"22");
outtextxy(260,120,"16");outtextxy(260,135,"22");
outtextxy(70,150,"TABLA DE DEMOSTRACION");
/*************************************/
outtextxy(10,276,"Ingrese intervalo:");
outtextxy(10,295,"Inervalo [a] de:2sg a 4sg");
outtextxy(10,305,"Inervalo [b] de:4sg a 6sg");
outtextxy(10,315,"Inervalo [c] de:6sg a 8sg");
outtextxy(10,325,"Inervalo [d] de:8sg a 10sg");
outtextxy(10,335,"Inervalo [e] de:10sg a 12sg");
outtextxy(10,345,"Inervalo [f] de:12sg a 14sg");
outtextxy(10,355,"Inervalo [g] de:14sg a 16sg");
gotoxy(23,18);cin>>intervalo;
if(intervalo=='a')
{
ec1=2-0/2;
gotoxy(25,18);printf("=%fm/sý",ec1);
}
if(intervalo=='b')
{
ec2=5-2/2;gotoxy(25,18);printf("=%fm/sý",ec2);
}
if(intervalo=='c')
{
ec3=10-5/2;gotoxy(25,18);printf("=%fm/sý",ec3);
}
if(intervalo=='d')
{
ec4=15-10/2;gotoxy(25,18);printf("=%fm/sý",ec4);
}
if(intervalo=='e')
{
ec5=20-15/2;gotoxy(25,18);printf("=%fm/sý",ec5);
}
if(intervalo=='f')
{
ec6=22-20/2;gotoxy(25,18);printf("=%fm/sý",ec6);
}
if(intervalo=='g')
{
ec7=22-22/2;gotoxy(25,18);printf("=%fm/sý",ec7);
}
outtextxy(10,373,"__________________________________");
outtextxy(10,372,"Desea ingresar otras medidas?[s/n]");
gotoxy(37,24);
cin>>res;
if(res=='s')
{
outtextxy(9,389,"T:");
gotoxy(4,25);
cin>>t;
outtextxy(63,389,"Vi:");
gotoxy(12,25);
cin>>v1;
outtextxy(112,389,"Vf:");
gotoxy(18,25);
cin>>v2;ac=v2-v1/t;
gotoxy(23,25);
printf("a=%fm/sý",ac);
}
if(res!='s')
outtextxy(9,410,"Escoja opcion del menu p/pal.");
}
/*******************************************************/
void ecuaciondesplaza()
{
int op;
float velocidad,tiempo,espacio;    double ec1,ec2,ec3,ec4,ec5,ec6,ec7;
char intervalo,a,b,c,d,e,f,g;

outtextxy(380,10,"Ecuacion de desplazamiento");
outtextxy(380,200,"Para demostracion utilice");
outtextxy(415,210,"valores de tabla");
/************************************************/
outtextxy(10,120,"tiempo");
outtextxy(10,135,"velocidad");
outtextxy(100,120,"0");outtextxy(100,135,"0");
outtextxy(120,120,"2");outtextxy(120,135,"0");
outtextxy(140,120,"4");outtextxy(140,135,"2");    //llamado de tabla de valores
outtextxy(160,120,"6");outtextxy(160,135,"5");
outtextxy(180,120,"8");outtextxy(180,135,"10");
outtextxy(200,120,"10");outtextxy(200,135,"15");
outtextxy(220,120,"12");outtextxy(220,135,"20");
outtextxy(240,120,"14");outtextxy(240,135,"22");
outtextxy(260,120,"16");outtextxy(260,135,"22");
outtextxy(70,150,"TABLA DE DEMOSTRACION");
/************************************************/
outtextxy(450,30,"X=VxT");
outtextxy(315,52,"Escoja velocidad :");gotoxy(59,4);scanf("%f",&velocidad);
outtextxy(315,69,"Escoja tiempo:"); gotoxy(55,5);scanf("%f",&tiempo);
outtextxy(315,101,"Espacio recorrido es:");
espacio=velocidad*tiempo;gotoxy(63,7);printf("%fmetros",espacio);
outtextxy(315,120,"Escoja opcion del menu p/pal.");
}