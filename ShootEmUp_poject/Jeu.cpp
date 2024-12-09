#include "Jeu.hpp"

using namespace sf;
using namespace std;

Jeu::Jeu(int score) : score(score) {
    this->personnage = Personnage(3, 100, 0.0, POSBASEX, POSBASEY);
    if (!persoTexture.loadFromFile("hercule.png")) {}
}

void Jeu::boucleDeJeu() {
    int spriteAnimation = 0;
    Text textMunitions;
    Sprite persoSprite;
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Mount Olympus");

    persoSprite.setTexture(persoTexture);
    float scaleX = 40.0f / persoTexture.getSize().x;
    float scaleY = 70.0f / persoTexture.getSize().y;
    persoSprite.setScale(scaleX, scaleY);

    persoSprite.setPosition(POSBASEX, POSBASEY);

    personnage.creerPieceRectangle(joueur, Color::White, TAILLEX, TAILLEY, WIDTH / 2 - TAILLEX / 2, HEIGHT - 20 - TAILLEY / 2);
    personnage.creerPieceRectangle(zoneDepl, Color::Red, WIDTH, HEIGHT / 2, 0, HEIGHT / 2);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.key.code == Keyboard::Space) {
                cout << "Creer une munition" << endl;
                personnage.mun.push_back(Munitions(joueur.getPosition().x, joueur.getPosition().y));
            }
        }

        personnage.creerText(textMunitions, "Munitions : 10", 20, Color::White, 50, 50);

        persoSprite.setPosition(joueur.getPosition());

        window.clear();
        window.setFramerateLimit(60);

        window.draw(zoneDepl);
        personnage.deplacement(joueur, event, window);
        personnage.attaque(joueur, event, window, spriteAnimation);
        spriteAnimation++;
        if (spriteAnimation == 10)
        {
            spriteAnimation = 0;
        }
        window.draw(textMunitions);
        window.draw(persoSprite);
        window.display();
    }
}
