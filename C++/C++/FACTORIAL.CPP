{\rtf1\ansi\ansicpg1252\deff0\deflang3082{\fonttbl{\f0\fswiss\fcharset0 Courier New;}{\f1\fswiss\fcharset0 Arial;}}
\viewkind4\uc1\pard\tx0\tx959\tx1918\tx2877\tx3836\tx4795\tx5754\tx6713\tx7672\tx8631\lang9226\f0\fs20 #include <stdio.h>\par
#include <conio.h>\par
int a[4][4], b[4][4],i,j,m,z,r[4][4];\par
main ()\par
\{\par
printf ("Programa que realiza la resta de dos matriz de 4x4\\n");\par
printf ("Inserta los valores de la matriz a:\\n");\par
for (i=0;i<4;i++)\par
\{\par
\tab for (j=0;j<4;j++)\par
\tab scanf ("%d", &a[i][j]);\par
\tab\}\par
printf ("Inserta los valores de la matriz b:\\n");\par
for (i=0;i<4;i++)\par
\tab\{\par
\tab for (j=0;j<4;j++)\par
\tab scanf ("%d", &b[i][j]);\par
\tab\}\par
for (m=0;m<4;m++)\{\par
for (i=0;i<4;i++)/*Operacion*/\par
\tab\{\par
\tab z=0;\par
\tab for (j=0;j<4;j++)\par
\tab\tab\{\par
\tab\tab z+=(a[m][j]*b[j][i]);\par
\tab\tab r[m][i]=z;\}\par
\tab\}\}\par
printf ("Matriz resultante:\\n");\par
for (m=0;m<4;m++)\par
\tab\{\par
\tab for (i=0;i<4;i++)\par
\tab printf ("%d\\n", r[m][i]);\par
\tab\}\par
getch ();\par
\}\par
\pard\lang3082\f1\par
}
 