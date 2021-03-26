/*Programa realizado por Juan Carlos Albarran Flores
Instituto Polit‚cnico Nacional
Escuela Superior de Ingenieria M‚canica y Electrica
Unidad Zacatenco
Ingenieria en Comunicaciones y Electronica*/
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void espera(float segundos){
	clock_t endwait;
	endwait = clock () + segundos * CLK_TCK ;
	while (clock() < endwait){}
	}
int main()
{
	textcolor(GREEN);
	textbackground(BLACK);
	clrscr();
	cout<<"root@matrix.com:$° \n\n";
	char MATRIX[]="wake up, Neo...\nThe Matrix has you...\nFollow the white rabbit... \n\n\n   Knock,knock, Neo\a\a";
	int i=0;
	while(i!=5){espera(.1);cout<<MATRIX[i];i++;}
	while(i!=10){espera(.2);cout<<MATRIX[i];i++;}
	while(i!=13){espera(.2);cout<<MATRIX[i];i++;}
	while(i!=16){espera(.3);cout<<MATRIX[i];i++;}
	espera(2);
	while(i!=22){espera(.1);cout<<MATRIX[i];i++;}
	while(i!=28){espera(.2);cout<<MATRIX[i];i++;}
	while(i!=33){espera(.1);cout<<MATRIX[i];i++;}
	while(i!=38){espera(.1);cout<<MATRIX[i];i++;}
	espera(2);
	while(i!=43){espera(.1);cout<<MATRIX[i];i++;}
	while(i!=52){espera(.2);cout<<MATRIX[i];i++;}
	while(i!=60){espera(.1);cout<<MATRIX[i];i++;}
	while(i!=63){espera(.2);cout<<MATRIX[i];i++;}
	espera(2.3);
	gotoxy(1,1);cout<<"root@matrix.com:$° \n\n";
	cout<<"wake up, Neo...";
	cout<<"\nThe Matrix has you...\n";
	cout<<"Follow the white rabbit... \n\n\n";
	cout<<"\n\n\n\n                         Knock,knock,Neo...";
	espera(3);
	getch();
	return(0);
}
