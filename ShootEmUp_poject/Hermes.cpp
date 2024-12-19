#include "Hermes.hpp"

void Hermes::deplacement() {
}
void Hermes::attaque(RectangleShape& rectangle, RenderWindow& window, int spriteAnimation, Texture& texture) {
    mun.push_back(Munitions(hermes.getPosition().x, hermes.getPosition().y));
    for (auto it = mun.begin(); it != mun.end(); ) {
        window.draw(it->mun);
        it->mun.move(0.f, 10.f);
        if (it->mun.getPosition().y + texture.getSize().y + 20 < 0) { it = mun.erase(it); }
        else { ++it; }
    }
}
void Hermes::incr_score() {}
void Hermes::drop() {}

void Hermes::depEnnemisRight(vector<Hermes>& ennemis, int velocity) { //deplace les ennemis dans le vecteur hermes en diagonale, et rebondi sur tous les wall
    static vector<int> directions(ennemis.size(), 1);
    static vector<int> verticalDirections(ennemis.size(), 1);
    static vector<float> delays(ennemis.size(), 0);
    float delayBetweenEnemies = 0.3f;
    float vitesse = 1.f * velocity;
    for (size_t i = 0; i < ennemis.size(); ++i) {
        Hermes& ennemi = ennemis[i];
        Vector2f position = ennemi.hermes.getPosition();

        if (delays[i] < i * delayBetweenEnemies) { delays[i] += vitesse; continue; }
        ennemi.hermes.move(vitesse * -directions[i], vitesse * verticalDirections[i]);
        if (position.x + vitesse >= WIDTH - ennemi.hermes.getGlobalBounds().width) { directions[i] = 1; }
        else if (position.x - vitesse <= 0) { directions[i] = -1; }
        if (position.y + vitesse >= HEIGHT / 2) { verticalDirections[i] = -1; }
        else if (position.y <= 0) { verticalDirections[i] = 1; }
    }
}

void Hermes::creerEnnemis(vector<Hermes>& hermes, int ennemis, float x, float y) { // creer N ennemis
    if (!hermesText.loadFromFile("Kratosidle.png")) {}
    int z = 30;
    for (int i = 0; i < ennemis; ++i) {
        z += 50;
        hermes.push_back(Hermes(x + z, y, hermesText));
    }
}

void Hermes::patern( vector<Hermes>& hermes, float x, float y, float moveToX, float moveToY, float velocity) { // deplace tous les ennemis du vector hermes vers un point ddonné
    for (size_t i = 0; i < hermes.size(); ++i) {
        Hermes& ennemi = hermes[i];
        Vector2f position = ennemi.hermes.getPosition();
        Vector2f direction(moveToX - position.x, moveToY - position.y);
        float length = sqrt(direction.x * direction.x + direction.y * direction.y);
        if (length != 0) { direction.x /= length; direction.y /= length; }
        ennemi.hermes.move(direction.x * velocity, direction.y * velocity);
        if (abs(moveToX - position.x) < velocity && abs(moveToY - position.y) < velocity) { ennemi.hermes.setPosition(moveToX, moveToY); }
    }
}

void Hermes::setVies(int nouvelleVies) { vies = nouvelleVies; }
int Hermes::getVies() { return vies; }