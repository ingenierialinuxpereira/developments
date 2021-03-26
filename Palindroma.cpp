#include <iostream>
using namespace std;

int main()
{
     int n, num, digit, rev = 0;

     cout << "Ingrese un numero positivo: ";
     cin >> num;

     n = num;

     do
     {
         digit = num % 10;
         rev = (rev * 10) + digit;
         num = num / 10;
     } while (num != 0);

     cout << " La inversion del numero es: " << rev << endl;

     if (n == rev)
         cout << " El numero es palindromo.";
     else
         cout << " El numero no es palindromo.";

    return 0;
}
