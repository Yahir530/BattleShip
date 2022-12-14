#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tial.h"


using namespace std;
using namespace sf;

Field::Field()
{
	blue.loadFromFile("Textures/Tial.png");
	purple.loadFromFile("Textures/Tial2.png");
}

void Field::SetTial(Vector2f Pos)
{
	Tial.setTexture(blue);
	Tial.setPosition(Pos);
	Location = Pos;
}

void Field::SetTialWater(Vector2f Pos)
{
	Tial.setTexture(purple);
	Tial.setPosition(Pos);
	Location = Pos;
}

Sprite Field::GetTialS()
{
	return Tial;
}

void Field::Hit()
{
	Is_Hit = true;
}

bool Field::GetStatus()
{
	return Is_Hit;
}

void Field::update(Vector2f Pos)
{
	Tial.setPosition(Pos);
}

