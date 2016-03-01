// -*- C++ -*-

#ifndef WINDOW_H
#define WINDOW_H

#include "core.h"

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
} window;

extern SDL_Window* WIN; // Window handler
extern SDL_Renderer* REN;

void init_window();
void pause(int time);
void close_window();

#endif
