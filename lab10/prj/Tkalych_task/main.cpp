#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include "ModulesTkalych.h"
#include <bitset>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    // Відкриваємо вхідний файл
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Не вдалося відкрити вхідний файл" << endl;
        return 1;
    }

    // Зчитуємо текст з вхідного файлу
    string inputText;
    getline(inputFile, inputText, '\0');

    // Визначаємо, до якої мови належить текст
    bool isUkrainian = false;
    for (char c : inputText) {
        if ((c >= 0x0400 && c <= 0x04FF) || (c >= 0x0500 && c <= 0x052F) || (c == 0x0456) || (c == 0x0491) || (c == 0x0490) || (c == 0x0407) || (c == 0x0406)) {
            isUkrainian = true;
            break;
        }
    }

    // Закриваємо вхідний файл
    inputFile.close();

    // Відкриваємо вихідний файл
    ofstream outputFile("output.txt", ios::out);
    if (!outputFile) {
        cerr << "Не вдалося відкрити вихідний файл" << endl;
        return 1;
    }

    // Додаємо маркер порядку байтів UTF-8 до вихідного файлу
    outputFile << char(0xEF) << char(0xBB) << char(0xBF);

    // Підраховуємо кількість ком та крапок у тексті
    int numCommas = 0;
    int numPeriods = 0;
    for (char c : inputText) {
        if (c == ',') {
            numCommas++;
        } else if (c == '.') {
            numPeriods++;
        }
    }

    // Запис до файлу інформації про автора
    cout << "Developed by Maksym Tkalych \nCNTU\nKropyvnytskiy\nUkraine\n2023\n"  << endl;
    outputFile << "Developed by Maksym Tkalych \nCNTU\nKropyvnytskiy\nUkraine\n2023\n"  << endl;

    // Виводимо кількість ком та крапок у консоль
    cout << "Count of commas: " << numCommas << endl;
    cout << "Count of dots: " << numPeriods << endl;

    // Записуємо кількість ком та крапок у вихідний файл
    outputFile << "Count of commas: " << numCommas << endl;
    outputFile << "Count of dots: " << numPeriods << endl;

    // Виводимо дату та час дозапису у консоль
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);
    cout << "Date and time of addition: " << asctime(localTime) << endl;

    // Записуємо дату та час дозапису у вихідний файл
    outputFile << "Date and time of addition: " << asctime(localTime) << endl;

    // Змінюємо порядок абзаців у тексті
    vector<string> paragraphs;
    size_t start = 0;
    size_t end = inputText.find("\n\n");
    while (end != string::npos) {
        paragraphs.push_back(inputText.substr(start, end - start));
        start = end + 2;
        end = inputText.find("\n\n", start);
    }
    paragraphs.push_back(inputText.substr(start));
    reverse(paragraphs.begin(), paragraphs.end());

    // Виводимо змінений текст у консоль
    for (const string& paragraph : paragraphs) {
        cout << paragraph << endl << endl;
    }

    // Записуємо змінений текст у вихідний файл
    for (const string& paragraph : paragraphs) {
        outputFile << paragraph << endl << endl;
    }

    // Записуємо інформацію про мову тексту у вихідний файл
    if (isUkrainian) {
        outputFile << "Text language: Ukrainian\n";
    } else {
        outputFile << "Text language: English\n";
    }

    // Виводимо рік
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int year = 1900 + ltm->tm_year;
    cout << "Year of development: " << year << endl;

    // Зчитуємо вхідні дані
    int x = 2, y=12, z = 3;
    int b = 25;
    inputFile >> x >> z >> b;
    double result = s_calculation(x,y,z);

    // Записуємо результат вихідної функції у вихідний файл
    outputFile << "Result of  s_calculation with agruments x = " << x << ", y = " << y << ",  z = " << z << " equals " << result << endl;

    // Конвертуємо число b в двійковий формат та записуємо його у вихідний файл
    string binary = bitset<32>(b).to_string();
    outputFile << "Number" << b << " in binary: " << binary << endl;

    // Закриваємо вхідний файл
    inputFile.close();

    // Закриваємо вихідний файл
    outputFile.close();

    return 0;
}
