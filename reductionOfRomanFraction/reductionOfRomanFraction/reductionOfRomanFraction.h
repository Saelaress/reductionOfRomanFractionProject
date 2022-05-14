#pragma once
using namespace std;

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
