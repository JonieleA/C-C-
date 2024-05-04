#include <iostream>
#include <iomanip>

int main()
{
    setlocale(LC_ALL, "Russian"); // Подключение русского языка
    int n;
    double s;
    std::cout << "Введите количество участников в игре, затем объем чаши:" << std::endl;
    std::cin >> n >> s;
    // Проверка выполнения условий для переменных n и s
    try {
        if ((n < 2) || (n > 100))
            throw "Количество игроков должно быть в диапазоне от 2 до 100";
        if ((s < 100) || (s > 1000))
            throw "Объем чаши должен быть в диапазоне от 100 до 1000";
        // Вычисление общего объема кружек выписывание сколько в чаше воды/сколько свободного объема
        std::cout << "Вводите поочередно объемы кружек:" << std::endl;
        double cup, sum=0;
        for (int i = 0; i < n; i += 1) {
            std::cin >> cup;
            if (cup <= 0) {
                std::cerr << "Ошибка: Объем кружки № " << i + 1 << " некорректен" << std::endl;;
                system("pause");
                return -1;
            }
            sum = sum + cup;
            // Коментарии к каждому ходу 
            if (sum <= s) std::cout << " Ход" << std::setw(4) << i+1 << "\tВоды в чаше:" << std::setw(5) << sum << "\tСвободный объем:" << std::setw(5) << s - sum << std::endl;
            if (sum > s) {
                std::cout << " Ход" << std::setw(4) << i + 1 << "\tИз чаши выбегает вода\n";
                i = n;
            }
        }
        // Вывод результата по выполнению условия
        std::cout << "Результат:" << std::endl;
        if (s >= sum) std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;
    }
    catch (const char* exception) {
        std::cerr << "Ошибка: " << exception << std::endl;
    }
    system("pause");
    return 0;
}