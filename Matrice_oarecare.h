#ifndef MATRICE_OARECARE_H
#define MATRICE_OARECARE_H

#include <Matrice.h>

class Matrice_oarecare: public Matrice
{
protected:
    int lin, col;
public:
    Matrice_oarecare();
    Matrice_oarecare(int n, int m);
    Matrice_oarecare(const Matrice_oarecare &ob); ///Constructor de copiere
    ~Matrice_oarecare();

    void set_dimensiune(int n, int m);
    int get_lin();
    int get_col();

    istream& citire(istream&);           ///citeste o matrice oarecare
    ostream& afisare(ostream&) const;    ///afiseaza o matrice oarecare

    friend istream& operator>>(istream&, Matrice_oarecare&);
    friend ostream& operator<<(ostream&, const Matrice_oarecare&);

    Matrice_oarecare& operator=(const Matrice_oarecare &z);

    bool Matrice_Triunghiulara_Diagonala(int lin, Complex **v);
};

#endif // MATRICE_OARECARE_H
