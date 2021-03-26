#include <iostream>
using namespace std;

int main()
{
    int n;
    unsigned long long factorial = 1;

    cout << "Ingrese un numero entero positivo: ";
    cin >> n;

    if (n < 0)
        cout << "Error! El factorial de un numero negativo no existe.";
    else {
        for(int i = 1; i <=n; ++i) {
            factorial *= i;
        }
        cout << "Factorial de " << n << " = " << factorial;    
    }

    return 0;
}
