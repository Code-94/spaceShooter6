#include "Entity.h"

void Entity::Load(std::string_view pathFile, sf::Vector2f dir, float speed)
{
	texture.loadFromFile(pathFile);
	engine_.setDirection(dir);
	engine_.setSpeed(speed);

	rect_.setTexture(&texture);
	rect_.setSize({ static_cast<float>(texture.getSize().x), static_cast<float>(texture.getSize().y) });
	rect_.setOrigin({ static_cast<float>(texture.getSize().x) / 2.f, static_cast<float>(texture.getSize().y) });
}

void Entity::setPosition(sf::Vector2f position)
{
	engine_.setPosition(position);
}

sf::Vector2f Entity::getPosition()
{
	return rect_.getPosition();
}

void Entity::setDirection(sf::Vector2f direction)
{
	engine_.setDirection(direction);
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates state)const
{
	if (stillAlive) {
		target.draw(rect_, state);
	}
}

sf::FloatRect Entity::getBounds()
{
	return rect_.getGlobalBounds();
}