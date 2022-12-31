#pragma once

#include <SDL2/SDL.h>

#include "error/data.hpp"
#include "window/opengl.hpp"
#include "window/window.hpp"


namespace gm
{
	class Application
	{
		public:
			Application() noexcept;
			~Application() noexcept = default;
			void load();
			void run();
			void unload() noexcept;
			void handleError(const gm::error::Data &error) noexcept;

		private:
			gm::window::OpenGL *m_window;
			gm::window::Window *m_window2;
	};
}