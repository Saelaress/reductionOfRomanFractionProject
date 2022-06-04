#include "pch.h"
#include "CppUnitTest.h"
#include "../reductionOfRomanFraction/reductionOfRomanFraction.h"
#include <string.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testreductionOfRomanFraction
{
	TEST_CLASS(testreductionOfRomanFraction)
	{
	public:
		
		TEST_METHOD(ExtraSpacesAtTheBeginningOfLine) //Лишние пробелы в начале строки
		{
			//Строка с исходной дробью
			string fraction = "   XV/III";

			//Ожидаемый код ошибки
			int expectedEx = 1;

			//Строка с сокращенной дробью
			string reducedFraction;

			try 
			{
				reducedFraction = reductionOfRomanFraction(fraction);
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

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
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

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
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

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
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

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
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

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
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

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
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

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}
		
		TEST_METHOD(RepeatedVInString) //В строке есть повторяющийся символ V
		{
			//Строка с исходной дробью
			string fraction = "XVV/II";

			//Ожидаемый код ошибки
			int expectedEx = 2;

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}
		
		TEST_METHOD(RepeatedLInString) //В строке есть повторяющийся символ L
		{
			//Строка с исходной дробью
			string fraction = "LL/III";

			//Ожидаемый код ошибки
			int expectedEx = 2;

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}
		
		TEST_METHOD(RepeatedDInString) //В строке есть повторяющийся символ D
		{
			//Строка с исходной дробью
			string fraction = "DD/III";

			//Ожидаемый код ошибки
			int expectedEx = 2;

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}
		
		TEST_METHOD(IRepeatedMoreThanThreeTimesInString) //В строке символ I повторяется более трех раз
		{
			//Строка с исходной дробью
			string fraction = "XV/IIII";

			//Ожидаемый код ошибки
			int expectedEx = 3;

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}
			
		TEST_METHOD(XRepeatedMoreThanThreeTimesInString) //В строке символ X повторяется более трех раз
		{
			//Строка с исходной дробью
			string fraction = "XXXX/III";

			//Ожидаемый код ошибки
			int expectedEx = 3;

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}
			
		TEST_METHOD(CRepeatedMoreThanThreeTimesInString) //В строке символ C повторяется более трех раз
		{
			//Строка с исходной дробью
			string fraction = "CCCC/III";

			//Ожидаемый код ошибки
			int expectedEx = 3;

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}
		
		TEST_METHOD(CombinationOfILCharactersInString) //В строке есть сочетание символов IL
		{
			//Строка с исходной дробью
			string fraction = "IL/III";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfICCharactersInString) //В строке есть сочетание символов IС
		{
			//Строка с исходной дробью
			string fraction = "IC/III";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}
			
		TEST_METHOD(CombinationOfIDCharactersInString) //В строке есть сочетание символов ID
		{
			//Строка с исходной дробью
			string fraction = "ID/III";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}	

		TEST_METHOD(CombinationOfIMCharactersInString) //В строке есть сочетание символов IM
		{
			//Строка с исходной дробью
			string fraction = "IM/III";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfVXCharactersInString) //В строке есть сочетание символов VX
		{
			//Строка с исходной дробью
			string fraction = "VX/III";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfVLCharactersInString) //В строке есть сочетание символов VL
		{
			//Строка с исходной дробью
			string fraction = "VL/III";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfVCCharactersInString) //В строке есть сочетание символов VC
		{
			//Строка с исходной дробью
			string fraction = "VC/III";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfVDCharactersInString) //В строке есть сочетание символов VD
		{
			//Строка с исходной дробью
			string fraction = "VD/III";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfVMCharactersInString) //В строке есть сочетание символов VM
		{
			//Строка с исходной дробью
			string fraction = "VM/III";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfXDCharactersInString) //В строке есть сочетание символов XD
		{
			//Строка с исходной дробью
			string fraction = "XD/III";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfXMCharactersInString) //В строке есть сочетание символов XM
		{
			//Строка с исходной дробью
			string fraction = "XM/III";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfLCCharactersInString) //В строке есть сочетание символов LC
		{
			//Строка с исходной дробью
			string fraction = "LC/III";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfLDCharactersInString) //В строке есть сочетание символов LD
		{
			//Строка с исходной дробью
			string fraction = "LD/III";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfLMCharactersInString) //В строке есть сочетание символов LM
		{
			//Строка с исходной дробью
			string fraction = "LM/III";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfDMCharactersInString) //В строке есть сочетание символов DM
		{
			//Строка с исходной дробью
			string fraction = "DM/III";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(LargerSymbolBetweenTwoIdenticalSmallerSymbols) //Больший символ находится между двумя одинаковыми меньшими символами
		{
			//Строка с исходной дробью
			string fraction = "CDC/III";

			//Ожидаемый код ошибки
			int expectedEx = 5;

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(LargerSymbolAfterTwoSmallerSymbols) //Больший символ находится после двух меньших символов
		{
			//Строка с исходной дробью
			string fraction = "XXC/III";

			//Ожидаемый код ошибки
			int expectedEx = 6;

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(IrreducibleFraction) //Дробь несократимая
		{
			//Строка с исходной дробью
			string fraction = "III/V";

			//Ожидаемый код ошибки
			int expectedEx = 7;

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(FractionCanBeReducedToAnOrdinaryFraction) //Дробь сократима до обыкновенной дроби
		{
			//Строка с исходной дробью
			string fraction = "II/IV";

			//Строка с сокращенной дробью
			string reducedFraction;

			reducedFraction = reductionOfRomanFraction(fraction);

			//Строка с ожидаемой дробью
			string expectedFraction = "I/II";

			Assert::AreEqual(expectedFraction, reducedFraction);
		}

		TEST_METHOD(FractionCanBeCompletelyReduced) //Дробь сократима полностью
		{
			//Строка с исходной дробью
			string fraction = "XV/III";

			//Строка с сокращенной дробью
			string reducedFraction;

			reducedFraction = reductionOfRomanFraction(fraction);

			//Строка с ожидаемой дробью
			string expectedFraction = "V";

			Assert::AreEqual(expectedFraction, reducedFraction);
		}

		TEST_METHOD(DenominatorIsI) //Знаменатель равен I
		{
			//Строка с исходной дробью
			string fraction = "XV/I";

			//Строка с сокращенной дробью
			string reducedFraction;

			reducedFraction = reductionOfRomanFraction(fraction);

			//Строка с ожидаемой дробью
			string expectedFraction = "XV";

			Assert::AreEqual(expectedFraction, reducedFraction);
		}
			
		TEST_METHOD(RomanNumberGreaterThan3999) //Римское число больше 3999
		{
			//Строка с исходной дробью
			string fraction = "MMMMCX/X";

			//Ожидаемый код ошибки
			int expectedEx = 8;

			//Строка с сокращенной дробью
			string reducedFraction;

			try
			{
				reducedFraction = reductionOfRomanFraction(fraction);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

	};
}
