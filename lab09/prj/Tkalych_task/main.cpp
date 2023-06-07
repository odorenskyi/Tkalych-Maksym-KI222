#include <iostream>
#include "ModulesTkalych.h"
#include <Windows.h>

using namespace std;


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    char input;
    while (true) {
        cout << "Введіть символ(v,n,m,q) або (w,W) для виходу: ";
        cin >> input;

        if (input == 'w' || input == 'W') {
            break;
        }

        switch (input) {
            case 'v': {
                int x, y, z;
                cout << "x = ";
                cin >> x;
                cout << "y = ";
                cin >> y;
                cout << "z = ";
                cin >> z;
                cout << s_calculation(x, y, z) << endl;
                break;
            }
            case 'n': {
                int worked_days;
                cout << "Введіть кількість відпрацьованих днів за звітні два тижні: ";
                cin >> worked_days;
                salary_calculate(worked_days);
                break;
            }
            case 'm':
                 int ukr_size;
                cout << "Список розмірів за українською системою: 23,25,27,29,31" << endl;
                cout << "Введіть ваш розмір: ";
                cin >> ukr_size;
                foot_size(ukr_size);
                break;
            case 'q':
                int N;
                cout << "Введіть число N(0-7483650):" ;
                cin >> N;
                if (N >= 0 && N <= 7483650){
                int result = (N & 1)? count_binary_zeros_or_ones(N) : count_binary_zeros_or_ones(N);
                cout << "Результат: " << result << endl;
                }
                else {
                cout << "Помилка. Введіть валідне число" << endl;
                }
                break;
            default:
                Beep(1000, 500);
                break;
        }
    }

    return 0;
}

