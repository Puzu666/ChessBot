#include <iostream>
#include "Echiquier.hpp"
#include <array>

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

bool Echiquier::setCase(Coord coordonnee, Piece piece)
{
    if(coordonnee.estValide()){
        this->_plateau[coordonnee.lettre][coordonnee.numero] = piece;
        return true;
    }
    return false;
}

bool Echiquier::setPlateau(std::array<Piece, 64> pieces)
{
    Coord coordonnee = { 0, 0};

    bool roiBlanc;
    bool roiNoir;

    for(size_t i = 0; i < 64; i++){
        this->setCase(coordonnee, pieces[i]);

        if(this->getCase(coordonnee).type == Piece::Type::ROI_BLANC){
            roiBlanc = true;
        }

        if(this->getCase(coordonnee).type == Piece::Type::ROI_NOIR){
            roiNoir = true;
        }

        coordonnee.lettre++;
        if(coordonnee.lettre >= 8){
            coordonnee.lettre = 0;
            coordonnee.numero++;
        }
    }
    return roiBlanc & roiNoir;
}
