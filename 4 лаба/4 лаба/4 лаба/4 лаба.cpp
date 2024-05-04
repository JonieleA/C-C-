#include "stdafx.h"
#include <iostream>
#include <ctime>

/*
Переставить в каждом столбце матрицы все отрицательные элементы в конец столбца.
Вывести часть полученной матрицы, состоящую из первых строк, не имеющих отрицательных элементов.
*/

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(static_cast<unsigned int>(time(0))); // Привязка к времени системных часов для получения "рандомных" чисел
	int n, m;
	cout << "Введите число строк матрицы:" << endl;
	cin >> n;
	cout << "Введите число столбцов матрицы:" << endl;
	cin >> m;
	try
	{
		if ((n <= 1) || (m <= 1))
			throw "Величина строк и столбцов должна быть больше единицы";

		double** x;
		x = new double* [n];
		for (int i = 0; i < n; i += 1) x[i] = new double[m];

		cout << "Создать матрицу автоматически? (Y-да/N-нет):" << endl;
		char create_flag;
		cin >> create_flag;
		try
		{
			if ((create_flag != 'Y') && (create_flag != 'N'))
				throw "Необходимо выбрать Y-да/N-нет!";
			// Автоматическое создание матрицы
			if (create_flag == 'Y') {
				for (int i = 0; i < n; i += 1) {
					for (int j = 0; j < m; j += 1) {
						x[i][j] = (500 - rand() % 1000) / 10;
					}
				}
			}

			// Ручное создание матрицы
			if (create_flag == 'N') {
				cout << "Введите элементы массива А:" << endl;
				for (int i = 0; i < n; i += 1) {
					cout << "Строка №" << i + 1 << ":" << endl;
					for (int j = 0; j < m; j += 1) {
						cin >> x[i][j];
					}
				}
			}
			// Вывод массива
			cout << "Полученный массив: " << endl;
			for (int i = 0; i < n; i += 1) {
				for (int j = 0; j < m; j += 1) {
					cout << x[i][j] << "\t";
				}
				cout << endl;
			}

			// Сортировка по условию
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

			cout << "Вывод после сортировки:" << endl;
			for (int i = 0; i < n; i += 1) {
				for (int j = 0; j < m; j += 1) {
					cout << x[i][j] << "\t";
				}
				cout << endl;
			}

			cout << "Вывод массива после 2 условия:" << endl;
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

			// Удаление массива из памяти
			for (int i = 0; i < n; i += 1) delete[] x[i];
			delete[] x;

		}
		catch (const char* exception)
		{
			cerr << "Ошибка: " << exception << '\n';
		}
	}
	catch (const char* exception)
	{
		cerr << "Ошибка: " << exception << '\n';
	}
	system("pause");
	return 0;
}