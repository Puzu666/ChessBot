#ifndef COORD_H
#define COORD_H
#include <cassert>

struct Coord{
    int lettre;
    int numero;

    constexpr bool estValide() const{
        return (this->lettre < 8 &&
                this->lettre >= 0 &&
                this->numero < 8 &&
                this->numero >= 0);
    }

    Coord operator+(const Coord& coordonnee){
        Coord coordTemp = {
        this->lettre + coordonnee.lettre,
        this->numero + coordonnee.numero
        };

        assert(coordTemp.estValide());

        return coordTemp;
    }
};

#endif