#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <iostream>

class Asteroid : public Entity {
public:
	void Move(float) override;
	void Load() override;


};

inline void Asteroid::Move(float dt)
{
	rect_.setPosition(engine_.Move(dt));
	std::cout << "rect position: " << rect_.getPosition().x << "," << rect_.getPosition().y << std::endl;
}

inline void Asteroid::Load()
{
	Entity::Load("data\\sprite\\meteorGrey_big2.png", { 0,1 }, 200);
}