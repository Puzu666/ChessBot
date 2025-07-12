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
void CoupLegaux::allCoupLegaux(bool couleur)
{
    Piece pieceTemp;
    Coord coordtemp;
    this->_coupLegauxBlanc.clear();
    this->_coupLegauxNoir.clear();
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            coordtemp = {i, j};
            pieceTemp = this->_echiquier.getCase(coordtemp);
            getCoupPiece(coordtemp, pieceTemp);
        }
    }
}

void CoupLegaux::getCoupPiece(Coord coordonnee, Piece pieceTemp)
{
}

std::vector<Coup> CoupLegaux::getCoupCavalier(Coord coordonnee, Piece piece) const
{
    std::vector<Coup> coupCavalier;
    Coup coupTemp;

    coupTemp.piece.type = piece.type;
    coupTemp.posIni = coordonnee;
    coupTemp.piece = piece;

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

    Coord tempCoord = { coupTemp.posIni.lettre + 1, coupTemp.posIni.numero - 1 };
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

    Coord tempCoord = { coupTemp.posIni.lettre - 1, coupTemp.posIni.numero + 1 };
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

    Coord tempCoord = { coupTemp.posIni.lettre - 1, coupTemp.posIni.numero - 1 };
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
    Coord tempCoord = { coordonnee.lettre - 1, coordonnee.numero - 1 };

    coupTemp.piece = piece;
    coupTemp.posIni = coordonnee;

    if(piece.couleur()=='B'){
        for(tempCoord.lettre; tempCoord.lettre < tempCoord.lettre + 3; tempCoord.lettre++){
            for(tempCoord.numero; tempCoord.numero < tempCoord.numero + 3; tempCoord.numero++){
                if(tempCoord.estValide()){
                    if(this->_verifCase(coordonnee, piece)) { coupRoi.push_back(coupTemp); }                        
                }
            }
        }
    }
    else{
        for(tempCoord.lettre; tempCoord.lettre < tempCoord.lettre + 3; tempCoord.lettre++){
            for(tempCoord.numero; tempCoord.numero < tempCoord.numero + 3; tempCoord.numero++){
                if(tempCoord.estValide()){
                    if(this->_verifCase(coordonnee, piece)) { coupRoi.push_back(coupTemp); }
                }
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
            if(coordonnee.numero == 1 && this->_echiquier.getCase(tempCoord).couleur() == 'v'){
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
    return coupPion;
}

/*void CoupLegaux::move(int index, char couleur)
{
    if(couleur == 'B' && index < this->_coupLegauxBlanc.size()){
        int temp = index;
        int i = 0;
        while(i < this->_coupParPieceBlanc.size() && temp>0){
            temp -= std::get <1> (this->_coupParPieceBlanc[i]);
            i++;
        }
        i--;
        this->_dernierCoup.posIni.first = std::get <0> (this->_coupParPieceBlanc[i]).first;
        this->_dernierCoup.posIni.second = std::get <0> (this->_coupParPieceBlanc[i]).second;
        this->_dernierCoup.posFin.first = this->_coupLegauxBlanc[index].first;
        this->_dernierCoup.posFin.second = this->_coupLegauxBlanc[index].second;
        this->_dernierCoup.piece = std::get <2> (this->_coupParPieceBlanc[i]);
        this->_dernierCoup.couleur = 'B';
        bool verif;
        verif = this->_echiquier.move(this->_dernierCoup.piece 
                                    , this->_dernierCoup.posIni.first
                                    , this->_dernierCoup.posIni.second
                                    , this->_dernierCoup.posFin.first
                                    , this->_dernierCoup.posFin.second);
        assert(verif);
    }
    else if(index < this->_coupLegauxNoir.size()){
        int temp = index;
        int i = 0;
        while(i < this->_coupParPieceNoir.size() && temp>0){
            temp -= std::get <1> (this->_coupParPieceNoir[i]);
            i++;
        }
        i--;
        this->_dernierCoup.posIni.first = std::get <0> (this->_coupParPieceNoir[i]).first;
        this->_dernierCoup.posIni.second = std::get <0> (this->_coupParPieceNoir[i]).second;
        this->_dernierCoup.posFin.first = this->_coupLegauxNoir[index].first;
        this->_dernierCoup.posFin.second = this->_coupLegauxNoir[index].second;
        this->_dernierCoup.piece = std::get <2> (this->_coupParPieceNoir[i]);
        this->_dernierCoup.couleur = 'n';
        bool verif;
        verif = this->_echiquier.move(this->_dernierCoup.piece 
                                    , this->_dernierCoup.posIni.first
                                    , this->_dernierCoup.posIni.second
                                    , this->_dernierCoup.posFin.first
                                    , this->_dernierCoup.posFin.second);
        assert(verif);
    }
}*/
