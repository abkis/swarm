#pragma once
#include <SFML/Graphics.hpp>

float mag(sf::Vector2f vec);

sf::Vector2f normalize(sf::Vector2f vec);

float dot(sf::Vector2f a, sf::Vector2f b);

sf::Vector2f cap_speed(sf::Vector2f vec, float max_speed);