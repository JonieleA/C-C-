#include <iostream>

using namespace std;

int main()
{
    setlocale(0, "");
    float Z, p, S = 0;
    cout << "Введите заработную плату:\n";
    cin >> Z;
    cout << "Введите процентную ставку:\n";
    cin >> p;
    for (int i = 1; i <= 12; i += 1) {
        S = S + Z / (i + 1);
        S = S + S * p / 100;
    }
    cout << "Счет в конце года: "<< endl << S << endl;
    system("pause");
    return 0;
}