// only so vs code is happy
#include "window.hpp"



namespace gm::window
{
	void Window::close()
	{
		m_isOpen = false;
	}



	void Window::setTitle(std::string title)
	{
		m_title = std::move(title);
		SDL_SetWindowTitle(m_window, m_title.c_str());
	}



	void Window::setPosition(glm::ivec2 pos)
	{
		m_pos = pos;
		SDL_SetWindowPosition(m_window, m_pos.x, m_pos.y);
	}



	void Window::setSize(glm::ivec2 size)
	{
		m_size = size;
		SDL_SetWindowSize(m_window, m_size.x, m_size.y);
	}



	SDL_Window *Window::getInternalObject() const noexcept
	{
		return m_window;
	}



	gm::window::ID Window::getID() const noexcept
	{
		return m_id;
	}



	const std::string &Window::getTitle() const noexcept
	{
		return m_title;
	}



	glm::ivec2 Window::getPosition() const noexcept
	{
		return m_pos;
	}



	glm::ivec2 Window::getSize() const noexcept
	{
		return m_size;
	}



	bool Window::isOpen() const noexcept
	{
		return m_isOpen;
	}



}