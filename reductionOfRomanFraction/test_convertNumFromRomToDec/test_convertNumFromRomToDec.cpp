#include "pch.h"
#include "CppUnitTest.h"
#include "../reductionOfRomanFraction/reductionOfRomanFraction.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testconvertNumFromRomToDec
{
	TEST_CLASS(testconvertNumFromRomToDec)
	{
	public:
		
		TEST_METHOD(OneSymbol) //���� ������
		{
			//������� �����
			string romNum = "I";

			//��������� �����
			int expectedNum = 1;

			//���������� �����
			int num = convertNumFromRomToDec(romNum);

			Assert::AreEqual(expectedNum, num);
		}

		TEST_METHOD(TwoSymbols) //��� �������
		{
			//������� �����
			string romNum = "II";

			//��������� �����
			int expectedNum = 2;

			//���������� �����
			int num = convertNumFromRomToDec(romNum);

			Assert::AreEqual(expectedNum, num);
		}

		TEST_METHOD(ManySymbols) //����� ��������
		{
			//������� �����
			string romNum = "MCX";

			//��������� �����
			int expectedNum = 1110;

			//���������� �����
			int num = convertNumFromRomToDec(romNum);

			Assert::AreEqual(expectedNum, num);
		}

		TEST_METHOD(symbolsIdentical) //������� ����������
		{
			//������� �����
			string romNum = "XXX";

			//��������� �����
			int expectedNum = 30;

			//���������� �����
			int num = convertNumFromRomToDec(romNum);

			Assert::AreEqual(expectedNum, num);
		}

		TEST_METHOD(symbolsDifferent) //������� ������
		{
			//������� �����
			string romNum = "CDXI";

			//��������� �����
			int expectedNum = 411;

			//���������� �����
			int num = convertNumFromRomToDec(romNum);

			Assert::AreEqual(expectedNum, num);
		}

		TEST_METHOD(lesserSymbolsAtTheBeginning) //������� ������� �������
		{
			//������� �����
			string romNum = "IX";

			//��������� �����
			int expectedNum = 9;

			//���������� �����
			int num = convertNumFromRomToDec(romNum);

			Assert::AreEqual(expectedNum, num);
		}

		TEST_METHOD(lesserSymbolsBetweenGreater) //������� ������� ����� ��������
		{
			//������� �����
			string romNum = "CIX";

			//��������� �����
			int expectedNum = 109;

			//���������� �����
			int num = convertNumFromRomToDec(romNum);

			Assert::AreEqual(expectedNum, num);
		}

		TEST_METHOD(greaterSymbolsBetweenLesser) //������� ������� ����� ��������
		{
			//������� �����
			string romNum = "CDI";

			//��������� �����
			int expectedNum = 401;

			//���������� �����
			int num = convertNumFromRomToDec(romNum);

			Assert::AreEqual(expectedNum, num);
		}

		TEST_METHOD(greaterAndLesserSymbolsAlternate) //������� � ������� ����� ����������
		{
			//������� �����
			string romNum = "MXCI";

			//��������� �����
			int expectedNum = 1091;

			//���������� �����
			int num = convertNumFromRomToDec(romNum);

			Assert::AreEqual(expectedNum, num);
		}

		TEST_METHOD(lesserAndGreaterSymbolsAlternate) //������� � ������� ����� ����������
		{
			//������� �����
			string romNum = "CMXL";

			//��������� �����
			int expectedNum = 940;

			//���������� �����
			int num = convertNumFromRomToDec(romNum);

			Assert::AreEqual(expectedNum, num);
		}
	};
}
