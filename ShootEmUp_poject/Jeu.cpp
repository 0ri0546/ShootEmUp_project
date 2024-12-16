#include "Jeu.hpp"

using namespace sf;
using namespace std;

Jeu::Jeu(int score) : score(score) {
    personnage = Personnage(3, 32, 0.0, POSBASEX, POSBASEY);
    if (!persoTexture.loadFromFile("hercule.png")) {}
    if (!persoTextureAtt.loadFromFile("herculeAtt.png")) {}
    if (!viesTextureFull.loadFromFile("heartfull.png")) {}
    if (!viesTexture0.loadFromFile("heart0.png")) {}
    if (!viesTexture2.loadFromFile("heart2.png")) {}
    if (!viesTexture1.loadFromFile("heart1.png")) {}
    if (!bg1Texture.loadFromFile("bg1.png")) {}
    if (!bg2Texture.loadFromFile("bg2.png")) {}
    if (!bg3Texture.loadFromFile("bg3.png")) {}
    
    
    if (!dgtultTexture.loadFromFile("dgtult.png")) {}
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
    string Game = "jeu";
    bool premierTir = true;
    int dontMove = 0;
    int ultState = 0;
    Vector2f initialPosition = persoSprite.getPosition();
    float ultScale = 1.0f;
    Clock ultTimer;
    Font fontMunition;
    fontMunition.loadFromFile("god.ttf");
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Mount Olympus");
    //Texture hermestext;
    enum class GameState { MenuStart, Jeu, levelSelect, OptionMenu };
    GameState gameState = GameState::Jeu;
    
    resize(persoTexture, persoSprite, 60.0f, 70.0f);
    resize(persoTextureAtt, persoSpriteAtt, 60.0f, 70.0f);
    resize(dgtultTexture, dgtultSprite, 150.0f, 150.0f);

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
    resize(bg3Texture, bg3Sprite, WIDTH, HEIGHT * 3);
    bg3Sprite.setPosition(0, -HEIGHT * 2);
    vector<Munitions>mun;
    vector<Hermes> hermes;
    Hermes hermes1(100, 100, hermesText);
    hermes1.paterns(hermes, 10);
    while (window.isOpen()) {
        enAttaquePerso++;
        sf::Event event;
        if (ultime == 0) { if (!ultTexture.loadFromFile("ult9.png")) {} } // à revoir
        else if (ultime <= 12.5) { if (!ultTexture.loadFromFile("ult8.png")) {} }
        else if (ultime <= 25.0) { if (!ultTexture.loadFromFile("ult7.png")) {} }
        else if (ultime <= 37.5) { if (!ultTexture.loadFromFile("ult6.png")) {} }
        else if (ultime <= 50.0) { if (!ultTexture.loadFromFile("ult5.png")) {} }
        else if (ultime <= 62.5) { if (!ultTexture.loadFromFile("ult4.png")) {} }
        else if (ultime <= 75.0) { if (!ultTexture.loadFromFile("ult3.png")) {} }
        else if (ultime <= 87.5) { if (!ultTexture.loadFromFile("ult2.png")) {} }
        else if (ultime <= 100.0) { if (!ultTexture.loadFromFile("ult1.png")) {} }
        resize(ultTexture, ultSprite, 100.0f, 100.0f);
        ultSprite.setPosition(20, HEIGHT - 120);

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
            if (event.key.code == Keyboard::U && ultState == 0 && ultime >= 100) {
                Game = "ult";
                ultState = 1;
                ultTimer.restart();
                initialPosition = persoSprite.getPosition();
                
            }
        }

        if (gameState == GameState::Jeu) {
            if (personnage.getVies() == 3) { resize(viesTextureFull, viesSprite, 100.0f, 70.0f); }
            if (personnage.getVies() == 2) { resize(viesTexture2, viesSprite, 100.0f, 70.0f); }
            if (personnage.getVies() == 1) { resize(viesTexture1, viesSprite, 100.0f, 70.0f); }
            if (personnage.getVies() == 0) { resize(viesTexture0, viesSprite, 100.0f, 70.0f); }

            viesSprite.setPosition(joueur.getPosition().x - TAILLEX / 4, joueur.getPosition().y + TAILLEY /2);
            if (Game == "ult") {
                int vies = personnage.getVies();
                if (ultState == 1) {
                    persoSprite.move(0.0f, -15.0f);
                    if (persoSprite.getPosition().y <= TAILLEY + 20) { ultState = 2; }
                }
                if (ultState == 2) {
                    float centerX = persoSprite.getPosition().x + persoSprite.getGlobalBounds().width / 2 + TAILLEX / 2 ;
                    float centerY = persoSprite.getPosition().y + persoSprite.getGlobalBounds().height / 2 + TAILLEY / 2;
                    dgtultSprite.setPosition(centerX - 100, centerY - 100);
                    dgtultSprite.setColor(couleurAvecOpacite);
                    if (ultTimer.getElapsedTime().asSeconds() >= 1.0f) { ultState = 3; }

                    FloatRect ultBounds = dgtultSprite.getGlobalBounds();
                    for (auto it = hermes.begin(); it != hermes.end();) {
                        if (ultBounds.intersects(it->hermes.getGlobalBounds())) { it->vie = 0; it = hermes.erase(it); }
                        else { ++it; }
                    }
                }

                else if (ultState == 3) {
                    persoSprite.setPosition(initialPosition);
                    ultState = 0;
                    ultime = 0;
                    Game = "jeu";

                }
                personnage.setVies(vies);
            }

            if (Game == "jeu") { persoSprite.setPosition(joueur.getPosition()); persoSpriteAtt.setPosition(joueur.getPosition()); }

            window.clear();
            window.setFramerateLimit(60);

            window.draw(bg1Sprite);
            window.draw(bg2Sprite);
            window.draw(bg3Sprite);

            personnage.creerText(textRecharge, "EN RECHARGE", 30, Color::Black, WIDTH - WIDTH / 3 + 70, HEIGHT - 150, fontMunition);
            if (dontMove >= 150) dontMove = 0;
            if (dontMove != 0) {
                dontMove++;
                personnage.creerPieceRectangle(rectangleRecharge, Color::White, dontMove * 1.826f, 30, WIDTH - WIDTH / 3 + 20, HEIGHT - 110);
                window.draw(rectangleRecharge);
            }
            if (Game == "jeu") { personnage.deplacement(joueur, event, window); personnage.attaque(joueur, event, window, spriteAnimation, hermes); }

            spriteAnimation++;
            if (spriteAnimation == 70) spriteAnimation = 0;

            personnage.creerPieceRectangle(rectangleMunitions, Color::White, personnage.getMunitions() * 7, 30, WIDTH - WIDTH / 3 + 20, HEIGHT - 70);
            rectangleMunitionsOutLine.setFillColor(Color::Transparent);
            rectangleMunitionsOutLine.setOutlineThickness(3);
            rectangleMunitionsOutLine.setOutlineColor(Color::Black);
            rectangleMunitionsOutLine.setPosition(Vector2f(WIDTH - WIDTH / 3 + 20, HEIGHT - 70));
            rectangleMunitionsOutLine.setSize(Vector2f(32 * 7 + 50, 30));
            personnage.creerText(textMunitions, to_string(personnage.getMunitions()), 30, Color::Black, WIDTH - WIDTH / 3 + 32 * 7 + 30, HEIGHT - 73, fontMunition); // _________________________________________________________

            window.draw(textMunitions);
            window.draw(rectangleMunitions);
            window.draw(rectangleMunitionsOutLine);
            
            if (enAttaque > 0) { window.draw(persoSpriteAtt); enAttaque++; }
            if (enAttaque >= 20) { enAttaque = 0;  window.draw(persoSprite); }

            
            window.draw(textMunitions);
            window.draw(textUlt);
            ultSprite.setTexture(ultTexture);
            window.draw(ultSprite);
            for (auto it = hermes.begin(); it != hermes.end();) {
                if (enAttaquePerso == 1) {
                    it->attaque(joueur, window, spriteAnimation);
                }
                window.draw(it->hermes);

                if (enAttaquePerso == 1) {
                    it->attaque(joueur, window, spriteAnimation);

                }
                if (enAttaquePerso == 100) {
                    enAttaquePerso == 0;
                }
                if (it->vie == 0) {
                    it = hermes.erase(it);
                    continue;
                }

                for (auto& munition : personnage.mun) {
                    if (it->hermes.getGlobalBounds().intersects(munition.mun.getGlobalBounds())) {
                        it->vie -= 1;
                        personnage.score += 1;
                        ultime += 5.f;
                        cout << ultime << endl;
                    }
                }
                it++;
            }
            hermes1.depEnnemisRight(hermes, 2);//------------------------------------------------------------------------------------------------
            window.draw(viesSprite);

            moveBg(bg2Sprite, 0.0f, -0.5f);
            if (bg2Sprite.getPosition().y > 0) bg2Sprite.setPosition(Vector2f(0, -HEIGHT));
            moveBg(bg3Sprite, 0.0f, -2.0f);
            if (bg3Sprite.getPosition().y > 0) bg3Sprite.setPosition(Vector2f(0, -HEIGHT * 2));
            if (ultState == 2 ) { window.draw(dgtultSprite); }
            window.draw(persoSprite);
            window.display();
        }
    }
}

