#pragma once

#include <string>

#include <glm/glm.hpp>
#include <SDL2/SDL.h>

#include "window.hpp"


namespace gm::window
{
	constexpr glm::ivec2 DEFAULT_OPENGL_VERSION {3, 3};

	class OpenGL : public Window
	{
		public:
			OpenGL();
			OpenGL(std::string title);
			OpenGL(std::string title, glm::ivec2 size);
			OpenGL(std::string title, glm::ivec2 pos, glm::ivec2 size);
			OpenGL(std::string title, glm::ivec2 pos, glm::ivec2 size, glm::ivec2 version);
			virtual ~OpenGL();

			OpenGL(const gm::window::OpenGL &openGL) = delete;
			const gm::window::OpenGL &operator=(const gm::window::OpenGL &openGL) = delete;

			OpenGL(gm::window::OpenGL &&openGL) noexcept = delete;
			const gm::window::OpenGL &operator=(gm::window::OpenGL &&openGL) noexcept = delete;


			inline SDL_GLContext getOpenGLContext() const noexcept;


		private:
			virtual void m_load();
			virtual void m_unload();

			SDL_GLContext m_context;
			glm::ivec2 m_version;
	};
}


#include "opengl.inl"