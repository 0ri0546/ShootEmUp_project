#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;



int main() {
<<<<<<< Updated upstream
    // Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(800, 600), "Fenêtre SFML");

    // Création d'un cercle
    sf::CircleShape shape(50); // Rayon de 50 pixels
    shape.setFillColor(sf::Color::Green);

    // Boucle principale
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); // Fermer la fenêtre
        }

        // Effacer la fenêtre
        window.clear();
        // Dessiner la forme
        window.draw(shape);
        // Afficher le contenu
        window.display();
    }
=======
    const int WIDTH = 1920;
    const int HEIGHT = 1080;
    sf::
    
    Jeu jeu;
    jeu.boucleDeJeu();
    
>>>>>>> Stashed changes

    return 0;
}