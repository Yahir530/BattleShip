#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tial.h"
#include "BattleField.h"
#include <vector>

using namespace std;
using namespace sf;

//Planning on making this the main game loop
int main()
{
    Field* Player1tials = NULL;
    Field* Player2tials = NULL;
    Vector2f gone;
    gone.x = -100.0;
    gone.y = -100.0;
    int num = 64;
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
	RenderWindow window(VideoMode(resolution.x, resolution.y), "BattleField Game", Style::Fullscreen);
    enum class State { Player1Screen, Player2Screen, GAME_OVER};
    State state = State::Player1Screen;
    delete[] Player1tials;
    Player1tials = CreateTials(num);

    //load a texture for background
    Texture battleshipMap;
    battleshipMap.loadFromFile("Textures/TankMapBackroundTexture.png");
    Sprite battleShipMap;
    battleShipMap.setTexture(battleshipMap);
    battleShipMap.setPosition(290, 0);

    while (window.isOpen())
    {
        // Create event object
        Event event;
        //Handle player input 
        while (window.pollEvent(event))
        {
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
            }
        }
        
        
        if (state == State::Player1Screen)
        {

            //Check if one of the grids were selected
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                Vector2i Select;
                Vector2f Check;
                Select = Mouse::getPosition(window);
                Check.x = Select.x;
                Check.y = Select.y;
                //Moves the clicked tial out of the way
                for (int i = 0; i < num; i++)
                {
                    if (Player1tials[i].GetTialS().getGlobalBounds().contains(Check))
                    {
                        Player1tials[i].Hit();
                        Player1tials[i].update(gone);  
                    }
                  
                }

            }
        }
        
        if (state == State::Player1Screen)
        {
            window.clear();
            window.draw(battleShipMap);
            
            for (int i = 0; i < num; i++)
            {
                window.draw(Player1tials[i].GetTialS());
            }

            window.display();

        }
        
    }

    return 0;
}
