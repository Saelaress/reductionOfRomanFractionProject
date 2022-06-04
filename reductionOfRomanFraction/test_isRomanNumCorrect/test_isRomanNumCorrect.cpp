#include "pch.h"
#include "CppUnitTest.h"
#include "../reductionOfRomanFraction/reductionOfRomanFraction.h"
#include <string.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testisRomNumCorrect
{
	TEST_CLASS(testisRomanNumCorrect)
	{
	public:
		
		TEST_METHOD(RepeatedVInString) //В строке есть повторяющийся символ V
		{
			//Римское число
			string romNum = "MVVI";

			//Ожидаемый код ошибки
			int expectedEx = 2;

			try
			{
				isRomNumCorrect(romNum);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(RepeatedLInString) //В строке есть повторяющийся символ L
		{
			//Римское число
			string romNum = "MLLI";

			//Ожидаемый код ошибки
			int expectedEx = 2;

			try
			{
				isRomNumCorrect(romNum);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(RepeatedDInString) //В строке есть повторяющийся символ D
		{
			//Римское число
			string romNum = "MDDI";

			//Ожидаемый код ошибки
			int expectedEx = 2;

			try
			{
				isRomNumCorrect(romNum);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(IRepeatedMoreThanThreeTimesInString) //В строке символ I повторяется более трех раз
		{
			//Римское число
			string romNum = "MIIII";

			//Ожидаемый код ошибки
			int expectedEx = 3;

			try
			{
				isRomNumCorrect(romNum);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(XRepeatedMoreThanThreeTimesInString) //В строке символ X повторяется более трех раз
		{
			//Римское число
			string romNum = "MXXXXI";

			//Ожидаемый код ошибки
			int expectedEx = 3;

			try
			{
				isRomNumCorrect(romNum);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CRepeatedMoreThanThreeTimesInString) //В строке символ C повторяется более трех раз
		{
			//Римское число
			string romNum = "MCCCCI";

			//Ожидаемый код ошибки
			int expectedEx = 3;

			try
			{
				isRomNumCorrect(romNum);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfILCharactersInString) //В строке есть сочетание символов IL
		{
			//Римское число
			string romNum = "MILI";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			try
			{
				isRomNumCorrect(romNum);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfICCharactersInString) //В строке есть сочетание символов IС
		{
			//Римское число
			string romNum = "MICI";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			try
			{
				isRomNumCorrect(romNum);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfIDCharactersInString) //В строке есть сочетание символов ID
		{
			//Римское число
			string romNum = "MIDI";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			try
			{
				isRomNumCorrect(romNum);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfIMCharactersInString) //В строке есть сочетание символов IM
		{
			//Римское число
			string romNum = "MIMI";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			try
			{
				isRomNumCorrect(romNum);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfVXCharactersInString) //В строке есть сочетание символов VX
		{
			//Римское число
			string romNum = "MVXI";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			try
			{
				isRomNumCorrect(romNum);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfVLCharactersInString) //В строке есть сочетание символов VL
		{
			//Римское число
			string romNum = "MVLI";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			try
			{
				isRomNumCorrect(romNum);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfVCCharactersInString) //В строке есть сочетание символов VC
		{
			//Римское число
			string romNum = "MVCI";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			try
			{
				isRomNumCorrect(romNum);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfVDCharactersInString) //В строке есть сочетание символов VD
		{
			//Римское число
			string romNum = "MVDI";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			try
			{
				isRomNumCorrect(romNum);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfVMCharactersInString) //В строке есть сочетание символов VM
		{
			//Римское число
			string romNum = "MVMI";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			try
			{
				isRomNumCorrect(romNum);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfXDCharactersInString) //В строке есть сочетание символов XD
		{
			//Римское число
			string romNum = "MXDI";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			try
			{
				isRomNumCorrect(romNum);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfXMCharactersInString) //В строке есть сочетание символов XM
		{
			//Римское число
			string romNum = "MXMI";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			try
			{
				isRomNumCorrect(romNum);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfLCCharactersInString) //В строке есть сочетание символов LC
		{
			//Римское число
			string romNum = "MLCI";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			try
			{
				isRomNumCorrect(romNum);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfLDCharactersInString) //В строке есть сочетание символов LD
		{
			//Римское число
			string romNum = "MLDI";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			try
			{
				isRomNumCorrect(romNum);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfLMCharactersInString) //В строке есть сочетание символов LM
		{
			//Римское число
			string romNum = "MLMI";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			try
			{
				isRomNumCorrect(romNum);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(CombinationOfDMCharactersInString) //В строке есть сочетание символов DM
		{
			//Римское число
			string romNum = "MDMI";

			//Ожидаемый код ошибки
			int expectedEx = 4;

			try
			{
				isRomNumCorrect(romNum);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(LargerSymbolBetweenTwoIdenticalSmallerSymbols) //Больший символ находится между двумя одинаковыми меньшими символами
		{ 
			//Римское число
			string romNum = "CDCI";

			//Ожидаемый код ошибки
			int expectedEx = 5;

			try
			{
				isRomNumCorrect(romNum);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

		TEST_METHOD(LargerSymbolAfterTwoSmallerSymbols) //Больший символ находится после двух меньших символов
		{
			//Римское число
			string romNum = "XXCI";

			//Ожидаемый код ошибки
			int expectedEx = 6;

			try
			{
				isRomNumCorrect(romNum);
				Assert::Fail();
			}
			catch (int ex)
			{
				Assert::AreEqual(expectedEx, ex);
			}
		}

	};
}
