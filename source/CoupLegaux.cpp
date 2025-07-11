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
    this->_dernierCoup.couleur = 'n';
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
    std::vector<std::pair<int, int>> temp;
    std::tuple<std::pair<int, int>, int, char> coupParPieceTemp;
    size_t tailleVectorBlanc = 0;
    size_t tailleVectorNoir = 0;
    switch(pieceTemp){
        case 'v':
        break;
        case 'C':
        temp = getCoupCavalier(lettre, numero, 'B');
        this->_coupLegauxBlanc.insert(this->_coupLegauxBlanc.end(), temp.begin(), temp.end());
        std::get<0>(coupParPieceTemp).first = lettre;
        std::get<0>(coupParPieceTemp).second = numero;
        std::get<1>(coupParPieceTemp) = this->_coupLegauxBlanc.size()-tailleVectorBlanc;
        std::get<2>(coupParPieceTemp) = 'C';
        this->_coupParPieceBlanc.push_back(coupParPieceTemp);
        tailleVectorBlanc = this->_coupLegauxBlanc.size();
        break;
        case 'c':
        temp = getCoupCavalier(lettre, numero, 'n');
        this->_coupLegauxNoir.insert(this->_coupLegauxNoir.end(), temp.begin(), temp.end());
        std::get<0>(coupParPieceTemp).first = lettre;
        std::get<0>(coupParPieceTemp).second = numero;
        std::get<1>(coupParPieceTemp) = this->_coupLegauxNoir.size()-tailleVectorNoir;
        std::get<2>(coupParPieceTemp) = 'C';
        this->_coupParPieceNoir.push_back(coupParPieceTemp);
        tailleVectorNoir = this->_coupLegauxNoir.size();
        break;
        case 'T':
        temp = getCoupTour(lettre, numero, 'B');
        this->_coupLegauxBlanc.insert(this->_coupLegauxBlanc.end(), temp.begin(), temp.end());
        std::get<0>(coupParPieceTemp).first = lettre;
        std::get<0>(coupParPieceTemp).second = numero;
        std::get<1>(coupParPieceTemp) = this->_coupLegauxBlanc.size()-tailleVectorBlanc;
        std::get<2>(coupParPieceTemp) = 'T';
        this->_coupParPieceBlanc.push_back(coupParPieceTemp);
        tailleVectorBlanc = this->_coupLegauxBlanc.size();
        break;
        case 't':
        temp = getCoupTour(lettre, numero, 'n');
        this->_coupLegauxNoir.insert(this->_coupLegauxNoir.end(), temp.begin(), temp.end());
        std::get<0>(coupParPieceTemp).first = lettre;
        std::get<0>(coupParPieceTemp).second = numero;
        std::get<1>(coupParPieceTemp) = this->_coupLegauxNoir.size()-tailleVectorNoir;
        std::get<2>(coupParPieceTemp) = 'T';
        this->_coupParPieceNoir.push_back(coupParPieceTemp);
        tailleVectorNoir = this->_coupLegauxNoir.size();
        break;
        case 'F':
        temp = getCoupFou(lettre, numero, 'B');
        this->_coupLegauxBlanc.insert(this->_coupLegauxBlanc.end(), temp.begin(), temp.end());
        std::get<0>(coupParPieceTemp).first = lettre;
        std::get<0>(coupParPieceTemp).second = numero;
        std::get<1>(coupParPieceTemp) = this->_coupLegauxBlanc.size()-tailleVectorBlanc;
        std::get<2>(coupParPieceTemp) = 'F';
        this->_coupParPieceBlanc.push_back(coupParPieceTemp);
        tailleVectorBlanc = this->_coupLegauxBlanc.size();
        break;
        case 'f':
        temp = getCoupFou(lettre, numero, 'n');
        this->_coupLegauxNoir.insert(this->_coupLegauxNoir.end(), temp.begin(), temp.end());
        std::get<0>(coupParPieceTemp).first = lettre;
        std::get<0>(coupParPieceTemp).second = numero;
        std::get<1>(coupParPieceTemp) = this->_coupLegauxNoir.size()-tailleVectorNoir;
        std::get<2>(coupParPieceTemp) = 'F';
        this->_coupParPieceNoir.push_back(coupParPieceTemp);
        tailleVectorNoir = this->_coupLegauxNoir.size();
        break;
        case 'D':
        temp = getCoupDame(lettre, numero, 'B');
        this->_coupLegauxBlanc.insert(this->_coupLegauxBlanc.end(), temp.begin(), temp.end());
        std::get<0>(coupParPieceTemp).first = lettre;
        std::get<0>(coupParPieceTemp).second = numero;
        std::get<1>(coupParPieceTemp) = this->_coupLegauxBlanc.size()-tailleVectorBlanc;
        std::get<2>(coupParPieceTemp) = 'D';
        this->_coupParPieceBlanc.push_back(coupParPieceTemp);
        tailleVectorBlanc = this->_coupLegauxBlanc.size();
        break;
        case 'd':
        temp = getCoupDame(lettre, numero, 'n');
        this->_coupLegauxNoir.insert(this->_coupLegauxNoir.end(), temp.begin(), temp.end());
        std::get<0>(coupParPieceTemp).first = lettre;
        std::get<0>(coupParPieceTemp).second = numero;
        std::get<1>(coupParPieceTemp) = this->_coupLegauxNoir.size()-tailleVectorNoir;
        std::get<2>(coupParPieceTemp) = 'D';
        this->_coupParPieceNoir.push_back(coupParPieceTemp);
        tailleVectorNoir = this->_coupLegauxNoir.size();
        break;
        case 'P':
        temp = getCoupPion(lettre, numero, 'B');
        this->_coupLegauxBlanc.insert(this->_coupLegauxBlanc.end(), temp.begin(), temp.end());
        std::get<0>(coupParPieceTemp).first = lettre;
        std::get<0>(coupParPieceTemp).second = numero;
        std::get<1>(coupParPieceTemp) = this->_coupLegauxBlanc.size()-tailleVectorBlanc;
        std::get<2>(coupParPieceTemp) = 'P';
        this->_coupParPieceBlanc.push_back(coupParPieceTemp);
        tailleVectorBlanc = this->_coupLegauxBlanc.size();
        break;
        case 'p':
        temp = getCoupPion(lettre, numero, 'n');
        this->_coupLegauxNoir.insert(this->_coupLegauxNoir.end(), temp.begin(), temp.end());
        std::get<0>(coupParPieceTemp).first = lettre;
        std::get<0>(coupParPieceTemp).second = numero;
        std::get<1>(coupParPieceTemp) = this->_coupLegauxNoir.size()-tailleVectorNoir;
        std::get<2>(coupParPieceTemp) = 'P';
        this->_coupParPieceNoir.push_back(coupParPieceTemp);
        tailleVectorNoir = this->_coupLegauxNoir.size();
        break;
        case 'R':
        temp = getCoupRoi(lettre, numero, 'B');
        this->_coupLegauxBlanc.insert(this->_coupLegauxBlanc.end(), temp.begin(), temp.end());
        std::get<0>(coupParPieceTemp).first = lettre;
        std::get<0>(coupParPieceTemp).second = numero;
        std::get<1>(coupParPieceTemp) = this->_coupLegauxBlanc.size()-tailleVectorBlanc;
        std::get<2>(coupParPieceTemp) = 'R';
        this->_coupParPieceBlanc.push_back(coupParPieceTemp);
        tailleVectorBlanc = this->_coupLegauxBlanc.size();
        break;
        case 'r':
        temp = getCoupRoi(lettre, numero, 'n');
        this->_coupLegauxNoir.insert(this->_coupLegauxNoir.end(), temp.begin(), temp.end());
        std::get<0>(coupParPieceTemp).first = lettre;
        std::get<0>(coupParPieceTemp).second = numero;
        std::get<1>(coupParPieceTemp) = this->_coupLegauxNoir.size()-tailleVectorNoir;
        std::get<2>(coupParPieceTemp) = 'R';
        this->_coupParPieceNoir.push_back(coupParPieceTemp);
        tailleVectorNoir = this->_coupLegauxNoir.size();
        break;
    }
}

std::vector<Coup> CoupLegaux::getCoupCavalier(Coord coordonnee, Piece piece) const
{
    std::vector<Coup> coupCavalier;
    Coup coupTemp;

    coupTemp.piece.type = piece.type;
    coupTemp.posIni = coordonnee;
    coupTemp.couleur = piece.couleur();

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
        if(coordonnee.lettre + positions[i].lettre < 8 && coordonnee.lettre + positions[i].lettre >= 0 && 
            coordonnee.numero + positions[i].numero < 8 && coordonnee.numero + positions[i].numero >= 0){
            coupTemp.posFin = coordonnee + positions[i];
            coupCavalier.push_back(coupTemp);
        }        
    }
    return coupCavalier;
}

std::vector<Coup> CoupLegaux::getCoupTour(Coord, char couleur) const
{
    Coup temp;
    std::vector<Coup> coupTour;
    
    int i = lettre + 1;

    temp.couleur = couleur;
    temp.piece = 'T';
    temp.posIni = {lettre, numero};
    temp.posFin.second = numero;

    while(i < 8){
        if(this->_echiquier.getCase(i, numero) != 'T,C,F,D,R,P' && couleur == 'B'){
            temp.posFin.first = i;
            coupTour.push_back(temp);
        }
        else if(this->_echiquier.getCase(i, numero) != 't,c,f,d,r,p'){
            temp.posFin.first = i;
            coupTour.push_back(temp);
        }
        if(this->_echiquier.getCase(i, numero) !='v'){
            break;
        }
        i++;
    }

    i = lettre - 1;
    while(i >= 0){
        if(this->_echiquier.getCase(i, numero) != 'T,C,F,D,R,P' && couleur == 'B'){
            temp.posFin.first = i;
            coupTour.push_back(temp);
        }
        else if(this->_echiquier.getCase(i, numero) != 't,c,f,d,r,p'){
            temp.posFin.first = i;
            coupTour.push_back(temp);
        }
        if(this->_echiquier.getCase(i, numero) !='v'){
            break;
        }
        i--;
    }

    temp.posFin.first = lettre;
    i = numero - 1;
    while(i >= 0){
        if(this->_echiquier.getCase(lettre, i) != 'T,C,F,D,R,P' && couleur == 'B'){
            temp.posFin.second = i;
            coupTour.push_back(temp);
        }
        else if(this->_echiquier.getCase(lettre, i) != 't,c,f,d,r,p'){
            temp.posFin.second = i;
            coupTour.push_back(temp);
        }
        if(this->_echiquier.getCase(lettre, i) !='v'){
            break;
        }
        i--;
    }

    i = numero + 1;
    while(i < 8){
        if(this->_echiquier.getCase(lettre, i) != 'T,C,F,D,R,P' && couleur == 'B'){
            temp.posFin.second = i;
            coupTour.push_back(temp);
        }
        else if(this->_echiquier.getCase(lettre, i) != 't,c,f,d,r,p'){
            temp.posFin.second = i;
            coupTour.push_back(temp);
        }
        if(this->_echiquier.getCase(lettre, i) != 'v'){
            break;
        }
        i--;
    }
    return coupTour;
}

std::vector<Coup> CoupLegaux::getCoupFou(Coord, char couleur) const
{
    Coup temp;
    std::vector<Coup> coupFou;

    temp.couleur = couleur;
    temp.piece = 'F';
    temp.posIni = {lettre, numero};

    int i = lettre+1;
    int j = numero+1;
    while(i<8&&j<8){
        if(couleur=='B'&&this->_echiquier.getCase(i,j)!='F,R,T,C,D,P'){
            temp.posFinfirst=i;
            temp.second=j;
            coupFou.push_back(temp);       
        }
        else if(this->_echiquier.getCase(i,j)!='f,r,t,c,d,p'){
            temp.first=i;
            temp.second=j;
            coupFou.push_back(temp);
        }
        if(this->_echiquier.getCase(i,j)!='v'){
            break;
        }
        i++;
        j++;
    }

    int i = lettre+1;
    int j = numero-1;
    while(i<8&&j>=0){
        if(couleur=='B'&&this->_echiquier.getCase(i,j)!='F,R,T,C,D,P'){
            temp.first=i;
            temp.second=j;
            coupFou.push_back(temp);       
        }
        else if(this->_echiquier.getCase(i,j)!='f,r,t,c,d,p'){
            temp.first=i;
            temp.second=j;
            coupFou.push_back(temp);
        }
        if(this->_echiquier.getCase(i,j)!='v'){
            break;
        }
        i++;
        j++;
    }

    int i = lettre-1;
    int j = numero+1;
    while(i>=0&&j<8){
        if(couleur=='B'&&this->_echiquier.getCase(i,j)!='F,R,T,C,D,P'){
            temp.first=i;
            temp.second=j;
            coupFou.push_back(temp);       
        }
        else if(this->_echiquier.getCase(i,j)!='f,r,t,c,d,p'){
            temp.first=i;
            temp.second=j;
            coupFou.push_back(temp);
        }
        if(this->_echiquier.getCase(i,j)!='v'){
            break;
        }
        i++;
        j++;
    }

    int i = lettre-1;
    int j = numero-1;
    while(i>=0&&j>=0){
        if(couleur=='B'&&this->_echiquier.getCase(i,j)!='F,R,T,C,D,P'){
            temp.first=i;
            temp.second=j;
            coupFou.push_back(temp);       
        }
        else if(this->_echiquier.getCase(i,j)!='f,r,t,c,d,p'){
            temp.first=i;
            temp.second=j;
            coupFou.push_back(temp);
        }
        if(this->_echiquier.getCase(i,j)!='v'){
            break;
        }
        i++;
        j++;
    }
    return coupFou;
}

std::vector<Coup> CoupLegaux::getCoupDame(Coord, char couleur) const
{
    std::vector<std::pair<int, int>> coupDame;
    std::vector<std::pair<int, int>> temp;
    coupDame = getCoupTour(lettre, numero, couleur);
    temp = getCoupFou(lettre, numero, couleur);
    coupDame.insert(coupDame.end(), temp.begin(), temp.end());
    return coupDame;
}

std::vector<Coup> CoupLegaux::getCoupRoi(Coord, char couleur) const
{
    std::pair<int, int> temp;
    std::vector<std::pair<int, int>> coupRoi;

    if(couleur=='B'){
        for(int i=lettre-1; i<lettre+2; i++){
            for(int j=numero-1; j<numero+2; j++){
                if(i>=0&&i<8&&j>=0&&j<8&&this->_echiquier.getCase(i,j)!='F,D,T,C,P'){
                    temp.first=i;
                    temp.second=j;
                    if(i!=lettre||j!=numero)
                    coupRoi.push_back(temp);
                }
            }
        }
    }
    else{
        for(int i=lettre-1; i<lettre+2; i++){
            for(int j=numero-1; j<numero+2; j++){
                if(i>=0&&i<8&&j>=0&&j<8&&this->_echiquier.getCase(i,j)!='f,d,t,c,p'){
                    temp.first=i;
                    temp.second=j;
                    if(i!=lettre||j!=numero)
                    coupRoi.push_back(temp);
                }
            }
        }
    }
    
    return coupRoi;
}

std::vector<Coup> CoupLegaux::getCoupPion(Coord, char couleur) const
{
    std::pair<int, int> temp;
    std::vector<std::pair<int, int>> coupPion;
    if(couleur=='B'||couleur=='b'){
        if(this->_echiquier.getCase(lettre, numero+1)=='v'){
            temp.first=lettre;
            temp.second=numero+1;
            coupPion.push_back(temp);
            if(numero==1&&this->_echiquier.getCase(lettre, numero+2)=='v'){
                temp.second++;
                coupPion.push_back(temp);
            }
        }
        if(lettre!=0){
            if(this->_echiquier.getCase(lettre-1, numero+1)=='p,d,t,f,c'){
                temp.first=lettre-1;
                temp.second=numero+1;
                coupPion.push_back(temp);
            }
        }
        if (lettre!=7){
            if(this->_echiquier.getCase(lettre+1, numero+1)=='p,d,t,f,c'){
                temp.first=lettre+1;
                temp.second=numero+1;
                coupPion.push_back(temp);
            }
        }
        if (numero == 5 && this->_dernierCoup.piece == 'P' 
            && this->_dernierCoup.couleur!='B' 
            && this->_dernierCoup.posIni.first == 7
            && this->_dernierCoup.posFin.first == 5
            && (this->_dernierCoup.posFin.second == lettre - 1 || this->_dernierCoup.posFin.second == lettre + 1)){
                temp.first = this->_dernierCoup.posFin.first;
                temp.second = this->_dernierCoup.posFin.second + 1;
                coupPion.push_back(temp);
            }
    }
    else{
        if(this->_echiquier.getCase(lettre, numero-1)=='v'){
            temp.first=lettre;
            temp.second=numero-1;
            coupPion.push_back(temp);
            if(numero==1&&this->_echiquier.getCase(lettre, numero-2)=='v'){
                temp.second--;
                coupPion.push_back(temp);
            }
        }
        if(lettre!=0){
            if(this->_echiquier.getCase(lettre-1, numero-1)=='P,D,T,F,C'){
                temp.first=lettre-1;
                temp.second=numero-1;
                coupPion.push_back(temp);
            }
        }
        if (lettre!=7){
            if(this->_echiquier.getCase(lettre+1, numero-1)=='P,D,T,F,C'){
                temp.first=lettre+1;
                temp.second=numero-1;
                coupPion.push_back(temp);
            }
        }
        if (numero == 4 && this->_dernierCoup.piece == 'P' 
            && this->_dernierCoup.couleur!='B' 
            && this->_dernierCoup.posIni.first == 2
            && this->_dernierCoup.posFin.first == 4
            && (this->_dernierCoup.posFin.second == lettre - 1 || this->_dernierCoup.posFin.second == lettre + 1)){
                temp.first = this->_dernierCoup.posFin.first;
                temp.second = this->_dernierCoup.posFin.second - 1;
                coupPion.push_back(temp);
            }
    }
    return coupPion;
}

void CoupLegaux::move(int index, char couleur)
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
}
