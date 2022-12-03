#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tial.h"
#include "BattleField.h"

using namespace std;
using namespace sf;


Field* CreateTials(int num)
{
	Field* Tial = new Field[num];
	Vector2f Pos;
	Vector2f gone;
	gone.x = 900.0;
	gone.y = 0.0;
	Pos.x = 400.0;
	Pos.y = 200.0;
	int x = 0;
	Vector2f tempPos = Pos;
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			tempPos.x += 90;
			Tial[x].SetTial(tempPos);
			x++;
		}
		tempPos.y += 80;
		tempPos.x = Pos.x;
	}
	for (int j = 0; j < num; j++)
	{
		if (Tial[j].GetStatus() == true)
		{
			Tial[j].SetTial(gone);
		}
	}
	return Tial;
}
