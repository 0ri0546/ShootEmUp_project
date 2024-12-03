#include "Jeu.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;

void Jeu::boucleDeJeu() {
    RenderWindow window(VideoMode(800, 600), "Mount Olympus");

    personnage.creerPieceRectangle(joueur, Color::White, 50, 100, 50, 200);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.draw(joueur);
        window.display();
    }
}