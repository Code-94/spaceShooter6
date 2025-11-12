#pragma once

#include "Entity.h"

class Projectile : public Entity
{
public:
	void Move(float)override;
	void Load()override;
};

inline void Projectile::Move(float dt)
{
	rect_.setPosition(engine_.Move(dt));

	float angle = std::atan2(engine_.getDirection().x, -engine_.getDirection().y);
	rect_.setRotation(sf::radians(angle));
}

inline void Projectile::Load()
{
	Entity::Load("data\\sprite\\laserGreen03.png", { 0,-1 }, 600);
}