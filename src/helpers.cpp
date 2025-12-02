#include "helpers.h"
#include <cmath>

// return magnitude of vector
float mag(const sf::Vector2f vec)
{
    return sqrt(vec.x * vec.x + vec.y * vec.y);
}

// return unit vector
sf::Vector2f normalize(const sf::Vector2f vec)
{
    float magn = mag(vec);
    if (magn == 0)
    {
        return vec;
    }
    return {vec.x / magn, vec.y / magn};
}

// return dot product of vectors
float dot(const sf::Vector2f a, const sf::Vector2f b)
{
    return a.x * b.x + a.y * b.y;
}

// cap speed: magnitude of vec must be <= max_speed
sf::Vector2f cap_speed(const sf::Vector2f vec, float max_speed)
{
    float magn = mag(vec);
    if (magn <= max_speed)
    {
        return vec;
    }
    return (max_speed / magn) * vec;
}