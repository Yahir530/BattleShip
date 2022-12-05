#ifndef TIAL_H
#define TIAL_H
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Field
{
public:
	Field();
	void SetTial(Vector2f Pos);
	Sprite GetTialS();
	void Hit();
	bool GetStatus();
	void update(Vector2f Pos);

private:
	Sprite Tial;
	bool Is_Hit = false;
	Texture blue;
	Vector2f Location;

};


#endif 

