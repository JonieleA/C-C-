#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian"); // Для стабильного отображения русского языка
	float A[10][10], K;
	int n;
	cout << "Введите размерность квадратной матрицы:" << endl;
	cin >> n;
	try 
	{
		if ((n <= 1) || (n>10)) // Использую перехват ошибок для n
			throw "Размер матрицы должен быть больше единицы, но меньше десяти";

		cout << "Введите заданное значение К:" << endl;
		cin >> K;
		cout << "Введите матрицу" << endl; // Ввод матрицы
		for (int i = 0; i < n; i += 1) {
			cout << "Строка №" << i + 1 << ":" << endl;
			for (int j = 0; j < n; j += 1) {
				cin >> A[i][j];
			}
		}
		cout << endl;
		cout << "Полученная матрица:" << endl; // Вывод после ввода :)
		for (int i = 0; i < n; i += 1) {
			for (int j = 0; j < n; j += 1) {
				cout << A[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
		// Выполнение условия
		int sc = 0;
		float sum = 0;
		for (int i = 0; i < n; i += 1) {
			for (int j = 0; j < n; j += 1) {
				if (A[i][j] < A[i][i])
				{
					sc = sc + 1;
					sum = sum + A[i][j];
					A[i][j] = A[i][j] + K;
				}
			}
		}
		// Вывод матрицы
		cout << "Матрица после выполнения условий:" << endl;
		for (int i = 0; i < n; i += 1) {
			for (int j = 0; j < n; j += 1) {
				cout << A[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "Число изменненных элементов : " << sc << endl << "Сумма начальных значений измененных элементов: " << sum << endl;
	}
	catch (const char* exception)
	{
		cerr << "Ошибка: " << exception << '\n';
	}
	system("pause");
	return 0;
}