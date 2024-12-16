#ifndef JEU_HPP
#define JEU_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <SFML/Audio.hpp>
#include <ctime>

#include "Obstacle.hpp"
#include "Hermes.hpp"
#include "PowerUp.hpp"
using namespace std;
using namespace sf;

class Jeu {
private:
    int score;
    int chargeurMax = 32;
    RectangleShape joueur, zoneDepl, bg1, bg2, bg3, rectangleRecharge, rectangleMunitions, rectangleMunitionsOutLine;
    CircleShape ultArea;
    time_t start, end;
    Text textMunitions, textVie, textUlt, textWave, textLevel, textRecharge, gameName;
    Sprite persoSprite, persoSpriteAtt, viesSprite, ultSprite, dgtultSprite, startButton, optionButton, exitButton, editorButton;
    Texture persoTexture, persoTextureAtt, viesTextureFull, viesTexture0, viesTexture1, viesTexture2, bg1Texture, bg2Texture, bg3Texture, hermesText, ultTexture, dgtultTexture, startTexture, optionTexture, exitTexture, editorTexture, powerUpTexture1, powerUpTexture2, powerUpTexture3;
    Mouse mouse;
    Personnage personnage;
    int enAttaque = 0;
    
    int ultime = 0;
    int enAttaqueMax=20;
    bool firstDep = true;
    Color couleurAvecOpacite = Color(255, 255, 255, 220);
public:
    int enAttaquePerso = 0;
    Jeu(const int score);
    void boucleDeJeu();
    void resize(Texture& texture, Sprite& sprite, float scaleX, float scaleY);
    void moveBg(Sprite& sprite, float speedX, float speedY);
};

#endif