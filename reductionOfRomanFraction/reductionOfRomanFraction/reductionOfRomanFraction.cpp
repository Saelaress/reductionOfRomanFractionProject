﻿#include <iostream>
#include <string>
#include <fstream>
#include "reductionOfRomanFraction.h"

using namespace std;

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus");

    //Выдать ошибку, если входной файл не указан в аргументах командной строки
    if (argc == 1)
    {
        cout << "Входной файл не указан." << endl;
        return 0;
    }
    
    //Выдать ошибку, если входной файл невозможно открыть
    string path = argv[1];

    ifstream fin;
    fin.open(path);

    if (!fin.is_open())
    {
        cout << "Входной файл " << path << " невозможно открыть." << endl;
        return 0;
    }

    //Считать строку с дробью из файла
    string fraction;

    getline(fin, fraction);
    cout << fraction << endl;

    fin.close();

    string newFraction;
    try
    {
    //Сократить дробь
    newFraction = reductionOfRomanFraction(fraction);
    }

    //Обработать исключения
    catch (int ex)
    {
        if (ex == 7)
            cout << "Несократимая дробь!" << endl;
    }

    //Записать сокращенную дробь в выходной файл
    string outPath = "C:\\Users\\User\\Desktop\\Universitet\\2_kurs_2_sem\\knpo\\reducedFraction.txt";
    
    ofstream fout;
    fout.open(outPath);
    fout << newFraction;
    fout.close();
}

string reductionOfRomanFraction(string romanFraction)
{
    //Проверить строку на корректность
    isContentOfStringCorrect(romanFraction);

    //Разделить строку на числитель и знаменатель
    string numerator;
    string denominator;

    auto pos = romanFraction.find("/");
    if (pos != string::npos)
    {
        numerator = romanFraction.substr(0, pos);
        denominator = romanFraction.substr(pos + 1);
    }

    //Проверить отвечают ли числитель и знаменатель принципам РСС
    isRomNumCorrect(numerator);
    isRomNumCorrect(denominator);

    //Перевести числитель и знаменатель из РСС в ДСС
    int decNumerator = convertNumFromRomToDec(numerator);
    int decDenominator = convertNumFromRomToDec(denominator);

    //Найти наибольший общий делитель(НОД)
    int GCD = findGCD(decNumerator, decDenominator);

    //Если НОД равен 1, и не равен знаменателю, выбросить исключение
    if (GCD = 1)
    {
        throw 7;
    }

    //Разделить числитель и знаменатель на НОД
    int newDecNumerator = decNumerator / GCD;
    int newDecDenominator = decDenominator / GCD;

    //Перевести из ДСС в РСС оба числа
    string newNumerator = convertNumFromDecToRom(newDecNumerator);
    string newDenominator = convertNumFromDecToRom(newDecDenominator);

    string reducedFraction = newNumerator + "/" + newDenominator;
    //Если знаменатель равен I
    if (newDenominator == "I")
    {
        //Вернуть числитель в Римской СС
        return newNumerator;
    }

    //Иначе вернуть строку из числителя, знака "/" и знаменателя без пробелов
    else return reducedFraction;
}

void isContentOfStringCorrect(string romanFraction) {

}

void isRomNumCorrect(string romNum) {

}

int convertNumFromRomToDec(string romNum) {
    return 0;
}

int findGCD(int numerator, int denominator) {
    return 0;
}

string convertNumFromDecToRom(int decNum) {
    return 0;
}