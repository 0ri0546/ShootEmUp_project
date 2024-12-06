#include "EnnemiFaible.hpp"

void EnnemiFaible::deplacement() {
    //les ennemis se deplacent en 'X'
}
void EnnemiFaible::attaque() {
    //attaque tout droit, rapidement
}
void EnnemiFaible::incr_score() {
    //retourne true si vies = 0
    //detruit l'ennemi
}
void EnnemiFaible::drop() {
    //un pourcentage de chance de drop un powerUp
}
void EnnemiFaible::setVies(int nouvelleVies) { vies = nouvelleVies; }
int EnnemiFaible::getVies() { return vies; }