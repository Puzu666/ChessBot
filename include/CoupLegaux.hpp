#ifndef COUPLEGAUX_HPP
#define COUPLEGAUX_HPP
#include <vector>
#include <array>
#include "Echiquier.hpp"

class CoupLegaux{
private:
Echiquier _echiquier;
std::vector<std::array<int,2>> _coupLegauxBlanc;
std::vector<std::array<int,2>> _coupLegauxNoir;

public:
CoupLegaux();
void allCoupLegaux();
std::vector<std::array<int, 2>> getCoupCavalier(int,int) const;
};

#endif