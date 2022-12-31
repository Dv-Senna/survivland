#include <cassert>

#include <glm/glm.hpp>
#include <SDL2/SDL.h>

#include "event/manager.hpp"




namespace gm::event
{
	std::vector<gm::event::KeyEvent> Manager::s_keys {};
	std::vector<gm::event::MouseButtonEvent> Manager::s_mouseButtons {};
	gm::event::MouseMotionEvent Manager::s_mouseMotion {{0, 0}, {0, 0}};
	std::vector<gm::event::WindowEvent> Manager::s_windows {};
	std::map<gm::window::ID, gm::event::Manager::WindowCallback> Manager::s_windowCallbacks {};



	void Manager::update()
	{
		static SDL_Event event {};

		s_resetWindowEvent();
		s_resetMouseMotion();



		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_KEYDOWN:
				{
					auto &key = s_getKey(static_cast<gm::event::Key> (event.key.keysym.scancode));
					key.isDown = true;
					key.windowID = event.key.windowID;
					break;
				}

				case SDL_KEYUP:
				{
					auto &key = s_getKey(static_cast<gm::event::Key> (event.key.keysym.scancode));
					key.isDown = false;
					key.windowID = event.key.windowID;
					break;
				}

				case SDL_MOUSEBUTTONDOWN:
				{
					auto &button = s_getMouseButton(static_cast<gm::event::MouseButton> (event.button.button));
					button.isDown = true;
					button.repetitions = event.button.clicks;
					button.windowID = event.button.windowID;
					break;
				}

				case SDL_MOUSEBUTTONUP:
				{
					auto &button = s_getMouseButton(static_cast<gm::event::MouseButton> (event.button.button));
					button.isDown = false;
					button.repetitions = event.button.clicks;
					button.windowID = event.button.windowID;
					break;
				}

				case SDL_MOUSEMOTION:
				{
					s_mouseMotion.pos = {event.motion.x, event.motion.y};
					s_mouseMotion.rel = {event.motion.xrel, event.motion.yrel};
					s_mouseMotion.windowID = event.motion.windowID;
					break;
				}

				case SDL_WINDOWEVENT:
				{
					auto &windowEvent = s_getWindowEvent(static_cast<gm::event::Window> (event.window.event));
					windowEvent.happenedInLastFrame = true;
					windowEvent.relData = glm::ivec2(event.window.data1, event.window.data2) - windowEvent.newData;
					windowEvent.newData = glm::ivec2(event.window.data1, event.window.data2);
					windowEvent.windowID = event.window.windowID;

					s_callWindowsCallbacks(windowEvent);

					break;
				}
			}
		}
	}



	void Manager::subscribeWindow(gm::window::ID window, gm::event::Manager::WindowCallback callback)
	{
		s_windowCallbacks[window] = callback;
	}



	void Manager::unsubscribeWindow(gm::window::ID window)
	{
		auto it {s_windowCallbacks.find(window)};

		assert(!(it == s_windowCallbacks.end() && "You shouldn't erase a window's subscription of an unsubscribed window"));

		if (it != s_windowCallbacks.end())
			s_windowCallbacks.erase(it);
	}



	gm::event::KeyEvent &Manager::s_getKey(gm::event::Key key)
	{
		int i {0};
		bool hadFound {false};

		for (auto it {s_keys.begin()}; it != s_keys.end(); ++it)
		{
			if (it->key == key)
			{
				hadFound = true;
				break;
			}

			i++;
		}


		if (hadFound)
			return s_keys[i];

		s_keys.push_back(gm::event::KeyEvent::create(key));

		return *(s_keys.end() - 1);
	}



	gm::event::MouseButtonEvent &Manager::s_getMouseButton(gm::event::MouseButton mouseButton)
	{
		int i {0};
		bool hadFound {false};

		for (auto it {s_mouseButtons.begin()}; it != s_mouseButtons.end(); ++it)
		{
			if (it->button == mouseButton)
			{
				hadFound = true;
				break;
			}

			i++;
		}


		if (hadFound)
			return s_mouseButtons[i];

		s_mouseButtons.push_back(gm::event::MouseButtonEvent::create(mouseButton));

		return *(s_mouseButtons.end() - 1);
	}



	gm::event::WindowEvent &Manager::s_getWindowEvent(gm::event::Window type)
	{
		int i {0};
		bool hadFound {false};

		for (auto it {s_windows.begin()}; it != s_windows.end(); ++it)
		{
			if (it->type == type)
			{
				hadFound = true;
				break;
			}

			i++;
		}


		if (hadFound)
			return s_windows[i];

		s_windows.push_back(gm::event::WindowEvent::create(type));

		return *(s_windows.end() - 1);
	}



	void Manager::s_resetWindowEvent()
	{
		gm::event::WindowEvent moved {getWindowEvent(gm::event::Window::wmoved)};
		gm::event::WindowEvent resized {getWindowEvent(gm::event::Window::wresized)};

		s_windows = {
			{gm::event::WindowEvent::create(gm::event::Window::wminimized)},
			{gm::event::WindowEvent::create(gm::event::Window::wmaximized)},
			{gm::event::Window::wmoved, moved.newData, {0, 0}, false},
			{gm::event::WindowEvent::create(gm::event::Window::wquit)},
			{gm::event::Window::wresized, resized.newData, {0, 0}, false}
		};
	}



	void Manager::s_resetMouseMotion()
	{
		s_mouseMotion.rel = {0, 0};
		s_mouseMotion.windowID = 0;
	}



	void Manager::s_callWindowsCallbacks(gm::event::WindowEvent event)
	{
		for (auto it {s_windowCallbacks.begin()}; it != s_windowCallbacks.end(); ++it)
		{
			it->second.operator()(event);
		}
	}
}