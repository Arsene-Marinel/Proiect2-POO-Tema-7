#ifndef MATRICE_H
#define MATRICE_H

#include <Complex.h>


class Matrice     ///clasa abstracta ce reprezinta multimea tuturor matricelor de numere complexe
{
protected:
    Complex **v;
public:
    Matrice();
    Matrice(int lin, int col);
    virtual ~Matrice();

    virtual istream& citire(istream&) = 0;               ///functie de citire pur virtuala
    virtual ostream& afisare(ostream&) const = 0;        ///functie de afisare pur virtuala

    bool Matrice_Triunghiulara_Diagonala();
};

#endif // MATRICE_H
