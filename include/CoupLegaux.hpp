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
std::vector<std::tuple<std::pair<int, int>, int, char>> _coupParPiece;

public:
CoupLegaux();
void allCoupLegaux();

std::vector<std::pair<int, int>> getCoupCavalier(int, int, char) const;
std::vector<std::pair<int, int>> getCoupTour(int, int, char) const;
std::vector<std::pair<int, int>> getCoupFou(int, int, char) const;
std::vector<std::pair<int, int>> getCoupDame(int, int, char) const;
std::vector<std::pair<int, int>> getCoupRoi(int, int, char) const;
std::vector<std::pair<int, int>> getCoupPion(int, int, char) const;
};

#endif