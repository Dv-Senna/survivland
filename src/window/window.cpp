#include <SDL2/SDL.h>

#include "error/exception.hpp"
#include "event/manager.hpp"
#include "window/window.hpp"

#include "test/event.hpp"



namespace gm::window
{
	Window::Window() :
		Window("", {
			gm::window::CENTERED_POSTION, gm::window::CENTERED_POSTION},
			gm::window::DEFAULT_WINDOW_SIZE
		)
	{

	}



	Window::Window(std::string title) : 
		Window(std::move(title), {
			gm::window::CENTERED_POSTION, gm::window::CENTERED_POSTION},
			gm::window::DEFAULT_WINDOW_SIZE
		)
	{

	}



	Window::Window(std::string title, glm::ivec2 size) : 
		Window(std::move(title), {
			gm::window::CENTERED_POSTION, gm::window::CENTERED_POSTION},
			size
		)
	{

	}



	Window::Window(std::string title, glm::ivec2 pos, glm::ivec2 size, bool load) :
		m_window {nullptr},
		m_id {},
		m_title {std::move(title)},
		m_pos {pos},
		m_size {size},
		m_isOpen {true}
	{
		if (load)
			this->m_load();
	}



	Window::~Window()
	{
		this->m_unload();
	}



	Window::Window(const gm::window::Window &window) : 
		m_window {nullptr},
		m_id {},
		m_title {window.m_title},
		m_pos {window.m_pos},
		m_size {window.m_size},
		m_isOpen {true}
	{
		this->m_load();
	}



	const gm::window::Window &Window::operator=(const gm::window::Window &window)
	{
		this->m_unload();

		m_window = nullptr;
		m_id = 0;
		m_title = window.m_title;
		m_pos = window.m_pos;
		m_size = window.m_size;
		m_isOpen = true;

		this->m_load();

		return *this;
	}



	Window::Window(gm::window::Window &&window) noexcept :
		m_window {window.m_window},
		m_id {window.m_id},
		m_title {std::move(window.m_title)},
		m_pos {std::move(window.m_pos)},
		m_size {std::move(window.m_size)},
		m_isOpen {window.m_isOpen}
	{
		window.m_window = nullptr;
		window.m_id = 0;
		window.m_isOpen = false;
	}



	const gm::window::Window &Window::operator=(gm::window::Window &&window) noexcept
	{
		this->m_unload();

		m_window = window.m_window;
		m_id = window.m_id;
		m_title = std::move(window.m_title);
		m_pos = std::move(window.m_pos);
		m_size = std::move(window.m_size);
		m_isOpen = window.m_isOpen;

		window.m_window = nullptr;
		window.m_id = 0;
		window.m_isOpen = false;

		return *this;
	}



	void Window::m_load(uint32_t sdlFlags)
	{
		m_window = SDL_CreateWindow(m_title.c_str(), m_pos.x, m_pos.y, m_size.x, m_size.y, sdlFlags);
		if (m_window == nullptr)
			throw gm::error::SDL("Can't create an SDL2 window");

		m_isOpen = true;
		SDL_GetWindowPosition(m_window, &m_pos.x, &m_pos.y);
		m_id = SDL_GetWindowID(m_window);

		gm::event::Manager::subscribeWindow(m_id, [this](gm::event::WindowEvent event)
		{
			if (event.windowID != this->m_id)
				return;

			switch (event.type)
			{
				case gm::event::Window::wmoved:
					this->m_pos = {event.newData.x, event.newData.y};
					break;

				case gm::event::Window::wresized:
					this->m_size = {event.newData.x, event.newData.y};
					break;

				case gm::event::Window::wmaximized:
					SDL_GetWindowSize(this->m_window, &this->m_size.x, &this->m_size.y);
					SDL_GetWindowPosition(this->m_window, &this->m_pos.x, &this->m_pos.y);
					break;

				case gm::event::Window::wminimized:
					SDL_GetWindowSize(this->m_window, &this->m_size.x, &this->m_size.y);
					SDL_GetWindowPosition(this->m_window, &this->m_pos.x, &this->m_pos.y);
					break;

				case gm::event::Window::wquit:
					this->m_unload();
					break;

				default:
					break;
			}

			//GM_TEST_WINDOW_CALLBACK_EVENT_ACCESS(this, event);
		});
	}



	void Window::m_unload()
	{
		m_isOpen = false;

		if (m_window != nullptr)
			SDL_DestroyWindow(m_window);

		if (m_id != 0)
			gm::event::Manager::unsubscribeWindow(m_id);

		m_id = 0;
	}



}