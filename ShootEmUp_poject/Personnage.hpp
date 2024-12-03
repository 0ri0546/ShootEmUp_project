#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP



#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class Personnage {
    int vies;
    int munitions;
    float tauxUtlime;

    float x, y;

    sf::Sprite perso;
    float speed;

    Personnage(float startX, float startY, const Texture &texture) {
        perso.setTexture(texture);
        perso.setFillColor(sf::Color::Blue);
        perso.setPosition(startX, startY);
        perso = 5.f;
    }


    int x, y;
public:
    sf::Sprite perso;
    float speed;

    Personnage(float startX, float startY, const Texture& texture) {
        perso.setTexture(texture);
        
        perso.setOrigin(startX, startY);
        speed: 5.f;
    }

    void deplacement();
    void attaque();
    void ult();
    void setVies(int nouvelleVie);
    void setMunitions(int nouvelleMunition);
    void setTauxUtlime(int NouveauTauxUlt);
    int getVies();
    int getMunitions();
    float getTauxUltime(); 
    void creerPieceRectangle(RectangleShape& rectangle,Color& color, int longueur, int largeur, int x, int y);
};


#endif