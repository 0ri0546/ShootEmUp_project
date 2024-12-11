#include "Jeu.hpp"

using namespace sf;
using namespace std;

Jeu::Jeu(int score) : score(score) {
    this->personnage = Personnage(3, 32, 0.0, POSBASEX, POSBASEY);
    if (!persoTexture.loadFromFile("hercule.png")) {}
    if (!persoTextureAtt.loadFromFile("herculeAtt.png")) {}
    if (!viesTextureFull.loadFromFile("heartfull.png")) {}
    if (!viesTexture0.loadFromFile("heart0.png")) {}
    if (!viesTexture2.loadFromFile("heart2.png")) {}
    if (!viesTexture1.loadFromFile("heart1.png")) {}
    if (!bg1Texture.loadFromFile("bg1.png")) {}
    if (!bg2Texture.loadFromFile("bg2.png")) {}
    if (!bg3Texture.loadFromFile("bg3.png")) {}
}
void Jeu::resize(Texture& texture, Sprite& sprite, float scaleX, float scaleY) {
    sprite.setTexture(texture);
    float scaleFinaleX = scaleX / texture.getSize().x;
    float scaleFinaleY = scaleY / texture.getSize().y;
    sprite.setScale(scaleFinaleX, scaleFinaleY);
}

void Jeu::moveBg(Sprite& sprite, float speedX, float speedY) {
    sprite.move(speedX, -speedY);
}

void Jeu::boucleDeJeu() {
    int spriteAnimation = 0;
    string gameState = "jeu";
    bool premierTir = true;
    int dontMove = 0;
    int ultState = 0;
    Vector2f initialPosition = persoSprite.getPosition();
    float ultScale = 1.0f;
    Clock ultTimer; 
    Font fontMunition;
    fontMunition.loadFromFile("god.ttf");
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Mount Olympus");

    resize(viesTextureFull, viesSpriteFull, 100.0f, 70.0f);
    resize(viesTexture0, viesSprite0, 100.0f, 70.0f);
    resize(viesTexture1, viesSprite1, 100.0f, 70.0f);
    resize(viesTexture2, viesSprite2, 100.0f, 70.0f);
    resize(persoTexture, persoSprite, 60.0f, 70.0f);
    resize(persoTextureAtt, persoSpriteAtt, 60.0f, 70.0f);

    persoSprite.setPosition(POSBASEX, POSBASEY);
    persoSpriteAtt.setPosition(POSBASEX, POSBASEY);

    personnage.creerPieceRectangle(joueur, Color::White, TAILLEX, TAILLEY, POSBASEX, POSBASEY);
    personnage.creerPieceRectangle(zoneDepl, Color::Green, WIDTH, HEIGHT / 2, 0, HEIGHT / 2);

    Sprite bg1Sprite(bg1Texture);
    resize(bg1Texture, bg1Sprite, WIDTH, HEIGHT);
    bg1Sprite.setPosition(0, 0);

    Sprite bg2Sprite(bg2Texture);
    resize(bg2Texture, bg2Sprite, WIDTH, HEIGHT * 2);
    bg2Sprite.setPosition(0, -HEIGHT);

    Sprite bg3Sprite(bg3Texture);
    resize(bg3Texture, bg3Sprite, WIDTH, HEIGHT * 2);
    bg3Sprite.setPosition(0, -HEIGHT);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.key.code == Keyboard::Space && personnage.getMunitions() > 0 && dontMove == 0 && ultState == 0) {
                enAttaque++;
                if (premierTir) {
                    start = time(nullptr);
                    personnage.mun.push_back(Munitions(joueur.getPosition().x - TAILLEX / 2, joueur.getPosition().y));
                    personnage.setMunitions(personnage.getMunitions() - 1);
                }
                end = time(nullptr);
                if (end - start > 0) {
                    premierTir = false;
                    personnage.mun.push_back(Munitions(joueur.getPosition().x - TAILLEX / 2, joueur.getPosition().y));
                    personnage.setMunitions(personnage.getMunitions() - 1);
                }
                else { premierTir = false; }
                start = time(nullptr);
            }
            if (event.key.code == Keyboard::R && ultState == 0) {
                personnage.setMunitions(31);
                dontMove++;
                cout << "recharge" << endl;
            }
            if (event.key.code == Keyboard::U && ultState == 0) { 
                gameState = "ult";
                ultState = 1;
                ultTimer.restart();
                initialPosition = persoSprite.getPosition();
            }
        }

        if (gameState == "ult") {
            if (ultState == 1) {
                persoSprite.move(0.0f, -15.0f);
                if (persoSprite.getPosition().y <= TAILLEY) { ultState = 2; }
            }
            if (ultState == 2) { 
                ultArea.setOutlineColor(Color::Red);
                ultArea.setOutlineThickness(5); 
                ultArea.setFillColor(Color::Transparent); 
                ultArea.setPosition(persoSprite.getPosition().x - ultArea.getRadius() + TAILLEX/2,
                    persoSprite.getPosition().y - ultArea.getRadius() + TAILLEY/2);
                ultArea.setRadius(100.f);
                if (ultTimer.getElapsedTime().asSeconds() >= 1.0f) { ultState = 3; }
            }

            else if (ultState == 3) { 
                persoSprite.setPosition(initialPosition);
                ultState = 0;
                gameState = "jeu";
                
            }
        }

        if (gameState == "jeu") { persoSprite.setPosition(joueur.getPosition()); persoSpriteAtt.setPosition(joueur.getPosition()); }

        window.clear();
        window.setFramerateLimit(60);

        window.draw(bg1Sprite);
        window.draw(bg2Sprite);
        window.draw(bg3Sprite);

        personnage.creerText(textRecharge, "EN RECHARGE", 30, Color::Black, WIDTH - WIDTH / 3 + 70, HEIGHT - 150, fontMunition);
        if (dontMove >= 150) dontMove = 0;
        if (dontMove != 0) {
            dontMove++;
            window.draw(textRecharge);
        }
        if (gameState == "jeu") { personnage.deplacement(joueur, event, window); personnage.attaque(joueur, event, window, spriteAnimation); }

        spriteAnimation++;
        if (spriteAnimation == 70) spriteAnimation = 0;

        string munitionsTexte = "Munitions : " + to_string(personnage.getMunitions());
        personnage.creerText(textMunitions, munitionsTexte, 30, Color::Black, WIDTH - WIDTH / 3 + 70, HEIGHT - 70, fontMunition);
        personnage.creerText(textUlt, "Ultime : %", 30, Color::Black, WIDTH - WIDTH / 3 + 70, HEIGHT - 110, fontMunition);

        if (enAttaque > 0) { window.draw(persoSpriteAtt); enAttaque++; }
        if (enAttaque >= 20) { enAttaque = 0;  window.draw(persoSprite); }

        window.draw(persoSprite);
        window.draw(textMunitions);
        window.draw(textUlt);

        moveBg(bg2Sprite, 0.0f, -0.5f);
        if (bg2Sprite.getPosition().y > 0) bg2Sprite.setPosition(Vector2f(0, -HEIGHT));
        moveBg(bg3Sprite, 0.0f, -2.0f);
        if (bg3Sprite.getPosition().y > 0) bg3Sprite.setPosition(Vector2f(0, -HEIGHT));
        if (ultState == 2) { window.draw(ultArea); }
        window.display();
    }
}

