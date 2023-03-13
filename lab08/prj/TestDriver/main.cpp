#include <iostream>
#include "ModulesTkalych.h"

using namespace std;

int main()
{
    for(int i=0; i<5; i++){
        int x,y,z;
        float result;
        cout << "Enter x" << endl;
        cin >> x;
        cout << "Enter y" << endl;
        cin >> y;
        cout << "Enter z" << endl;
        cin >> z;
        cout << s_calculation(x,y,z) << endl;
        if(z<0){
            cout << "Error. z cannot be less than 0" <<endl;
            continue;
        }
        cout << "Enter result" <<endl;
        cin >> result;
        if(result == s_calculation(x,y,z)){
            cout << "Status: passed" << endl;
        }
        else{
            cout << "Status: failed" << endl;

        }
    }


}
