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
		
		TEST_METHOD(ExtraSpacesAtTheBeginningOfLine) //������ ������� � ������ ������
		{
			//������ � �������� ������
			string fraction = "   XV/III";

			//��������� ��� ������
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

		TEST_METHOD(ExtraSpacesInTheMiddleOfLine) //������ ������� � �������� ������
		{
			//������ � �������� ������
			string fraction = "XV   /III";

			//��������� ��� ������
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

		TEST_METHOD(ExtraSpacesAtTheEndOfLine) //������ ������� � ����� ������
		{
			//������ � �������� ������
			string fraction = "XV/III          ";

			//��������� ��� ������
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

		TEST_METHOD(ExtraneousCharactersInString) //����������� ������� � ������
		{
			//������ � �������� ������
			string fraction = "XVada12/IIIaas";

			//��������� ��� ������
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

		TEST_METHOD(LineIsMissingSlash) //� ������ ����������� /
		{
			//������ � �������� ������
			string fraction = "XVIII";

			//��������� ��� ������
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

		TEST_METHOD(LotsOfSlashInLine) //� ������ ����� /
		{
			//������ � �������� ������
			string fraction = "XV///III";

			//��������� ��� ������
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

		TEST_METHOD(ManySeparatedSlashInLine) //� ������ ����� ����������� /
		{
			//������ � �������� ������
			string fraction = "XV/II/I";

			//��������� ��� ������
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

		TEST_METHOD(NoNumberAfterSlash) //��� ����� ����� /
		{
			//������ � �������� ������
			string fraction = "XV/";

			//��������� ��� ������
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
