#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// 2.	Написать программу, которая вводит текст, состоящий из нескольких предложений, и выводит его на экран,  меняя местами каждые два соседних слова.

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string s;
    int first = 0, second = 0, third = 0, fourth = 0;
    cout << "Введите строку:\n";
    getline(cin, s);
    cout << "Измененная строка:\n";
    while (s.length() > 0)
    {
        first = s.find_first_not_of(' ');
        second = s.find_first_of(' ', first)-1;
        third = s.find_first_not_of(' ', second+1);
        fourth = s.find_first_of(' ', third)-1;
        if (fourth < 0) fourth = s.length() - 1;
        if (first < 0) first = 0;
        if (second < 0) second = s.length() - 1;
        if (third < 0) third = 0;
        if ((fourth > 0) && (third > 0)) cout << s.substr(third, fourth - third + 1) << " " << s.substr(first, second - first + 1) << " ";
        else cout << s.substr(first, second - first + 1);
        s.erase(first, fourth - first+1);
        first = 0; second = 0; third = 0; fourth = 0;
    }
    return 0;
}