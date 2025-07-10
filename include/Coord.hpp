#ifndef COORD_H
#define COORD_H

struct Coord{
    int lettre;
    int numero;

    constexpr bool estValide(Coord coordonnee){
        return (coordonnee.lettre < 8 &&
                coordonnee.lettre >= 0 &&
                coordonnee.numero < 8 &&
                coordonnee.numero >= 0);
    }
};

#endif