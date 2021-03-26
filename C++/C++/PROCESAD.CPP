# include <conio.h>
# include <stdio.h>
# include <iostream.h>

void pres()
{int a;
clrscr();
gotoxy (37,4);
cout <<"LUISA";
gotoxy (18,24);
cout <<"Ctrl+Alt+B = Borrar el archivo   Esc = Salir";
gotoxy (8,25);
cout<<"Sugerencia: Evite el uso de tildes y dem s caracteres especiales";
gotoxy (4,9);
putchar (201);
gotoxy (4,12);
putchar (200);
gotoxy (77,9);
putchar (187),
gotoxy (77,12);
putchar (188);
for (a=5; a<=76; a++)
	{gotoxy (a, 9);
        putchar (205);
	gotoxy (a, 12);
	putchar (205);
	}
gotoxy (4,10);
putchar (186);
gotoxy (4,11);
putchar (186);
gotoxy (77,10);
putchar (186);
gotoxy (77,11);
putchar (186);
}

void main()
{int px, py, i, s;
char v[144], c;
FILE *ar;
ar = fopen ("c:\\misdoc~1\\luisa.txt", "rb");
if (ar==NULL)
	ar= fopen("c:\\misdoc~1\\luisa.txt", "wb");
else
	{fclose (ar);
	fopen ("c:\\misdoc~1\\luisa.txt", "ab");
	}
pres();
px=5; py=10; i=0; s=1; v[0]='\0';
while (s)
	{gotoxy (35,20);
	cout <<"QUEDAN "<<143-i<<"   ";
	gotoxy (px, py);
	v[i]='\0';
	c=getch();
	if (c==char(0))
		{c=getch();
		if (c==48) // Ctrl+Alt+b
			{gotoxy (10, 18);
			cout<<"Presione 1 para borrar el archivo ";
			if ((c=getch())=='1')
				{fclose(ar);
				ar=fopen("c:\\misdoc~1\\luisa.txt", "wb");
				gotoxy(10,18);
				clreol();
				gotoxy(10,18);
				cout<<"Archivo borrado ";
				if ((c=getch())==char(0))
					c=getch();
				gotoxy(10,18);
				clreol();}
			else if (c==char(0))
				c=getch();
			gotoxy(10,18);
			clreol();}
		}
	else
		switch (c)
			{case char(27):
				s=0;
				break;
			case char (13):
				if (i!=0)
					{i=0;
					while (v[i]!='\0')
						{putc(int(v[i]), ar);
						i++;}
					putc (13, ar);
					putc (10, ar);
					putc (13, ar);
					putc (10, ar);
					i=0;
					pres();
					px=5; py=10;
					v[0]='/0';
					}
				else
					putchar(7);
				break;
			case char (8):
				if (i==0)
					putchar (7);
				else
					if (i==72)
						{px=76; py=10;
						gotoxy (px, py);
						putchar (32);
						i--;
						}
					else
						{px--;
						gotoxy (px, py);
						putchar (32);
						i--;}
					break;
				default:
					if (i==143)
						putchar (7);
					else
						{v[i]=c;
						i++;
						px++;
						cout<<c;
						if (px==77 && py==10)
							{px=5; py=11;
							}
						}
					break;
				}
		}
fclose (ar);
gotoxy (33,22);
cout<<"HASTA LA MUERTE ";
if (getch()==0)
	getch();
}