#pragma once
#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "ProjectileManager.h"

class Player : public sf::Drawable 
{
	sf::Texture texture;
	sf::RectangleShape rect_;

	Engine engine_;

	ProjectileManager projectileManager;
	
	


public:
	void Load(sf::Vector2f);
	void HandleEvent();
	void Update(sf::RenderWindow&, float);
	bool CheckCollisions(std::vector<Entity*>& others);
	void CheckProjectileCollisions(std::vector<Entity*>& others);

	void setPosition(sf::Vector2f);


protected:
	void draw(sf::RenderTarget&, sf::RenderStates)const override;
};