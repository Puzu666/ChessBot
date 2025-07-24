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

constexpr bool _verifCase(Coord coordonnee, Piece piece) const{
    return this->_echiquier.getCase(coordonnee).couleur() != piece.couleur();
}

std::vector<Coup> getCoupPiece(Coord, Piece);

std::vector<Coup> getCoupCavalier(Coord, Piece) const;
std::vector<Coup> getCoupTour(Coord, Piece) const;
std::vector<Coup> getCoupFou(Coord, Piece) const;
std::vector<Coup> getCoupDame(Coord, Piece) const;
std::vector<Coup> getCoupRoi(Coord, Piece) const;
std::vector<Coup> getCoupPion(Coord, Piece) const;
std::vector<Coup> getCoupPromotion(Coord, Piece) const;

public:
CoupLegaux();
void allCoupLegaux();

int getLettrePremCoup() const;
void move(Coup);

std::vector<Coup> getVectorCoupLegaux(bool couleur);

void setEchiquier(Echiquier);
};

#endif