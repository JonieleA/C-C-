#include <iostream>

using namespace std;

int main()
{
    setlocale(0, "");
    float Z, Y, X, p, S;
    cout << "Введите изначальное состояние счета:\n";
    cin >> Z;
    cout << "Введите заработную плату:\n";
    cin >> Y;
    cout << "Введите коммунальные платежи:\n";
    cin >> X;
    cout << "Введите процент для остатка:\n";
    cin >> p;
    cout << "Месяц\t\tБаланс счета\n" << endl;
    S = Z + Y - X;
    int i = 1;
    cout << i << "\t\t" << S << " руб." << endl;
    S = S + S * p / 100;
    for (int i = 2; i <= 12; i += 1) {
        S = S + Y - X;
        cout << i << "\t\t" << S << " руб." << endl;
        S = S + S * p / 100;
    }
    system("pause");
    return 0;
}