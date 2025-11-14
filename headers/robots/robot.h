#pragma once
#include "sensors/sensor.h"
#include "sensors/neighbor_sensor.h"
#include "terrain.h"

// base class for robot; simplest kind
class Robot
{
    sf::Vector2f vel;       // velocity of movement in x/y direction
    const float max_speed;  // speed of max movement
    const float speed_incr; // amount magnitude of velocity can increase by per time step
    sf::Vector2f posn;      // position in xy plane of robot center
    float direction{0};     // direction robot is moving in, in radians
    float size{1};          // size of robot, radius/width/etc depending on type
    float mass{1};
    std::vector<std::unique_ptr<Sensor>> sensors;

    void on_collision(sf::Vector2f force);      // handles when robot collides with something
    void check_collision();                     // checks if robot collided with something
    void update_sensor(const Terrain &terrain); // update sensors after movement
    void increase_speed();                      // increase robot speed (if possible)

public:
    Robot(float v_x, float v_y, float p_x, float p_y, float size, float direction, float mass, float max_speed, float speed_incr);
    void random_movement();                          // move in random manner
    void add_sensor(std::unique_ptr<Sensor> sensor); // add new sensor

    inline float get_direction() const { return direction; };
    inline sf::Vector2f get_posn() const { return posn; };
    inline sf::Vector2f get_vel() const { return vel; };
    inline float get_mass() const { return mass; }

    void update(const Sensor &sensor, const Terrain &terrain); // update robot info using sensor
    void update_from_robot(const Robot &robot);                // update robot info from another robot

    void transmit_info(const std::weak_ptr<NeighborSensor> sensor) const; // transmit info to neighbors
};