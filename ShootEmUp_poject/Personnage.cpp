#include "Personnage.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <SFML/Audio.hpp>
using namespace sf;


<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes

void Personnage::deplacement() {
    //D�placement : Le personnage se d�place uniquement gr�ce au clic de la souris, dans un style hack n slash.
    //set le sprite de move pour une animation de deplacement
}
void Personnage::attaque() {
    //Tir automatique en maintenant une touche ou un bouton enfonc� jusqu'� ce que le nombre de charge soit vide.
}
void Personnage::ult() {
    //Saute sur les ennemis avec un gros marteau, fait des degats de zone. invincible durant cette p�riode.

}
void Personnage::creerPieceRectangle(RectangleShape& rectangle,Color& color, int longueur, int largeur, int x, int y) {
    rectangle.setSize(Vector2f(longueur, largeur));
    rectangle.setFillColor(color);
    rectangle.setOutlineColor(Color::Black);
    rectangle.setOutlineThickness(3);
    rectangle.setPosition(x, y);
}
void Personnage::setVies(int nouvelleVie) { vies = nouvelleVie; }
void Personnage::setMunitions(int nouvelleMunition) { munitions = nouvelleMunition; }
void Personnage::setTauxUtlime(int NouveauTauxUlt) { tauxUtlime = NouveauTauxUlt; }

int Personnage::getVies() { return vies; }
int Personnage::getMunitions() { return munitions; }
float Personnage::getTauxUltime() { return tauxUtlime; }