#ifndef MODULESTKALYCH_H_INCLUDED
#define MODULESTKALYCH_H_INCLUDED

#include <cmath>

class ClassLab12Tkalych {
private:
    float edgeLength;

public:
    ClassLab12Tkalych(float length) {
        edgeLength = length;
    }

    void setEdgeLength(float length) {
        edgeLength = length;
    }

    float getEdgeLength() {
        return edgeLength;
    }

    float calculateVolume() {
        return pow(edgeLength, 3);
    }
};

#endif // MODULESTKALYCH_H_INCLUDED
