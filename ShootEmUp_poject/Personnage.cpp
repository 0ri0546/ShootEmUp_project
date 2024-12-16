#include "Personnage.hpp"

using namespace sf;
Keyboard keyboard;
Font font;
Personnage::Personnage() {
};
Personnage::Personnage(int vies, int munitions, float tauxUltime, float x, float y) : vies(vies), munitions(munitions), tauxUtlime(tauxUltime), x(x), y(y) {

};

void Personnage::deplacement(RectangleShape& rectangle, Event event, RenderWindow& window) {
    static Vector2f targetPosition = rectangle.getPosition();
    static sf::Clock clock;
    float velocity = 400.f;
    const float stopThreshold = 5.f;
    const float maxX = WIDTH; 
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
        rectangle.setPosition(targetPosition);
    }
}

bool Personnage::attaque(RectangleShape& rectangle, Event event, RenderWindow& window, int spriteAnimation, vector<Hermes> hermes) {
    for (auto it = mun.begin(); it != mun.end(); ) {
        Texture test;

        if (spriteAnimation <= 10) { test.loadFromFile("fleche1.png"); }
        else if (spriteAnimation <= 20) { test.loadFromFile("fleche2.png"); }
        else if (spriteAnimation <= 30) { test.loadFromFile("fleche3.png"); }
        else if (spriteAnimation <= 40) { test.loadFromFile("fleche4.png"); }
        else if (spriteAnimation <= 50) { test.loadFromFile("fleche5.png"); }
        else if (spriteAnimation <= 60) { test.loadFromFile("fleche6.png"); }
        else if (spriteAnimation <= 70) { test.loadFromFile("fleche7.png"); }
        it->mun.setTexture(test);
        
        window.draw(it->mun);
        it->mun.move(0.f, -10.f);

        if (it->mun.getPosition().y + test.getSize().y + 20 < 0) { it = mun.erase(it); }


        else { ++it; }
        Vector2f pos = it->mun.getPosition();
    }

    /*for (auto& elem : mun) {
        cout << elem.getPosX() << endl;
    }*/
    return true;
}

void Personnage::ult(RectangleShape& rectangle, Event event, RenderWindow& window) {
    //Saute sur les ennemis avec un gros marteau, fait des degats de zone. invincible durant cette période.
    cout << "ultime !" << endl;
    if (rectangle.getPosition().y > 20)
    {
        rectangle.move(0.f, -10.f);
    }
    else if (rectangle.getPosition().y <= 20)
    {
        // kill dans un rayon de 20
    }
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

void Personnage::creerText(Text& text, const std::string& texte, int charSize, const sf::Color& color, float x, float y, Font& font) {
    text.setString(texte);
    text.setCharacterSize(charSize);
    text.setFillColor(color);
    text.setPosition(x, y);
    text.setFont(font);
}

void Personnage::setVies(int nouvelleVie) { vies = nouvelleVie; }
void Personnage::setMunitions(int nouvelleMunition) { munitions = nouvelleMunition; }
void Personnage::setTauxUtlime(float NouveauTauxUlt) { tauxUtlime = NouveauTauxUlt; }

int Personnage::getVies() { return vies; }
int Personnage::getMunitions() { return munitions; }
float Personnage::getTauxUltime() { return tauxUtlime; }
float Personnage::getPositionX() { return x; }
float Personnage::getPositionY() { return y; }