#include "pch.h"
#include "CppUnitTest.h"
#include "../reductionOfRomanFraction/reductionOfRomanFraction.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testfindGCD
{
	TEST_CLASS(testfindGCD)
	{
	public:
		
		TEST_METHOD(numeratorAndDenominatorAreSame) //Числитель и знаменатель совпадают
		{
			//Числитель
			int numerator = 20;

			//Знаменатель
			int denominator = 20;

			//Ожидаемый НОД
			int expectedGCD = 20;

			//Полученный НОД
			int GCD = findGCD(numerator, denominator);

			Assert::AreEqual(expectedGCD, GCD);
		}

		TEST_METHOD(numeratorBiggerThenDenominator) //Числитель больше знаменателя
		{
			//Числитель
			int numerator = 15;

			//Знаменатель
			int denominator = 3;

			//Ожидаемый НОД
			int expectedGCD = 3;

			//Полученный НОД
			int GCD = findGCD(numerator, denominator);

			Assert::AreEqual(expectedGCD, GCD);
		}

		TEST_METHOD(numeratorSmallerThenDenominator) //Числитель меньше знаменателя
		{
			//Числитель
			int numerator = 3;

			//Знаменатель
			int denominator = 15;

			//Ожидаемый НОД
			int expectedGCD = 3;

			//Полученный НОД
			int GCD = findGCD(numerator, denominator);

			Assert::AreEqual(expectedGCD, GCD);
		}

		TEST_METHOD(numeratorIs1) //Числитель равен 1
		{
			//Числитель
			int numerator = 1;

			//Знаменатель
			int denominator = 20;

			//Ожидаемый НОД
			int expectedGCD = 1;

			//Полученный НОД
			int GCD = findGCD(numerator, denominator);

			Assert::AreEqual(expectedGCD, GCD);
		}

		TEST_METHOD(denominatorIs1) //Знаменатель равен 1
		{
			//Числитель
			int numerator = 20;

			//Знаменатель
			int denominator = 1;

			//Ожидаемый НОД
			int expectedGCD = 1;

			//Полученный НОД
			int GCD = findGCD(numerator, denominator);

			Assert::AreEqual(expectedGCD, GCD);
		}

		TEST_METHOD(numeratorAndDenominatorDontHaveCommonFactorGreaterThan1) //Числитель и знаменатель не имеют общих делителей больше 1
		{
			//Числитель
			int numerator = 3;

			//Знаменатель
			int denominator = 5;

			//Ожидаемый НОД
			int expectedGCD = 1;

			//Полученный НОД
			int GCD = findGCD(numerator, denominator);

			Assert::AreEqual(expectedGCD, GCD);
		}
	};
}
