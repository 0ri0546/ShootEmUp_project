#ifndef ENNEMIFAIBLE_HPP
#define ENNEMIFAIBLE_HPP

using namespace std;

class EnnemiFaible {
    int vies = 1;
    int celerite = 3;

    void deplacement();
    void attaque();
    void incr_score();
    void drop();
    void setVies(int nouvelleVies);
    int getVies();
};

#endif