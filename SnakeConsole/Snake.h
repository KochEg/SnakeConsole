#pragma once
#include <Windows.h>
#include "Map.h"

class Snake
{
private:
	int x, y;
	Map* p_map;
	Direction dir;
	POINT tail[maxLengthTail];
	int lengthTail;
	int score;
public:
	Snake(Map* _map);
	void Init(int x, int y, Direction dir);
	void PutOnMapSnake();
	State UserControl(char w, char s, char a, char d);
	State Move();
	int GetX(); 
	int GetY(); 
	void MoveTail(int _x, int _y); 
	void AddTail(int _x, int _y);
};

