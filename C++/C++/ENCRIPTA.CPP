

/*
  Encriptado de textos.
  Noviembre 1 del 2003.
  Francisco Javier Gutierrez.
*/

#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <string.h>
#include <ctype.h>
#include<dos.h>
int main(void)
{
    FILE *arch,*handle;
    char encriptado[100],desencriptado[100], r, pas[11];
    int longitud,i;


    arch=fopen("c:\Datos.txt","w");

    clrscr();

    cout<<"Escriba el texto que deseas encriptar :\n\n ";
    cin.getline(encriptado,100);

    longitud = strlen(encriptado);

    for ( i = 0;i<longitud;i++)
    {
       encriptado[i] = char(toascii(encriptado[i])+122);
    }
    fprintf(arch,"%s",encriptado);
    cout<<"\n\nEl texto encriptado es\n\n "<<encriptado;

    cout<<"\n\nDesea desencriptar el texto s/n\n ";
    cin>>r;
    if (toupper(r)=='S')
    {
       cout<<"\n\nLa clave de acceso para desencriptar : ";
       cin>>pas;
       if (strcmp(pas,"francisco")==0)
       {
	  cout<<"\n\nEl texto desencriptado es\n ";
	  for(i=0;i<longitud;i++)
	  {
	     desencriptado[i]=char(encriptado[i])-122;
	     cout<<desencriptado[i];
	  }
       }
       else
       {
	  cout<<"\n\n\nNo esta autorizado para ver el archivo....";
	  getch();
       }
    }
    else cout<<"\n\nGracias por utilizar el programa...";
    getchar();
    fclose(arch);

    return(0);
}

