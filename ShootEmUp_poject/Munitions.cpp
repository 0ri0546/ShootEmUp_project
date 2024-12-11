#include "Munitions.hpp"

using namespace std;

Munitions::Munitions(float posX, float posY) {
    textureMun.loadFromFile("fleche1.png");
    mun.setTexture(textureMun);
    mun.setPosition(posX + TAILLEX / 2, posY);
    mun.setScale(Vector2f(3.f, 3.f));
    speed = 1.f;
}
void Munitions::move() {
    mun.move(0, speed);
}

float Munitions::getPosX() {
    return mun.getPosition().y;
}
