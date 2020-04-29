#ifndef MATRICE_PATRATICA_H
#define MATRICE_PATRATICA_H

#include <iostream>
#include <Matrice.h>


class Matrice_patratica: public Matrice
{
protected:
    int dim;
public:
    Matrice_patratica();
    Matrice_patratica(int d);
    Matrice_patratica(const Matrice_patratica &ob);
    ~Matrice_patratica();

    void set_dim(int a);
    int get_dim();
    istream& citire(istream&);
    ostream& afisare(ostream&) const;

    friend istream& operator>>(istream&, Matrice_patratica&);
    friend ostream& operator<<(ostream&, const Matrice_patratica&);
    Matrice_patratica& operator=(const Matrice_patratica&);

    bool Matrice_Triunghiulara_Diagonala(int dim, Complex **v);
    Complex determinant(int dim, Complex **v);
};

#endif // MATRICE_PATRATICA_H
