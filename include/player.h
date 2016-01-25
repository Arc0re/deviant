// -*- C++ -*-

#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"
#include "characters.h"

class Player : public Object
{
public:
	//using Object::Object;
	Player(CHARS sym, SDL_Color bg, SDL_Color t);
	
	inline void setHealth(int health) { this->health = health; }
	inline int getHealth() { return health; }
private:
	int health;
};

#endif
