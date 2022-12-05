#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


string ChoicesText()
{

	string txt;

	txt =
		"Select a number on your keyboard\n"
		"1: Ground Forces\n"
		"2: Battleship\n"
		"Esc: Quit\n";
	return txt;
}

string Player1Text()
{

	string txt;

	txt = 
		"Player 1's Turn\n" 
		"(Remove this later) Right now swap between\n player 1 and 2 by pressing space";
	return txt;

}

string Player2Text()
{

	string txt;

	txt = "Player 2's Turn";
	return txt;
}

