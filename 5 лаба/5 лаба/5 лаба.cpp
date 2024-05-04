#include <iostream>
#include <string>
#include <windows.h>

// 1.	Введите  строку. Добавьте в середину строки пять символов «!».

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(0, "");
    string s;
    cout << "Введите строку:\n";
    getline(cin, s);
    
    s.insert((s.length() / 2) + (s.length() % 2), 5, '!');
    cout << "Измененная строка:" << endl << s << endl;
    system("pause");
    return 0;
}