#include <iostream>

#include "test/event.hpp"


#ifdef GM_DEBUG
	namespace gm::test
	{
		void directEventDataAccess()
		{
			if (gm::event::Manager::getKey(gm::event::Key::ka).isDown)
				std::cout << "A is down on" << gm::event::Manager::getKey(gm::event::Key::ka).windowID << std::endl;

			if (gm::event::Manager::getMouseButton(gm::event::MouseButton::bright).isDown)
				std::cout << "Right mouse button had been clicked " << gm::event::Manager::getMouseButton(gm::event::MouseButton::bright).repetitions << " times on" <<
				gm::event::Manager::getMouseButton(gm::event::MouseButton::bright).windowID << std::endl;

			if (gm::event::Manager::getMouseMotion().rel != glm::ivec2(0, 0))
			{
				std::cout << "The mouse is located at (" << 
					gm::event::Manager::getMouseMotion().pos.x << ", " <<
					gm::event::Manager::getMouseMotion().pos.y << ") and had moved (" <<
					gm::event::Manager::getMouseMotion().rel.x << ", " <<
					gm::event::Manager::getMouseMotion().rel.y << ") on" <<
					gm::event::Manager::getMouseMotion().windowID << std::endl;
			}

			if (gm::event::Manager::getWindowEvent(gm::event::Window::wmoved).happenedInLastFrame)
			{
				std::cout << "Window moved at (" << 
					gm::event::Manager::getWindowEvent(gm::event::Window::wmoved).newData.x << ", " <<
					gm::event::Manager::getWindowEvent(gm::event::Window::wmoved).newData.y << ") and had moved (" <<
					gm::event::Manager::getWindowEvent(gm::event::Window::wmoved).relData.x << ", " <<
					gm::event::Manager::getWindowEvent(gm::event::Window::wmoved).relData.y << ") on" <<
					gm::event::Manager::getWindowEvent(gm::event::Window::wmoved).windowID << std::endl;
			}
		}


		void windowCallbackEventAccess(gm::window::Window *window, gm::event::WindowEvent event)
		{
			switch (event.type)
			{
				case gm::event::Window::wmoved:
					std::cout << "Window " << window->getID() << " moves to (" <<
						window->getPosition().x << ", " << window->getPosition().y << ")" << std::endl;
					break;

				case gm::event::Window::wresized:
					std::cout << "Window " << window->getID() << " resizes to (" <<
						window->getSize().x << ", " << window->getSize().y << ")" << std::endl;
					break;

				case gm::event::Window::wmaximized:
					std::cout << "Window " << window->getID() << " maximizes to (" <<
						window->getPosition().x << ", " << window->getPosition().y << 
						") : (" << window->getSize().x << ", " << window->getSize().y << ")" << std::endl;
					break;

				case gm::event::Window::wminimized:
					std::cout << "Window " << window->getID() << " minimizes to (" <<
						window->getPosition().x << ", " << window->getPosition().y << 
						") : (" << window->getSize().x << ", " << window->getSize().y << ")" << std::endl;
					break;

				case gm::event::Window::wquit:
					std::cout << "Window " << window->getID() << " quits" << std::endl;
					break;
			}
		}
	}
#endif