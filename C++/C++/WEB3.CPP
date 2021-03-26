#include"conio.h"
#include<dos.h>
#include"stdio.h"
#include"fstream.h"
#include"string.h"
#include"stdlib.h"


void cuadro(int x1,int y1,int x2,int y2,int color);    //funciones que intervienen en la creacion de la aplicacion
int etiquetas();

/*---------------------------funci¢n cuadro----------------------------------*/
//Nota: se hace con (cprintf)para hacer efectivo el color de la linea
void cuadro (int x1,int y1,int x2,int y2, int color)
{
int xi;

textcolor(color);

for (xi=y1; xi<=y2; xi++)
{
gotoxy (xi,x1);
delay(4);//tiempo para el dibujado del recuadro
cprintf("%c",196);
gotoxy (xi,x2);
cprintf("%c",196);
}

for (xi=x1; xi<=x2; xi++)
{
gotoxy (y1,xi);
cprintf("%c",179);
gotoxy (y2,xi);
cprintf("%c",179);
}

gotoxy(y1,x1);
cprintf("%c",218);
gotoxy(y2,x2);
cprintf("%c",217);
gotoxy(y2,x1);
cprintf("%c",191);
gotoxy(y1,x2);
cprintf("%c",192);
}
/*---------------------------fin funcion cuadro------------------------------*/

/*--------------------funcion para desarrollo de etiquetas-------------------*/

int etiquetas()
{

 clrscr ();
 int opc,posicion,salir=0;

 char res[10],unidad,v,pagina[100],texto[100];

 textmode(BW80);  //tipo de letra modo grafico me sirve modo texto//

/***************Destino del archivo web con su unidad respectiva**************/
 gotoxy(20,10);
 cout<<"Unidad de destino:";//unidad destino
 cin>>unidad;
 if(unidad=='C'||unidad=='c')
 {
 gotoxy(21,11);
 cout<<"C:";
 gotoxy(23,11);      //ojo preguntar a hugo
 putchar(char(47));
 gotoxy(8,10);
 cout<<"Nombre que desea para archivo web,anteponga este simbolo /";
 gotoxy(24,11);
 cin>>pagina;
 clrscr();
 }
 /*cout<<"nombre:";  //ojo
 cin>>pagina;*/

 if(unidad=='a'|| unidad=='A')
 {
 /*gotoxy(23,11);
 putchar(char(92));*/
 gotoxy(21,11);
 cout<<"A:";
 /*gotoxy(23,11);
 putchar(char(92));*/
 gotoxy(20,10);
 cout<<"Nombre que desea para archivo web";
 gotoxy(24,11);
 cin>>pagina;
 clrscr();
 }

 strcat(pagina,".html");//concatena con extension para tipo de archivo a generar//
 ofstream pacho(pagina,ios::app);//creo un objeto(pacho), para trabajar funciones miembro

  if(pacho.bad())//condiciona la creaci¢n de archivo
  {
   gotoxy(20,10);
   cout<<"Error en creacion de archivo"<< endl;//valido que el archivo se haya abierto
   getch();
   return -1;

 }//cierro if()

pacho<<"<html>";//identifica codigo en HTML
gotoxy(33,13);
v=putchar(char(92));
gotoxy(25,11);
cout<<"DIRECTORIO-->"<<unidad<<":"<<v<<pagina;//unidad y ruta seguido del titulo
gotoxy(27,13);
cout<<"TITULO DE LA PAGINA";
gotoxy(31,14);
cout<<"[";
gotoxy(41,14);
cout<<"]";
gotoxy(32,14);
cin>>texto;
pacho<<"<head> <title>";//titulo de pagina cerado en el objeto pacho
pacho<<texto;
pacho<<"</title></head>";//termina la funcion de ingreso de titulo
pacho<<"<body>";//cuerpo de la pagina

 do
 {
  clrscr();
  //menu p/pal
  //textmode(BW40);

  cuadro(5,8,15,72,2);//cuadro grande
  cuadro(6,10,14,70,BROWN);//cuadro mediano
  cuadro(18,36,20,42,LIGHTBLUE);//cuadro peque¤o

  gotoxy(36,3);
  cout<<"OPCIONES";
  gotoxy(20,7);
  cout << "1. IMAGEN";
  gotoxy(20,9);
  cout << "2. TEXTO";
  gotoxy(20,11);
  cout << "3. MARQUEZINA";
  gotoxy(20,13);
  cout << "4. BOTON";
  gotoxy(50,7);
  cout << "5. CAMPO PASSWORD";
  gotoxy(50,9);
  cout << "6. TITULO";
  gotoxy(50,11);
  cout << "7. HIPERVINCULO";
  gotoxy(50,13);
  cout<<  "8. SALIR";
  gotoxy(40,19);
  cout << "]";
  gotoxy(38,19);
  cout <<"[";
  cin >>res;    //leo con una variable tipo char , para tener en cuenta cualquier error del usuario//
  opc=atoi(res);//primero a caracter lo convierto en un valor int,despues lo convierto en la variable opc
  clrscr();

 //tomo en cuenta la variable opc al momento de leer la opcion del menu

    switch (opc)
    {

/****************************trabajo con imagen*******************************/
    //<img src= "ruta" alt="descripcion">//

   case 1:
	  cuadro(7,29,15,45,BLUE);
	  cuadro(8,30,14,44,BLUE);

	  gotoxy(32,9);
	  cout<<"1. Centrado";
	  gotoxy(32,11);
	  cout<<"2. Izquierdo";
	  gotoxy(32,13);
	  cout<<"3. Derecho";
	  gotoxy(30,16);
	  cout<<"Posici¢n :    ";
	  cin>>res;

	  posicion=atoi(res);//evita error de usuario
	   if(posicion>3)//regresa al menu principal//
	    {
	    clrscr();
	    break;
	    }
	    if(posicion==1)
	    pacho<<"<p align=\"center\">";//alineacion central
	    if(posicion==2)
	    pacho<<"<p align=\"left\">";//alineacion izq.
	    if(posicion==3)
	    pacho<<"<p align=\"right\">";//alineacion derecha
	    pacho<<"<img src= \" "; //insercion de imagen
	    gotoxy(20,17);
	    cout<<"Ruta :        "; //ruta de directorio donde se necuentra la imagen
	    cin>>texto;
	    pacho<<texto;
	    pacho<<"\" alt =\" ";
	    gotoxy(20,18);
	    cout<<"Descripcion : ";//informacion sobre elemento
	    gets(texto);
	    pacho<<texto;
	    pacho<<"\"></p>";//salto de linea
	    clrscr();
	    break;

/**********Trabajo con Tipo de linea y color de texto*************************/

  case 2:
	   gotoxy(20,3);
	   cout<<"El color de la letra digitelo en ingles";
	   gotoxy(20,4);
	   cout<<"Si no sabe, digite un numero entre 1-15";
	   cuadro(8,30,14,44,BLUE);
	   gotoxy(22,9);
	   cout<<"1. Centrado";
	   gotoxy(22,11);
	   cout<<"2. Izquierda";
	   gotoxy(22,13);
	   cout<<"3. Derecha";
	   gotoxy(20,15);
	   cout<<"Posici¢n :    ";
	   cin>>res;

	   posicion=atoi(res);//evita error del usuario al digitar

	     if(posicion>3)//si se cumple, retorna el menu principal
	     {
	     clrscr();
	     break;
	     }
	   if(posicion==1)
	   pacho<<"<p align=\"center\">";//alineacion de texto centrado
	   if(posicion==2)
	   pacho<<"<p align=\"left\">"; //alineacion de texto izq.
	   if(posicion==3)
	   pacho<<"<p align=\"right\">";//alineacion de texto derecha
	   pacho<<"<font face =\"" ;
	   gotoxy(20,16);
	   cout<<"Tipo de letra :        " ;//escoge el tipo de letra
	   cin>>texto;
	   pacho<<texto;
	   pacho<<"\"color =\"";//color de letra
	   gotoxy(20,17);
	   cout<<"Color :                ";
	   gets(texto);
	   pacho<<texto;
	   pacho<<"\">";
	   gotoxy(20,18);
	   cout<<"Texto :                "; //digitar texto de la pagina
	   gets(texto);
	   pacho<<texto;
	   pacho<<"</font></p>";//salto de linea
	   clrscr();
	   break;

/*********************** Trabajo con marquezina******************************/
   //inserta marquesina
   //<p> <marquee> texto </marquee></p>

   case 3:
	  gotoxy(20,10);
	  cout<<"Mensaje de texto con desplazamiento horizontal";
	  pacho<<"<p><marquee>" ; //marquezina
	  gotoxy(20,12);
	  cout<<"Texto a desplazarce en la marquezina :  " ;
	  gets(texto);
	  pacho<<texto;
	  pacho<<"</marquee></p>";//salto de linea
	  clrscr();
	  break;

/*************************Trabajo con el botones*******************************/
   //inserta boton
   //<input type=button value="texto">

   case 4:
	  cuadro(8,30,14,44,BLUE);
	  gotoxy(22,9);
	  cout<<"1. Centrado";
	  gotoxy(22,11);
	  cout<<"2. Izquierda";
	  gotoxy(22,13);
	  cout<<"3. Derecha";
	  gotoxy(20,15);
	  cout<<"Posici¢n :         ";
	  cin>>res;
	  posicion=atoi(res);//evita error del usuario
	    if(posicion>3)//retorna al menu principal
	    {
	    clrscr();
	    break;
	    }
	 if(posicion==1)
	 pacho<<"<p align=\"center\">";//alineacion de boton centrado
	 if(posicion==2)
	 pacho<<"<p align=\"left\">";//alineacion de boton centrado
	 if(posicion==3)
	 pacho<<"<p align=\"right\">";//alineacion de boton centrado
	 pacho<<"<input type=button value=\"" ; //muestra el boton con su valor respectivo
	 gotoxy(20,16);
	 cout<<"Texto del bot¢n :  " ;
	 gets(texto);
	 pacho<<texto;
	 pacho<<"\">";
	 clrscr();
	 break;

/***********************introduccion de un campo de contrase¤a****************/
  //inserta campo de contrase¤a
  //<input type="password" name="nombre">

  case 5:
	 cuadro(8,30,14,44,BLUE);
	 gotoxy(22,9);
	 cout<<"1. Centrado";
	 gotoxy(22,11);
	 cout<<"2. Izquierda";
	 gotoxy(22,13);
	 cout<<"3. Derecha";
	 gotoxy(20,17);
	 cout<<"Posici¢n :         ";
	 cin>>res;

	 posicion=atoi(res);
	   if(posicion>3)
	   {
	   clrscr();
	   break;
	   }
	 if(posicion==1)
	 pacho<<"<p align=\"center\">";//centrado
	 if(posicion==2)
	 pacho<<"<p align=\"left\">";//izquierdo
	 if(posicion==3)
	 pacho<<"<p align=\"right\">";//derecho
	 pacho<<"<input type=\"password\"name=\"nombre\">" ;//validacion del password
	 clrscr();
	 break;

/**************valor o texto del boton centrado*******************************/
   //<h2 align="center">texto</h2>

  case 6:
	 pacho<<"<h2 align=\"center\">" ;//centrado del texto o valor del boton
	 gotoxy(20,12);
	 cout<<"Titulo  :  " ;
	 gets(texto);
	 pacho<<texto;
	 pacho<<"</h2>";
	 clrscr();
	 break;

/******************trabajo de hipervinculo************************************/


  case 7:
	 cuadro(8,30,14,44,BLUE);
	 gotoxy(22,9);
	 cout<<"1. Web";
	 gotoxy(22,11);
	 cout<<"2. Email";
	 gotoxy(22,16);
	 cout<<"Tipo de Hiperv¡nculo :  ";
	 cin>>res;
	 posicion=atoi(res);
	   if(posicion>2)
	   {
	   clrscr();
	   break;
	   }

/***********************vinculacion a otra pagina web*************************/
	//<a href="htpp://nomb.pagina">texto en pantalla </a>

	if(posicion==1)
	{
	pacho<<"<p> <a href=\"htpp:// ";//protocolo de direccion
	gotoxy(20,17);
	cout<<"Nombre de P gina   :";//ingresa direccion de la pagina normalmente
	gets(texto);
	pacho<<texto;
	pacho<<"\">";
	gotoxy(20,18);
	cout<<"Texto en Pantalla  :";
	gets(texto);
	pacho<<texto;
	pacho<<"</a> </p>";
	clrscr();
	break;
	}

/***********************Trabajo con outlook (correo)**************************/
	//<a href="mailto:correo">texto en pantalla</a>

	if(posicion==2)
	{
	pacho<<"<p> <a href=\"mailto:";//dirige al correo electronico
	gotoxy(20,17);
	cout<<"Correo electr¢nico :   ";
	gets(texto);
	pacho<<texto;
	pacho<<"\">";
	gotoxy(20,18);
	cout<<"Texto en pantalla :    ";
	gets (texto);
	pacho<<texto;
	pacho<<"</a> </p>";
	clrscr();
	break;
	}
/**********************case para salir,aqui cierro el objeto******************/

  case 8:
	 pacho<<"</body>";
	 pacho<<"</html>";
	 salir=1;//validacion de la variable salir para salida
	 pacho.close();//cierro totalmente el objeto pacho
	 break;
     }//switch case

   }while(salir!=1);//si salir no cambia de valor inicial (salir=0) el programa se ejecuta

 return 0;
}
/*-------------------------fin de funcion etiquetas--------------------------*/


/*-------------------------inicio del programa------------------------------*/
int main()
{
clrscr();
textmode(BW80);//modo de texto
cout<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<"                   FRANCISCO JAVIER GUTIERREZ GUTIERREZ "<<endl<<endl;
cout<<"                  PROGRAMA DE EDICION Y DISE¥O DE PAGINAS "<<endl<<endl<<endl<<endl;
cout<<"                        OPRIMA ENTER PARA INICIAR"<<endl;
cuadro(5,12,15,64,BLUE);
getch();
etiquetas();
return 0;
}
/*--------------------------------fin del programa----------------------------*/








