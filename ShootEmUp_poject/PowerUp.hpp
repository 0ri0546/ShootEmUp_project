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
	string type;
	void cadenceDeTir();  //augmente les tirs par seconde
	void upChargeur(); //augmente la capacité du chargeur
	void MultiShot(); //tire en diagonale
	void bouclier(); //invincible pendant x secondes
	void gel(); //arret du mouvement des ennemis

	string getType();
};

#endif