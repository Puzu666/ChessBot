#include "CoupLegaux.hpp"
#include <cassert>

CoupLegaux::CoupLegaux()
{
    this->_dernierCoup.posIni.first = -1;
    this->_dernierCoup.posIni.second = -1;
    this->_dernierCoup.posFin.first = -1;
    this->_dernierCoup.posFin.second = -1;
    this->_dernierCoup.piece = 'v';
    this->_dernierCoup.couleur = 'n';
}

//true==blanc; false==noir
void CoupLegaux::allCoupLegaux(bool couleur)
{
    char pieceTemp;
    this->_coupLegauxBlanc.clear();
    this->_coupLegauxNoir.clear();
    this->_coupParPieceBlanc.clear();
    this->_coupParPieceNoir.clear();
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            pieceTemp = this->_echiquier.getCase(i, j);
            getCoupPiece(i, j, pieceTemp);
        }
    }
    if(couleur){

    }
    else{
        
    }
}

void CoupLegaux::getCoupPiece(int lettre, int numero, char pieceTemp)
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

std::vector<std::pair<int, int>> CoupLegaux::getCoupCavalier(int lettre, int numero, char couleur) const
{
    std::vector<std::pair<int, int>> coupCavalier;
    std::pair<int, int> temp;
    const std::array<std::pair<int, int>, 8> positions = {
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
        if(lettre + positions[i].first < 8 && lettre + positions[i].first >= 0 && numero + positions[i].second < 8 && numero + positions[i].second >= 0){
            temp.first = lettre + positions[i].first;
            temp.second = numero + positions[i].second;
            coupCavalier.push_back(temp);
        }        
    }
    return coupCavalier;
}

std::vector<std::pair<int, int>> CoupLegaux::getCoupTour(int lettre, int numero, char couleur) const
{
    std::pair<int, int> temp;
    std::vector<std::pair<int, int>> coupTour;
    
    int i = lettre + 1;
    temp.second = numero;

    while(i < 8){
        if(this->_echiquier.getCase(i, numero) != 'T,C,F,D,R,P' && couleur == 'B'){
            temp.first = i;
            coupTour.push_back(temp);
        }
        else if(this->_echiquier.getCase(i, numero) != 't,c,f,d,r,p'){
            temp.first = i;
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
            temp.first = i;
            coupTour.push_back(temp);
        }
        else if(this->_echiquier.getCase(i, numero) != 't,c,f,d,r,p'){
            temp.first = i;
            coupTour.push_back(temp);
        }
        if(this->_echiquier.getCase(i, numero) !='v'){
            break;
        }
        i--;
    }

    temp.first = lettre;
    i = numero - 1;
    while(i >= 0){
        if(this->_echiquier.getCase(lettre, i) != 'T,C,F,D,R,P' && couleur == 'B'){
            temp.second = i;
            coupTour.push_back(temp);
        }
        else if(this->_echiquier.getCase(lettre, i) != 't,c,f,d,r,p'){
            temp.second = i;
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
            temp.second = i;
            coupTour.push_back(temp);
        }
        else if(this->_echiquier.getCase(lettre, i) != 't,c,f,d,r,p'){
            temp.second = i;
            coupTour.push_back(temp);
        }
        if(this->_echiquier.getCase(lettre, i) != 'v'){
            break;
        }
        i--;
    }
    return coupTour;
}

std::vector<std::pair<int, int>> CoupLegaux::getCoupFou(int lettre, int numero, char couleur) const
{
    std::pair<int, int> temp;
    std::vector<std::pair<int, int>> coupFou;
    int i = lettre+1;
    int j = numero+1;
    while(i<8&&j<8){
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

std::vector<std::pair<int, int>> CoupLegaux::getCoupDame(int lettre, int numero, char couleur) const
{
    std::vector<std::pair<int, int>> coupDame;
    std::vector<std::pair<int, int>> temp;
    coupDame = getCoupTour(lettre, numero, couleur);
    temp = getCoupFou(lettre, numero, couleur);
    coupDame.insert(coupDame.end(), temp.begin(), temp.end());
    return coupDame;
}

std::vector<std::pair<int, int>> CoupLegaux::getCoupRoi(int lettre, int numero, char couleur) const
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

std::vector<std::pair<int, int>> CoupLegaux::getCoupPion(int lettre, int numero, char couleur) const
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
