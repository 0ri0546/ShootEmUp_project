#include "Personnage.hpp"

using namespace sf;
Keyboard keyboard;
Personnage::Personnage() {
};
Personnage::Personnage(int vies, int munitions, float tauxUltime, float x, float y) : vies(vies), munitions(munitions), tauxUtlime(tauxUltime), x(x), y(y) {

};

void Personnage::deplacement(RectangleShape& rectangle, Event event, RenderWindow& window) {
    static Vector2f targetPosition = rectangle.getPosition();
    static sf::Clock clock;
    float velocity = 200.f;
    const float stopThreshold = 5.f;
    const float maxX = WIDTH; // Limite maximale en X
    const float maxY = HEIGHT / 2.f;

    if (Mouse::isButtonPressed(Mouse::Left)) {
        Vector2i posMouse = Mouse::getPosition(window);
        if (posMouse.x > 0 && posMouse.x < WIDTH && posMouse.y > 0 && posMouse.y < HEIGHT) {
            targetPosition = Vector2f(posMouse) - Vector2f(TAILLEX / 2, TAILLEY / 2);
            if (targetPosition.y < 0) targetPosition.y = 0;
            if (targetPosition.y < maxY) targetPosition.y = maxY;
        }
    }

    float deltaTime = clock.restart().asSeconds();

    Vector2f currentPosition = rectangle.getPosition();
    Vector2f direction = targetPosition - currentPosition;
    float distance = sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance > stopThreshold) {
        direction /= distance; 
        rectangle.move(direction * velocity * deltaTime); 
    }
    else {
        rectangle.setPosition(targetPosition); // S'assure que la position finale est exacte
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