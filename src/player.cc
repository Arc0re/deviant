#include "core.h"
#include "render.h"
#include "window.h"
#include "player.h"

#include <SDL.h>
#include <iostream>

static PLAYER player = {
	100,
	CHAR_at,
	200,
	200,
	{0, 48, 64},
	{51, 102, 0}
};

void render_player()
{
    render_tile(player.sym, player.x, player.y, player.bg, player.t);
}

void move_player(int x, int y)
{
    player.x = player.x + x;
    player.y = player.y + y;
}

void playerattack()
{

}
