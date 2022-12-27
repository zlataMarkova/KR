#include "Header.h"
using namespace std;
#include <iostream>
void lab1()
{
	setlocale(0, "");


	//1)
	cout << "1) " << "int: " << sizeof(int) << '\n';
	cout << "short int: " << sizeof(short) << '\n';
	cout << "long int: " << sizeof(long int) << '\n';
	cout << "float: " << sizeof(float) << '\n';
	cout << "double: " << sizeof(double) << '\n';
	cout << "long double: " << sizeof(long double);
	cout << '\n' << "char: " << sizeof(char);
	cout << '\n' << "bool: " << sizeof(bool) << '\n';
	cout << "\n";



	//2)
	cout << "2) " << "Введите целое число: ";
	int a;
	cin >> a;
	int s = sizeof(a) * 8;
	int mask = 1 << s - 1;
	for (int i = 0; i < s; i++)
	{
		if (i % 8 == 0 || i == 1)
		{
			putchar(' ');
		}
		putchar(a & mask ? '1' : '0');
		a <<= 1;
	}
	cout << "\n";
	cout << "\n";


	//3)
	cout << "3) " << "Введите вещественное число: ";
	union
	{
		int b;
		float fl;
	};
	cin >> fl;
	for (int i = 0; i < s; i++)
	{
		if (i % 8 == 0 || i == 1)
		{
			putchar(' ');
		}
		putchar(b & mask ? '1' : '0');
		b <<= 1;
		if (i == 0 || i == 8)
		{
			putchar('|');
			//'|'- разделение знакового разряда, порядка и мантисы
		}
	}
	cout << "\n";
	cout << "\n";


	//4)
	cout << "4) " << "Введите вещественное число: ";
	union
	{
		int c[2];
		double db;
	};
	cin >> db;
	int s4 = sizeof(db) * 8;
	unsigned int mask4 = 1 << s4 - 1;
	for (int i = 0; i < s4 / 2; i++)
	{
		if (i % 8 == 0 || i == 1)
		{
			putchar(' ');
		}
		if (i == 1 || i == 12)
		{
			putchar('|');
			//'|'- разделение знакового разряда, порядка и мантисы
		}
		putchar(c[1] & mask4 ? '1' : '0');
		c[1] <<= 1;
	}
	for (int j = 0; j < s4 / 2; j++)
	{
		if (j % 8 == 0)
		{
			putchar(' ');
		}
		putchar(c[0] & mask4 ? '1' : '0');
		c[0] <<= 1;
	}

}

