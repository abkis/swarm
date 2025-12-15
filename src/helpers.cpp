#include "helpers.h"
#include <cmath>

// return magnitude of vector
float helpers::mag(const sf::Vector2f vec)
{
    return sqrt(vec.x * vec.x + vec.y * vec.y);
}

// return unit vector
sf::Vector2f helpers::normalize(const sf::Vector2f vec)
{
    float magn = helpers::mag(vec);
    if (magn == 0)
    {
        return vec;
    }
    return {vec.x / magn, vec.y / magn};
}

// return dot product of vectors
float helpers::dot(const sf::Vector2f a, const sf::Vector2f b)
{
    return a.x * b.x + a.y * b.y;
}

// cap speed: magnitude of vec must be <= max_speed
sf::Vector2f helpers::cap_speed(const sf::Vector2f vec, float max_speed)
{
    float magn = helpers::mag(vec);
    if (magn <= max_speed)
    {
        return vec;
    }
    return (max_speed / magn) * vec;
}

// return distance bw posn1 and posn2 using euclidean two-norm
float helpers::dist(const sf::Vector2f posn1, const sf::Vector2f posn2)
{
    return helpers::mag(posn2 - posn1);
}
