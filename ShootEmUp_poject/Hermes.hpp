#ifndef HERMES_HPP
#define HERMES_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <SFML/Audio.hpp>

#include "Datas.hpp"
#include "Munitions.hpp"
using namespace std;

class Hermes {
    int vies = 1;
    int celerite = 3;

    
public:
    void deplacement();
    void attaque(RectangleShape& rectangle, RenderWindow& window, int spriteAnimation);
    void incr_score();
    void drop();
    void setVies(int nouvelleVies);
    int getVies();
    Texture hermesText;
    sf::Sprite hermes;
    float speed;
    int vie = 1;
    vector<Munitions> mun;
    Hermes(float posX, float posY, sf::Texture& texture) {
        hermes.setTexture(texture);
        hermes.setPosition(posX, posY);
        hermes.setScale(sf::Vector2f(0.2f, 0.2f));
        
        speed = 5.f;
        
    };
    void paterns(vector<Hermes>& hermes, int ennemis);
    void depEnnemisRight(vector<Hermes>& ennemis, int velocity);
};

#endif