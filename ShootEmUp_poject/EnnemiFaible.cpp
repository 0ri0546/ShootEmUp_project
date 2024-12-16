#include "EnnemiFaible.hpp"

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

        //window.draw(it->mun);

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
void Hermes::setVies(int nouvelleVies) { vies = nouvelleVies; }
int Hermes::getVies() { return vies; }