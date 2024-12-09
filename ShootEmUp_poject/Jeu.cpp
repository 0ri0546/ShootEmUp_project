#include "Jeu.hpp"

using namespace sf;
using namespace std;

Jeu::Jeu(int score) : score(score) {
    this->personnage = Personnage(3, 32, 0.0, POSBASEX, POSBASEY);
    if (!persoTexture.loadFromFile("hercule.png")) {}
    if (!viesTextureFull.loadFromFile("heartfull.png")) {}
    if (!viesTexture0.loadFromFile("heart0.png")) {}
    if (!viesTexture2.loadFromFile("heart2.png")) {}
    if (!viesTexture1.loadFromFile("heart1.png")) {}
}

void Jeu::boucleDeJeu() {
    int spriteAnimation = 0;
    string gameState = "jeu";
    bool premierTir = true;
    int dontMove = 0;
    Font fontMunition;
    fontMunition.loadFromFile("god.ttf");
    time_t start;
    time_t end;
    Text textMunitions, textVie, textUlt, textWave, textLevel, textRecharge;
    Sprite persoSprite, viesSpriteFull, viesSprite0, viesSprite1, viesSprite2;
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Mount Olympus");

    viesSpriteFull.setTexture(viesTextureFull);
    float scaleXvieFull = 100.f / viesTextureFull.getSize().x;
    float scaleYvieFull = 70.0f / viesTextureFull.getSize().y;
    viesSpriteFull.setScale(scaleXvieFull, scaleYvieFull);

    viesSprite0.setTexture(viesTexture0);
    float scaleXvie0 = 100.f / viesTexture0.getSize().x;
    float scaleYvie0 = 70.0f / viesTexture0.getSize().y;
    viesSprite0.setScale(scaleXvie0, scaleYvie0);

    viesSprite1.setTexture(viesTexture1);
    float scaleXvie1 = 100.f / viesTexture1.getSize().x;
    float scaleYvie1 = 70.0f / viesTexture1.getSize().y;
    viesSprite1.setScale(scaleXvie1, scaleYvie1);

    viesSprite2.setTexture(viesTexture2);
    float scaleXvie2 = 100.f / viesTexture2.getSize().x;
    float scaleYvie2 = 70.0f / viesTexture2.getSize().y;
    viesSprite2.setScale(scaleXvie2, scaleYvie2);

    persoSprite.setTexture(persoTexture);
    float scaleX = 60.0f / persoTexture.getSize().x;
    float scaleY = 70.0f / persoTexture.getSize().y;
    persoSprite.setScale(scaleX, scaleY);

    persoSprite.setPosition(POSBASEX, POSBASEY); //-------------------------------------------------------------------------------------------

    personnage.creerPieceRectangle(joueur, Color::White, TAILLEX, TAILLEY, POSBASEX, POSBASEY);
    personnage.creerPieceRectangle(zoneDepl, Color::Green, WIDTH, HEIGHT / 2, 0, HEIGHT / 2);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.key.code == Keyboard::Space && personnage.getMunitions() > 0 && dontMove == 0) {
                if (premierTir) { start = time(nullptr); }
                end = time(nullptr);
                if (end - start > 0)
                {
                    premierTir = false;
                    personnage.mun.push_back(Munitions(joueur.getPosition().x - TAILLEX / 2, joueur.getPosition().y));
                    personnage.setMunitions(personnage.getMunitions() - 1);
                }
                else { premierTir = false; }
                start = time(nullptr);
            }
            if (event.key.code == Keyboard::R)
            {
                personnage.setMunitions(31);
                dontMove++;
                cout << "recharge" << endl;
            }
            int vieTemp = personnage.getVies();
            if (event.key.code == Keyboard::X)
            {
                gameState = "ult";
                /*personnage.x = persoSprite.getPosition().x - persoSprite.getScale().x / 2;
                personnage.y = persoSprite.getPosition().y - persoSprite.getScale().y / 2;*/
                personnage.ult(joueur, event, window);
                personnage.setVies(vieTemp);
            }
        }

        if (gameState == "jeu")
        {
            persoSprite.setPosition(joueur.getPosition());
        }
        else if (gameState == "ult")
        {
            // le personnage avance de 150 et s'agrandissant, puis avance de 150 en gardant cette taille. puis sa taille reduit pour revenir à sa taille normale, et reviens à sa position initiale
            ;
        }
        
        window.clear();
        window.setFramerateLimit(60);
        window.draw(zoneDepl);
        personnage.creerText(textRecharge, "EN RECHARGE", 40, Color::White, WIDTH - WIDTH / 3 + 40, HEIGHT - 170, fontMunition);
        if (dontMove >= 150) { dontMove = 0; }
        if (dontMove != 0) { dontMove++; window.draw(textRecharge); }
        if (gameState == "jeu")
        {
            personnage.deplacement(joueur, event, window);
            personnage.attaque(joueur, event, window, spriteAnimation);
        }
        spriteAnimation++;
        if (spriteAnimation == 10) { spriteAnimation = 0; }
        string munitionsTexte = "Munitions : " + to_string(personnage.getMunitions());

        personnage.creerText(textMunitions, munitionsTexte, 40, Color::White, WIDTH - WIDTH / 3 + 40, HEIGHT - 70, fontMunition);
        if (personnage.getVies() == 3) {
            viesSpriteFull.setPosition(Vector2f(joueur.getPosition().x - 20, joueur.getPosition().y + TAILLEY - 30));
            window.draw(viesSpriteFull);
        }
        else if (personnage.getVies() == 2) {
            viesSprite2.setPosition(Vector2f(joueur.getPosition().x - 20, joueur.getPosition().y + TAILLEY - 30));
            window.draw(viesSprite2);
        }
        else if (personnage.getVies() == 1) {
            viesSprite1.setPosition(Vector2f(joueur.getPosition().x - 20, joueur.getPosition().y + TAILLEY - 30));
            window.draw(viesSprite1);
        }
        else {
            viesSprite0.setPosition(Vector2f(joueur.getPosition().x - 20, joueur.getPosition().y + TAILLEY - 30));
            window.draw(viesSprite0);
        }
        window.draw(textMunitions);
        window.draw(persoSprite);
        window.display();
    }
}
