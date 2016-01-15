#include "core.h"
#include "maingame.h"
#include "colors.h"
#include "window.h"
#include "characters.h"
#include "render.h"
#include "player.h"
#include "states.h"
#include "menu.h"
#include "map.h"

//
// PROTOTYPES
//
void run_game();
void render_game();
void mv_menu_cursor (SDL_KeyboardEvent *key);


static BOOL quit = FALSE;
static SDL_Event ev;
static GAMESTATE currentgs = TITLE_SCREEN;
static int pos = 0; // cursor pos
static menu_item main_menu[3]=
{
	{TRUE,"New game"},
	{FALSE,"Options"},
	{FALSE,"Return to OS"}
};

void run_game ()
{
	int ww, wh;
	char size[20];
	
    init_window();
    load_texture(TILESET); // we got a nice mem leak here
	
	while (!quit) {
		
		// Window title + size
		SDL_GetWindowSize(WIN, &ww, &wh);
		sprintf(size, "%s %dx%d", WINDOW_TITLE, ww, wh);
		SDL_SetWindowTitle(WIN, size);

		// Set screen to black
		SDL_RenderClear(REN);
		SDL_SetRenderDrawColor(REN, 0, 0, 0, 255);

		render_game();
		
		while (SDL_PollEvent (&ev)) {
			switch (ev.type) {
			case SDL_QUIT:
				quit = TRUE;
				break;
			case SDL_KEYDOWN:
				if (currentgs==TITLE_SCREEN) {
					mv_menu_cursor(&ev.key);
				} else if (currentgs==IN_GAME) {
					switch (ev.key.keysym.sym) {
					case SDLK_q: quit = TRUE;
					case SDLK_UP: move_player(0, -12); break;
					case SDLK_DOWN: move_player(0, +12); break;
					case SDLK_LEFT: move_player(-8, 0); break;
					case SDLK_RIGHT: move_player(+8, 0); break;
					} break;
				}
			}
		}
	}
	
    close_window(); // this should free the texture too
}

void render_game ()
{
	if (currentgs == TITLE_SCREEN) {
		render_ts();
	} else if (currentgs == IN_GAME) {

		w_viewport();
		render_player();

		c_viewport();
		render_str("console:", 0, 0, WHITE, BLUE);
	}
	SDL_RenderPresent(REN);
}

void mv_menu_cursor (SDL_KeyboardEvent *key)
{
	switch (key->keysym.sym) {
	case SDLK_DOWN: ++pos; break;
	case SDLK_UP: --pos; break;
	case SDLK_RETURN:
		if (main_menu[0].is_selected) currentgs=IN_GAME;
		if (main_menu[1].is_selected) bubble("Not implemented yet ;3");
		if (main_menu[2].is_selected) quit = TRUE;
		break;
	}
	switch (pos) {
	case 0:
		main_menu[0].is_selected = TRUE;
		main_menu[1].is_selected = FALSE;
		main_menu[2].is_selected = FALSE;
		break;
	case 1:
		main_menu[0].is_selected = FALSE;
		main_menu[1].is_selected = TRUE;
		main_menu[2].is_selected = FALSE;
		break;
	case 2:
		main_menu[0].is_selected = FALSE;
		main_menu[1].is_selected = FALSE;
		main_menu[2].is_selected = TRUE;
		break;
	}
}

void render_ts ()
{
	int ww, wh;
	const char* t = "DEVIOUS -- ALPHA BUILD";
	const char* st = "All hail the Mighty Cthulhu!!";
	const char* c = "Made by Arc0re1 (c) 2016";

	int	tsize = TILE_WIDTH*strlen(t);
	int stsize = TILE_WIDTH*strlen(st);
	int csize = TILE_WIDTH*strlen(c);
	
	SDL_GetWindowSize(WIN, &ww, &wh);
		
	render_str(t, (ww/2-(tsize/2)), 20, BLACK, BLUE);
	render_str(st, (ww/2-(stsize/2)), 40, DEEPGREEN, GREEN);
	render_str(c, (ww/2-(csize/2)), wh-20, BLACK, RED);

	render_menu(main_menu, ((wh/2)-(15*3)), 3, MENU_CENTERED);
}
