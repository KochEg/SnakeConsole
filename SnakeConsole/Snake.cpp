#include <Windows.h>
#include "Snake.h"

Snake::Snake(Map* _map)
{
	p_map = _map;
	Init(0, 0, Rigth);
	_map->SetScore(score);
}

void Snake::Init(int _x, int _y, Direction _dir)
{
	x = _x;
	y = _y;
	dir = _dir;
	lengthTail = 0;
	p_map->SetScore(0);
}

void Snake::PutOnMapSnake()
{
	p_map->PutSimbol(x, y, head);
	for (int i = 0; i < lengthTail; i++) /*проходим по всем элементам хвоста и рисуем '+'*/
		p_map->PutSimbol(tail[i].x, tail[i].y, tail_c);
}

State Snake::UserControl(char w, char s, char a, char d)
{
	if (GetKeyState(w) < 0) dir = Up;
	if (GetKeyState(s) < 0) dir = Down;
	if (GetKeyState(a) < 0) dir = Left;
	if (GetKeyState(d) < 0) dir = Rigth;
	
	return Move();
}


State Snake::Move()
{
	POINT old; 
	old.x = x;
	old.y = y;

	if (dir == Left) x--;  
	if (dir == Rigth) x++;
	if (dir == Up) y--;
	if (dir == Down) y++;

	if (!p_map->IsFreeCell(x, y))
	{
		score = 0;
		return Death;
	}

	if (p_map->GetMap(y, x) == apple)
	{
		AddTail(old.x, old.y);
		p_map->SetScore(++score);
	}
	else
		MoveTail(old.x, old.y);

	return Life;
}

int Snake::GetX()
{
	return x;
}


int Snake::GetY()
{
	return y;
}

void Snake::AddTail(int _x, int _y)
{
	MoveTail(_x, _y);
	lengthTail++;
	if (lengthTail >= maxLengthTail) 
		lengthTail = maxLengthTail - 1;
}

void Snake::MoveTail(int _x, int _y)
{
	for (int i = lengthTail - 1; i >= 0; i--)
		tail[i + 1] = tail[i];
	tail[0].x = _x; 
	tail[0].y = _y;
}



