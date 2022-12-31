#include "error/exception.hpp"
#include "window/opengl.hpp"



namespace gm::window
{
	OpenGL::OpenGL() : 
		OpenGL(
			"",
			{gm::window::CENTERED_POSTION, gm::window::CENTERED_POSTION},
			gm::window::DEFAULT_WINDOW_SIZE,
			gm::window::DEFAULT_OPENGL_VERSION
		)
	{

	}



	OpenGL::OpenGL(std::string title) :
		OpenGL(
			std::move(title),
			{gm::window::CENTERED_POSTION, gm::window::CENTERED_POSTION},
			gm::window::DEFAULT_WINDOW_SIZE,
			gm::window::DEFAULT_OPENGL_VERSION
		)
	{

	}



	OpenGL::OpenGL(std::string title, glm::ivec2 size) :
		OpenGL(
			std::move(title),
			{gm::window::CENTERED_POSTION, gm::window::CENTERED_POSTION},
			size,
			gm::window::DEFAULT_OPENGL_VERSION
		)
	{

	}



	OpenGL::OpenGL(std::string title, glm::ivec2 pos, glm::ivec2 size) :
		OpenGL(
			std::move(title),
			pos,
			size,
			gm::window::DEFAULT_OPENGL_VERSION
		)
	{

	}



	OpenGL::OpenGL(std::string title, glm::ivec2 pos, glm::ivec2 size, glm::ivec2 version) :
		Window(std::move(title), pos, size, false),
		m_context {nullptr},
		m_version {version}
	{
		this->m_load();
	}



	OpenGL::~OpenGL()
	{
		this->m_unload();
	}



	void OpenGL::m_load()
	{
		Window::m_load(SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, m_version.x);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, m_version.y);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

		m_context = SDL_GL_CreateContext(m_window);
		if (m_context == nullptr)
			throw gm::error::SDL("Can't create an OpenGL context");
	}



	void OpenGL::m_unload()
	{
		SDL_GL_DeleteContext(m_context);
		Window::m_unload();
	}



}