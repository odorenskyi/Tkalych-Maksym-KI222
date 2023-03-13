#include <iostream>
#include "ModulesTkalych.h"
#include <Windows.h>

using namespace std;

string copyright(){
    return "Tkalych Maksym. All rights are reserved  ©";
}

bool boolean_expression(char a, char b){
    return a+1<b;
}

float number_translation(int x, int y, int z){
    cout << "x = " << dec << x << " In hexadecimal system: " << hex << x << endl;
    cout << "y = " << dec << y << " In hexadecimal system: " << hex << y << endl;
    cout << "z = " << dec << z << " In hexadecimal system: " << hex << z << endl;
    return s_calculation(x,y,z);}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int x, y, z;
    char a,b;
    cout << copyright() << endl;
    cout << "Enter a,b" << endl;
    cin >> a >> b;
    cout << boolean_expression(a,b) << endl;
    cout << "Enter x,y,z" << endl;
    cin >> x >> y >> z;
    cout << number_translation(x,y,z) << endl;
    return 0;
}
