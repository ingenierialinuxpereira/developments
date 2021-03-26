#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	string nombre1="prueba.txt";
	string linea;
    ofstream fichero("prueba.txt");
    fichero << "Esto es una linea" << endl;
    fichero << "Esto es otra";
    fichero << " y esto es continuacion de la anterior" << endl;
    fichero.close();

    cout<<"\nContenido del archivo:";
    cout<<"\n========= === ========\n\n";
    ifstream fichero1(nombre1.c_str());
    if( fichero1.fail() )
    {
        cout << "No existe el fichero!" << endl;
        exit(1);
    }
 
    while (! fichero1.eof()) 
    {
        getline(fichero1,linea);
        if (! fichero1.eof()) 
            cout <<" " << linea << endl;
    }
    fichero1.close();
    return 0;
}
