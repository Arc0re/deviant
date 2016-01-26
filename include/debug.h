// -*- C++ -*-
#include "core.h"
#include <iostream>

namespace Debug {

	template <typename T>
	void print(T msg)
	{
		std::cout << msg << std::endl;
	}
	
	template <typename T, typename T2>
	void print(T msg, T2 ad)
	{
		std::cout << msg << ": " << ad << std::endl;
	}

	template <typename T>
	void msgBox(T msg)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", msg, NULL);
	}
}
