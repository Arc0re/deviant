// -*- C++ -*-

#ifndef CORE_H
#define CORE_H

#ifdef _WIN32
	#include <SDL2\SDL.h>
	#include <SDL2\SDL_image.h>
#elif __APPLE__
	#include <SDL.h>
	#include <SDL_image.h>
#endif

#include "characters.h"
#include "debug.h"

#define TRUE 1
#define FALSE 0

typedef int BOOL;
typedef unsigned int uint;

#define VERSION "0.0.1"
#define WINDOW_TITLE "Deviant"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 300

#endif
