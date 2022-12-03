#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
 /*
 int main()
{
    //Create a video mode object
    VideoMode vm(1920, 1080);
    
    // create and open a window for the game
    RenderWindow window(vm, "Battleship-Ground Forces!", Style::Fullscreen);

    //Create texture
    Texture introScreen;
    //Load graphic into texture
    introScreen.loadFromFile("Textures/GameIntroScreen (1).png");
    //make sprite
    Sprite loadingScreen;
    //Attach texture to sprite
    loadingScreen.setTexture(introScreen);
    // Set the sprite Backround to cover screen
    loadingScreen.setPosition(0,0);

    //Battleship map texture
    Texture battleshipMap;
    battleshipMap.loadFromFile("Textures/OceanMapBackround2.png");
    Sprite battleShipMap;
    battleShipMap.setTexture(battleshipMap);
    battleShipMap.setPosition(0,0);

    //Ground Forces map texture backround
    Texture groundforces;
    groundforces.loadFromFile("Textures/TankMapBackroundTexture.png");
    Sprite groundForcesMap;
    groundForcesMap.setTexture(groundforces);
    groundForcesMap.setPosition(0,0);


    //main game loop
    while(window.isOpen())
    {
        // Create event object
        Event event;
        //Handle player input 
        while(window.pollEvent(event))
        {
            if(Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
            }

            switch(event.type)
            {
                case Event::Closed:
                    window.close();
                    break;

                case Event::KeyPressed:1
                   // window.draw(battleShipMap);
                    //break;

                case Event::KeyPressed:2
                    //window.draw(groundForcesMap);
                    //break;
            }

            // Update scene

            //Draw scene

            // Clear everything from last frame
            window.clear();

            // Draw our game scene
            //window.draw(loadingScreen);
            window.draw(groundForcesMap);

            //Show eveyerything you drew
            window.display();
        }
        

    }

    return 0;
}
*/