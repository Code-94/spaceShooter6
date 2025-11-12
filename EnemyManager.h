#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Projectile.h"
#include "EntityManager.h"

class EnemyManager : public EntityManager
{
public:
	void SpawnEntity(sf::Vector2f position)override
	{
		entities_.emplace_back(new Enemy());

		entities_.back()->Load();
		entities_.back()->setPosition(position);
	}
};
