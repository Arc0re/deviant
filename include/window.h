// -*- C++ -*-

#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
} window;

extern SDL_Window* WIN; // Window handler
extern SDL_Renderer* REN;

void init_window();
void pause(int time);
void close_window();
void msg_box(const char* message);

#endif
