#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<iostream.h>
typedef struct notas
{
char cedula;
float n1,n2,n3;
};
typedef struct lista
{
notas info;
struct lista *sig *ant;
}*aplista;
int op;
aplista adicionarfin(aplista cab,float dato);
aplista eliminarnodo(aplista aux,float dato);
aplista buscarlista(aplista cab,float dato);
int imprimir(aplista aux);
notas leernotas(aplista cab);

int main()
{
aplista cab;
op=1;
cab=adicionarfin();
if(cab==NULL)
cout<<"Decidio no ingresar datos:";
else
imprimir(cab);
return 1;
}
aplista crearlista()
{
return NULL;
}
aplista adicionarfin()
{
char res1,res,res2;
aplista cabeza,aux;
notas fco;
cabeza=crearlista();
while(1)
{
cout<<"Desea ingresar alguna nota? [s/n]";
cin>>res;
if(res=='N'|| res=='n')
break;
else
cabeza=adicionarfin(cabeza,float fco);
cout<<"Desea eliminar algun registro?[s/n]";
cin>>res1;
if(res=='s'||res=='S')
eliminarnodo(aplista aux,float dato);
else
break;
cout<<"desea buscar algun dato?[s/n]";
cin>>res2;
if(res2=='s'||res2=='S')
buscarlista(aplista aux,float dato);
else
break;
}
return cabeza;
}
aplista adicionarfin(aplista cab, float dato)
{
aplista nodo,aux;
nodo=(aplista)malloc(sizeof(lista));
if(nodo==NULL)
return NULL;
nodo->sig=nodo->ant=NULL;
nodo->info=dato;
if(cab==NULL)
cab=nodo;
else
{
aux=cab;
while(aux->sig!=NULL)
aux=aux->sig;
nodo->ant=aux;
aux->sig=nodo;
}
return cab;
}
notas leernotas(aplista cab)
{
notas dato1;
cout<<"Nota 1:";
cin>>dato1.n1;
cout<<"Nota 2:";
cin>>dato1.n2;
cout<<"Nota 3:";
cin>>dato1.n3;
cout<<"Cedula:";
cin>>dato1.cedula;
return dato1.n1,dato1.n2,dato1.n3;
}
aplista buscarlista(aplista cab,float dato)
{
int ban=0;
aplista aux=0;
while(ban=0;&&aux!=NULL)
if(aux->info==dato1)
return 1;
else
aux=aux->sig;
return =0;
}
int imprimir(aplista aux)
{
aplista cab;
cab=aux;
while(cab!=NULL)
{
cout<<"las notas son:"<<dato1.n1,dato1.n2,dat3.n3<<endl;
cab=cab->ant->sig;
}
return 1;
}
aplista eliminarnodo(aplista aux,float dato)
{
aplista q,aux;
int ban=0;
if(cab==NULL)
{
cout<<"lista vacia";
return NULL;
}
aux=cab;
while(aux!=NULL && ban=0)
if(aux->dato=dato1)
{
q=aux;
ban=1;
}
else
aux=aux->sig;
if(ban==1)
{
if(q->ant==NULL)
{
cab=cab->sig;
cab->ant=NULL;
}
else
if(q->sig!=NULL)
{
aux->ant->sig=aux->sig;
aux->sig->ant=aux->ant;
}else
aux->ant->sig=NULL;
}
free (q);
}
else
cout<<"no existe en lista";
return cab;
}