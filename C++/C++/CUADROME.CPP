# include <conio.h>
# include <stdio.h>

void cuadro (int x1,int y1,int x2,int y2, int color);//recibe parametros del usuario
void coloreo(int x1,int y1,int x2,int y2,int color, int tipo);

int main() //inicio del programa
{
int xa,ya,xf,yf,color1;//declaracion de variables(parametros)que van a interferir en dibujo del cuadro
clrscr();//limpio pantalla

printf("Ingrese coordenada de inicio de dibujo en x (fila) menor a 24:");
scanf("%d",&xa);//coordenada de inicio de dibujo del cuadro en fila inicial

printf("Ingrese coordenada de inicio de dibujo en y (columna) menor a 80:");
scanf("%d",&ya);//coordenada de inicio de dibujo del cuadro en columna inicial

printf("Ingrese coordenada de fin de dibujo en x (fila final) menor a 24:");
scanf("%d",&xf);//coordenada de fin de dibujo del cuadro en fila final

printf("Ingrese coordenada de fin de dibujo en y (columna final) menor 80:");
scanf("%d",&yf);//coordenada de fin de dibujo del cuadro en columna final

printf("Ingrese color de dibujo,valor entre 1 y 15:");
scanf("%d",&color1);//lectura del color a escoger por el usuario

cuadro(xa,ya,xf,yf,color1);//llamado de la funcion cuadro con los parametros leidos anteriormente el cual los recibe
coloreo(xa+1,ya+1,xf-1,yf-1,color1,219);//colorea el cuadro sin violar las lineas del mismo recibiendo el coordenadas del cuadro,color y simbolo ASCCII 219.

getch();

return 0;
}

void cuadro (int x1,int y1,int x2,int y2, int color)
{
int xi,g;

textcolor(color);//color a recibir en el cuadro

for (xi=y1; xi<=y2; xi++) //ciclo que regula el dibujo de linea horizontal parte superior e inferior del cuadro
{
gotoxy (xi,x1);
cprintf("%c",196);//linea superior del cuadro
gotoxy (xi,x2);
cprintf("%c",196);//linea inferior del cuadro
}

for (xi=x1; xi<=x2; xi++) //ciclo que regula el dibujo de linea vertical parte izquierda y derecha del cuadro
{
gotoxy (y1,xi);
cprintf("%c",179);//dibujo linea izquierda del cuadro
gotoxy (y2,xi);
cprintf("%c",179);//dibujo linea derecha del cuadro
}

gotoxy(y1,x1);
cprintf("%c",218);//esquina izquierda superior
gotoxy(y2,x2);
cprintf("%c",217);//esquina derecha inferior
gotoxy(y2,x1);
cprintf("%c",191);//esquina derecha superior
gotoxy(y1,x2);
cprintf("%c",192);//esquina izquierda inferior
}

void coloreo(int x1,int y1,int x2,int y2,int color, int tipo)
{
int yi,xi;
for(xi=y1;xi<=y2;xi++)
 {
  for(yi=x1;yi<=x2;yi++)
    {
    gotoxy(xi,yi);
    textcolor(color);
    cprintf("%c",tipo);
    }
   }
}
