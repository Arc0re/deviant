// -*- C++ -*-

#ifndef CORE_H
#define CORE_H

#include <SDL.h>
#include <SDL_image.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;
typedef unsigned int uint;

#define print_error() printf("%s\n", SDL_GetError());
#define bubble(s) SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,\
											   "Error",\
											   s,\
											   NULL);

#define VERSION "0.0.1"
#define WINDOW_TITLE "Deviant"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 300

#define DEFAULT_SPRITESHEET "art/curses_640x300ALPHA.png"
#define TILESET "art/Phoebus_16x16.png"

#endif
