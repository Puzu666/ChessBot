#include <iostream>
#include "Echiquier.hpp"

Echiquier::Echiquier()
{
}

bool Echiquier::move(Piece piece, Coord coordIni, Coord coordFin, Piece promotion)
{
    if(this->_plateau[coordIni.lettre][coordIni.numero].type == piece.type){
        this->_plateau[coordIni.lettre][coordIni.numero].type = Piece::Type::VIDE;
        if(promotion.type == Piece::Type::VIDE){
            this->_plateau[coordFin.lettre][coordFin.numero].type = piece.type;
        }
        else{
            this->_plateau[coordFin.lettre][coordFin.numero].type = promotion.type;
        }
        return true;
    }
    return false;
}
