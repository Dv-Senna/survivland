#include <iostream>

#include <SDL2/SDL.h>

#include "application.hpp"
#include "error/exception.hpp"
#include "event/manager.hpp"

#include "test/event.hpp"



namespace gm
{
	Application::Application() noexcept : 
		m_window {nullptr},
		m_window2 {nullptr}
	{
		std::cout << "Creation of application..." << std::endl;
	}



	void Application::load()
	{
		std::cout << "Loading of application..." << std::endl;

		if (SDL_Init(SDL_INIT_VIDEO) != 0)
			throw gm::error::SDL("Can't init SDL2");

		m_window = new gm::window::OpenGL(
			"Challenge#1",
			{gm::window::CENTERED_POSTION, gm::window::CENTERED_POSTION},
			gm::window::DEFAULT_WINDOW_SIZE,
			{4, 6}
		);
		m_window2 = new gm::window::Window("Challenge#2", {16 * 70, 9 * 70});

		std::cout << "Main window's id : " << m_window->getID() << std::endl;
		std::cout << "Window2's id : " << m_window2->getID() << std::endl;
	}



	void Application::run()
	{
		std::cout << "Application runs..." << std::endl;


		while (m_window->isOpen())
		{
			gm::event::Manager::update();

			//GM_TEST_DIRECT_EVENT_DATA_ACCESS

			SDL_GL_SwapWindow(m_window->getInternalObject());
		}
	}



	void Application::unload() noexcept
	{
		std::cout << "Unloading of application..." << std::endl;

		delete m_window2;
		delete m_window;
		SDL_Quit();
	}



	void Application::handleError(const gm::error::Data &error) noexcept
	{
		std::cerr << "EXCEPTION : " << error.type << "[" << error.code << "]" << error.what << std::endl;

		this->unload();
	}



}