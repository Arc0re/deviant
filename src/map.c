#include "core.h"
#include "window.h"
#include "render.h"
#include "map.h"

void w_viewport ()
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

void c_viewport ()
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
