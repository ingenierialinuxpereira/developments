#include <stdio.h>
#include <conio.h>
int a[4][4], b[4][4],i,j,m,z,r[4][4];
main ()
{
printf ("Programa que realiza la resta de dos matriz de 4x4\n");
printf ("Inserta los valores de la matriz a:\n");
for (i=0;i<4;i++)
{
	for (j=0;j<4;j++)
	scanf ("%d", &a[i][j]);
	}
printf ("Inserta los valores de la matriz b:\n");
for (i=0;i<4;i++)
	{
	for (j=0;j<4;j++)
	scanf ("%d", &b[i][j]);
	}
for (m=0;m<4;m++){
for (i=0;i<4;i++)/*Operacion*/
	{
	z=0;
	for (j=0;j<4;j++)
		{
		z+=(a[m][j]*b[j][i]);
		r[m][i]=z;}
	}}
printf ("Matriz resultante:\n");
for (m=0;m<4;m++)
	{
	for (i=0;i<4;i++)
	printf ("%d\n", r[m][i]);
	}
getch ();
}
