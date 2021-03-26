#include <iostream>
using namespace std;

int main()
{
    int espacios, filas;

    cout <<"Numero de Filas: ";
    cin >> filas;

    for(int i = 1, k = 0; i <= filas; ++i, k = 0)
    {
        for(espacios = 1; espacios <= filas-i; ++espacios)
        {
            cout <<"  ";
        }

        while(k != 2*i-1)
        {
            cout << "* ";
            ++k;
        }
        cout << endl;
    }    
    return 0;
}
