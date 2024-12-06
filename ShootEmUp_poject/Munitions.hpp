#ifndef MUNITIONS_HPP
#define MUNITIONS_HPP

#include "Datas.hpp"

using namespace std;
using namespace sf;

class Munitions {
public:
    Texture textureMun;
    Sprite mun;
    float speed;
    Munitions(float posX, float posY);
    void move();
    float getPosX();
};

#endif