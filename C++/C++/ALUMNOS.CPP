#include <iostream.h>
#include <conio.h>
#include <alloc.h>
#include<stdio.h>
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

alumno * ReservaMemoria(int x);
alumno LeerUnSoloAlumno();
alumno * LeerAlumnos(int pos);
calificaciones LeerCalificaciones();
materia LeerMateria();
persona LeerPersona();
int Imprimir(alumno *v,int pos);
int ImprimirAlumno(alumno v);
int ImprimirPersona(persona);
int ImprimirMateria(materia mat);
float ImprimirCalificaciones(calificaciones cal);

int main()
{
 alumno *Vec;
 int numPos;
 clrscr();
 cout<<" Diga el numero de alumnos del grupo: ";
 cin>>numPos;
 Vec=LeerAlumnos(numPos);
 if(Vec==NULL)
    cout<<"Problemas al reservar la memoria ";
 else
    Imprimir(Vec,numPos);

 getch();

 free(Vec); //libero la memoria que reserve
 return 1;
}


/*funcion que reserva memoria para un vector de datos de tipo alumnos**/
alumno * ReservaMemoria(int pos)
{
 alumno *p;
 p=(alumno *)malloc(sizeof(alumno)*pos);
 return p;
}

/**FUNCIONES DE LECTURA DE DATOS*/
alumno *LeerAlumnos(int pos)
{
 int i;
 alumno *G;
 G=ReservaMemoria(pos);
 if(G!=NULL)
    for(i=0;i<pos;i++)
      //se lee de aun alumno y se guarda en la posicion del vector
       G[i]=LeerUnSoloAlumno();

 return G;
}

alumno LeerUnSoloAlumno()
{
 alumno aux;
 int i;

 /*  Miren que el campo fulano(de la estructura alumno) es de tipo persona
     y la funcion LeerPersona retorna un dato de tipo persona*/

 aux.fulano=LeerPersona();
 for(i=0;i<NUMMATERIAS;i++)
  /*
   Miren que el campo asign es un atributo de la estructura alumno y que a su vez es un vector, tambien miren que es de tipo
   materia y que la funcion LeerMateria retorna un dato de tipo...qué tipo?
  */
   aux.asign[i]=LeerMateria();
 return aux;
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


materia LeerMateria()
{
  materia mat;
  int i;
  cout<<"Ingrese por favor el nombre del profesor: ";
  gets(mat.profesor);
  cout<<"Ingrse el nombre de la materia:";
  gets(mat.nommateria);
  cout<<endl;
  for(i=0;i<NUMPARCIALES;i++)
    {
     cout<<endl<<" Ingrese las notas del parcial "<<i+1<<endl;
     mat.parciales[i]=LeerCalificaciones();
    }

 return mat;
}


calificaciones LeerCalificaciones()
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


/*****FUNCIONES DE IMPRESION***/

int Imprimir(alumno *p,int pos)
{
 int i;
 for(i=0;i<pos;i++)
  {
   ImprimirAlumno(p[i]);
   getch();
  }
  return 1;
}
int ImprimirAlumno(alumno  v)
{

 int i;
 ImprimirPersona(v.fulano);
 for(i=0;i<NUMMATERIAS;i++)
    ImprimirMateria(v.asign[i]);

 return 1;
}

int ImprimirPersona(persona per)
{cout<<endl;
 cout<<"Identificacion: "<<per.identificacion<<endl;
 cout<<"Nombre :"<<per.nombre<<endl;
 cout<<"Apellido :"<<per.apellido<<endl;
 cout<<"Telefono :"<<per.telefono<<endl;
 cout<<"Direccion :"<<per.direccion<<endl;

return 1;
}

int ImprimirMateria(materia mat)
{
 int i;
 float suma=0;
 cout<<"Materia:"<<mat.nommateria<<endl;
 cout<<"Profesor:"<<mat.profesor<<endl;
 cout.precision(3);
 for(i=0;i<NUMPARCIALES;i++)
   suma+=ImprimirCalificaciones(mat.parciales[i]);

 cout<<"Su definitiva es: "<<suma/NUMPARCIALES;
return 1;
}

float  ImprimirCalificaciones(calificaciones cal)
{
  cout<<"Nota de asistencia: "<<cal.asistencia<<endl;
  cout<<"Nota de participacion: "<<cal.participacion<<endl;
  cout<<"Nota de examen: "<<cal.examen<<endl;
  cout<<"Nota de definitiva parcial: "<<cal.asistencia*0.10+ cal.participacion*0.20+ cal.examen*0.70<<endl;

 return cal.asistencia*0.10+ cal.participacion*0.20+ cal.examen*0.70;
}
