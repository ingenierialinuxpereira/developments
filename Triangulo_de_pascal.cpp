#include <iostream>
using namespace std;

int main()
{
    int filas, coeficiente = 1;

    cout << "Ingrese cantidad de filas: ";
    cin >> filas;

    for(int i = 0; i < filas; i++)
    {
        for(int espacio = 1; espacio <= filas-i; espacio++)
            cout <<"  ";

        for(int j = 0; j <= i; j++)
        {
            if (j == 0 || i == 0)
                coeficiente = 1;
            else
                coeficiente = coeficiente*(i-j+1)/j;

            cout << coeficiente << "   ";
        }
        cout << endl;
    }

    return 0;
}
