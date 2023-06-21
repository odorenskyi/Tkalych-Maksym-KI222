#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "ModulesTkalych.h"
using namespace std;

int main() {
    const string TestsFileFolder = "D:\\BMTP\\Tkalych-Maksym-KI222\\lab12\\prj\\TestSuite\\Tests.txt";
    const string TestsResultFileFolder = "D:\\BMTP\\Tkalych-Maksym-KI222\\lab12\\prj\\TestSuite\\TestResults.txt";
    string filePath = __FILE__; // перевірка шляху компліюємого файлу
    size_t checking = filePath.find("\\prj"); // перевірка чи є prj в шляху
    if (checking == string::npos) {
        for (int i = 0; i < 100; i++) {
            MessageBeep(MB_ICONERROR);
        }
        ofstream outputFile(TestsResultFileFolder);
        if (outputFile.is_open()) {
            outputFile << "Встановлені вимоги порядку виконання лабораторної роботи порушено!";
            outputFile.close();
        } else {
            cout << "Не вдалося відкрити файл для запису" << endl;
        }
    } else {
        // Зчитування тестових значень
        ifstream inputFile(TestsFileFolder);
        if (inputFile.is_open()) {
            float edgeLength;
            int testCount = 1;

            ofstream outputFile(TestsResultFileFolder);
            if (outputFile.is_open()) {
                while (inputFile >> edgeLength) {
                    // Створення об'єкту класу
                    ClassLab12Tkalych obj(edgeLength);
                    // Запис результатів до файлу
                    outputFile << "Тест №: " << testCount << ", Довжина ребра: " << obj.getEdgeLength()<< ", Результат: " << obj.calculateVolume() << endl;
                    testCount++;
                }
                outputFile.close();
            } else {
                cout << "Не вдалося відкрити файл для запису" << endl;
            }
            inputFile.close();
        } else {
            cout << "Не вдалося відкрити файл для зчитування" << endl;
        }
    }

    return 0;
}
