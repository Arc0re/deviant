// -*- C++ -*-

#ifndef WORLD_H
#define WORLD_H

#include <array>
#include <random>

#define MAP_WIDTH 100
#define MAP_HEIGHT 100

typedef std::array<std::array<bool, MAP_WIDTH>, MAP_HEIGHT> Cellmap;

class World {
	
public:
	World();
	~World();
	void renderCellmap();
	inline auto getMap() { return newCellmap; }

private:
	// RNG stuff
	std::random_device rd;
	std::mt19937 gen;
	std::uniform_real_distribution<> dis;
	// -----
	float chanceStartAlive;
	int birthLimit;
	int deathLimit;
	int steps;
	Cellmap cellmap;
	Cellmap newCellmap;
	
	void initWorld();
    void doSimulationStep();
	int countAliveNeighbours(Cellmap cellmap, int x, int y);
};

#endif

