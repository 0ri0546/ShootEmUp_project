#include "Personnage.hpp"

using namespace sf;
Keyboard keyboard;
Personnage::Personnage() {};
Personnage::Personnage(int vies, int munitions, float tauxUltime, float x, float y) : vies(vies), munitions(munitions), tauxUtlime(tauxUltime), x(x), y(y) {};

void Personnage::deplacerVers(RectangleShape& rectangle, Event event, RenderWindow& window) {
    Vector2i posMouse = Mouse::getPosition(window);
    Vector2f vec = sf::Vector2f(posMouse);

    /*int distanceX = posMouse.y - rectangle.getPosition().y;
    int distanceY = posMouse.y - rectangle.getPosition().y;
    rectangle.move(distanceX, distanceY);*/

    float velocity = 1.0f;
    float norme = sqrt(vec.x * vec.x + vec.y * vec.y);
    vec = vec / norme;
    Vector2f direction = (vec - rectangle.getPosition());
    rectangle.move(direction * velocity);
}

void Personnage::deplacement(RectangleShape& rectangle,Event event, RenderWindow& window) {
    //Déplacement : Le personnage se déplace uniquement grâce au clic de la souris, dans un style hack n slash.
    //set le sprite de move pour une animation de deplacement
    Vector2i posMouse = Mouse::getPosition(window);
    
    if (Mouse::isButtonPressed(Mouse::Left) && posMouse.x > 0 && posMouse.x < WIDTH && posMouse.y < HEIGHT) {
        /*deplacerVers(rectangle, event, window);*/
        rectangle.setPosition(posMouse.x - TAILLEX / 2, max(posMouse.y - TAILLEY / 2, HEIGHT /2));
        cout << posMouse.x << ", " << posMouse.y << endl;
        cout << rectangle.getPosition().x <<", " << posMouse.y << endl << endl;
    }
}
void Personnage::attaque(RectangleShape& rectangle, Event event, RenderWindow& window) {
    Personnage personnage;
    //Tir automatique en maintenant une touche ou un bouton enfoncé jusqu'à ce que le nombre de charge soit vide.
    
    for (auto it = mun.begin(); it != mun.end(); ) {
        cout << "lance" << endl;
        Texture test;
        test.loadFromFile("munition.png");
        it->mun.setTexture(test);
        window.draw(it->mun);
        it->mun.move(0.f, -30.f);

        if (it->mun.getPosition().y < 0) {
            it = mun.erase(it);
        }
        else {
            ++it;
        }
    }
    /*for (auto& elem : mun) {
        cout << elem.getPosX() << endl;
    }*/
    
}
void Personnage::ult() {
    //Saute sur les ennemis avec un gros marteau, fait des degats de zone. invincible durant cette période.

}

void Personnage::setTexture(RectangleShape& rectangle, const Texture *texture) {
    //Saute sur les ennemis avec un gros marteau, fait des degats de zone. invincible durant cette période.
    rectangle.setTexture(texture);
}
void Personnage::creerPieceRectangle(RectangleShape& rectangle,Color color, int longueur, int largeur, float x, float y) {
    rectangle.setSize(Vector2f(longueur, largeur));
    rectangle.setFillColor(color);
    rectangle.setOutlineColor(Color::Black);
    rectangle.setOutlineThickness(3);
    rectangle.setPosition(x, y);
}

void Personnage::creerText(Text& text, const std::string& texte, int charSize, const sf::Color& color, float x, float y) {
    text.setString(texte);
    text.setCharacterSize(charSize);
    text.setFillColor(color);
    text.setPosition(x, y);
}

void Personnage::setVies(int nouvelleVie) { vies = nouvelleVie; }
void Personnage::setMunitions(int nouvelleMunition) { munitions = nouvelleMunition; }
void Personnage::setTauxUtlime(float NouveauTauxUlt) { tauxUtlime = NouveauTauxUlt; }

int Personnage::getVies() { return vies; }
int Personnage::getMunitions() { return munitions; }
float Personnage::getTauxUltime() { return tauxUtlime; }