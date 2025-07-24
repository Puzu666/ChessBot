#include "Evaluation.hpp"
#include <array>
#include <limits>

void Evaluation::_materielBrute()
{
    Coord tempCoord;
    Piece elem;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            tempCoord = { i, j};
            elem = this->_echiquier.getCase(tempCoord);

            switch(elem.type){
                case Piece::Type::CAVALIER_BLANC:
                case Piece::Type::FOU_BLANC:
                this->_avantage += 3;
                break;

                case Piece::Type::CAVALIER_NOIR:
                case Piece::Type::FOU_NOIR:
                this->_avantage -= 3;
                break;

                case Piece::Type::TOUR_BLANC:
                this->_avantage += 5;
                break;

                case Piece::Type::DAME_BLANC:
                this->_avantage += 9;
                break;

                case Piece::Type::PION_BLANC:
                this->_avantage += 1;
                break;

                case Piece::Type::TOUR_NOIR:
                this->_avantage -= 5;
                break;

                case Piece::Type::DAME_NOIR:
                this->_avantage -= 9;
                break;

                case Piece::Type::PION_NOIR:
                this->_avantage -= 1;
                break;
            }
        }
    }
}

void Evaluation::_verifRoi()
{
    Coord tempCoord;
    std::pair<bool, bool> rois = { false, false };
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            tempCoord = { i, j };
            if(this->_echiquier.getCase(tempCoord).type == Piece::Type::ROI_BLANC){
                rois.first = true;
            } 

            if(this->_echiquier.getCase(tempCoord).type == Piece::Type::ROI_NOIR){
                rois.second = true;
            } 
        }
    }

    if(!rois.first){
        this->_avantage = std::numeric_limits<float>::infinity();
    }

    if(!rois.second){
        this->_avantage = -std::numeric_limits<float>::infinity();
    }
}

void Evaluation::_coupPossible()
{
    float temp = this->_coupLegaux.getVectorCoupLegaux(true).size() - this->_coupLegaux.getVectorCoupLegaux(false).size();
    temp /= 10;
    this->_avantage += temp;
}

float Evaluation::_controleDuCentre()
{
    std::vector<Coup> tempBlanc = this->_coupLegaux.getVectorCoupLegaux(true);
    std::vector<Coup> tempNoir = this->_coupLegaux.getVectorCoupLegaux(false);

    Coord tempCoord = { 3, 3 };

    float temp = 0;
    for(size_t i = 0; i < tempBlanc.size(); i++){
        if(tempBlanc[i].posFin.estPareil(tempCoord)){
            temp++;
        }
        tempCoord.lettre++;
        if(tempBlanc[i].posFin.estPareil(tempCoord)){
            temp++;
        }
        tempCoord.numero++;
        if(tempBlanc[i].posFin.estPareil(tempCoord)){
            temp++;
        }
        tempCoord.lettre--;
        if(tempBlanc[i].posFin.estPareil(tempCoord)){
            temp++;
        }
        tempCoord.lettre--;
    }

    for(size_t i = 0; i < tempNoir.size(); i++){
        if(tempNoir[i].posFin.estPareil(tempCoord)){
            temp--;
        }
        tempCoord.lettre++;
        if(tempNoir[i].posFin.estPareil(tempCoord)){
            temp--;
        }
        tempCoord.numero++;
        if(tempNoir[i].posFin.estPareil(tempCoord)){
            temp--;
        }
        tempCoord.lettre--;
        if(tempNoir[i].posFin.estPareil(tempCoord)){
            temp--;
        }
        tempCoord.lettre--;
    }
    return temp / 10;
}

int Evaluation::_pieceTotal()
{
    Coord tempCoord;
    int nbPiece = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            tempCoord = { i, j };
            if(this->_echiquier.getCase(tempCoord).type != Piece::Type::VIDE && 
               this->_echiquier.getCase(tempCoord).type != Piece::Type::PION_BLANC &&
               this->_echiquier.getCase(tempCoord).type != Piece::Type::PION_NOIR){
                nbPiece++;
            }
        }
    }
    return 0;
}

Evaluation::Evaluation()
{
    this->_avantage = 0;
    this->_coupLegaux.setEchiquier(this->_echiquier);
    this->_coupLegaux.allCoupLegaux();
}

void Evaluation::calculAvantage(bool couleur)
{
    this->_verifRoi();

    if(this->_avantage != std::numeric_limits<float>::infinity() && this->_avantage != -std::numeric_limits<float>::infinity()){
        this->_materielBrute();

        if(this->_pieceTotal() > 8){
            this->_coupPossible();
        }        
    }
}
