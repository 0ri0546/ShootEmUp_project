#ifndef ENNEMIFAIBLE_HPP
#define ENNEMIFAIBLE_HPP
using namespace std;

class EnnemiMoyen {
    int vies = 2;
    int celerite = 2;

    void deplacement();
    void attaque();
    void incr_score();
    void drop();
    void setVies(int nouvelleVies);
    int getVies();
};

#endif