# include "conio.h"
# include "iostream.h"
# include "stdio.h"
# include "alloc.h"

typedef struct Registro
{
 char NombrePersona [50], DireccionPersona [50], ApodoPersona [20];
 long int CedulaPersona, TelefonoPersona;
};

Registro * ReservarVector (int TamanoVector);
Registro * LlenarVector (int TamanoVector);
int MostrarVector (Registro * Vector, int TamanoVector);
FILE * AbrirArchivo (char * NombreArchivo);
int GuardarElArchivo (char * NombreArchivo, int I, Registro * Vector);

int Escribir (FILE * Archivo, Registro Personas)
{
 return fwrite (& Personas, sizeof (Registro), 1, Archivo);
}

int main ()
{
 Registro * Vector;
 int TamanoVector;
 clrscr ();
 gotoxy (2,1);
 cout << "Digite el numero de personas que desea ingresar al directorio:"; putchar (32);
 cin >> TamanoVector;
 Vector = LlenarVector (TamanoVector);
 MostrarVector (Vector, TamanoVector);
 getch ();
 return 1;
}

Registro * ReservarVector (int TamanoVector)
{
 Registro * Vector;
 Vector = (Registro *) malloc (sizeof (Registro) * TamanoVector);
 return Vector;
}

Registro * LlenarVector (int TamanoVector)
{
 Registro * Vector;
 int I;
 char Decision, NombreArchivo [50];
 Vector = ReservarVector (TamanoVector);
 for (I = 0; I < TamanoVector; I++)
 {
  gotoxy (2,2);
  cout << "Ingrese el nombre de la persona No." << I; putchar (32);clreol();
  gets (Vector [I].NombrePersona);
  gotoxy (2,3);
  cout << "Ingrese el apodo de la persona No." << I; putchar (32);clreol();
  gets (Vector [I].ApodoPersona);
  gotoxy (2,4);
  cout << "Ingrese el numero de la cedula de la persona No." << I; putchar (32);clreol();
  cin >> Vector [I].CedulaPersona;
  gotoxy (2,5);
  cout << "Ingrese la direccion de la persona No." << I; putchar (32);clreol();
  gets (Vector [I].DireccionPersona);
  gotoxy (2,6);
  cout << "Ingrese el numero telefonico de la persona No." << I; putchar (32);clreol();
  cin >> Vector [I].TelefonoPersona;
  clreol();
  gotoxy (2,7);
  cout << "Desea guardar esta informaci¢n S/N?"; putchar (32);
  cin >> Decision;
  if ((Decision == 'S') || (Decision == 's'))
  {
   gotoxy (2,8);
   cout << "Ingrese el nombre del archivo:"; putchar (32);
   gets (NombreArchivo);
   GuardarElArchivo (NombreArchivo, I, Vector);
  }
 }
 return Vector;
}

int MostrarVector (Registro * Vector, int TamanoVector)
{
 int I;
 clrscr ();
 for (I = 0; I < TamanoVector; I++)
 {
  cout << Vector [I].NombrePersona << endl;
  cout << Vector [I].ApodoPersona << endl;//"\t";
  cout << Vector [I].CedulaPersona << endl;
  cout << Vector [I].DireccionPersona << endl;
  cout << Vector [I].TelefonoPersona << endl;
  getch (); clrscr ();
 }
 return 1;
}

FILE * AbrirArchivo (char * NombreArchivo)
{
 FILE * Archivo;
 Archivo = fopen (NombreArchivo, "at");
 if (Archivo == NULL)
  cout << "PROBLEMAS";
 return Archivo;
}


int GuardarElArchivo (char * NombreArchivo, int I, Registro * Vector)
{
 FILE * Archivo;
 Archivo = AbrirArchivo (NombreArchivo);
 if (Archivo != NULL)
 {
  Escribir (Archivo, Vector [I]);
  fclose (Archivo);
 }
 return 1;
}

