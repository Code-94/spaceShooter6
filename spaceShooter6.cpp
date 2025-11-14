// spaceShooter6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "EnemyManager.h"
#include "AsteroidManager.h"
#include <random>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "Space");

    std::mt19937 gen(static_cast<unsigned int>(std::time(nullptr)));

    std::uniform_int_distribution<> distribX(0, 1920);
    // Les positions Y peuvent aller de 0 à la hauteur de la fenêtre
    std::uniform_int_distribution<> distribY(0, 1080);

    Engine engine;
   


    Player spaceShip;
    spaceShip.Load({ 960,1000 });
    EnemyManager enemies;
    AsteroidManager meteor;
    
    sf::Clock clock;

    window.setVerticalSyncEnabled(true);
    // run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Time delta = clock.restart();
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

                /*if (keyPressed->scancode == sf::Keyboard::Scancode::E)
                {
                    enemies.SpawnEntity({ 400,0 });
                }*/

                float randomX = static_cast<float>(distribX(gen));
                float randomY = static_cast<float>(distribY(gen));

                // Définir la nouvelle position du sprite
                enemies.SpawnEntity({ randomX, randomY });
                //enemies.SpawnEntity({ 400,0 });
            }
            
            
        }
        
        
        spaceShip.HandleEvent();
        spaceShip.CheckCollisions(enemies.getEntity());
        
        spaceShip.CheckProjectileCollisions(enemies.getEntity());

        spaceShip.HandleEvent();

        window.clear(sf::Color::Black);

        spaceShip.Update(window,delta.asSeconds());
        enemies.Update(window, delta.asSeconds());
        
        
        
        window.draw(spaceShip);
        window.draw(meteor);
        //meteor.Update(window, delta.asSeconds());
        window.draw(enemies);
        
        window.display();

        
    }
}


