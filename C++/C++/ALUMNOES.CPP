#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<iostream.h>
#define NUMMATERIAS  1
#define NUMPARCIALES 2

typedef struct calificaciones
  {
     float asistencia;
     float participacion;
     float examen;
  };

typedef struct materia
   {
     calificaciones parciales[NUMPARCIALES];
     char nommateria[40];
     char profesor[40];
   };

typedef struct persona
   {
     char nombre [40];
     char apellido [40];
     char direccion [40];
     char telefono [30];
     long identificacion;
   };

typedef struct alumno
  {
    persona fulano;
    materia asign [NUMMATERIAS];
  };


typedef struct lista
{
int info;
struct lista *sig;
}* aplista;
 aplista crearlista();
 aplista adicionarn(aplista cab,int dato);
 aplista adicionar();
 int imprimirlista(aplista c)
int main()
{
aplista cab;
cab=adicionarn();
gotoxy(30,1);cout<<"Francisco Gutierrez";
if (cab==NULL)
cout<<"memoria insufuciente";
else
imprimirlista(cab);
getch();
return 1;
}
aplista crearlista();
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
aux -> sig= info =dato;
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
aplista adicionar()
{
aplista cab;
int num,dato;
cab=crearlista();
if(cab==NULL)
return NULL;
while(1)
{
pacho=LeerPersona(cab,pacho)
cab=adicionarn(cab,dato);
break;
}
return cab;
}
int imprimirlista(aplista aux)
{
aplista cab;
cab=aux;
while(cab!=NULL)
{
cout<<"la informacion esta descrita asi:"<<cab>>info;
cab=cab->sig;
}
return 1;
}
persona LeerPersona()
{
 persona per;
 cout<<"Ingrese el nombre: ";
 gets(per.nombre);
 cout<<"Ingrese el apellido: ";
 gets(per.apellido);
 cout<<"Ingrese la direccion: ";
 gets(per.direccion);
 cout<<"Ingrese el numero telefonico: ";
 cin>>per.telefono;
 cout<<"Ingrese la identificacion: ";
 cin>>(per.identificacion);
 return per;
}
materia LeerMateria();
{
  materia mat;
  int i;
  cout<<"Ingrese por favor el nombre del profesor: ";
  gets(mat.profesor);
  cout<<"Ingrese el nombre de la materia:";
  gets(mat.nommateria);
  cout<<endl;
//  falta....
}
calificaciones LeerCalificaciones();
{
 calificaciones cal;
 cout<<" Ingrese la nota de la asistencia: ";
 cin>>cal.asistencia;
 cout<<" Ingrese la nota de la participacion: ";
 cin>>cal.participacion;
 cout<<" Ingrese la nota del examen: ";
 cin>>cal.examen;

 return cal;
}
