#pragma once
#include <SFML/Graphics.hpp>
#include "Engine.h"

class Entity : public sf::Drawable
{
	sf::Texture texture;

protected:
	Engine engine_;
	sf::RectangleShape rect_;
	void Load(std::string_view, sf::Vector2f, float);

public:
	void setPosition(sf::Vector2f);
	sf::Vector2f getPosition();

	void setDirection(sf::Vector2f);

	virtual void Move(float) = 0;
	virtual void Load() = 0;
	sf::FloatRect getBounds();

	bool stillAlive = true;

protected:
	void draw(sf::RenderTarget&, sf::RenderStates)const override;
	
};