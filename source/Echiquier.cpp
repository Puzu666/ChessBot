#include <iostream>
#include "Echiquier.hpp"

Echiquier::Echiquier()
{
}

bool Echiquier::move(Piece piece, Coord coordIni, Coord coordFin)
{
    if(this->_plateau[coordIni.lettre][coordIni.numero].type == piece.type){
        this->_plateau[coordIni.lettre][coordIni.numero].type = Piece::Type::VIDE;
        this->_plateau[coordFin.lettre][coordFin.numero].type == piece.type;
        return true;
    }
    return false;
}
