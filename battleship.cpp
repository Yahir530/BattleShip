Boat::Boat(): BOATCOUNT(4),HORIZONTAL(90),VERTICAL(180),MARGIN(50),STARTED(1)
{	
	// SMALL / MEDIUM / BIG BOATS
	textureRect.push_back(sf::IntRect(123,86,29,61));
	textureRect.push_back(sf::IntRect(59,56,29,91));
	textureRect.push_back(sf::IntRect(59,56,29,91));
	textureRect.push_back(sf::IntRect(0,0,31,147));
	
	//EXPLOSION
	explosionTexture.loadFromFile("Boats.png");
	explosion.setTexture(explosionTexture);
	explosion.setTextureRect(sf::IntRect(74,1,39,33));

	//FILLED CASE
	filledTexture.loadFromFile("Boats.png");
	filledCase.setTexture(filledTexture);
	filledCase.setTextureRect(sf::IntRect(114,9,23,23));
	filledCase.setOrigin(-1,-6);
	
	// PLAYED CASE
	playedTexture.loadFromFile("Resources/Boats.png");
	playedCase.setTexture(playedTexture);
	playedCase.setTextureRect(sf::IntRect(37,6,30,31));
	playedCase.setOrigin(-1,-2);

	// SET ORIGIN OF EACH BOATS SMALL / MEDIUM / BIG
	origin.push_back(sf::Vector2f(6,25));	
	origin.push_back(sf::Vector2f(7,40));
	origin.push_back(sf::Vector2f(7,40));
	origin.push_back(sf::Vector2f(8,71));	
	
	position.x = 512;
	position.y = 140;
	
	canSelect = true;
	status = true;	
}

void Boat::initialize()
{
	boatTexture.loadFromFile("Resources/Boats.png");
	
	// DEFINE TEXTURE / POSITION / ORIGIN FOR EACH BOAT
	for(int i = 0; i < BOATCOUNT ; i++)
	{
		boat.push_back(Boat());
		boat[i].sprite.setTexture(boatTexture);
		boat[i].sprite.setTextureRect(textureRect[i]);
		boat[i].sprite.setPosition(position.x,position.y + i * MARGIN);
		boat[i].sprite.setRotation(HORIZONTAL);
		boat[i].sprite.setOrigin(origin[i]);
		boat[i].state = "LOCKED";
		boat[i].rotation = "HORIZONTAL";	
	}
}

void Boat::setStatus(bool value)
{ // SET IF THE BOAT CAN MOVED OR NOT MOVED IF THE GAME STARTED
	status = value;
}

void Boat::select(sf::RenderWindow& win,sf::Vector2i cursorPosition)
{
	
	for(int i = 0;i < boat.size();i++) {
		if(boat[i].sprite.getGlobalBounds().contains(cursorPosition.x,cursorPosition.y))
		{

			boat[i].state = "UNLOCKED";
			// LEFT CLICK LOCK/UNLOCK BOAT
			if(boat[i].state == "UNLOCKED" && canSelect && status) { 
				boat[i].move(win);
			}
			canSelect = false;
				
		}
		else { boat[i].state = "LOCKED"; canSelect = true; }

	}
}

void Boat::rotate(sf::Vector2i cursorPosition,sf::Event &event)
{
	for(int i = 0;i < boat.size();i++) {
		if(boat[i].sprite.getGlobalBounds().contains(cursorPosition.x,cursorPosition.y) && 
				boat[i].rotation == "HORIZONTAL")	
		{
			 boat[i].sprite.setRotation(VERTICAL); boat[i].rotation = "VERTICAL"; 
		}
		else if (boat[i].sprite.getGlobalBounds().contains(cursorPosition.x,cursorPosition.y)) 
		{
	       		boat[i].sprite.setRotation(HORIZONTAL); boat[i].rotation = "HORIZONTAL";
		}
	}
}

void Boat::move(sf::RenderWindow& win)
{	
		sprite.setPosition(sf::Mouse::getPosition(win).x,sf::Mouse::getPosition(win).y);
}

bool Boat::checkPositionOnGrid(sf::FloatRect& gridSquare)
{
	for(int i=0; i < boat.size(); i++)
	{
		if(gridSquare.intersects(boat[i].sprite.getGlobalBounds()))
		{
			return true;
		}		
	}

	return false;
}

const sf::FloatRect Boat::getBoatPosition()
{	
	for ( int i = 0; i < boat.size() ; i++)
	{ 
		return boat[i].sprite.getGlobalBounds();
	}
}

void Boat::missed(sf::RenderWindow& window, const int& positionX,const int& positionY)
{
	playedCase.setPosition(positionX,positionY);
	window.draw(playedCase);
}

void Boat::filled(sf::RenderWindow& window, const int& positionX,const int& positionY)
{ 
	filledCase.setPosition(positionX,positionY);
//	window.draw(filledCase);
}

void Boat::destroyed(sf::RenderWindow& window,const int& positionX,const int& positionY )
{
	explosion.setPosition(positionX,positionY);
	window.draw(explosion);		
}

void Boat::draw(sf::RenderWindow& window)
{
	
	for(int i = 0; i < boat.size() ; i++)
	{
		window.draw(boat[i].sprite);
	}
	
}
