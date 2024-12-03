#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <SFML/Audio.hpp>


using namespace std;
using namespace sf;

//vector<EnnemiFaible> ennemisFaibles;
//vector<EnnemiMoyen> ennemisMoyens;
//vector<EnnemiFort> ennemisForts;
//vector<PowerUp> bonusPersonnage;





class Jeu {
private:
    int score;
    
public:
    void boucleDeJeu() {
        Event event;
        RenderWindow window(VideoMode(800, 600), "Mount Olympus");
        sf::Texture t;
        t.loadFromFile("../assets/Hercule.png");
        sf::Sprite s(t);
        

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            window.draw(s);
            window.display();
        }
    }
};

int main() {
    const int WIDTH = 1920;
    const int HEIGHT = 1080;
    sf::Texture background;

    
    Jeu jeu;
    jeu.boucleDeJeu();
    

    return 0;
}