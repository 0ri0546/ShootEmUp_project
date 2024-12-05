#include "Jeu.hpp"


using namespace sf;
using namespace std;


Jeu::Jeu(int score) : score(score) {
    this->personnage = Personnage(3, 100, 0.0 , POSBASEX, POSBASEY);
};

void Jeu::boucleDeJeu() {
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Mount Olympus");
    personnage.creerPieceRectangle(joueur, Color::White, TAILLEX, TAILLEY, WIDTH / 2 - TAILLEX / 2, HEIGHT - 20 - TAILLEY / 2);
    personnage.creerPieceRectangle(zoneDepl, Color::Red, WIDTH, HEIGHT / 2, 0, HEIGHT / 2); 

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        personnage.deplacement(joueur, event, window);
        window.clear();
        window.setFramerateLimit(60);
        window.draw(zoneDepl);
        window.draw(joueur);
        window.display();
    }
}