#include "Munitions.hpp"

using namespace std;

Munitions::Munitions(float posX, float posY) {
    
    
    mun.setPosition(posX + TAILLEX / 2, posY);
    mun.setScale(Vector2f(1.5f, 1.5f));
    speed = 1.f;
}
void Munitions::move() {
    mun.move(0, speed);
}

float Munitions::getPosX() {
    return mun.getPosition().y;
}
