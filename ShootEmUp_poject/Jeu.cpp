#include "Jeu.hpp"

using namespace sf;
using namespace std;

Jeu::Jeu(int score) : score(score) {
    this->personnage = Personnage(3, 100, 0.0 , POSBASEX, POSBASEY);
};

void Jeu::boucleDeJeu() {
    Text textMunitions;
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Mount Olympus");
    personnage.creerPieceRectangle(joueur, Color::White, TAILLEX, TAILLEY, WIDTH / 2 - TAILLEX / 2, HEIGHT - 20 - TAILLEY / 2);
    personnage.creerPieceRectangle(zoneDepl, Color::Red, WIDTH, HEIGHT / 2, 0, HEIGHT / 2);

    while (window.isOpen()) {
        sf::Event event;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.key.code == Keyboard::Space) {
                cout << "creer une mun" << endl;
                personnage.mun.push_back(Munitions(joueur.getPosition().x, joueur.getPosition().y));
            }
        }
        personnage.creerText(textMunitions, "Munitions : 10", 20, Color::White, 50, 50);
        window.clear();
        window.setFramerateLimit(40);
        window.draw(zoneDepl);
        personnage.deplacement(joueur, event, window);
        personnage.attaque(joueur, event, window);// --------------------------------------------------------------------------------------------------------------------------------------
        window.draw(textMunitions);
        window.draw(joueur);
        window.display();
    }
}