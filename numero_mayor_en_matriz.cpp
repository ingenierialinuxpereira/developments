#include <iostream>
using namespace std;

int main()
{
    int i, n;
    double arr[100];

    cout << "Ingrese cantidad deseada de elementos (de 1 a 100): ";
    cin >> n;
    cout << endl;

    for(i = 0; i < n; ++i)
    {
       cout << "Ingrese un elemento numerico " << i + 1 << " : ";
       cin >> arr[i];
    }

    // Aqui se declara un loop patra almacenar el elemento mayor an arr[0]
    for(i = 1;i < n; ++i)
    {
       // Si desea puede Cambiar < a > para encontrar el elemento menor
       if(arr[0] < arr[i])
           arr[0] = arr[i];
    }
    cout << "El elemento mayor es = " << arr[0];

    return 0;
}

