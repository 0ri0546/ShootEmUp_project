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
#include "Hermes.hpp"

using namespace std;
using namespace sf;

class Personnage {
    
    
    float tauxUtlime;
    float speed = 1.0f;
    
public:
    int vies;
    int munitions;
    float x, y;
    vector<Munitions> mun;
    Font font;
    int score;
    
    Personnage();
    Personnage(int vies, int munitions, float tauxUltime, float x, float y);
    void deplacement(RectangleShape& rectangle, Event event, RenderWindow& window);
    bool attaque(RectangleShape& rectangle, Event event, RenderWindow& window, int spriteAnimation, vector<Hermes> hermes);
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
    int chargeurMax = 32;
};

#endif