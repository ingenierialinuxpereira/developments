#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <iostream.h>
#include <string.h>
typedef struct notas
{
char cedula[20];
float n1;
float n2;
float n3;
} ;
typedef struct lista
{
notas info;
struct lista *sig, *ant;
} *aplista;
int adicionar();
notas buscar(aplista cabeza);
aplista crearlista();
aplista adicionarinicio(aplista cabeza,notas reg);
notas captura(aplista cabeza);
int comparar(notas reg,notas regf);
aplista adicionarfin(aplista cabeza,notas reg);
aplista eliminar(aplista cabeza,notas reg);
int imprimir(notas reg);
aplista adicionarordenado(aplista cabeza,notas reg);
aplista opciones(aplista cabeza);
int compararsub(notas reg,notas cedu);
int opcionsub(aplista cabeza);
int fco,pacho,gut;
int main()
{
adicionar();
return 1;
}
int adicionar()
{
aplista cabeza;
cabeza = crearlista();
cabeza= opciones(cabeza);
fco=pacho=gut=0;
return 1;
}
aplista crearlista()
{
return NULL;
}
int opcionsub(aplista cab)
{
notas reg,re;
aplista cabeza;
cabeza=cab;
int op;
op=0;
while (op!=5)
{
clrscr();
gotoxy(30,1);cout<<"---Francisco Gutierrez--Juan Alejandro Hernandez---";
cout<<"\n\r1. Adicionar";
cout<<"\n\r2. Buscar";
cout<<"\n\r3. Eliminar";
cout<<"\n\r4. Imprimir";
cout<<"\n\r5. Salir";
cout<<"\n\rElija una opcion: ";
cin>>op;
switch (op)
{
case 1:reg=captura(cabeza);
       if (gut!=2)
       {
       switch (fco)
       {
 case 1:cabeza=adicionarinicio(cabeza,reg);break;
case 2:cabeza=adicionarfin(cabeza,reg);break;
case 3:cabeza=adicionarordenado(cabeza,reg);break;
       }
      }
      else
      {
      cout<<"Existente";
      getch();
      }
break;
case 2:re = buscar(cabeza);
       if (pacho==1)
       imprimir(re);
       else
       cout<<"No existente";
       getch();
       break;
case 3:cabeza=eliminar(cabeza,re);
       break;
case 4:while(cabeza!=NULL)
       {
       imprimir(cabeza->info);
       cabeza=cabeza->sig;
       getch();
       }
       break;
case 5:clrscr();
       cout<<"Ha decidido abandonar la ejecucion";
       cout<<"Saliendo...";
       cout<<"Oprima enter para salir";
       getch();
       break;
}
}
return 1;
}

aplista opciones(aplista cabeza)
{
notas reg;
int num,per,op;
char res;
clrscr();
op=0;
per=0;
while (op!=4)
{
clrscr();
gotoxy(30,1);cout<<"Submenu de la opcion Adicionar";
cout <<"\n\r1. Adicionar en el inicio:";
cout <<"\n\r2. Adicionar al final:";
cout <<"\n\r3. Adicionar de forma ordenada:";
cout <<"\n\rElija una opcion: ";
cin>>op;
switch (op)
{
case 1:while (1)
      {
      clrscr();
      cout <<"Desea adicionar nodo [s/n]:";
      res=getche();
      getch();
      if(res=='n'|| res=='N')
      break;
      reg=captura(cabeza);
      fco=1;
      per=1;
      if (gut!=2)
      cabeza=adicionarinicio(cabeza,reg);
      else
      {
      cout<<"Existente";
      getch();
      }
      }
      opcionsub(cabeza);
      break;

case 2:while (1)
      {
      clrscr();
      cout <<"Desea adicionar nodo [s/n] :";
      res=getche();
      if(res=='n' || res=='N')
      break;
      reg=captura(cabeza);
      fco=2;
      per=1;
      if (gut!=2)
      cabeza=adicionarfin(cabeza,reg);
      else
      {
      cout<<"Existente";
      getch();
      }
      }
      opcionsub(cabeza);
      break;
case 3:while (1)
      {
      clrscr();
      cout <<"Desea adicionar nodo [s/n]:";
      res=getche();
      getch();
      if(res=='n' ||  res=='N')
      break;
      reg=captura(cabeza);
      fco=3;
      per=1;
      if (gut != 2)
      cabeza=adicionarordenado(cabeza,reg);
      else
      {
      cout<<"Existente";
      getch();
      }
      }
      opcionsub(cabeza);
      break;
 }
      if (per == 1)
      break;
 }
      return cabeza;
      }
notas captura(aplista cab)
{
notas reg;
gotoxy(30,2);cout<<"--Ingreso de notas--";
cout<<"Cedula:";
cin>>reg.cedula;
cout<<"Primer nota:";
cin>>reg.n1;
cout<<"Segunda nota:";
cin>>reg.n2;
cout<<"Tercer nota:";
cin>>reg.n3;
while (cab!=NULL)
{
compararsub(cab->info,reg);
cab=cab->sig;
}
return reg;
}
aplista adicionarinicio(aplista cab,notas num)
{
aplista nodo;
nodo=(aplista)malloc(sizeof (lista));
nodo->sig=nodo->ant=NULL;
nodo->info=num;
if(cab==NULL)
cab=nodo;
else
{
cab->ant=nodo;
nodo->sig=cab;
cab=nodo;
}
return cab;
}
int comparar(notas reg,notas regf)
{
if(strcmp(reg.cedula,regf.cedula) >0)
return 1;
else
return 2;
}
aplista adicionarordenado(aplista cab,notas reg)
{  int n,p;
aplista nodo,aux;
aplista per;
notas regi;
nodo=(aplista)malloc(sizeof (lista));
nodo->sig=nodo->ant=NULL;
nodo->info=reg;
if(cab==NULL)
aux=nodo;
else
{
aux=cab;
while(aux!=NULL)
{
p=0;
n=comparar(aux->info,reg);
if (n==1)
{
if (aux->ant==NULL)
{
nodo->sig=aux;
aux->ant=nodo;
p=2;
break;
}
else
{
  per=aux->sig;
 aux->sig=nodo;
   aux->sig=per;
   aux->ant=nodo;
aux=aux->ant;
  p=2;
break;
}
}
 else
 aux=aux->sig;
if (p!=2)
{
nodo->ant=aux;
aux->sig=nodo;
break;
}
}
}
return aux;
}
int comparar(notas reg,notas regf)
{
if (reg.cedula>regf.cedula)
{
return 1;
}
else
return 2;
}
notas buscar(aplista cabeza)
{
aplista cab,aux;
notas ind,reg,num;
char numero[15];
aux->sig->ant=NULL;
cab=cabeza;
cout<<"ingrese numero de cedula";
cin>>num.cedula;
while (cab!=NULL)
{
pacho=compararsub(cab->info,num);
if(pacho==1)
{
return cab->info;
}
else
cab=cab->sig;
}
return aux->info;
}
int compararsub(notas reg,notas regf)
{
int n;
if(strcmp(regf.cedula, reg.cedula) == 0)
{
n=1;gut=2;
return n;
}
else
return 2;
}
int imprimir(notas reg)
{
clrscr();
cout<<"Cedula:"<<reg.cedula;
cout<<"Nota 1:"<<reg.n1;
cout<<"Nota 2:"<<reg.n2;
cout<<"Nota 3:"<<reg.n3;
return 1;
}
aplista eliminar(aplista cabeza,notas reg)
{
int ban=0;
aplista cab,aux,q;
notas ind,num;
cab->sig->ant=NULL;
aux=cabeza;
cout<<"Numero de identificacion";
cin>>num.cedula;
if (cab==NULL)
{
cout<<"Lista sin contenido";
return NULL;
}
while (aux!=NULL && ban==0)
{
pacho=compararsub(aux->info,num);
if(pacho==1)
{
q=aux;
ban=1;
}
else
aux=aux->sig;
if (ban==1)
{
  if (q->ant==NULL)
  {
  cabeza=cabeza->sig;
  cabeza->ant=NULL;
  }
  else
  {
   if (q->sig!=NULL)
   {
   aux->ant->sig=aux->sig;
   aux->sig->ant=aux->ant;
   }
   else
   aux->ant->sig=NULL;
  }
}
else
cout<<"No existente";
}
free(q);
return cabeza;
}
aplista adicionarfin(aplista cab,notas num)
{
aplista nodo,aux;
nodo=(aplista)malloc(sizeof (lista));
nodo->sig=nodo->ant=NULL;
nodo->info=num;
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

