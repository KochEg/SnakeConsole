#include <iostream>
#include <Windows.h>
#include "Map.h"
#include "Snake.h"
using namespace std;

void Map::MoveXY(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Map::PutSimbol(int x, int y, char simbol)
{
	this->map[y][x] = simbol;
}

void Map::ClearMap()
{
	map[heigthMap - 1][widthMap - 1] = '\0';
	for (int i = 0; i < heigthMap; i++)
		for (int j = 0; j < widthMap; j++)
		{
			map[i][j] = ' ';
		}

	for (int i = 0; i < heigthMap; i++)
		for (int j = 0; j < widthMap; j++)
		{
			map[0][j] = wall;
			map[heigthMap - 1][j] = wall;
		}

	for (int i = 1; i < heigthMap - 1; i++)
	{
		map[i][0] = wall;
		map[i][widthMap -1] = wall;
	}

}

void Map::ShowMap()
{
	MoveXY(0, 0);
	for (int i = 0; i < heigthMap; i++)
	{
		for (int j = 0; j < widthMap; j++)
			cout << map[i][j];
		printf("\n");
	}
	printf(" Score: %d              exit - press esc\n", score);
}

bool Map::CellInMap(int x, int y)
{
	return (x >= 1) && (x < widthMap - 1) && (y >= 1) && (y < heigthMap -1);
}

bool Map::IsFreeCell(int x, int y)
{
	if (!CellInMap(x, y))
		return false; 

	return (map[y][x] != head) && (map[y][x] != tail_c);
}

char Map::GetMap(int y, int x)
{
	return map[y][x];
}

void Map::SetScore(int _score)
{
	score = _score;
}

void Map::Title()
{
	printf("   W - Up    S - Down                 \n");
	printf("   A - Left  D - Rigth                \n");
	printf("                                      \n");
	printf("                                      \n");
	printf("                                      \n");
	printf("                                      \n");
	printf("      ### #     # #### #  # ###       \n");
	printf("      #   # #   # #  # # #  #         \n");
	printf("      ### #   # # #  # ##   ###       \n"); 
	printf("        # #    ## #### ##   #         \n");
	printf("        # #     # #  # # #  #         \n");
	printf("      ### #     # #  # #  # ###       \n");
	printf("                                      \n");
	printf("      Press any key to Start          \n");
}
