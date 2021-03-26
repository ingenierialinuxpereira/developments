#include<conio.h>
#include<stdlib.h>
#include<iostream.h>
#include<alloc.h>
#include<stdio.h>

typedef struct Lista
{
 int info;
 struct Lista *sig,*ant;
}*Aplista;

typedef struct Ventana
{
 Aplista Primero;
 Aplista Actual;
 Aplista Ultimo;
 int Contador;
}*Apventana;

Apventana  G_vent=NULL;

/*la funcion de adicion de nodos en orden*/

Aplista AdicionarOrden (Aplista cab, int num)
{
 Aplista aux, nodo,otro;

 nodo=(Aplista)malloc(sizeof(Lista));
 if(nodo==NULL)
  return NULL;

 nodo->sig=nodo->ant=NULL;
 nodo->info=num;

 if(cab==NULL)
 {
  cab=G_vent->Primero=G_vent->Actual=G_vent->Ultimo=nodo;
 }
 else
  {
   if(cab->info>=num)
   {
    G_vent->Primero=G_vent->Actual=nodo;
    nodo->sig=cab;
    cab->ant=nodo;
    cab=nodo;
   }
   else
   {
    if(G_vent->Ultimo->info<=num)
    {
     aux=G_vent->Ultimo;
     aux->sig=nodo;
     nodo->ant=aux;
     G_vent->Ultimo=G_vent->Actual=nodo;
    }
    else
    {
     aux=cab;
     while(aux->sig!=G_vent->Ultimo && aux->sig->info<=num)
      aux=aux->sig;

     G_vent->Actual=nodo;
     nodo->sig=aux->sig;
     nodo->ant=aux;
     aux->sig=nodo;
     nodo->sig->ant=nodo;
    }
  }
}
  G_vent->Contador++;
  return cab;
}

/*Aplista AdicionarOrden (Aplista cab, int num)
{
 Aplista aux,nodo,otro;

 nodo=(Aplista)malloc(sizeof(Lista));
 if(nodo==NULL)
  return NULL;
 nodo->sig=nodo->ant=NULL;
 nodo->info=num;

 if(cab==NULL)
 {
  cab=nodo;
  G_vent->Primero=G_vent->Actual=G_vent->Ultimo=cab;
 }
 else
 {
  if(cab->info>=num)
  {
   G_vent->Primero=G_vent->Actual=nodo;
   nodo->sig=cab;
   cab->ant=nodo;
   cab=nodo;
  }
  else
  {
   aux=cab;
   while(aux->sig!=NULL && aux->sig->info<=num)
    aux=aux->sig;
   G_vent->Actual=nodo;
   nodo->sig=aux->sig;
   nodo->ant=aux;
   aux->sig=nodo;

   if(nodo->sig==NULL)
     G_vent->Ultimo=nodo;
  }
 }
 G_vent->Contador++;
return cab;
} */




/*funcion para la llenada general de la lista*/
Aplista llenarLista()
{
 Aplista c;
 int dat,col=33;
 char res;
 clrscr();

 while(1)
 {
  gotoxy(6,10);
  cout<<"                                    ";
  gotoxy(6,8);
  cout<<"Digite un N£mero entero";
  gotoxy(col,8);
  cin>>dat;
  c=AdicionarOrden(c,dat);
  gotoxy(6,10);
  cout<<"M s datos a la lista??... S/N..:   ";
  res=getche();
  if(res=='N'||res=='n')
   break;
   col+=4;
 }
 //getch();
 return c;
}

/*funcion que muestra la lista de izquieerda a derecha*/
int MostrarDerecho (Aplista cab)
{
 Aplista aux=cab;
 int col=20;
 clrscr();
 while(aux!=NULL)
 {
  gotoxy(col,8);
  cout<<aux->info;
  aux=aux->sig;
  col+=4;
 }
 getch();
 return 1;
}



int MostrarInversa (/*Aplista cab*/)
{
 Aplista aux=G_vent->Ultimo;
 int col=20;
 clrscr();
 while(aux!=NULL)
 {
  gotoxy(col,8);
  cout<<aux->info;
  aux=aux->ant;
  col+=4;
 }
 return 1;
}
/*funcion que muestra los datos almacenados en la ventana*/
int MostrarVentana ()
{
 clrscr();
 gotoxy(6,8);
 cout<<"Primer Dato de la Lista :   "<<G_vent->Primero->info;
 gotoxy(6,9);
 cout<<"Ultimo Dato de la Lista :   "<<G_vent->Ultimo->info;
 gotoxy(6,10);
 cout<<"Ultimo Dato en registrar la Lista :   "<<G_vent->Actual->info;
 gotoxy(6,11);
 cout<<"Total cantidad de datos de la Lista :   "<<G_vent->Contador;
 getch();
 return 1;
}


/*funcion queelimina el nodo y la informacion del nodo como tal*/
Aplista EliminarDato(Aplista cab,int dato)
{
 Aplista aux=cab,otro,elim;

 if(cab->info==dato)
 {
  if(cab->sig==NULL)
  {
   otro=cab;
   free(otro);
   cab=NULL;
   G_vent->Primero=G_vent->Actual=G_vent->Ultimo=NULL;
   G_vent->Contador=0;
   return cab;
  }
  else
  {
   elim=cab;
   cab=cab->sig;
   G_vent->Primero=cab;
   if(elim==G_vent->Actual)
    G_vent->Actual=cab;
   free(elim);
   G_vent->Contador--;
  }
 }
 else
 {
  if(G_vent->Ultimo->info==dato)
  {
   elim=G_vent->Ultimo;
   otro=elim->ant;
   G_vent->Ultimo=otro;
   otro->sig=NULL;
   G_vent->Contador--;
   free(elim);
  }
  else
  {
   aux=cab;
   while(aux!=G_vent->Ultimo && aux->info!=dato)
    aux=aux->sig;

   otro=aux->ant;
   elim=aux->sig;
   otro->sig=elim;
   elim->ant=otro;
   G_vent->Contador--;
   if(aux==G_vent->Actual)
    G_vent->Actual=otro;
   free(aux);
  }
 }
return cab;
}


Aplista Eliminar (Aplista cab)
{
 Aplista aux;
 int d;
 clrscr();
 gotoxy(6,5);
 cout<<"ELIMINAR DATOS";
 gotoxy(6,8);
 cout<<"Digite el dato que desea Eliminar de la lista:   ";
 cin>>d;
 while(aux!=NULL)
 {
  if(aux->info==d)
    break;
   aux=aux->sig;
 }
 if(aux==NULL)
 {
  cout<<"No se encontro el dato :"  <<d;

 }
 else
 {
  cab=EliminarDato(cab,d);
  cout<<"Dato Eliminado...";
 }
 getch();
 return cab;
}


int menu()
{
 int op;
 clrscr();
 gotoxy(20,6);
 cout<<"MENU PRINCIPAL";
 gotoxy(8,8);
 cout<<"1. Agregar/llenar lista";
 gotoxy(8,9);
 cout<<"2. Mostrar al derecho" ;
 gotoxy(8,10);
 cout<<"3. Mostrar al contrario" ;
 gotoxy(8,11);
 cout<<"4. Mostrar Ventana";
 gotoxy(8,12);
 cout<<"5. Eliminar Dato ";
 gotoxy(8,13);
 cout<<"6. Salir";
 gotoxy(15,14);
 cout<<"Digite Opci¢n:  ";
 cin>>op;
// getch();
 return op;
}

int salir(Aplista cab)
{
 Aplista aux=cab;
 clrscr();

 gotoxy(8,6);
 cout<<"Gracias por usarme... Adios pues!!..";
 gotoxy(8,7);
 cout<<"Se liberar  la memoria usada anteriormente!!..";

 while(cab!=NULL)
 {
  aux=cab;
  free(aux);
  cab=cab->sig;
 }
 //getch();
 return 1;
}

Aplista crear()
{
 return NULL;
}


int main()
{
 int op;
 Aplista cab;
 clrscr();
 G_vent->Contador=0;
 G_vent->Ultimo=NULL;
 cab=crear();
 do
 {
  op=menu();
  switch(op)
  {
   case 1: cab=llenarLista();break;
   case 2: if (cab==NULL)
	   {
	    gotoxy(20,15);
	    cout<<"Lista vacia..";
	   }
	   else
	    MostrarDerecho(cab);
	   break;
   case 3: if (cab==NULL)
	   {
	    gotoxy(20,15);
	    cout<<"Lista vacia..";
	   }
	   else
	    MostrarInversa(/*cab*/);
	   break;
   case 4: if (G_vent->Primero==NULL)
	   {
	    gotoxy(20,15);
	    cout<<"Ventana vacia..";
	   }
	   else
	    MostrarVentana();
	   break;
   case 5: if (cab==NULL)
	   {
	    gotoxy(20,15);
	    cout<<"Lista vacia..";
	   }
	   else
	    cab=Eliminar(cab);
	   break;
   case 6: salir(cab); break;
   default:gotoxy(20,15);
	    cout<<"Dato Incorrecto.."; break;
  }
//  getch();
  }while(op!=6);
 return 0;
}








