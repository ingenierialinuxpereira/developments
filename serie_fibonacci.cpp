#include <iostream>
using namespace std;

int main() {
    int n, t1 = 0, t2 = 1, siguienteTerm = 0;

    cout << "Ingrese el numero de iteraciones: ";
    cin >> n;

    cout << "La serie Fibonacci es: ";

    for (int i = 1; i <= n; ++i) {
        // imprime las dos primeras cantidades.
        if(i == 1) {
            cout << t1 << ", ";
            continue;
        }
        if(i == 2) {
            cout << t2 << ", ";
            continue;
        }
        siguienteTerm = t1 + t2;
        t1 = t2;
        t2 = siguienteTerm;
        
        cout << siguienteTerm << ", ";
    }
    return 0;
}
