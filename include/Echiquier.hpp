#ifndef ECHIQUIER_HPP
#define ECHIQUIER_HPP
#include <cstdint>

class Echiquier{
private:
char _plateau[8][8];

public:
Echiquier();
char getCase(int, int);
//Pour debuger, à retirer une fois le programme terminé
void printEchiquier() const;
};

#endif