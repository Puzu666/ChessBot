#ifndef ECHIQUIER_HPP
#define ECHIQUIER_HPP
#include <cstdint>

class Echiquier{
private:
char _plateau[8][8]={
        {'T','P','v','v','v','v','p','t'},
        {'C','P','v','v','v','v','p','c'},
        {'F','P','v','v','v','v','p','f'},
        {'D','P','v','v','v','v','p','d'},
        {'R','P','v','v','v','v','p','r'},
        {'F','P','v','v','v','v','p','f'},
        {'C','P','v','v','v','v','p','c'},
        {'T','P','v','v','v','v','p','t'}
    };

public:
Echiquier();
constexpr char getCase(int lettre, int numero) const
{
    return this->_plateau[lettre][numero];
}

bool move(char piece, int lettreInitial, int numeroInitial, int lettreFinal, int numeroFinal);
//Pour debuger, à retirer une fois le programme terminé
void printEchiquier() const;
};

#endif