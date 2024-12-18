#ifndef POSEIDON_HPP
#define POSEIDON_HPP


#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <SFML/Audio.hpp>

#include "Datas.hpp"
#include "Munitions.hpp"

using namespace std;
using namespace sf;

class Poseidon {

    int munitions;
    float tauxUtlime;
    float speed = 1.0f;

public:
    Sprite poseidon;
    int vies = 100;
    float x, y;
    vector<Munitions> mun;
    Font font;
    int score;
    bool alive;
    Poseidon(float posX, float posY, sf::Texture& texture) {
        poseidon.setTexture(texture);
        poseidon.setPosition(posX, posY);
        poseidon.setScale(sf::Vector2f(0.2f, 0.2f));

        speed = 5.f;

    };

    void deplacement(int velocity);
    void attaque(RectangleShape& rectangle, RenderWindow& window, int spriteAnimation);
    void ult(RectangleShape& rectangle, Event event, RenderWindow& window);
    void setTexture(RectangleShape& rectangle, const Texture* texture);
    void setVies(int nouvelleVie);
    void setMunitions(int nouvelleMunition);
    void setTauxUtlime(float NouveauTauxUlt);
    int getVies();
    int getMunitions();




    float getPositionX();
    float getPositionY();
};

#endif