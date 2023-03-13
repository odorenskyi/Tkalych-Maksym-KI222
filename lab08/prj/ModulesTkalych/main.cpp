#include <cmath>
#define _USE_MATH_DEFINES
float s_calculation(int x, int y, int z){
    if(z>0){
        float result;
        result = pow((z+y+z),2)-((2*M_PI)*pow(((1/3) * z),1/2));
        return round(result*10000)/10000;
    }
    else
        return NAN;
}
