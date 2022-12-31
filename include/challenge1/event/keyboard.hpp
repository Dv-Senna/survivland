#pragma once

#include <SDL2/SDL.h>

#include "window/id.hpp"


namespace gm::event
{
	enum class Key
	{
		ka = SDL_SCANCODE_A,
		kb, kc, kd, ke, kf, kg, kh, ki, kj, kk, kl, km, kn, ko, kp, kq, kr, ks, kt, ku, kv, kw, kx, ky, kz,

		k1 = SDL_SCANCODE_1,
		k2, k3, k4, k5, k6, k7, k8, k9, k0,

		kesc = SDL_SCANCODE_ESCAPE,
		ktab = SDL_SCANCODE_TAB,
		kcapslock = SDL_SCANCODE_CAPSLOCK,
		klshift = SDL_SCANCODE_LSHIFT,
		klctrl = SDL_SCANCODE_LCTRL,
		klalt = SDL_SCANCODE_LALT,
		kspace = SDL_SCANCODE_SPACE,
		kralt = SDL_SCANCODE_RALT,
		krctrl = SDL_SCANCODE_RCTRL,
		krshift = SDL_SCANCODE_RSHIFT,
		kreturn = SDL_SCANCODE_RETURN,
		kbackspace = SDL_SCANCODE_BACKSPACE,

		kinsert = SDL_SCANCODE_INSERT,
		kdelete = SDL_SCANCODE_DELETE,
		khome = SDL_SCANCODE_HOME,
		kend = SDL_SCANCODE_END,
		kpageup = SDL_SCANCODE_PAGEUP,
		kpagedown = SDL_SCANCODE_PAGEDOWN,

		knumdiv = SDL_SCANCODE_KP_DIVIDE,
		knummult = SDL_SCANCODE_KP_MULTIPLY,
		knumplus = SDL_SCANCODE_KP_PLUS,
		knumminus = SDL_SCANCODE_MINUS,
		knumenter = SDL_SCANCODE_KP_ENTER,
		knum1 = SDL_SCANCODE_KP_1,
		knum2, knum3, knum4, knum5, knum6, knum7, knum8, knum9, knum0,
		knumdot = SDL_SCANCODE_KP_PERIOD,

		kup = SDL_SCANCODE_UP,
		kdown = SDL_SCANCODE_DOWN,
		kright = SDL_SCANCODE_RIGHT,
		kleft = SDL_SCANCODE_LEFT,

		kf1 = SDL_SCANCODE_F1,
		kf2, kf3, kf4, kf5, kf6, kf7, kf8, kf9, kf10, fk11, fk12,

		kundefined
	};


	struct KeyEvent
	{
		gm::event::Key key;
		bool isDown;
		gm::window::ID windowID;

		inline static gm::event::KeyEvent create(gm::event::Key key) noexcept
		{
			return {key, false, 0};
		}
	};
}