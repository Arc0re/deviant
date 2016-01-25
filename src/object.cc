#include "object.h"
#include "render.h"

Object::Object(CHARS sym, SDL_Color bg, SDL_Color t)
	: x(0)
	, y(0)
{
	this->sym = sym;
	this->bg = bg;
	this->t = t;
}

Object::~Object()
{
}

void Object::render()
{
	render_tile(this->sym, this->x, this->y, this->bg, this->t);
}

void Object::move(int x, int y)
{
	this->x += x;
	this->y += y;
}

void Object::attack()
{
}
