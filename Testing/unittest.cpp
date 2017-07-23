
#include "stdafx.h"
#include "CppUnitTest.h"
#include "../NumericBox/NumericBox.h"
#include "../TextBox/TextBox.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{		
	TEST_CLASS(UnitTest1)
	{
		
	public:
		NumericBox *box = new NumericBox(30, 10, 50);

		TEST_METHOD(setPositionCheck)
		{
			Assert::AreEqual(0, (int)box->getTop(), L"Assert");
			Assert::AreEqual(0, (int)box->getLeft(), L"Assert");
			Assert::AreEqual(1, (int)box->getBodyTop(), L"Assert");
			Assert::AreEqual(1, (int)box->getBodyLeft(), L"Assert");
			box->setLocation({ 2,2 });
			Assert::AreEqual(2, (int)box->getTop(), L"Assert");
			Assert::AreEqual(2, (int)box->getLeft(), L"Assert");
			Assert::AreEqual(3, (int)box->getBodyTop(), L"Assert");
			Assert::AreEqual(3, (int)box->getBodyLeft(), L"Assert");
		}

		TEST_METHOD(setHeightCheck)
		{
			Assert::AreEqual(5, box->getHeight(), L"Assert");
			box->setHeight(6);
			Assert::AreEqual(6, box->getHeight(), L"Assert");
		}
		
		TEST_METHOD(setWidthCheck)
		{
			Assert::AreEqual(32, box->getWidth(), L"Assert");
			box->setWidth(20);
			Assert::AreEqual(20, box->getWidth(), L"Assert");
		}

		TEST_METHOD(setValueCheck)
		{
			Assert::AreEqual(10, box->getValue(), L"message");
			box->setValue(13);
			Assert::AreEqual(13, box->getValue(), L"message");
		}

		
		
	};
}