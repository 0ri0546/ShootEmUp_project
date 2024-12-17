#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP
#include "Personnage.hpp"

using namespace std;
using namespace sf;

class Obstacle {
public:
    RectangleShape shape;
    Texture obstacleTexture;
    float speed;
    Obstacle(float x, float y, float width, float height, float speed, const Texture *texture);
    void move();
    bool estDansLesLimites(float windowHeight);
};

#endif