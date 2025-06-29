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
std::vector<std::tuple<std::pair<int, int>, int, char>> _coupParPieceBlanc;
std::vector<std::tuple<std::pair<int, int>, int, char>> _coupParPieceNoir;
std::tuple<std::pair<int, int>, std::pair<int, int>, char, bool> _dernierCoup;

public:
CoupLegaux();
void allCoupLegaux(bool);
void getCoupPiece(int, int, char);

std::vector<std::pair<int, int>> getCoupCavalier(int, int, char) const;
std::vector<std::pair<int, int>> getCoupTour(int, int, char) const;
std::vector<std::pair<int, int>> getCoupFou(int, int, char) const;
std::vector<std::pair<int, int>> getCoupDame(int, int, char) const;
std::vector<std::pair<int, int>> getCoupRoi(int, int, char) const;
std::vector<std::pair<int, int>> getCoupPion(int, int, char) const;

void move(int index, char couleur);
};

#endif