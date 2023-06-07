#include <iostream>
#include "ModulesTkalych.h"
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    for (int i=0; i<5; i++)
    {
    int worked_days;
    cout << "Введіть кількість відпрацьованих днів за звітні два тижні: ";
    cin >> worked_days;
    double expected_result;
    cout << "Введіть очікуванний результат: ";
    cin >> expected_result;
    if (salary_calculate(worked_days)==expected_result)
        cout << "Status: Passed" << endl;
    else
        cout << "Status: Failed" << endl;


    int ukr_size;
    cout << "Список розмірів за українською системою: 23,25,27,29,31" << endl;
    cout << "Введіть ваш розмір: ";
    cin >> ukr_size;
    foot_size(ukr_size);


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
    }
    return 0;

}

