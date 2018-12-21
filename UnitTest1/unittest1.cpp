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
			vector2f v(1, 3);

			Assert::AreEqual(r1, v, L"They are not equal");
		}

		TEST_METHOD(mat2_row_1_test)
		{
			// TODO: Your test code here
			mat2<float> m1(1, 2, 3, 4);

			auto r1 = m1.get_row_1();
			vector2f v(2, 4);

			Assert::AreEqual(r1, v, L"They are not equal");
		}

		TEST_METHOD(mat2_col_0_test)
		{
			// TODO: Your test code here
			mat2<float> m1(1, 2, 3, 4);

			auto c1 = m1.get_column_0();
			//v2f v(2, 4);
			vector2f v(1, 2);
			Assert::AreEqual(c1, v, L"Not equal: Should be 1 and 2");
		}

		TEST_METHOD(mat2_col_1_test)
		{
			// TODO: Your test code here
			mat2<float> m1(1, 2, 3, 4);

			auto c1 = m1.get_column_1();
			//v2f v(2, 4);
			//v2f v(1, 2);
			vector2f v{ 3, 4 };
			Assert::AreEqual(c1, v, L"Not equal: Should be 3 and 4");
		}

		TEST_METHOD(IDENTITY_TEST)
		{
			mat2<float> m1;

			m1.set_identity();

			mat2<float> m2(1, 0, 1, 0);
			mat2<float> m3;		// default constructed to identity

			Assert::AreEqual(m1, m3, L"Not equal to identity");
		}

		TEST_METHOD(ZeroTest)
		{
			// TODO: Your test code here
			matrix2f m1;
			matrix2f m2;

			m1.zero();
			m2 = matrix2f{ 0, 0, 0, 0 };
			Assert::AreEqual(m1, m2, L"They should both have all zero elements");
		}

		TEST_METHOD(PlusOperatorTest)
		{
			// TODO: Your test code here
			matrix2i m1(1, 2, 3, 4);
			matrix2i m2(5, 6, 7, 8);

			matrix2i res = m1 + m2;

			// should be equal to m{6, 8, 10, 12}
			matrix2i comp1{ 6, 8, 10, 13 };
			matrix2i comp2{ 6, 8, 10, 12 };
			Assert::AreEqual(res, comp2);
		}

		TEST_METHOD(PlusEqualOperatorTest)
		{
			// TODO: Your test code here
			matrix2i m1(1, 2, 3, 4);
			matrix2i m2(5, 6, 7, 8);

			m1 += m2;

			// should be equal to m{6, 8, 10, 12}
			matrix2i comp1{ 6, 8, 10, 13 };
			matrix2i comp2{ 6, 8, 10, 12 };
			Assert::AreEqual(m1, comp2);
		}

		TEST_METHOD(MinusOperatorTest)
		{
			// TODO: Your test code here
			matrix2i m1(1, 2, 3, 4);
			matrix2i m2(5, 6, 7, 8);

			matrix2i res = m1 - m2;

			// should be equal to m{-4, 4, -4, -4}
			matrix2i comp1{ 6, 8, 10, 13 };
			matrix2i comp2{ -4, -4, -4, -4 };
			//Assert::AreEqual(res, comp1);
			Assert::AreEqual(res, comp2);
		}

		TEST_METHOD(MinusEqualOperatorTest)
		{
			// TODO: Your test code here
			matrix2i m1(1, 2, 3, 4);
			matrix2i m2(5, 6, 7, 8);

			m1 -= m2;

			// should be equal to m{-4, 4, -4, -4}
			matrix2i comp1{ 6, 8, 10, 13 };
			matrix2i comp2{ -4, -4, -4, -4 };
			//Assert::AreEqual(m1, comp1);
			Assert::AreEqual(m1, comp2);
		}

		TEST_METHOD(Mat2Mat2Multiplication)
		{
			// TODO: Your test code here
			matrix2i m1(4, 3, 6, 1);
			matrix2i m2(2, 5, 9, 5);

			matrix2i res = m1 * m2;

			// should be equal to m{38, 11, 66, 32}
			matrix2i comp1{ 6, 8, 10, 13 };
			matrix2i comp2{ 38, 11, 66, 32 };
			//Assert::AreEqual(res, comp1);
			Assert::AreEqual(res, comp2);
		}
	};
}