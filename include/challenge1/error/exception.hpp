#pragma once

#include <exception>
#include <string>


namespace gm::error
{
	class Exception
	{
		public:
			virtual ~Exception() = default;
			virtual const std::string &getMessage() const noexcept = 0;
			virtual int getCode() const noexcept = 0;
	};


	class Game : public std::exception, public gm::error::Exception
	{
		public:
			Game(int code, std::string text) noexcept;
			virtual ~Game() noexcept = default;

			virtual const char *what() const noexcept;
			virtual const std::string &getMessage() const noexcept;
			virtual int getCode() const noexcept;


		private:
			int m_code;
			std::string m_text;
	};



	class SDL : public std::exception, public gm::error::Exception
	{
		public:
			SDL(std::string text) noexcept;
			virtual ~SDL() noexcept = default;

			virtual const char *what() const noexcept;
			virtual const std::string &getMessage() const noexcept;
			virtual int getCode() const noexcept;


		private:
			std::string m_text;
	};



	class OpenGL : public std::exception, public gm::error::Exception
	{
		public:
			OpenGL(int code, std::string text) noexcept;
			virtual ~OpenGL() noexcept = default;

			virtual const char *what() const noexcept;
			virtual const std::string &getMessage() const noexcept;
			virtual int getCode() const noexcept;


		private:
			int m_code;
			std::string m_text;
	};
}