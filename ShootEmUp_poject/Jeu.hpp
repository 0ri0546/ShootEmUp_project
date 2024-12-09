#ifndef JEU_HPP
#define JEU_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <SFML/Audio.hpp>
#include <ctime>

#include "Personnage.hpp"

using namespace std;
using namespace sf;

class Jeu {
private:
    int score;
    RectangleShape joueur, zoneDepl;

public:
    
    Jeu(const int score);
    //Event event;
    Mouse mouse;
    Texture persoTexture, viesTextureFull, viesTexture0, viesTexture1, viesTexture2;
    Personnage personnage;
    void boucleDeJeu();
};

#endif