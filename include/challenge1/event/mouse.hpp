#pragma once

#include <glm/glm.hpp>
#include <SDL2/SDL.h>

#include "window/id.hpp"


namespace gm::event
{
	enum class MouseButton
	{
		bright = SDL_BUTTON_RIGHT,
		bmiddle = SDL_BUTTON_MIDDLE,
		bleft = SDL_BUTTON_LEFT,
		b1 = SDL_BUTTON_X1,
		b2 = SDL_BUTTON_X2,

		bundefined
	};


	struct MouseButtonEvent
	{
		gm::event::MouseButton button;
		bool isDown;
		int repetitions;
		gm::window::ID windowID;

		inline static gm::event::MouseButtonEvent create(gm::event::MouseButton button) noexcept
		{
			return {button, false, 0, 0};
		}
	};


	struct MouseMotionEvent
	{
		glm::ivec2 pos, rel;
		gm::window::ID windowID;
	};
}