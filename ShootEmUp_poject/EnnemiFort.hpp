#ifndef ENNEMIFAIBLE_HPP
#define ENNEMIFAIBLE_HPP
using namespace std;
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <SFML/Audio.hpp>

class EnnemiFort {
private:
    int vies = 3;
    int celerite = 1;
public:
    void deplacement();
    void attaque();
    void incr_score();
    void drop();

    void setVies(int nouvelleVies);
    int getVies();
};

#endif