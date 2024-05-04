#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(0))); // Привязка к времени системных часов для получения "рандомных" чисел
	int A[50][50], C[50];
    int n;
    cout << "Введите n - размер квадратной матрицы А" << endl;
    cin >> n;
    try
    {
        if ((n <= 2) || (n > 50))
            throw "Значение n должно быть в диапазоне от 3 до 50!";

        cout << "Создать матрицу автоматически? (Y-да/N-нет)" << endl;
        char create_flag;
        cin >> create_flag;
        try
        {
            if ((create_flag != 'Y') && (create_flag != 'N'))
                throw "Необходимо выбрать Y-да/N-нет!";
            // Автоматическое создание матрицы
            if (create_flag == 'Y') {
                for (int i = 0; i < n; i += 1) {
                    for (int j = 0; j < n; j += 1) {
                        A[i][j] = 50 - rand()%100;
                    }
                }
            }
            // Ручное создание матрицы
            if (create_flag == 'N') {
                cout << "Введите элементы массива:" << endl;
                for (int i = 0; i < n; i += 1) {
                    cout << "Строка №" << i+1 << ":" << endl;
                    for (int j = 0; j < n; j += 1) {
                        cin >> A[i][j];
                    }
                }
            }
            // Вывод массива
            cout << "Полученный массив: " << endl;
            for (int i = 0; i < n; i += 1) {
                for (int j = 0; j < n; j += 1) {
                    cout << A[i][j] << "\t";
                }
                cout << endl;
            }
            // Выполнение условия создания ветора C
            for (int i = 0; i < n; i += 1) {
                int flag = 0;
                for (int j = 1; j < n-1; j += 1) {
                    if (A[j][i] < A[j + 1][i] + A[j - 1][i]) flag = flag + 1;
                }
                if (flag == n - 2) C[i] = 1;
                else C[i] = 0;
            }
            // Вывод вектора C
            cout << "Полученный вектор:" << endl;
            for (int i = 0; i < n; i += 1) cout << C[i] << "\t";
            cout << endl;
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