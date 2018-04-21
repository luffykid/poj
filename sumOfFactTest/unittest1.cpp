#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sumoffactorial/stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace sumOfFactTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			int n = 51200;
			int exceptVal = 9403103;
			int realVal = sumOfFact(n, [](int n) { return n % 1000000; });
			Assert::AreEqual(realVal, exceptVal);
		}

	};
}