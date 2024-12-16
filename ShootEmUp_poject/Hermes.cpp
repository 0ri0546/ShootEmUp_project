#include "Hermes.hpp"

void Hermes::deplacement() {
    //les ennemis se deplacent en 'X'
}
void Hermes::attaque(RectangleShape& rectangle, RenderWindow& window, int spriteAnimation) {
    
    mun.push_back(Munitions(hermes.getPosition().x, hermes.getPosition().y));
    
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
void Hermes::incr_score() {
    //retourne true si vies = 0
    //detruit l'ennemi
}
void Hermes::drop() {
    //un pourcentage de chance de drop un powerUp
}

void Hermes::depEnnemisRight(vector<Hermes>& ennemis, int velocity) {
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

void Hermes::paterns(vector<Hermes>& hermes, int ennemis) {
    srand((unsigned)time(0));
    if (!hermesText.loadFromFile("Kratosidle.png")) {}
    for (int i = 0; i < ennemis; ++i) {
        hermes.push_back(Hermes(rand() % WIDTH, rand() % HEIGHT / 2, hermesText));
    }
}

void Hermes::setVies(int nouvelleVies) { vies = nouvelleVies; }
int Hermes::getVies() { return vies; }