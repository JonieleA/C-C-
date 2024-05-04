#include <iostream>
#include <vector>
#include <iomanip>

/* 8.	Найти максимальный отрицательный элемент в массиве с нечетным индексом.
    Также найти среднее арифметическое таких элементов, начиная от индекса минимального элемента массива.*/

int main()
{
    setlocale(0, "");
    std::cout << "Введите количество элементов последовательности:\n";
    int n;
    std::cin >> n;
    while (n <= 1) { // Проверка на некорректный размер последовательности
        std::cout << "Введите корректный размер последовательности:\n";
        std::cin >> n;
    }
    std::vector <double> third(n);
    std::cout << "Введите последовательность:\n";
    for (int i = 0; i < n; i += 1) std::cin >> third[i];
    double maxmin = 0;
    int min_ind = 0;
    int i = 0;
    // Поиск первого отрицательного элемента
    while ((maxmin >= 0) && (i < n)) {
        maxmin = third[i];
        i++;
    }
    if (maxmin >= 0) std::cout << "Отрицательных элементов в последовательности нет\n";
    else {
        // Поиск максимального отрицательного элемента и индекса минимального элемента
        bool maxmin_flag = false;
        for (int i = 0; i < n; i += 1) {
            if ((third[i] < 0) && (third[i] > maxmin) && (i % 2 == 1)) {
                maxmin = third[i];
                maxmin_flag = true;
            }
            if (third[min_ind] > third[i]) min_ind = i;
        }
        if (maxmin_flag) std::cout << "Максимальный отрицательный элемент с нечетным индексом: " << maxmin << std::endl;
        else std::cout << "Отрицательный элемент с нечетным индексом отсутствует\n";
        // Нахождение среднего арифметического отрицательных элементов начиная от индекса минимального элемента массива
        double sr_ar = 0;
        int sr_num = 0;
        for (int i = min_ind; i < n; i += 1) if (third[i] < 0) {
            sr_ar = sr_ar + third[i];
            sr_num = sr_num + 1;
        }
        if (sr_num > 0) {
            sr_ar = sr_ar / sr_num;
            std::cout << "Минимальный элемент: " << third[min_ind] << "\t С индексом: " << min_ind << std::endl;
            std::cout << "Среднее арифметическое отрицательных элементов начиная от индекса минимального элемента массива: " << std::setprecision(4) << sr_ar << std::endl;
        }
        else std::cout << "Таких элементов нет\n";
    }
    system("pause");
    return 0;
}