#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP
#include "Personnage.hpp"

using namespace std;
using namespace sf;

class Obstacle {
public:
    RectangleShape shape;
    float speed;
    Obstacle(float x, float y, float width, float height, float speed, Color color);
    void move();
    bool isOutOfBounds(float windowHeight);
};

#endif