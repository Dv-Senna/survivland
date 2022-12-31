#pragma once

#include <ostream>
#include <string>


namespace gm::error
{
	enum class Type
	{
		SDL,
		OPENGL,
		GAME,
		STANDARD
	};


	std::string getStringVersionOfType(gm::error::Type type) noexcept;
	std::ostream &operator<<(std::ostream &stream, gm::error::Type type) noexcept;
}