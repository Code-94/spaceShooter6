#pragma once

#include "Entity.h"
#include <iostream>
class Enemy : public Entity
{
public:
	void Move(float)override;
	void Load()override;
	
};

inline void Enemy::Move(float dt)
{
	rect_.setPosition(engine_.Move(dt));
	std::cout << "rect position: " << rect_.getPosition().x << "," << rect_.getPosition().y << std::endl;
}

inline void Enemy::Load()
{
	Entity::Load("data\\sprite\\enemyBlack3.png", { 0,1 }, 300);
}
