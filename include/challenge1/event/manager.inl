// only so vs code is happy
#include "manager.hpp"



namespace gm::event
{
	gm::event::KeyEvent Manager::getKey(gm::event::Key key)
	{
		return s_getKey(key);
	}



	gm::event::MouseButtonEvent Manager::getMouseButton(gm::event::MouseButton mouseButton)
	{
		return s_getMouseButton(mouseButton);
	}



	gm::event::WindowEvent Manager::getWindowEvent(gm::event::Window type)
	{
		return s_getWindowEvent(type);
	}



	gm::event::MouseMotionEvent Manager::getMouseMotion() noexcept
	{
		return s_mouseMotion;
	}



}