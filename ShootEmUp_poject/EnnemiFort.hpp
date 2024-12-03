#ifndef ENNEMIFAIBLE_HPP
#define ENNEMIFAIBLE_HPP
using namespace std;

class EnnemiFort {
private:
    int vies = 3;
    int celerite = 1;
public:
    void deplacement();
    void attaque();
    void incr_score();
    void drop();

    void setVies(int nouvelleVies);
    int getVies();
};

#endif