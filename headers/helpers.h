#pragma once
#include <SFML/Graphics.hpp>

float mag(const sf::Vector2f vec);

sf::Vector2f normalize(const sf::Vector2f vec);

float dot(const sf::Vector2f a, const sf::Vector2f b);

sf::Vector2f cap_speed(const sf::Vector2f vec, float max_speed);