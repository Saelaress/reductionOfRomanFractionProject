#include "pch.h"
#include "CppUnitTest.h"
#include "../reductionOfRomanFraction/reductionOfRomanFraction.h"
#include <string.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testisContentOfStringCorrect
{
	TEST_CLASS(testisContentOfStringCorrect)
	{
	public:
		
		TEST_METHOD(ExtraSpacesAtTheBeginningOfLine) //Лишние пробелы в начале строки
		{
			//Строка с исходной дробью
			string fraction = "   XV/III";

			//Ожидаемый код ошибки
			int expectedEx = 1;

			try
			{
				isContentOfStringCorrect(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(ExtraSpacesInTheMiddleOfLine) //Лишние пробелы в середине строки
		{
			//Строка с исходной дробью
			string fraction = "XV   /III";

			//Ожидаемый код ошибки
			int expectedEx = 1;

			try
			{
				isContentOfStringCorrect(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(ExtraSpacesAtTheEndOfLine) //Лишние пробелы в конце строки
		{
			//Строка с исходной дробью
			string fraction = "XV/III          ";

			//Ожидаемый код ошибки
			int expectedEx = 1;

			try
			{
				isContentOfStringCorrect(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(ExtraneousCharactersInString) //Посторонние символы в строке
		{
			//Строка с исходной дробью
			string fraction = "XVada12/IIIaas";

			//Ожидаемый код ошибки
			int expectedEx = 1;

			try
			{
				isContentOfStringCorrect(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(LineIsMissingSlash) //В строке отсутствует /
		{
			//Строка с исходной дробью
			string fraction = "XVIII";

			//Ожидаемый код ошибки
			int expectedEx = 1;

			try
			{
				isContentOfStringCorrect(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(LotsOfSlashInLine) //В строке много /
		{
			//Строка с исходной дробью
			string fraction = "XV///III";

			//Ожидаемый код ошибки
			int expectedEx = 1;

			try
			{
				isContentOfStringCorrect(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(ManySeparatedSlashInLine) //В строке много разделенных /
		{
			//Строка с исходной дробью
			string fraction = "XV/II/I";

			//Ожидаемый код ошибки
			int expectedEx = 1;

			try
			{
				isContentOfStringCorrect(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(NoNumberAfterSlash) //Нет числа после /
		{
			//Строка с исходной дробью
			string fraction = "XV/";

			//Ожидаемый код ошибки
			int expectedEx = 1;

			try
			{
				isContentOfStringCorrect(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

	};
}
