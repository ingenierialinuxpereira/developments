#include<alloc.h>
#include<stdio.h>
#include<conio.h>
#include<iostream.h>

typedef struct lista
{
 int dato;
 struct lista * sig,* ant;
}*aplista;

typedef struct ventana
{
 aplista primero;
 aplista ultimo;
 aplista actual;
 long cont;
}*apventana;

int menu ();
aplista adicionar (aplista m);
aplista eliminar (aplista m,int n);
int listar (aplista m);
int informaventana ();
int reves ();
aplista crear ();

apventana grefer;

int main ()
{
 int n,op=0;
 aplista m,q;
 clrscr ();
 m=crear();
 while (op!=6)
       {
	op=menu();
	switch (op)
	       {
		case 1: m=adicionar(m);
			break;
		case 2: if (m->sig==NULL)
			    cout<<endl<<"\t\t\t\tLA LISTA SE ENCUENTRA VACIA";
			    else
			    listar(m->sig);
			break;
		case 3: if (m->sig==NULL)
			    cout<<endl<<"\t\t\t\tLA LISTA SE ENCUENTRA VACIA";
			    else
			    informaventana();
			break;
		case 4: if (m->sig==NULL)
			    cout<<endl<<"\t\t\t\tLA LISTA SE ENCUENTRA VACIA";
			    else
			    {
			    cout<<endl<<"\t\t\t\tDigite el numero a eliminar:  ";
			    cin>>n;
			    m=eliminar(m,n);
			    }
			break;
		case 5: if (m->sig==NULL)
			    cout<<endl<<"\t\t\t\tLA LISTA SE ENCUENTRA VACIA";
			    else
			    reves();
			break;
		case 6: while (m!=NULL)
			      {
			       q=m;
			       m=m->sig;
			       free(q);
			      }
			cout<<endl<<"\t\t\t\tGRACIAS POR SU TIEMPO";
			break;
		default: cout<<endl<<"\t\t\t\tOPCION NO VALIDA";
			 break;
	       }
	getch ();
       }
 return 0;
}


int menu ()
{
 int op;
 clrscr ();
 cout<<endl<<endl<<endl<<endl<<"\t\t\t\tMENU PRINCIPAL"<<endl<<endl<<endl;
 cout<<"\t\t\t\t1. Adicionar nodo"<<endl;
 cout<<"\t\t\t\t2. Listar nodos"<<endl;
 cout<<"\t\t\t\t3. Mostrar informacion de la ventana"<<endl;
 cout<<"\t\t\t\t4. Eliminar un nodo"<<endl;
 cout<<"\t\t\t\t5. Listar al reves"<<endl;
 cout<<"\t\t\t\t6. Salir"<<endl<<endl<<endl;
 cout<<"\t\t\t\tDIGITE SU OPCION  ";
 cin>>op;
 return op;
}


aplista crear ()
{
 aplista c;
 c=(aplista)malloc(sizeof(lista));
 if (c==NULL)
     cout<<"PROBLEMAS CON LA MEMORIA"<<endl;
     else
     c->sig=c->ant=NULL;
 return c;
}


aplista adicionar (aplista m)
{
 int n;
 aplista nodo,aux;
 nodo=(aplista)malloc(sizeof(lista));
 cout<<endl<<endl<<"\t\t\t\tDigite el numero:  ";
 cin>>n;
 if (nodo==NULL)
     return NULL;
 aux=m;
 nodo->sig=nodo->ant=NULL; //Cambiar
 nodo->dato=n;
 while (aux->sig!=NULL)
	aux=aux->sig;
 aux->sig=nodo;
 //nodo->sig=NULL; //Preguntar si se puede cambiar
 nodo->ant=aux;
 grefer->primero=m->sig;
 grefer->ultimo=nodo;
 grefer->actual=nodo;
 grefer->cont++;
 return m;
}


int listar (aplista m)
{
 clrscr ();
 cout<<endl<<endl<<endl<<endl<<"\t\t\t\tLISTA NORMAL"<<endl<<endl<<endl;
 while (m!=NULL)
       {
	cout<<"    "<<m->dato;
	m=m->sig;
       }
 return 0;
}


int informaventana ()
{
 clrscr ();
 cout<<endl<<endl<<endl<<endl<<"\t\t\t\tDATOS DE LA VENTANA"<<endl<<endl<<endl;
 cout<<endl<<" El primer dato de la lista es:  "<<grefer->primero->dato<<endl;
 cout<<endl<<" El ultimo dato de la lista es:  "<<grefer->ultimo->dato<<endl;
 cout<<endl<<" El dato actual de la lista es:  "<<grefer->actual->dato<<endl;
 cout<<endl<<" Cantidad de nodos de la lista:  "<<grefer->cont<<endl;
 return 0;
}


int reves ()
{
 aplista aux;
 clrscr ();
 cout<<endl<<endl<<endl<<endl<<"\t\t\t\tLISTA INVERTIDA"<<endl<<endl<<endl;
 aux=grefer->ultimo;
 while (aux->ant!=NULL)
       {
	cout<<"    "<<aux->dato;
	aux=aux->ant;
       }
 return 0;
}


aplista eliminar (aplista m)
{
 clrscr ();
 return m;
}


aplista eliminar (aplista m,int n)
{
 int cd=0;
 aplista aux=m->sig;
 while (aux!=NULL)
       {
	if(aux->dato==n)
	  {
	   aux->ant->sig=aux->sig;
	   if (aux->sig!=NULL)
	       aux->sig->ant=aux->ant;
	   cd++;
	   free(aux);
	  }
	  else
	  aux=aux->sig;
       }
 if (cd==0)
     cout<<endl<<"\t\t\t\tEl dato no existe";
     else
     cout<<endl<<"\t\t\t\tEl dato se elimino correctamente";
 return m;
}