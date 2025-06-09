#include "CoupLegaux.hpp"

CoupLegaux::CoupLegaux()
{
}

void CoupLegaux::allCoupLegaux()
{
    std::vector<std::pair<int, int>> temp;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(this->_echiquier.getCase(i,j)=='C'){
                temp = getCoupCavalier(i,j);
                this->_coupLegauxBlanc.insert(this->_coupLegauxBlanc.end(), temp.begin(), temp.end());
            }else if(this->_echiquier.getCase(i,j)=='c'){
                temp = getCoupCavalier(i,j);
                this->_coupLegauxNoir.insert(this->_coupLegauxBlanc.end(), temp.begin(), temp.end());
            }else if(this->_echiquier.getCase(i,j)=='t'){
                temp = getCoupTour(i,j);
                this->_coupLegauxNoir.insert(this->_coupLegauxBlanc.end(), temp.begin(), temp.end());
            }else if(this->_echiquier.getCase(i,j)=='T'){
                temp = getCoupTour(i,j);
                this->_coupLegauxBlanc.insert(this->_coupLegauxBlanc.end(), temp.begin(), temp.end());
            }else if(this->_echiquier.getCase(i,j)=='F'){
                temp = getCoupFou(i,j);
                this->_coupLegauxBlanc.insert(this->_coupLegauxBlanc.end(), temp.begin(), temp.end());
            }else if(this->_echiquier.getCase(i,j)=='f'){
                temp = getCoupFou(i,j);
                this->_coupLegauxNoir.insert(this->_coupLegauxBlanc.end(), temp.begin(), temp.end());
            }
        }
    }
}

std::vector<std::pair<int, int>> CoupLegaux::getCoupCavalier(int lettre, int numero) const
{
    std::pair<int, int> temp;
    std::vector<std::pair<int, int>> coupCavalier;
    temp.first=lettre+2;
    temp.second=numero+1;
    if(lettre<8&&lettre>=0&&numero<8&&numero>=0)
    coupCavalier.push_back(temp);
    temp.first=lettre+2;
    temp.second=numero-1;
    if(lettre<8&&lettre>=0&&numero<8&&numero>=0)
    coupCavalier.push_back(temp);
    temp.first=lettre-2;
    temp.second=numero+1;
    if(lettre<8&&lettre>=0&&numero<8&&numero>=0)
    coupCavalier.push_back(temp);
    temp.first=lettre-2;
    temp.second=numero-1;
    if(lettre<8&&lettre>=0&&numero<8&&numero>=0)
    coupCavalier.push_back(temp);
    temp.first=lettre+1;
    temp.second=numero+2;
    if(lettre<8&&lettre>=0&&numero<8&&numero>=0)
    coupCavalier.push_back(temp);
    temp.first=lettre+1;
    temp.second=numero-2;
    if(lettre<8&&lettre>=0&&numero<8&&numero>=0)
    coupCavalier.push_back(temp);
    temp.first=lettre-1;
    temp.second=numero-2;
    if(lettre<8&&lettre>=0&&numero<8&&numero>=0)
    coupCavalier.push_back(temp);
    temp.first=lettre-1;
    temp.second=numero+2;
    if(lettre<8&&lettre>=0&&numero<8&&numero>=0)
    coupCavalier.push_back(temp);

    return coupCavalier;
}

std::vector<std::pair<int, int>> CoupLegaux::getCoupTour(int lettre, int numero) const
{
    std::pair<int, int> temp;
    std::vector<std::pair<int, int>> coupTour;
    for(int i=0; i<8; i++){
        temp.first=lettre;
        temp.second=i;
        if(i!=numero){
            coupTour.push_back(temp);
        }
        temp.first=i;
        temp.second=numero;
        if(i!=lettre){
            coupTour.push_back(temp);
        }
    }
    return coupTour;
}

std::vector<std::pair<int, int>> CoupLegaux::getCoupFou(int lettre, int numero) const
{
    std::pair<int, int> temp;
    std::vector<std::pair<int, int>> coupFou;
    int i = lettre;
    int j = numero;
    while(i<8&&j<8){
        if(i!=lettre&&j!=numero){
            temp.first=i;
            temp.second=j;
            coupFou.push_back(temp);
        }
        i++;
        j++;
    }

    int i = lettre;
    int j = numero;
    while(i<8&&j>=0){
        if(i!=lettre&&j!=numero){
            temp.first=i;
            temp.second=j;
            coupFou.push_back(temp);
        }
        i++;
        j--;
    }

    int i = lettre;
    int j = numero;
    while(i>=0&&j<8){
        if(i!=lettre&&j!=numero){
            temp.first=i;
            temp.second=j;
            coupFou.push_back(temp);
        }
        i--;
        j++;
    }

    int i = lettre;
    int j = numero;
    while(i>=0&&j>=0){
        if(i!=lettre&&j!=numero){
            temp.first=i;
            temp.second=j;
            coupFou.push_back(temp);
        }
        i--;
        j--;
    }
    return coupFou;
}

std::vector<std::pair<int, int>> CoupLegaux::getCoupDame(int lettre, int numero) const
{
    std::pair<int, int> temp;
    std::vector<std::pair<int, int>> coupDame;
    for(int i=0; i<8; i++){
        temp.first=lettre;
        temp.second=i;
        if(i!=numero){
            coupDame.push_back(temp);
        }
        temp.first=i;
        temp.second=numero;
        if(i!=lettre){
            coupDame.push_back(temp);
        }
    }
    int i=lettre;
    int j=numero;
    while(i<8&&j<8){
        if(i!=lettre&&j!=numero){
            temp.first=i;
            temp.second=j;
            coupDame.push_back(temp);
        }
        i++;
        j++;
    }

    int i = lettre;
    int j = numero;
    while(i<8&&j>=0){
        if(i!=lettre&&j!=numero){
            temp.first=i;
            temp.second=j;
            coupDame.push_back(temp);
        }
        i++;
        j--;
    }

    int i = lettre;
    int j = numero;
    while(i>=0&&j<8){
        if(i!=lettre&&j!=numero){
            temp.first=i;
            temp.second=j;
            coupDame.push_back(temp);
        }
        i--;
        j++;
    }

    int i = lettre;
    int j = numero;
    while(i>=0&&j>=0){
        if(i!=lettre&&j!=numero){
            temp.first=i;
            temp.second=j;
            coupDame.push_back(temp);
        }
        i--;
        j--;
    }
    return coupDame;
}

std::vector<std::pair<int, int>> CoupLegaux::getCoupRoi(int lettre, int numero) const
{
    std::pair<int, int> temp;
    std::vector<std::pair<int, int>> coupRoi;

    for(int i=lettre-1; i<lettre+2; i++){
        for(int j=numero-1; j<numero+2; j++){
            if(lettre>=0&&lettre<8&&numero>=0&&numero<8){
                temp.first=i;
                temp.second=j;
                if(i!=lettre||j!=numero)
                coupRoi.push_back(temp);
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
    }
    return coupPion;
}
