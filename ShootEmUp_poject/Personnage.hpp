#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP
using namespace std;
using namespace sf;

class Personnage {
    int vies;
    int munitions;
    float tauxUtlime;
    int x, y;

    void deplacement();
    void attaque();
    void ult();
    void setVies(int nouvelleVie);
    void setMunitions(int nouvelleMunition);
    void setTauxUtlime(int NouveauTauxUlt);
    int getVies();
    int getMunitions();
    float getTauxUltime(); 
    void creerPieceRectangle(RectangleShape& rectangle,Color& color, int longueur, int largeur, int x, int y);
};


#endif