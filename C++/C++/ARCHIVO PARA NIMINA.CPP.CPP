/*Mantener grandes ficheros de datos ordenados es muy costoso, ya que
requiere mucho tiempo de procesador. Afortunadamente, existe una
alternativa mucho mejor: indicarlos (o indexarlos).

Para indicar un archivo normalmente se suele generar un archivo auxiliar
de índices. Existen varios métodos, de los que veremos algunos.
El más sencillo es crear un archivo plano que sólo contenga registros
con dos campos: el campo o la expresión por la que queremos ordenar
el archivo, y un campo con un índexe que almecene la posición del registro
indicado en el archivo de datos.

Por ejemplo, supongamos que tenemos un archivo de datos con la
siguiente estructura de registro:

struct stRegistro {
   char nombre[32];
   char apellido[2][32];
   char telefono[12];
   char calle[45];
   int numero;
   char ciudad[32];
   char fechaNacimiento[9]; // formato AAAAMMDD: Año, mes y día
   char estadoCivil;
   int hijos;
}

Imaginemos que necesitamos buscar un registro a partir del número de
teléfono. Si no tenemos el archivo ordenado por ese campo, estaremos
obligados a leer todos los registros del archivo hasta encontrar el que
buscamos, y si el número no está, tendremos que leer todos los registros
que existan.

Si tenemos el archivo ordenado por números de teléfono podremos aplicar
un algoritmo de búsqueda. Pero si también queremos hacer búsquedas por
otros campos, estaremos obligados a ordenar de nuevo el archivo.

La solución es crear un fichero de índices, cada registro de este archivo
tendrá la siguiente estructura:

struct stIndiceTelefono {
   char telefono[12];
   long indice;
}
Crearemos el fichero de índices a partir del archivo de datos, asignando a cada registro el campo "telefono" y el número de registro correspondiente. Veamos un ejemplo:

000: [Fulanito] [Pérez] [Sanchez] [12345678] [Mayor] [15] [Lisboa] [19540425] [S] [0]
001: [Fonforito] [Fernandez] [López] [84565456] [Baja] [54] [Londres] [19750924] [C] [3]
002: [Tantolito] [Jimenez] [Fernandez] [45684565] [Alta] [153] [Berlin] [19840628] [S] [0]
003: [Menganito] [Sanchez] [López] [23254532] [Diagonal] [145] [Barcelona] [19650505] [C] [1]
004: [Tulanito] [Sanz] [Sanchez] [54556544] [Pez] [18] [Dublín] [19750111] [S] [0]

Generamos un fichero de índices:

[12345678][000]
[84565456][001]
[45684565][002]
[23254532][003]
[54556544][004]
Y lo ordenamos:

[12345678][000]
[23254532][003]
[45684565][002]
[54556544][004]
[84565456][001]
Ahora, cuando queramos buscar un número de teléfono, lo haremos en el fichero
de índices, por ejemplo el "54556544" será el registro número 3, y le
corresponde el índice "004". Con ese índice podemos acceder directamente
al archivo de datos, y veremos que el número corresponde a
"Tulanito Sanz Sanchez".

Por supuesto, nada nos impide tener más ficheros de índices, para otros
campos.

El mayor problema es mantener los ficheros de índices ordenados a medida
que añadimos, eliminamos o modificamos registros. Pero al ser los registros
de índices más pequeños, los ficheros son más manejables, pudiendo incluso
 almacenarse en memoria en muchos casos.

Ejemplo
Veramos un ejemplo de implementación de índices:


// indices.cpp: Ejemplo de ficheros de acceso aleatorio con índices.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
struct stRegistro {
   char valido;  // Campo que indica si el registro es valido S->Válido, N->Inválido
   char nombre[34];
   char apellido[2][34];
   char telefono[10];
   char sexo[15];
   char cedula[10];
   long salario;
   char direccion[30];
   int edad;
};

struct stIndice {
   char telefono[10];
   long indice;
};

int Menu();
void Capturar(stRegistro &reg);
void EliminarRetornoLinea(char *cad);
void Leer(FILE *fa, stRegistro &reg, char *telefono);
void Insertar(FILE *fa, stRegistro &reg);
void Mostrar(stRegistro &reg);
void ListarPorTelefonos(FILE *fa);
void ListarNatural(FILE *fa);
void ReconstruirIndices(FILE *fa);
// Funciones para ordenar el fichero de índices:
void Intercambia(FILE *fa, long iz, long de);
char *LeeCampo(FILE *fa, long n, char *buf);
void QuickSort(FILE *fa, long inicio, long final);

int main()
{
   stRegistro reg;
   FILE *fa;
   int opcion;
   char telefono[10];
   clrscr();
   fa = fopen("indices.dat", "r+b");          // Este modo permite leer y escribir
   if(!fa) fa = fopen("indices.dat", "w+b");  // si el fichero no existe, lo crea.

   do {
      opcion = Menu();
      switch(opcion) {
	 case '1': // Insertar registro
	    Capturar(reg);
	    Insertar(fa, reg);
	    break;
	 case '2': // Buscar registro
	    system("cls");
	    printf("Buscar registro (la b£squeda se har  por n£mero telef¢nico): ");
	    do {
	       fgets(telefono, 10, stdin);
	       EliminarRetornoLinea(telefono);
	    } while(strlen(telefono) < 1);
	    Leer(fa, reg, telefono);
	    Mostrar(reg);
	    break;
	 case '3': // Indicar archivo
	    system("cls");
	    printf("Indicando archivo: ");
	    ReconstruirIndices(fa);
	    break;
	 case '4': // Mostrar todo por orden de teléfonos
	    ListarPorTelefonos(fa);
	    break;
	 case '5': // Mostrar todo por orden natural
	    ListarNatural(fa);
	    break;
      }
   } while(opcion != '0');
   fclose(fa);
   return 0;
}

// Muestra un menú con las opciones disponibles y captura una opción del usuario
int Menu()
{
   char resp[20];

   do {
      system("cls");
      printf("MENU PRINCIPAL\n");
      printf("--------------\n\n");
      printf("1- Insertar registro\n");
      printf("2- Buscar registro\n");
      printf("3- Reindicar archivo\n");
      printf("4- Listar por orden de teléfonos\n");
      printf("5- Listar por orden natural\n");
      printf("0- Salir\n");
      fgets(resp, 20, stdin);
   } while(resp[0] < '0' && resp[0] > '5');
   return resp[0];
}

// Permite que el usuario introduzca un registro por pantalla
void Capturar(stRegistro &reg)
{
   char edad[4];
   char numero[10];

   system("cls");
   printf("Leer registro:\n\n");
   reg.valido = 'S';
   printf("Nombre: ");
   fgets(reg.nombre, 34, stdin);
   EliminarRetornoLinea(reg.nombre);
   printf("Primer apellido: ");
   fgets(reg.apellido[0], 34, stdin);
   EliminarRetornoLinea(reg.apellido[0]);
   printf("Segundo apellido: ");
   fgets(reg.apellido[1], 34, stdin);
   EliminarRetornoLinea(reg.apellido[1]);
   printf("Tel‚fono: ");
   fgets(reg.telefono, 10, stdin);
   EliminarRetornoLinea(reg.telefono);
   printf("C‚dula:");
   fgets(reg.cedula,10,stdin);
   printf("Direcci¢n:");
   fgets(reg.direccion,30,stdin);


   printf("Edad:");
   fgets(edad,4,stdin);
   reg.edad = atoi(edad);

   printf("Sexo:");
   fgets(reg.sexo,15,stdin);

   printf("Salario:");
   fgets(numero,10,stdin);
   reg.salario = atoi(numero);
}

// Elimina los caracteres de retorno de línea al final de cadena
void EliminarRetornoLinea(char *cad)
{
   int i;
   // la función fgets captura el retorno de línea, hay que eliminarlo:
   for(i = strlen(cad)-1; i >= 0 && cad[i] < ' '; i--) cad[i] = 0;
}

// Muestra un registro en pantalla, si no está marcado como borrado
void Mostrar(stRegistro &reg)
{
   int i;

   if(reg.valido == 'S') {
      printf("Nombre: %s %s %s\n", reg.nombre, reg.apellido[0], reg.apellido[1]);
      printf("N£mero de tel‚fono: %s\n", reg.telefono);
      printf("Cedula:%s",reg.cedula);
      printf("Sexo:%s",reg.sexo);
      printf("Direccion:%s",reg.direccion);
      printf("Salario:%ld",reg.salario);
      printf("Edad:%d",reg.edad);
   }
   system("PAUSE");
}

// Lee el registro desde el fichero de datos con el teléfono dado
void Leer(FILE *fa, stRegistro &reg, char *telefono)
{
   FILE *fi;
   stIndice ind;
   long inf, sup, n, nRegs;

   fi = fopen("indices.ind", "rb");
   fseek(fi, 0, SEEK_END);
   nRegs = ftell(fi)/sizeof(stIndice);
   // Búsqueda binaria:
   inf = 0;
   sup = nRegs-1;
   do {
      n = inf+(sup-inf)/2;
      fseek(fi, n*sizeof(stIndice), SEEK_SET);
      fread(&ind, sizeof(stIndice), 1, fi);
      if(strcmp(ind.telefono, telefono) < 0) inf = n+1;
      else sup = n-1;
   } while(inf <= sup && strcmp(ind.telefono, telefono));
   // Si se encontró el teléfono, lee el registro, si no muestra mensaje.
   if(!strcmp(ind.telefono, telefono)) {
      fseek(fa, ind.indice*sizeof(stRegistro), SEEK_SET);
      fread(&reg, sizeof(stRegistro), 1, fa);
   }
   else {
      reg.valido = 'N';
      printf("Registro no encontrado\n");
   }
   fclose(fi);
}

// Añade un registro al archivo de datos y reconstruye los índices
void Insertar(FILE *fa, stRegistro &reg)
{
   // Insertar al final:
   fseek(fa, 0, SEEK_END);
   fwrite(&reg, sizeof(stRegistro), 1, fa);
   ReconstruirIndices(fa);
}

// Lista todos los registros ordenados por el número de teléfono
void ListarPorTelefonos(FILE *fa)
{
   FILE *fi;
   stIndice ind;
   stRegistro reg;

   system("cls");
   fi = fopen("indices.ind", "rb");
   while(fread(&ind, sizeof(stIndice), 1, fi)) {
      fseek(fa, ind.indice*sizeof(stRegistro), SEEK_SET);
      fread(&reg, sizeof(stRegistro), 1, fa);
      printf("%s %s %s %s\n", reg.nombre, reg.apellido[0],
      reg.apellido[1], reg.telefono);
      printf("Cedula:%s",reg.cedula);
      printf("Sexo:%s",reg.sexo);
      printf("Direccion:%s",reg.direccion);
      printf("Salario:%ld\n",reg.salario);
      printf("Edad:%d\n",reg.edad);
   }
   fclose(fi);
   system("PAUSE");
}

// Lista todos los registros del archivo de datos por el orden en que se
// insertaron.
void ListarNatural(FILE *fa)
{
   stRegistro reg;

   rewind(fa);
   system("cls");
   while(fread(&reg, sizeof(stRegistro), 1, fa))
      printf("%s %s %s %s\n", reg.nombre, reg.apellido[0],
	 reg.apellido[1], reg.telefono);
   system("PAUSE");
}

// Reconstruye el archivo de índices
void ReconstruirIndices(FILE *fa)
{
   long n=0;
   FILE *fi;
   stRegistro reg;
   stIndice ind;

   // Crea el fichero de índices a partir del archivo de datos:
   fi = fopen("indices.ind", "w+b");
   rewind(fa);
   while(fread(&reg, sizeof(stRegistro), 1, fa)) {
      strcpy(ind.telefono, reg.telefono);
      ind.indice = n++;
      fwrite(&ind, sizeof(stIndice), 1, fi);
   }
   // Ordena usando el algoritmo Quicksort:
   QuickSort(fi, 0, n-1);
   fclose(fi);
}

// Implementacion del algoritmo Quicksort para fichero de Indices
void QuickSort(FILE *fi, long inicio, long final)
{
   long iz, de;
   char mitad[10];
   static char cad[10];

   iz = inicio;
   de = final;
   strcpy(mitad, LeeCampo(fi, (iz+de)/2, cad));
   do {
      while(strcmp(LeeCampo(fi, iz, cad), mitad) < 0 && iz < final) iz++;
      while(strcmp(mitad, LeeCampo(fi, de, cad)) < 0 && de > inicio) de--;
      if(iz < de) Intercambia(fi, iz, de);
      if(iz <= de) {
         iz++;
         de--;
      }
   } while(iz <= de);
   if(inicio < de) QuickSort(fi, inicio, de);
   if(iz < final) QuickSort(fi, iz, final);
}

char *LeeCampo(FILE *fi, long n, char *buf)
{
   stIndice ind;

   fseek(fi, n*sizeof(stIndice), SEEK_SET);
   fread(&ind, sizeof(stIndice), 1, fi);
   strcpy(buf, ind.telefono);
   return buf;
}

void Intercambia(FILE *fi, long iz, long de)
{
   stIndice reg1, reg2;

   fseek(fi, iz*sizeof(stIndice), SEEK_SET);
   fread(&reg1, sizeof(stIndice), 1, fi);
   fseek(fi, de*sizeof(stIndice), SEEK_SET);
   fread(&reg2, sizeof(stIndice), 1, fi);
   fseek(fi, iz*sizeof(stIndice), SEEK_SET);
   fwrite(&reg2, sizeof(stIndice), 1, fi);
   fseek(fi, de*sizeof(stIndice), SEEK_SET);
   fwrite(&reg1, sizeof(stIndice), 1, fi);
}


/*Aún no hemos llegado al mayor nivel de optimización, nuestro último ejemplo
requiere reconstruir el fichero de índices cada vez que se añade o se
elimina un registro.*/

