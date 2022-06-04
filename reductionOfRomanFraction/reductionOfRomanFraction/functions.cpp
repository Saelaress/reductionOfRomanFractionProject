#include "reductionOfRomanFraction.h"

string reductionOfRomanFraction(string romanFraction)
{
    //��������� ������ �� ������������
    isContentOfStringCorrect(romanFraction);

    //��������� ������ �� ��������� � �����������
    string numerator;
    string denominator;

    auto pos = romanFraction.find("/");
    if (pos != string::npos)
    {
        numerator = romanFraction.substr(0, pos);
        denominator = romanFraction.substr(pos + 1);
    }

    //��������� �������� �� ��������� � ����������� ��������� ���
    isRomNumCorrect(numerator);
    isRomNumCorrect(denominator);

    //��������� ��������� � ����������� �� ��� � ���
    int decNumerator = convertNumFromRomToDec(numerator);
    int decDenominator = convertNumFromRomToDec(denominator);

    //����� ���������� ����� ��������(���)
    int GCD = findGCD(decNumerator, decDenominator);

    //���� ��� ����� 1, � �� ����� �����������, ��������� ����������
    if (GCD == 1 && GCD != decDenominator)
    {
        throw 7;
    }

    //��������� ��������� � ����������� �� ���
    int newDecNumerator = decNumerator / GCD;
    int newDecDenominator = decDenominator / GCD;

    //��������� �� ��� � ��� ��� �����
    string newNumerator = convertNumFromDecToRom(newDecNumerator);
    string newDenominator = convertNumFromDecToRom(newDecDenominator);

    string reducedFraction = newNumerator + "/" + newDenominator;
    //���� ����������� ����� I
    if (newDenominator == "I")
    {
        //������� ��������� � ������� ��
        return newNumerator;
    }

    //����� ������� ������ �� ���������, ����� "/" � ����������� ��� ��������
    else return reducedFraction;
}

void isContentOfStringCorrect(string romanFraction)
{

    bool isSlashFind = 0;
    int lengthStr = size(romanFraction);
    //��� ������� ������� ������
    for (int i = 0; i < lengthStr; i++)
    {
        /*��������� ����������, ���� ������ ������, ������� �� �������� �������� M, D, C, L, X, V, I ��� /,
        ���� ���� ������ ������� ������, � ������� ������ - /,
        ���� ������, ��� ��������� ������ - /
        */
        if (strchr("MDCLXVI/", romanFraction[i]) == 0 || isSlashFind == 1 && romanFraction[i] == '/'
            || (romanFraction[lengthStr - 1] == '/' || romanFraction[0] == '/'))
        {
            throw 1;
        }
        //���� ������ ������ /, ���������� ���� ������� ������� ������
        if (romanFraction[i] == '/')
        {
            isSlashFind = 1;
        }
    }
    //��������� ����������, ���� �� ������ ������ ������� /
    if (isSlashFind == 0)
    {
        throw 1;
    }
}

void isRomNumCorrect(string romNum)
{
    //��������� ����������, ���� ������ �������� "VV", ��� "LL", ��� "DD".
    if (romNum.find("VV") != -1 || romNum.find("LL") != -1 || romNum.find("DD") != -1)
    {
        throw 2;
    }

    //��������� ����������, ���� ������ �������� "IIII", ��� "XXXX", ��� "CCCC".
    if (romNum.find("IIII") != -1 || romNum.find("XXXX") != -1 || romNum.find("CCCC") != -1)
    {
        throw 3;
    }

    /*��������� ����������, ���� ������ �������� "IL", ��� "IC", ��� "ID", ��� "IM", ��� "VX", ��� "VL",
    ��� "VC", ��� "VD", ��� "VM", ��� "XD", ��� "XM", ��� "LC", ��� "LD", ��� "LM", ��� "DM".
    */
    if (romNum.find("IL") != -1 || romNum.find("IC") != -1 || romNum.find("ID") != -1 || romNum.find("IM") != -1
        || romNum.find("VX") != -1 || romNum.find("VL") != -1 || romNum.find("VC") != -1 || romNum.find("VD") != -1
        || romNum.find("VM") != -1 || romNum.find("XD") != -1 || romNum.find("XM") != -1 || romNum.find("LC") != -1
        || romNum.find("LD") != -1 || romNum.find("LM") != -1 || romNum.find("DM") != -1)
    {
        throw 4;
    }
    //���� � ������ ��� ��� ������ ��������
    int lengthRomNum = size(romNum);
    if (lengthRomNum >= 3)
    {
        //��� ������� �������, ������� � ��������, �� ����������
        for (int i = 2; i < lengthRomNum; i++)
        {
            //��������� ����������, ���� ������� ������, ������������ � ��� ������ ����������� � ����� ���������������
            if (romDecMap.find(romNum[i])->second < romDecMap.find(romNum[i - 1])->second &&
                romDecMap.find(romNum[i])->second == romDecMap.find(romNum[i - 2])->second)
            {
                throw 5;
            }
            //��������� ����������, ���� ������� ������, ������������ � ���, ������ ����������� � ��������������� �������,
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
    //����������� ������
    int length = size(romNum);

    for (int i = 0, j = length - 1; i < j; i++, j--)
    {
        char temp = romNum[i];
        romNum[i] = romNum[j];
        romNum[j] = temp;
    }

    //������� ������� ������ ������������� ����� � ��� ��� ������� �������
    int decNum = romDecMap.find(romNum[0])->second;

    //��� ������� ������� ������, ������� �� �������
    for (int i = 1; i < length; i++)
    {
        //����� ������������� ����� � ���
        int equiDec = romDecMap.find(romNum[i])->second;

        //���� ��� ����� ����� 1 ��� 10 ��� 100 � ������ �����������, ������� ��� �� �������� �������� �������� �����
        if ((equiDec == 1 || equiDec == 10 || equiDec == 100) && equiDec < romDecMap.find(romNum[i - 1])->second)
        {
            decNum -= equiDec;
        }
        //����� ��������� ��� � �������� �������� �������� �����
        else decNum += equiDec;
    }
    //���� ������� ����� ������ 3999, ��������� ����������
    if (decNum > 3999) throw 8;
    //����� ������� ������� �����
    else return decNum;
}

int findGCD(int numerator, int denominator)
{
    //���� ��������� � ����������� �� ����� ����
    while (numerator != 0 && denominator != 0)
    {
        //���� ��������� ������ �����������, ��������� ������� �� ������� ���������
        if (numerator > denominator) numerator %= denominator;

        //����� ��������� ������� �� ������� �����������
        else denominator %= numerator;
    }
        //������� ����� ��������� � �����������
        return numerator + denominator;
}

string convertNumFromDecToRom(int decNum)
{
    //��������� ����� �� ��������
    int thousends = decNum / 1000;
    int hundreds = decNum % 1000 / 100;
    int tens = decNum % 100 / 10;
    int units = decNum % 10;

    //��������� ����� ������� ����� �� 1000, ����� �� 100, �������� �� 10
    thousends *= 1000;
    hundreds *= 100;
    tens *= 10;

    //�������� ������� ���������� ����� ��� �����, �����, �������� � ������
    string thousendsRom = decRomMap.find(thousends)->second;
    string hundredsRom = decRomMap.find(hundreds)->second;
    string tensRom = decRomMap.find(tens)->second;
    string unitsRom = decRomMap.find(units)->second;
    //������� ������, �� ����� ����� ���� ��������
    return thousendsRom + hundredsRom + tensRom + unitsRom;
}