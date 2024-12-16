#ifndef POWERUP_HPP
#define POWERUP_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <SFML/Audio.hpp>

using namespace std;


class PowerUp {
public:
	float x, y;
	int type;
	sf::Sprite powerUp;

	PowerUp(float posX, float posY, int type, sf::Texture& texture) {
		powerUp.setTexture(texture);
		powerUp.setPosition(posX, posY);
		powerUp.setScale(sf::Vector2f(0.2f, 0.2f));


	}
	void deplacer();  //augmente les tirs par seconde



};

#endif