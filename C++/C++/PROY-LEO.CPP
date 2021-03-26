#include<conio.h>
#include<iostream.h>
#include<alloc.h>
#include<stdio.h>

class rectangulo//clase de el rectangulo
{
 public:                                /*definicion y prototipo delas funciones de a la clase */
 int l1,l2;
 int area (int,int);
 int perimetro(int,int);
 int dibujar(int,int);
 int validar(int,int);
};

class elipse
{
 public:
 int r1,r2;
 int area (int,int);
 int perimetro(int,int);
 int dibujar(int,int);
 int tipo(int,int);
};

class triangulo
{
 public:
 int l1,l2,l3;
 int area (int,int);
 int perimetro(int,int);
 int dibujar(int,int);
 int tipo(int,int);
 int hallaraltura(int,int);
};

class trapecio
{
 public:
 int b1,b2,h;
 int area (int,int);
 int perimetro(int,int);
 int dibujar(int,int);
};

class poligono
{
 public:
 int lado;
 int area (int);
 int perimetro(int);
 int dibujar(int);
 int nombre(int);
};









