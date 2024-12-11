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
            if (event.key.code == Keyboard::Space && personnage.getMunitions() > 0 && dontMove == 0) {
                enAttaque++;
                cout << "en attaque" << endl;
                if (premierTir) { 
                    start = time(nullptr); 
                    personnage.mun.push_back(Munitions(joueur.getPosition().x - TAILLEX / 2, joueur.getPosition().y));
                    personnage.setMunitions(personnage.getMunitions() - 1); 
                }
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
        }

        if (gameState == "jeu")
        {
            persoSprite.setPosition(joueur.getPosition());
            persoSpriteAtt.setPosition(joueur.getPosition());
        }
        else if (gameState == "ult")
        {
            // le personnage avance de 150 et s'agrandissant, puis avance de 150 en gardant cette taille. puis sa taille reduit pour revenir à sa taille normale, et reviens à sa position initiale
        }
        
        window.clear();
        window.setFramerateLimit(60);
        window.draw(bg1Sprite);
        window.draw(bg2Sprite);
        window.draw(bg3Sprite);
        /*window.draw(zoneDepl);*/
        personnage.creerText(textRecharge, "EN RECHARGE", 40, Color::Black, WIDTH - WIDTH / 3 + 40, HEIGHT - 170, fontMunition);
        if (dontMove >= 150) { dontMove = 0; }
        if (dontMove != 0) { dontMove++; window.draw(textRecharge); }
        if (gameState == "jeu") { 
            personnage.deplacement(joueur, event, window);   
            personnage.attaque(joueur, event, window, spriteAnimation);
            
        }
        spriteAnimation++;
        if (spriteAnimation == 70) { spriteAnimation = 0; }
        string munitionsTexte = "Munitions : " + to_string(personnage.getMunitions());

        personnage.creerText(textMunitions, munitionsTexte, 40, Color::Black, WIDTH - WIDTH / 3 + 40, HEIGHT - 70, fontMunition);

        
        if (enAttaque > 0) // ------------------------------------------------------------------------
        {
            window.draw(persoSpriteAtt);
            enAttaque++;
        }
        if (enAttaque >= 20)
        {
            enAttaque = 0;
            window.draw(persoSprite);
        }
        
        cout << enAttaque << endl;
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
        if (true)
        {

        }
        window.draw(persoSprite);
        window.draw(textMunitions);

        moveBg(bg2Sprite, 0.0f, -0.5f);
        if (bg2Sprite.getPosition().y > 0) { bg2Sprite.setPosition(Vector2f(0, -HEIGHT)); }
        moveBg(bg3Sprite, 0.0f, -2.0f);
        if (bg3Sprite.getPosition().y > 0) { bg3Sprite.setPosition(Vector2f(0, -HEIGHT)); }

        window.display();
    }
}
