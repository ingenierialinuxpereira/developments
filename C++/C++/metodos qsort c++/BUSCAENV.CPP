 #include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>
 int compare(int *x, int *y)
 {
    return( *x - *y );
 }

 int main(void)
 {
    char array[5][5],encontrar[5];
    size_t nelem = 5;
    int i;
    int *result;

    for(i=1;i<=5;i++)
    {
    printf("Ingrese datos:");
    scanf("%s",&array[i]);
    }
    printf("Ingrese dato abuscar:");
    scanf("%s",&encontrar);
    //puntero que almacena instruccion lfind con tres parametros
    //el primero es:variable que almacena el dato a buscar
    //el segundo es:el arreglo que lo contiene
    //el tercero el tama¤o del puntero que limita el numero de entradas al arreglo
    //el cuarto es el tama¤o en bytes del arreglo
    result = (int *) lfind(&encontrar, array, &nelem,
	      sizeof(int), (int(*)(const void *,const void *))compare);
    if (result)
       printf("Componente %s found\n",encontrar);
    else
       printf("Componente %s not found\n",encontrar);
    getch();
    return 0;
 }

