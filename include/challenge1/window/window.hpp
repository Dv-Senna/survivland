#pragma once

#include <cinttypes>

#include <string>

#include <glm/glm.hpp>
#include <SDL2/SDL.h>

#include "id.hpp"


namespace gm::window
{
	constexpr int CENTERED_POSTION {SDL_WINDOWPOS_CENTERED};
	constexpr glm::ivec2 DEFAULT_WINDOW_SIZE {16 * 70, 9 * 70};


	class Window
	{
		public:
			Window();
			Window(std::string title);
			Window(std::string title, glm::ivec2 size);
			Window(std::string title, glm::ivec2 pos, glm::ivec2 size, bool load = true);
			virtual ~Window();

			Window(const gm::window::Window &window);
			const gm::window::Window &operator=(const gm::window::Window &window);

			Window(gm::window::Window &&window) noexcept;
			const gm::window::Window &operator=(gm::window::Window &&window) noexcept;


			inline void close();

			inline void setTitle(std::string title);
			inline void setPosition(glm::ivec2 pos);
			inline void setSize(glm::ivec2 size);

			inline SDL_Window *getInternalObject() const noexcept;
			inline gm::window::ID getID() const noexcept;
			inline const std::string &getTitle() const noexcept;
			inline glm::ivec2 getPosition() const noexcept;
			inline glm::ivec2 getSize() const noexcept;
			inline bool isOpen() const noexcept;


		protected:
			virtual void m_load(uint32_t sdlFlags = SDL_WINDOW_SHOWN);
			virtual void m_unload();

			SDL_Window *m_window;
			gm::window::ID m_id;
			std::string m_title;
			glm::ivec2 m_pos, m_size;
			bool m_isOpen;
	};
}


#include "window.inl"