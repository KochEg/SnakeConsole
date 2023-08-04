#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Map.h"
#include "Snake.h"
#include "Apple.h"
using namespace std;




int main()
{
	char command[1000];
	sprintf(command, "mode con cols=%d lines=%d", scr_width, scr_heigth);
	system(command);
	bool start;
	Map map;
	Snake snake(&map);
	Apple apple(&map);
	snake.Init(5, 10, Rigth);
	do
	{
		map.Title();
		start = _getch();
	} 
	while (!start);
	do
	{
		bool kill = snake.UserControl('W', 'S', 'A', 'D') == Death;
		if (kill)
			snake.Init(5, 10, Rigth);
		map.ClearMap();
		snake.PutOnMapSnake();
		apple.PutOnMapApple(&snake);
		map.ShowMap();
	
		Sleep(80);
	} while (GetKeyState(VK_ESCAPE) >= 0);

	return 0;
}


