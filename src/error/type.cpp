#include "error/type.hpp"



namespace gm::error
{
	std::string getStringVersionOfType(gm::error::Type type) noexcept
	{
		switch (type)
		{
			case gm::error::Type::SDL:
				return "SDL";

			case gm::error::Type::OPENGL:
				return "OPENGL";

			case gm::error::Type::GAME:
				return "GAME";

			case gm::error::Type::STANDARD:
				return "STANDARD";

			default:
				return "INVALID";
		}
	}



	std::ostream &operator<<(std::ostream &stream, gm::error::Type type) noexcept
	{
		stream << gm::error::getStringVersionOfType(type);
		return stream;
	}
}