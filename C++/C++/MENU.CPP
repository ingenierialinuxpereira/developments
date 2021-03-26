#include<process.h>
#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<math.h>
char *menu="1-Media aritmetica\n2-Mediana\n3-Moda\n4-Varianza\n5-Salir\n";

void main()
{
int op,cuantos,z,v,l[100],h,i,m,a[100],fr,b=0,sum,promedio,num[100];
float x,x1;
//clrscr();

cout<<menu<<endl;

cin>>op;

switch(op)
{
case 1:   cout<<"cuantos numeros desea ingresar para promediar?"<<endl;
	  cin>>cuantos;
	  for(i=1;i<=cuantos;i++)
	  {
	  cout<<"ingrese"<<endl;
	  cin>>num[i];
	  b=b+num[i];
	  }
	  promedio=b/cuantos;
	  cout<<promedio;
	  break;

case 2:   cout<<"cuantos numeros desea ingresar para operar?"<<endl;
	  cin>>cuantos;
	  for (i=0; i<cuantos; i++)//Vector original
	  {
	  cout<<"ingrese:";
	  cin>>a[i];
	  }
	  for (i=0; i<cuantos; i++)//Vector original
	  {
	  for (m=0; m<cuantos; m++) //Vector temporal
	  {
	   do
	   {
	   fr=a[m];
	   a[m]=a[i];
	   a[i]=fr;
	   }
	    while (a[m]>a[i]);
	   }
	   }
	   for (i=0; i<cuantos; i++)//Vector original
	  {
	  cout<<a[i];
	  }
	  if (cuantos % 2 == 0)
	  {
	  h=cuantos/2;
	  v=h-1;
	  x= a[v] + a[h];
	  x1=x/2;
	  cout<< endl<<x1;
	  }
	  if (cuantos % 2 != 0)
	  {
	  h=cuantos/2;
	  x= a[h];
	  cout<< endl<<x;
	  }

break;


case 3:   cout<<"cuantos numeros desea ingresar para operar?"<<endl;
	  cin>>cuantos;
	  for (i=0; i<cuantos; i++)//Vector original
	  {
	  cout<<"ingrese:";
	  cin>>a[i];
	  }
	  for (i=0; i<cuantos; i++)//Vector original
	  {
	  for (m=0; m<cuantos; m++) //Vector temporal
	  {
	   do
	   {
	   fr=a[m];
	   a[m]=a[i];
	   a[i]=fr;
	   }
	    while (a[m]>a[i]);
	   }
	   }
	   for (i=0; i<cuantos; i++)//Vector original
	  {
	  cout<<a[i];
	   }
	  for (i=0; i<cuantos; i++)//Vector original
	  {
	   if(a[i]==a[i])
	   {
  //	   z=0;
	   a[i]=z;
	   }
	   cout<<endl<<z;
	   }




break;

case '4':




case 5:
exit(1);
break;
}
getch();
}