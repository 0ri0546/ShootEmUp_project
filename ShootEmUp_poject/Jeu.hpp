#ifndef JEU_HPP
#define JEU_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <SFML/Audio.hpp>
#include <ctime>

#include "Personnage.hpp"

using namespace std;
using namespace sf;

class Jeu {
private:
    int score;
    RectangleShape joueur, zoneDepl, bg1, bg2, bg3;
    CircleShape ultArea;
    time_t start, end;
    Text textMunitions, textVie, textUlt, textWave, textLevel, textRecharge;
    Sprite persoSprite, persoSpriteAtt, viesSpriteFull, viesSprite0, viesSprite1, viesSprite2;
    Texture persoTexture, persoTextureAtt, viesTextureFull, viesTexture0, viesTexture1, viesTexture2, bg1Texture, bg2Texture, bg3Texture;
    Mouse mouse;
    Personnage personnage;
    int enAttaque = 0;

public:
    Jeu(const int score);
    void boucleDeJeu();
    void resize(Texture& texture, Sprite& sprite, float scaleX, float scaleY);
    void moveBg(Sprite& sprite, float speedX, float speedY);
};

#endif