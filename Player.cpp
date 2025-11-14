#include "Player.h"
#include <iostream>



void Player::Load(sf::Vector2f position) 
{
	texture.loadFromFile("data\\sprite\\playerShip3_red.png");
	engine_.setPosition(position);
	engine_ .setDirection({ 10,0 });
	engine_.setSpeed(700);

	rect_.setTexture(&texture);
	rect_.setSize({ static_cast<float>(texture.getSize().x), static_cast<float>(texture.getSize().y) });
	rect_.setOrigin({ static_cast<float>(texture.getSize().x) / 2.f, static_cast<float>(texture.getSize().y) });
}

void Player::Update(sf::RenderWindow& window, float dt)
{
	
	rect_.setPosition(engine_.Move(dt));

	//std::cout << "rect position: " << rect_.getPosition().x << "," << rect_.getPosition().y << std::endl;
	
	//rect_.setPosition({ 200,200 });
	projectileManager.Update(window, dt);
}

bool Player::CheckCollisions(std::vector<Entity*>& others)
{

	for (auto& other : others) {

		if (other->stillAlive == false)
		{
			continue;
		}

		if (rect_.getGlobalBounds().findIntersection(other->getBounds()))
		{
			other->stillAlive = false;
			return true;
		}
	}

	return false;

}
void Player::CheckProjectileCollisions(std::vector<Entity*>& others)
{

	auto bullets = projectileManager.getEntity();

	for (auto& bullet : bullets)
	{
		if (!bullet->stillAlive)
		{
			continue;
		}

		for (auto& other : others)
		{

			if (!other->stillAlive)
			{
				continue;
			}

			if (bullet->getBounds().findIntersection(other->getBounds()))
			{
				other->stillAlive = false;
				bullet->stillAlive = false;
			}
		}
	}


}
void Player::HandleEvent()
{

	sf::Vector2f direction = { 0,0 };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down))
	{
		direction.y = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up))
	{
		direction.y = -1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left))
	{
		direction.x = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Right)) {
		direction.x = 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::LShift))
		{
			
		}
		else
		{
			
			projectileManager.Spawn(rect_.getPosition());
		}

	}

	engine_.setDirection(direction);
}


void Player::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(projectileManager);
	target.draw(rect_);
}