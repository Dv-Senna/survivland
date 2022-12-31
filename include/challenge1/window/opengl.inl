// only so vs code is happy
#include "opengl.hpp"



namespace gm::window
{
	SDL_GLContext OpenGL::getOpenGLContext() const noexcept
	{
		return m_context;
	}
}