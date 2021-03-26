#include <iostream>
using namespace std;
int numempleados;
struct persona{
        char nombre[15];
        char apellido[15];
        int edad;
        char sexo[15];
        int telefono;
};

int main(){
	cout <<"Cuantos registros desea hacer?"<<endl;
    cin >> numempleados;
    cout <<"";
    persona amigo[numempleados];
    for (int i = 0; i <= numempleados-1; i++){
        cout <<"Nombre "<<i+1<<":";
        cin >> amigo[i].nombre;

        cout <<"\nApellido "<<i+1<<":";
        cin >> amigo[i].apellido;

        cout <<"\nEdad de "<<i+1<<":";
        cin >> amigo[i].edad;

        cout <<"\nSexo de "<<i+1<<":";
        cin >> amigo[i].sexo;

        cout <<"\nTelefono de "<<i+1<<":";
        cin >> amigo[i].telefono;
        
        cout <<endl;
    }

    cout<<"El registro de personas que se introdujeron es: \n\n";
    cout<<endl;

    for (int i = 0; i <=numempleados-1; i++){
    	
        cout<<"\nNombre:"<<amigo[i].nombre;
        cout<<"\nApellido:"<<amigo[i].apellido;
        cout<<"\nEdad:"<<amigo[i].edad;
        cout<<"\nSexo:"<<amigo[i].sexo;
        cout<<"\nTelefono:"<<amigo[i].telefono<<"\n";
        cout<<"\n<<>>\n\n";
        
   }
   
   return 0;
}
