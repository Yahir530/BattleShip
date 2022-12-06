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
