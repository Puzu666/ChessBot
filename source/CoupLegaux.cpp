#include "CoupLegaux.hpp"

CoupLegaux::CoupLegaux()
{
}

void CoupLegaux::allCoupLegaux()
{
    std::vector<std::array<int,2>> temp;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(this->_echiquier.getCase(i,j)=='C'){
                temp = getCoupCavalier(i,j);
                this->_coupLegauxBlanc.insert(this->_coupLegauxBlanc.end(), temp.begin(), temp.end());
            }
            if(this->_echiquier.getCase(i,j)=='c'){
                temp = getCoupCavalier(i,j);
                this->_coupLegauxNoir.insert(this->_coupLegauxBlanc.end(), temp.begin(), temp.end());
            }
        }
    }
}

std::vector<std::array<int, 2>> CoupLegaux::getCoupCavalier(int lettre, int numero) const
{
    std::array<int,2> temp;
    std::vector<std::array<int,2>> coupCavalier;
    temp[0]=lettre+2;
    temp[1]=numero+1;
    if(lettre<8&&lettre>=0&&numero<8&&numero>=0)
    coupCavalier.push_back(temp);
    temp[0]=lettre+2;
    temp[1]=numero-1;
    if(lettre<8&&lettre>=0&&numero<8&&numero>=0)
    coupCavalier.push_back(temp);
    temp[0]=lettre-2;
    temp[1]=numero+1;
    if(lettre<8&&lettre>=0&&numero<8&&numero>=0)
    coupCavalier.push_back(temp);
    temp[0]=lettre-2;
    temp[1]=numero-1;
    if(lettre<8&&lettre>=0&&numero<8&&numero>=0)
    coupCavalier.push_back(temp);
    temp[0]=lettre+1;
    temp[1]=numero+2;
    if(lettre<8&&lettre>=0&&numero<8&&numero>=0)
    coupCavalier.push_back(temp);
    temp[0]=lettre+1;
    temp[1]=numero-2;
    if(lettre<8&&lettre>=0&&numero<8&&numero>=0)
    coupCavalier.push_back(temp);
    temp[0]=lettre-1;
    temp[1]=numero-2;
    if(lettre<8&&lettre>=0&&numero<8&&numero>=0)
    coupCavalier.push_back(temp);
    temp[0]=lettre-1;
    temp[1]=numero+2;
    if(lettre<8&&lettre>=0&&numero<8&&numero>=0)
    coupCavalier.push_back(temp);
    return coupCavalier;
}
