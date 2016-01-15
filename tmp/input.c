#include "core.h"
#include "maingame.h"
#include "input.h"
#include "menu.h"
#include "player.h"
#include "states.h"

#include <SDL.h>

BOOL parse_events(GAMESTATE g)
{
    BOOL is_running = TRUE;
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        /*if (event.type == SDL_QUIT) {
            is_running = FALSE;
        } else if (event.type == SDL_KEYDOWN) {
			if(g == PLAYING) {
				switch (event.key.keysym.sym) {
				case SDLK_UP: move_player(0, -12); break;
				case SDLK_DOWN: move_player(0, +12); break;
				case SDLK_LEFT: move_player(-8, 0); break;
				case SDLK_RIGHT: move_player(+8, 0); break;
				case SDLK_ESCAPE: is_running=FALSE; break;
				}
			} else if(g==TITLE_SCREEN) {
				switch (event.key.keysym.sym) {
				case SDLK_UP: puts("up"); break;
				case SDLK_DOWN: move_cursor(&event.key, main_menu); break;
				case SDLK_ESCAPE: is_running=FALSE; break;
				}
			}
        }*/

		// Testing
		switch(event.type){
		case SDL_QUIT:
			is_running=FALSE;
		case SDL_KEYDOWN:
			if (g==TITLE_SCREEN) {
				// move_cursor
				//switch (event.key.keysym.sym) {
					//case SDLK_RETURN: 
			} else if (g==IN_GAME) {
				switch (event.key.keysym.sym) {
				case SDLK_UP: move_player(0, -12); break;
				case SDLK_DOWN: move_player(0, +12); break;
				case SDLK_LEFT: move_player(-8, 0); break;
				case SDLK_RIGHT: move_player(+8, 0); break;
				case SDLK_ESCAPE: is_running=FALSE; break; // Change this
				}
				}
			}
		}
    return is_running;
}
