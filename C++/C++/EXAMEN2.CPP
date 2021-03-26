#include"conio.h"
#include"stdio.h"
void captura(int x,int y);
void modificar(int k,int z);
void listar(int x,int y);
char mat[100][100];
void main()
{
int x,y,k,z,opc,s;
textbackground(BLUE);
opc=0;
clrscr();
while(opc!=4)
{
textcolor(YELLOW);
cprintf("\n\r                   FRANCISCO GUTIERREZ/MARCELA TOBON");
textcolor(128);
cprintf("\n\r                   ---------------------------------");
textcolor(WHITE);
cprintf("\n\r                          1-Captura de matriz");
cprintf("\n\r                          2-Modificar posicion");
cprintf("\n\r                          3-Listar nueva matriz");
cprintf("\n\r                          4-Salir");
cprintf("\n\r                          ¨Cu l es su opcion?");
scanf("%d",&opc);

switch(opc)

{
case 1:cprintf("\n\n\n\r¨Cuantas filas?");
cprintf("\n\n\r*Debe tener un limite de 100 datos*:");
scanf("%d",&x);
cprintf("\n\n\r¨Cuantas columnas?");
cprintf("\n\n\r*Debe tener un limite de 100 datos*:");
scanf("%d",&y);
captura(x,y);
break;
case 2:cprintf("\n\r                           Fila a modificar:");
scanf("%d",&k);
cprintf("\n\r                           Columna a modificar:");
scanf("%d",&z);
modificar(k,z);
break;
case 3:listar(x,y);
break;
case 4:cprintf("\n\n\n\n\n\r              SALIENDO...OPRIMA LA TECLA ALT Y CUALQUIER LETRA");
break;
default:cprintf("\n\r          No sea bruto mire las opciones oprima enter y reintente!");
break;
}
getch();
clrscr();
}
getch();
}
void captura(int x,int y)
{
clrscr();
int f,c;
f=c=1;

for(f=1;f<=x;f++)
{
  for(c=1;c<=y;c++)
{
textcolor(YELLOW);
cprintf("\n\r                Digite hasta [%d],datos y luego oprima enter:",x*y);
mat[f][c]=getch();
putchar(mat[f][c]);
}
}
getch();
cprintf("\n\rOprima cualquier tecla y luego enter");
}
void modificar(int k,int z)
{
int f,c;
clrscr();
cprintf("\n\rIngrese dato para la posicion[%d][%d] y oprima enter:",k,z);
{
mat[k][z]=getch();
putchar(mat[k][z]);
}
getch();
cprintf("\n\rOprima cualquier tecla y luego enter");
}
void listar(int x,int y)
{
int f,c;
f=c=1;
clrscr();
cprintf("\n\n\n\rNueva matriz:");
for(f=1;f<=x;f++)
   {
   for(c=1;c<=y;c++)
{
cprintf("%c",mat[f][c]);
}

}
cprintf("\n\rOprima cualquier tecla y luego enter");
getch();
}