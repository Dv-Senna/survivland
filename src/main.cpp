//#include <SDL2/SDL.h>
#include <exception>
#include <cstdlib>

#include <SDL2/SDL.h>

#include "application.hpp"
#include "error/exception.hpp"


int main(int argc, char *argv[])
{
	gm::Application application {};

	try
	{
		application.load();
		application.run();
	}

	catch (const gm::error::Game &game)
	{
		application.handleError({gm::error::Type::GAME, game.getCode(), game.getMessage()});
		return EXIT_FAILURE;
	}

	catch (const gm::error::SDL &sdl)
	{
		application.handleError({gm::error::Type::SDL, sdl.getCode(), sdl.getMessage()});
		return EXIT_FAILURE;
	}

	catch (const gm::error::OpenGL &opengl)
	{
		application.handleError({gm::error::Type::OPENGL, opengl.getCode(), opengl.getMessage()});
		return EXIT_FAILURE;
	}

	catch (const std::exception &exception)
	{
		application.handleError({gm::error::Type::STANDARD, -1, exception.what()});
		return EXIT_FAILURE;
	}

	application.unload();

	return EXIT_SUCCESS;
}