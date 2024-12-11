#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <SFML/Audio.hpp>
#include <ctime>

using namespace std;
using namespace sf;

class Obstacle {
private:
    float x, y;
    int index;
public:
    Obstacle(float x, float y, int index);
    void move(float speed);
    vector<Obstacle> obs;
};

#endif