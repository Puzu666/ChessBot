#include "CoupLegaux.hpp"
#include <cassert>
#include <array>

CoupLegaux::CoupLegaux()
{
    this->_dernierCoup.posIni.lettre = -1;
    this->_dernierCoup.posIni.numero = -1;
    this->_dernierCoup.posFin.lettre = -1;
    this->_dernierCoup.posFin.numero = -1;
    this->_dernierCoup.piece.type = Piece::Type::VIDE;
    this->_dernierCoup.promotion.type = Piece::Type::VIDE;
}

//true==blanc; false==noir
void CoupLegaux::allCoupLegaux()
{
    Piece pieceTemp;
    Coord coordTemp;
    std::vector<Coup> tempVector;

    this->_coupLegauxBlanc.clear();
    this->_coupLegauxNoir.clear();

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            coordTemp = { i, j };
            pieceTemp = this->_echiquier.getCase(coordTemp);

            switch(this->_echiquier.getCase(coordTemp).couleur()){
                case 'B':
                tempVector = this->getCoupPiece(coordTemp, pieceTemp);
                this->_coupLegauxBlanc.insert(this->_coupLegauxBlanc.end(), tempVector.begin(), tempVector.end());
                break;

                case 'n':
                tempVector = this->getCoupPiece(coordTemp, pieceTemp);
                this->_coupLegauxNoir.insert(this->_coupLegauxNoir.end(), tempVector.begin(), tempVector.end());
                break;

                default:
                break;
            }
        }
    }
}

std::vector<Coup> CoupLegaux::getCoupPiece(Coord coordonnee, Piece piece)
{
    Piece::Type tempType = piece.type;
    std::vector<Coup> tempCoupVec;

    switch(tempType){
        case Piece::Type::CAVALIER_BLANC:
        case Piece::Type::CAVALIER_NOIR:
        tempCoupVec = getCoupCavalier(coordonnee, piece);
        break;
        case Piece::Type::TOUR_BLANC:
        case Piece::Type::TOUR_NOIR:
        tempCoupVec = getCoupTour(coordonnee, piece);
        break;
        case Piece::Type::DAME_BLANC:
        case Piece::Type::DAME_NOIR:
        tempCoupVec = getCoupDame(coordonnee, piece);
        break;
        case Piece::Type::FOU_BLANC:
        case Piece::Type::FOU_NOIR:
        tempCoupVec = getCoupFou(coordonnee, piece);
        break;
        case Piece::Type::ROI_BLANC:
        case Piece::Type::ROI_NOIR:
        tempCoupVec = getCoupRoi(coordonnee, piece);
        break;
        case Piece::Type::PION_BLANC:
        case Piece::Type::PION_NOIR:
        tempCoupVec = getCoupPion(coordonnee, piece);
        break;
        case Piece::Type::VIDE:
        break;
    }
    return tempCoupVec;
}

std::vector<Coup> CoupLegaux::getCoupCavalier(Coord coordonnee, Piece piece) const
{
    std::vector<Coup> coupCavalier;
    Coup coupTemp;

    coupTemp.piece.type = piece.type;
    coupTemp.posIni = coordonnee;
    coupTemp.piece = piece;
    coupTemp.promotion.type = Piece::Type::VIDE;

    const std::array<Coord, 8> positions = {
        { 
        { 2, 1 },
        { 2, -1 },
        { 2, 1 },
        { 2,-1 },
        { 1, 2 },
        { 1,-2 },
        {-1,-2 },
        {-1, 2 }, 
        }
    };
    for(int i = 0; i < 8; i++){
        if((coordonnee + positions[i]).estValide()) {
            if(this->_verifCase(coordonnee + positions[i], piece)){
                coupTemp.posFin = coordonnee + positions[i];
                coupCavalier.push_back(coupTemp);
            }
        }        
    }
    return coupCavalier;
}

std::vector<Coup> CoupLegaux::getCoupTour(Coord coordonnee, Piece piece) const
{
    Coup coupTemp;
    std::vector<Coup> coupTour;
    Coord tempCoord;
    
    coupTemp.piece = piece;
    coupTemp.posIni = coordonnee;
    coupTemp.posFin.numero = coordonnee.numero;
    coupTemp.promotion.type = Piece::Type::VIDE;
    tempCoord = {coupTemp.posFin.lettre+1, coupTemp.posFin.numero};

    while(tempCoord.estValide()){
        if(this->_verifCase(tempCoord, piece)){
            coupTemp.posFin.lettre = tempCoord.lettre;
            coupTour.push_back(coupTemp);
        }
        if(this->_echiquier.getCase(tempCoord).couleur() != 'v'){
            break;
        }
        tempCoord.lettre++;
    }

    tempCoord.lettre = coordonnee.lettre - 1;
    while(tempCoord.estValide()){
        if(this->_verifCase(tempCoord, piece)){
            coupTemp.posFin.lettre = tempCoord.lettre;
            coupTour.push_back(coupTemp);
        }
        if(this->_echiquier.getCase(tempCoord).couleur() != 'v'){
            break;
        }
        tempCoord.lettre--;
    }

    tempCoord = { coordonnee.lettre, coordonnee.numero - 1 };
    while(tempCoord.estValide()){
        if(this->_verifCase(tempCoord, piece)){
            coupTemp.posFin.numero = tempCoord.numero;
            coupTour.push_back(coupTemp);
        }
        if(this->_echiquier.getCase(tempCoord).couleur() != 'v'){
            break;
        }
        tempCoord.numero--;
    }

    tempCoord.numero = coordonnee.numero + 1;
    while(tempCoord.estValide()){
        if(this->_echiquier.getCase(tempCoord).couleur() != piece.couleur()){
            coupTemp.posFin.numero = tempCoord.numero;
            coupTour.push_back(coupTemp);
        }
        if(this->_echiquier.getCase(tempCoord).couleur() != 'v'){
            break;
        }
        tempCoord.numero++;
    }
    return coupTour;
}

std::vector<Coup> CoupLegaux::getCoupFou(Coord coordonnee, Piece piece) const
{
    Coup coupTemp;
    std::vector<Coup> coupFou;

    coupTemp.piece = piece;
    coupTemp.posIni = { coordonnee.lettre, coordonnee.numero };
    coupTemp.promotion.type = Piece::Type::VIDE;

    Coord tempCoord = { coupTemp.posIni.lettre + 1, coupTemp.posIni.numero + 1 };
    while(tempCoord.estValide()){
        if(this->_verifCase(tempCoord, piece)){
            coupTemp.posFin = tempCoord;
            coupFou.push_back(coupTemp);       
        }
        if(this->_echiquier.getCase(tempCoord).couleur() != 'v'){
            break;
        }
        tempCoord.lettre++;
        tempCoord.numero++;
    }

    tempCoord = { coupTemp.posIni.lettre + 1, coupTemp.posIni.numero - 1 };
    while(tempCoord.estValide()){
        if(this->_verifCase(tempCoord, piece)){
            coupTemp.posFin = tempCoord;
            coupFou.push_back(coupTemp);       
        }
        if(this->_echiquier.getCase(tempCoord).couleur() != 'v'){
            break;
        }
        tempCoord.lettre++;
        tempCoord.numero--;
    }

    tempCoord = { coupTemp.posIni.lettre - 1, coupTemp.posIni.numero + 1 };
    while(tempCoord.estValide()){
        if(this->_verifCase(tempCoord, piece)){
            coupTemp.posFin = tempCoord;
            coupFou.push_back(coupTemp);       
        }
        if(this->_echiquier.getCase(tempCoord).couleur() != 'v'){
            break;
        }
        tempCoord.lettre--;
        tempCoord.numero++;
    }

    tempCoord = { coupTemp.posIni.lettre - 1, coupTemp.posIni.numero - 1 };
    while(tempCoord.estValide()){
        if(this->_verifCase(tempCoord, piece)){
            coupTemp.posFin = tempCoord;
            coupFou.push_back(coupTemp);       
        }
        if(this->_echiquier.getCase(tempCoord).couleur() != 'v'){
            break;
        }
        tempCoord.lettre--;
        tempCoord.numero--;
    }
    return coupFou;
}

std::vector<Coup> CoupLegaux::getCoupDame(Coord coordonnee, Piece piece) const
{
    std::vector<Coup> coupDame;
    std::vector<Coup> temp;
    coupDame = getCoupTour(coordonnee, piece);
    temp = getCoupFou(coordonnee, piece);
    coupDame.insert(coupDame.end(), temp.begin(), temp.end());
    return coupDame;
}

std::vector<Coup> CoupLegaux::getCoupRoi(Coord coordonnee, Piece piece) const
{
    Coup coupTemp;
    std::vector<Coup> coupRoi;
    Coord startCoord = { coordonnee.lettre - 1, coordonnee.numero - 1 };
    Coord tempCoord;

    coupTemp.piece = piece;
    coupTemp.posIni = coordonnee;
    coupTemp.promotion.type = Piece::Type::VIDE;

    for(int i = startCoord.lettre; i < startCoord.lettre + 3; i++){
        for(int j = startCoord.numero; j < startCoord.numero + 3; j++){
            tempCoord = startCoord;
            tempCoord.lettre += i;
            tempCoord.numero += j;
            if(tempCoord.estValide()){
                if(this->_verifCase(tempCoord, piece)) { coupRoi.push_back(coupTemp); }                        
            }
        }
    }
    
    return coupRoi;
}

std::vector<Coup> CoupLegaux::getCoupPion(Coord coordonnee, Piece piece) const
{
    Coup coupTemp;
    std::vector<Coup> coupPion;
    Coord tempCoord = { coordonnee.lettre, coordonnee.numero + 1 };

    coupTemp.piece = piece;
    coupTemp.posIni = coordonnee;
    coupTemp.promotion.type = Piece::Type::VIDE;

    if((coordonnee.numero == 6 && piece.couleur() == 'B') || (coordonnee.numero == 1 && piece.couleur() == 'n')){
        coupPion = getCoupPromotion(coordonnee, piece);
    }
    else{
        if(piece.couleur() == 'B'){        
            if(this->_echiquier.getCase(tempCoord).couleur() == 'v'){
                coupTemp.posFin = tempCoord;
                coupPion.push_back(coupTemp);

                tempCoord.numero++;
                if(coordonnee.numero == 1 && this->_echiquier.getCase(tempCoord).couleur() == 'v'){
                    coupTemp.posFin.numero++;
                    coupPion.push_back(coupTemp);
                }
            }

            tempCoord = { coordonnee.lettre - 1, coordonnee.numero + 1};
            if(tempCoord.estValide()){
                if(this->_echiquier.getCase(tempCoord).couleur() == 'n'){
                    coupTemp.posFin = tempCoord;
                    coupPion.push_back(coupTemp);
                }
            }

            tempCoord = { coordonnee.lettre + 1, coordonnee.numero + 1};
            if(tempCoord.estValide()){
                if(this->_echiquier.getCase(tempCoord).couleur() == 'n'){
                    coupTemp.posFin = tempCoord;
                    coupPion.push_back(coupTemp);
                }
            }

            if (coordonnee.numero == 5 && this->_dernierCoup.piece.type == Piece::Type::PION_NOIR
                && this->_dernierCoup.posIni.numero == 7
                && this->_dernierCoup.posFin.numero == 5
                && (this->_dernierCoup.posFin.lettre == coordonnee.lettre - 1 || this->_dernierCoup.posFin.lettre == coordonnee.lettre + 1)){
                    tempCoord = { this->_dernierCoup.posFin.lettre, coordonnee.numero + 1 };
                    coupTemp.posFin = tempCoord;
                    coupPion.push_back(coupTemp);
            }
        }
        else{
            if(this->_echiquier.getCase(tempCoord).couleur() == 'v'){
                coupTemp.posFin = tempCoord;
                coupPion.push_back(coupTemp);
                tempCoord.numero++;
                if(coordonnee.numero == 6 && this->_echiquier.getCase(tempCoord).couleur() == 'v'){
                    coupTemp.posFin.numero++;
                    coupPion.push_back(coupTemp);
                }
            }

            tempCoord = { coordonnee.lettre - 1, coordonnee.numero + 1};
            if(tempCoord.estValide()){
                if(this->_echiquier.getCase(tempCoord).couleur() == 'B'){
                    coupTemp.posFin = tempCoord;
                    coupPion.push_back(coupTemp);
                }
            }

            tempCoord = { coordonnee.lettre + 1, coordonnee.numero + 1};
            if(tempCoord.estValide()){
                if(this->_echiquier.getCase(tempCoord).couleur() == 'B'){
                    coupTemp.posFin = tempCoord;
                    coupPion.push_back(coupTemp);
                }
            }

            if (coordonnee.numero == 5 && this->_dernierCoup.piece.type == Piece::Type::PION_BLANC
                && this->_dernierCoup.posIni.numero == 7
                && this->_dernierCoup.posFin.numero == 5
                && (this->_dernierCoup.posFin.lettre == coordonnee.lettre - 1 || this->_dernierCoup.posFin.lettre == coordonnee.lettre + 1)){
                    tempCoord = { this->_dernierCoup.posFin.lettre, coordonnee.numero + 1 };
                    coupTemp.posFin = tempCoord;
                    coupPion.push_back(coupTemp);
            }
        }
    }
    return coupPion;
}

std::vector<Coup> CoupLegaux::getCoupPromotion(Coord coordonnee, Piece piece) const{
    Coord tempCoord;
    Coup coupTemp;
    std::vector<Coup> coupPromotion;

    coupTemp.piece = piece;
    coupTemp.posIni = coordonnee;

    if(piece.couleur() == 'B'){
        tempCoord = { coordonnee.lettre, coordonnee.numero + 1 };

        if(this->_echiquier.getCase(tempCoord).type == Piece::Type::VIDE){
            coupTemp.posFin = tempCoord;

            coupTemp.promotion.type = Piece::Type::DAME_BLANC;
            coupPromotion.push_back(coupTemp);

            coupTemp.promotion.type = Piece::Type::TOUR_BLANC;
            coupPromotion.push_back(coupTemp);

            coupTemp.promotion.type = Piece::Type::FOU_BLANC;
            coupPromotion.push_back(coupTemp);

            coupTemp.promotion.type = Piece::Type::CAVALIER_BLANC;
            coupPromotion.push_back(coupTemp);
        }

        tempCoord.lettre--;
        if(tempCoord.estValide()){
            if(this->_echiquier.getCase(tempCoord).couleur() == 'n'){
                coupTemp.posFin = tempCoord;
            
                coupTemp.promotion.type = Piece::Type::DAME_BLANC;
                coupPromotion.push_back(coupTemp);

                coupTemp.promotion.type = Piece::Type::TOUR_BLANC;
                coupPromotion.push_back(coupTemp);

                coupTemp.promotion.type = Piece::Type::FOU_BLANC;
                coupPromotion.push_back(coupTemp);

                coupTemp.promotion.type = Piece::Type::CAVALIER_BLANC;
                coupPromotion.push_back(coupTemp);
            }
        }   

        tempCoord.lettre += 2;
        if(tempCoord.estValide()){
            if(this->_echiquier.getCase(tempCoord).couleur() == 'n'){
                coupTemp.posFin = tempCoord;
            
                coupTemp.promotion.type = Piece::Type::DAME_BLANC;
                coupPromotion.push_back(coupTemp);

                coupTemp.promotion.type = Piece::Type::TOUR_BLANC;
                coupPromotion.push_back(coupTemp);

                coupTemp.promotion.type = Piece::Type::FOU_BLANC;
                coupPromotion.push_back(coupTemp);

                coupTemp.promotion.type = Piece::Type::CAVALIER_BLANC;
                coupPromotion.push_back(coupTemp);
            }
        }
    }
    else{
        tempCoord = { coordonnee.lettre, coordonnee.numero - 1 };
        
        if(this->_echiquier.getCase(tempCoord).type == Piece::Type::VIDE){
            coupTemp.posFin = tempCoord;

            coupTemp.promotion.type = Piece::Type::DAME_NOIR;
            coupPromotion.push_back(coupTemp);

            coupTemp.promotion.type = Piece::Type::TOUR_NOIR;
            coupPromotion.push_back(coupTemp);

            coupTemp.promotion.type = Piece::Type::FOU_NOIR;
            coupPromotion.push_back(coupTemp);

            coupTemp.promotion.type = Piece::Type::CAVALIER_NOIR;
            coupPromotion.push_back(coupTemp);
        }

        tempCoord.lettre--;
        if(tempCoord.estValide()){
            if(this->_echiquier.getCase(tempCoord).couleur() == 'n'){
                coupTemp.posFin = tempCoord;
            
                coupTemp.promotion.type = Piece::Type::DAME_NOIR;
                coupPromotion.push_back(coupTemp);

                coupTemp.promotion.type = Piece::Type::TOUR_NOIR;
                coupPromotion.push_back(coupTemp);

                coupTemp.promotion.type = Piece::Type::FOU_NOIR;
                coupPromotion.push_back(coupTemp);

                coupTemp.promotion.type = Piece::Type::CAVALIER_NOIR;
                coupPromotion.push_back(coupTemp);
            }
        }   

        tempCoord.lettre += 2;
        if(tempCoord.estValide()){
            if(this->_echiquier.getCase(tempCoord).couleur() == 'n'){
                coupTemp.posFin = tempCoord;
            
                coupTemp.promotion.type = Piece::Type::DAME_NOIR;
                coupPromotion.push_back(coupTemp);

                coupTemp.promotion.type = Piece::Type::TOUR_NOIR;
                coupPromotion.push_back(coupTemp);

                coupTemp.promotion.type = Piece::Type::FOU_NOIR;
                coupPromotion.push_back(coupTemp);

                coupTemp.promotion.type = Piece::Type::CAVALIER_NOIR;
                coupPromotion.push_back(coupTemp);
            }
        }
    }
    return coupPromotion;
}

int CoupLegaux::getLettrePremCoup() const
{
    return this->_coupLegauxBlanc[0].posIni.lettre;
}

void CoupLegaux::move(Coup coup)
{
    this->_echiquier.move(coup.piece, coup.posIni, coup.posFin, coup.promotion);
}

std::vector<Coup> CoupLegaux::getVectorCoupLegaux(bool couleur)
{
    return couleur? this->_coupLegauxBlanc : this->_coupLegauxNoir;
}

void CoupLegaux::setEchiquier(Echiquier echiquier)
{
    std::array<Piece, 64> tempArray;
    size_t index = 0;
    Coord tempCoord;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            tempCoord = { i, j};
            tempArray[index] = echiquier.getCase(tempCoord);
        }
    }

    this->_echiquier.setPlateau(tempArray);
}
