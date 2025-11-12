// spaceShooter6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "EnemyManager.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "Space");

    Player spaceShip;
    spaceShip.Load({ 960,1000 });
    EnemyManager enemies;

    sf::Clock clock;

    window.setVerticalSyncEnabled(true);
    // run the program as long as the window is open
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();

                if (keyPressed->scancode == sf::Keyboard::Scancode::E)
                {
                    enemies.SpawnEntity({ 400,0 });
                }
            }

            window.clear();
            window.draw(spaceShip);
            window.draw(enemies);
            window.display();
        }

        
    }
}


