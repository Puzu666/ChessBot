#include <iostream>
#include "Echiquier.hpp"
#include "CoupLegaux.hpp"

int main(){
    CoupLegaux cl;
    cl.allCoupLegaux();

    int test = cl.getLettrePremCoup();

    std::cout << test;
}