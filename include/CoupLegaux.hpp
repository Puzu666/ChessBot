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
void getCoupPiece(Coord, Piece);

std::vector<Coup> getCoupCavalier(Coord, Piece) const;
std::vector<Coup> getCoupTour(Coord, Piece) const;
std::vector<Coup> getCoupFou(Coord, Piece) const;
std::vector<Coup> getCoupDame(Coord, Piece) const;
std::vector<Coup> getCoupRoi(Coord, Piece) const;
std::vector<Coup> getCoupPion(Coord, Piece) const;

void move(int index, char couleur);
};

#endif