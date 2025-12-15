#include "objects/robots/robot.h"
#include "helpers.h"
#include <cmath>

Robot::Robot(float v_x, float v_y, float p_x, float p_y, float size_x, float size_y, float direction, float mass, float max_speed, float speed_incr, int id, sf::Color color) : Object(p_x, p_y, size_x, size_y, color), max_speed{max_speed}, id{id},
                                                                                                                                                                                speed_incr{speed_incr}, mass{mass}, direction{direction}
{
    vel = helpers::cap_speed({v_x, v_y}, max_speed);
}

// update sensors after robot movement
void Robot::update_sensor(const Terrain &terrain)
{
    for (auto &s : sensors)
    {
        s->update(*this, terrain);
    }
}

void Robot::add_sensor(std::unique_ptr<Sensor> s)
{
    sensors.push_back(std::move(s));
}

void Robot::transmit_info(const std::weak_ptr<NeighborSensor> sensor) const
{
    // update neighbors
    auto neighbors = sensor.lock()->get_neighbors();
    for (auto &neighbor : neighbors)
    {
        neighbor->update_from_robot(*this);
    }
}

void Robot::on_collision(sf::Vector2f force)
{
    // changes velocity
    vel = helpers::cap_speed(vel + force, max_speed);
}

// increase speed in velocity direction
void Robot::increase_speed()
{
    float mag = helpers::mag(vel);
    if (mag == 0)
    {
        // not moving in any direction
        // use "direction" to describe xy movements
        // result is unit vector, no extra speed incr needed
        vel.x = cos(direction);
        vel.y = sin(direction);
    }
    else if (mag > max_speed)
    {
        vel = helpers::cap_speed(vel, max_speed); // shouldn't be allowed to go that fast
    }
    else if (mag < max_speed)
    {
        vel *= speed_incr; // incr by appropriate amount
        vel = helpers::cap_speed(vel, max_speed);
    }
}
