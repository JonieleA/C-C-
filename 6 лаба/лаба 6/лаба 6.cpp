#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <iomanip>

/* О каждой книге имеются следующие сведения : фамилия и  инициалы автора, название, год издания и число запросов за последние три года.
Вывести фамилии авторов и названия книг, изданных до 1980 г., по которым нет запросов. Определить число таких книг. Решить задачу с использованием файлов. */

struct books { // Создание структуры книг
    std::string name; // Название книги
    std::string author; // Фамилия и инициалы автора
    int public_year; // Год публикации книги
    int request; // Количество запросов книги за 3 года
};

int main()
{
    setlocale(LC_ALL, "rus"); 
    SetConsoleCP(1251); // Устанваливаем кодировку для ввода и вывода
    SetConsoleOutputCP(1251);
    
    const int m = 100;
    books list[m]; // Инициализируем массив книг
    int n=0;
    while ((n <= 0) || (n > m)) {
        std::cout << "Введите корректное количество вводимых книг: ";
        std::cin >> n;
    }
    char input;
    std::cout << "Ввести книги из файла или вручную?(F-из файла/H-вручную)" << std::endl;
    std::cin >> input;
    // Ввод с клавиатуры
    if (input == 'H') {
        for (int i = 0; i < n; i += 1) {
            while (list[i].name.length() == 0) {
                std::cout << "Введите корректное название книги:" << std::endl;
                std::cin.ignore();
                getline(std::cin, list[i].name);
            }
            while (list[i].author.length() == 0) {
                std::cout << "Введите корректные фамилию и инициалы автора:" << std::endl;
                getline(std::cin, list[i].author);
            }
            while ((list[i].public_year <= 0) || (list[i].public_year > 2021)) {
                std::cout << "Введите корректный год публикации книги:" << std::endl;
                std::cin >> list[i].public_year;
            }
            while (list[i].request < 0) {
                std::cout << "Введите корректное количество запросов за 3 года:" << std::endl;
                std::cin >> list[i].request;
            }
        }
    }
    // Чтение из открытого файла
    else if (input == 'F') {
        std::ifstream file("C:\\Users\\Dmitrii\\Desktop\\Важное\\3 сем\\Инфа\\6 лаба\\books.txt"); // Открываем файл с информацией о книгах
        for (int i = 0; i < n; i += 1) {
            getline(file, list[i].name);
            getline(file, list[i].author);
            file >> list[i].public_year >> list[i].request;
            file.ignore(256, '\n');
            if ((list[i].name.length() == 0) && (list[i].author.length() == 0)) {
                std::cout << "Книги №" << i + 1 << " не существует. Хотите ввести данные?(Y-да/N-нет)" << std::endl;
                char flag;
                std::cin >> flag;
                if (flag == 'Y') {
                    while (list[i].name.length() == 0) {
                        std::cout << "Введите корректное название книги:" << std::endl;
                        std::cin.ignore();
                        getline(std::cin, list[i].name);
                    }
                    while (list[i].author.length() == 0) {
                        std::cout << "Введите корректные фамилию и инициалы автора:" << std::endl;
                        getline(std::cin, list[i].author);
                    }
                    while ((list[i].public_year <= 0) || (list[i].public_year > 2021)) {
                        std::cout << "Введите корректный год публикации книги:" << std::endl;
                        std::cin >> list[i].public_year;
                    }
                    while (list[i].request < 0) {
                        std::cout << "Введите корректное количество запросов за 3 года:" << std::endl;
                        std::cin >> list[i].request;
                    }
                }
                else if (flag == 'N') i = n;
                else if (flag != 'N') {
                    std::cout << "Ошибка: Необходимо было ввести Y или N" << std::endl;
                    system("pause");
                    return -1;
                }
            }
            if (((list[i].public_year <= 0) || (list[i].public_year > 2021)) && (i < n)) {
                std::cout << "Год книги №" << i + 1 << " некорректен. Хотите изменить год?(Y-да/N-нет)" << std::endl;
                char flag;
                std::cin >> flag;
                if (flag == 'Y') {
                    while ((list[i].public_year <= 0) || (list[i].public_year > 2021)) {
                        std::cout << "Введите новый год для книги №" << i + 1 << " повторно:" << std::endl;
                        std::cin >> list[i].public_year;
                    }
                }
                else if (flag != 'N') {
                    std::cout << "Ошибка: Необходимо было ввести Y или N" << std::endl;
                    system("pause");
                    return -1;
                }
            }
            if ((list[i].request < 0) && (i < n)) {
                std::cout << "Количество запросов книги №" << i + 1 << " некорректны. Хотите изменить количество запросов?(Y-да/N-нет)" << std::endl;
                char flag;
                std::cin >> flag;
                if (flag == 'Y') {
                    while (list[i].request < 0) {
                        std::cout << "Введите количество запросов для книги №" << i + 1 << " повторно:" << std::endl;
                        std::cin >> list[i].request;
                    }
                }
                else if (flag != 'N') {
                    std::cout << "Ошибка: Необходимо было ввести Y или N" << std::endl;
                    system("pause");
                    return -1;
                }
            }
        }
        file.close(); // Закрытие файла
    }
    else {
        std::cout << "Ошибка: Необходимо было ввести F или H" << std::endl;
        return -1;
    }
    // Вывод книг, удовлетворяющих условию
    std::cout << std::setw(8) << "Книга №:" << std::setw(25) << "Название:" << std::setw(20) <<"Автор:" << std::setw(20) << "Год публикации:" << std::setw(25) << "Количество запросов:" << std::endl;
    unsigned int booknum = 0;
    for (int i = 0; i < n; i += 1) {
        if ((list[i].public_year < 1980) && (list[i].request == 0)) {
            std::cout << std::setw(8) << i + 1 << std::setw(25) << list[i].name << std::setw(20) << list[i].author << std::setw(20) << list[i].public_year << std::setw(25) << list[i].request << std::endl;
            booknum = booknum + 1;
        }
    }
    std::cout << "Количество книг: " << booknum << std::endl;
    system("pause");
    return 0;
}