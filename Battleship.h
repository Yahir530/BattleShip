/* 
#include <iostream>
#include<time.h>
#include <string>
using namespace std;

class vehicle
{
public:
    int coordX;
    int coordY;
    int coordX_prev;
    int coordY_prev;
    int coord_ascii;
    int m_size;
    int m_player;
    string m_name;
private:
    void drawShip();
    boat();
    void locateXY(int x, int y);
    void generateVehicle();
    virtual void sound();
    int getX(int x);
    int gety(int y);
    int getsize();
    string getname();
    int getposition(int loc1, int loc2);
    void setCordinateX(int x);
    void setCoordinateY(int y);
    void setplayer(int player);
    void setlocaton(int loc1,int loc 2, int value);
    int counter;

    

};

class tank: public vehicle
{
public:
    tank();
    void sound();
};

class boat: public vehicle
{
public:
    boat();
    void sound();
};

class cruiser: public boat
{
public:
    cruiser()
    void sound();
};

class submarine: public boat
{
public:
    submarine()
    void sound();
};
class destroyer: public boat
{
public:
    destroyer()
    void sound ();

}*/
#include <iostream>
#include <vector>
#include "string"
#include "array"
#include <SFML/Graphics.hpp>




class Boat
{
	private:
		sf::Sprite sprite;
		sf::Sprite explosion;
		sf::Sprite filledCase;
		sf::Sprite playedCase;
		sf::Texture playedTexture;
		sf::Texture explosionTexture;
		sf::Texture boatTexture;				  
		sf::Texture filledTexture;
		sf::Vector2f position;
		std::vector<sf::IntRect> textureRect;
		std::vector<sf::Vector2f> origin;
		std::vector<Boat> boat;
		std::string state;	
		std::string rotation;
		const int BOATCOUNT;
		const int HORIZONTAL;
		const int VERTICAL;
		const int MARGIN;
		const int STARTED;
		bool canSelect;
		bool status;
	public:
		Boat();											
		void initialize();						
		void setStatus(bool);					
		void select(sf::RenderWindow&,sf::Vector2i);					
		void rotate(sf::Vector2i,sf::Event&);			
		void move(sf::RenderWindow&);							 
		bool checkPositionOnGrid(sf::FloatRect& );			
		const sf::FloatRect getBoatPosition();				
		void missed(sf::RenderWindow& window, const int&,const int&);    
		void filled(sf::RenderWindow&, const int&,const int&);		
		void destroyed(sf::RenderWindow&,const int&, const int&);		
		void draw(sf::RenderWindow&);				
};
#endif
