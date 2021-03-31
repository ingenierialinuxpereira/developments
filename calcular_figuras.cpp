#include <iostream>
#include <cstdlib>
//Francisco Gutierrez
using namespace std;
void pausa();
int main()
 
{
	float LadoA,LadoB,LadoC,LadoD,LadoE,LadoF,perimetro,lado,radio;
    bool flag=false;
    char tecla;
    do
 
    {
 
        system("cls");
        cin.clear();
        cout << "Calculo de perimetros" << endl;
        cout << "--------------------------" << endl << endl;
 
        cout << "\t1 .- TRIANGULO" << endl;
        cout << "\t2 .- CUADRADO" << endl;
        cout << "\t3 .- HEXAGONO" << endl;
        cout << "\t4 .- CIRCULO" << endl;
        cout << "\t5 .- Salir" << endl << endl;
 
        cout << "Elije una opcion: ";
 
        cin >> tecla;
 
		switch(tecla)
		{
 
			case '1':
				system("cls");
				cout << "CALCULO DEL PERIMETRO DE UN TRIANGULO\n";
				cout <<"\n  Longitud del lado A del triangulo: ";
				cin >> LadoA;
				cout <<"  Longitud del lado B del triangulo: ";
				cin >> LadoB;
				cout <<"  Longitud del lado C del triangulo: ";
				cin >> LadoC;
				perimetro =(LadoA+LadoB+LadoC);
				cout<<"\nPERIMETRO: "<<perimetro;
				printf("\n\n\n");
				pausa();
				break;
 
			case '2':
				system("cls");
				cout << "CALCULO DEL PERIMETRO DE UN CUADRADO\n";
				cout <<"\n  Longitud de un lado del cuadrado: ";
				cin >> lado;
				perimetro =(lado)*4;
				cout<<"\nPERIMETRO: "<<perimetro;
				printf("\n\n\n");
				pausa();
				break;
 
			case '3':
				system("cls");
				cout << "CALCULO DEL PERIMETRO DE UN HEXAGONO\n";
				cout <<"\n  Longitud lado A del hexagono: ";
				cin >> LadoA;
				cout <<"  Longitud lado B del hexagono: ";
				cin >> LadoB;
				cout <<"  Longitud lado C del hexagono: ";
				cin >> LadoC;
				cout <<"  Longitud lado D del hexagono: ";
				cin >> LadoD;
				cout <<"  Longitud lado E del hexagono: ";
				cin >> LadoE;
				cout <<"  Longitud lado F del hexagono: ";
				cin >> LadoF;
				perimetro =(LadoA+LadoB+LadoC+LadoD+LadoE+LadoF);
				cout<<"\nPERIMETRO: "<<perimetro;
				printf("\n\n\n");
				pausa();
				break;
 
			case '4':
				system("cls");
				cout << "CALCULO DEL PERIMETRO DE UN CIRCULO\n";
				cout <<"\n  Radio del circulo: ";
				cin >> radio;
				perimetro =(3.1416*2)*radio;
				cout<<"\nPERIMETRO: "<<perimetro;
				printf("\n\n\n");
				pausa();
				break;
 
			case '5':
				flag=true;
 
				//exit(1);
 
				break;
				default:
				system("cls");
				cout << "Opcion invalida.\a\n";
				pausa();
				break;
		}
 
    }while(flag!=true);
 
    return 0;
}
 
void pausa()
 
{
    cout << "Presionar ENTER para regresar al menu...";
    getwchar();
    getwchar();
}
