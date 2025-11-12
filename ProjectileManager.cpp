#include "Projectile.h"
#include "ProjectileManager.h"

void ProjectileManager::SpawnEntity(sf::Vector2f position)
{
	entities_.emplace_back(new Projectile());

	entities_.back()->Load();
	entities_.back()->setPosition(position);
}

void ProjectileManager::Spawn(sf::Vector2f position)
{
	SpawnEntity(position);
}

void ProjectileManager::Spawn(sf::Vector2f position, sf::Vector2f direction)
{
	SpawnEntity(position);
	entities_.back()->setPosition(direction);
}