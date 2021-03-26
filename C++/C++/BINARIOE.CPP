#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<iostream.h>
typedef struct lista
{
int info;
struct lista *sig;
}* aplista;
 aplista crearlista();
 aplista adicionarn(aplista cab,int dato);
 aplista adicionar();
 int imprimir(aplista aux);
int main()
{ int dato;
aplista cab;
cab=adicionarn(cab, dato);
gotoxy(30,1);cout<<"Francisco Gutierrez";
if (cab==NULL)
cout<<"memoria insufuciente";
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
aplista adicionarn(aplista cab,int dato)
{ int info;
aplista aux;
aux=(aplista)malloc(sizeof(lista));
if(aux==NULL)
{
return NULL;
aux -> sig=NULL;
aux -> sig= aux->info;
aux->info=dato;
}
if(cab==NULL)
{
cab->sig=aux;
aux ->sig=cab->sig;
}
else
{
aux->sig=cab->sig;
cab->sig=aux;
}
return cab;
}
aplista adicionarn()
{
aplista cab;
int num,dato,div;
cab=crearlista();
if(cab==NULL)
return NULL;
cout<<"Ingrese un numero:";
cin>>num;
while(num>=2)
{
div=num%2; num=num/2;
cab=adicionarn(cab,div);
break;
}
return cab;
}
int imprimir(aplista aux)
{
aplista cab;
cab=aux;
while(cab!=NULL)
{
cout<<"El binario correspondiente al numero ingresado es:"<<cab;
cab=cab->sig;
}
return 1;
}