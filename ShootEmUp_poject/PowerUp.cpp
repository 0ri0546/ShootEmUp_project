#include "PowerUp.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <SFML/Audio.hpp>

void PowerUp::cadenceDeTir() {
    //augmente les tirs par seconde
}
void PowerUp::upChargeur() {
    //augmente la capacit� du chargeur
}
void PowerUp::MultiShot() {
    //tire en diagonale
}
void PowerUp::bouclier() {
    //invincible pendant x secondes
}
void PowerUp::gel() {
    //arret du mouvement des ennemis
}

string PowerUp::getType() { return type; }
