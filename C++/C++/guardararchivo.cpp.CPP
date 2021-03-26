/*********************************************************/
#include<fstream>
#include<iostream>
#include<conio.h>      //cabeceras correspondientes al manejo de las diferentes instrucciones en el codigo
#include<stdio.h>
#include<string.h>
/*********************************************************/
int main()
{
clrscr();//limpieza de pantalla
char  * francisco,unidad,texto[150]; //declaracion de variables
/*********************************************************/
cout<<"        En que unidad?"<<endl;
cout<<"Floppy(A:/) ¢ Disco Duro (C:/):"<<endl;
gotoxy(14,3);
cout<<"[";                                     //seccion para darle al usuario la libertad de escoger la unidad
gotoxy(16,3);
cout<<"]";
gotoxy(15,3);
cin>>unidad;
/**********************************************************/
if((unidad=='A')||(unidad=='a'))
{
cout<<"RUTA EN (A:/):";
gotoxy(16,4);
cin>>francisco;
}
else//if((unidad!='a')||(unidad!='A')||(unidad!='c')||(unidad!='C'))
{
cout<<"                  Unidad no Admitida"<<endl;
getch();
main();
}
				      //seccion que compara si la unidad es valida
if((unidad=='C')||(unidad=='c'))
{
cout<<"RUTA EN (C:/):";
gotoxy(16,4);
cin>>francisco;
}
else//if((unidad!='a')||(unidad!='A')||(unidad!='c')||(unidad!='C'))
{
cout<<"                  Unidad no Admitida"<<endl;
getch();
main();
}

/*********************************************************/
strcat(francisco,".txt");
ofstream pacho(francisco,ios::app);
  if(!pacho)
  {
   cout<<" Error!, porfavor especifique la uinidad de destino"<< endl;  //correspondiente a la operacion interna para generar el archivo especificado por el usuario
   cout<<"y el nombre del archivo sin puntos, espacios, ni comas";
   getch();
   return -1;
  }
/*********************************************************/
  cout<<"    Por favor ingrese el contenido del archivo"<< endl;
  gets(texto);   //captura del texto que se almacenara en el archivo
  getch();
  pacho<<texto<<endl;//escritura en el archivo
  pacho.close();//cierra el archivo
  return 0;
}



