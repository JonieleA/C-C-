#include <iostream>
#include <cmath>

/*В той из двух матриц, все элементы которой по модулю меньше заданной величины, проверить наличие строки с положительной суммой элементов.*/

void input(double a[50][50], int n, int m); // Ввод матрицы
void output(double a[50][50], int n, int m); //
bool flag(double a[50][50], int n, int m, double mod); // Проверяет, что все элементы меньше заданного значения
void strok(double a[50][50], int n, int m); // Ищет строку с положительной суммой элементов

int main()
{
    setlocale(LC_ALL, "Russian");
    double a[50][50], b[50][50];
    int n1, n2, m1, m2;
    std::cout << "Введите количество строк первой матрицы:" << std::endl;
    std::cin >> n1;
    std::cout << "Введите количество столбцов первой матрицы:" << std::endl;
    std::cin >> m1;
    std::cout << "Введите количество строк второй матрицы:" << std::endl;
    std::cin >> n2;
    std::cout << "Введите количество столбцов второй матрицы:" << std::endl;
    std::cin >> m2;
    std::cout << "Первая матрица:" << std::endl;
    input(a, n1, m1);
    std::cout << "Вторая матрица:" << std::endl;
    input(b, n2, m2);
    std::cout << "Полученные матрицы:\n";
    std::cout << "Первая матрица:" << std::endl;
    output(a, n1, m1);
    std::cout << "Вторая матрица:" << std::endl;
    output(b, n2, m2);
    std::cout << "Введите заданную величину для матриц:" << std::endl;
    double mod;
    std::cin >> mod;
    if (flag(a,n1,m1,mod)) {
        std::cout << "Первая матрица\n";
        strok(a, n1, m1);
    }
    if (flag(b, n2, m2, mod)) {
        std::cout << "Вторая матрица\n";
        strok(b, n2, m2);
    }
    system("pause");
    return 0;
}

void input(double a[50][50], int n,int m)
{
    for (int i = 0; i < n; i += 1) {
        std::cout << "Строка №" << i + 1 << ":\n";
        for (int j = 0; j < m; j += 1) {
            std::cin >> a[i][j];
        }
    }
}

void output(double a[50][50], int n, int m)
{
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            std::cout << a[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

bool flag(double a[50][50], int n, int m, double mod)
{
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            if (abs(a[i][j]) >= mod) return false;
        }
    }
    return true;
}

void strok(double a[50][50], int n, int m)
{
    int str = 0;
    for (int i = 0; i < n; i += 1) {
        int sum = 0;
        for (int j = 0; j < m; j += 1) {
            sum = sum + a[i][j];
        }
        if (sum > 0) {
            std::cout << "Сумма строки №" << i + 1 << " положительна\n";
            str = str + 1;
        }
    }
    if (str == 0) std::cout << "Нет строк с положительной суммой\n";
}