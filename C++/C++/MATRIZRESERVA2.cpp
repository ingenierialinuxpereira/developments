#include <iostream.h>
#include <conio.h>
#include <alloc.h>
int **reserva(int fil, int col);

int main()
{
int **matr;
int t,cont,cut,diad,diai,p,p1;
int aux,i,fil,col,f,c,x,y;
clrscr();
diad=0;diai=0;
cout<<"numero de posiciones: ";
cin>>fil;
clrscr();
cprintf("su matriz quedara de %d  x  %d ",fil,fil);
fil+=1;col=fil;
matr=reserva(fil,col);
if(matr==NULL)
{
cout<<"no se pueden guardar datos";
return 1;
}
for (f=0; f<=fil; f++)
{
  for (c=0; c<=col; c++)
  {
  matr[f][c]=0;
  }
}
y=8;
p=0;
p1=col-2;
for (f=0; f<fil-1; f++)
{
  t=0;
  matr[fil][col]=0;
  x=8;
  for (c=0; c<col-1; c++)
  {
  gotoxy(8,5);cprintf("ingrese valor para posicion %d   %d",f,c);
  gotoxy(x,y);cin>>matr[f][c];
  matr[fil][col]=matr[fil][col]+matr[f][c];
  x+=6;
  matr[t][col]+=matr[f][c];
  t++;
    if(matr[f][c]==matr[p][p1])
    {
    diai+=matr[f][c];
    p+=1;
    p1-=1;
    }
     if(f==c)
     diad+=matr[f][c];
  }
  gotoxy(x,y);cprintf("pr %d ",matr[fil][col]/(fil-1));
  matr[f][col]+=matr[f][c];
  y+=2;
}
x=5;
gotoxy(16,22);cprintf("promedio diagonal derecha %d ",diad/(fil-1));
gotoxy(16,23);cprintf("promedio diagonal izquierda %d ",diai/(fil-1));
for (f=0; f<fil-1; f++)
{
  gotoxy(x,y);cprintf("pr %d",matr[f][col]/(fil-1));
  x+=6;
}
cut=0;
cont=0;
for(f=0;f<fil-1;f++)
{
 for(t=f;t<fil-1;t++)
  {
   for(c=0;c<col-1;c++)
    {
     if(matr[f][c]==matr[t][c])
      {
       cont=cont+1;
	if (cont>=cut)
	{
	cut=cont;
	aux=matr[t][c];
	}
      }
    }
  }
cont=0;
}
gotoxy(16,24);
cprintf("el numero que mas se repite es %d",aux);
getch();
return 1;
}


int **reserva(int filas, int columnas)
{
int **matr;
int i;
matr=(int **)malloc(sizeof(int)*filas);
if(matr==NULL)
  cout<<"memoria insuficiente";
 else
  for (i=0; i<=filas; i++)
    {
    matr[i]=(int *) malloc (sizeof(int)*columnas);
    if (matr[i]==NULL)
      {
      cout<<"memoria insuficiente";
      return NULL;
      }
    }
      return matr;
}



