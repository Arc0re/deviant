#include "core.h"
#include "maingame.h"
#include "colors.h"
#include "window.h"
#include "characters.h"
#include "render.h"
#include "player.h"
#include "states.h"
#include "menu.h"
#include "world.h"
#include "object.h"

#include <cstdlib>
#include <iostream>
#include <random>

void run_game(void);
void render_game(void);
void mv_menu_cursor(SDL_KeyboardEvent *key);
void w_viewport(void);
void c_viewport(void);

static BOOL quit = FALSE;
static SDL_Event ev;
static GAMESTATE currentgs = TITLE_SCREEN;
static int pos = 0; // cursor pos
static World world;
static Player player(CHAR_at, {0,48,64}, {51,102,0});

static menu_item main_menu[3] =
{
	{TRUE,"New game"},
	{FALSE,"Options"},
	{FALSE,"Return to OS"}
};

void run_game()
{
	int ww, wh;
	char size[20];
	
    init_window();
	
	while (!quit) {
		
		// Window title + size
		SDL_GetWindowSize(WIN, &ww, &wh);
		sprintf(size, "%s %dx%d", WINDOW_TITLE, ww, wh);
		SDL_SetWindowTitle(WIN, size);

		// Set screen to black
		SDL_RenderClear(REN);
		SDL_SetRenderDrawColor(REN, 0, 0, 0, 255);

		render_game();
		
		while (SDL_PollEvent(&ev)) {
			switch (ev.type) {
			case SDL_QUIT:
				quit = TRUE;
				break;
			case SDL_KEYDOWN:
				if (currentgs == TITLE_SCREEN) {
					mv_menu_cursor(&ev.key);
				} else if (currentgs == IN_GAME) {
					switch (ev.key.keysym.sym) {
					case SDLK_q:
						quit = TRUE;
					case SDLK_UP:
						player.move(0, -12); break;
					case SDLK_DOWN:
						player.move(0, 12); break;
					case SDLK_LEFT:
						player.move(-8, 0); break;
					case SDLK_RIGHT:
						player.move(8, 0); break;
					} break;
				}
			}
		}
	}
	close_window();
}

void render_game()
{
	if (currentgs == TITLE_SCREEN) {
		render_ts();
	} else if (currentgs == IN_GAME) {
		w_viewport();

	    world.renderCellmap();

		player.render();

		c_viewport();
		render_str("console:", 0, 0, WHITE, BLUE);
		render_str("Press 'q' to quit.", 0, 20, BLACK, RED);
	}
	SDL_RenderPresent(REN);
}

void mv_menu_cursor(SDL_KeyboardEvent *key)
{
	switch (key->keysym.sym) {
	case SDLK_DOWN: ++pos; break;
	case SDLK_UP: --pos; break;
	case SDLK_RETURN:
		if (main_menu[0].is_selected) currentgs = IN_GAME;
		if (main_menu[1].is_selected) Debug::msgBox("Not implemented yet ;3");
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

void render_ts()
{
	int ww, wh;
	const char* t = "DEVIANT -- ALPHA BUILD";
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

void w_viewport()
{
	int ww, wh;
	SDL_Rect world_view;

	SDL_GetWindowSize(WIN, &ww, &wh);
	
	world_view.x = 0;
	world_view.y = 0;
	world_view.w = ww;
	world_view.h = wh-(wh/5);
	SDL_RenderSetViewport(REN, &world_view);
}

void c_viewport()
{
	int ww, wh;
	SDL_Rect console;

	SDL_GetWindowSize(WIN, &ww, &wh);
	
	console.x = 0;
	console.y = wh-(wh/5);
	console.w = ww;
	console.h = wh/5;
	SDL_RenderSetViewport(REN, &console);
}
