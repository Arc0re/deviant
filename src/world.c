#include "core.h"
#include "world.h"
#include "render.h"
#include "colors.h"

#include <time.h>
#include <stdlib.h>

//static int wrand = get_rand();
//static int world_w = 600;
//static int world_h = 600;


int get_rand(void)
{
	srand(time(NULL));
	int r = rand();
	return r;
}

void gen_world(void)
{
	gen_sea();
}

void gen_sea(void)
{
	/*for (int i=0; i<world_w; ++i) {
		for (int j=0; j<world_h; ++j) {
			render_tile(CHAR_WAVES, i, j, DEEPBLUE, BLUE);
		}
		}*/
	render_tile(CHAR_WAVES, 0,0, DEEPBLUE, BLUE);
}
