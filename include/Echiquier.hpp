#ifndef ECHIQUIER_HPP
#define ECHIQUIER_HPP
#include <cstdint>
#include "Coord.hpp"
#include "Piece.hpp"

class Echiquier{
private:
Piece _plateau[8][8] = {
    {Piece::Type::TOUR_BLANC, Piece::Type::PION_BLANC, Piece::Type::VIDE, Piece::Type::VIDE, 
        Piece::Type::VIDE, Piece::Type::VIDE, Piece::Type::PION_NOIR, Piece::Type::TOUR_NOIR},
    {Piece::Type::CAVALIER_BLANC, Piece::Type::PION_BLANC, Piece::Type::VIDE, Piece::Type::VIDE, 
        Piece::Type::VIDE, Piece::Type::VIDE, Piece::Type::PION_NOIR, Piece::Type::CAVALIER_NOIR},
    {Piece::Type::FOU_BLANC, Piece::Type::PION_BLANC, Piece::Type::VIDE, Piece::Type::VIDE, 
        Piece::Type::VIDE, Piece::Type::VIDE, Piece::Type::PION_NOIR, Piece::Type::FOU_NOIR},
    {Piece::Type::DAME_BLANC, Piece::Type::PION_BLANC, Piece::Type::VIDE, Piece::Type::VIDE, 
        Piece::Type::VIDE, Piece::Type::VIDE, Piece::Type::PION_NOIR, Piece::Type::DAME_NOIR},
    {Piece::Type::ROI_BLANC, Piece::Type::PION_BLANC, Piece::Type::VIDE, Piece::Type::VIDE, 
        Piece::Type::VIDE, Piece::Type::VIDE, Piece::Type::PION_NOIR, Piece::Type::ROI_NOIR},
    {Piece::Type::FOU_BLANC, Piece::Type::PION_BLANC, Piece::Type::VIDE, Piece::Type::VIDE, 
        Piece::Type::VIDE, Piece::Type::VIDE, Piece::Type::PION_NOIR, Piece::Type::FOU_NOIR},
    {Piece::Type::CAVALIER_BLANC, Piece::Type::PION_BLANC, Piece::Type::VIDE, Piece::Type::VIDE, 
        Piece::Type::VIDE, Piece::Type::VIDE, Piece::Type::PION_NOIR, Piece::Type::CAVALIER_NOIR},
    {Piece::Type::TOUR_BLANC, Piece::Type::PION_BLANC, Piece::Type::VIDE, Piece::Type::VIDE, 
        Piece::Type::VIDE, Piece::Type::VIDE, Piece::Type::PION_NOIR, Piece::Type::TOUR_NOIR},
};

public:
Echiquier();
constexpr Piece getCase(Coord coordonnee) const
{
    return this->_plateau[coordonnee.lettre][coordonnee.numero];
}

bool move(Piece piece, Coord coordIni, Coord coordFin, Piece promotion);
};

#endif