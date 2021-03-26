#include <iostream.h>
#include <alloc.h>
#include <stdio.h>
#include <conio.h>
#define nummaterias 1
#define numparciales 1
typedef struct calificaciones
{
float asistencia;
float participacion;
float examen;
};
typedef struct materia
{
calificaciones parciales[numparciales];
char nommateria[40];
char profesor[40];
};
typedef struct persona
{
char nombre[20];
char apellido[40];
char direccion[40];
char telefono[30];
long identificacion;
};
typedef struct alumno
{
persona fulano;
materia asign[nummaterias];
};

typedef struct lista
{
alumno estudiante;
struct lista *sig;
}*aplista;

alumno leerunalumno(aplista cab);
calificaciones leercalificaciones();
void comparar (alumno, persona);
materia leermateria();
persona leerpersona(aplista cab);
aplista crearlista();
aplista adicionarnodo(aplista cab, alumno dato);
aplista adicionar();
int imprimiralumno (alumno v);
int imprimirpersona (persona);
int imprimirmateria (materia mat);
float imprimircalificaciones (calificaciones cal);
int Imprimir (aplista cab);
int op;

int main()
{
aplista cab;
clrscr();
op=1;
cab=adicionar();
if (cab==NULL)
{
lowvideo();
gotoxy(9,3);cprintf("Ha decidido no ingresar alumnos,por favor oprima enter para salir");
highvideo();
gotoxy(9,4);
cprintf("-----------------------------------------------------------------");
gotoxy(38,5);
cprintf("   ");
gotoxy(37,5);cprintf("   ");
gotoxy(80,50);
}
else
Imprimir (cab);
getch();
return 1;
}

aplista crearlista()
{
return NULL;
}


aplista adicionar()
{
char res;
aplista cabeza;
alumno fco;
int nume;
cabeza=crearlista();
while (1)
{
clrscr();
highvideo(); gotoxy(24,3);
cprintf("Desea Ingresar un alumno s/n: ");//<<endl;
gotoxy(24,4);cprintf("------------------------------");
gotoxy(37,5);cprintf("[");gotoxy(39,5);cprintf("]");gotoxy(38,5);scanf("%c",&res);
cout<<endl;
if (res=='n' || res=='N')
break;
fco=leerunalumno (cabeza);
if (op==2)
{
highvideo();cprintf("Ya existe el registro");
getch();
op=1;
continue;
}
cabeza = adicionarnodo (cabeza,fco);
}
return cabeza;
}
aplista adicionarnodo(aplista cab, alumno dato)
{
aplista aux;
aux=cab;
aux=(aplista)malloc(sizeof(lista));
aux->sig=NULL;
aux->estudiante=dato;
if (cab==NULL)
cab=aux;
else
{
aux->sig=cab;
cab=aux;
}
return cab;
}



persona leerpersona(aplista cab)
{
persona per;
cout<<"Nombre: ";
gets (per.nombre);
cout<<"Apellido: ";
gets (per.apellido);
cout<<"Direccion: ";
gets (per.direccion);
cout<<"Telefonico: ";
gets (per.telefono);
cout<<"Identificacion: ";
cin>>per.identificacion;
while (cab!=NULL)
{
comparar(cab->estudiante,per);
cab=cab->sig;
}
return per;
}
alumno leerunalumno(aplista cab)
{
alumno aux;
int l;
aux.fulano=leerpersona(cab);
if (op==2)
return aux;
for (l=0; l<nummaterias; l++)
aux.asign[l]=leermateria();
return aux;
}

materia leermateria()
{
materia mat;
int i;
cout<<endl<<"Nombre del docente: ";
gets (mat.profesor);
cout<<"Materia: ";
gets (mat.nommateria);
cout<<endl;
for (i=0; i<numparciales; i++)
{
cout<<"Notas del parcial: "<<i+1;
mat.parciales[i]=leercalificaciones();
}
return mat;
}

calificaciones leercalificaciones()
{
calificaciones cal;
cout<<endl<<"Asistencia: ";
cin>>cal.asistencia;
cout<<"Participacion: ";
cin>>cal.participacion;
cout<<"Examen: ";
cin>>cal.examen;
return cal;
}

int Imprimir(aplista aux)
{
aplista cab;
cab=aux;
while(cab!=NULL)
{
imprimiralumno(cab->estudiante);
cab=cab->sig;
}
return 1;
}
int imprimiralumno (alumno v)
{
int l;
imprimirpersona (v.fulano);
for (l=0; l<nummaterias; l++)
imprimirmateria (v.asign[l]);
return 1;
}

int imprimirpersona(persona per)
{
cout<<endl<<"Identificacion: "<<per.identificacion<<endl;
cout<<"Nombre: "<<per.nombre<<endl;
cout<<"Apellido: "<<per.apellido<<endl;
cout<<"Telefono: "<<per.telefono<<endl;
cout<<"Direccion: "<<per.direccion<<endl;
return 1;
}

int imprimirmateria(materia mat)
{
int i;
float suma=0;
cout<<"Materia: "<<mat.nommateria<<endl;
cout<<"Profesor: "<<mat.profesor<<endl;
cout.precision (3);
for (i=0; i<numparciales; i++)
suma+=imprimircalificaciones(mat.parciales [i]);
cout<<endl<<"Definitiva: "<<suma/numparciales<<endl;
return 1;
}

float imprimircalificaciones (calificaciones cal)
{
cout<<endl<<"Nota de asistencia: "<<cal.asistencia<<endl;
cout<<"Nota de participacion: "<<cal.participacion<<endl;
cout<<"Nota de examen: "<<cal.examen<<endl;
cout<<endl<<"Nota definitiva del periodo: "<<cal.asistencia*0.10 + cal.participacion*0.20 + cal.examen* 0.70<<endl;
return cal.asistencia * 0.10 + cal.participacion * 0.20 + cal.examen * 0.70;
}









void comparar(alumno p,persona s)
{
if (p.fulano.identificacion==s.identificacion)
op=2;
}