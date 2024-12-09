#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <SFML/Audio.hpp>
#include <SFML/Window/Mouse.hpp>

#include "Datas.hpp"
#include "Munitions.hpp"

using namespace std;
using namespace sf;

class Personnage {
    int vies;
    int munitions;
    float tauxUtlime;
    float speed = 1.0f;
public:
    float x, y;
    vector<Munitions> mun;
    Font font;
    
    Personnage();
    Personnage(int vies, int munitions, float tauxUltime, float x, float y);
    void deplacement(RectangleShape& rectangle, Event event, RenderWindow& window);
    void attaque(RectangleShape& rectangle, Event event, RenderWindow& window, int spriteAnimation);
    void ult(RectangleShape& rectangle, Event event, RenderWindow& window);
    void setTexture(RectangleShape& rectangle, const Texture *texture);
    void setVies(int nouvelleVie);
    void setMunitions(int nouvelleMunition);
    void setTauxUtlime(float NouveauTauxUlt);
    int getVies();
    int getMunitions();
    float getTauxUltime(); 
    void creerPieceRectangle(RectangleShape& rectangle,Color color, int longueur, int largeur, float x, float y);
    void creerText(Text& text, const std::string& texte, int charSize, const sf::Color& color, float x, float y, Font& font);
    float getPositionX();
    float getPositionY();
};

#endif