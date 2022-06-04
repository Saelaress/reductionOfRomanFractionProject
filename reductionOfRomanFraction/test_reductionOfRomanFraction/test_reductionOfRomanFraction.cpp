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
		
		TEST_METHOD(ExtraSpacesAtTheBeginningOfLine) //������ ������� � ������ ������
		{
			//������ � �������� ������
			string fraction = "   XV/III";

			//��������� ��� ������
			int expectedEx = 1;

			//������ � ����������� ������
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

		TEST_METHOD(ExtraSpacesInTheMiddleOfLine) //������ ������� � �������� ������
		{
			//������ � �������� ������
			string fraction = "XV   /III";

			//��������� ��� ������
			int expectedEx = 1;

			//������ � ����������� ������
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

		TEST_METHOD(ExtraSpacesAtTheEndOfLine) //������ ������� � ����� ������
		{
			//������ � �������� ������
			string fraction = "XV/III          ";

			//��������� ��� ������
			int expectedEx = 1;

			//������ � ����������� ������
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
			
		TEST_METHOD(ExtraneousCharactersInString) //����������� ������� � ������
		{
			//������ � �������� ������
			string fraction = "XVada12/IIIaas";

			//��������� ��� ������
			int expectedEx = 1;

			//������ � ����������� ������
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
		
		TEST_METHOD(LineIsMissingSlash) //� ������ ����������� /
		{
			//������ � �������� ������
			string fraction = "XVIII";

			//��������� ��� ������
			int expectedEx = 1;

			//������ � ����������� ������
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
			
		TEST_METHOD(LotsOfSlashInLine) //� ������ ����� /
		{
			//������ � �������� ������
			string fraction = "XV///III";

			//��������� ��� ������
			int expectedEx = 1;

			//������ � ����������� ������
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

		TEST_METHOD(ManySeparatedSlashInLine) //� ������ ����� ����������� /
		{
			//������ � �������� ������
			string fraction = "XV/II/I";

			//��������� ��� ������
			int expectedEx = 1;

			//������ � ����������� ������
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
		
		TEST_METHOD(NoNumberAfterSlash) //��� ����� ����� /
		{
			//������ � �������� ������
			string fraction = "XV/";

			//��������� ��� ������
			int expectedEx = 1;

			//������ � ����������� ������
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
		
		TEST_METHOD(RepeatedVInString) //� ������ ���� ������������� ������ V
		{
			//������ � �������� ������
			string fraction = "XVV/II";

			//��������� ��� ������
			int expectedEx = 2;

			//������ � ����������� ������
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
		
		TEST_METHOD(RepeatedLInString) //� ������ ���� ������������� ������ L
		{
			//������ � �������� ������
			string fraction = "LL/III";

			//��������� ��� ������
			int expectedEx = 2;

			//������ � ����������� ������
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
		
		TEST_METHOD(RepeatedDInString) //� ������ ���� ������������� ������ D
		{
			//������ � �������� ������
			string fraction = "DD/III";

			//��������� ��� ������
			int expectedEx = 2;

			//������ � ����������� ������
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
		
		TEST_METHOD(IRepeatedMoreThanThreeTimesInString) //� ������ ������ I ����������� ����� ���� ���
		{
			//������ � �������� ������
			string fraction = "XV/IIII";

			//��������� ��� ������
			int expectedEx = 3;

			//������ � ����������� ������
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
			
		TEST_METHOD(XRepeatedMoreThanThreeTimesInString) //� ������ ������ X ����������� ����� ���� ���
		{
			//������ � �������� ������
			string fraction = "XXXX/III";

			//��������� ��� ������
			int expectedEx = 3;

			//������ � ����������� ������
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
			
		TEST_METHOD(CRepeatedMoreThanThreeTimesInString) //� ������ ������ C ����������� ����� ���� ���
		{
			//������ � �������� ������
			string fraction = "CCCC/III";

			//��������� ��� ������
			int expectedEx = 3;

			//������ � ����������� ������
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
		
		TEST_METHOD(CombinationOfILCharactersInString) //� ������ ���� ��������� �������� IL
		{
			//������ � �������� ������
			string fraction = "IL/III";

			//��������� ��� ������
			int expectedEx = 4;

			//������ � ����������� ������
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

		TEST_METHOD(CombinationOfICCharactersInString) //� ������ ���� ��������� �������� I�
		{
			//������ � �������� ������
			string fraction = "IC/III";

			//��������� ��� ������
			int expectedEx = 4;

			//������ � ����������� ������
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
			
		TEST_METHOD(CombinationOfIDCharactersInString) //� ������ ���� ��������� �������� ID
		{
			//������ � �������� ������
			string fraction = "ID/III";

			//��������� ��� ������
			int expectedEx = 4;

			//������ � ����������� ������
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

		TEST_METHOD(CombinationOfIMCharactersInString) //� ������ ���� ��������� �������� IM
		{
			//������ � �������� ������
			string fraction = "IM/III";

			//��������� ��� ������
			int expectedEx = 4;

			//������ � ����������� ������
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

		TEST_METHOD(CombinationOfVXCharactersInString) //� ������ ���� ��������� �������� VX
		{
			//������ � �������� ������
			string fraction = "VX/III";

			//��������� ��� ������
			int expectedEx = 4;

			//������ � ����������� ������
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

		TEST_METHOD(CombinationOfVLCharactersInString) //� ������ ���� ��������� �������� VL
		{
			//������ � �������� ������
			string fraction = "VL/III";

			//��������� ��� ������
			int expectedEx = 4;

			//������ � ����������� ������
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

		TEST_METHOD(CombinationOfVCCharactersInString) //� ������ ���� ��������� �������� VC
		{
			//������ � �������� ������
			string fraction = "VC/III";

			//��������� ��� ������
			int expectedEx = 4;

			//������ � ����������� ������
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

		TEST_METHOD(CombinationOfVDCharactersInString) //� ������ ���� ��������� �������� VD
		{
			//������ � �������� ������
			string fraction = "VD/III";

			//��������� ��� ������
			int expectedEx = 4;

			//������ � ����������� ������
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

		TEST_METHOD(CombinationOfVMCharactersInString) //� ������ ���� ��������� �������� VM
		{
			//������ � �������� ������
			string fraction = "VM/III";

			//��������� ��� ������
			int expectedEx = 4;

			//������ � ����������� ������
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

		TEST_METHOD(CombinationOfXDCharactersInString) //� ������ ���� ��������� �������� XD
		{
			//������ � �������� ������
			string fraction = "XD/III";

			//��������� ��� ������
			int expectedEx = 4;

			//������ � ����������� ������
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

		TEST_METHOD(CombinationOfXMCharactersInString) //� ������ ���� ��������� �������� XM
		{
			//������ � �������� ������
			string fraction = "XM/III";

			//��������� ��� ������
			int expectedEx = 4;

			//������ � ����������� ������
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

		TEST_METHOD(CombinationOfLCCharactersInString) //� ������ ���� ��������� �������� LC
		{
			//������ � �������� ������
			string fraction = "LC/III";

			//��������� ��� ������
			int expectedEx = 4;

			//������ � ����������� ������
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

		TEST_METHOD(CombinationOfLDCharactersInString) //� ������ ���� ��������� �������� LD
		{
			//������ � �������� ������
			string fraction = "LD/III";

			//��������� ��� ������
			int expectedEx = 4;

			//������ � ����������� ������
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

		TEST_METHOD(CombinationOfLMCharactersInString) //� ������ ���� ��������� �������� LM
		{
			//������ � �������� ������
			string fraction = "LM/III";

			//��������� ��� ������
			int expectedEx = 4;

			//������ � ����������� ������
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

		TEST_METHOD(CombinationOfDMCharactersInString) //� ������ ���� ��������� �������� DM
		{
			//������ � �������� ������
			string fraction = "DM/III";

			//��������� ��� ������
			int expectedEx = 4;

			//������ � ����������� ������
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

		TEST_METHOD(LargerSymbolBetweenTwoIdenticalSmallerSymbols) //������� ������ ��������� ����� ����� ����������� �������� ���������
		{
			//������ � �������� ������
			string fraction = "CDC/III";

			//��������� ��� ������
			int expectedEx = 5;

			//������ � ����������� ������
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

		TEST_METHOD(LargerSymbolAfterTwoSmallerSymbols) //������� ������ ��������� ����� ���� ������� ��������
		{
			//������ � �������� ������
			string fraction = "XXC/III";

			//��������� ��� ������
			int expectedEx = 6;

			//������ � ����������� ������
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

		TEST_METHOD(IrreducibleFraction) //����� ������������
		{
			//������ � �������� ������
			string fraction = "III/V";

			//��������� ��� ������
			int expectedEx = 7;

			//������ � ����������� ������
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

		TEST_METHOD(FractionCanBeReducedToAnOrdinaryFraction) //����� ��������� �� ������������ �����
		{
			//������ � �������� ������
			string fraction = "II/IV";

			//������ � ����������� ������
			string reducedFraction;

			reducedFraction = reductionOfRomanFraction(fraction);

			//������ � ��������� ������
			string expectedFraction = "I/II";

			Assert::AreEqual(expectedFraction, reducedFraction);
		}

		TEST_METHOD(FractionCanBeCompletelyReduced) //����� ��������� ���������
		{
			//������ � �������� ������
			string fraction = "XV/III";

			//������ � ����������� ������
			string reducedFraction;

			reducedFraction = reductionOfRomanFraction(fraction);

			//������ � ��������� ������
			string expectedFraction = "V";

			Assert::AreEqual(expectedFraction, reducedFraction);
		}

		TEST_METHOD(DenominatorIsI) //����������� ����� I
		{
			//������ � �������� ������
			string fraction = "XV/I";

			//������ � ����������� ������
			string reducedFraction;

			reducedFraction = reductionOfRomanFraction(fraction);

			//������ � ��������� ������
			string expectedFraction = "XV";

			Assert::AreEqual(expectedFraction, reducedFraction);
		}
			
		TEST_METHOD(RomanNumberGreaterThan3999) //������� ����� ������ 3999
		{
			//������ � �������� ������
			string fraction = "MMMMCX/X";

			//��������� ��� ������
			int expectedEx = 8;

			//������ � ����������� ������
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
