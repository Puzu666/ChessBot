#ifndef PIECE_HPP
#define PIECE_HPP

struct Piece{
    enum class Type {
    VIDE = 0x0001, // 0
    PION_BLANC, 
    CAVALIER_BLANC,
    FOU_BLANC,
    TOUR_BLANC,
    ROI_BLANC,
    DAME_BLANC,
    PION_NOIR = 0b1000, // 8
    CAVALIER_NOIR,
    FOU_NOIR,
    TOUR_NOIR,
    ROI_NOIR,
    DAME_NOIR,
    };
    // la ligne d'après est idéale mais c'est du c++20. va changer ton CMake si tu veux que ça marche
    //using enum Type;
    Type type;

    // si le 8e bit est à 1, alors c'est noir
    constexpr bool couleur() { return bool(int(this->type) & 8); }

    constexpr bool estMemeCouleur(Piece piece) {
      return (this->couleur() == piece.couleur());
    }
};

#endif