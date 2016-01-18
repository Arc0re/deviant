#include "core.h"
#include "colors.h"
#include "window.h"
#include "render.h"
#include "characters.h"
#include "menu.h"
#include "file_parser.h"

#include <iostream>
#include <string>
#include <map>

static tile char_tile;
static float sc = 1.0; // scaling, 1.5 looks good for strs, default is 1.0

// GLOBALS defined in render.h
int TILE_WIDTH = 0;
int TILE_HEIGHT = 0;

bool load_texture(std::string path)
{
	std::string full_path("art/");
	full_path.append(path);

    char_tile.texture = IMG_LoadTexture(REN, full_path.c_str());
	if (char_tile.texture == NULL) {
		std::cerr << "Wrong texture name: " << full_path << std::endl;
		return false;
	}
	
    printf("Spritesheet texture %s loaded.\n", full_path.c_str());
	return true;
}

void render_tile(CHARS c, int x, int y, SDL_Color bg_color, SDL_Color tile_color)
{
    int X = TILE_WIDTH;
    int Y = TILE_HEIGHT;
    CHAR_DATA chars;
    SDL_Rect bg = {X*11, Y*13, X, Y}; //pos of the block tile

    if (char_tile.texture == NULL) {
		auto parsed = parser::parse_file("data/init.txt");
		for (auto it = parsed.cbegin(); it != parsed.cend(); ++it) {
			if (!load_texture(it->second.c_str()))
				exit(EXIT_FAILURE); // Crash if wrong texture name
		}
	}

    // texture png must be 8x12 * 256 tiles and based on CP437, 16x16 lines
	// actually I think the size doesn't matter, only ASCII and same resolution
    SDL_QueryTexture(char_tile.texture, NULL, NULL, &char_tile.w, &char_tile.h);

    chars = get_ascii(c);

    // Which part of the texture is gonna be rendered
    char_tile.src.x = chars.char_x;
    char_tile.src.y = chars.char_y;
    char_tile.src.w = X;
    char_tile.src.h = Y;

    // Where its gonna be rendered
    char_tile.dest.x = x;
    char_tile.dest.y = y;
    char_tile.dest.w = X*sc;
    char_tile.dest.h = Y*sc;

    // bg tile color
    SDL_SetTextureColorMod(char_tile.texture, bg_color.r, bg_color.g,
        bg_color.b);
    SDL_RenderCopy(REN, char_tile.texture, &bg, &char_tile.dest);
    // char color
    SDL_SetTextureColorMod(char_tile.texture, tile_color.r, tile_color.g,
        tile_color.b);
    SDL_RenderCopy(REN, char_tile.texture, &char_tile.src,
        &char_tile.dest);
}

void render_tile(int c, int x, int y, SDL_Color bg_color, SDL_Color tile_color)
{
    //int X = TILE_WIDTH;
    //int Y = TILE_HEIGHT;
    CHAR_DATA chars;

    // texture png must be 8x12 * 256 tiles and based on CP437, 16x16 lines
	// actually I think the size doesn't matter, only ASCII and same resolution
    SDL_QueryTexture(char_tile.texture, NULL, NULL, &char_tile.w, &char_tile.h);
	TILE_WIDTH = char_tile.w/16;
    TILE_HEIGHT = char_tile.h/16;

	SDL_Rect bg = {TILE_WIDTH*11, TILE_HEIGHT*13, TILE_WIDTH, TILE_HEIGHT}; //pos of the block tile

	if (char_tile.texture == NULL) {
		auto parsed = parser::parse_file("data/init.txt");
		for (auto it = parsed.cbegin(); it != parsed.cend(); ++it) {
			if (!load_texture(it->second.c_str()))
				exit(EXIT_FAILURE); // Crash if wrong texture name
		}
	}

    chars = get_ascii(c, TILE_WIDTH, TILE_HEIGHT);

    // Which part of the texture is gonna be rendered
    char_tile.src.x = chars.char_x;
    char_tile.src.y = chars.char_y;
    char_tile.src.w = TILE_WIDTH;
    char_tile.src.h = TILE_HEIGHT;

    // Where its gonna be rendered
    char_tile.dest.x = x;
    char_tile.dest.y = y;
    char_tile.dest.w = TILE_WIDTH*sc;
    char_tile.dest.h = TILE_HEIGHT*sc;

    // bg tile color
    SDL_SetTextureColorMod(char_tile.texture, bg_color.r, bg_color.g,
        bg_color.b);
    SDL_RenderCopy(REN, char_tile.texture, &bg, &char_tile.dest);
    // char color
    SDL_SetTextureColorMod(char_tile.texture, tile_color.r, tile_color.g,
        tile_color.b);
    SDL_RenderCopy(REN, char_tile.texture, &char_tile.src,
        &char_tile.dest);
}

void render_str(const char* str, int x, int y, SDL_Color bg, SDL_Color t)
{
    int len = strlen(str);

    for(int i = 0; i < len; ++i) {
        render_tile(str[i], x+TILE_WIDTH*i, y, bg, t);
    }
}
