#include <iostream>
#include <ctime>

using namespace std;

/*
1.	Проверить, есть ли среди элементов главной диагонали матрицы A (5×5) отрицательные элементы,
а среди элементов главной диаго¬нали матрицы B (3×3) — элементы, меньшие 2,7.
2.	Если максимальный элемент матрицы, находящийся на главной диагонали больше 10,
то отсортировать по возрастанию элементы второй строки, иначе – третьего столбца. Сортировка методом обмена.
*/

void matrix_create(int n, double A[][5]);
void matrix_first(int n, double A[][5], int m, double B[][5]);
void matrix_second(int n, double A[][5]);

    int main()
    {
        setlocale(LC_ALL, "Russian");
        srand(static_cast<unsigned int>(time(0))); // Привязка к времени системных часов для получения "рандомных" чисел
        double A[5][5], B[5][5];
		cout << "матрица A:" << endl;
        matrix_create(5, A);
		cout << endl << "матрица B:" << endl;
        matrix_create(3, B);
        cout << endl;
        matrix_first(5, A, 3, B);
        cout << endl << "матрица A:" << endl;
        matrix_second(5, A);
        cout << endl;
        cout << "матрица B:" << endl;
        matrix_second(3, B);
        system("pause");
        return 0;
    }

	void matrix_create(int n, double A[][5])
	{
		cout << "Создать матрицу автоматически? (Y-да/N-нет)" << endl;
		char create_flag;
		cin >> create_flag;
		try
		{
			if ((create_flag != 'Y') && (create_flag != 'N'))
				throw "Необходимо выбрать Y-да/N-нет!";
			// Автоматическое создание матриц A и В
			if (create_flag == 'Y') {
				for (int i = 0; i < n; i += 1) {
					for (int j = 0; j < n; j += 1) {
						A[i][j] = (500 - rand() % 1000) / 10;
					}
				}
			}

			// Ручное создание матриц А и B
			if (create_flag == 'N') {
				cout << "Введите элементы массива А:" << endl;
				for (int i = 0; i < n; i += 1) {
					cout << "Строка №" << i + 1 << ":" << endl;
					for (int j = 0; j < n; j += 1) {
						cin >> A[i][j];
					}
				}
			}
			// Вывод массивов
			cout << "Полученный массив: " << endl;
			for (int i = 0; i < n; i += 1) {
				for (int j = 0; j < n; j += 1) {
					cout << A[i][j] << "\t";
				}
				cout << endl;
			}
		}
		catch (const char* exception)
		{
			cerr << "Ошибка: " << exception << '\n';
		}
	}

	void matrix_first(int n, double A[][5], int m, double B[][5])
	{
		int a = 0, b = 0;
		for (int i = 0; i < n; i += 1) {
			if (A[i][i] < 0) a = a + 1;
		}
		for (int i = 0; i < m; i += 1) {
			if (B[i][i] < 2.7) b = b + 1;
		}
		if (a != 0) cout << "Количество отрицательных элементов диагонали матрицы А: " << a << endl;
		else cout << "Отрицательных элементов в диагонали матрицы А нет" << endl;
		if (b != 0) cout << "Количество элементов диагонали матрицы В, меньших 2.7: " << b << endl;
		else cout << "Элементов диагонали матрицы В, меньших 2.7 нет" << endl;
	}

	void matrix_second(int n, double A[][5]) {
		double max = A[0][0];
		for (int i = 1; i < n; i += 1) {
			if (A[i][i] > max) max = A[i][i];
		}
		if (max > 10) {
			cout << "Максимальный элемент диагонали больше 10" << endl;
			for (int i = 0; i < n - 1; i++)
			{
				for (int j = (n - 1); j > i; j--)
				{
					if (A[1][j - 1] > A[1][j])
					{
						double temp = A[1][j - 1];
						A[1][j - 1] = A[1][j];
						A[1][j] = temp;
					}
				}
			}
		}
		else {
			cout << "Максимальный элемент диагонали меньше 10" << endl;
			for (int i = 0; i < n - 1; i++)
			{
				for (int j = (n - 1); j > i; j--)
				{
					if (A[j - 1][2] > A[j][2])
					{
						double temp = A[j - 1][2];
						A[j - 1][2] = A[j][2];
						A[j][2] = temp;
					}
				}
			}
		}
		cout << "Полученный массив: " << endl;
		for (int i = 0; i < n; i += 1) {
			for (int j = 0; j < n; j += 1) {
				cout << A[i][j] << "\t";
			}
			cout << endl;
		}
	}