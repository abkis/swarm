#include "robots/robot.h"

Robot::Robot(float v_x, float v_y, float p_x, float p_y, float size, float direction) : velocity_x{v_x}, velocity_y{v_y},
                                                                                        posn{p_x, p_y}, size{size > 0 ? size : 1}, direction{direction} {}

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

void Robot::random_movement()
{
}
