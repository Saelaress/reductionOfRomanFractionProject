#include <iostream>
#include <string>
#include <fstream>
#include "reductionOfRomanFraction.h"
#include <map>

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
        if (ex == 1)
            cout << "Ошибка в записи римской дроби!" << endl;
        if (ex == 2)
            cout << "Символы V,L,D не могут повторяться!" << endl;
        if (ex == 3)
            cout << "Символы I,X,C не могут повторяться больше 3х раз!" << endl;
        if (ex == 4)
            cout << "Недопустимы сочетания: IL, IC, ID, IM, VX, VL, VC, VD, VM, XD, XM, LC, LD, LM, DM" << endl;
        if (ex == 5)
            cout << "Больший символ не может находиться между двумя одинаковыми меньшими!" << endl;
        if (ex == 6)
            cout << "Больший символ не может быть записан после двух меньших!" << endl;
        if (ex == 7)
            cout << "Несократимая дробь!" << endl;
        return 0;
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

void isContentOfStringCorrect(string romanFraction) 
{
    
    bool isSlashFind = 0;
    int lengthStr = size(romanFraction);
    //Для каждого символа строки
    for (int i = 0; i < lengthStr; i++)
    {
        /*Выбросить исключение, если найден символ, который не является символом M, D, C, L, X, V, I или /,
        либо если символ деления найден, и текущий символ - /,
        либо первый, или последний символ - /
        */
        if (strchr("MDCLXVI/", romanFraction[i])==0 || isSlashFind == 1 && romanFraction[i]=='/' 
            || (romanFraction[lengthStr] == '/' || romanFraction[0] == '/'))
        {
            throw 1;
        }
        //Если найден символ /, установить флаг «символ деления найден»
        if (romanFraction[i] == '/') 
        {
            isSlashFind = 1;
        }
    }
    //Выбросить исключение, если не найден символ деления /
    if (isSlashFind == 0) 
    {
        throw 1;
    }
}

void isRomNumCorrect(string romNum) 
{
    //Выбросить исключение, если строка содержит "VV", или "LL", или "DD".
    if (romNum.find("VV") == 0 || romNum.find("LL") == 0 || romNum.find("DD") == 0)
    {
        throw 2;
    }

    //Выбросить исключение, если строка содержит "IIII", или "XXXX", или "CCCC".
    if (romNum.find("IIII") == 0 || romNum.find("XXXX") == 0 || romNum.find("CCCC") == 0)
    {
        throw 3;
    }

    /*Выбросить исключение, если строка содержит "IL", или "IC", или "ID", или "IM", или "VX", или "VL", 
    или "VC", или "VD", или "VM", или "XD", или "XM", или "LC", или "LD", или "LM", или "DM".
    */
    if (romNum.find("IL") == 0 || romNum.find("IC") == 0 || romNum.find("ID") == 0 || romNum.find("IM") == 0
        || romNum.find("VX") == 0 || romNum.find("VL") == 0 || romNum.find("VC") == 0 || romNum.find("VD") == 0
        || romNum.find("VM") == 0 || romNum.find("XD") == 0 || romNum.find("XM") == 0 || romNum.find("LC") == 0
        || romNum.find("LD") == 0 || romNum.find("LM") == 0 || romNum.find("DM") == 0)
    {
        throw 4;
    }
    //Если в строке три или больше символов
    int lengthRomNum = size(romNum);
    if(lengthRomNum >= 3)
    {
        //Для каждого символа, начиная с третьего, до последнего
        for (int i=2; i < lengthRomNum; i++)
        {
            //Выбросить исключение, если текущий символ, переведенный в ДСС меньше предыдущего и равен предпредыдущему
            if (romDecMap.find(romNum[i])->second < romDecMap.find(romNum[i - 1])->second && 
                romDecMap.find(romNum[i])->second == romDecMap.find(romNum[i - 2])->second)
            {
                throw 5;
            }
            //Выбросить исключение, если текущий символ, переведенный в ДСС, больше предыдущего и предпредыдущего символа,
            if (romDecMap.find(romNum[i])->second > romDecMap.find(romNum[i - 1])->second &&
                romDecMap.find(romNum[i])->second > romDecMap.find(romNum[i - 2])->second)
            {
                throw 6;
            }
        }
    }
}

int convertNumFromRomToDec(string romNum) 
{
    return 0;
}

int findGCD(int numerator, int denominator) 
{
    return 0;
}

string convertNumFromDecToRom(int decNum) 
{
    return 0;
}

