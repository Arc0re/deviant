#include "core.h"
#include "world.h"
#include "render.h"
#include "colors.h"
#include "characters.h"

#include <random>
#include <iostream>


World::World():
	gen(rd()),
	dis(0, 1),
	chanceStartAlive(0.4f),
    birthLimit(4),
	deathLimit(3),
	steps(3)
{
	Debug::print("Chances", chanceStartAlive);
	Debug::print("Birth limit", birthLimit);
	Debug::print("Death limit", deathLimit);

	initWorld();
	for (int i = 1; i <= steps; ++i) {
		doSimulationStep();
		Debug::print("Generation step", i);
	}
}

World::~World()
{
}

void World::initWorld()
{
	// Filling up base map
	for (int x = 0; x < MAP_WIDTH; ++x) {
		for (int y = 0; y < MAP_HEIGHT; ++y) {
			if (dis(gen) < chanceStartAlive) {
				cellmap[x][y] = true;
			}
		}
	}
}

// Returns the number of cells around x-y that are 'alive'
int World::countAliveNeighbours(Cellmap cellmap, int x, int y)
{
	int count = 0;

	// Starts at -1, loops to +1
	// x-1  x   x+1
	// y-1
	// y   (x,y)
	// y+1
	for (int i = -1; i < 2; ++i) {
		for (int j = -1; j < 2; ++j) {
			int neighbour_x = x+i;
			int neighbour_y = y+j;
			
			// If we're looking at the middle point
			if (i == 0 && j == 0) {
                //Do nothing
            } else if (neighbour_x < 0 ||
					   neighbour_y < 0 ||
					   neighbour_x >= static_cast<int>(cellmap.size()) ||
					   neighbour_y >= static_cast<int>(cellmap[0].size())) {
				//In case the index we're looking at it off the edge of the map
                count = count + 1;
            }
            //Otherwise, a normal check of the neighbour
            else if (cellmap[neighbour_x][neighbour_y]) {
                count = count + 1;
            }
		}
	}
	return count;
}

void World::doSimulationStep()
{
	for (int x = 0; x < static_cast<int>(cellmap.size()); ++x) {
		for (int y = 0; y < static_cast<int>(cellmap[0].size()); ++y) {
			int nbs = countAliveNeighbours(cellmap, x, y);

			// If a cell is alive, but has too few neightboors, kill it
			if (cellmap[x][y]) {
				if (nbs < deathLimit) {
					newCellmap[x][y] = false;
				} else {
					newCellmap[x][y] = true;
				}
			} else {
				// If a cell is dead, check if she has enough nbs to be alive (DEADCELL lol)
				if (nbs > birthLimit) {
					newCellmap[x][y] = true;
				} else {
					newCellmap[x][y] = false;
				}
			}
		}
	}
}

void World::renderCellmap()
{
	for (uint a = 0; a < newCellmap.size(); ++a) {
		for (uint b = 0; b < newCellmap[a].size(); ++b) {
		    if (newCellmap[a][b] == true) {
				render_tile(CHAR_hash, a*TILE_WIDTH, b*TILE_HEIGHT, BLACK, DEEPPURPLE);
			} else if (newCellmap[a][b] == false) {
				render_tile(CHAR_dot, a*TILE_WIDTH, b*TILE_HEIGHT, BLACK, DEEPGREY);
			}
		}
	}
}
