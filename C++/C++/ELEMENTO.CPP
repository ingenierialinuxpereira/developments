#include<stdio.h>
#include<process.h>
#include<conio.h>
char a[100];
char b[100];
int captura(int x);
int imprimir(int x);

int main()
{
int i,tope,tope2;
clrscr();
printf("Ingrese tope maximo para el vector:");
scanf("%d",&tope);
captura(tope);
imprimir(tope);

getch();
return 1;
}

int captura(int x)
{
int i,j;
printf("\n\rFrase");
for(i=1;i<=x;i++)
{
printf("\n\rIngrese palabra y oprima enter:");
scanf("%s",&a[i]);
}
getch();
return 1;
}
int imprimir(int x)
{
int i,ban,cont;
char res;
ban=0;
for(i=1;i<=x;i++)
{
 if(a[i]==a[i]+1)
 ban=1;
 }
if(ban==1)
printf("Componente repetido");
else
printf("No repetido");
getch();
return 1;
}
