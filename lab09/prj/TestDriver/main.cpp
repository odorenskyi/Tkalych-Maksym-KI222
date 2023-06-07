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
    cout << "������ ������� ������������� ��� �� ���� ��� ����: ";
    cin >> worked_days;
    double expected_result;
    cout << "������ ����������� ���������: ";
    cin >> expected_result;
    if (salary_calculate(worked_days)==expected_result)
        cout << "Status: Passed" << endl;
    else
        cout << "Status: Failed" << endl;


    int ukr_size;
    cout << "������ ������ �� ���������� ��������: 23,25,27,29,31" << endl;
    cout << "������ ��� �����: ";
    cin >> ukr_size;
    foot_size(ukr_size);


    int N;
    cout << "������ ����� N(0-7483650):" ;
    cin >> N;
    if (N >= 0 && N <= 7483650){
    int result = (N & 1)? count_binary_zeros_or_ones(N) : count_binary_zeros_or_ones(N);
    cout << "���������: " << result << endl;
    }
    else {
        cout << "�������. ������ ������ �����" << endl;
    }
    }
    return 0;

}

