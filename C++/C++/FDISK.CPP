#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <string.h>
#include <stdlib.h>

#define disco 20000
#define ESC 27

struct fat{
	char tipopart; //[1];
	char estado;
	char unidad_logica;
	char etiqueta;
	char sistema;
	int numero;
	float capacidad;
};
	struct fat part[10],*apunt_fat;
	int fatty;

int inicio();
void menu();
void fin(void);
void crear(void);
void activar(void);
void eliminar (struct fat *apun_crea_fatty);
void eliminar_pri(struct fat *apunt_crea_fatty);
void eliminar_ext(struct fat *apunt_fatty);
void eliminar_logica(struct fat *apunt_fatty);
void consultar(struct fat *apunt_fatty, char cual);
void consulta_ext(struct fat *apunt_fatty,char cual);
void crea_pri(struct fat *apunt_fatty);
void crea_ext(struct fat *apunt_fatty);
void crea_log(struct fat *apunt_fatty);
int check_fat(struct fat *apunt_fatty, char cual);
int check_val(char strval[5],int disponible);

main()
{
	apunt_fat=&part[0];
	char opcion;
	fatty=inicio();
	opcion='1';
	menu();
	while (opcion!=ESC)
	{
		menu();
		gotoxy(50,20);opcion=getche();
		switch(opcion){
			case '1':crear();
				break;
			case '2':activar();
				break;
			case '3':apunt_fat=&part[0];
				eliminar(apunt_fat);
				break;
			case '4':apunt_fat=&part[0];
				consultar(apunt_fat,'C');
				break;
//			case '5':cout<<"opcion 1";
//				break;
			default :gotoxy(30,24);cout<<"Entrada no V lida 1-5";
				break;
			}
	//menu();
	}
	return(0);
}



void menu()
{
clrscr();
gotoxy(30,1);cout<<"Microsoft Windows 98";
gotoxy(25,2);cout<<"Programa de instalaci¢n de disco duro";
gotoxy(20,3);cout<<"(C)Copyright Microsoft Corp. 1983 - 1998";
gotoxy(30,5);cout<<"Opciones de FDISK";
gotoxy(5,7);cout<<"Unidad actual de disco duro: 1";
gotoxy(5,9);cout<<"Elija una de las siguientes opciones:";
gotoxy(5,11);cout<<"1. Crear una partici¢n o una unidad l¢gica de DOS";
gotoxy(5,12);cout<<"2. Establecer la partici¢n activa";
gotoxy(5,13);cout<<"3. Eliminar una partici¢n o unidad l¢gica de DOS";
gotoxy(5,14);cout<<"4. Mostrar informaci¢n sobre la partici¢n";
gotoxy(15,20);cout<<"Escriba el n£mero de su elecci¢n: [ ]";
}

int inicio()

{
	char sel;
	int fatty;
	clrscr();
	gotoxy(5,5);
	cout<<"Su PC tiene un disco mayor que 512 MB. Esta versi¢n de Windows incluye";
	gotoxy(5,6);
	cout<<"compatibilidad mejorada con discos grandes, lo que permite un uso m s";
	gotoxy(5,7);
	cout<<"eficiente del espacio libre en unidades de gran tama¤o y el que los discos";
	gotoxy(5,8);
	cout<<"de m s de 2 GB sean formateados como una £nica unidad.";
	gotoxy(5,11);
	cout<<"IMPORTANTE: si activa la compatibilidad con discos grandes y crea nuevas";
	gotoxy(5,12);
	cout<<"unidades en este disco, no podr  tener acceso a las nuevas unidades usando";
	gotoxy(5,13);
	cout<<"otros sistemas operativos, incluyendo algunas versiones de Windows 95 y";
	gotoxy(5,14);
	cout<<"versiones anteriores de Windows y MS-DOS. Adem s, utilidades de disco que";
	gotoxy(5,15);
	cout<<"no fueron dise¤adas para FAT32 no podr n trabajar con";
	gotoxy(5,16);
	cout<<"este disco. Si necesita tener acceso a este disco con otros sistemas";
	gotoxy(5,17);
	cout<<"operativos o con utilidades de disco antiguas, no la active.";
	gotoxy(5,19);
	cout<<"Desea activar la compatibilidad con discos grandes (S/N)...........? [ ]";
	sel= ' ';
	while (sel!='s'&&sel!='S'&&sel!='n'&&sel!='N')
	{
		gotoxy(10,24),cout<<"Entrada no V lida S o N";
		gotoxy(75,19);
		sel=getche();
	}
	if (sel=='S'||sel=='s')
		fatty=1;
	else
		fatty=2;
	return(fatty);
}

void crear (void)
{
	int prima,extended;
	char opc;
	opc='1';
	while (opc!=ESC)
	{
		clrscr();
		gotoxy(20,5);cout<<"Crear una partici¢n o una unidad l¢gica de DOS";
		gotoxy(5,7);cout<<"Unidad actual de disco duro: 1";
		gotoxy(5,9);cout<<"Elija una de las siguientes opciones:";
		gotoxy(5,11);cout<<"1. Crear una partici¢n primaria de DOS";
		gotoxy(5,12);cout<<"2. Crear una partici¢n extendida de DOS";
		gotoxy(5,13);cout<<"3. Crear unidades l¢gicas de DOS en la partici¢n extendida de DOS";
		gotoxy(15,20);cout<<"Escriba el n£mero de su elecci¢n: [ ]";
		gotoxy(50,20);opc=getche();
		switch(opc)
		{
			case '1':apunt_fat=&part[0];
				prima=check_fat(apunt_fat,'P');
				if (prima==0)
				{
					apunt_fat=&part[0];
					crea_pri(apunt_fat);//aqui debe llamarse la funcion crear_pri
				}
				else
				{
					gotoxy(20,20);cout<<"Particion Primaria Ya existe";
					getchar();
				}
				break;
			case '2':apunt_fat=&part[0];
				prima=check_fat(apunt_fat,'P');
				if (prima==1)
				{
					apunt_fat=&part[0];
					extended=check_fat(apunt_fat,'E');
					if (extended==0)
					{
						apunt_fat=&part[0];
						crea_ext(apunt_fat);
					}
					else
					{
						gotoxy(20,24);cout<<"Ya existen particiones extendidas";
						getchar();
					}
				}
				break;
			case '3':apunt_fat=&part[0];
				prima=check_fat(apunt_fat,'P');
				if (prima==1)
				{
				    apunt_fat=&part[0];
				    extended=check_fat(apunt_fat,'E');
					if (extended==1)
					{
						apunt_fat=&part[1];
						crea_log(apunt_fat);
					}
					else
					{
						gotoxy(20,24);cout<<"No se han definido particiones extendidas de DOS";
						getchar();
					}
				}
				break;
			default:break;
		}
	}
}

void activar (void)
{
int parti;
parti=0;
clrscr();
apunt_fat=&part[0];
consultar(apunt_fat,'A');
gotoxy(5,22);cout<<"Especifique el n£mero de particion que desea activar..................[ ] ";
while (parti<1 || parti>2)
{
	gotoxy(76,22);cin>>parti;
	if (parti!=1)
	{
		gotoxy(5,19);cout<<"Solo puede activarse una particion primaria";
		getchar();
	}
	else
		apunt_fat->estado='A';
}
fin();
}

void eliminar(struct fat *apun_crea_fatty)
{
char resp;
while (resp!=ESC)
{
	clrscr();
	gotoxy(20,5);cout<<"Eliminar una partici¢n o una unidad l¢gica de DOS";
	gotoxy(5,7);cout<<"Unidad actual de disco duro: 1";
	gotoxy(5,9);cout<<"Elija una de las siguientes opciones:";
	gotoxy(5,11);cout<<"1.  Eliminar una partici¢n primaria de DOS";
	gotoxy(5,12);cout<<"2.  Eliminar una partici¢n extendida de DOS";
	gotoxy(5,13);cout<<"3.  Eliminar unidades l¢gicas en la partici¢n extendida de DOS";
	gotoxy(5,14);cout<<"4.  Eliminar una partici¢n que no es de DOS";
	gotoxy(5,18);cout<<"Escriba el n£mero de su elecci¢n: [ ]";
	gotoxy(5,24);cout<<"Presione Esc para volver a las opciones de FDISK";
	gotoxy(40,18);resp=getche();
	switch (resp)
	{
	case '1': apun_crea_fatty=&part[0];
		eliminar_pri(apun_crea_fatty);
		break;
	case '2': apun_crea_fatty=&part[0];
		eliminar_ext(apun_crea_fatty);
		break;
	case '3': apun_crea_fatty=&part[0];
		eliminar_logica(apun_crea_fatty);
		break;
//	case 4:break;
	default:break;
	}
}
return;
//getchar();
}

void eliminar_pri(struct fat *apun_crea_fatty)
{
int sw;
char resp;
clrscr();
//consultar(apun_crea_fatty,'E');
sw=check_fat(apun_crea_fatty,'E');
if (sw==1)
{
	gotoxy(5,22);cout<<"No se puede eliminar la unidad primaria si existen particiones extendidas";
	getche();
}
else
{
	sw=check_fat(apun_crea_fatty,'P');
	if (sw==1)
	{
		gotoxy(15,5);cout<<"Eliminar las unidades primarias de DOS";
		gotoxy(5,19);cout<<"ADVERTENCIA: los datos en la unidad de DOS eliminada se perder n.";
		gotoxy(5,20);cout<<"Qu‚ unidad desea eliminar..........................? [ ]";
		gotoxy(59,20);resp=getche();
		if(resp=='s' || resp=='S')
		{
			gotoxy(5,20);cout<<"Partici¢n primaria eliminada";
			apun_crea_fatty->tipopart=' ';
			apun_crea_fatty->numero=0;
			apun_crea_fatty->unidad_logica=' ';
			apun_crea_fatty->sistema=' ';
			apun_crea_fatty->estado=' ';
			apun_crea_fatty->capacidad=0;
		}
	}
}
//getchar();
}


void eliminar_ext (struct fat *apun_crea_fatty)
{
int sw;
char resp;
clrscr();
consultar(apun_crea_fatty,'E');
sw=check_fat(apun_crea_fatty,'U');
if (sw==1)
{
	gotoxy(5,22);cout<<"No se puede eliminar la unidad extendidad si existen unidades l¢gicas";
	getche();
}
else
{
	gotoxy(15,5);cout<<"Eliminar las unidades l¢gicas en la partici¢n extendida de DOS";
	gotoxy(5,19);cout<<"ADVERTENCIA: los datos en la unidad l¢gica de DOS eliminada se perder n.";
	gotoxy(5,20);cout<<"Esta seguro que desea eliminarla.H..................? [ ]";
	gotoxy(59,20);cin>>resp;
	if(resp=='s'||resp=='S')
	{
		apun_crea_fatty=&part[1];
		apun_crea_fatty->tipopart=' ';
		apun_crea_fatty->numero=0;
		apun_crea_fatty->unidad_logica=' ';
		apun_crea_fatty->sistema=' ';
		apun_crea_fatty->estado=' ';
		apun_crea_fatty->capacidad=0;
	}
}
return;
}

void eliminar_logica (struct fat *apun_crea_fatty)
{
char resp,pbor;
char volumen[10];
//clrscr();
apun_crea_fatty=&part[2];
consulta_ext(apun_crea_fatty,'E');
gotoxy(15,5);cout<<"Eliminar las unidades l¢gicas en la partici¢n extendida de DOS";
gotoxy(5,19);cout<<"ADVERTENCIA: los datos en la unidad lógica de DOS eliminada se perderán.";
gotoxy(5,20);cout<<"Qu‚ unidad desea eliminar..........................? [ ]";
gotoxy(59,20);cin>>pbor;
if(pbor>='D')
{
	gotoxy(5,21);cout<<"Nombre del Volumen.....................[               ]";
	gotoxy(45,21);cin>>volumen;
	gotoxy(5,22);cout<<"Toda la informacion de la particion se predera S/N   [ ]";
	gotoxy(59,22);cin>>resp;
	if (resp=='S' || resp=='S')
	{
		for(int i=0;i<7;i++)
		{
		 if(apun_crea_fatty->unidad_logica==pbor)
		 {
			apun_crea_fatty->tipopart=' ';
			apun_crea_fatty->estado=' ';
			apun_crea_fatty->unidad_logica=' ';
			apun_crea_fatty->etiqueta=' ';
			apun_crea_fatty->sistema=' ';
			apun_crea_fatty->numero=0;
			apun_crea_fatty->capacidad=0;
		 }
		 apun_crea_fatty++;
		}
		apun_crea_fatty=&part[2];
	}
}
}

void consultar (struct fat *apun_crea_fatty, char cual)
{
int fila=10,sw=0;
clrscr();
if (cual=='E') { gotoxy(20,5);cout<<"Eliminar Particion de DOS  "; }
if (cual=='A') { gotoxy(20,5);cout<<"Activar particion de DOS   "; }
if (cual=='C') { gotoxy(20,5);cout<<"Consulta partici¢nes de DOS"; }
gotoxy(5,7);cout<<"Unidad actual de disco duro: 1";
gotoxy(5,9);cout<<"Partici¢n  Estado   Tipo    Etiqueta vol.   MB     Sistema      Uso";
gotoxy(5,22);cout<<"Espacio total en disco:       MB (1 MB = 1048576 bytes)";
gotoxy(5,24);cout<<"Presione Esc para volver a las opciones de FDISK";
gotoxy(29,22);cout<<disco;
for (int i=0;i<10;i++)
{
	if (apun_crea_fatty->numero>0)
	{
		if (apun_crea_fatty->estado==' ' && sw==0)
		sw=1;
		gotoxy(8,fila);cout<<apun_crea_fatty->numero;
		gotoxy(9,fila);cout<<apun_crea_fatty->unidad_logica;
		gotoxy(18,fila);cout<<apun_crea_fatty->estado;
		gotoxy(26,fila);cout<<apun_crea_fatty->tipopart;
		gotoxy(48,fila);cout<<apun_crea_fatty->capacidad;
		gotoxy(55,fila);cout<<apun_crea_fatty->sistema;
		gotoxy(69,fila);cout<<(apun_crea_fatty->capacidad/disco)*100<<'%';
	}
	fila++;
	apun_crea_fatty++;
}
apun_crea_fatty=&part[0];
sw=check_fat(apun_crea_fatty,'U');
if (sw==1 && cual=='C')
{
	apun_crea_fatty=&part[1];
	consulta_ext(apun_crea_fatty,'C');
}
/*if (sw==1)
{
	gotoxy(5,19);cout<<"ADVERTENCIA: No se han definifo particiones activas.";
	gotoxy(5,20);cout<<"necesitar  una partici¢n activa para iniciar el sistema";
	gotoxy(5,21);cout<<"correctamente";

} */
if (cual=='C')
{
	gotoxy(70,22);getche();
}
return;
}


void consulta_ext(struct fat *apun_crea_fatty,char cual)
{
char resp;
float disponible;
int fil=8;
apun_crea_fatty=&part[1];
disponible=apun_crea_fatty->capacidad;
if (cual!='E' && cual!='e')
{
	gotoxy(10,18);cout<<"La partici¢n extendida contiene unidades l¢gicas de DOS.";
	gotoxy(10,19);cout<<"Desea ver la informaci¢n de la unidad l¢gica (S/N)......?[ ]";
	gotoxy(68,19);cin>>resp;
}
if (resp=='s' || resp=='S'|| cual=='E' || cual=='e')
{
	clrscr();
	gotoxy(20,5);cout<<"Mostrar informaci¢n de la unidad l¢gica de DOS";
	gotoxy(5,7);cout<<"Und Etiqueta vol.   MB   Sistema    Uso";
	gotoxy(5,24);cout<<"Presione Esc para volver a las opciones de FDISK";
	gotoxy(5,14);cout<<"Tama¤o de la partici¢n extendida de DOS:       MB (1 MB = 1048576 bytes)";
	gotoxy(45,14);cout<<disponible;
	for(int i=1;i<10;i++)
	{
		if (apun_crea_fatty->tipopart=='U')
		{
			gotoxy(5,fil);cout<<apun_crea_fatty->unidad_logica;
			gotoxy(24,fil);cout<<apun_crea_fatty->capacidad;
			gotoxy(41,fil);cout<<((apun_crea_fatty->capacidad/disponible)*100)<<'%';
			fil++;
		}
		apun_crea_fatty++;
	}
}
}


void crea_pri(struct fat *apun_crea_fatty)
{
int disponible;
char resp,strval[5];
apun_crea_fatty->tipopart='P';
apun_crea_fatty->numero=1;
apun_crea_fatty->unidad_logica='C';
apun_crea_fatty->sistema='UN';
disponible=disco;
clrscr();
gotoxy(20,5);cout<<"Crear una partici¢n primaria de DOS";
gotoxy(5,9);cout<<"Desea Utilizar el tama¤o m ximo disponible y activar la partici¢n..[ ]";
gotoxy(73,9);resp=getche();
if (resp=='s'||resp=='S')
{
	apun_crea_fatty->estado='A';
	apun_crea_fatty->capacidad=disco;
	fin();
}
else
{
	gotoxy(5,9);cout<<"Seleccione la capacidad de la particion % o MB                          ";
	//apun_crea_fatty->capacidad=0;
	while (apun_crea_fatty->capacidad<=0 || apun_crea_fatty->capacidad>20000)
	{
		gotoxy(55,9);cin>>strval;
		apun_crea_fatty->capacidad=check_val(strval,disponible);
		if(apun_crea_fatty->capacidad<=0 || apun_crea_fatty->capacidad>20000)
		{
			gotoxy(15,20);cout<<"Tama¤o particion excede el espacio disponible";
		}
		else
		{
			gotoxy(10,22);cout<<"ADVERTENCIA: No se han definifo particiones activas.";
			gotoxy(10,23);cout<<"necesitar  una partici¢n activa para iniciar el sistema";
			gotoxy(10,24);cout<<"correctamente";
		}
	}
	apun_crea_fatty++;
}
}

void crea_ext(struct fat *apun_crea_fatty)
{
float disponible=0;
char strval[5];
disponible=disco-apun_crea_fatty->capacidad;
clrscr();
gotoxy(20,5);cout<<"Crear una partici¢n extendidad de DOS";
gotoxy(5,7);cout<<"Unidad actual de disco duro: 1";
gotoxy(5,9);cout<<"Partici¢n  Estado   Tipo    Etiqueta vol.   MB     Sistema      Uso";
gotoxy(5,18);cout<<"Espacio total en disco:       MB (1 MB = 1048576 bytes)";
gotoxy(5,24);cout<<"Presione Esc para continuar";
gotoxy(5,19);cout<<"M ximo espacio disponible para la partici¢n:       MB ( 69% )";
gotoxy(5,21);cout<<"Escriba el tama¤o de la partici¢n en MB o porcentaje de espacio en disco (%)";
gotoxy(5,22);cout<<"crear una partici¢n extendida de DOS..........................: [22246]";
gotoxy(5,24);cout<<"Presione Esc para volver a las opciones de FDISK";
gotoxy(29,18);cout<<disco;
gotoxy(50,19);cout<<disco-apun_crea_fatty->capacidad;
gotoxy(60,19);cout<<apun_crea_fatty->capacidad/disco*100;
gotoxy(8,10);cout<<apun_crea_fatty->numero;
gotoxy(9,10);cout<<apun_crea_fatty->unidad_logica;
gotoxy(18,10);cout<<apun_crea_fatty->estado;
gotoxy(26,10);cout<<apun_crea_fatty->tipopart;
gotoxy(48,10);cout<<apun_crea_fatty->capacidad;
gotoxy(55,10);cout<<apun_crea_fatty->sistema;
gotoxy(70,10);cout<<(apun_crea_fatty->capacidad/disco)*100<<'%';
gotoxy(70,22);cout<<"     ";
if (apun_crea_fatty->capacidad<disco)
{
	apun_crea_fatty++;
	apun_crea_fatty->capacidad=check_val(strval,disponible);
	while(apun_crea_fatty->capacidad<1 || apun_crea_fatty->capacidad>disponible)
	{
		gotoxy(70,22);cin>>strval;
		apun_crea_fatty->capacidad=check_val(strval,disponible);
	}
	apun_crea_fatty->numero=2;
	apun_crea_fatty->unidad_logica=' ';
	apun_crea_fatty->tipopart='E';
	apun_crea_fatty->sistema='U';
	gotoxy(8,11);cout<<apun_crea_fatty->numero;
	gotoxy(9,11);cout<<apun_crea_fatty->unidad_logica;
	gotoxy(26,11);cout<<apun_crea_fatty->tipopart;
	gotoxy(48,11);cout<<apun_crea_fatty->capacidad;
	gotoxy(55,11);cout<<apun_crea_fatty->sistema;
	gotoxy(70,11);cout<<(apun_crea_fatty->capacidad/disco)*100<<'%';
	gotoxy(5,18);cout<<"Se ha creado una partici¢n extendidad de DOS                               ";
	gotoxy(5,19);cout<<"                                                                            ";
	gotoxy(5,21);cout<<"                                                                            ";
	gotoxy(5,22);cout<<"                                                                            ";

}
else
{
	gotoxy(5,21);cout<<"Todo el espacio disponible en disco ha sido empleado                              ";
	gotoxy(5,22);cout<<"                                                                       ";
	gotoxy(5,24);cout<<"Presione Esc para volver a las opciones de FDISK";
}
getche();
}

void crea_log(struct fat *apun_crea_fatty)
{
float disponible,ext,nueva;
char strval[5];
int fil=8,un=68;
char t;
disponible=apun_crea_fatty->capacidad;
ext=apun_crea_fatty->capacidad;
apun_crea_fatty++;
clrscr();
gotoxy(8,5),cout<<"Crear unidades l¢gicas de DOS en la partici¢n extendida DOS";
gotoxy(5,7);cout<<"Und Etiqueta vol.   MB   Sistema    Uso";
gotoxy(8,14),cout<<"No se han definido unidades l¢gicas";
//gotoxy(8,16),cout<<"Comprobando la integridad de la unidad,  63% completado.";
gotoxy(8,18),cout<<"Tama¤o de la partici¢n extendida de DOS:       MB (1 MB = 1048576 bytes)";
gotoxy(8,19),cout<<"El m ximo espacio disponible para la unidad l¢gica es de       MB (100% )";
gotoxy(8,21),cout<<"Escriba el tama¤o de la unidad o el porcentaje de espacio (%)...[     ]";
gotoxy(8,24),cout<<"Presione Esc para volver a las opciones de FDISK";
while (disponible>0)
{
	gotoxy(50,18),cout<<ext; //aqui debe ir el tama¤o de la part ext
	gotoxy(66,19),cout<<disponible; //aqui el tama¤o actualizado diponlible para la part
	gotoxy(73,21);cin>>strval;
	nueva=check_val(strval,disponible);
	//gotoxy(73,21),cin>>nueva;
	disponible=disponible-nueva;
	if (disponible>=0)
	{
		apun_crea_fatty->capacidad=nueva;
		apun_crea_fatty->tipopart='U';
		//apun_crea_fatty->unidad_logica=un;
		gotoxy(5,fil);apun_crea_fatty->unidad_logica=putchar(un); //apun_crea_fatty->unidad_logica;;
		//t=getchar();
		//gotoxy(7,fil);cout<<t;
		gotoxy(24,fil);cout<<apun_crea_fatty->capacidad;
		gotoxy(41,fil);cout<<((apun_crea_fatty->capacidad/ext)*100)<<'%';
		fil++;un++;apun_crea_fatty++;
	}
	else
	{
		gotoxy(5,14),cout<<"Espacio insuficiente en particion";
		getchar();
		disponible=disponible+nueva;
	}
}
getchar();
}

int check_fat(struct fat *apunt_fat, char cual)
{
	int ok;
	ok=0;
	for (int i=0;i<10;i++)
	{
		if(cual=='p'||cual=='P')
		{
			if (apunt_fat->tipopart=='P')
			{
				ok=1;
				i=11;
			}
			else
				ok=0;
		}
		else
		{
			if (cual=='e'||cual=='E')
			{
				if (apunt_fat->tipopart=='E')
				{
					ok=1;
					i=11;
				}
				else
					ok=0;
			}
			else
			{
				if (apunt_fat->tipopart=='U')
				{
					ok=1;
					i=11;
				}
				else
					ok=0;
			}
		}
		apunt_fat++;
	}
	return(ok);
}

int check_val(char strval[5],int disponible)
{
   float size=0;
   int   i;
   char *ptr;
   ptr = strchr(strval,'%');
   size= atoi(strval);
   if(size>0 && disponible-size>=0)
   {
	if (ptr)
	{
		if(size<=100)
			size=disponible*size/100;
		else
			size=0;

	}
   }
   return size;
}

void fin(void)
{
clrscr();
gotoxy(10,12);cout<<"Ha de reiniciar su sistema para que sus cambios hagan efecto.";
gotoxy(10,13);cout<<"Cualquier unidad que haya creado o cambiado ha de ser formateada";
gotoxy(10,14);cout<<"ANTES de reiniciar.";
gotoxy(10,16);cout<<"Cierre Windows antes de reiniciar.";
gotoxy(10,24);cout<<"Presione Esc para salir de FDISK";
getche();
}
