#ifndef COUPLEGAUX_HPP
#define COUPLEGAUX_HPP
#include <vector>
#include "Coord.hpp"
#include "Coup.hpp"
#include "Echiquier.hpp"

class CoupLegaux{
private:
Echiquier _echiquier;
std::vector<Coup> _coupLegauxBlanc;
std::vector<Coup> _coupLegauxNoir;
Coup _dernierCoup;

public:
CoupLegaux();
void allCoupLegaux(bool);
void getCoupPiece(Coord, char);

std::vector<Coup> getCoupCavalier(Coord, char) const;
std::vector<Coup> getCoupTour(Coord, char) const;
std::vector<Coup> getCoupFou(Coord, char) const;
std::vector<Coup> getCoupDame(Coord, char) const;
std::vector<Coup> getCoupRoi(Coord, char) const;
std::vector<Coup> getCoupPion(Coord, char) const;

void move(int index, char couleur);
};

#endif