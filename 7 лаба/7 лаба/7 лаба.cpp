#include <iostream>
#include <vector>

/*Общая часть задания :
    Даны две последовательности. Изменить первую последовательность, вставляя после каждого элемента 1-ой
    последовательности очередной элемент 2-ой последовательности.*/

int main()
{
    setlocale(0, "");
    int n;
    std::cout << "Введите размер последовательностей:\n";
    std::cin >> n;
    while (n <= 1) { // Проверка на некорректный размер последовательности
        std::cout << "Введите корректный размер последовательности:\n";
        std::cin >> n;
    }
    std::vector <double> first(n), result(n*2);
    std::cout << "Введите элементы первой последовательности\n";
    for (int i = 0; i < n; i += 1) std::cin >> first[i];
    std::cout << "Введите элементы второй последовательности\n";
    for (int i = 0; i < n * 2; i += 2) {
        std::cin >> result[i + 1];
        result[i] = first[i / 2];
    }
    std::cout << "Полученная последовательность:\n";
    for (int i = 0; i < n * 2; i += 1) std::cout << result[i] << " ";
    std::cout << std::endl;
    system("pause");
    return 0;
}