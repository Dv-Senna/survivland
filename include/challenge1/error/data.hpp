#pragma once

#include <string_view>

#include "error/type.hpp"



namespace gm::error
{
	struct Data
	{
		gm::error::Type type;
		int code;
		std::string_view what;
	};
}