#pragma once

#include "preambule.inl"


#ifdef GM_DEBUG

	#include "event/manager.hpp"
	#include "window/window.hpp"


	namespace gm::test
	{
		void directEventDataAccess();
		void windowCallbackEventAccess(gm::window::Window *window, gm::event::WindowEvent event);
	}

#endif


#ifdef GM_DEBUG
	#define GM_TEST_DIRECT_EVENT_DATA_ACCESS ::gm::test::directEventDataAccess();
	#define GM_TEST_WINDOW_CALLBACK_EVENT_ACCESS(window, event) ::gm::test::windowCallbackEventAccess(window, event)
#else
	#define GM_TEST_DIRECT_EVENT_DATA_ACCESS
	#define GM_TEST_WINDOW_CALLBACK_EVENT_ACCESS(window, event)
#endif