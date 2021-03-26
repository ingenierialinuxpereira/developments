#include <iostream>
using namespace std;

int main()
{
    int a[10][10], b[10][10], mult[10][10], r1, c1, r2, c2, i, j, k;

    cout << "Ingrese cantidad de columnas y filas de primera matriz: ";
    cin >> r1 >> c1;
    cout << "Ingrese cantidad de columnas y filas de segunda matriz: ";
    cin >> r2 >> c2;

    // Si columnas de primera matriz no son iguales en cantidad a filas de segunda matriz,
    // se solicita que el usuario rectifique e ingrese de nuevo.
    while (c1!=r2)
    {
        cout << "Error! columnas de primera matriz no son iguales en cantidad a filas de segunda matriz.";

    cout << "Ingrese cantidad de columnas y filas de primera matriz: ";
    cin >> r1 >> c1;
    cout << "Ingrese cantidad de columnas y filas de segunda matriz: ";
    cin >> r2 >> c2;
    }

    // Almacenando elementos de primera matriz.
    cout << endl << "Ingrese elementos de matriz 1:" << endl;
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c1; ++j)
        {
            cout << "Ingrese elemento a" << i + 1 << j + 1 << " : ";
            cin >> a[i][j];
        }

    // Almacenando elementos de segunda matriz.
    cout << endl << "Ingrese elementos de matriz 2:" << endl;
    for(i = 0; i < r2; ++i)
        for(j = 0; j < c2; ++j)
        {
            cout << "Ingrese elemento b" << i + 1 << j + 1 << " : ";
            cin >> b[i][j];
        }

    // Inicializando elementos de matriz multidimensional a 0.
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
        {
            mult[i][j]=0;
        }

    // Multilpicando matriz a and b y ordenando en arreglo multidimensional.
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
            for(k = 0; k < c1; ++k)
            {
                mult[i][j] += a[i][k] * b[k][j];
            }

    // Resultado de multiplicacion de las dos matrices.
    cout << endl << "Matriz resultante: " << endl;
    for(i = 0; i < r1; ++i)
    for(j = 0; j < c2; ++j)
    {
        cout << " " << mult[i][j];
        if(j == c2-1)
            cout << endl;
    }

    return 0;
}
