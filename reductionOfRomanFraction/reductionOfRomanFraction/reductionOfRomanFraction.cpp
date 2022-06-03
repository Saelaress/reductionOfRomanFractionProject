#include <iostream>
#include <string>
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
    if (GCD == 1 && GCD != decDenominator)
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
            || (romanFraction[lengthStr-1] == '/' || romanFraction[0] == '/'))
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
    if (romNum.find("VV") != -1 || romNum.find("LL") != -1 || romNum.find("DD") != -1)
    {
        throw 2;
    }

    //Выбросить исключение, если строка содержит "IIII", или "XXXX", или "CCCC".
    if (romNum.find("IIII") != -1 || romNum.find("XXXX") != -1 || romNum.find("CCCC") != -1)
    {
        throw 3;
    }

    /*Выбросить исключение, если строка содержит "IL", или "IC", или "ID", или "IM", или "VX", или "VL", 
    или "VC", или "VD", или "VM", или "XD", или "XM", или "LC", или "LD", или "LM", или "DM".
    */
    if (romNum.find("IL") != -1 || romNum.find("IC") != -1 || romNum.find("ID") != -1 || romNum.find("IM") != -1
        || romNum.find("VX") != -1 || romNum.find("VL") != -1 || romNum.find("VC") != -1 || romNum.find("VD") != -1
        || romNum.find("VM") != -1 || romNum.find("XD") != -1 || romNum.find("XM") != -1 || romNum.find("LC") != -1
        || romNum.find("LD") != -1 || romNum.find("LM") != -1 || romNum.find("DM") != -1)
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
    //Перевернуть строку
    int length = size(romNum);

    for (int i = 0, j = length - 1; i < j; i++, j--)
    {
        char temp = romNum[i];
        romNum[i] = romNum[j];
        romNum[j] = temp;
    }
    
    //Считать искомым числом эквивалентное число в ДСС для первого символа
    int decNum = romDecMap.find(romNum[0])->second;

    //Для каждого символа строки, начиная со второго
    for (int i = 1; i < length; i++)
    {
        //Найти эквивалентное число в ДСС
        int equiDec = romDecMap.find(romNum[i])->second;

        //Если это число равно 1 или 10 или 100 и меньше предыдущего, вычесть его из текущего значения искомого числа
        if ((equiDec == 1 || equiDec == 10 || equiDec == 100) && equiDec < romDecMap.find(romNum[i-1])->second)
        {
            decNum -= equiDec;
        }
        //Иначе прибавить его к текущему значению искомого числа
        else decNum += equiDec;
    }
    //Если искомое число больше 3999, выбросить исключение
    if (decNum > 3999) throw 8;
    //Иначе вернуть искомое число
    else return decNum;
}

int findGCD(int numerator, int denominator) 
{
    int lesserNumber, GCD;
    //Если числитель меньше знаменателя
    if (numerator < denominator)
    {
        //Считать меньшим числом - числитель
        lesserNumber = numerator;
    }

    //Иначе считать меньшим числом знаменатель
    else lesserNumber = denominator;

    //Для каждого числа, начиная с единицы, вплоть до меньшего числа
    for (int i = 1; i <= lesserNumber; i++)
    {
      //Если числитель делится нацело на текущее число
      if (numerator%i == 0)
      {
          //Если знаменатель делится нацело на текущее число
          if (denominator%i == 0)
          {
              //Cчитать текущее число — НОД
              GCD = i;
          }
      }
    }
    //Вернуть НОД
    return GCD;
}

string convertNumFromDecToRom(int decNum) 
{
    //Разделить число по разрядам
    int thousends = decNum / 1000;
    int hundreds = decNum % 1000 / 100;
    int tens = decNum % 100 / 10;
    int units = decNum % 10;

    //Домножить число разряда тысяч на 1000, сотен на 100, десятков на 10
    thousends *= 1000;
    hundreds *= 100;
    tens *= 10;

    //Получить римский эквивалент числа для тысяч, сотен, десятков и единиц
    string thousendsRom = decRomMap.find(thousends)->second;
    string hundredsRom = decRomMap.find(hundreds)->second;
    string tensRom = decRomMap.find(tens)->second;
    string unitsRom = decRomMap.find(units)->second;
    //Вернуть строку, из суммы строк всех разрядов
    return thousendsRom + hundredsRom + tensRom + unitsRom;
}

