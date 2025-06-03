#include <iostream>
#include "Echiquier.hpp"

Echiquier::Echiquier()
{
    this->_plateau[0][0] = 'T';
    this->_plateau[7][0] = 'T';
    this->_plateau[0][7] = 't';
    this->_plateau[7][7] = 't';
    this->_plateau[1][0] = 'C';
    this->_plateau[6][0] = 'C';
    this->_plateau[1][7] = 'c';
    this->_plateau[6][7] = 'c';
    this->_plateau[2][0] = 'F';
    this->_plateau[5][0] = 'F';
    this->_plateau[2][7] = 'f';
    this->_plateau[5][7] = 'f';
    this->_plateau[3][0] = 'D';
    this->_plateau[4][0] = 'R';
    this->_plateau[3][7] = 'd';
    this->_plateau[4][7] = 'r';
    for(int i=0;i<8;i++){
        this->_plateau[i][1] = 'P';
        this->_plateau[i][6] = 'p';
        for(int j=2;j<6;j++){
            this->_plateau[i][j] = 'v';
        }
    }
}

char Echiquier::getCase(int lettre, int numero)
{
    return this->_plateau[lettre][numero];
}

void Echiquier::printEchiquier() const
{
    for(int i=7;i>=0;i--){
        for(int j=0; j<8; j++){
            std::cout<<this->_plateau[j][i];
        }
        std::cout<<std::endl;
    }
}
