#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <SFML/Audio.hpp>
#include "Personnage.hpp"
#include "Jeu.hpp"

using namespace std;
using namespace sf;

//vector<EnnemiFaible> ennemisFaibles;
//vector<EnnemiMoyen> ennemisMoyens;
//vector<EnnemiFort> ennemisForts;
//vector<PowerUp> bonusPersonnage;

//class PowerUp {
//private:
//    string type;
//public:
//    void cadenceDeTir() {
//        //augmente les tirs par seconde
//    }
//    void upChargeur() {
//        //augmente la capacité du chargeur
//    }
//    void MultiShot() {
//        //tire en diagonale
//    }
//    void bouclier() {
//        //invincible pendant x secondes
//    }
//    void gel() {
//        //arret du mouvement des ennemis
//    }
//
//    string getType() { return type; }
//};
//
//
//
//class poseidon {
//private:
//    int vies; 
//public:
//    void deplacement() {
//        //
//    }
//    void attaque() {
//        //
//    }
//};
//class Ares {
//private:
//    int vies;
//public:
//    void deplacement() {
//        //
//    }
//    void attaque() {
//        //
//    }
//};
//class Hades {
//private:
//    int vies;
//public:
//    void deplacement() {
//        //
//    }
//    void attaque() {
//        //
//    }
//};
//class Zeus {
//private:
//    int vies;
//public:
//    void deplacement() {
//        //
//    }
//    void attaque() {
//        //
//    }
//};
//
//class Kratos {
//private:
//    int vies;
//public:
//    void deplacement() {
//        //
//    }
//    void attaque() {
//        //
//    }
//};


int main() {
    const int WIDTH = 1920;
    const int HEIGHT = 1080;
    Texture texture;
    
    Jeu jeu;
    jeu.boucleDeJeu();
    
    return 0;
}