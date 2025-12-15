#include "terrain.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "constants.h"
#include "objects/obstacles/static_obs.h"
#include "helpers.h"

Terrain::Terrain(float w, float h, int num_obstacles) : width{w}, height{h}
{
    // for now just make base class of obstacles, can make it more interesting later
    // make sure have more than one obstacle to make
    if (num_obstacles < 0)
    {
        std::cerr << "Cannot create negative number of obstacles. Will create none." << std::endl;
        return;
    }
    if (num_obstacles == 0)
    {
        return;
    }
    std::srand(std::time(0)); // seed randomness

    // loop for making obstacles
    int max_loops = MAX_TRIES;
    for (int i = 0; i < num_obstacles; ++i)
    {
        if (max_loops < 0)
        {
            std::cerr << "Not enough space for all obstacles. End loop after " << obstacles.size() << " obstacles." << std::endl;
            break;
        }
        float x = static_cast<float>(rand()) / width;
        float y = static_cast<float>(rand()) / height;
        sf::Vector2f posn{x, y};

        float obs_w = static_cast<float>(rand() / MAX_OBS_W);
        float obs_h = static_cast<float>(rand() / MAX_OBS_H);
        sf::Vector2f size{obs_w, obs_h};
        sf::RectangleShape rect{size};
        rect.setPosition(posn);

        for (auto &obs : obstacles)
        {
            // make sure no overlap with obstacles
            if (obs->at_posn(rect))
            {
                --i;
                continue;
            }
        }
        // no intersection so ok
        obstacles.push_back(std::make_unique<StaticObs>(posn, size, sf::Color::Red));
        --max_loops;
    }
}

// returns distance to oject if in sensor range. If no object returns -1
// seeks in direction vector dir for total length (euclidean 2-norm) range starting at position posn
float Terrain::cast_ray(sf::Vector2f posn, sf::Vector2f dir, float range) const
{
    for (auto &obs : obstacles)
    {
        if (obs->at_posn(posn, dir, range))
        {
            return true;
        }
    }
    for (auto &obs : robots)
    {
        if (obs->at_posn(posn, dir, range))
        {
            return true;
        }
    }
    return false;
}

// called by neighbor_sensor
// finds neighboring robots to current robot within a specific radius given by "range"
// returns vector of ptrs to found robots
std::vector<Robot *> Terrain::find_neighbors(sf::Vector2f posn, float range) const
{
    std::vector<Robot *> found_robots;
    for (auto &robot : robots)
    {
        // go thru all robots in terrain and check distance
        auto loc = robot->get_posn();
        float dist = helpers::dist(posn, loc);
        if (dist <= range)
        {
            found_robots.push_back(robot.get());
        }
    }
    return found_robots;
}