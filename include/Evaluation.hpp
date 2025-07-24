#ifndef EVALUATION_HPP
#define EVALUATION_HPP

#include"Echiquier.hpp"
#include "CoupLegaux.hpp";

class Evaluation{
CoupLegaux _coupLegaux;
Echiquier _echiquier;
float _avantage;

void _materielBrute();
void _verifRoi();
void _coupPossible();
float _controleDuCentre();
int _pieceTotal();

public:
Evaluation();

void calculAvantage(bool couleur);
};

#endif