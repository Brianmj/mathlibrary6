#ifndef KNU_MATHLIBRARY6_HPP
#define KNU_MATHLIBRARY6_HPP

#include <array>
#include <iostream>

namespace knu {
	namespace math {
		inline namespace v1 {

			template<typename T>
			const T KNU_EPSILON = static_cast<T>(0.000001);

			struct vector_component_2 {};
			struct vector_component_3 {};
			struct vector_component_4 {};

			// matrix size constants
			const int MAT_2_2 = 4;
			const int MAT_3_3 = 9;
			const int MAT_4_4 = 16;

			template<typename T>
			struct vec2
			{
			public:

				using value_type = T;
				using component_count = vector_component_2;

				// Default constructor
				vec2()
					:
					x(static_cast<T>(0)),
					y(static_cast<T>(0))
				{}

				vec2(T ptr[2])
					:
					x(ptr[0]),
					y(ptr[1])
				{}

				vec2(T x_, T y_)
					:
					x(x_),
					y(y_)
				{}

				// Copy constructor
				vec2(const vec2 &v)
					:
					x(v.x),
					y(v.y)
				{}
				
				// move constructor
				vec2(vec2 &&v) :
					x(v.x),
					y(v.y)
				{
					std::cout << "rvalue reference called\n";
				}

				vec2 &operator =(const vec2 &v)
				{
					x = v.x;
					y = v.y;

					return (*this);
				}

				vec2 &operator =(vec2 &&v)
				{
					x = v.x;
					y = v.y;

					v.x = static_cast<T>(0);
					v.y = static_cast<T>(0);

					std::cout << "move assignment operator called\n";

					return (*this);
				}

				bool operator ==(const vec2 &v) const
				{
					return ((abs(x - v.x) <= KNU_EPSILON<T>) &&
						(abs(y - v.y) <= KNU_EPSILON<T>));
				}

				vec2 operator +(const vec2 &v) const
				{
					return (vec2(x + v.x, y + v.y));

				}

				vec2 &operator +=(const vec2 &v)
				{
					x += v.x;
					y += v.y;

					return (*this);
				}

				vec2<T> operator -(const vec2 &v)const
				{
					return (vec2(x - v.x, y - v.y));
				}

				vec2<T> &operator -=(const vec2 &v)
				{
					x -= v.x;
					y -= v.y;

					return (*this);
				}


				vec2 operator *(T scalar)const
				{
					return (vec2(x * scalar, y * scalar));
				}

				vec2 &operator *=(T scalar)
				{
					x *= scalar;
					y *= scalar;

					return (*this);
				}

				vec2 operator /(T scalar)const
				{
					return (vec2<T>(x / scalar, y / scalar));
				}

				vec2 &operator /=(T scalar)
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

				vec2& normalize()
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
					if (((x - static_cast<T>(0)) < KNU_EPSILON<T>) && 
						((y - static_cast<T>(0)) < KNU_EPSILON<T>))
						return (true);

					return (false);
				}

				T dot(const vec2 &v)const
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
			class vec3 {
			public:

				using value_type = T;
				using component_count = vector_component_3;

				// Default constructor
				vec3()
					:
					x(static_cast<T>(0)),
					y(static_cast<T>(0)),
					z(static_cast<T>(0))
				{}

				vec3<T>(T x_, T y_, T z_)
					:
					x(x_),
					y(y_),
					z(z_)
				{}

				// Destructor
				~vec3() {}

				// Copy constructor
				vec3<T>(const vec3 &v)
					:
					x(v.x),
					y(v.y),
					z(v.z)
				{}

				// move constructor
				vec3(vec3 &&v) :
					x(v.x),
					y(v.y),
					z(v.z)
				{
					v.x = static_cast<T>(0);
					v.y = static_cast<T>(0);
					v.z = static_cast<T>(0);
					std::cout << "rvalue reference called\n";
				}

				vec3<T> operator -()const
				{
					return vec3<T>(-x, -y, -z);
				}

				vec3<T> &operator =(const vec3 &v)
				{
					x = v.x;
					y = v.y;
					z = v.z;

					return (*this);
				}

				vec3 &operator =(const vec3 &&v)
				{
					x = v.x;
					y = v.y;
					z = v.z;

					std::cout << "V3f move assignment operator called\n";
					return (*this);
				}

				const vec3 operator +(const vec3 &v)const
				{
					return (vec3(x + v.x, y + v.y, z + v.z));
				}

	
				vec3& operator +=(const vec3 &v)
				{
					x += v.x;
					y += v.y;
					z += v.z;

					return (*this);
				}

	
				const vec3 operator -(const vec3 &v)const
				{
					return (vec3(x - v.x, y - v.y, z - v.z));
				}

				vec3 &operator -=(const vec3 &v)
				{
					x -= v.x;
					y -= v.y;
					z -= v.z;

					return (*this);
				}

				const vec3 operator *(T scalar)const
				{
					return (vec3(x * scalar, y * scalar, z * scalar));
				}

				vec3& operator *=(T scalar)
				{
					x *= scalar;
					y *= scalar;
					z *= scalar;

					return (*this);
				}

				const vec3 operator /(T scalar)const
				{
					return (vec3(x / scalar, y / scalar, z / scalar));
				}

				vec3& operator /=(T scalar)
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

				vec3& normalize()
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
					if (((x - static_cast<T>(0)) < KNU_EPSILON<T>) &&
						((y - static_cast<T>(0)) < KNU_EPSILON<T>) &&
						((z - static_cast<T>(0)) < KNU_EPSILON<T>))
						return (true);

					return (false);
				}

				T dot(const vec3 &v)const
				{
					return ((x * v.x) + (y * v.y) + (z * v.z));
				}

				vec3<T> cross(const vec3 &v)const
				{
					return (vec3(((y * v.z) - (z * v.y)), ((z * v.x) - (x * v.z)), ((x * v.y) - (y * v.x))));
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

				vec2<T> get_vec2() const
				{
					return vec2<T>(x, y);
				}

				T x, y, z;

			};			// Class Vec3

			template<typename T>
			class vec4 {
			public:

				using value_type = T;
				using component_count = vector_component_4;

				// Default constructor
				vec4<T>()
					:
					x(static_cast<T>(0)),
					y(static_cast<T>(0)),
					z(static_cast<T>(0)),
					w(static_cast<T>(1))
				{}

				vec4(T x_, T y_, T z_, T w_)
					:
					x(x_),
					y(y_),
					z(z_),
					w(w_)
				{}

				vec4<T>(const vec3<T> &v, T w_)
					:
					x(v.x),
					y(v.y),
					z(v.z),
					w(w_)
				{}

				// Copy constructor
				vec4<T>(const vec4<T> &v)
					:
					x(v.x),
					y(v.y),
					z(v.z),
					w(v.w)
				{}

				// move constructor
				vec4(vec4 &&v) :
					x(v.x),
					y(v.y),
					z(v.z),
					w(v.w)
				{
					v.x = static_cast<T>(0);
					v.y = static_cast<T>(0);
					v.z = static_cast<T>(0);
					v.w = static_cast<T>(0);
					std::cout << "rvalue reference called for v4\n";
				}

				vec4<T> operator -()const
				{
					return vec4(-x, -y, -z, -w);
				}

				vec4& operator =(const vec4 &v)
				{
					x = v.x;
					y = v.y;
					z = v.z;
					w = v.w;

					return (*this);
				}

				vec4 &operator =(const vec4 &&v)
				{
					x = v.x;
					y = v.y;
					z = v.z;
					w = v.w;

					std::cout << "V4f move assignment operator called\n";
					return (*this);
				}


				vec4 operator +(const vec4 &v)const
				{
					return (vec4(x + v.x, y + v.y, z + v.z, w + v.w));
				}

				vec4& operator +=(const vec4 &v)
				{
					x += v.x;
					y += v.y;
					z += v.z;
					w += v.w;

					return (*this);
				}

				vec4 operator -(const vec4 &v)const
				{
					return (vec4(x - v.x, y - v.y, z - v.z, w - v.w));
				}

				vec4& operator -=(const vec4 &v)
				{
					x -= v.x;
					y -= v.y;
					z -= v.z;
					w -= v.w;

					return (*this);
				}

				vec4 operator *(T scalar)const
				{
					return (vec4(x * scalar, y * scalar, z * scalar, w * scalar));
				}

				vec4& operator *=(T scalar)
				{
					x *= scalar;
					y *= scalar;
					z *= scalar;
					w *= scalar;

					return (*this);
				}

				vec4 operator /(T scalar)const
				{
					return (vec4(x / scalar, y / scalar, z / scalar, w / scalar));
				}

				vec4& operator /=(T scalar)
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

				vec4<T>& normalize()
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
					if (((x - static_cast<T>(0)) < KNU_EPSILON<T>) &&
						((y - static_cast<T>(0)) < KNU_EPSILON<T>) &&
						((z - static_cast<T>(0)) < KNU_EPSILON<T>) &&
						((w - static_cast<T>(0)) < KNU_EPSILON<T>))
						return (true);

					return (false);
				}

				template<typename T2>
				T dot(const vec4<T2> &v)const
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

				vec3<T> get_vec3() const
				{
					return vec3<T>(x, y, z);
				}

				T x, y, z, w;
			};

			template<typename T>
			struct  mat2
			{
				using value_type = T;

				mat2<T>() :
					elements()
				{
					set_identity();
				}

				// column major
				mat2(T a, T b, T c, T d) :
					elements()
				{
					elements[0] = a;
					elements[1] = b;
					elements[2] = c;
					elements[3] = d;
				}

				mat2(const mat2 &m) :
					elements()
				{
					std::copy(std::begin(m.elements), std::end(m.elements),
						std::begin(elements));
				}

				mat2 &operator=(const mat2 &m)
				{
					std::copy(std::begin(m.elements), std::end(m.elements),
						std::begin(elements));
					return *this;
				}

				bool operator==(const mat2 &m) const
				{
					bool are_equal = std::equal(std::begin(elements), std::end(elements),
						std::begin(m.elements),
						[](auto e1, auto e2) -> bool {
						return abs(e1 - e2) <= KNU_EPSILON<T>;
					});

					return are_equal;
				}

				// column major
				T &operator [](int i)
				{
					return elements[i];
				}

				T operator [](int i)const
				{
					return elements[i];
				}

				vec2<T> get_row_0()const
				{
					return vec2<T>(elements[0], elements[2]);
				}

				vec2<T> get_row_1()const
				{
					return vec2<T>(elements[1], elements[3]);
				}

				void set_row_0(T a, T b)
				{
					elements[0] = a;
					elements[2] = b;
				}

				void set_row_0(const vec2<T> &v)
				{
					set_row_0(v.x, v.y);
				}

				void set_row_1(T a, T b)
				{
					elements[1] = a;
					elements[3] = b;
				}

				void set_row_1(const vec2<T> &v)
				{
					set_row_1(v.x, v.y);
				}

				vec2<T> get_column_0()const
				{
					return vec2<T>(elements[0], elements[1]);
				}

				vec2<T> get_column_1()const
				{
					return vec2<T>(elements[2], elements[3]);
				}

				void set_column_0(T a, T b)
				{
					elements[0] = a;
					elements[1] = b;
				}

				void set_column_0(const vec2<T> &v)
				{
					set_column_0(v.x, v.y);
				}

				void set_column_1(T a, T b)
				{
					elements[2] = a;
					elements[3] = b;
				}

				void set_column_1(const vec2<T> &v)
				{
					set_column_1(v.x, v.y);
				}

				mat2 &set_identity()
				{
					set_row_0(1, 0);
					set_row_1(0, 1);
					return *this;
				}

				mat2 &zero()
				{
					std::fill(std::begin(elements), std::end(elements),
						static_cast<T>(0));
					return *this;
				}

				mat2 operator+(const mat2 &m)const
				{
					return mat2(elements[0] + m.elements[0],
						elements[1] + m.elements[1],
						elements[2] + m.elements[2],
						elements[3] + m.elements[3]);
				}

				mat2 &operator+=(const mat2 &m)
				{
					*this = *this + m;
					return *this;
				}

				mat2 operator-(const mat2 &m)const
				{
					return mat2(elements[0] - m.elements[0],
						elements[1] - m.elements[1],
						elements[2] - m.elements[2],
						elements[3] - m.elements[3]);
				}

				mat2 &operator-=(const mat2 &m)
				{
					*this = *this - m;
					return *this;
				}

				mat2 operator*(const mat2 &m)const
				{
					mat2 ret;
					ret[0] = get_row_0().dot(m.get_column_0());
					ret[2] = get_row_0().dot(m.get_column_1());

					ret[1] = get_row_1().dot(m.get_column_0());
					ret[3] = get_row_1().dot(m.get_column_1());
					return ret;
				}

				mat2 &scale(T x, T y)
				{
					set_row_0(x, 0);
					set_row_1(0, y);
					return *this;
				}
				mat2 &transpose()
				{
					auto row0 = get_row_0();
					auto row1 = get_row_1();
					set_column_0(row0);
					set_column_1(row1);

					return *this;
				}

				mat2 &rotation(T radians)
				{
					T c = cos(radians);
					T s = sin(radians);

					set_row_0(c, -s);
					set_row_1(s, c);
					return *this;
				}

				T* data()
				{
					return &elements[0];
				}

				std::array<T, MAT_2_2> elements;
			};	// Mat2



		} // namespace of v1

		using vector2f = vec2<float>;
		using vector2d = vec2<double>;
		using vector2i = vec2<std::uint32_t>;
		using vector2l = vec2<std::uint64_t>;

		using vector3f = vec3<float>;
		using vector3d = vec3<double>;
		using vector3i = vec3<std::uint32_t>;
		using vector3l = vec3<std::uint64_t>;

		using vector4f = vec4<float>;
		using vector4d = vec4<double>;
		using vector4i = vec4<std::uint32_t>;
		using vector4l = vec4<std::uint64_t>;

		using matrix2f = mat2<float>;
		using matrix2d = mat2<double>;
		using matrix2i = mat2<int>;
		using matrix2l = mat2<long>;

	} // namespace math
} // namespace knu

template<typename T2>
std::ostream &operator <<(std::ostream &os, const knu::math::vec2<T2> &v)
{
	os << "(" << v.x << ", " << v.y << ")";
	return os;
}

template<typename T2>
std::wostream &operator <<(std::wostream &wos, const knu::math::vec2<T2> &v)
{
	wos << "(" << v.x << ", " << v.y << ")";
	return wos;
}

template<typename T2>
std::ostream &operator <<(std::ostream &os, const knu::math::mat2<T2> &m)
{
	os << m[0] << " " << m[2] << "\n"
		<< m[1] << " " << m[3];
	return os;
}

template<typename T2>
std::wostream &operator <<(std::wostream &wos, const knu::math::mat2<T2> &m)
{
	wos << m[0] << " " << m[2] << "\n"
		<< m[1] << " " << m[3];
	return wos;
}


#endif // KNU_MATHLIBRARY6_HPP