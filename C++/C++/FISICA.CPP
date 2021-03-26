#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//francisco
void centrado(int fila, char *texto)
{gotoxy(40-strlen(texto)/2,fila);
cout<<texto;}

void descripcion(int fila, char *text1, char *text2, char *text3)
{gotoxy(5,fila);
cout<<text1;
gotoxy(16,fila);
cout<<text2;
gotoxy(58,fila);
cout<<text3;}

void llenado()
{descripcion(9," 0","Gravedad en el Sol"," 274");
descripcion(10," 1","Gravedad en Mercurio"," 2.94");
descripcion(11," 2","Gravedad en Venus"," 8.63");
descripcion(12," 3","Gravedad en la Tierra"," 9.81");
descripcion(13," 4","Gravedad en Marte"," 3.82");
descripcion(14," 5","Gravedad en J£piter"," 25.99");
descripcion(15," 6","Gravedad en Urano"," 8.14");
descripcion(16," 7","Gravedad en Neptuno"," 11.37");
descripcion(17," 8","Gravedad en Saturno"," 10.39");
descripcion(18," 9","Gravedad en la Luna"," 1.62");
descripcion(19," -","<Entrada por el usuario>","        ");}

void estrellitas()
{int cde;
randomize();
for (cde=1; cde<=1000; cde++)
	putpixel(random(640),random(415),15);
}

void estrellas()
{int cde;
randomize();
for (cde=1; cde<=200; cde++)
	putpixel(random(160)+401,random(94)+301,15);
}

void pelota(int x, int ybase, int color)
{setcolor(color);
setfillstyle(1,color);
circle(x,ybase-10,10);
floodfill(x,ybase-10,color);
}

double real(char *texto)
{int i, s, z, sw, fila, posx;
double num;
char g[7], c;
posx=wherex();
fila=wherey();
gotoxy(posx,fila);
cout<<texto;
gotoxy(posx,fila);
i=posx;
s=0;
z=0;
sw=0;
while(s==0)
  {c=getch();
  switch(c)
	{case 0:
		getch();
		putchar(7);
		break;
	case 8:
		if (i==posx)
			putchar(7);
		else
			{if (g[i-posx+1]=='.')
				z=0;
			cout<<"    ";
			gotoxy(i-1,fila);
			putchar(32);
			i--;}
		break;
	case 13:
		if (i>posx+1)
			if (g[i-posx+1]=='.')
				i--;
		s=1;
		break;
	case 27:
		g[0]='0';
		i=posx+1;
		sw=1;
		s=1;
		break;
	default:
		if ((c>=48 && c<=57) || (c==44 || c==46))
		  if(i==posx+6)
			putchar(7);
		  else
			{if (c=='.' || c==',')
			  if (z==0 && i!=posx && i!=posx+5)
			    {g[i-posx]='.';
			    cout<<".";
			    i++;
			    z=1;}
			  else
			    putchar(7);
			else
			  {g[i-posx]=c;
			  cout<<c;
			  i++;}
			}
		break;
	}
  gotoxy(i,fila);
  cout<<texto;
  gotoxy(i,fila);
  }
g[i-posx]='\0';
if (sw==1)
	{gotoxy(posx,fila);
	for (i=posx; i<=posx+11; i++)
		putchar(32);
	return(-1);}
return(atof(g));
}

int entero(double num)
{char h[7];
char *b;
int i=0;
b=gcvt(num,6,h);
while (h[i]!='.')
	i++;
h[i]='\0';
if (h[i+1]>5)
	i=1;
else
	i=0;
return(atoi(h)+i);
}

void borlin(int min, int max, int fil)
{int i;
gotoxy(min,fil);
for (i=min; i<=max; i++)
	putchar(32);
}

void main()
{char opcion;
int i, sw=1, color, gdriver=9, gmode=2;
double gravedad, altura, vox, x, y, t, amx, tt, yy, xx;
clrscr();
centrado(4,"Programa para analizar un movimiento semiparab¢lico");
descripcion(7,"Opci¢n","Descripci¢n","Gravedad (m/sý)");
llenado();
_setcursortype(_NOCURSOR);
while (sw)
	{gotoxy(5,22);
	delline();
	cout<<"Su opci¢n: _";
	opcion=getch();
	gotoxy(16,22);
	putchar(32);
	sw=0;
	switch (opcion)
		{case 0:
			opcion=getch();
			sw=1;
			break;
		case '0':
			gravedad=274;
			color=14;
			break;
		case '1':
			gravedad=2.94;
			color=8;
			break;
		case '2':
			gravedad=8.63;
			color=9;
			break;
		case '3':
			gravedad=9.81;
			color=6;
			break;
		case '4':
			gravedad=3.82;
			color=4;
			break;
		case '5':
			gravedad=25.99;
			color=12;
			break;
		case '6':
			gravedad=8.14;
			color=14;
			break;
		case '7':
			gravedad=11.37;
			color=1;
			break;
		case '8':
			gravedad=10.39;
			color=12;
			break;
		case '9':
			gravedad=1.62;
			color=7;
			break;
		case '-':
			gotoxy(59,19);
			gravedad=real("_");
			color=15;
			break;
		default:
			sw=1;
			break;
		}
	}
initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
cleardevice();
centrado(4,"INGRESO DE DATOS DEL MOVIMIENTO");
gotoxy(4,8);
cout<<"Entre altura de lanzamiento:   ";
altura=real(" m");
gotoxy(4,10);
cout<<"Entre velocidad inicial en x:   ";
vox=real(" m/s");
gotoxy(50,12);
cout<<"M ximo 1 s";
gotoxy(4,12);
cout<<"Entre exactitud de trazo:   ";
t=real(" s");
setcolor(10);
rectangle(400,300,560,420);
estrellas();
circle(411,320,4);
setfillstyle(1,10);
floodfill(411,320,10);
setcolor(color);
for (i=395; i<=419; i++)
	line(401,i,559,i);
setcolor(9);
rectangle(410,325,411,394);
line(410,325,410,394);
setcolor(6);
arc(394,304,90,180,4);
arc(394,390,180,270,4);
arc(386,343,270,360,4);
arc(386,351,0,90,4);
line(390,304,390,343);
line(390,351,390,390);
arc(416,426,180,270,4);
arc(556,426,270,360,4);
arc(482,434,0,90,4);
arc(490,434,90,180,4);
line(416,430,482,430);
line(490,430,556,430);
settextstyle(3,0,1);
outtextxy(373,330,"y");
outtextxy(483,430,"x");
gotoxy(50,14);
cout<<"Mayor que "<<altura<<" m";
gotoxy(4,14);
cout<<"Entre distancia y:   ";
y=real(" m");
amx=sqrt(2*altura/gravedad)*vox;
x=-1;
while (x<amx)
	{gotoxy(50,16);
	cout<<"Mayor que "<<amx<<" m";
	borlin(4,35,16);
	gotoxy(4,16);
	cout<<"Entre distancia x:   ";
	x=real(" m");}
cleardevice();
setcolor(color);
for (i=415; i<=479; i++) //Piso del planeta
	line(0,i,639,i);
estrellitas();
setcolor(9);
for (i=415-entero(altura); i<=414; i++) //Poste
	line(37,i,43,i);
setcolor(1);
rectangle(37,416-entero(altura),38,414);
setcolor(11);
line(42,416-entero(altura),42,414); //Hasta aqu¡ el poste
xx=0;
yy=altura;
tt=0;
while (yy<415 && !kbhit())
	{pelota(entero(xx)+40,415-entero(altura)+entero(yy),2); ///////////*/*/*/*/*/*/*/*/*/
	yy=gravedad/2*tt*tt;
	xx=vox*tt;
	tt+=t;
	pelota(entero(xx)+40,415-entero(altura)+entero(yy),10);
	delay(entero(t*1000));
	}
getch();
closegraph();
}