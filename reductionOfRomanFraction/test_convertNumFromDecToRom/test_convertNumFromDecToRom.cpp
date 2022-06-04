#include "pch.h"
#include "CppUnitTest.h"
#include "../reductionOfRomanFraction/reductionOfRomanFraction.h"
#include <string.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testconvertNumFromDecToRom
{
	TEST_CLASS(testconvertNumFromDecToRom)
	{
	public:
		
		TEST_METHOD(numberHasSingleCharacterEquivalent) //Число имеет одиночный символьный эквивалент
		{
			//Число
			int num = 100;

			//Ожидаемое римское число
			string expectedRomNum = "C";

			//Полученное число
			string romNum = convertNumFromDecToRom(num);

			Assert::AreEqual(expectedRomNum, romNum);
		}

		TEST_METHOD(numberHasNoSingleCharacterEquivalent) //Число не имеет одиночного символьного эквивалента
		{
			//Число
			int num = 154;

			//Ожидаемое римское число
			string expectedRomNum = "CLIV";

			//Полученное число
			string romNum = convertNumFromDecToRom(num);

			Assert::AreEqual(expectedRomNum, romNum);
		}

		TEST_METHOD(unitsDigitZero) //Разряд единиц равен нулю
		{
			//Число
			int num = 1230;

			//Ожидаемое римское число
			string expectedRomNum = "MCCXXX";

			//Полученное число
			string romNum = convertNumFromDecToRom(num);

			Assert::AreEqual(expectedRomNum, romNum);
		}

		TEST_METHOD(tensDigitIs0) //Разряд десятков равен 0
		{
			//Число
			int num = 1204;

			//Ожидаемое римское число
			string expectedRomNum = "MCCIV";

			//Полученное число
			string romNum = convertNumFromDecToRom(num);

			Assert::AreEqual(expectedRomNum, romNum);
		}

		TEST_METHOD(hundredsDigitIs0) //Разряд сотен равен 0
		{
			//Число
			int num = 1034;

			//Ожидаемое римское число
			string expectedRomNum = "MXXXIV";

			//Полученное число
			string romNum = convertNumFromDecToRom(num);

			Assert::AreEqual(expectedRomNum, romNum);
		}

		TEST_METHOD(unitsDigitOnly) //Только разряд единиц
		{
			//Число
			int num = 4;

			//Ожидаемое римское число
			string expectedRomNum = "IV";

			//Полученное число
			string romNum = convertNumFromDecToRom(num);

			Assert::AreEqual(expectedRomNum, romNum);
		}

		TEST_METHOD(tensAndOnesPlaceOnly) //Только разряд десятков и единиц
		{
			//Число
			int num = 14;

			//Ожидаемое римское число
			string expectedRomNum = "XIV";

			//Полученное число
			string romNum = convertNumFromDecToRom(num);

			Assert::AreEqual(expectedRomNum, romNum);
		}

		TEST_METHOD(OnlyRowOfHundredsTensAndUnits) //Только рязряд сотен, десятков и единиц
		{
			//Число
			int num = 514;

			//Ожидаемое римское число
			string expectedRomNum = "DXIV";

			//Полученное число
			string romNum = convertNumFromDecToRom(num);

			Assert::AreEqual(expectedRomNum, romNum);
		}

		TEST_METHOD(rowOfThousandsHundredsTensAndUnits) //Разряд тысяч, сотен, десятков и единиц
		{
			//Число
			int num = 1514;

			//Ожидаемое римское число
			string expectedRomNum = "MDXIV";

			//Полученное число
			string romNum = convertNumFromDecToRom(num);

			Assert::AreEqual(expectedRomNum, romNum);
		}
	};
}
