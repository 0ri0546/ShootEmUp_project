#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <SFML/Audio.hpp>

#include "Jeu.hpp"

using namespace std;
using namespace sf;



int main() {
    const int WIDTH = 1920;
    const int HEIGHT = 1080;
    using namespace std;
    using namespace sf;
    
    Jeu jeu(0);
    jeu.boucleDeJeu();
    
    return 0;
}