#include <iostream>
#include "Echiquier.hpp"

Echiquier::Echiquier()
{
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
