#include<a:raton.h>
#include<grafico.h>
#include<dos.h>
#include<process.h>
/*****************************************************/
void botoncrea(int xi,int yi,int color,char *texto);
void dibujarbotones();
void click();                                     //declaracion de funciones del codigo entero
void leerboton();

/******************************************************/
int main()
{
iniciarmodografico();
mostrarraton();
moverraton(0,0);
dibujarbotones();                      //principal con llamados a todo el codigo
click();
cerrarmodografico();
return 0;
}
/****************************************************/
void dibujarbotones()
{
//cleardevice();
botoncrea(280,100,3,"Aceptar");                       //llamado de los tres botones en pantalla
botoncrea(280,150,3,"Salir");
botoncrea(280,200,3,"Borrar");
}
/****************************************************/
void botoncrea(int xi,int yi,int color,char *texto)
{
setfillstyle(1,color);                                //dibujado del boton
bar3d(xi,yi,xi+90,yi+25,5,1);
outtextxy(xi+20,yi+10,texto);
}
/****************************************************/
void click()//funcion que valida el clicka y poner sobre el boton
{
do
{
leerraton(); //llamado de funcion que pone el raton en pantalla
/****************************************************/
if(x>=280 && x<=370 && y>=100 && y<=125 && boton==0)
botoncrea(280,100,2,"Aceptar");
else
botoncrea(280,100,3,"Aceptar");
if(x>=280 &&x<=370 && y>=200 && y<=225 && boton==0)   //valida cambio de color cuando el raton esta sobre el boton
botoncrea(280,200,2,"Salir");
else
botoncrea(280,200,3,"Salir");
if(x>=280 && x<=370 && y>=150 && y<=175 && boton==0)

botoncrea(280,150,2,"Borrar");
else
botoncrea(280,150,3,"Borrar");
/***************************************************/

/***************************************************/
if(x>=280 && x<=370 && y>=100 && y<=125 && boton==1)
{
outtextxy(400,400,"haz hecho click");
}
if(x>=280 &&x<=370 && y>=150 && y<=175 && boton==1)
{
//cleardevice();
dibujarbotones();                                     //condiciones que validan el click y funcion de cada boton
}
if(x>=280 && x<=370 && y>=200 && y<=225 && boton==1)
{
cerrarmodografico();
exit(1);
}
}while(1);
}
/****************************************************/