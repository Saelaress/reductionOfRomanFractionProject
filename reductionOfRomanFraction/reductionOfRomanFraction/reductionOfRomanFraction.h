#pragma once
using namespace std;
#include <map>

/*! Сокращает римскую дробь
*	\param[in] romanFraction - дробь в римской СС
*	\return - строка с сокращённой дробью
*	\throw - (Выбрасывает исключения в случае ошибок)
*/
string reductionOfRomanFraction(string romanFraction);

/*! Проверяет содержимое строки на корректность
*	\param[in] romanFraction - дробь в римской СС
*	\throw - (Выбрасывает исключения в случае ошибок)
*/
void isContentOfStringCorrect(string romanFraction);

/*! Проверяет отвечает ли число приципам РСС
*	\param[in] romNum - римское число
*	\throw - (Выбрасывает исключения в случае ошибок)
*/
void isRomNumCorrect(string romNum);

/*! Переводит число из РСС в ДСС
*	\param[in] romNum - римское число
*	\return - десятичное число
*	\throw - (Выбрасывает исключения в случае ошибок)
*/
int convertNumFromRomToDec(string romNum);

/*! Находит наибольший общий делитель (НОД)
*	\param[in] numerator - числитель
*	\param[in] denominator - знаменатель
*	\return - НОД
*	\throw - (Выбрасывает исключения в случае ошибок)
*/
int findGCD(int numerator, int denominator);

/*! Переводит число из ДСС в РСС
*	\param[in] romNum - десятичное число
*	\return - римское число
*	\throw - (Выбрасывает исключения в случае ошибок)
*/
string convertNumFromDecToRom(int decNum);

map<char, int> romDecMap{
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

map<int, string> decRomMap{
    {0, ""},
    {1, "I"},
    {2, "II"},
    {3, "III"},
    {4, "IV"},
    {5, "V"},
    {6, "VI"},
    {7, "VII"},
    {8, "VIII"},
    {9, "IX"},
    {10, "X"},
    {20, "XX"},
    {30, "XXX"},
    {40, "XL"},
    {50, "L"},
    {60, "LX"},
    {70, "LXX"},
    {80, "LXXX"},
    {90, "XC"},
    {100, "C"},
    {200, "CC"},
    {300, "CCC"},
    {400, "CD"},
    {500, "D"},
    {600, "DC"},
    {700, "DCC"},
    {800, "DCCC"},
    {900, "CM"},
    {1000, "M"},
    {2000, "MM"},
    {3000, "MMM"}
};