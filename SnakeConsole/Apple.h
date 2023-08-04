#pragma once
#include "Map.h"
#include "Snake.h"

class Apple
{
private:
	int appleX;
	int appleY;
	Map* p_map;

public:
	Apple(Map *_map);
	void Init(int x, int y);
	void PutOnMapApple(Snake* snake);
};

