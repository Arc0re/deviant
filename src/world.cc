#include "core.h"
#include "world.h"
#include "render.h"
#include "colors.h"

#include <time.h>
#include <stdlib.h>
#include <iostream>

void gen_world(void)
{
	gen_sea();
}

void gen_sea(void)
{
	render_tile(CHAR_almost_equal_to, 0,0, DEEPGREEN, GREEN);
}
