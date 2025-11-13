#pragma once
// base class for robot; simplest kind
class Robot
{
    float velocity_x{0}, velocity_y{0}; // speed of movement in x/y direction
    float posn_x{0}, posn_y{0};         // position in xy plane
    float size{1};                      // size of robot, radius/width/etc depending on type
    float sensor_range{1};              // radius range of sensor

    void on_collision();    // handles when robot collides with something
    void check_collision(); // checks if robot collided with something
public:
    Robot(float v_x, float v_y, float p_x, float p_y, float size = 1, float sensor = 1);
    void random_movement(); // move in random manner
};