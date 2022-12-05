#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tial.h"
#include "BattleField.h"

using namespace std;
using namespace sf;

//Function creates the tial sprites wich will be stored in a class
Field* CreateTials(int num)
{
	Field* Tial = new Field[num];
	Vector2f Pos;

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
	
	return Tial;
}

Field* CreateTialsWater(int num)
{
	Field* Tial = new Field[num];
	Vector2f Pos;

	Pos.x = 400.0;
	Pos.y = 200.0;
	int x = 0;

	Vector2f tempPos = Pos;
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			tempPos.x += 90;
			Tial[x].SetTialWater(tempPos);
			x++;
		}
		tempPos.y += 80;
		tempPos.x = Pos.x;
	}

	return Tial;
}
