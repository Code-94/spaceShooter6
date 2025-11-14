#pragma once
#include "EntityManager.h"
#include "Enemy.h"
#include "Projectile.h"


class AsteroidManager : public EntityManager
{
public:
	void SpawnEntity(sf::Vector2f position)override
	{
		entities_.emplace_back(new Asteroid());

		entities_.back()->Load();
		entities_.back()->setPosition(position);
	}
};