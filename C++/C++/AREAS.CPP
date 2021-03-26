
#include<stdio.h>
#include<conio.h>

#define PI 3.1415926536

/************************************* PROTOTIPOS ********************************************/

void area_cuadrado (float lado);
void area_triangulo (float altura, float base);
void area_circulo(float radio);
void area_paralelogramo(float altura, float base);
void area_trapezoide (float altura);
void pausa();

/*************************************** MAIN ************************************************/

void main (void)
{
	int opcion=0;
	float lado=0, base=0, altura=0, radio=0, rdo=0;	
	do
	{
		system("cls");
		printf("\n MENU\n");
		printf(" 1. Area cuadrado.\n");
		printf(" 2. Area triangulo.\n");
		printf(" 3. Area circulo.\n");
		printf(" 4. Area paralelogramo.\n");
		printf(" 5. Area trapezoide.\n");
		printf("\n");
		printf(" 0. Salir");	
		printf("\n\n Elige una opcion: ");
		scanf("%d", &opcion);
		switch(opcion)
		{
			case 0:
				break;
			case 1:
				area_cuadrado(lado);
				break;
			case 2:
				area_triangulo(altura, base);
				break;
			case 3:
				area_circulo(radio);
				break;
			case 4:
				area_paralelogramo(altura, base);
				break;
			case 5:
				area_trapezoide(altura);
				break;
			default:
				printf("\n Opcion no valida.");
				pausa();
		}// switch
	}// do
	while(opcion !=0);	
}//end of main

void pausa()
// función que nos ayuda a parar el programa cuando lo necesitemos
{
	printf("\n\n\n\n Pulsa cualquier tecla... ");
	getch();
}//end of pausa

void area_cuadrado (float lado)
// función que pide por teclado el lado y calcula el área del cuadrado
{
	printf("\n Introduce el valor del lado: ");
	scanf("%f", &lado);
	printf("\n El area del cuadrado es:  %.2f", lado*lado);
	pausa();
}//end of area_cuadrado

void area_triangulo (float altura, float base)
// función que pide por teclado la altura y la base y calcula el área del triángulo
{
	printf("\n Introduce la altura: ");
	scanf("%f", &altura);
	printf("\n Introduce la base: ");
	scanf("%f", &base);
	printf("\n El area del triangulo es:  %.2f", base*altura/2);
	pausa();
}//end of area_triangulo


void area_circulo(float radio)
// función que pide por teclado el radio y calcula el área del círculo
{
	printf("\n Introduce el radio: ");
	scanf("%f", &radio);
	printf("\n El area del circulo es:  %.2f", PI*radio*radio);
	pausa();
}//end of area_circulo

void area_paralelogramo (float altura, float lado)
{
	printf("\n Introduce la altura: ");
	scanf("%f", &altura);
	printf("\n Introduce el lado: ");
	scanf("%f", &lado);
	printf("\n El area del paralelogramo es:  %.2f", altura*lado);
	pausa();
}//end of area_paralelogramo

void area_trapezoide (float altura)
{
	float l1=0, l2=0;
	printf("\n Introduce la altura: ");
	scanf("%f", &altura);
	printf("\n Introduce el lado menor: ");
	scanf("%f", &l1);
	printf("\n Introduce el lado mayor: ");
	scanf("%f", &l2);
	printf("\n El area del trapezoide es: %.2f", 0.5*(altura*(l1+l2)));
	pausa();
}//end of area_trapezoide




