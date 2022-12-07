#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tial.h"
#include "BattleField.h"
#include "Text.h"
#include <vector>

using namespace std;
using namespace sf;

//Planning on making this the main game loop
int main()
{
    Field* Player1tials = NULL;
    Field* Player2tials = NULL;

    Field* Player1tialsWater = NULL;
    Field* Player2tialsWater = NULL;

    Vector2f gone;

    gone.x = -100.0;
    gone.y = -100.0;

    int num = 64;

    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
	RenderWindow window(VideoMode(resolution.x, resolution.y), "BattleField Game", Style::Fullscreen);

    enum class State { Player1Screen, Player2Screen, Title, Player1ScreenWater, Player2ScreenWater};

    State state = State::Title;

    delete[] Player1tials;
    Player1tials = CreateTials(num);
    delete[] Player2tials;
    Player2tials = CreateTials(num);

    delete[] Player1tialsWater;
    Player1tialsWater = CreateTialsWater(num);
    delete[] Player2tialsWater;
    Player2tialsWater = CreateTialsWater(num);

    //load Fonts
    Font font;
    font.loadFromFile("fonts/KOMIKAP_.ttf");
    Text Choices;
    Choices.setFont(font);
    Choices.setFillColor(Color::Black);
    Choices.setCharacterSize(40);
    Choices.setPosition(440, 580);

    Text player1;
    player1.setFont(font);
    player1.setFillColor(Color::Blue);
    player1.setCharacterSize(40);
    player1.setPosition(640, 0);

    Text player2;
    player2.setFont(font);
    player2.setFillColor(Color::Black);
    player2.setCharacterSize(40);
    player2.setPosition(640, 0);

    //load a texture for background
    Texture LandMap;
    LandMap.loadFromFile("Textures/TankMapBackroundTexture.png");
    Sprite GroundForcesMap;
    GroundForcesMap.setTexture(LandMap);
    GroundForcesMap.setPosition(320, 0);

    Texture WaterMap;
    WaterMap.loadFromFile("Textures/OceanMapBackround2.png");
    Sprite BattleShipMap;
    BattleShipMap.setTexture(WaterMap);
    BattleShipMap.setPosition(320, 0);

    Texture Title;
    Title.loadFromFile("Textures/GameIntroScreen (1).png");
    Sprite TitleScreen;
    TitleScreen.setTexture(Title);
    TitleScreen.setPosition(320, 0);
 
    //User ship sprites textures
    Texture Battleshiptexture;
    Battleshiptexture.loadFromFile("Textures/BattleShipSprite.png");
    Sprite TestureBattleship;
    TestureBattleship.setTexture(Battleshiptexture);
    TestureBattleship.setPosition(190,0);
	
    Texture scout;
    scout. loadFromFile("Textures/ScoutCruizerSprite.png");
    Sprite scoutcruzer;
    scoutCruzer.setTexture(scout);
    scoutCruzer.setPosition(190.490);
	
    Texture submarine;
    submarine. loadFromFile("Textures/SubmarineSprite.png");
    Sprite submarineTexture;
    submarineTexture.setTexture(submarine);
    submarineTexture.setPosition(640,-165);
	
    Texture aircraftCarrier;
    aircraftCarrier.loadFromFile("Textures/AircraftCarrierSprite.png"):
    Sprite aircraftcarrierTexture;
    aircrafttarrierTexture.setTexture(aircraftcarrier);
    aircraftCarrierTexture.setPosition(530,25);
	
    // Enemy ship sprites

    Sprite enemyTestureBattleship;
    enemyTestureBattleship.setTexture(Battleshiptexture);
    enemyTestureBattleship.setPosition(190,490);
  
    Sprite enemyscoutcruzer;
    enemyscoutCruzer.setTexture(scout);
    enemyscoutCruzer.setPosition(190,0);
  
    Sprite enemysubmarineTexture;
    enemysubmarineTexture.setTexture(submarine);
    enemysubmarineTexture.setPosition(220,45);
  
    Sprite enemyaircraftCarrierTexture;
    enemyaircraftCarrierTexture.setTexture(aircraftCarrier);
    enemyaircraftcarrierTexture.setPosition(640,-125);
    // User Tank Sprites
    Texture Maus;
    Maus.loadFromFile("Textures/MausTankSprite.png");
    Sprite MausTexture;
    MausTexture. setTexture (Maus);
    MausTexture. setPosition(50, 370);

    Texture littleTank;
    littleTank.loadFromFile("Textures/TankSpritez.png");
    Sprite littleTankTexture;
    littleTankTexture.setTexture(littleTank);
    littleTankTexture.setPosition(370,110);

    Texture sturmTiger;
    sturmTiger. loadFromFile ("Textures/Tank.png");
    Sprite sturmTigerTexture;
    sturmTigerTexture.setTexture(sturmTiger);
    sturmTigerTexture.setPosition(580,99);

    Texture isthree;
    isthree.loadFromFile("Textures/EnemyTankIS-3Sprtie(1).png");
    Sprite isthreeTexture;
    isthreeTexture,setTexture(isthree);
    isthreeTexture,setPosition(630,25);
    // Enemy Tank Sprites
    Texture meighteen;
    meighteen.loadFromFile("Textures/EnemyM-18TankSprite.png");
    Sprite enemymeighteen;
    enemymeighteen.setTexture(meighteen);
    enemymeighteen.setPosition(280,600);
  
    Texture tthirtyfour;
    thirtyfour.loadFromFile("Textures/EnemyT-34TankSprite.png");
    Sprite enemytthirtyfour;
    enemytthirtyfour.setTexture(tthirtyfour);
    enemytthirtyfour.setPosition(190,0);
  
    Sprite enemysturmTigerTexture;
    enemysturmTigerTexture.setTexture(sturmTiger);
    enemysturmTigerTexture.setPosition(610,485);
  
    Sprite enemyisthreeTexture;
    enemyisthreeTexture.setTexture(isthree);
    enemyisthreeTexture.setPosition(640,-125);



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
            else if (Keyboard::isKeyPressed(Keyboard::Num1) && state == State::Title)
            {
                if (event.key.code == Keyboard::Num1)
                {
                    state = State::Player1Screen;
                }

            }
            else if (Keyboard::isKeyPressed(Keyboard::Num2) && state == State::Title)
            {
                if (event.key.code == Keyboard::Num2)
                {
                    state = State::Player1ScreenWater;
                }
            }
            else if (Keyboard::isKeyPressed(Keyboard::Space) && state == State::Player2Screen)
            {
                if (event.key.code == Keyboard::Space)
                {
                    state = State::Player1Screen;
                }
                
            }
            else if (Keyboard::isKeyPressed(Keyboard::Space) && state == State::Player1Screen)
            {
                if (event.key.code == Keyboard::Space)
                {
                    state = State::Player2Screen;
                }
            }
            else if (Keyboard::isKeyPressed(Keyboard::Space) && state == State::Player2ScreenWater)
            {
                if (event.key.code == Keyboard::Space)
                {
                    state = State::Player1ScreenWater;
                }

            }
            else if (Keyboard::isKeyPressed(Keyboard::Space) && state == State::Player1ScreenWater)
            {
                if (event.key.code == Keyboard::Space)
                {
                    state = State::Player2ScreenWater;
                }
            }
            else if (Keyboard::isKeyPressed(Keyboard::B) || state == State::Player1ScreenWater || state == State::Player2ScreenWater || state == State::Player1Screen || state == State::Player2Screen)
            {
                if (event.key.code == Keyboard::B)
                {
                    state = State::Title;
                }
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

        if (state == State::Player1ScreenWater)
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
                    if (Player1tialsWater[i].GetTialS().getGlobalBounds().contains(Check))
                    {
                        Player1tialsWater[i].Hit();
                        Player1tialsWater[i].update(gone);
                    }

                }

            }
        }
        
        if (state == State::Player1Screen)
        {
            window.clear();
            window.draw(GroundForcesMap);
            
            for (int i = 0; i < num; i++)
            {
                window.draw(Player1tials[i].GetTialS());
            }

            player1.setString(Player1Text());
            window.draw(player1);
            window.draw(isthreeTexture);
            window.draw(littleTankTexture);
            window.draw(sturmTigerTexture);
            window.draw (MausTexture);
            window.display();

        }

        if (state == State::Player1ScreenWater)
        {
            window.clear();
            window.draw(BattleShipMap);

            for (int i = 0; i < num; i++)
            {
                window.draw(Player1tialsWater[i].GetTialS());
            }

            player1.setString(Player1Text());
            window.draw(player1);
            window. draw(aircraftCarrierTexture):
            window.draw(submarineTexture);
            window.draw(scoutCruzer);
            window. draw(TestureBattleship);
            window.display();

        }

        if (state == State::Player2Screen)
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
                    if (Player2tials[i].GetTialS().getGlobalBounds().contains(Check))
                    {
                        Player2tials[i].Hit();
                        Player2tials[i].update(gone);
                    }

                }

            }
        }

        if (state == State::Player2ScreenWater)
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
                    if (Player2tialsWater[i].GetTialS().getGlobalBounds().contains(Check))
                    {
                        Player2tialsWater[i].Hit();
                        Player2tialsWater[i].update(gone);
                    }

                }

            }
        }

        if (state == State::Player2Screen)
        {
            window.clear();
            window.draw(GroundForcesMap);

            for (int i = 0; i < num; i++)
            {
                window.draw(Player2tials[i].GetTialS());
            }

            player2.setString(Player2Text());
            window.draw(player2);
            window.draw (enemymeighteen);
            window.draw(enemytthirtyfour);
            window.draw(enemysturmTigerTexture);
            window.draw(enemyisthreeTexture);
            window.display();

        }

        if (state == State::Player2ScreenWater)
        {
            window.clear();
            window.draw(BattleShipMap);

            for (int i = 0; i < num; i++)
            {
                window.draw(Player2tialsWater[i].GetTialS());
            }

            player2.setString(Player2Text());
            window.draw(player2);
            window.draw(enemyaircraftCarrierTexture);
            window.draw (enemysubmarineTexture);
            window. draw (enemyscoutCruzer);
            window. draw (enemyTestureBattleship);
            window.display();

        }

        if (state == State::Title)
        {
            window.clear();
            window.draw(TitleScreen);
            
            Choices.setString(ChoicesText());

            window.draw(Choices);
            window.display();

        }
        
    }

    return 0;
}
