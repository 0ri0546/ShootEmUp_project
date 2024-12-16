#include "Obstacle.hpp"

Obstacle::Obstacle(float x, float y, float width, float height, float speed, Color color) : speed(speed) {
    shape.setSize(Vector2f(width, height));
    shape.setPosition(x, y);
    shape.setFillColor(color);
}

void Obstacle::move() {
    shape.move(0, speed);
}

bool Obstacle::isOutOfBounds(float windowHeight) {
    return shape.getPosition().y > windowHeight;
}