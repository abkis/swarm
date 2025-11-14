#include "obstacle.h"
#include "helpers.h"

Obstacle::Obstacle(sf::Vector2f &posn, sf::Vector2f &size, sf::Color color, float elastic) : posn{posn}, size{size}, elastic{elastic}

{
    shape.setSize(size);
    shape.setPosition(posn);
    shape.setFillColor(color);
}

Obstacle::Obstacle(Obstacle &obs) : posn{obs.get_posn()}, size{obs.get_size()}, shape{obs.get_shape()} {}

Obstacle::Obstacle(float x, float y, float w, float h, sf::Color color) : posn{x, y}, size{w, h}
{
    shape.setSize(size);
    shape.setPosition(posn);
    shape.setFillColor(color);
}

bool Obstacle::at_posn(const sf::RectangleShape test_shape) const
{
    return shape.getGlobalBounds().intersects(test_shape.getGlobalBounds());
}

// returns vector of force caused by collision by robot
// collision occurs at posn
// TODO: can change this for different types of objects, ex. ellastic ones or moving ones
// assume static for now
// J = (-(1+e)*v_n)/(1/m_r+1/m_o)
sf::Vector2f Obstacle::collision_force(const Robot &robot, sf::Vector2f posn) const
{
    sf::Vector2f vel = robot.get_vel(); // velocity before collision
    sf::Vector2f center = robot.get_posn();

    sf::Vector2f unit = normalize(center - posn);
    float norm = dot(vel, unit);
    float m = robot.get_mass();
    float impulse = -(1 + elastic) * norm * m;
    return (impulse / m) * unit;
}
