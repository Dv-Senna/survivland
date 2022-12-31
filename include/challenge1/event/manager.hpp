#pragma once

#include <functional>
#include <map>
#include <vector>

#include "keyboard.hpp"
#include "mouse.hpp"
#include "window.hpp"
#include "window/window.hpp"


namespace gm::event
{
	class Manager
	{
		friend class ::gm::window::Window;

		using WindowCallback = std::function<void (gm::event::WindowEvent)>;

		public:
			static void update();

			inline static gm::event::KeyEvent getKey(gm::event::Key key);
			inline static gm::event::MouseButtonEvent getMouseButton(gm::event::MouseButton mouseButton);
			inline static gm::event::WindowEvent getWindowEvent(gm::event::Window type);
			inline static gm::event::MouseMotionEvent getMouseMotion() noexcept;


		protected:
			static void subscribeWindow(gm::window::ID window, gm::event::Manager::WindowCallback callback);
			static void unsubscribeWindow(gm::window::ID window);


		private:
			static std::vector<gm::event::KeyEvent> s_keys;
			static std::vector<gm::event::MouseButtonEvent> s_mouseButtons;
			static gm::event::MouseMotionEvent s_mouseMotion;
			static std::vector<gm::event::WindowEvent> s_windows;
			static std::map<gm::window::ID, gm::event::Manager::WindowCallback> s_windowCallbacks;

			static gm::event::KeyEvent &s_getKey(gm::event::Key key);
			static gm::event::MouseButtonEvent &s_getMouseButton(gm::event::MouseButton mouseButton);
			static gm::event::WindowEvent &s_getWindowEvent(gm::event::Window type);
			static void s_resetWindowEvent();
			static void s_resetMouseMotion();
			static void s_callWindowsCallbacks(gm::event::WindowEvent event);

			Manager();
			~Manager();
	};
}


#include "manager.inl"