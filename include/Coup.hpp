#ifndef COUP_H
#define COUP_H
#include "Coord.hpp"
#include "Piece.hpp"

struct Coup{
    Coord posIni;
    Coord posFin;
    Piece piece;
    Piece promotion;
};

#endif