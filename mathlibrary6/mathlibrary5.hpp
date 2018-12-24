#ifndef KNU_MATH_LIBRARY_5
#define KNU_MATH_LIBRARY_5

#include <cmath>
#include <iostream>
#include <vector>
#include <array>
#include <numeric>

namespace knu
{
	inline namespace math6
	{

	}
	namespace math
	{
		const int MAT_2_2 = 4;
		const int MAT_3_3 = 9;
		const int MAT_4_4 = 16;

		template<typename T>
		class Vec2
		{
		public:

			typedef T value_type;

			// Default constructor
			Vec2<T>()
				:
				x(static_cast<T>(0)),
				y(static_cast<T>(0))
			{}

			Vec2<T>(T ptr[2])
				:
				x(ptr[0]),
				y(ptr[1])
			{}

			Vec2<T>(T x_, T y_)
				:
				x(x_),
				y(y_)
			{}

			// Copy constructor
			template<typename T2>
			Vec2<T>(const Vec2<T2> &v)
				:
				x(v.x),
				y(v.y)
			{}

			template<typename T2>
			Vec2<T> &operator =(const Vec2<T2> &v)
			{
				x = v.x;
				y = v.y;

				return (*this);
			}

			template<typename T2>
			Vec2<T> operator +(const Vec2<T2> &v)const
			{
				return (Vec2(x + v.x, y + v.y));
			}

			template<typename T2>
			Vec2<T> &operator +=(const Vec2<T2> &v)
			{
				x += v.x;
				y += v.y;

				return (*this);
			}

			template<typename T2>
			Vec2<T> operator -(const Vec2<T2> &v)const
			{
				return (Vec2(x - v.x, y - v.y));
			}

			template<typename T2>
			Vec2<T> &operator -=(const Vec2<T2> &v)
			{
				x -= v.x;
				y -= v.y;

				return (*this);
			}


			Vec2<T> operator *(T scalar)const
			{
				return (Vec2(x * scalar, y * scalar));
			}

			Vec2<T> &operator *=(T scalar)
			{
				x *= scalar;
				y *= scalar;

				return (*this);
			}

			Vec2<T> operator /(T scalar)const
			{
				return (Vec2<T>(x / scalar, y / scalar));
			}

			Vec2<T> &operator /=(T scalar)
			{
				x /= scalar;
				y /= scalar;

				return (*this);
			}

			float length()const
			{
				return (sqrt((x * x) + (y * y)));
			}

			float length_squared()const
			{
				return ((x * x) + (y * y));
			}

			Vec2<T>& normalize()
			{
				if (is_zero())
					return (*this);

				T length_ = length();

				x /= length_;
				y /= length_;

				return (*this);
			}

			bool is_zero()const
			{
				if ((x == static_cast<T>(0)) && (y == static_cast<T>(0)))
					return (true);

				return (false);
			}

			template<typename T2>
			float dot(const Vec2<T2> &v)const
			{
				return ((x * v.x) + (y * v.y));
			}

			void zero()
			{
				x = y = static_cast<T>(0);
			}

			void set(T x_, T y_)
			{
				x = x_;
				y = y_;
			}
			T x, y;
		};			// Class Vec2


		template<typename T>
		class Vec3{
		public:

			typedef T value_type;

			// Default constructor
			Vec3<T>()
				:
				x(static_cast<T>(0)),
				y(static_cast<T>(0)),
				z(static_cast<T>(0))
			{}

			Vec3<T>(T ptr[3])
				:
				x(ptr[0]),
				y(ptr[1]),
				z(ptr[2])
			{}

			Vec3<T>(T x_, T y_, T z_)
				:
				x(x_),
				y(y_),
				z(z_)
			{}

			// Destructor
			~Vec3(){}

			// Copy constructor
			template<typename T2>
			Vec3<T>(const Vec3<T2> &v)
				:
				x(v.x),
				y(v.y),
				z(v.z)
			{}

			Vec3<T> operator -()const
			{
				return Vec3<T>(-x, -y, -z);
			}

			template<typename T2>
			Vec3<T> &operator =(const Vec3<T2> &v)
			{
				x = v.x;
				y = v.y;
				z = v.z;

				return (*this);
			}

			template<typename T2>
			const Vec3<T> operator +(const Vec3<T2> &v)const
			{
				return (Vec3<T>(x + v.x, y + v.y, z + v.z));
			}

			template<typename T2>
			Vec3<T>& operator +=(const Vec3<T2> &v)
			{
				x += v.x;
				y += v.y;
				z += v.z;

				return (*this);
			}

			template<typename T2>
			const Vec3<T> operator -(const Vec3<T2> &v)const
			{
				return (Vec3<T>(x - v.x, y - v.y, z - v.z));
			}

			Vec3<T> &operator -=(const Vec3<T> &v)
			{
				x -= v.x;
				y -= v.y;
				z -= v.z;

				return (*this);
			}

			const Vec3<T> operator *(T scalar)const
			{
				return (Vec3<T>(x * scalar, y * scalar, z * scalar));
			}

			Vec3<T>& operator *=(T scalar)
			{
				x *= scalar;
				y *= scalar;
				z *= scalar;

				return (*this);
			}

			const Vec3<T> operator /(T scalar)const
			{
				return (Vec3<T>(x / scalar, y / scalar, z / scalar));
			}

			Vec3<T>& operator /=(T scalar)
			{
				x /= scalar;
				y /= scalar;
				z /= scalar;

				return (*this);
			}

			T length()const
			{
				return (sqrt((x * x) + (y * y) + (z * z)));
			}

			T length_squared()const
			{
				return ((x * x) + (y * y) + (z * z));
			}

			Vec3<T>& normalize()
			{
				if (is_zero())
					return (*this);

				T length_ = length();
				x /= length_;
				y /= length_;
				z /= length_;

				return (*this);
			}

			bool is_zero()const
			{
				if ((x == static_cast<T>(0)) && (y == static_cast<T>(0)) && (z == static_cast<T>(0)))
					return (true);

				return (false);
			}

			template<typename T2>
			T dot(const Vec3<T2> &v)const
			{
				return ((x * v.x) + (y * v.y) + (z * v.z));
			}

			template<typename T2>
			Vec3<T> cross(const Vec3<T2> &v)const
			{
				return (Vec3<T>(((y * v.z) - (z * v.y)), ((z * v.x) - (x * v.z)), ((x * v.y) - (y * v.x))));
			}

			void zero()
			{
				x = y = z = static_cast<T>(0);
			}

			void set(T x_, T y_, T z_)
			{
				x = x_;
				y = y_;
				z = z_;
			}
            
            Vec2<T> get_vec2() const
            {
                return Vec2<T>(x, y);
            }

			T x, y, z;

		};			// Class Vec3

		template<typename T>
		class Vec4{
		public:

			typedef T value_type;

			// Default constructor
			Vec4<T>()
				:
				x(static_cast<T>(0)),
				y(static_cast<T>(0)),
				z(static_cast<T>(0)),
				// Changed the w from 1 in mathlibrary5 to 0 in mathlibrary6.
				// No longer assuming we want to create a point.
				w(static_cast<T>(0))
			{}

			Vec4<T>(T ptr[4])
				:
				x(ptr[0]),
				y(ptr[1]),
				z(ptr[2]),
				w(ptr[3])
			{}

			Vec4(T x_, T y_, T z_, T w_)
				:
				x(x_),
				y(y_),
				z(z_),
				w(w_)
			{}

			template<typename T2, typename T3>
			Vec4<T>(const Vec3<T2> &v, T3 w_)
				:
				x(v.x),
				y(v.y),
				z(v.z),
				w(w_)
			{}

			// Copy constructor
			template<typename T2>
			Vec4<T>(const Vec4<T2> &v)
				:
				x(v.x),
				y(v.y),
				z(v.z),
				w(v.w)
			{}

			Vec4<T> operator -()const
			{
				return Vec4<T>(-x, -y, -z, -w);
			}


			template<typename T2>
			Vec4<T>& operator =(const Vec4<T2> &v)
			{
				x = v.x;
				y = v.y;
				z = v.z;
				w = v.w;

				return (*this);
			}

			template<typename T2>
			Vec4<T> operator +(const Vec4<T2> &v)const
			{
				return (Vec4(x + v.x, y + v.y, z + v.z, w + v.w));
			}

			template<typename T2>
			Vec4<T>& operator +=(const Vec4<T2> &v)
			{
				x += v.x;
				y += v.y;
				z += v.z;
				w += v.w;

				return (*this);
			}

			template<typename T2>
			Vec4<T> operator -(const Vec4<T2> &v)const
			{
				return (Vec4<T>(x - v.x, y - v.y, z - v.z, w - v.w));
			}

			template<typename T2>
			Vec4<T>& operator -=(const Vec4<T2> &v)
			{
				x -= v.x;
				y -= v.y;
				z -= v.z;
				w -= v.w;

				return (*this);
			}

			Vec4<T> operator *(T scalar)const
			{
				return (Vec4<T>(x * scalar, y * scalar, z * scalar, w * scalar));
			}

			Vec4<T>& operator *=(T scalar)
			{
				x *= scalar;
				y *= scalar;
				z *= scalar;
				w *= scalar;

				return (*this);
			}

			Vec4<T> operator /(T scalar)const
			{
				return (Vec4<T>(x / scalar, y / scalar, z / scalar, w / scalar));
			}

			Vec4<T>& operator /=(T scalar)
			{
				x /= scalar;
				y /= scalar;
				z /= scalar;
				w /= scalar;

				return (*this);
			}

			T length()const
			{
				return (sqrt((x * x) + (y * y) + (z * z))); // removed w as it shouldn't contribute to length
			}

			T length_squared()const
			{
				return ((x * x) + (y * y) + (z * z));   // removed w as it shouldn't contribute to length_squared
			}

			Vec4<T>& normalize()
			{
				if (is_zero())
					return (*this);

				T length_ = length();

				x /= length_;
				y /= length_;
				z /= length_;
				// w /= length_;    // doesn't need to be normalized

				return (*this);
			}

			bool is_zero()const
			{
				if ((x == static_cast<T>(0)) && (y == static_cast<T>(0)) && (z == static_cast<T>(0)) &&
					(w == static_cast<T>(0)))
					return (true);

				return (false);
			}

			template<typename T2>
			T dot(const Vec4<T2> &v)const
			{
				return ((x * v.x) + (y * v.y) + (z * v.z) + (w * v.w));
			}

			void zero()
			{
				x = y = z = w = static_cast<T>(0);
			}

			void set(T x_, T y_, T z_, T w_)
			{
				x = x_;
				y = y_;
				z = z_;
				w = w_;
			}
            
            Vec3<T> get_vec3() const
            {
                return Vec3<T>(x, y, z);
            }

			T x, y, z, w;
		};

		template<typename T>
		class Mat2
		{
		public:
			typedef T value_type;

			Mat2<T>() :
				elements(MAT_2_2)
			{
				set_identity();
			}

			Mat2<T>(T a, T b, T c, T d) :
				elements(MAT_2_2)
			{
				elements[0] = a;
				elements[1] = b;
				elements[2] = c;
				elements[3] = d;
			}

			template<typename T2>
			Mat2<T>(const Mat2<T2> &m) :
				elements(MAT_2_2)
			{
				std::copy(std::begin(m.elements), std::end(m.elements),
					std::begin(elements));
			}

			template<typename T2>
			Mat2<T> &operator=(const Mat2<T2> &m)
			{
				std::copy(std::begin(m.elements), std::end(m.elements),
					std::begin(elements));
				return *this;
			}

			T &operator [](int i)
			{
				return elements[i];
			}

			T operator [](int i)const
			{
				return elements[i];
			}

			Vec2<T> get_row_0()const
			{
				return Vec2<T>(elements[0], elements[1]);
			}

			Vec2<T> get_row_1()const
			{
				return Vec2<T>(elements[2], elements[3]);
			}

			void set_row_0(T a, T b)
			{
				elements[0] = a;
				elements[1] = b;
			}

			template<typename T2>
			void set_row_0(const Vec2<T2> &v)
			{
				set_row_0(v.x, v.y);
			}

			void set_row_1(T a, T b)
			{
				elements[2] = a;
				elements[3] = b;
			}

			template<typename T2>
			void set_row_1(const Vec2<T2> &v)
			{
				set_row_1(v.x, v.y);
			}

			Vec2<T> get_column_0()const
			{
				return Vec2<T>(elements[0], elements[2]);
			}

			Vec2<T> get_column_1()const
			{
				return Vec2<T>(elements[1], elements[3]);
			}

			void set_column_0(T a, T b)
			{
				elements[0] = a;
				elements[2] = b;
			}

			template<typename T2>
			void set_column_0(const Vec2<T2> &v)
			{
				set_column_0(v.x, v.y);
			}

			void set_column_1(T a, T b)
			{
				elements[1] = a;
				elements[3] = b;
			}

			template<typename T2>
			void set_column_1(const Vec2<T2> &v)
			{
				set_column_1(v.x, v.y);
			}

			Mat2<T> &set_identity()
			{
				set_row_0(1, 0);
				set_row_1(0, 1);
				return *this;
			}

			Mat2<T> &zero()
			{
				std::fill(std::begin(elements), std::end(elements), 0);
				return *this;
			}

			template<typename T2>
			Mat2<T> operator+(const Mat2<T2> &m)const
			{
				Mat2<T> ret(elements[0] + m.elements[0],
					elements[1] + m.elements[1],
					elements[2] + m.elements[2],
					elements[3] + m.elements[3]);
				return ret;
			}

			template<typename T2>
			Mat2<T> &operator+=(const Mat2<T2> &m)
			{
				*this = *this + m;
				return *this;
			}


			template<typename T2>
			Mat2<T> operator-(const Mat2<T2> &m)const
			{
				Mat2<T> ret(elements[0] - m.elements[0],
					elements[1] - m.elements[1],
					elements[2] - m.elements[2],
					elements[3] - m.elements[3]);
				return ret;
			}

			template<typename T2>
			Mat2<T> &operator-=(const Mat2<T2> &m)
			{
				*this = *this - m;
				return *this;
			}

			template<typename T2>
			Mat2<T> operator*(const Mat2<T2> &m)const
			{
				Mat2<T> ret;
				ret[0] = get_row_0().dot(m.get_column_0());
				ret[1] = get_row_0().dot(m.get_column_1());

				ret[2] = get_row_1().dot(m.get_column_0());
				ret[3] = get_row_1().dot(m.get_column_1());
				return ret;
			}

			Mat2<T> &scale(T x, T y)
			{
				set_row_0(x, 0);
				set_row_1(0, y);
				return *this;
			}
			Mat2<T> &transpose()
			{
				auto row0 = get_row_0();
				auto row1 = get_row_1();
				set_column_0(row0);
				set_column_1(row1);

				return *this;
			}

			Mat2<T> &rotation(T radians)
			{
				T c = cos(radians);
				T s = sin(radians);

				set_row_0(c, s);
				set_row_1(-s, c);
				return *this;
			}

			T* data()
			{
				return &elements[0];
			}

		public:
			std::array<T, MAT_2_2> elements;
		};

		template<typename T>
		class Mat3
		{
		public:
			typedef T value_type;

			Mat3<T>()
			{
				set_identity();
			}

			Mat3<T>(T a, T b, T c, T d, T e, T f, T g, T h, T i)
			{
				elements[0] = a;
				elements[1] = b;
				elements[2] = c;
				elements[3] = d;
				elements[4] = e;
				elements[5] = f;
				elements[6] = g;
				elements[7] = h;
				elements[8] = i;
			}

			template<typename T2>
			Mat3<T>(const Mat3<T2> &m)
			{
				std::copy(std::begin(m.elements), std::end(m.elements),
					std::begin(elements));
			}

			template<typename T2>
			Mat3<T> &operator=(const Mat3<T2> &m)
			{
				std::copy(std::begin(m.elements), std::end(m.elements),
					std::begin(elements));
				return *this;
			}

			T &operator [](int i)
			{
				return elements[i];
			}

			const T &operator [](int i)const
			{
				return elements[i];
			}


			Vec3<T> get_row_0()const
			{
				return Vec3<T>(elements[0], elements[1], elements[2]);
			}

			Vec3<T> get_row_1()const
			{
				return Vec3<T>(elements[3], elements[4], elements[5]);
			}

			Vec3<T> get_row_2()const
			{
				return Vec3<T>(elements[6], elements[7], elements[8]);
			}

			void set_row_0(T x, T y, T z)
			{
				elements[0] = x;
				elements[1] = y;
				elements[2] = z;
			}

			template<typename T2>
			void set_row_0(const Vec3<T2> &v)
			{
				set_row_0(v.x, v.y, v.z);
			}

			void set_row_1(T x, T y, T z)
			{
				elements[3] = x;
				elements[4] = y;
				elements[5] = z;
			}

			template<typename T2>
			void set_row_1(const Vec3<T2> &v)
			{
				set_row_1(v.x, v.y, v.z);
			}

			void set_row_2(T x, T y, T z)
			{
				elements[6] = x;
				elements[7] = y;
				elements[8] = z;
			}

			template<typename T2>
			void set_row_2(const Vec3<T2> &v)
			{
				set_row_2(v.x, v.y, v.z);
			}

			Vec3<T> get_column_0()const
			{
				return Vec3<T>(elements[0], elements[3], elements[6]);
			}

			Vec3<T> get_column_1()const
			{
				return Vec3<T>(elements[1], elements[4], elements[7]);
			}

			Vec3<T> get_column_2()const
			{
				return Vec3<T>(elements[2], elements[5], elements[8]);
			}

			void set_column_0(T x, T y, T z)
			{
				elements[0] = x;
				elements[3] = y;
				elements[6] = z;
			}

			template<typename T2>
			void set_column_0(const Vec3<T2> &v)
			{
				set_column_0(v.x, v.y, v.z);
			}

			void set_column_1(T x, T y, T z)
			{
				elements[1] = x;
				elements[4] = y;
				elements[7] = z;
			}

			template<typename T2>
			void set_column_1(const Vec3<T2> &v)
			{
				set_column_1(v.x, v.y, v.z);
			}

			void set_column_2(T x, T y, T z)
			{
				elements[2] = x;
				elements[5] = y;
				elements[8] = z;
			}

			template<typename T2>
			void set_column_2(const Vec3<T2> &v)
			{
				set_column_2(v.x, v.y, v.z);
			}

			template<typename T2>
			Mat3<T> operator+(const Mat3<T2> &m)const
			{
				Mat3<T> ret(elements[0] + m.elements[0],
					elements[1] + m.elements[1],
					elements[2] + m.elements[2],
					elements[3] + m.elements[3],
					elements[4] + m.elements[4],
					elements[5] + m.elements[5],
					elements[6] + m.elements[6],
					elements[7] + m.elements[7],
					elements[8] + m.elements[8]);
				return ret;
			}

			template<typename T2>
			Mat3<T> &operator +=(const Mat3<T2> &m)
			{
				*this = *this + m;
				return *this;
			}

			template<typename T2>
			Mat3<T> operator-(const Mat3<T2> &m)const
			{
				Mat3<T> ret(elements[0] - m.elements[0],
					elements[1] - m.elements[1],
					elements[2] - m.elements[2],
					elements[3] - m.elements[3],
					elements[4] - m.elements[4],
					elements[5] - m.elements[5],
					elements[6] - m.elements[6],
					elements[7] - m.elements[7],
					elements[8] - m.elements[8]);
				return ret;
			}

			template<typename T2>
			Mat3<T> &operator -=(const Mat3<T2> &m)
			{
				*this = *this - m;
				return *this;
			}

			template<typename T2>
			Mat3<T> operator*(const Mat3<T2> &m)const
			{
				Mat3<T> ret;
				ret[0] = get_row_0().dot(m.get_column_0());
				ret[1] = get_row_0().dot(m.get_column_1());
				ret[2] = get_row_0().dot(m.get_column_2());

				ret[3] = get_row_1().dot(m.get_column_0());
				ret[4] = get_row_1().dot(m.get_column_1());
				ret[5] = get_row_1().dot(m.get_column_2());

				ret[6] = get_row_2().dot(m.get_column_0());
				ret[7] = get_row_2().dot(m.get_column_1());
				ret[8] = get_row_2().dot(m.get_column_2());

				return ret;
			}

			template<typename T2>
			Mat3<T> &operator*=(const Mat3<T2> &m)
			{
				*this = *this * m;
				return *this;
			}

			Mat3<T> &set_identity()
			{
				set_row_0(1, 0, 0);
				set_row_1(0, 1, 0);
				set_row_2(0, 0, 1);

				return *this;
			}

			Mat3<T> &zero()
			{
				std::fill(std::begin(elements), std::end(elements), 0);
				return *this;
			}

			Mat3<T> &scale(T x, T y, T z)
			{
				set_row_0(x, 0, 0);
				set_row_1(0, y, 0);
				set_row_2(0, 0, z);
				return *this;
			}

			Mat3<T> &transpose()
			{
				auto row0 = get_row_0();
				auto row1 = get_row_1();
				auto row2 = get_row_2();

				set_column_0(row0);
				set_column_1(row1);
				set_column_2(row2);

				return *this;
			}

			Mat3<T> &rotate_x(T radians)
			{
				T c = cos(radians);
				T s = sin(radians);

				set_row_0(1, 0, 0);
				set_row_1(0, c, s);
				set_row_2(0, -s, c);

				return *this;
			}

			Mat3<T> &rotate_y(T radians)
			{
				T c = cos(radians);
				T s = sin(radians);

				set_row_0(c, 0, -s);
				set_row_1(0, 1, 0);
				set_row_2(s, 0, c);

				return *this;
			}

			Mat3<T> &rotate_z(T radians)
			{
				T c = cos(radians);
				T s = sin(radians);

				set_row_0(c, s, 0);
				set_row_1(-s, c, 0);
				set_row_2(0, 0, 1);

				return *this;
			}

			T* data()
			{
				return &elements[0];
			}

		public:
			std::array<T, MAT_3_3> elements;
		};

		template<typename T>
		class Mat4
		{
		public:
			typedef T value_type;

			Mat4<T>()
			{
				identity();
			}

			Mat4<T>(T a, T b, T c, T d, T e, T f, T g, T h, T i, T j, T k, T l, T m, T n, T o, T p)
			{
				elements[0] = a;
				elements[1] = b;
				elements[2] = c;
				elements[3] = d;
				elements[4] = e;
				elements[5] = f;
				elements[6] = g;
				elements[7] = h;
				elements[8] = i;
				elements[9] = j;
				elements[10] = k;
				elements[11] = l;
				elements[12] = m;
				elements[13] = n;
				elements[14] = o;
				elements[15] = p;
			}

			template<typename T2>
			Mat4<T>(const Mat4<T2> &m)
			{
				std::copy(std::begin(m.elements), std::end(m.elements),
					std::begin(elements));
			}

			template<typename T2>
			Mat4<T> &operator=(const Mat4<T2> &m)
			{
				std::copy(std::begin(m.elements), std::end(m.elements),
					std::begin(elements));
				return *this;
			}

			T &operator [](int i)
			{
				return elements[i];
			}

			const T &operator [](int i)const
			{
				return elements[i];
			}

			Vec4<T> get_row_0()const
			{
				return Vec4<T>(elements[0], elements[1], elements[2], elements[3]);
			}

			Vec4<T> get_row_1()const
			{
				return Vec4<T>(elements[4], elements[5], elements[6], elements[7]);
			}

			Vec4<T> get_row_2()const
			{
				return Vec4<T>(elements[8], elements[9], elements[10], elements[11]);
			}

			Vec4<T> get_row_3()const
			{
				return Vec4<T>(elements[12], elements[13], elements[14], elements[15]);
			}

			void set_row_0(T x, T y, T z, T w)
			{
				elements[0] = x;
				elements[1] = y;
				elements[2] = z;
				elements[3] = w;
			}

			template<typename T2>
			void set_row_0(const Vec4<T2> &v)
			{
				set_row_0(v.x, v.y, v.z, v.w);
			}

			void set_row_1(T x, T y, T z, T w)
			{
				elements[4] = x;
				elements[5] = y;
				elements[6] = z;
				elements[7] = w;
			}

			template<typename T2>
			void set_row_1(const Vec4<T2> &v)
			{
				set_row_1(v.x, v.y, v.z, v.w);
			}

			void set_row_2(T x, T y, T z, T w)
			{
				elements[8] = x;
				elements[9] = y;
				elements[10] = z;
				elements[11] = w;
			}

			template<typename T2>
			void set_row_2(const Vec4<T2> &v)
			{
				set_row_2(v.x, v.y, v.z, v.w);
			}

			void set_row_3(T x, T y, T z, T w)
			{
				elements[12] = x;
				elements[13] = y;
				elements[14] = z;
				elements[15] = w;
			}

			template<typename T2>
			void set_row_3(const Vec4<T2> &v)
			{
				set_row_3(v.x, v.y, v.z, v.w);
			}

			Vec4<T> get_column_0()const
			{
				return Vec4<T>(elements[0], elements[4], elements[8], elements[12]);
			}

			Vec4<T> get_column_1()const
			{
				return Vec4<T>(elements[1], elements[5], elements[9], elements[13]);
			}

			Vec4<T> get_column_2()const
			{
				return Vec4<T>(elements[2], elements[6], elements[10], elements[14]);
			}

			Vec4<T> get_column_3()const
			{
				return Vec4<T>(elements[3], elements[7], elements[11], elements[15]);
			}

			void set_column_0(T x, T y, T z, T w)
			{
				elements[0] = x;
				elements[4] = y;
				elements[8] = z;
				elements[12] = w;
			}
			template<typename T2>
			void set_column_0(const Vec4<T2> &v)
			{
				set_column_0(v.x, v.y, v.z, v.w);
			}

			void set_column_1(T x, T y, T z, T w)
			{
				elements[1] = x;
				elements[5] = y;
				elements[9] = z;
				elements[13] = w;
			}

			template<typename T2>
			void set_column_1(const Vec4<T2> &v)
			{
				set_column_1(v.x, v.y, v.z, v.w);
			}

			void set_column_2(T x, T y, T z, T w)
			{
				elements[2] = x;
				elements[6] = y;
				elements[10] = z;
				elements[14] = w;
			}

			template<typename T2>
			void set_column_2(const Vec4<T2> &v)
			{
				set_column_2(v.x, v.y, v.z, v.w);
			}

			void set_column_3(T x, T y, T z, T w)
			{
				elements[3] = x;
				elements[7] = y;
				elements[11] = z;
				elements[15] = w;
			}

			template<typename T2>
			void set_column_3(const Vec4<T2> &v)
			{
				set_column_3(v.x, v.y, v.z, v.w);
			}

			template<typename T2>
			Mat4<T> operator+(const Mat4<T2> &m)const
			{
				Mat4<T> ret(elements[0] + m.elements[0],
					elements[1] + m.elements[1],
					elements[2] + m.elements[2],
					elements[3] + m.elements[3],
					elements[4] + m.elements[4],
					elements[5] + m.elements[5],
					elements[6] + m.elements[6],
					elements[7] + m.elements[7],
					elements[8] + m.elements[8],
					elements[9] + m.elements[9],
					elements[10] + m.elements[10],
					elements[11] + m.elements[11],
					elements[12] + m.elements[12],
					elements[13] + m.elements[13],
					elements[14] + m.elements[14],
					elements[15] + m.elements[15]);

				return ret;
			}

			template<typename T2>
			Mat4<T> &operator +=(const Mat4<T2> &m)
			{
				*this = *this + m;
				return *this;
			}


			template<typename T2>
			Mat4<T> operator-(const Mat4<T2> &m)const
			{
				Mat4<T> ret(elements[0] - m.elements[0],
					elements[1] - m.elements[1],
					elements[2] - m.elements[2],
					elements[3] - m.elements[3],
					elements[4] - m.elements[4],
					elements[5] - m.elements[5],
					elements[6] - m.elements[6],
					elements[7] - m.elements[7],
					elements[8] - m.elements[8],
					elements[9] - m.elements[9],
					elements[10] - m.elements[10],
					elements[11] - m.elements[11],
					elements[12] - m.elements[12],
					elements[13] - m.elements[13],
					elements[14] - m.elements[14],
					elements[15] - m.elements[15]);

				return ret;
			}

			template<typename T2>
			Mat4<T> &operator -=(const Mat4<T2> &m)
			{
				*this = *this - m;
				return *this;
			}

			Mat4<T> operator*(double scalar)const
			{
				Mat4<T> ret;

				std::transform(std::begin(elements), std::end(elements), std::begin(ret.elements),
					[=](T val){
						return (scalar * val);
				});
				return ret;
			}

			template<typename T2>
			Mat4<T> operator*(const Mat4<T2> &m)const
			{
				Mat4<T> ret;

				ret[0] = get_row_0().dot(m.get_column_0());
				ret[1] = get_row_0().dot(m.get_column_1());
				ret[2] = get_row_0().dot(m.get_column_2());
				ret[3] = get_row_0().dot(m.get_column_3());

				ret[4] = get_row_1().dot(m.get_column_0());
				ret[5] = get_row_1().dot(m.get_column_1());
				ret[6] = get_row_1().dot(m.get_column_2());
				ret[7] = get_row_1().dot(m.get_column_3());

				ret[8] = get_row_2().dot(m.get_column_0());
				ret[9] = get_row_2().dot(m.get_column_1());
				ret[10] = get_row_2().dot(m.get_column_2());
				ret[11] = get_row_2().dot(m.get_column_3());

				ret[12] = get_row_3().dot(m.get_column_0());
				ret[13] = get_row_3().dot(m.get_column_1());
				ret[14] = get_row_3().dot(m.get_column_2());
				ret[15] = get_row_3().dot(m.get_column_3());

				return ret;
			}

			template<typename T2>
			Mat4<T> &operator*=(const Mat4<T2> &m)
			{
				*this = *this * m;
				return *this;
			}

			Mat4<T>& translate(T x, T y, T z)
			{
				set_row_0(Vec4<T>(T(1.0f), T(0.0f), T(0.0f), T(0.0f)));
				set_row_1(Vec4<T>(T(0.0f), T(1.0f), T(0.0f), T(0.0f)));
				set_row_2(Vec4<T>(T(0.0f), T(0.0f), T(1.0f), T(0.0f)));
				set_row_3(Vec4<T>(x, y, z, T(1.0f)));

				return *this;
			}

			template<typename T2>
			Mat4<T> &translate(const Vec4<T2> &v)
			{
				translate(v.x, v.y, v.z);
				return *this;
			}

			Mat4<T> &rotate_x(T radians)
			{
				T c = cos(radians);
				T s = sin(radians);

				set_row_0(1, 0, 0, 0);
				set_row_1(0, c, s, 0);
				set_row_2(0, -s, c, 0);
				set_row_3(0, 0, 0, 1);

				return *this;
			}

			Mat4<T> &rotate_y(T radians)
			{
				T c = cos(radians);
				T s = sin(radians);

				set_row_0(c, 0, -s, 0);
				set_row_1(0, 1, 0, 0);
				set_row_2(s, 0, c, 0);
				set_row_3(0, 0, 0, 1);

				return *this;
			}

			Mat4<T> &rotate_z(T radians)
			{
				T c = cos(radians);
				T s = sin(radians);

				set_row_0(c, s, 0, 0);
				set_row_1(-s, c, 0, 0);
				set_row_2(0, 0, 1, 0);
				set_row_3(0, 0, 0, 1);

				return *this;
			}

			Mat4<T> &scale(T x, T y, T z)
			{
				set_row_0(x, 0, 0, 0);
				set_row_1(0, y, 0, 0);
				set_row_2(0, 0, z, 0);
				set_row_3(0, 0, 0, 1);

				return *this;
			}

			Mat4<T> &transpose()
			{
				auto row0 = get_row_0();
				auto row1 = get_row_1();
				auto row2 = get_row_2();
				auto row3 = get_row_3();

				set_column_0(row0);
				set_column_1(row1);
				set_column_2(row2);
				set_column_3(row3);

				return *this;
			}

			Mat4<T> &identity()
			{
				set_row_0(1, 0, 0, 0);
				set_row_1(0, 1, 0, 0);
				set_row_2(0, 0, 1, 0);
				set_row_3(0, 0, 0, 1);

				return *this;
			}

			Mat4<T> &zero()
			{
				std::fill(std::begin(elements), std::end(elements), 0);
				return *this;
			}

			Mat3<T> make_3x3()const
			{
				Mat3<T> m;
				Vec4<T> v;

				v = get_row_0();
				m.set_row_0(v.x, v.y, v.z);

				v = get_row_1();
				m.set_row_1(v.x, v.y, v.z);

				v = get_row_2();
				m.set_row_2(v.x, v.y, v.z);

				return m;
			}

			T* data()
			{
				return &elements[0];
			}


		public:
			std::array<T, MAT_4_4> elements;
		};
        
         /* say if you have quaternions q60 and q20, and you'd like to "pull the 60 degree quaternion by 20 degrees so you'd have a q80 quaternion, you do q20.multiply(q60) */
        template<typename T>
        class Quaternion
        {
        public:
            T w;
            knu::math::Vec3<T> v;
        public:
            Quaternion<T>() { identity(); }
            Quaternion<T>(T angle, knu::math::Vec3<T> axis) { axis_angle(angle, axis); }
            Quaternion<T>(Quaternion<T> const &other) : w(other.w), v(other.v) {}
            
            Quaternion<T>& operator=(Quaternion<T> const &other)
            {
                w = other.w;
                v = other.v;
                return *this;
            }
            
            Quaternion<T> &identity()
            {
                w = T(1);
                v.zero();
                return *this;
            }
            
            T magnitude() const
            {
                return sqrt((w * w) + (v.dot(v)));
            }
            
            Quaternion<T> &conjugate()
            {
                v = -v;
                return *this;
            }
            
            Quaternion<T> get_conjugate() const
            {
                Quaternion<T> res;
                res.w = w;
                res.v = -v;
                return res;
            }
            
            Quaternion<T> get_inverse() const
            {
                Quaternion<T> res(get_conjugate());
                T mag = magnitude();
                
                res.w /= mag;
                res.x /= mag;
                res.y /= mag;
                res.z /= mag;
                return res;
            }
            
            T get_angle() const
            {
                return 2 * acos(w);
            }
            
            void axis_angle(T angle, knu::math::Vec3<T> axis)
            {
                angle *= 0.5f;
                T s = sin(angle);
                T c = cos(angle);
                
                axis.normalize();
                v = axis * s;
                w = c;
            }
            
            Quaternion<T> multiply(Quaternion<T> const &other) const
            {
                // When mutliplying (adding) the this quaternion is "from" and other is "to"
                Quaternion<T> res;
                res.w = w * other.w - v.dot(other.v);
                res.v = (other.v * w) + (v * other.w) + v.cross(other.v);	// might have to do other.cross(v)
                return res;
            }
            
            knu::math::Vec3<T> multiply(knu::math::Vec3<T> const &other) const
            {
                /*Quaternion<T1> c, p;	// conjugate and point quaternion
                 c.w = w;
                 c.v = -v;
                 
                 p.w = T1(0);
                 p.v = other;
                 
                 Quaternion<T1> res = c.multiply(p);
                 res = res.multiply(*this);
                 
                 
                 return res.v;*/
                
                // The following code rotates the vec counter-clockwise. The above code rotates clockwise
                Quaternion<T> c(get_conjugate()), p;
                p.w = T(0);
                p.v = other;
                
                Quaternion<T> res = p.multiply(c);
                res = this->multiply(res);
                
                return res.v;
            }
            
            Quaternion<T> difference(Quaternion<T> const &other) const
            {
                return other.multiply(get_conjugate());
            }
            
            T dot(Quaternion<T> const &other) const
            {
                return w * other.w + v.x * other.v.x + v.y * other.v.y + v.z * other.v.z;
            }
            
            
            Quaternion<float> exponentiation(float exponent)
            {
                Quaternion<float> res;
                if(fabsf(w) < 1.0f)
                {
                    float alpha = acosf(w);
                    float newAlpha = alpha * exponent;
                    res.w = cosf(newAlpha);
                    float multi = sinf(newAlpha) / sinf(alpha);
                    res.v.x = v.x * multi;
                    res.v.y = v.y * multi;
                    res.v.z = v.z * multi;
                }
                
                return res;
            }
            
            Quaternion<double> exponentiation(double exponent)
            {
                Quaternion<double> res;
                if(fabs(w) < 1.0)
                {
                    double alpha = acos(w);
                    double newAlpha = alpha * exponent;
                    res.w = cos(newAlpha);
                    double multi = sin(newAlpha) / sin(alpha);
                    res.v.x = v.x * multi;
                    res.v.y = v.y * multi;
                    res.v.z = v.z * multi;
                }
                
                return res;
            }
            
            knu::math::Mat4<T> to_matrix() const
            {
                T a = 1 - (2 * v.y * v.y) - (2 * v.z * v.z);
                T b = (2 * v.x * v.y) + (2 * w * v.z);
                T c = (2 * v.x * v.z) - (2 * w * v.y);
                T d = T(0);
                T e = (2 * v.x * v.y) - (2 * w * v.z);
                T f = 1 - (2 * v.x * v.x) - (2 * v.z * v.z);
                T g = (2 * v.y * v.z) + (2 * w * v.x);
                T h = T(0);
                T i = (2 * v.x * v.z) + (2 * w * v.y);
                T j = (2 * v.y * v.z) - (2 * w * v.x);
                T k = 1 - (2 * v.x * v.x) - (2 * v.y * v.y);
                T l = T(0);
                T m = T(0);
                T n = T(0);
                T o = T(0);
                T p = T(1);
                
                return knu::math::Mat4<T>(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p);
            }
        };
        
        template<typename T, typename T2>
        Quaternion<T> slerp(Quaternion<T> from, Quaternion<T> to, T2 t)
        {
            if(t < T2(0))
                return from;
            if(t > T2(1))
                return to;
            
            T cosOmega = from.w * to.w + from.v.x * to.v.x + from.v.y * to.v.y + from.v.z * to.v.z;
            
            if(cosOmega < T(0))
            {
                to.w = -to.w;
                to.v.x = -to.v.x;
                to.v.y = -to.v.y;
                to.v.z = -to.v.z;
                cosOmega = -cosOmega;
            }
            
            T k0, k1;
            
            if(cosOmega > T(0.9999))
            {
                k0 = T(1.0) - T(t);
            }else
            {
                T sinOmega = sqrt(T(1.0) - cosOmega * cosOmega);
                
                T omega = atan2(sinOmega, cosOmega);
                
                T oneOverSineOmega = T(1) / sinOmega;
                
                k0 = sin((T(1) - T(t)) * omega) * oneOverSineOmega;
                k1 = sin(T(t) * omega) * oneOverSineOmega;
            }
            
            // interpolate
            Quaternion<T> res;
            res.w = from.w * k0 + to.w * k1;
            res.v.x = from.v.x * k0 + to.v.x * k1;
            res.v.y = from.v.y * k0 + to.v.y * k1;
            res.v.z = from.v.z * k0 + to.v.z * k1;
            
            return res;
            
        }

		typedef Vec2<int>		Vector2i;
		typedef Vec3<int>		Vector3i;
		typedef Vec4<int>		Vector4i;

		typedef Vec2<float>		Vector2f;
		typedef Vec3<float>		Vector3f;
		typedef Vec4<float>		Vector4f;

		typedef	Vec2<double>	Vector2d;
		typedef Vec3<double>	Vector3d;
		typedef Vec4<double>	Vector4d;

		typedef Mat2<int>       Matrix2i;
		typedef Mat3<int>       Matrix3i;
		typedef Mat4<int>       Matrix4i;

		typedef Mat2<float>     Matrix2f;
		typedef Mat3<float>     Matrix3f;
		typedef Mat4<float>     Matrix4f;

		typedef Mat2<double>    Matrix2d;
		typedef Mat3<double>    Matrix3d;
		typedef Mat4<double>    Matrix4d;
        
        using   vector2i =           Vec2<int>;
        using   vector3i =           Vec3<int>;
        using   vector4i =           Vec4<int>;
        
        using   vector2f =           Vec2<float>;
        using   vector3f =           Vec3<float>;
        using   vector4f =           Vec4<float>;
        
        using   vector2d =           Vec2<double>;
        using   vector3d =           Vec3<double>;
        using   vector4d =           Vec4<double>;
        
        using   m2i =           Mat2<int>;
        using   m3i =           Mat3<int>;
        using   m4i =           Mat4<int>;
        
        using   m2f =           Mat2<float>;
        using   m3f =           Mat3<float>;
        using   m4f =           Mat4<float>;
        
        using   m2d =           Mat2<double>;
        using   m3d =           Mat3<double>;
        using   m4d =           Mat4<double>;
        
        using   qf  =           Quaternion<float>;
        using   qd  =           Quaternion<double>;


		// Math math non member functions
		template<typename T, typename T2>
		Vec2<T2> operator *(const Mat2<T> &m, const Vec2<T2> &v)
		{
			Vec2<T2> ret;
			ret.x = m.get_row_0().dot(v);
			ret.y = m.get_row_1().dot(v);
			return ret;
            
		}

		template<typename T, typename T2>
		Vec2<T2> operator *(const Vec2<T2> &v, const Mat2<T> &m)
		{
			return m * v;
		}

		template<typename T, typename T2>
		Vec3<T2> operator*(const Mat3<T> &m, const Vec3<T2> &v)
		{
			Vec3<T2> ret;
			ret.x = m.get_row_0().dot(v);
			ret.y = m.get_row_1().dot(v);
			ret.z = m.get_row_2().dot(v);

			return ret;
		}

		template<typename T, typename T2>
		Vec3<T2> operator*(const Vec3<T2> &v, const Mat3<T> &m)
		{
			return m * v;
		}

		template<typename T, typename T2>
		Vec4<T2> operator*(const Mat4<T> &m, const Vec4<T2> &v)
		{
			Vec4<T2> ret;
			ret.x = m.get_row_0().dot(v);
			ret.y = m.get_row_1().dot(v);
			ret.z = m.get_row_2().dot(v);
			ret.w = m.get_row_3().dot(v);

			return ret;
		}

		template<typename T, typename T2>
		Vec4<T2> operator*(const Vec4<T2> &v, const Mat4<T> &m)
		{
			Vec4<T2> ret;
			ret.x = v.dot(m.get_column_0());
			ret.y = v.dot(m.get_column_1());
			ret.z = v.dot(m.get_column_2());
			ret.w = v.dot(m.get_column_3());
			return ret;;
		}

		template<typename T>
		Mat4<T> make_translate(T x, T y, T z)
		{
			Mat4<T> m;
			m.translate(x, y, z);
			return m;
		}

		template<typename T>
		Mat4<T> make_rotation_x(T radians)
		{
			Mat4<T> m;
			m.rotate_x(radians);
			return m;
		}

		template<typename T>
		Mat4<T> make_rotation_y(T radians)
		{
			Mat4<T> m;
			m.rotate_y(radians);
			return m;
		}

		template<typename T>
		Mat4<T> make_rotation_z(T radians)
		{
			Mat4<T> m;
			m.rotate_z(radians);
			return m;
		}

		template<typename T>
		Mat4<T> make_scale(T x, T y, T z)
		{
			Mat4<T> m;
			m.scale(x, y, z);
			return m;
		}

		namespace utility
		{
			// Helper utility functions
			const float PI_CONSTANT = 3.141592653f;
			const float DEGREES_TO_RADIANS_CONSTANT = 3.141592653f / 180.0f;
			const float RADIANS_TO_DEGREES_CONSTANT = 180.0f / 3.141592653f;

			template<typename T>
			T degrees_to_radians(T degrees)
			{
				return (PI_CONSTANT * degrees) / T(180.0);
			}

			template<typename T>
			T radians_to_degrees(T radians)
			{
				return (radians * RADIANS_TO_DEGREES_CONSTANT);
			}

			// Return the angle between two vectors
			template<typename VecType>
			typename VecType::value_type angle(const VecType &v1, const VecType &v2)
			{
				return acos(v1.dot(v2));
			}

			template<typename T>
			T distanceVx(const Vec2<T> &v1, const Vec2<T> &v2)
			{
				return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2));
			}

			template<typename T>
			T distanceVx(const Vec3<T> &v1, const Vec3<T> &v2)
			{
				return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2) + pow(v1.z - v2.z, 2));
			}

			template<typename T>
			T distanceVx(const Vec4<T> &v1, const Vec4<T> &v2)
			{
				// do not process the w coordinate
				return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2) + pow(v1.z - v2.z, 2));
			}

			template<typename VecType>
			typename VecType::value_type distance(const VecType &v1, const VecType &v2)
			{
				return distanceVx(v1, v2);
			}

			template<typename Scalar, typename Point>
			Point affine_combination(const std::vector<Scalar> &s, const std::vector<Point> &p)
			{
				if (s.size() != p.size())
					throw std::runtime_error("vector of scalars and vectors of points must be same size");

				std::vector<Point> r(s.size());

				std::transform(std::begin(s), std::end(s), std::begin(p), std::begin(r), [](Scalar sc, Point po)->Point
				{
					return po * sc;
				});

				return std::accumulate(std::begin(r), std::end(r), Point());
			}
			// Get distance between two vectors

			template<typename T>
			Mat4<T> make_ortho(T maxX, T maxY)
			{
				Mat4<T> ortho;
				T a = 1.0f / maxX;
				T b = 1.0f / maxY;

				ortho.set_row_0(a, 0, 0, 0);
				ortho.set_row_1(0, b, 0, 0);
				ortho.set_row_2(0, 0, -1, 0);
				ortho.set_row_3(0, 0, 0, 1);

				return ortho;
			}

			template <typename T>
			Mat4<T> make_ortho(T left, T right, T bottom, T top, T Znear, T Zfar)
			{
				float tx = (left + right) / (left - right);
				float ty = (top + bottom) / (bottom - top);
				float tz = (Zfar + Znear) / (Zfar - Znear);
				Mat4<T> ortho;

				ortho.set_row_0(2 / (right - left), 0, 0, 0);
				ortho.set_row_1(0, 2 / (top - bottom), 0, 0);
				ortho.set_row_2(0, 0, 2 / (Znear - Zfar), 0);
				ortho.set_row_3(tx, ty, tz, 1);

				return ortho;
			}
            
            template <typename T>
            Mat4<T> make_ortho2(T left, T right, T bottom, T top, T Znear, T Zfar)
            {
                float tx = (right + left) / (right - left);
                float ty = (top + bottom) / (top - bottom);
                float tz = (Zfar + Znear) / (Zfar - Znear);
                Mat4<T> ortho;
                
                ortho.set_row_0(2 / (right - left), 0, 0, 0);
                ortho.set_row_1(0, 2 / (top - bottom), 0, 0);
                ortho.set_row_2(0, 0, 2 / (Znear - Zfar), 0);
                ortho.set_row_3(-tx, -ty, -tz, 1);
                
                return ortho;
            }

			template<typename T>
			Mat4<T> make_frustrum(T left, T right, T bottom, T top, T zNear, T zFar)
			{
				float a = 2 * zNear / (right - left);
				float b = 2 * zNear / (top - bottom);
				float A = (right + left) / (right - left);
				float B = (top + bottom) / (top - bottom);
				float C = -((zFar + zNear) / (zFar - zNear));
				float D = -((2 * zFar * zNear) / (zFar - zNear));

				Mat4<T> frustrum;
				frustrum.set_row_0(a, 0, 0, 0);
				frustrum.set_row_1(0, b, 0, 0);
				frustrum.set_row_2(A, B, C, -1);
				frustrum.set_row_3(0, 0, D, 0);

				return frustrum;
			}
            
            template<typename T>
            Mat4<T> make_perspective(T fovRadians, T aspectRatio, T zNear, T zFar)
            {
                T yMax, xMax;
                yMax = zNear * tan(fovRadians);
                xMax = yMax * aspectRatio;
                return make_frustrum<T>(-xMax, xMax, -yMax, yMax, zNear, zFar);
            }

			template<typename VecType>
			VecType project(VecType v, VecType onto)
			{
				onto.normalize();

				auto magnitude = onto.length();
				auto magnitudeSquared = magnitude * magnitude;
				auto dotProduct = v.dot(onto);
				return onto * (dotProduct / magnitudeSquared);
			}

			template<typename VecType>
			std::vector<VecType> orthogonalize(const std::vector<VecType> &v)
			{
				std::vector<VecType> w(v.size());
				w[0] = v[0];

				for (size_t i = 1; i < v.size(); ++i)
					w[i] = v[i] - project(v[i], w[i - 1]);

				std::transform(std::begin(w), std::end(w),
					std::begin(w), [](VecType vector)->VecType{vector.normalize(); return vector; });

				return w;
			}
            
            // ken perlin noise
            inline float noise(int x)
            {
                x = (x << 13) ^ x;
                return (1.0f - ((x * (x * x * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0f);
            }
            
            inline float cos_interpolate(float v1, float v2, float t)
            {
                float angle = t * 3.141592653f;
                float prc = (1.0f - (cos(angle)) * 0.5f);
                return v1 * (1.0f - prc) + v2 * prc;
            }
            
            template<typename T>
            inline T clamp(T value, T minValue, T maxValue)
            {
                if(value < minValue)        return minValue;
                else if(value > maxValue)   return maxValue;
                
                return value;
            }
            
            template <typename T>
            inline T maximum(T val1, T val2)
            {
                if(val1 > val2) return val1;
                return val2;
            }
            
            template<typename T>
            inline T minimum(T val1, T val2)
            {
                if(val1 < val2) return val1;
                return val2;
            }

			template<typename T, typename FloatingPointScalar>
			inline T linear_interpolate(T a, T b, FloatingPointScalar t)
			{
				return a + ((b - a) * t);
			}
            
			template<typename T2>
			std::ostream &operator <<(std::ostream &os, const Vec2<T2> &v)
			{
				os << "(" << v.x << ", " << v.y << ")";
				return os;
			}

			template<typename T2>
			std::ostream &operator <<(std::ostream &os, const Vec3<T2> &v)
			{
				os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
				return os;
			}

			template<typename T2>
			std::ostream &operator <<(std::ostream &os, const Vec4<T2> &v)
			{
				os << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
				return os;
			}

			template<typename T2>
			std::ostream &operator <<(std::ostream &os, const Mat2<T2> &m)
			{
				os << m[0] << " " << m[1] << "\n"
					<< m[2] << " " << m[3];
				return os;
			}

			template <typename T2>
			std::ostream &operator <<(std::ostream &os, const Mat3<T2> &m)
			{
				os << m[0] << " " << m[1] << " " << m[2] << "\n"
					<< m[3] << " " << m[4] << " " << m[5] << "\n"
					<< m[6] << " " << m[7] << " " << m[8];
				return os;
			}

			template<typename T2>
			std::ostream &operator <<(std::ostream &os, const Mat4<T2> &m)
			{
				os << m[0] << " " << m[1] << " " << m[2] << " " << m[3] << "\n"
					<< m[4] << " " << m[5] << " " << m[6] << " " << m[7] << "\n"
					<< m[8] << " " << m[9] << " " << m[10] << " " << m[11] << "\n"
					<< m[12] << " " << m[13] << " " << m[14] << " " << m[15] << "\n";

				return os;
			}
		} // namespace utility
	}   // Namespace math
}   // Namespace knu

#endif