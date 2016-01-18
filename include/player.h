// -*- C++ -*-

#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include "characters.h"

typedef struct {
    int health;
    CHARS sym;
    int x;
    int y;
    SDL_Color bg;
    SDL_Color t;
} PLAYER;

void render_player();
void move_player(int x, int y);
void playerattack();

#endif
