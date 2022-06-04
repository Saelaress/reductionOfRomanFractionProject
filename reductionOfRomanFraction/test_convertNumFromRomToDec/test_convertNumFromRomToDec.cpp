#include "pch.h"
#include "CppUnitTest.h"
#include "../reductionOfRomanFraction/reductionOfRomanFraction.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testconvertNumFromRomToDec
{
	TEST_CLASS(testconvertNumFromRomToDec)
	{
	public:
		
		TEST_METHOD(OneSymbol) //Один символ
		{
			//Римское число
			string romNum = "I";

			//Ожидаемое число
			int expectedNum = 1;

			//Полученное число
			int num = convertNumFromRomToDec(romNum);

			Assert::AreEqual(expectedNum, num);
		}

		TEST_METHOD(TwoSymbols) //Два символа
		{
			//Римское число
			string romNum = "II";

			//Ожидаемое число
			int expectedNum = 2;

			//Полученное число
			int num = convertNumFromRomToDec(romNum);

			Assert::AreEqual(expectedNum, num);
		}

		TEST_METHOD(ManySymbols) //Много символов
		{
			//Римское число
			string romNum = "MCX";

			//Ожидаемое число
			int expectedNum = 1110;

			//Полученное число
			int num = convertNumFromRomToDec(romNum);

			Assert::AreEqual(expectedNum, num);
		}

		TEST_METHOD(symbolsIdentical) //Символы одинаковые
		{
			//Римское число
			string romNum = "XXX";

			//Ожидаемое число
			int expectedNum = 30;

			//Полученное число
			int num = convertNumFromRomToDec(romNum);

			Assert::AreEqual(expectedNum, num);
		}

		TEST_METHOD(symbolsDifferent) //Символы разные
		{
			//Римское число
			string romNum = "CDXI";

			//Ожидаемое число
			int expectedNum = 411;

			//Полученное число
			int num = convertNumFromRomToDec(romNum);

			Assert::AreEqual(expectedNum, num);
		}

		TEST_METHOD(lesserSymbolsAtTheBeginning) //Меньшие символы впереди
		{
			//Римское число
			string romNum = "IX";

			//Ожидаемое число
			int expectedNum = 9;

			//Полученное число
			int num = convertNumFromRomToDec(romNum);

			Assert::AreEqual(expectedNum, num);
		}

		TEST_METHOD(lesserSymbolsBetweenGreater) //Меньшие символы между большими
		{
			//Римское число
			string romNum = "CIX";

			//Ожидаемое число
			int expectedNum = 109;

			//Полученное число
			int num = convertNumFromRomToDec(romNum);

			Assert::AreEqual(expectedNum, num);
		}

		TEST_METHOD(greaterSymbolsBetweenLesser) //Большие символы между большими
		{
			//Римское число
			string romNum = "CDI";

			//Ожидаемое число
			int expectedNum = 401;

			//Полученное число
			int num = convertNumFromRomToDec(romNum);

			Assert::AreEqual(expectedNum, num);
		}

		TEST_METHOD(greaterAndLesserSymbolsAlternate) //Большие и меньшие цифры чередуются
		{
			//Римское число
			string romNum = "MXCI";

			//Ожидаемое число
			int expectedNum = 1091;

			//Полученное число
			int num = convertNumFromRomToDec(romNum);

			Assert::AreEqual(expectedNum, num);
		}

		TEST_METHOD(lesserAndGreaterSymbolsAlternate) //Меньшие и большие цифры чередуются
		{
			//Римское число
			string romNum = "CMXL";

			//Ожидаемое число
			int expectedNum = 940;

			//Полученное число
			int num = convertNumFromRomToDec(romNum);

			Assert::AreEqual(expectedNum, num);
		}
	};
}
