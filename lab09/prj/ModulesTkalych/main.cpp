#include <cmath>
#include <iostream>
#define _USE_MATH_DEFINES
using namespace std;

float s_calculation(int x, int y, int z){
    if(z>0){
        float result;
        result = pow((z+y+z),2)-((2*M_PI)*pow(((1/3) * z),1/2));
        return round(result*10000)/10000;
    }
    else
        return NAN;
}

float salary_calculate(int worked_days) {
    const double hourly_salary = 450.0;
    const int working_days_per_two_weeks = 10;
    const int work_hours_per_day = 8;
    float total_payment = 0.0;

    if (worked_days >= 1) {
        double salary = hourly_salary * worked_days * work_hours_per_day;

        double income_tax = salary * 0.15;
        double pension_fund = salary * 0.02;
        double social_insurance_unemployment_fund = salary * 0.06;
        double social_insurance_temporary_disability = salary * 0.01;

        total_payment = salary - income_tax - pension_fund - social_insurance_unemployment_fund - social_insurance_temporary_disability;

        cout << "���������� �������� ����� ����������: " << salary << " ���." << endl;
        cout << "����� ����������� �������: " << income_tax + pension_fund + social_insurance_unemployment_fund + social_insurance_temporary_disability << " ���."  << endl;
        cout << "���� �� �������: " << total_payment << " ���." << endl;
    } else {
        cout << "�������. ʳ������ ������������� ��� �� ���� ���� ����� 1" << endl;
    }

    return total_payment;
    }

int foot_size(int ukr_size) {
    if (ukr_size>=23 && ukr_size <=31){
    switch(ukr_size){
    case 23:
        cout << "³�������� ����� �� �������� ���: 8, ��: 37,38" << endl;
        break;
    case 25:
        cout << "³�������� ����� �� �������� ���: 9, ��: 39,40" << endl;
        break;
    case 27:
        cout << "³�������� ����� �� �������� ���: 10, ��: 41,42" << endl;
        break;
    case 29:
        cout << "³�������� ����� �� �������� ���: 11, ��: 43,44" << endl;
        break;
    case 31:
        cout << "³�������� ����� �� �������� ���: 12, ��: 45,46" << endl;
        break;
    }
    }
    else{
        cout << "�������. ������ ����� � ������" << endl;
    }

    return 0;
}

int count_binary_zeros_or_ones(int N) {
    int count = 0;
    while (N > 0) {
        int bit = N % 2;
        count += (bit == 0) ? 1 : 0;
        N /= 2;
    }
    return count;
}


