#include "Header.h"
#include <iostream>
#include <Windows.h>
using namespace std;
#include <ctime>
void lab3()
{
	setlocale(0, "");
	srand(time(NULL));
	const int n = 6;
	int arr[n][n];

	//1)
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int *first = &arr[0][0];
	int *end = first + n * n - 1;
	for (int* num = first, i = 1, x = 0, y = 1, s = 0; num <= end; num++, i++) {
		*num = 1 + rand() % (n * n);
		if (s % 2 == 0) {
			destCoord.X = x;
			destCoord.Y = y;
			SetConsoleCursorPosition(hStdout, destCoord);
			cout << *num;
			y += 1;
			Sleep(50);
		}
		if (s % 2 != 0) {
			destCoord.X = x;
			destCoord.Y = n - y+1;
			SetConsoleCursorPosition(hStdout, destCoord);
			cout << *num;
			y += 1;
			Sleep(50);
		}
		if (i % n == 0) {
			y = 1;
			x += 3;
			s += 1;
		}
	}
	cout << "\n\n\n\n\n\n\n\n";


	//arr2: копия массив arr в привичном виде(не змейкой)
	int arr2[n][n];
	int *first2 = &arr2[0][0];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (j % 2 != 0)
				*(first2 + n * i + j) = *(first + n * j + (n - (i + 1)));
			else
				*(first2 + n * i + j) = *(first + n * j + i);
		}
	int arr3[n][n];//буферный массив
	int *first3 = &arr3[0][0];

	//2a)
	cout << "2a)";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (0 <= i and i <= (n / 2 - 1) and 0 <= j and j <= (n / 2 - 1))
				*(first3 + n * i + j) = *(first2 + n * (i + n / 2) + j);
			if (0 <= i and i <= (n / 2 - 1) and (n / 2) <= j and j <= (n - 1))
				*(first3 + n * i + j) = *(first2 + n * i + (j - n / 2));
			if ((n / 2) <= i and i <= (n - 1) and (n / 2) <= j and j <= (n - 1))
				*(first3 + n * i + j) = *(first2 + n * (i - n / 2) + j);
			if ((n / 2) <= i and i <= (n - 1) and 0 <= j and j <= (n / 2 - 1))
				*(first3 + n * i + j) = *(first2 + n * i + (j + n / 2));
		}
	}
	for (int *first3 = &arr3[0][0], *last = first3 + (n*n - 1); first3 <= last; first3++) {
		if ((first3 - &arr3[0][0]) % n == 0)
			cout << "\n";
		cout << *first3 << " ";
	}
	cout << "\n\n";


	//2b)
	cout << "2b)";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (0 <= i and i <= (n / 2 - 1) and 0 <= j and j <= (n / 2 - 1))
				*(first3 + n * i + j) = *(first2 + n * (i + n / 2) + j + n / 2);
			if ((n / 2) <= i and i <= (n - 1) and (n / 2) <= j and j <= (n - 1))
				*(first3 + n * i + j) = *(first2 + n * (i - n / 2) + j - n / 2);
			if (0 <= i and i <= (n / 2 - 1) and (n / 2) <= j and j <= (n - 1))
				*(first3 + n * i + j) = *(first2 + n * (i + n / 2) + j - n / 2);
			if ((n / 2) <= i and i <= (n - 1) and 0 <= j and j <= (n / 2 - 1))
				*(first3 + n * i + j) = *(first2 + n * (i - n / 2) + j + n / 2);
		}
	}
	for (int *first3 = &arr3[0][0], *last = first3 + (n*n - 1); first3 <= last; first3++) {
		if ((first3 - &arr3[0][0]) % n == 0)
			cout << "\n";
		cout << *first3 << " ";
	}
	cout << "\n\n";
	//2c)
	cout << "2c)";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (0 <= i and i <= (n / 2 - 1))
				*(first3 + n * i + j) = *(first2 + n * (i + n / 2) + j);
			if ((n / 2) <= i and i <= (n - 1))
				*(first3 + n * i + j) = *(first2 + n * (i - n / 2) + j);
		}
	}
	for (int *first3 = &arr3[0][0], *last = first3 + (n*n - 1); first3 <= last; first3++) {
		if ((first3 - &arr3[0][0]) % n == 0)
			cout << "\n";
		cout << *first3 << " ";
	}
	cout << "\n\n";

	//2d)
	cout << "2d)";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (0 <= j and j <= (n / 2 - 1))
				*(first3 + n * i + j) = *(first2 + n * i + j + (n / 2));
			if ((n / 2) <= j and j <= (n - 1))
				*(first3 + n * i + j) = *(first2 + n * i + j - (n / 2));
		}
	}
	for (int *first3 = &arr3[0][0], *last = first3 + (n*n - 1); first3 <= last; first3++) {
		if ((first3 - &arr3[0][0]) % n == 0)
			cout << "\n";
		cout << *first3 << " ";
	}
	cout << "\n\n";
	//3)
	int b;
	cout << "Сортированный массив:";
	for (int i = 0; i < n*n; i++)
	{
		for (int j = 0; j < n*n - i - 1; j++)
		{
			if (*(first3 + j + 1) < *(first3 + j))
			{
				b = *(first3 + j);
				*(first3 + j) = *(first3 + j + 1);
				*(first3 + j + 1) = b;
			}
		}
	}
	for (int *first3 = &arr3[0][0], *last = first3 + (n*n - 1); first3 <= last; first3++) {
		if ((first3 - &arr3[0][0]) % n == 0)
			cout << "\n";
		cout << *first3 << " ";
	}
	cout << "\n\n";



	//4)
	while (true) {
		cout << "Введите число:";
		int a;
		cin >> a;
		cout << "\n";
		cout << "Выберите действие:\n";
		cout << "1)Уменьшить\n" << "2)Увеличить\n" << "3)Умножить\n" << "4)Рaзделить\n" << "0)Выйти\n";
		int p;
		cout << "Ваш выбор:";
		cin >> p;
		cout << "\n";
		if (p == 0)
			break;
		switch (p)
		{
		case(1):
			for (int *first2 = &arr2[0][0], *last = first2 + (n*n - 1); first2 <= last; first2++)
			{
				*(&arr3[0][0] + (first2 - &arr2[0][0])) = *first2 - a;
			}
			break;
		case(2):
			for (int *first2 = &arr2[0][0], *last = first2 + (n*n - 1); first2 <= last; first2++)
			{
				*(&arr3[0][0] + (first2 - &arr2[0][0])) = *first2 + a;
			}

			break;
		case(3):
			for (int *first2 = &arr2[0][0], *last = first2 + (n*n - 1); first2 <= last; first2++)
			{
				*(&arr3[0][0] + (first2 - &arr2[0][0])) = *first2 * a;
			}
			break;
		case(4):
			for (int *first2 = &arr2[0][0], *last = first2 + (n*n - 1); first2 <= last; first2++)
			{
				*(&arr3[0][0] + (first2 - &arr2[0][0])) = *first2 / a;
			}
			break;
		}
		for (int *first3 = &arr3[0][0], *last = first3 + (n*n - 1); first3 <= last; first3++)
		{
			if ((first3 - &arr3[0][0]) % n == 0)
				cout << "\n";
			cout << *first3 << " ";
		}
		cout << "\n\n";
	}
}
