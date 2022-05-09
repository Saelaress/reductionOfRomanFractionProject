#include <iostream>
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

    //Сократить дробь
    string newFraction = reductionOfRomanFraction(fraction);
    //Записать сокращенную дробь в выходной файл
    string outPath = "C:\\Users\\User\\Desktop\\Universitet\\2_kurs_2_sem\\knpo\\reducedFraction.txt";
    
    ofstream fout;
    fout.open(outPath);
    fout << newFraction;
    fout.close();

    //Обработать исключения

}

string reductionOfRomanFraction(string romanFraction)
{
    string reducedFraction = "III";
    return reducedFraction;
}