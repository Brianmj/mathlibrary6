#include "stdafx.h"
#include "CppUnitTest.h"
#include "impl.h"
#include <cassert>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace knu::math;



namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			mat2<int> m1;
			mat2<int> m2;
			bool b = (m1 == m2);
			Assert::AreEqual(m1, m2, L"They are not equal");
			//assert(m1 == m2);
		}

		TEST_METHOD(TestMethod2)
		{
			// TODO: Your test code here
			mat2<float> m1(1, 2, 3, 4);

			auto r1 = m1.get_row_0();
			v2f v(1, 3);

			Assert::AreEqual(r1, v, L"They are not equal");
		}

		TEST_METHOD(mat2_row_1_test)
		{
			// TODO: Your test code here
			mat2<float> m1(1, 2, 3, 4);

			auto r1 = m1.get_row_1();
			v2f v(2, 4);

			Assert::AreEqual(r1, v, L"They are not equal");
		}

		TEST_METHOD(mat2_col_0_test)
		{
			// TODO: Your test code here
			mat2<float> m1(1, 2, 3, 4);

			auto c1 = m1.get_column_0();
			//v2f v(2, 4);
			v2f v(1, 2);
			Assert::AreEqual(c1, v, L"Not equal: Should be 1 and 2");
		}

		TEST_METHOD(mat2_col_1_test)
		{
			// TODO: Your test code here
			mat2<float> m1(1, 2, 3, 4);

			auto c1 = m1.get_column_1();
			//v2f v(2, 4);
			//v2f v(1, 2);
			v2f v{ 3, 4 };
			Assert::AreEqual(c1, v, L"Not equal: Should be 3 and 4");
		}

	};
}