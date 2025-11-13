#include "terrain.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "constants.h"

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
        obstacles.push_back(std::make_unique<Obstacle>(posn, size, sf::Color::Red));
        --max_loops;
    }
}