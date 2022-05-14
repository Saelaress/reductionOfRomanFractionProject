#pragma once
using namespace std;

/*! ��������� ������� �����
*	\param[in] romanFraction - ����� � ������� ��
*	\return - ������ � ����������� ������
*	\throw - (����������� ���������� � ������ ������)
*/
string reductionOfRomanFraction(string romanFraction);

/*! ��������� ���������� ������ �� ������������
*	\param[in] romanFraction - ����� � ������� ��
*	\throw - (����������� ���������� � ������ ������)
*/
void isContentOfStringCorrect(string romanFraction);

/*! ��������� �������� �� ����� �������� ���
*	\param[in] romNum - ������� �����
*	\throw - (����������� ���������� � ������ ������)
*/
void isRomNumCorrect(string romNum);

/*! ��������� ����� �� ��� � ���
*	\param[in] romNum - ������� �����
*	\return - ���������� �����
*	\throw - (����������� ���������� � ������ ������)
*/
int convertNumFromRomToDec(string romNum);

/*! ������� ���������� ����� �������� (���)
*	\param[in] numerator - ���������
*	\param[in] denominator - �����������
*	\return - ���
*	\throw - (����������� ���������� � ������ ������)
*/
int findGCD(int numerator, int denominator);

/*! ��������� ����� �� ��� � ���
*	\param[in] romNum - ���������� �����
*	\return - ������� �����
*	\throw - (����������� ���������� � ������ ������)
*/
string convertNumFromDecToRom(int decNum);
