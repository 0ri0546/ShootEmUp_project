#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <SFML/Audio.hpp>
#include "Personnage.hpp"

using namespace std;
using namespace sf;

//vector<EnnemiFaible> ennemisFaibles;
//vector<EnnemiMoyen> ennemisMoyens;
//vector<EnnemiFort> ennemisForts;
//vector<PowerUp> bonusPersonnage;



class PowerUp {
private:
    string type;
public:
    void cadenceDeTir() {
        //augmente les tirs par seconde
    }
    void upChargeur() {
        //augmente la capacité du chargeur
    }
    void MultiShot() {
        //tire en diagonale
    }
    void bouclier() {
        //invincible pendant x secondes
    }
    void gel() {
        //arret du mouvement des ennemis
    }

    string getType() { return type; }
};

class EnnemiMoyen {
private:
    int vies = 2;
    int celerite = 2;
public:
    void deplacement()  {
        //les ennemis se deplacent à l'horizontale
    }
    void attaque() {

    }
    void incr_score() {

    }
    void drop() {

    }
    void setVies(int nouvelleVies) { vies = nouvelleVies; }
    int getVies() { return vies; }
};

class EnnemiFort {
private:
    int vies = 3;
    int celerite = 1;
public:
    void deplacement()  {
        //les ennemis se deplacent en diagonale
    }
    void attaque() {

    }
    void incr_score() {

    }
    void drop() {

    }

    void setVies(int nouvelleVies) { vies = nouvelleVies; }
    int getVies() { return vies; }
};

class Athena {
private:
    int vies; 
public:
    void deplacement() {

    }
    void attaque() {

    }
};
class Ares {
private:
    int vies;
public:
    void deplacement() {

    }
    void attaque() {

    }
};
class Hades {
private:
    int vies;
public:
    void deplacement() {

    }
    void attaque() {

    }
};
class Zeus {
private:
    int vies;
public:
    void deplacement() {

    }
    void attaque() {

    }
};

class Kratos {
private:
    int vies;
public:
    void deplacement() {

    }
    void attaque() {

    }
};

class Jeu {
private:
    int score;
    
public:
    void boucleDeJeu() {
        Event event;
        RenderWindow window(VideoMode(800, 600), "Mount Olympus");

        Personnage::

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            window.draw(shape);
            window.display();
        }
    }
};

int main() {
    const int WIDTH = 1920;
    const int HEIGHT = 1080;
    Texture texture;
    
    Jeu jeu;
    jeu.boucleDeJeu();
    

    return 0;
}