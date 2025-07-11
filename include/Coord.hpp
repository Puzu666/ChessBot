#ifndef COORD_H
#define COORD_H
#include <cassert>

struct Coord{
    int lettre;
    int numero;

    constexpr bool estValide(Coord coordonnee){
        return (coordonnee.lettre < 8 &&
                coordonnee.lettre >= 0 &&
                coordonnee.numero < 8 &&
                coordonnee.numero >= 0);
    }

    constexpr Coord operator+(const Coord& coordonnee) const{
        Coord coordTemp = {
        this->lettre + coordonnee.lettre,
        this->numero + coordonnee.numero
        };

        assert(estValide(coordTemp));

        return coordTemp;
    }
};

#endif