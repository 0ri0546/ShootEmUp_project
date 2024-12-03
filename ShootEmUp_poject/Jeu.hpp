#ifndef ENNEMIFAIBLE_HPP
#define ENNEMIFAIBLE_HPP
using namespace std;
using namespace sf;
#include "EnnemiMoyen.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <SFML/Audio.hpp>
#include "Personnage.hpp"

class Jeu {
private:
    int score;
    RectangleShape joueur;

public:
    void boucleDeJeu();
    Event event;
    Personnage personnage;
};

#endif