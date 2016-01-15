#include "core.h"
#include "colors.h"
#include "menu.h"
#include "render.h"
#include "window.h"

#include <string.h>
#include <SDL.h>

void render_menu(menu_item* items, int y, int nbr, int flag)
{
	int ww, wh;
	SDL_GetWindowSize(WIN, &ww, &wh);

	if (flag == MENU_CENTERED) {
		for (int i=0; i<nbr; ++i) {
			if(items[i].is_selected) {
				render_str(items[i].item,
						   (ww/2-(TILE_WIDTH*strlen(items[i].item)/2)),
						   y+i*15, WHITE, BLACK);
			} else {
				render_str(items[i].item,
						   (ww/2-(TILE_WIDTH*strlen(items[i].item)/2)),
						   y+i*15, BLACK, WHITE);
			}
		}
	}
}
