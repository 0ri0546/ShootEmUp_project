#ifndef ENNEMIFAIBLE_HPP
#define ENNEMIFAIBLE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <SFML/Audio.hpp>

#include "Personnage.hpp"
#include "Munitions.hpp"

using namespace std;
using namespace sf;

class Jeu {
private:
    int score;
    RectangleShape joueur, zoneDepl;

public:
    const static int WIDTH = 700;
    const static int HEIGHT = 800;
    const float POSBASEX = WIDTH / 2 - 40;
    const float POSBASEY = HEIGHT - 20 - 70;
    const static int TAILLEX = 40;
    const static int TAILLEY = 70;
    Jeu(const int score);
    //Event event;
    Mouse mouse;
    Personnage personnage;
    void boucleDeJeu();
};

#endif