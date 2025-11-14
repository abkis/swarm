#pragma once
#include "sensors/sensor.h"
#include "terrain.h"

// base class for robot; simplest kind
class Robot
{
    float velocity_x{0}, velocity_y{0}; // speed of movement in x/y direction
    sf::Vector2f posn;                  // position in xy plane
    float direction{0};                 // direction robot is in, in radians
    float size{1};                      // size of robot, radius/width/etc depending on type
    std::vector<std::unique_ptr<Sensor>> sensors;

    void on_collision();                        // handles when robot collides with something
    void check_collision();                     // checks if robot collided with something
    void update_sensor(const Terrain &terrain); // update sensors after movement
public:
    Robot(float v_x, float v_y, float p_x, float p_y, float size, float direction);
    void random_movement();                          // move in random manner
    void add_sensor(std::unique_ptr<Sensor> sensor); // add new sensor

    inline float get_direction() const { return direction; };
    inline sf::Vector2f get_posn() const { return posn; };
};