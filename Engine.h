#pragma once
#include <SFML/Graphics.hpp>
class Engine {
	sf::Vector2f position_;
	sf::Vector2f direction_;
	float speed_;

public:
	Engine();
	void Load();
	void setPosition(sf::Vector2f);
	void setDirection(sf::Vector2f);
	sf::Vector2f getDirection();
	void setSpeed(float);

	sf::Vector2f Move(float deltaTimeSec);
	
};