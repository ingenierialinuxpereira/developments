# include "conio.h"
# include "iostream.h"
# include "stdio.h"
# include "alloc.h"

typedef struct Registro
{
 char NombrePersona [50], DireccionPersona [50], ApodoPersona [20];
 long int CedulaPersona, TelefonoPersona;
};

Registro ** ReservarMatriz (int TamanoColumnasMatriz, int TamanoFilasColumnas);
Registro ** LlenarMatriz (int TamanoColumnasMatriz, int TamanoFilasMatriz);
int MostrarMatriz (Registro ** Matriz, int TamanoColumnasMatriz, int TamanoFilasColumnas);
FILE * AbrirArchivo (char * NombreArchivo);
int GuardarElArchivo (char * NombreArchivo, int I, int J, Registro ** Matriz);

int Escribir (FILE * Archivo, Registro Personas)
{
 return fwrite (& Personas, sizeof (Registro), 1, Archivo);
}

int main ()
{
 Registro ** Matriz;
 int TamanoColumnasMatriz, TamanoFilasMatriz;
 clrscr ();
 gotoxy (2,1);
 cout << "Digite el numero de columnas del que desea la matriz:"; putchar (32);
 cin >> TamanoColumnasMatriz;
 cout << "Digite el numero de filas del que desea la matriz:"; putchar (32);
 cin >> TamanoFilasMatriz;
 Matriz = LlenarMatriz (TamanoColumnasMatriz, TamanoFilasMatriz);
 MostrarMatriz (Matriz, TamanoColumnasMatriz, TamanoFilasMatriz);
 getch ();
 return 1;
}

Registro ** ReservarMatriz (int TamanoColumnasMatriz, int TamanoFilasMatriz)
{
 Registro ** Matriz;
 int I;
 Matriz = (Registro **) malloc (sizeof (Registro) * TamanoFilasMatriz);
 for (I = 0; I < TamanoColumnasMatriz; I++)
  Matriz [I] = (Registro *) malloc (sizeof (Registro) * TamanoColumnasMatriz);
 return Matriz;
}

Registro ** LlenarMatriz (int TamanoColumnasMatriz, int TamanoFilasMatriz)
{
 Registro ** Matriz;
 int I, J;
 char Decision, NombreArchivo [50];
 Matriz = ReservarMatriz (TamanoColumnasMatriz, TamanoFilasMatriz);
 for (I = 0; I < TamanoFilasMatriz; I++)
  for (J = 0; J < TamanoColumnasMatriz; J++)
  {
   gotoxy (2,2);
   cout << "Ingrese el nombre de la persona No." << I << J; putchar (32); clreol();
   gets (Matriz [I] [J].NombrePersona);
   gotoxy (2,3);
   cout << "Ingrese el apodo de la persona No." << I << J; putchar (32); clreol();
   gets (Matriz [I] [J].ApodoPersona);
   gotoxy (2,4);
   cout << "Ingrese el numero de la cedula de la persona No." << I << J; putchar (32); clreol();
   cin >> Matriz [I] [J].CedulaPersona;
   gotoxy (2,5);
   cout << "Ingrese la direccion de la persona No." << I << J; putchar (32); clreol();
   gets (Matriz [I] [J].DireccionPersona);
   gotoxy (2,6);
   cout << "Ingrese el numero telefonico de la persona No." << I << J; putchar (32); clreol();
   cin >> Matriz [I] [J].TelefonoPersona;
   gotoxy (2,7);
   cout << "Desea guardar esta informaci¢n S/N?"; putchar (32);
   cin >> Decision;
   if ((Decision == 'S') || (Decision == 's'))
   {
    gotoxy (2,8);
    cout << "Ingrese el nombre del archivo:"; putchar (32);
    gets (NombreArchivo);
    GuardarElArchivo (NombreArchivo, I, J, Matriz);
   }
  }
 return Matriz;
}

int MostrarMatriz (Registro ** Matriz, int TamanoColumnasMatriz, int TamanoFilasMatriz)
{
 int I, J;
 clrscr ();
 for (I = 0; I < TamanoFilasMatriz; I++)
  for (J = 0; J < TamanoColumnasMatriz; J++)
  {
   cout << Matriz [I] [J].NombrePersona << endl;
   cout << Matriz [I] [J].ApodoPersona << endl;//"\t";
   cout << Matriz [I] [J].CedulaPersona << endl;
   cout << Matriz [I] [J].DireccionPersona << endl;
   cout << Matriz [I] [J].TelefonoPersona << endl;
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


int GuardarElArchivo (char * NombreArchivo, int I, int J, Registro ** Matriz)
{
 FILE * Archivo;
 Archivo = AbrirArchivo (NombreArchivo);
 if (Archivo != NULL)
 {
  Escribir (Archivo, Matriz [I] [J]);
  fclose (Archivo);
 }
 return 1;
}

