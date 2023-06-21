#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "ModulesTkalych.h"
using namespace std;

int main() {
    const string TestsFileFolder = "D:\\BMTP\\Tkalych-Maksym-KI222\\lab12\\prj\\TestSuite\\Tests.txt";
    const string TestsResultFileFolder = "D:\\BMTP\\Tkalych-Maksym-KI222\\lab12\\prj\\TestSuite\\TestResults.txt";
    string filePath = __FILE__; // �������� ����� ����������� �����
    size_t checking = filePath.find("\\prj"); // �������� �� � prj � �����
    if (checking == string::npos) {
        for (int i = 0; i < 100; i++) {
            MessageBeep(MB_ICONERROR);
        }
        ofstream outputFile(TestsResultFileFolder);
        if (outputFile.is_open()) {
            outputFile << "���������� ������ ������� ��������� ����������� ������ ��������!";
            outputFile.close();
        } else {
            cout << "�� ������� ������� ���� ��� ������" << endl;
        }
    } else {
        // ���������� �������� �������
        ifstream inputFile(TestsFileFolder);
        if (inputFile.is_open()) {
            float edgeLength;
            int testCount = 1;

            ofstream outputFile(TestsResultFileFolder);
            if (outputFile.is_open()) {
                while (inputFile >> edgeLength) {
                    // ��������� ��'���� �����
                    ClassLab12Tkalych obj(edgeLength);
                    // ����� ���������� �� �����
                    outputFile << "���� �: " << testCount << ", ������� �����: " << obj.getEdgeLength()<< ", ���������: " << obj.calculateVolume() << endl;
                    testCount++;
                }
                outputFile.close();
            } else {
                cout << "�� ������� ������� ���� ��� ������" << endl;
            }
            inputFile.close();
        } else {
            cout << "�� ������� ������� ���� ��� ����������" << endl;
        }
    }

    return 0;
}
