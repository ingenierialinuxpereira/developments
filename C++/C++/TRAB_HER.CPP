#include<conio.h>
#include<stdio.h>
#include<iostream.h>
#include<stdlib.h>
#include<alloc.h>

typedef struct lista
 {
  int dato;
  struct lista *sig,*ant;
  }*aplista;

  typedef struct ventana
  {
  aplista primero;
  aplista actual;
  aplista ultimo;
  long cont;
  }*apventana;

  apventana grefer;

  int menu();
  aplista crearlista();
  aplista llenarlista(aplista cab);
  aplista adicionarorden(aplista cab);
  aplista eliminar(aplista cab, int dato);
  int listarderecho(aplista cab);
  int listarreves();
  int informaventana();


 int main()
 {
   int dato,op=0;
   aplista aux,cab;
   clrscr();
   cab=crearlista();

/*   cab=(aplista)malloc(sizeof(lista));
   if (cab==NULL)
      cout<<"PROBLEMAS CON LA MEMORIA"<<endl;
      else
      cab->sig=cab->ant=NULL;*/

   while(op!=6)
   {
    op=menu();
    switch (op)
   {
    case 1: cab=llenarlista(cab);
	    break;
    case 2: if (cab==NULL)
	   {
	    cout<<"LISTA VACIA"; getch();
	   }
	    else
	    listarderecho(cab);
	    break;
    case 3: if(cab==NULL)
	   {
	    cout<<"LISTA VACIA"; getch();
	   }
	    else
	    listarreves();
	    break;
    case 4: if (grefer->primero==NULL)
	   {
	    cout<<"VENTANA VACIA";  getch();
	   }
	    else
	    informaventana();
	    break;

    case 5: if (cab==NULL)
	   {
	    cout<<"LISTA VACIA";  getch();
	   }
	    else

	    cab=eliminar(cab,dato);
	    break;

    case 6: while(cab!=NULL)
    {
	    aux=cab;
	    free(aux);
	    cab=cab->sig;

    }
	    cout<<"\t\t\t GRACIAS   PRESIONE ENTER PARA SALIR";
	     break;

    }
    }
	    getch();
	    return 0;
  }

  int menu()
  {
	int op;
	clrscr();
	cout<<"\t\t\t    MENU PRINCIPAL"<<endl<<endl;
	cout<<"\t\t\t 1..ADICIONAR NODO"<<endl;
	cout<<"\t\t\t 2..LISTAR AL DERECHO"<<endl;
	cout<<"\t\t\t 3..LISTAR AL REVES"<<endl;
	cout<<"\t\t\t 4..MOSTRAR INFORMACION DE LA VENTANA"<<endl;
	cout<<"\t\t\t 5..ELIMINAR NODO"<<endl;
	cout<<"\t\t\t 6..SALIR"<<endl;
	cout<<"\t\t\t  DIGITE SU OPCION:   ";
	cin>>op;
	return op;
  }

 aplista crearlista()
	{
	 grefer=(apventana)malloc(sizeof(ventana));
	 grefer->primero=grefer->ultimo=grefer->actual=NULL;
	 grefer->cont=0;
	 return NULL;
	}


  aplista llenarlista(aplista cab)
 {

   int d;
   clrscr();
 // {
   cout<<"DIGITE UN DATO";
   cin>>d;

   cab=adicionarorden(cab);
 // }
   getch()
   return d;
 }


  aplista adicionarorden(aplista cab, int num)
  {
     aplista aux,nodo;
     nodo=(aplista)malloc(sizeof(lista));
     if (nodo==NULL)
     return NULL;
     nodo->sig=nodo->ant=NULL;
     nodo->dato=num;

     if (cab==NULL)
      {
	cab=grefer->primero=grefer->actual=grefer->ultimo=nodo;
      }
	else
	if (cab->dato>=num)
      {
	  grefer->primero=grefer->actual=nodo;
	  nodo->sig=cab;
	  cab->ant=nodo;
	  cab=nodo;
       }
	  else
       {
	 aux=cab;
	 while(aux->sig!=NULL && aux->sig->dato<=num)
	   aux=aux->sig;
	 grefer->actual=nodo;
	 nodo->sig=aux->sig;
	 nodo->ant=aux;
	 aux->sig=nodo;

	 if (nodo->sig==NULL)
	 grefer->ultimo=nodo;
	   else
	   nodo->sig->ant=nodo;
	  }
	 // }
	  grefer->cont++;
	  return cab;
	 }

	 int listarderecho(aplista cab)
	 {
	 aplista aux=cab;
	 clrscr();
	  while(aux!=NULL)
		{
		 cout<<aux->dato;
		 aux=aux->sig;
		}
		getch();
		return 1;
	 }

	 int listarreves()
	 {
	 aplista aux=grefer->ultimo;
	 clrscr();
	  while(aux!=NULL)
		{
		 cout<<aux->dato;
		 aux=aux->ant;
		}
		 getch();
		 return 1;
	 }

    int informaventana()
    {
       clrscr();
       cout<<"EL PRIMER DATO DE LA LISTA ES:  "<<grefer->primero->dato;
       cout<<"EL ULTIMO DATO DE LA LISTA ES:  "<<grefer->ultimo->dato;
       cout<<"EL DATO ACTUAL DE LA LISTA ES:  "<<grefer->actual->dato;
       cout<<"CANTIDAD DE DATOS DE LA LISTA:  "<<grefer->cont;
       return 0;
     }

   aplista eliminar(aplista cab,int dato)
  {
	aplista x,aux=cab;
	int a;
	clrscr();

	while(aux->sig!=NULL)
	 {
	    if(aux->sig->dato==dato)
	  {
		x=aux->sig;
		aux->sig=aux->sig->sig;
	     if (aux->sig!=NULL)
		 aux->sig->ant=aux;
		 a++;
		 free(x);

	  }
		 else
		 aux=aux->sig;
			}
		aux=cab->sig;
		if(a==0)
		{
		  cout<<"NO SE ENCONTRO EL DATO:  "<<a;
		  return cab;
		 }
		 else
		 {
		 cout<<endl<<"\t\t\t EL DATO FUE ELIMINADO  " ;
		 grefer->primero=cab->sig;
		 while( aux->sig!=NULL)
				aux=aux->sig;
		 grefer->ultimo=aux;
		 grefer->actual=aux;
		 }
		 return cab;
		}


