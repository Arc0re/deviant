#include "maingame.h"

#include <stdio.h>

void usage()
{
	puts("Usage:");
	puts("'-t': load the tileset");
	puts("No args loads the ascii tileset. WIP");
	exit(EXIT_FAILURE);
}

// the C is required for SDL
extern "C" int main(int argc, char* argv[])
{
	while ((argc > 1) && (argv[1][0] == '-'))
	{
		switch (argv[1][1])
		{
		case 't':
			break;
		default:
			printf("Wrong Argument: %s\n", argv[1]);
			usage();
		}

		++argv;
		--argc;
	}

    run_game();
    return 0;
}
