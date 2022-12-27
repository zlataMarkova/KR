#include "Header.h"
using namespace std;
#include <iostream>
#include <chrono>
using namespace chrono;
void lab2()
{
	const int n = 100;
	int sort[n];
	int nesort[n];
	time_point<steady_clock> start;
	time_point<steady_clock> end;
	time_point<steady_clock> start1;
	time_point<steady_clock> end1;
	time_point<steady_clock> start2;
	time_point<steady_clock> end2;
	time_point<steady_clock> start3;
	time_point<steady_clock> end3;
	time_point<steady_clock> start4;
	time_point<steady_clock> end4;
	time_point<steady_clock> start5;
	time_point<steady_clock> end5;
	while (true)
	{
		setlocale(0, "");
		cout << "�������� ��������: " << "\n";
		cout << "1) ������� ������:" << "\n";
		cout << "2) ������������� ������:\n";
		cout << "3) ����� ������������ � ����������� ������� �������:\n";
		cout << "4) ����� ������� �������� ���� � ��� ���������, ������� ��������� ������ ��� � �� ����������:\n";
		cout << "5) ����� ���������� ��������� � ��������������� �������, ������� ������ ���������� ���� �����:\n";
		cout << "6) ����� ���������� ��������� � ��������������� �������, ������� ������ ���������� ���� �����:\n";
		cout << "7) ���������� ���� �� ��������� ����� � �������:\n";
		cout << "8) �������� ������� �������� �������:\n";
		cout << "0) ��������� ���������\n";
		cout << "��� �����: ";
		int p;
		cin >> p;
		cout << "\n";
		if (p == 0)
			break;
		switch (p)
		{
		case 1:
			//1 �������
			cout << "1) ����������������� ������: ";
			for (int i = 0; i < n; i++)
			{
				nesort[i] = rand() % 199 - 99;
				cout << nesort[i] << " ";
			}
			for (int i = 0; i < n; i++)
				sort[i] = nesort[i];
			cout << "\n\n\n";
			break;

		case 2:
			//2 �������
			cout << "2) ��������������� ������: ";
			start = chrono::steady_clock::now();
			int x, j;
			for (int i = 1; i < n; i++)
			{
				x = sort[i];
				j = i;
				while ((j > 0) && (x < sort[j - 1]))
				{
					sort[j] = sort[j - 1];
					j--;
				}
				sort[j] = x;
			}
			end = chrono::steady_clock::now();
			for (int i = 0; i < n; i++)
				cout << sort[i] << " ";
			cout << "\n";
			cout << "����������� �����: " << duration_cast<microseconds>(end - start).count() << " ���.";
			cout << "\n\n\n";
			break;

		case 3:
			//3 �������
			//����� max � min � ��������������� �������
			start1 = chrono::steady_clock::now();
			int mns;
			mns = sort[0];
			int mas;
			mas = sort[0];
			for (int i = 0; i < n; i++)
			{
				if (sort[i] > mas)
					mas = sort[i];
				if (sort[i] < mns)
					mns = sort[i];
			}
			end1 = chrono::steady_clock::now();

			//����� max � min � ����������������� �������
			start2 = chrono::steady_clock::now();
			int mn;
			mn = nesort[0];
			int ma;
			ma = nesort[0];
			for (int i = 0; i < n; i++)
			{
				if (nesort[i] > ma)
					ma = nesort[i];
				if (nesort[i] < mn)
					mn = nesort[i];
			}
			end2 = chrono::steady_clock::now();
			cout << "3) ������������ ������� �������: " << mas << "\n";
			cout << "   ����������� ������� �������: " << mns << "\n";
			cout << "   ����������� ����� � ������ �������: " << duration_cast<nanoseconds>(end1 - start1).count() << "��.";
			cout << "   ����������� ����� � ��������. �������: " << duration_cast<nanoseconds>(end2 - start2).count() << "��.";
			cout << "\n\n\n";
			break;

		case 4:
			//4 �������
			int sum;
			int mid;
			int k;
			k = 0;
			sum = mas + mns;
			if (sum % 2 != 0)
				sum += 1;
			mid = sum / 2;
			cout << "4) ������� �������� ���� � ��� ���������: " << mid << "\n";

			cout << "   ������� ��������� ������ �������� �������� ���� � ��� � ������ �������: ";
			start3 = chrono::steady_clock::now();
			for (int i = 0; i < n; i++)
			{
				if (sort[i] == mid)
				{
					cout << i << " ";
					k++;
				}

			}
			end3 = chrono::steady_clock::now();
			cout << "\n";

			cout << "   ������ ��������� ������ �������� �������� ���� � ��� � �������� �������: ";
			start4 = chrono::steady_clock::now();
			for (int i = 0; i < n; i++)
			{
				if (nesort[i] == mid)
					cout << i << " ";
			}
			cout << "\n";
			cout << "   ���������� ��������� ������ �������� ��������: " << k;
			end4 = chrono::steady_clock::now();
			cout << "\n";
			cout << "   ����������� ����� � ������ �������: " << duration_cast<microseconds>(end3 - start3).count() << "���." << "\n";
			cout << "   ����������� ����� � ��������. �������: " << duration_cast<microseconds>(end4 - start4).count() << "���." << "\n";
			cout << "\n\n";
			break;

		case 5:
			//5 �������
			cout << "5) ������� ����� ��� ������ ���������� ��������� ������� ��������� �����: ";
			int ka;
			ka = 0;
			int a;
			cin >> a;
			for (int i = 0; i < n; i++)
			{
				if (sort[i] < a)
					ka += 1;
			}
			cout << "   ���������� ��������� ������ " << a << ": " << ka;
			cout << "\n\n\n";
			break;

		case 6:
			//6 �������
			cout << "6) ������� ����� ��� ������ ���������� ��������� ������� ��������� �����: ";
			int b;
			cin >> b;
			int kb;
			kb = 0;
			for (int i = 0; i < n; i++)
			{
				if (sort[i] > b)
					kb += 1;
			}
			cout << "   ���������� ��������� ������ " << b << ": " << kb;
			cout << "\n\n\n";
			break;

		case 7:
			//7 �������
			int num;
			int st;
			st = 0;
			int en;
			en = n;
			cout << "7)������� �����, ����� ��������� ���� �� ��� � �������: ";
			cin >> num;
			int midl;
			for (int i = st; i < en; i++)
			{
				midl = ((st + en) / 2) + ((st + en) % 2);
				if (num < sort[midl])
					en = midl;
				if (num > sort[midl])
					st = midl + 1;
				if (num == sort[st] or num == sort[midl])
					break;
			}
			if (num == sort[st] or num == sort[midl])
			{
				cout << "  �������� ����� ����\n\n";
				break;
			}
			else
			{
				cout << "  ��������� ����� ���\n\n";
				break;
			}
			cout << "\n\n\n";
			break;

		case 8:
			//8 �������
			cout << "8) ������� ������� ��������� �������, ������� ������ ��������: " << "\n";
			start5 = chrono::steady_clock::now();
			int m, l;
			cin >> m >> l;
			int swap;
			swap = sort[l];
			sort[l] = sort[m];
			sort[m] = swap;
			end5 = chrono::steady_clock::now();
			cout << "������ � ��������������� ����������: ";
			for (int i = 0; i < n; i++)
				cout << sort[i] << " ";
			cout << "\n" << "����������� ����� �� ������������ �������� �������: " << duration_cast<milliseconds>(end5 - start5).count() << "��." << "\n";
			break;
		}
	}
}