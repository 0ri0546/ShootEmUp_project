#include "Munitions.hpp"

using namespace std;

Munitions::Munitions(float posX, float posY) {
    textureMun.loadFromFile("munition.png");
    mun.setTexture(textureMun);
    mun.setPosition(posX + TAILLEX / 2, posY);
    mun.setScale(Vector2f(0.1f, 0.1f));
    speed = 1.f;
}
void Munitions::move() {
    mun.move(0, speed);
}

float Munitions::getPosX() {
    return mun.getPosition().y;
}
