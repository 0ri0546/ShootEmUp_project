#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <SFML/Audio.hpp>
#include <SFML/Window/Mouse.hpp>

#include "Jeu.hpp"

using namespace std;
using namespace sf;

class Personnage {
    int vies;
    int munitions;
    float tauxUtlime;
    float x, y;
    float speed = 1.0f;
public:
    Personnage();
    Personnage(int vies, int munitions, float tauxUltime, float x, float y);
    void deplacerVers(RectangleShape& rectangle, Event event, RenderWindow& window);
    void deplacement(RectangleShape& rectangle,Event event, RenderWindow& window);
    void attaque();
    void ult();
    void setVies(int nouvelleVie);
    void setMunitions(int nouvelleMunition);
    void setTauxUtlime(float NouveauTauxUlt);
    int getVies();
    int getMunitions();
    float getTauxUltime(); 
    void creerPieceRectangle(RectangleShape& rectangle,Color color, int longueur, int largeur, float x, float y);
};

#endif