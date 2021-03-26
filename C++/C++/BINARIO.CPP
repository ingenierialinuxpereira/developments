#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<iostream.h>
typedef struct lista
{
int info;
struct lista *sig;
}*aplista;
aplista crearlista();
aplista adicionarnodo(aplista cab, int dato);
aplista adicionar();
int imprimir(aplista c);
int main()
{
aplista cab;
cab=adicionar();
if(cab==NULL)
cout<<"No se guardaron datos";
else
imprimir(cab);
getch();
return 1;
}
aplista crearlista()
{
aplista aux;
aux=(aplista)malloc(sizeof(lista));
return aux;
}
aplista adicionarnodo(aplista cab, int dato)
{
aplista aux;
aux=(aplista)malloc(sizeof(lista));
if(aux==NULL)
return NULL;
aux->sig=NULL;
aux->info=dato;
if(cab->sig==NULL)
cab->sig=aux;
else
{
aux->sig=cab->sig;
cab->sig=aux;
}
return cab;
}
aplista adicionar()
{ int num,fco;
char res;
aplista cab;
cab=crearlista();
if(cab==NULL)
return NULL;
while(num>=2)
{
fco=num%2;
cab=adicionarnodo(cab,fco);
num=num/2;
}
cab=adicionarnodo(cab,num);
return cab;
}