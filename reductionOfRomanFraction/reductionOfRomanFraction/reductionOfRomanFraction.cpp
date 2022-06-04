#include <iostream>
#include <fstream>
#include "reductionOfRomanFraction.h"

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus");

    //Выдать ошибку, если входной файл не указан в аргументах командной строки
    if (argc < 2)
    {
        cout << "Program's argument is empty. Enter name of the input file that contains roman fraction" << endl;
        return 0;
    }

    //Выдать ошибку, если выходной файл не указан в аргументах командной строки
    if (argc < 3)
    {
        cout << "Program's argument is empty. Enter name of the output file" << endl;
        return 0;
    }

    //Выдать ошибку, если входной файл невозможно открыть
    string inputPath = argv[1];

    ifstream fin;
    fin.open(inputPath);

    if (!fin.is_open())
    {
        cout << "Input file was not opened!" << endl;
        return 0;
    }

    //Считать строку с дробью из файла
    string fraction;

    getline(fin, fraction);
    
    //Выдать ошибку, если в файл пустой
    if (fraction == "")
    {
        cout << "There is no data in the input file. Enter a fraction in the Roman numeral system!" << endl;
        return 0;
    }

    //Выдать ошибку, если в файле больше одной строки
    if (!fin.eof())
    {
        cout << "The program accepts files from one line as input. Place each line in a separate file." << endl;
        return 0;
    }

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
        switch (ex)
        {
        case 1:
            cout << "Error in writing Roman fractions!" << endl;
            break;
        case 2:
            cout << "Characters V,L,D cannot be repeated!" << endl;
            break;
        case 3:
            cout << "Symbols I,X,C cannot be repeated more than 3 times!" << endl;
            break;
        case 4:
            cout << "Combinations not allowed: IL, IC, ID, IM, VX, VL, VC, VD, VM, XD, XM, LC, LD, LM, DM." << endl;
            break;
        case 5:
            cout << "A larger symbol cannot be between two identical smaller ones!" << endl;
            break;
        case 6:
            cout << "A larger character cannot be written after two smaller ones!" << endl;
            break;
        case 7:
            cout << "Irreducible fraction!" << endl;
            break;
        case 8:
            cout << "The number is greater than the maximum!" << endl;
            break;
        }
        return 0;
    }

    //Записать сокращенную дробь в выходной файл
    string outPath = argv[2];
    
    ofstream fout;
    fout.open(outPath);

    if (!fout.is_open())
    {
        cout << "Output file was not opened!" << endl;
        return 0;
    }

    fout << newFraction;
    fout.close();
}

