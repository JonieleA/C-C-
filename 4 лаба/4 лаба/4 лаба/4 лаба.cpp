#include "stdafx.h"
#include <iostream>
#include <ctime>

/*
����������� � ������ ������� ������� ��� ������������� �������� � ����� �������.
������� ����� ���������� �������, ��������� �� ������ �����, �� ������� ������������� ���������.
*/

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(static_cast<unsigned int>(time(0))); // �������� � ������� ��������� ����� ��� ��������� "���������" �����
	int n, m;
	cout << "������� ����� ����� �������:" << endl;
	cin >> n;
	cout << "������� ����� �������� �������:" << endl;
	cin >> m;
	try
	{
		if ((n <= 1) || (m <= 1))
			throw "�������� ����� � �������� ������ ���� ������ �������";

		double** x;
		x = new double* [n];
		for (int i = 0; i < n; i += 1) x[i] = new double[m];

		cout << "������� ������� �������������? (Y-��/N-���):" << endl;
		char create_flag;
		cin >> create_flag;
		try
		{
			if ((create_flag != 'Y') && (create_flag != 'N'))
				throw "���������� ������� Y-��/N-���!";
			// �������������� �������� �������
			if (create_flag == 'Y') {
				for (int i = 0; i < n; i += 1) {
					for (int j = 0; j < m; j += 1) {
						x[i][j] = (500 - rand() % 1000) / 10;
					}
				}
			}

			// ������ �������� �������
			if (create_flag == 'N') {
				cout << "������� �������� ������� �:" << endl;
				for (int i = 0; i < n; i += 1) {
					cout << "������ �" << i + 1 << ":" << endl;
					for (int j = 0; j < m; j += 1) {
						cin >> x[i][j];
					}
				}
			}
			// ����� �������
			cout << "���������� ������: " << endl;
			for (int i = 0; i < n; i += 1) {
				for (int j = 0; j < m; j += 1) {
					cout << x[i][j] << "\t";
				}
				cout << endl;
			}

			// ���������� �� �������
			int temp;
			for (int j = 0; j < m; j += 1) {
				for (int i = 0; i < n; i += 1) {
					if (x[i][j] < 0) {
						for (int k = n - 1; k > i; k -= 1) {
							if (x[k][j] >= 0) {
								temp = x[i][j];
								x[i][j] = x[k][j];
								x[k][j] = temp;
							}
						}
					}
				}
			}

			cout << "����� ����� ����������:" << endl;
			for (int i = 0; i < n; i += 1) {
				for (int j = 0; j < m; j += 1) {
					cout << x[i][j] << "\t";
				}
				cout << endl;
			}

			cout << "����� ������� ����� 2 �������:" << endl;
			for (int i = 0; i < n; i += 1) {
				int flag = 0;
				for (int j = 0; j < m; j += 1) if (x[i][j] >= 0) flag++;
				if (flag == m) {
					for (int j = 0; j < m; j += 1) {
						cout << x[i][j] << "\t";
					}
					cout << endl;
				}
			}

			// �������� ������� �� ������
			for (int i = 0; i < n; i += 1) delete[] x[i];
			delete[] x;

		}
		catch (const char* exception)
		{
			cerr << "������: " << exception << '\n';
		}
	}
	catch (const char* exception)
	{
		cerr << "������: " << exception << '\n';
	}
	system("pause");
	return 0;
}