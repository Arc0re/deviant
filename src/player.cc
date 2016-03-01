#include "core.h"
#include "player.h"

Player::Player(CHARS sym, SDL_Color bg, SDL_Color t):
	Object(sym, bg, t),
	health(100)
{
}
