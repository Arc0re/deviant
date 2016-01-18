// -*- C++ -*-

#ifndef RENDER_H
#define RENDER_H

#include "characters.h"

#include <SDL.h>
#include <string>

typedef struct {
    SDL_Texture* texture;
    SDL_Rect src; // part of the texture
    SDL_Rect dest; // rendering target, can do scaling
    int w;
    int h;
} tile;

extern int TILE_WIDTH; // texture w & h
extern int TILE_HEIGHT;

bool load_texture(std::string path);
void render_tile(CHARS c, int x, int y, SDL_Color bg, SDL_Color t);
void render_str(const char* str, int x, int y, SDL_Color bg, SDL_Color t);

#endif
