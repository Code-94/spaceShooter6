#include "Engine.h"

Engine::Engine()
{
	position_ = { 0,0 };
	direction_ = { 0,0 };
	speed_ = 0;
}

void Engine::setPosition(sf::Vector2f position)
{
	position_ = position;
}

void Engine::setDirection(sf::Vector2f dir)
{
	direction_ = dir;
}

void Engine::setSpeed(float s)
{
	speed_ = s;
}

sf::Vector2f Engine::getDirection()
{
	return direction_;
}

sf::Vector2f Engine::Move(float deltaTimeSec)
{
	if (direction_.length() > 0)
	{
		position_ += deltaTimeSec * speed_ * direction_.normalized();
	}
	return position_;
}