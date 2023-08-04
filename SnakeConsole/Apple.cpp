#include <iostream>
#include "Apple.h"

Apple::Apple(Map *_map)
{
	p_map = _map;
	Init(10, 10);
}

void Apple::Init(int x, int y)
{
	appleX = x;
	appleY = y;
}

void Apple::PutOnMapApple(Snake *snake)
{
	p_map->PutSimbol(appleX, appleY, apple);

	if ((snake->GetY() == appleY) && (snake->GetX() == appleX))
	{
		appleX = rand() * 1.0 / RAND_MAX * 38 + 1;
		appleY =  rand() * 1.0 / RAND_MAX * 18 + 1;
	}
}