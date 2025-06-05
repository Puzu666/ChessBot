#ifndef COUPLEGAUX_HPP
#define COUPLEGAUX_HPP
#include <vector>
#include <array>
#include "Echiquier.hpp"

class CoupLegaux{
private:
Echiquier _echiquier;
std::vector<std::pair<int, int>> _coupLegauxBlanc;
std::vector<std::pair<int, int>> _coupLegauxNoir;

public:
CoupLegaux();
void allCoupLegaux();
std::vector<std::pair<int, int>> getCoupCavalier(int,int) const;
std::vector<std::pair<int, int>> getCoupTour(int, int) const;
std::vector<std::pair<int, int>> getCoupFou(int, int) const;
};

#endif