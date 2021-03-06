#include "stdafx.h"
#include "CppUnitTest.h"
#include "impl.h"
#include <cassert>
#include <cmath>

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
			vector2f v(1, 2);

			Assert::AreEqual(r1, v, L"They are not equal");
		}

		TEST_METHOD(mat2_row_1_test)
		{
			// TODO: Your test code here
			mat2<float> m1(1, 2, 3, 4);

			auto r1 = m1.get_row_1();
			vector2f v(3, 4);

			Assert::AreEqual(r1, v, L"They are not equal");
		}

		TEST_METHOD(mat2_col_0_test)
		{
			// TODO: Your test code here
			mat2<float> m1(1, 2, 3, 4);

			auto c1 = m1.get_column_0();
			//v2f v(2, 4);
			vector2f v(1, 3);
			Assert::AreEqual(c1, v, L"Not equal: Should be 1 and 2");
		}

		TEST_METHOD(mat2_col_1_test)
		{
			// TODO: Your test code here
			mat2<float> m1(1, 2, 3, 4);

			auto c1 = m1.get_column_1();
			//v2f v(2, 4);
			//v2f v(1, 2);
			vector2f v{ 2, 4 };
			Assert::AreEqual(c1, v, L"Not equal: Should be 3 and 4");
		}

		TEST_METHOD(Mat2IDENTITY_TEST)
		{
			mat2<float> m1;

			m1 = mat2<float>::identity_matrix();

			mat2<float> m2(1, 0, 1, 0);
			mat2<float> m3;		// default constructed to identity

			Assert::AreEqual(m1, m3, L"Not equal to identity");
		}

		TEST_METHOD(ZeroTest)
		{
			// TODO: Your test code here
			matrix2f m1;
			matrix2f m2;

			auto res = matrix2f::zero_matrix();
			m2 = matrix2f{ 0, 0, 0, 0 };
			Assert::AreEqual(res, m2, L"They should both have all zero elements");
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

			m1 = m1 + m2;

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

			// removed -= operator
			m1 = m1 - m2;

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
			matrix2i comp2{ 35, 35, 21, 35 };
			//Assert::AreEqual(res, comp1);
			Assert::AreEqual(res, comp2);
		}

		TEST_METHOD(ScaleTestMat2)
		{
			// TODO: Your test code here
			matrix2i m1;
			m1 = matrix2i::scale_matrix(4, 7);
			matrix2i m2(4, 0, 0, 8);


			// should be equal to m{4, 0, 0, 7}
			matrix2i comp2{ 4, 0, 0, 7 };
			//Assert::AreEqual(m1, m2);
			Assert::AreEqual(m1, comp2);
		}

		TEST_METHOD(TransposeTestMat2)
		{
			// TODO: Your test code here
			matrix2i m1{ 3, 4, 7, 9 };
			m1 = m1.transpose();

			// should be equal to m {3 4
			//						 7 9}

			matrix2i m2{ 3, 9, 4, 7 };
			matrix2i comp2{ 3, 7, 4, 9 };
			//Assert::AreEqual(m1, m2);
			Assert::AreEqual(m1, comp2);
		}

		TEST_METHOD(RotationTestMat2)
		{
			constexpr float PI = 3.1415926535897932384626433832795f;

			// 1.0471975511965977461542144610932
			const float pi_div_3 = PI / 3.0f;


			matrix2f m;
			m = matrix2f::rotation_matrix_z(pi_div_3);

			float c = cos(pi_div_3);
			float s = sin(pi_div_3);

			matrix2f wrong(c + 0.1f, s + 0.1f, -s, c);
			matrix2f right(c, s, -s, c);

			//Assert::AreEqual(m, wrong);
			Assert::AreEqual(m, right);
		}

		TEST_METHOD(Mat3IdentityTest)
		{
			matrix3f m1(3, 4, 5, 6, 7, 8, 9, 10, 11);
			matrix3f m2;

			//Assert::AreEqual(m1.is_identity(), true);
			Assert::AreEqual(m2.is_identity(), true);

			m1 = matrix3f::identity_matrix();
			Assert::AreEqual(m2, m1);
		}

		TEST_METHOD(Mat3Mat3Multiplication)
		{
			matrix3i m1{ 4, 7, 2, 3, 2, 1, 5, 0, 8 };
			matrix3i m2{ 2, 4, 1, 7, 3, 0, 2, 4, 2 };

			matrix3i res = m1 * m2;

			matrix3i wrong{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			matrix3i right{ 61, 45, 8, 22, 22, 5, 26, 52, 21 };

			//Assert::AreEqual(res, wrong);
			Assert::AreEqual(res, right);
		}

		TEST_METHOD(Mat3RotationTestZ)
		{
			constexpr float PI = 3.1415926535897932384626433832795f;

			// 1.0471975511965977461542144610932
			const float pi_div_3 = PI / 3.0f;

			matrix3f m = matrix3f::rotation_z_matrix(pi_div_3);

			float c = cos(pi_div_3);
			float s = sin(pi_div_3);

			matrix3f wrong(c + 0.1f, s + 0.1f, 0, -s, c, 0, 0, 0, 1.0f);
			matrix3f right(c, s, 0.0f, -s, c, 0.0f, 0.0f, 0.0f, 1.0);

			//Assert::AreEqual(m, wrong);
			Assert::AreEqual(m, right);
		}

		TEST_METHOD(Mat3RotationTestY)
		{
			constexpr float PI = 3.1415926535897932384626433832795f;

			// 1.0471975511965977461542144610932
			const float pi_div_3 = PI / 3.0f;

			matrix3f m = matrix3f::rotation_y_matrix(pi_div_3);

			float c = cos(pi_div_3);
			float s = sin(pi_div_3);

			matrix3f wrong(c + 0.1f, s + 0.1f, 0, -s, c, 0, 0, 0, 1.0f);
			matrix3f right(c, 0.0f, -s, 0.0f, 1.0f, 0.0f, s, 0.0f, c);

			//Assert::AreEqual(m, wrong);
			Assert::AreEqual(m, right);
		}

		TEST_METHOD(Mat3RotationTestX)
		{
			constexpr float PI = 3.1415926535897932384626433832795f;

			// 1.0471975511965977461542144610932
			const float pi_div_3 = PI / 3.0f;

			matrix3f m = matrix3f::rotation_x_matrix(pi_div_3);

			float c = cos(pi_div_3);
			float s = sin(pi_div_3);

			matrix3f wrong(c + 0.1f, s + 0.1f, 0, -s, c, 0, 0, 0, 1.0f);
			matrix3f right(1.0f, 0.0f, 0.0f, 0.0f, c, s, 0.0f, -s, c);

			//Assert::AreEqual(m, wrong);
			Assert::AreEqual(m, right);
		}

		TEST_METHOD(Mat4Identity)
		{
			matrix4f m1;
			matrix4f m2(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

			//Assert::AreEqual(m1, m2);
			m2 = m2.identity_matrix();
			Assert::AreEqual(m1, m2);
			Assert::AreEqual(m1.is_identity(), true);
			m2.elements[5] = 4;
			Assert::AreEqual(m2.is_identity(), false);
		}

		TEST_METHOD(Mat4MoveCopyconstruct)
		{
			matrix4i m1(matrix4i(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16));
			matrix4i m2(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
			Assert::AreEqual(m1, m2);
		}

		TEST_METHOD(Mat4Mat4Mulitplication)
		{
			matrix4i m1(matrix4i(1, 5, 9, 13,
				2, 6, 10, 14,
				3, 7, 11, 15,
				4, 8, 12, 16));
			matrix4i m2(m1);

			matrix4i res = m1 * m2;

			matrix4i right(90, 202, 314, 426,
				100, 228, 356, 484,
				110, 254, 398, 542,
				120, 280, 440, 600);

			matrix4i wrong;

			//Assert::AreEqual(res, wrong);
			Assert::AreEqual(res, right);
		}

		TEST_METHOD(Mat4TranslationAndVectorMultiply)
		{
			matrix4i translation;
			translation = matrix4i::translation_matrix(4, 5, 6);

			vector4i point(0, 0, 0, 1);

			vector4i res = translation * point;

			vector4i wrong = { 0, 0, 0, 1 };
			vector4i right = { 4, 5, 6, 1 };

			//Assert::AreEqual(res, wrong);
			Assert::AreEqual(res, right);
		}

		TEST_METHOD(Mat3RotationZMultiplyVec)
		{
			matrix3f m = matrix3f::rotation_z_matrix(degrees_to_radians(90.0f));

			vector3f v{ 1.0f, 0.0f, 0.0f };

			auto res = v * m;

			vector3f wrong{ 1.0f, 1.0f, 0.0f};
			vector3f right{ 0.0f, 1.0f, -0.0f};

			//Assert::AreEqual(res, wrong);
			Assert::AreEqual(res, right);
		}

		TEST_METHOD(Mat4RotationXMultiplyVec4)
		{
			matrix4f m;
			matrix4f m2;
			matrix4f m3;

			matrix4f r1 = m * m2 * m3;

			Assert::AreEqual(r1.is_identity(), true);
			m = matrix4f::rotation_x_matrix(degrees_to_radians(90.0f));

			vector4f v{ 0.0f, 1.0f, 0.0f, 0.0f };

			auto res = m * v;

			vector4f wrong{ 1.0f, 1.0f, 0.0f, 0.0f };
			vector4f right{ 0.0f, 0.0f, 1.0f, 0.0f };

			//Assert::AreEqual(res, wrong);
			Assert::AreEqual(res, right);
		}


		TEST_METHOD(Mat4RotationYMultiplyVec4)
		{
			matrix4f m;
			matrix4f m2;
			matrix4f m3;

			matrix4f r1 = m * m2 * m3;

			Assert::AreEqual(r1.is_identity(), true);
			m = matrix4f::rotation_y_matrix(degrees_to_radians(90.0f));

			vector4f v{ 1.0f, 0.0f, 0.0f, 0.0f };

			auto res = v * m;

			vector4f wrong{ 1.0f, 1.0f, 0.0f, 0.0f };
			vector4f right{ 0.0f, 0.0f, -1.0f, 0.0f };

			//Assert::AreEqual(res, wrong);
			Assert::AreEqual(res, right);
		}

		TEST_METHOD(Mat4RotationZMultiplyVec4)
		{
			matrix4f m;
			matrix4f m2;
			matrix4f m3;

			matrix4f r1 = m * m2 * m3;

			Assert::AreEqual(r1.is_identity(), true);
			m = matrix4f::rotation_z_matrix(degrees_to_radians(90.0f));

			vector4f v{ 1.0f, 0.0f, 0.0f, 0.0f };

			auto res = m * v;

			vector4f wrong{ 1.0f, 1.0f, 0.0f, 0.0f };
			vector4f right{ 0.0f, 1.0f, -0.0f, 0.0f };

			//Assert::AreEqual(res, wrong);
			Assert::AreEqual(res, right);
		}

		TEST_METHOD(Mat4RotationZPreMultiplyVec4)
		{
			matrix4f m;
			matrix4f m2;
			matrix4f m3;
			matrix4f m4;

			matrix4f r1 = m * m2 * m3 * m4;

			Assert::AreEqual(r1.is_identity(), true);
			m = matrix4f::rotation_z_matrix(degrees_to_radians(90.0f));

			vector4f v{ 1.0f, 0.0f, 0.0f, 0.0f };

			auto res = v * m;

			vector4f wrong{ 1.0f, 1.0f, 0.0f, 0.0f };
			vector4f right{ 0.0f, 1.0f, -0.0f, 0.0f };

			//Assert::AreEqual(res, wrong);
			Assert::AreEqual(res, right);
		}

		TEST_METHOD(MakeMatrices)
		{
			matrix4f::rotation_x_matrix(44.3f);
			matrix4f::rotation_y_matrix(30.0f);
			matrix4f::rotation_z_matrix(20.0f);

			matrix4f::scale_matrix(1, 1, 1);

			matrix4f::translation_matrix(20, 20, 20);
		}

		TEST_METHOD(AffineCombinationTest)
		{
			std::vector<vector4f> points{
				{4, 2, 0, 1},
			{-4, -2, 0, 1},
			{0, -5, 0, 1}
			};

			std::vector<float> scalars{ 0.2f, 0.5f, 1.0f };

			auto point_combination = affine_combination(points, scalars);

			Assert::AreNotEqual(point_combination, vector4f{ 0.0f, 0.0f, 0.0f, 1.0f });
		}

		TEST_METHOD(AngleTest)
		{
			/*matrix4f rot = matrix4f::rotation_matrix_z(degrees_to_radians(45.0f));
			vector4f x_vec{ 1.0f, 0.0f, 0.0f, 0.0f };

			vector4f rot_vec = rot * x_vec;*/

			matrix3f rot = matrix3f::rotation_z_matrix(degrees_to_radians(45.0f));
			vector3f x_vec{ 1.0f, 0.0f, 0.0f };

			vector3f rot_vec = rot * x_vec;

			auto angle_between = angle(rot_vec, x_vec);
			auto angle_in_degrees = radians_to_degrees<float>(angle_between);
			
			Assert::AreEqual(angle_in_degrees, 45.000f);
		}

		TEST_METHOD(CrossProductTest)
		{
			vector3f v1{ -1.0f, 0.0f, 0.0f };
			vector3f v2{ 0.0f, 0.0f, 1.0f };

			auto res = v1.cross(v2);

			Assert::AreEqual(res, vector3f{ 0.0f, 1.0f, 0.0f });
		}

		TEST_METHOD(Determinant2X2)
		{
			matrix2i m1{ 2, 1, -1, 2 };
			int wrong = 44;
			int right = 5;

			//Assert::AreEqual(m1.determinant(), wrong);
			Assert::AreEqual(m1.determinant(), right);
		}

		TEST_METHOD(Determinant3X3)
		{
			matrix3i m1{ 1, 5, 7, 
			5, 2, -6, 
			2, 1, 0};
			int wrong = 312;
			int right = -47;

			auto r0 = m1.get_row_0();
			auto r1 = m1.get_row_1();
			auto r2 = m1.get_row_2();

			auto res = (r0.cross(r1).dot(r2));

			//Assert::AreEqual(m1.determinant(), wrong);
			Assert::AreEqual(m1.determinant(), right);
		}

		TEST_METHOD(Determinant4X4)
		{
			matrix4i m1{2, 6, 6, 2,
			2, 7, 3, 6,
			1, 5, 0, 1,
			3, 7, 0, 7};
			int wrong = 312;
			int right = -168;

			//auto r0 = m1.get_row_0();
			//auto r1 = m1.get_row_1();
			//auto r2 = m1.get_row_2();

			//auto res = (r0.cross(r1).dot(r2));

			//Assert::AreEqual(m1.determinant(), wrong);
			Assert::AreEqual(right, m1.determinant());
		}

		TEST_METHOD(ProjectionMatrixTest)
		{
			fmake_ortho(-3, 3, -3, 3, 0.1f, 100.0f);
		}

		TEST_METHOD(ScalarMultiplyVector)
		{
			knu::math::vector2i v1{ 2, 4 };
			Assert::AreEqual(vector2i{ 8, 16 }, 4 * v1);

			knu::math::vector3i v2{ 2, 3, 4 };
			Assert::AreEqual(vector3i{ 4, 6, 8 }, 2 * v2);

			vector4i v3{ 1, 2, 3, 4 };
			Assert::AreEqual(vector4i{ 3, 6, 9, 12 }, 3 * v3);
		}

	};
}