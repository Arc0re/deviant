// -*- C++ -*-

#ifndef MENU_H
#define MENU_H

#include "core.h"

// Menu rendering flags
#define MENU_CENTERED 1
#define MENU_RIGHT 2
#define MENU_LEFT 3

typedef struct {
	BOOL is_selected;
	const char* item;
} menu_item;

void render_menu(menu_item items[], int y, int nbr, int flag);
void move_cursor(menu_item* items, const char* dir);
#endif
