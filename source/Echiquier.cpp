#include <iostream>
#include "Echiquier.hpp"

Echiquier::Echiquier()
{
}

bool Echiquier::move(char piece, int lettreInitial, int numeroInitial, int lettreFinal, int numeroFinal)
{
    if(this->_plateau[lettreInitial][numeroInitial]==piece){
        this->_plateau[lettreInitial][numeroInitial]='v';
        this->_plateau[lettreFinal][numeroFinal]==piece;
        return true;
    }
    return false;
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
