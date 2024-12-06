#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <SFML/Audio.hpp>

#include "Jeu.hpp"

using namespace std;
using namespace sf;

//vector<EnnemiFaible> ennemisFaibles;
//vector<EnnemiMoyen> ennemisMoyens;
//vector<EnnemiFort> ennemisForts;
//vector<PowerUp> bonusPersonnage;

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
    using namespace std;
    using namespace sf;

    Jeu jeu(0);
    jeu.boucleDeJeu();
    
    return 0;
}