// -*- C++ -*-

#ifndef OBJECT_H
#define OBJECT_H

#include "core.h"

class Object
{
public:
	Object(CHARS sym, SDL_Color bg, SDL_Color t);
	~Object();
	void render();
	virtual void move(int x, int y);
	virtual void attack();

	inline CHARS getSym() { return sym; }
	inline int getX() { return x; }
	inline int getY() { return y; }
	inline SDL_Color getBg() { return bg; }
	inline SDL_Color getT() { return t; }

private:
	CHARS sym;
	int x;
	int y;
	SDL_Color bg;
	SDL_Color t;
};

#endif
