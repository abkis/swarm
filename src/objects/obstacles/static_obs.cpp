#include "objects/obstacles/static_obs.h"
#include "helpers.h"

StaticObs::StaticObs(sf::Vector2f &posn, sf::Vector2f &size, sf::Color color, float elastic) : Obstacle(posn, size, color), elastic{elastic} {}

StaticObs::StaticObs(Obstacle &obs, float e) : Obstacle(obs), elastic{e} {}

StaticObs::StaticObs(float x, float y, float w, float h, sf::Color color, float e) : Obstacle(x, y, w, h, color), elastic{e} {}

// returns vector of force caused by collision by robot
// collision occurs at posn
// TODO: can change this for different types of objects, ex. ellastic ones or moving ones
// assume static for now
// J = (-(1+e)*v_n)/(1/m_r+1/m_o)
sf::Vector2f StaticObs::collision_force(const Robot &robot, sf::Vector2f posn) const
{
    sf::Vector2f vel = robot.get_vel(); // velocity before collision
    sf::Vector2f center = robot.get_posn();

    sf::Vector2f unit = helpers::normalize(center - posn);
    float norm = helpers::dot(vel, unit);
    float m = robot.get_mass();
    float impulse = -(1 + elastic) * norm * m;
    return (impulse / m) * unit;
}