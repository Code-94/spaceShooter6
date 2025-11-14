#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Projectile.h"
#include "Asteroid.h"

class EntityManager : public sf::Drawable
{
public:
	virtual void SpawnEntity(sf::Vector2f) = 0;
	void Update(const sf::RenderWindow&, float dt);
	std::vector<Entity*>& getEntity();

protected:
	std::vector<Entity*> entities_;
	void draw(sf::RenderTarget&, sf::RenderStates) const override;

};


