#pragma once
#include "Constants.h"

class Map
{
private:
	void MoveXY(int x, int y);
	char map[heigthMap][widthMap];
	int score;

public:
	void PutSimbol(int x, int y, char head);
	void ClearMap();
	void ShowMap();
	bool CellInMap(int x, int y);
	bool IsFreeCell(int x, int y);
	char GetMap(int y, int x);
	void SetScore(int _score);
	void Title();
};
