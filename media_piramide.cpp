#include <iostream>
using namespace std;

int main()
{
    int filas;

    cout << "Numero de Filas: ";
    cin >> filas;

    for(int i = 1; i <= filas; ++i)
    {
        for(int j = 1; j <= i; ++j)
        {
            cout << "* ";
        }
        cout << "\n";
    }
    return 0;
}
