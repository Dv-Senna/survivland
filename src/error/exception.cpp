#include <string>

#include <SDL2/SDL.h>

#include "error/exception.hpp"



namespace gm::error
{
	Game::Game(int code, std::string text) noexcept : m_code {code}, m_text {std::move(text)}
	{

	}



	const char *Game::what() const noexcept
	{
		return this->getMessage().c_str();
	}



	const std::string &Game::getMessage() const noexcept
	{
		return m_text;
	}



	int Game::getCode() const noexcept
	{
		return m_code;
	}






	SDL::SDL(std::string text) noexcept : m_text {std::move(text)}
	{
		m_text += " : " + std::string(SDL_GetError());
	}



	const char *SDL::what() const noexcept
	{
		return this->getMessage().c_str();
	}



	const std::string &SDL::getMessage() const noexcept
	{
		return m_text;
	}



	int SDL::getCode() const noexcept
	{
		return -1;
	}






	OpenGL::OpenGL(int code, std::string text) noexcept : m_code {code}, m_text {std::move(text)}
	{

	}



	const char *OpenGL::what() const noexcept
	{
		return this->getMessage().c_str();
	}



	const std::string &OpenGL::getMessage() const noexcept
	{
		return m_text;
	}



	int OpenGL::getCode() const noexcept
	{
		return m_code;
	}
}