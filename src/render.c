#include "core.h"
#include "colors.h"
#include "window.h"
#include "render.h"
#include "characters.h"
#include "menu.h"


static tile char_tile;
static float sc = 1.0; //scaling, 1.5 looks good for strs, default is 1.0

void load_texture(const char* path)
{
    char_tile.texture = IMG_LoadTexture(REN, path);
    printf("Spritesheet texture %s loaded.\n", path);
}

void render_tile(CHARS c, int x, int y, SDL_Color bg_color,
    SDL_Color tile_color)
{
    int X = TILE_WIDTH;
    int Y = TILE_HEIGHT;
    CHAR_DATA chars;
    SDL_Rect bg = {X*11, Y*13, X, Y}; //pos of the block tile

    /* texture png must be 8x12 * 256 tiles and based on CP437, 16x16 lines */
	/* actually I think the size doesn't matter, only ASCII and same resolution */
    if (char_tile.texture == NULL) {
		puts("Wrong texture! Check spritesheet.");
		exit(EXIT_FAILURE);
    }
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

void render_str(const char* str, int x, int y, SDL_Color bg, SDL_Color t)
{
    int X = TILE_WIDTH;
    int len = strlen(str);

    for(int i = 0; i < len; ++i) {
        render_tile(str[i], x+X*i, y, bg, t);
    }
}
