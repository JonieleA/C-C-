#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(0, "");
    srand(static_cast<unsigned int>(time(0))); // Используем системные часы для начальной генерации рандомных чисел
    int a[100];
    cout << "Введите размер массива: " << endl;
    int n;
    cin >> n;
    try 
    {
        if ((n <= 1) || (n > 100))
            throw "Количество элементов массива должно быть в диапазоне от 2 до 100"; 

        cout << "Составить массив автоматически? (Y(Да)/N(Нет))" << endl;
        char Flag;
        cin >> Flag;
        try 
        {
            if ((Flag != 'N') && (Flag != 'Y'))
                throw "Необходимо выбрать Y-Да  N-Нет"; 

            if (Flag == 'Y') {
                for (int i = 0; i < n; i += 1) {
                    a[i] = 50 - rand()%100;
                }
            }
            if (Flag == 'N') {
                cout << "Введите поочередно элементы массива: " << endl;
                for (int i = 0; i < n; i += 1) {
                    cin >> a[i];
                }
            }
            cout << "Массив:" << endl;
            for (int i = 0; i < n; i += 1) cout << a[i] << "\t";
            cout << endl;
            int Mult=1;
            int Sum=0;
            for (int i = 0; i < n; i += 1) {
                if ((a[i] >= 0) && (sin(a[i]) <= 0)) {
                    Mult = Mult * a[i];
                    Sum = Sum + a[i];
                }
            }
            cout << "Произведение элементов, удовлетворяющих условию: " << Mult << endl << "Сумма элементов, удовлетворяющих условию: " << Sum << endl;
        }
        catch (const char* exception) 
        {
            cerr << "Ошибка: " << exception << endl;
        }
    }
    catch (const char* exception) 
    {
        cerr << "Ошибка: " << exception << endl;
    }
    
    
    system("pause");
    return 0;
}