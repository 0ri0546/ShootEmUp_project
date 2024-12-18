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
    if (!startTexture.loadFromFile("startButton.png")) {}
    if (!optionTexture.loadFromFile("optionsButton.png")) {}
    if (!exitTexture.loadFromFile("exitButton.png")) {}
    if (!editorTexture.loadFromFile("editorButton.png")) {}
    if (!powerUpTexture1.loadFromFile("powerUpTexture1.png")) {}
    if (!powerUpTexture2.loadFromFile("powerUpTexture2.png")) {}
    if (!powerUpTexture3.loadFromFile("powerUpTexture3.png")) {}
    if (!obstacleTexture.loadFromFile("obstacle.png")) {}
    if (!backTexture.loadFromFile("backButton.png")) {}
    if (!level1ButtonTexture.loadFromFile("level1Button1.png")) {}
    if (!poseidonTexture.loadFromFile("poseidon.png")) {}
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
    vector<PowerUp> power1;
    vector<PowerUp> power2;
    vector<PowerUp> power3;
    vector<Poseidon> pose;
    pose.push_back(Poseidon(WIDTH / 2, 0, poseidonTexture));
    enum class GameState { MenuStart, Jeu, LevelSelect, OptionMenu, levelEditor, Pause, GameOver };
    enum class LevelState { Level1, Level2, Level3, Level4, Final };
    enum class VagueState { Vague1, Vague2, Vague3, Vague4, Vague5, Boss };
    GameState gameState = GameState::MenuStart;
    LevelState level = LevelState::Level1;
    VagueState vague = VagueState::Vague1;

    srand(static_cast<unsigned>(time(nullptr))); // pour les obstacles
    vector<Obstacle> obstacles;
    Clock obstacleClock;
    float obstacleSpawnInterval = 2.f;
    
    resize(persoTexture, persoSprite, 60.0f, 70.0f);
    resize(persoTextureAtt, persoSpriteAtt, 60.0f, 70.0f);
    resize(dgtultTexture, dgtultSprite, 150.0f, 150.0f);

    persoSprite.setPosition(POSBASEX, POSBASEY);
    persoSpriteAtt.setPosition(POSBASEX, POSBASEY);

    startButton.setPosition(0, 0);
    startButton.setTexture(startTexture);
    exitButton.setTexture(exitTexture);
    optionButton.setTexture(optionTexture);
    editorButton.setTexture(editorTexture);
    backButton.setTexture(backTexture);
    level1Button.setTexture(level1ButtonTexture);

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
    hermes1.creerEnnemis(hermes, 2, WIDTH / 2, HEIGHT * 1/4); 

    bool pause = false;
    while (window.isOpen()) {
        
        enAttaquePerso++;
        sf::Event event;
        if (ultime == 0) { if (!ultTexture.loadFromFile("ult9.png")) {} }
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
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (gameState == GameState::GameOver) {
                if (event.key.code == Mouse::Left && sf::Mouse::getPosition(window).x > backButton.getGlobalBounds().left &&
                    sf::Mouse::getPosition(window).x < backButton.getGlobalBounds().left +
                    backButton.getGlobalBounds().width && sf::Mouse::getPosition(window).y >
                    backButton.getGlobalBounds().top && sf::Mouse::getPosition(window).y
                    < (backButton.getGlobalBounds().top + backButton.getGlobalBounds().height)) {
                    gameState = GameState::MenuStart;
                }
            }
            if (gameState == GameState::levelEditor) {
                if (event.key.code == Mouse::Left && sf::Mouse::getPosition(window).x > backButton.getGlobalBounds().left &&
                    sf::Mouse::getPosition(window).x < backButton.getGlobalBounds().left +
                    backButton.getGlobalBounds().width && sf::Mouse::getPosition(window).y >
                    backButton.getGlobalBounds().top && sf::Mouse::getPosition(window).y
                    < (backButton.getGlobalBounds().top + backButton.getGlobalBounds().height)) {
                    gameState = GameState::MenuStart;
                }
            }
            if (gameState == GameState::LevelSelect) {
                if (event.key.code == Mouse::Left && sf::Mouse::getPosition(window).x > backButton.getGlobalBounds().left &&
                    sf::Mouse::getPosition(window).x < backButton.getGlobalBounds().left +
                    backButton.getGlobalBounds().width && sf::Mouse::getPosition(window).y >
                    backButton.getGlobalBounds().top && sf::Mouse::getPosition(window).y
                    < (backButton.getGlobalBounds().top + backButton.getGlobalBounds().height)) {
                    gameState = GameState::MenuStart;
                }
                if (event.key.code == Mouse::Left && sf::Mouse::getPosition(window).x > level1Button.getGlobalBounds().left &&
                    sf::Mouse::getPosition(window).x < level1Button.getGlobalBounds().left +
                    level1Button.getGlobalBounds().width && sf::Mouse::getPosition(window).y >
                    level1Button.getGlobalBounds().top && sf::Mouse::getPosition(window).y
                    < (level1Button.getGlobalBounds().top + level1Button.getGlobalBounds().height)) {
                    gameState = GameState::Jeu;
                    level = LevelState::Level1;
                }
            }
            if (gameState == GameState::OptionMenu) {
                if (event.key.code == Mouse::Left && sf::Mouse::getPosition(window).x > backButton.getGlobalBounds().left &&
                    sf::Mouse::getPosition(window).x < backButton.getGlobalBounds().left +
                    backButton.getGlobalBounds().width && sf::Mouse::getPosition(window).y >
                    backButton.getGlobalBounds().top && sf::Mouse::getPosition(window).y
                    < (backButton.getGlobalBounds().top + backButton.getGlobalBounds().height)) {
                    gameState = GameState::MenuStart;
                }
            }
            if (gameState == GameState::Pause) {}

            if (gameState == GameState::MenuStart) {
                if (event.key.code == Mouse::Left && sf::Mouse::getPosition(window).x > startButton.getGlobalBounds().left &&
                    sf::Mouse::getPosition(window).x < startButton.getGlobalBounds().left +
                    startButton.getGlobalBounds().width && sf::Mouse::getPosition(window).y >
                    startButton.getGlobalBounds().top && sf::Mouse::getPosition(window).y
                    < (startButton.getGlobalBounds().top + startButton.getGlobalBounds().height)) {
                    gameState = GameState::LevelSelect;
                }
                if (event.key.code == Mouse::Left && sf::Mouse::getPosition(window).x > exitButton.getGlobalBounds().left &&
                    sf::Mouse::getPosition(window).x < exitButton.getGlobalBounds().left +
                    exitButton.getGlobalBounds().width && sf::Mouse::getPosition(window).y >
                    exitButton.getGlobalBounds().top && sf::Mouse::getPosition(window).y
                    < (exitButton.getGlobalBounds().top + exitButton.getGlobalBounds().height)) {
                    window.close();
                }
                if (event.key.code == Mouse::Left && sf::Mouse::getPosition(window).x > editorButton.getGlobalBounds().left &&
                    sf::Mouse::getPosition(window).x < editorButton.getGlobalBounds().left +
                    editorButton.getGlobalBounds().width && sf::Mouse::getPosition(window).y >
                    editorButton.getGlobalBounds().top && sf::Mouse::getPosition(window).y
                    < (editorButton.getGlobalBounds().top + editorButton.getGlobalBounds().height)) {
                    gameState = GameState::levelEditor;
                }
                if (event.key.code == Mouse::Left && sf::Mouse::getPosition(window).x > optionButton.getGlobalBounds().left &&
                    sf::Mouse::getPosition(window).x < optionButton.getGlobalBounds().left +
                    optionButton.getGlobalBounds().width && sf::Mouse::getPosition(window).y >
                    optionButton.getGlobalBounds().top && sf::Mouse::getPosition(window).y
                    < (optionButton.getGlobalBounds().top + optionButton.getGlobalBounds().height)) {
                    gameState = GameState::OptionMenu;
                }
                
            }
            if (gameState == GameState::Jeu) {
                if (event.key.code == Keyboard::Space && personnage.getMunitions() > 0 && dontMove == 0 && ultState == 0 && gameState != GameState::Pause) {
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
                    personnage.setMunitions(32);
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
            float posX = personnage.getPositionX();
            float posY = personnage.getPositionY();
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::P && Game != "ult") {
                    pause = true;
                    gameState = GameState::Pause;
                    personnage.creerPieceRectangle(rectanglePause, Color(255, 255, 255, 150), WIDTH, HEIGHT, 0, 0);
                    window.draw(rectanglePause);
                    window.display();
                }
                if (event.key.code == Keyboard::A) pause = false;
                if (gameState == GameState::Pause && !pause) { // ------------------------------------------------PAUSE-------------------------------------
                    persoSprite.setPosition(posX, posY);
                    gameState = GameState::Jeu;
                }
            }
        }
        //------------------------------------------------------------Obstacles------------------------------------------------------
        if (obstacleClock.getElapsedTime().asSeconds() >= obstacleSpawnInterval) {
            float randomX = static_cast<float>(rand() % static_cast<int>(WIDTH - 50));
            obstacles.emplace_back(randomX, 0, 50, 100, 5.0f, &obstacleTexture);
            obstacleClock.restart();
        }

        for (auto it = obstacles.begin(); it != obstacles.end();) {
            it->move();

            if (it->shape.getGlobalBounds().intersects(persoSprite.getGlobalBounds())) {
                personnage.setVies(personnage.getVies() - 1);
                it = obstacles.erase(it);
                continue;
            }

            if (it->estDansLesLimites(HEIGHT)) {
                it = obstacles.erase(it);
                continue;
            }

            ++it;
        }
        
        window.clear();
        if (gameState == GameState::MenuStart) {

            personnage.creerText(gameName, "MOUNT OLYMPUS", 64, Color::White, WIDTH / 2, HEIGHT / 2, fontMunition);
            gameName.setPosition(WIDTH / 2 - gameName.getGlobalBounds().width / 2, HEIGHT / 2 - gameName.getGlobalBounds().height / 2 - 300);
            startButton.setPosition(WIDTH / 2 - startButton.getGlobalBounds().width / 2 - 200, HEIGHT / 2 - startButton.getGlobalBounds().height / 2 - 100);
            optionButton.setPosition(WIDTH / 2 - startButton.getGlobalBounds().width / 2 + 200, HEIGHT / 2 - startButton.getGlobalBounds().height / 2 - 100);
            exitButton.setPosition(WIDTH / 2 - startButton.getGlobalBounds().width / 2 + 200, HEIGHT / 2 - startButton.getGlobalBounds().height / 2 + 100);
            editorButton.setPosition(WIDTH / 2 - startButton.getGlobalBounds().width / 2 - 200, HEIGHT / 2 - startButton.getGlobalBounds().height / 2 + 100);

            window.draw(gameName);
            window.draw(startButton);
            window.draw(exitButton);
            window.draw(optionButton);
            window.draw(editorButton);
        }

        if (gameState == GameState::GameOver) {
            backButton.setPosition(WIDTH / 2 - backButton.getGlobalBounds().width / 2 - 400, HEIGHT / 2 - backButton.getGlobalBounds().height / 2 + 350);
            backButton.setScale(.4f, .4f);
            window.draw(backButton);
        }
        if (gameState == GameState::levelEditor) {
            
            backButton.setPosition(WIDTH / 2 - backButton.getGlobalBounds().width / 2 - 400, HEIGHT / 2 - backButton.getGlobalBounds().height / 2 + 350);

            backButton.setScale(.4f, .4f);
            window.draw(backButton);

        }
        if (gameState == GameState::LevelSelect) {
            
            backButton.setPosition(WIDTH / 2 - backButton.getGlobalBounds().width / 2 - 400, HEIGHT / 2 - backButton.getGlobalBounds().height / 2 + 350);
            level1Button.setPosition(WIDTH / 2 - backButton.getGlobalBounds().width / 2 - 400, HEIGHT / 2 - backButton.getGlobalBounds().height / 2);
            backButton.setScale(.4f, .4f);
            level1Button.setScale(.3f, .3f);
            window.draw(backButton);
            window.draw(level1Button);
        }
        if (gameState == GameState::OptionMenu) {
            
            backButton.setPosition(WIDTH / 2 - backButton.getGlobalBounds().width / 2 - 400, HEIGHT / 2 - backButton.getGlobalBounds().height / 2 + 350);
            backButton.setScale(.4f, .4f);
            window.draw(backButton);


        }
        if (gameState == GameState::Jeu && gameState != GameState::Pause) {
            if (level == LevelState::Level1) {
                if (personnage.vies == 0) {
                    window.clear();
                    gameState = GameState::GameOver;
                }
                if (enAttaquePerso == 100) {
                    enAttaquePerso = 0;
                }

                if (personnage.getVies() == 3) { resize(viesTextureFull, viesSprite, 100.0f, 70.0f); }
                if (personnage.getVies() == 2) { resize(viesTexture2, viesSprite, 100.0f, 70.0f); }
                if (personnage.getVies() == 1) { resize(viesTexture1, viesSprite, 100.0f, 70.0f); }
                if (personnage.getVies() == 0) { resize(viesTexture0, viesSprite, 100.0f, 70.0f); }

                viesSprite.setPosition(joueur.getPosition().x - TAILLEX / 4, joueur.getPosition().y + TAILLEY / 2);
                if (Game == "ult") {
                    int vies = personnage.getVies();
                    if (ultState == 1) {
                        persoSprite.move(0.0f, -15.0f);
                        if (persoSprite.getPosition().y <= TAILLEY + 20) { ultState = 2; }
                    }
                    if (ultState == 2) {
                        float centerX = persoSprite.getPosition().x + persoSprite.getGlobalBounds().width / 2 + TAILLEX / 2;
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

                for (const auto& obstacle : obstacles) { //---afficher les obstacles------------------------
                    window.draw(obstacle.shape);
                }

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
                personnage.creerText(textMunitions, to_string(personnage.getMunitions()), 30, Color::Black, WIDTH - WIDTH / 3 + 32 * 7 + 30, HEIGHT - 73, fontMunition);

                window.draw(textMunitions);
                window.draw(rectangleMunitions);
                window.draw(rectangleMunitionsOutLine);

                if (enAttaque > 0) { window.draw(persoSpriteAtt); enAttaque++; }
                if (enAttaque >= enAttaqueMax) { enAttaque = 0;  window.draw(persoSprite); }
                

                window.draw(textMunitions);
                window.draw(textUlt);
                ultSprite.setTexture(ultTexture);
                window.draw(ultSprite);
                if (vague == VagueState::Vague1) {

                   

                }
                if (vague == VagueState::Vague2) {

                }
                if (vague == VagueState::Vague3) {

                }
                if (vague == VagueState::Vague4) {

                }
                if (vague == VagueState::Boss) {
                    if (pose.size() > 0) {
                        for (auto it = pose.begin(); it != pose.end();) {
                            window.draw(it->poseidon);
                            if (it->vies == 0) {
                                it = pose.erase(it);
                                gameState = GameState::MenuStart;
                                continue;
                            }

                            for (auto& munition : personnage.mun) {
                                if (it->poseidon.getGlobalBounds().intersects(munition.mun.getGlobalBounds())) {
                                    cout << it->vies;

                                    it->vies--;
                                    personnage.score += 1;
                                }
                                if (it->poseidon.getGlobalBounds().intersects(munition.mun.getGlobalBounds())) { cout << it->vies, it->vies--; personnage.score += 1; }
                            }

                            it++;
                        }
                    }
                }
                
                for (auto it = hermes.begin(); it != hermes.end();) {
                    if (enAttaquePerso == 1) {
                        it->attaque(joueur, window, spriteAnimation);

                    }
                    for (auto& munition : it->mun) {
                        munition.mun.setTexture(munition.textureMun);
                        window.draw(munition.mun);

                        munition.mun.move(0.f, 5.f);

                        if (munition.mun.getGlobalBounds().intersects(persoSprite.getGlobalBounds())) {
                            personnage.vies -= 1;
                        }
                    }
                    window.draw(it->hermes);

                    if (it->vie == 0) {
                        int randPowerUp = rand() % 10;
                        ultime += 5.f;
                        if (randPowerUp == 2) { power1.push_back(PowerUp(it->hermes.getPosition().x, it->hermes.getPosition().y, 1, powerUpTexture1)); }
                        if (randPowerUp == 4) { power2.push_back(PowerUp(it->hermes.getPosition().x, it->hermes.getPosition().y, 2, powerUpTexture2)); }
                        if (randPowerUp == 6) { power3.push_back(PowerUp(it->hermes.getPosition().x, it->hermes.getPosition().y, 3, powerUpTexture3)); }
                        it = hermes.erase(it);
                        continue;
                    }

                    for (auto& munition : personnage.mun) {
                        if (it->hermes.getGlobalBounds().intersects(munition.mun.getGlobalBounds())) { it->vie -= 1; personnage.score += 1; }
                    }
                    it++;
                }
                for (auto it = power1.begin(); it != power1.end();) {
                    window.draw(it->powerUp);
                    it->powerUp.move(0, 2.5f);

                    if (it->powerUp.getGlobalBounds().intersects(persoSprite.getGlobalBounds())) { personnage.setMunitions(50); it = power1.erase(it); continue; }
                    it++;
                }
                for (auto it = power2.begin(); it != power2.end();) {
                    window.draw(it->powerUp);
                    it->powerUp.move(0, 2.5f);

                    if (it->powerUp.getGlobalBounds().intersects(persoSprite.getGlobalBounds())) { enAttaqueMax = 1; it = power2.erase(it); continue; }
                    it++;
                }
                for (auto it = power3.begin(); it != power3.end();) {
                    window.draw(it->powerUp);
                    it->powerUp.move(0, 2.5f);

                    if (it->powerUp.getGlobalBounds().intersects(persoSprite.getGlobalBounds())) { enAttaqueMax = 1; it = power3.erase(it); continue; }
                    it++;
                }
                hermes1.patern(hermes, 50, 50, 100, 100, 2.f);//--------------------------Deplacemment des ennemis----------------------------------------------------------------------
                window.draw(viesSprite);

                moveBg(bg2Sprite, 0.0f, -0.5f);
                if (bg2Sprite.getPosition().y > 0) bg2Sprite.setPosition(Vector2f(0, -HEIGHT));
                moveBg(bg3Sprite, 0.0f, -2.0f);
                if (bg3Sprite.getPosition().y > 0) bg3Sprite.setPosition(Vector2f(0, -HEIGHT * 2));
                if (ultState == 2) { window.draw(dgtultSprite); }
                window.draw(persoSprite);
            }
            

                  
            
        }
        window.display();
    }
}

