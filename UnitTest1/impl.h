#pragma once

#include "mathlibrary6.hpp"
#include <CppUnitTestAssert.h>

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template<> static std::wstring ToString<knu::math::vec2<int>>(const knu::math::vec2<int>& t) { RETURN_WIDE_STRING(t); }
			template<> static std::wstring ToString<knu::math::vec2<float>>(const knu::math::vec2<float>& t) { RETURN_WIDE_STRING(t); }
			template<> static std::wstring ToString<knu::math::vec3<std::int32_t>>(const knu::math::vec3<int>& t) { RETURN_WIDE_STRING(t); }
			template<> static std::wstring ToString<knu::math::vec3<float>>(const knu::math::vec3<float>& t) { RETURN_WIDE_STRING(t); }
			template<> static std::wstring ToString<knu::math::vec4<std::int32_t>>(const knu::math::vec4<int>& t) { RETURN_WIDE_STRING(t); }
			template<> static std::wstring ToString<knu::math::vec4<float>>(const knu::math::vec4<float>& t) { RETURN_WIDE_STRING(t); }
			template<> static std::wstring ToString<knu::math::mat2<int>>(const knu::math::mat2<int>& t) { RETURN_WIDE_STRING(t); }
			template<> static std::wstring ToString<knu::math::mat2<float>>(const knu::math::mat2<float>& t) { RETURN_WIDE_STRING(t); }
			template<> static std::wstring ToString<knu::math::mat3<int>>(const knu::math::mat3<int>& t) { RETURN_WIDE_STRING(t); }
			template<> static std::wstring ToString<knu::math::mat3<float>>(const knu::math::mat3<float>& t) { RETURN_WIDE_STRING(t); }
			template<> static std::wstring ToString<knu::math::mat4<int>>(const knu::math::mat4<int>& t) { RETURN_WIDE_STRING(t); }
			template<> static std::wstring ToString<knu::math::mat4<float>>(const knu::math::mat4<float>& t) { RETURN_WIDE_STRING(t); }
		}
	}
}