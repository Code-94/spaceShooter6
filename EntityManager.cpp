#include "EntityManager.h"


void EntityManager::Update(const sf::RenderWindow& window, float dt)
{
	erase_if(entities_, [&window](Entity* p)
		{
			return p->getPosition().y < 0 || p->getPosition().y > window.getSize().y || p->stillAlive == false;
		}
	);

	for (auto& entity : entities_)
	{
		entity->Move(dt);
	}
}



std::vector<Entity*>& EntityManager::getEntity()
{
	return entities_;
}

void EntityManager::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	for (auto& projectile : entities_)
	{
		target.draw(*projectile);
	}
}
