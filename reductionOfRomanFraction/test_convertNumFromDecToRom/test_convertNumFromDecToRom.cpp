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
		
		TEST_METHOD(numberHasSingleCharacterEquivalent) //����� ����� ��������� ���������� ����������
		{
			//�����
			int num = 100;

			//��������� ������� �����
			string expectedRomNum = "C";

			//���������� �����
			string romNum = convertNumFromDecToRom(num);

			Assert::AreEqual(expectedRomNum, romNum);
		}

		TEST_METHOD(numberHasNoSingleCharacterEquivalent) //����� �� ����� ���������� ����������� �����������
		{
			//�����
			int num = 154;

			//��������� ������� �����
			string expectedRomNum = "CLIV";

			//���������� �����
			string romNum = convertNumFromDecToRom(num);

			Assert::AreEqual(expectedRomNum, romNum);
		}

		TEST_METHOD(unitsDigitZero) //������ ������ ����� ����
		{
			//�����
			int num = 1230;

			//��������� ������� �����
			string expectedRomNum = "MCCXXX";

			//���������� �����
			string romNum = convertNumFromDecToRom(num);

			Assert::AreEqual(expectedRomNum, romNum);
		}

		TEST_METHOD(tensDigitIs0) //������ �������� ����� 0
		{
			//�����
			int num = 1204;

			//��������� ������� �����
			string expectedRomNum = "MCCIV";

			//���������� �����
			string romNum = convertNumFromDecToRom(num);

			Assert::AreEqual(expectedRomNum, romNum);
		}

		TEST_METHOD(hundredsDigitIs0) //������ ����� ����� 0
		{
			//�����
			int num = 1034;

			//��������� ������� �����
			string expectedRomNum = "MXXXIV";

			//���������� �����
			string romNum = convertNumFromDecToRom(num);

			Assert::AreEqual(expectedRomNum, romNum);
		}

		TEST_METHOD(unitsDigitOnly) //������ ������ ������
		{
			//�����
			int num = 4;

			//��������� ������� �����
			string expectedRomNum = "IV";

			//���������� �����
			string romNum = convertNumFromDecToRom(num);

			Assert::AreEqual(expectedRomNum, romNum);
		}

		TEST_METHOD(tensAndOnesPlaceOnly) //������ ������ �������� � ������
		{
			//�����
			int num = 14;

			//��������� ������� �����
			string expectedRomNum = "XIV";

			//���������� �����
			string romNum = convertNumFromDecToRom(num);

			Assert::AreEqual(expectedRomNum, romNum);
		}

		TEST_METHOD(OnlyRowOfHundredsTensAndUnits) //������ ������ �����, �������� � ������
		{
			//�����
			int num = 514;

			//��������� ������� �����
			string expectedRomNum = "DXIV";

			//���������� �����
			string romNum = convertNumFromDecToRom(num);

			Assert::AreEqual(expectedRomNum, romNum);
		}

		TEST_METHOD(rowOfThousandsHundredsTensAndUnits) //������ �����, �����, �������� � ������
		{
			//�����
			int num = 1514;

			//��������� ������� �����
			string expectedRomNum = "MDXIV";

			//���������� �����
			string romNum = convertNumFromDecToRom(num);

			Assert::AreEqual(expectedRomNum, romNum);
		}
	};
}
