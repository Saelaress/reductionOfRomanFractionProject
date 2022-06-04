#include "pch.h"
#include "CppUnitTest.h"
#include "../reductionOfRomanFraction/reductionOfRomanFraction.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testfindGCD
{
	TEST_CLASS(testfindGCD)
	{
	public:
		
		TEST_METHOD(numeratorAndDenominatorAreSame) //��������� � ����������� ���������
		{
			//���������
			int numerator = 20;

			//�����������
			int denominator = 20;

			//��������� ���
			int expectedGCD = 20;

			//���������� ���
			int GCD = findGCD(numerator, denominator);

			Assert::AreEqual(expectedGCD, GCD);
		}

		TEST_METHOD(numeratorBiggerThenDenominator) //��������� ������ �����������
		{
			//���������
			int numerator = 15;

			//�����������
			int denominator = 3;

			//��������� ���
			int expectedGCD = 3;

			//���������� ���
			int GCD = findGCD(numerator, denominator);

			Assert::AreEqual(expectedGCD, GCD);
		}

		TEST_METHOD(numeratorSmallerThenDenominator) //��������� ������ �����������
		{
			//���������
			int numerator = 3;

			//�����������
			int denominator = 15;

			//��������� ���
			int expectedGCD = 3;

			//���������� ���
			int GCD = findGCD(numerator, denominator);

			Assert::AreEqual(expectedGCD, GCD);
		}

		TEST_METHOD(numeratorIs1) //��������� ����� 1
		{
			//���������
			int numerator = 1;

			//�����������
			int denominator = 20;

			//��������� ���
			int expectedGCD = 1;

			//���������� ���
			int GCD = findGCD(numerator, denominator);

			Assert::AreEqual(expectedGCD, GCD);
		}

		TEST_METHOD(denominatorIs1) //����������� ����� 1
		{
			//���������
			int numerator = 20;

			//�����������
			int denominator = 1;

			//��������� ���
			int expectedGCD = 1;

			//���������� ���
			int GCD = findGCD(numerator, denominator);

			Assert::AreEqual(expectedGCD, GCD);
		}

		TEST_METHOD(numeratorAndDenominatorDontHaveCommonFactorGreaterThan1) //��������� � ����������� �� ����� ����� ��������� ������ 1
		{
			//���������
			int numerator = 3;

			//�����������
			int denominator = 5;

			//��������� ���
			int expectedGCD = 1;

			//���������� ���
			int GCD = findGCD(numerator, denominator);

			Assert::AreEqual(expectedGCD, GCD);
		}
	};
}
