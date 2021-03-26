#include<stdio.h>
#include<process.h>
#include<conio.h>
char a[100];
char b[100];
int captura(int x,int y);
int imprimir(int x,int y);

int main()
{
int i,tope,tope2;
clrscr();
printf("Ingrese tope maximo para el vector:");
scanf("%d",&tope);
printf("Ingrese tope maximo para palabra:");
scanf("%d",&tope2);
captura(tope,tope2);
imprimir(tope,tope2);

getch();
return 1;
}

int captura(int x,int y)
{
int i,j;
printf("\n\rFrase");
for(i=0;i<=x;i++)
{
printf("\n\rIngrese letra %d  de frase y oprima enter:",i);
scanf("%s",&a[i]);
}
printf("-----------------------------------------------");
for(j=0;j<=y;j++)
{
printf("\n\rIngrese letra %d de palabra y oprima enter:",j);
scanf("%s",&b[j]);
}
getch();
return 1;
}
int imprimir(int x,int y)
{
int i,j=1,ban=0,cont;
char res;
for(i=0;i<=x;i++)
{
 for(j=0;j<=y;j++)
 {
 if(a[i]==b[j])
 ban=1;
 j++;
 }
 i++;
}
if(ban==1)
printf("Componente repetido %s",a[i]);
else
printf("Componente no repetido");
printf("\n\rIngresar de nuevo? s/n");
scanf("%s",&res);
if(res=='s'||res=='S')
main();
else
exit(1);
getch();
return 1;
}
