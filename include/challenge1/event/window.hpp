#pragma once

#include <glm/glm.hpp>
#include <SDL2/SDL.h>

#include "window/id.hpp"


namespace gm::event
{
	enum class Window
	{
		wminimized = SDL_WINDOWEVENT_MINIMIZED,
		wmaximized = SDL_WINDOWEVENT_MAXIMIZED,
		wmoved = SDL_WINDOWEVENT_MOVED,
		wresized = SDL_WINDOWEVENT_RESIZED,
		wquit = SDL_WINDOWEVENT_CLOSE,

		wundefined
	};



	struct WindowEvent
	{
		gm::event::Window type;
		glm::ivec2 newData;
		glm::ivec2 relData;
		bool happenedInLastFrame;
		gm::window::ID windowID;


		inline static gm::event::WindowEvent create(gm::event::Window type) noexcept
		{
			return {type, {0, 0}, {0, 0}, false, 0};
		}
	};
}