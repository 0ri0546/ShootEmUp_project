#include "Poseidon.hpp"

using namespace sf;




void Poseidon::deplacement(int velocity) {
    static Vector2f targetPosition = rectangle.getPosition();
    static sf::Clock clock;
    float velocity = 200.f;
    const float stopThreshold = 5.f;
    const float maxX = WIDTH;
    const float maxY = HEIGHT / 2.f;

    if (Mouse::isButtonPressed(Mouse::Left)) {
        Vector2i posMouse = Mouse::getPosition(window);
        if (posMouse.x > 0 && posMouse.x < WIDTH && posMouse.y > 0 && posMouse.y < HEIGHT) {
            targetPosition = Vector2f(posMouse) - Vector2f(TAILLEX / 2, TAILLEY / 2);
            if (targetPosition.y < 0) targetPosition.y = 0;
            if (targetPosition.y < maxY) targetPosition.y = maxY;
        }
    }
    float deltaTime = clock.restart().asSeconds();

    Vector2f currentPosition = rectangle.getPosition();
    Vector2f direction = targetPosition - currentPosition;
    float distance = sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance > stopThreshold) {
        direction /= distance;
        rectangle.move(direction * velocity * deltaTime);
    }
    else {
        rectangle.setPosition(targetPosition);
    }
}
void Poseidon::depEnnemisRight(vector<Poseidon>& pose, int velocity) { //deplace les ennemis dans le vecteur hermes en diagonale, et rebondi sur tous les wall
    static vector<int> directions(pose.size(), 1);
    static vector<int> verticalDirections(pose.size(), 1);
    static vector<float> delays(pose.size(), 0);
    float delayBetweenEnemies = 0.3f;
    float vitesse = 1.f * velocity;
    for (size_t i = 0; i < pose.size(); ++i) {
        Poseidon& pose = pose[i];
        Vector2f position = pose.getPosition();

        if (delays[i] < i * delayBetweenEnemies) { delays[i] += vitesse; continue; }
        pose.hermes.move(vitesse * -directions[i], vitesse * verticalDirections[i]);
        if (position.x + vitesse >= WIDTH - pose.hermes.getGlobalBounds().width) { directions[i] = 1; }
        else if (position.x - vitesse <= 0) { directions[i] = -1; }
        if (position.y + vitesse >= HEIGHT / 2) { verticalDirections[i] = -1; }
        else if (position.y <= 0) { verticalDirections[i] = 1; }
    }
}
void Poseidon::attaque(RectangleShape& rectangle, RenderWindow& window, int spriteAnimation) {

    mun.push_back(Munitions(poseidon.getPosition().x, poseidon.getPosition().y));

    for (auto it = mun.begin(); it != mun.end(); ) {
        Texture test;

        if (spriteAnimation <= 10) { test.loadFromFile("fleche1.png"); }
        else if (spriteAnimation <= 20) { test.loadFromFile("fleche2.png"); }
        else if (spriteAnimation <= 30) { test.loadFromFile("fleche3.png"); }
        else if (spriteAnimation <= 40) { test.loadFromFile("fleche4.png"); }
        else if (spriteAnimation <= 50) { test.loadFromFile("fleche5.png"); }
        else if (spriteAnimation <= 60) { test.loadFromFile("fleche6.png"); }
        else if (spriteAnimation <= 70) { test.loadFromFile("fleche7.png"); }
        it->mun.setTexture(test);

        window.draw(it->mun);
        it->mun.move(0.f, 10.f);

        if (it->mun.getPosition().y + test.getSize().y + 20 < 0) { it = mun.erase(it); }
        else { ++it; }
    }
}

void Poseidon::ult(RectangleShape& rectangle, Event event, RenderWindow& window) {
    //Saute sur les ennemis avec un gros marteau, fait des degats de zone. invincible durant cette période.
    cout << "ultime !" << endl;
    if (rectangle.getPosition().y > 20)
    {
        rectangle.move(0.f, -10.f);
    }
    else if (rectangle.getPosition().y <= 20)
    {
        // kill dans un rayon de 20
    }
}

void Poseidon::setTexture(RectangleShape& rectangle, const Texture* texture) {
    //Saute sur les ennemis avec un gros marteau, fait des degats de zone. invincible durant cette période.
    rectangle.setTexture(texture);
}




void Poseidon::setVies(int nouvelleVie) { vies = nouvelleVie; }
void Poseidon::setMunitions(int nouvelleMunition) { munitions = nouvelleMunition; }
void Poseidon::setTauxUtlime(float NouveauTauxUlt) { tauxUtlime = NouveauTauxUlt; }

int Poseidon::getVies() { return vies; }
int Poseidon::getMunitions() { return munitions; }

float Poseidon::getPositionX() { return x; }
float Poseidon::getPositionY() { return y; }