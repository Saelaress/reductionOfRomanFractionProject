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
		
		TEST_METHOD(RepeatedVInString) //� ������ ���� ������������� ������ V
		{
			//������� �����
			string romNum = "MVVI";

			//��������� ��� ������
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

		TEST_METHOD(RepeatedLInString) //� ������ ���� ������������� ������ L
		{
			//������� �����
			string romNum = "MLLI";

			//��������� ��� ������
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

		TEST_METHOD(RepeatedDInString) //� ������ ���� ������������� ������ D
		{
			//������� �����
			string romNum = "MDDI";

			//��������� ��� ������
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

		TEST_METHOD(IRepeatedMoreThanThreeTimesInString) //� ������ ������ I ����������� ����� ���� ���
		{
			//������� �����
			string romNum = "MIIII";

			//��������� ��� ������
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

		TEST_METHOD(XRepeatedMoreThanThreeTimesInString) //� ������ ������ X ����������� ����� ���� ���
		{
			//������� �����
			string romNum = "MXXXXI";

			//��������� ��� ������
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

		TEST_METHOD(CRepeatedMoreThanThreeTimesInString) //� ������ ������ C ����������� ����� ���� ���
		{
			//������� �����
			string romNum = "MCCCCI";

			//��������� ��� ������
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

		TEST_METHOD(CombinationOfILCharactersInString) //� ������ ���� ��������� �������� IL
		{
			//������� �����
			string romNum = "MILI";

			//��������� ��� ������
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

		TEST_METHOD(CombinationOfICCharactersInString) //� ������ ���� ��������� �������� I�
		{
			//������� �����
			string romNum = "MICI";

			//��������� ��� ������
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

		TEST_METHOD(CombinationOfIDCharactersInString) //� ������ ���� ��������� �������� ID
		{
			//������� �����
			string romNum = "MIDI";

			//��������� ��� ������
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

		TEST_METHOD(CombinationOfIMCharactersInString) //� ������ ���� ��������� �������� IM
		{
			//������� �����
			string romNum = "MIMI";

			//��������� ��� ������
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

		TEST_METHOD(CombinationOfVXCharactersInString) //� ������ ���� ��������� �������� VX
		{
			//������� �����
			string romNum = "MVXI";

			//��������� ��� ������
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

		TEST_METHOD(CombinationOfVLCharactersInString) //� ������ ���� ��������� �������� VL
		{
			//������� �����
			string romNum = "MVLI";

			//��������� ��� ������
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

		TEST_METHOD(CombinationOfVCCharactersInString) //� ������ ���� ��������� �������� VC
		{
			//������� �����
			string romNum = "MVCI";

			//��������� ��� ������
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

		TEST_METHOD(CombinationOfVDCharactersInString) //� ������ ���� ��������� �������� VD
		{
			//������� �����
			string romNum = "MVDI";

			//��������� ��� ������
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

		TEST_METHOD(CombinationOfVMCharactersInString) //� ������ ���� ��������� �������� VM
		{
			//������� �����
			string romNum = "MVMI";

			//��������� ��� ������
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

		TEST_METHOD(CombinationOfXDCharactersInString) //� ������ ���� ��������� �������� XD
		{
			//������� �����
			string romNum = "MXDI";

			//��������� ��� ������
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

		TEST_METHOD(CombinationOfXMCharactersInString) //� ������ ���� ��������� �������� XM
		{
			//������� �����
			string romNum = "MXMI";

			//��������� ��� ������
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

		TEST_METHOD(CombinationOfLCCharactersInString) //� ������ ���� ��������� �������� LC
		{
			//������� �����
			string romNum = "MLCI";

			//��������� ��� ������
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

		TEST_METHOD(CombinationOfLDCharactersInString) //� ������ ���� ��������� �������� LD
		{
			//������� �����
			string romNum = "MLDI";

			//��������� ��� ������
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

		TEST_METHOD(CombinationOfLMCharactersInString) //� ������ ���� ��������� �������� LM
		{
			//������� �����
			string romNum = "MLMI";

			//��������� ��� ������
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

		TEST_METHOD(CombinationOfDMCharactersInString) //� ������ ���� ��������� �������� DM
		{
			//������� �����
			string romNum = "MDMI";

			//��������� ��� ������
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

		TEST_METHOD(LargerSymbolBetweenTwoIdenticalSmallerSymbols) //������� ������ ��������� ����� ����� ����������� �������� ���������
		{ 
			//������� �����
			string romNum = "CDCI";

			//��������� ��� ������
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

		TEST_METHOD(LargerSymbolAfterTwoSmallerSymbols) //������� ������ ��������� ����� ���� ������� ��������
		{
			//������� �����
			string romNum = "XXCI";

			//��������� ��� ������
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
