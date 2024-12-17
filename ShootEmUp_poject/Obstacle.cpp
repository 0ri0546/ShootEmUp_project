#include "Obstacle.hpp"

Obstacle::Obstacle(float x, float y, float width, float height, float speed, const Texture *texture) : speed(speed) {
    shape.setSize(Vector2f(width, height));
    shape.setPosition(x, y);
    shape.setTexture(texture);
}

void Obstacle::move() {
    shape.move(0, speed);
}

bool Obstacle::estDansLesLimites(float windowHeight) {
    return shape.getPosition().y > windowHeight;
}
