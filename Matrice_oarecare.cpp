#include "Matrice_oarecare.h"

#include <iostream>
#include <Matrice.h>
#include <Complex.h>
using namespace std;

Matrice_oarecare::Matrice_oarecare():Matrice()    ///constructor de initializare ce apeleaza constr din clasa de baza
{
    lin = 0;
    col = 0;
}

Matrice_oarecare::Matrice_oarecare(int n, int m)
{
    Complex z;
    z.set_Complex(0,0);
    lin = n;
    col = m;
    v = new Complex*[lin];
    for (int i = 0; i < lin; i++)
        v[i] = new Complex[col];

    for(int i = 0; i < lin; i++)
        for(int j = 0; j < col; j++)
            v[i][j] = z;

}

Matrice_oarecare::Matrice_oarecare(const Matrice_oarecare &ob)
{
    lin = ob.lin;
    col = ob.col;

    v = new Complex*[lin];
    for (int i = 0; i < lin; i++)
        v[i] = new Complex[col];

    for(int i =0 ; i < lin; i++)
        for(int j = 0; j < col; j++)
            v[i][j] = ob.v[i][j];
}

Matrice_oarecare::~Matrice_oarecare()
{
    for(int i = 0; i < lin; i++)
        delete v[i];
    delete v;

}

void Matrice_oarecare::set_dimensiune(int n, int m)
{
    lin = n;
    col = m;
}

int Matrice_oarecare::get_lin()
{
    return lin;
}

int Matrice_oarecare::get_col()
{
    return col;
}

istream& Matrice_oarecare::citire(istream& in)
{
    if(v != NULL)           ///daca este nenula o sterge
    {
        for(int i = 0; i < lin; i++)
            delete[] v[i];
        delete[] v;
    }
    cout << "Nr linii si coloane:\n";
    in >> lin>> col;

    v = new Complex*[lin];
    for(int i = 0; i < lin; i++)      ///aloc memorie
        v[i] = new Complex[col];

    for(int i = 0; i < lin; i++)
        for(int j = 0; j < col; j++)
            in >> v[i][j];
    return in;
}

ostream& Matrice_oarecare::afisare(ostream& out) const
{
    if(lin == 0)
    {
        out << "Matrice nula\n";
        return out;
    }
    for(int i = 0; i < lin; i++)
    {
        for(int j = 0; j < col; j++)
            out << v[i][j] <<' ';
        out<<'\n';
    }
    return out;
}

istream& operator>>(istream& in, Matrice_oarecare& M)
{
    return M.citire(in);
}

ostream& operator<<(ostream& out, const Matrice_oarecare &M)
{
    return M.afisare(out);
}

Matrice_oarecare& Matrice_oarecare::operator=(const Matrice_oarecare &z)
{
    if(this != NULL)         ///daca este nenula o sterge
    {
        for(int i=0; i < lin; i++)
            delete[] v[i];
        delete[] v;
    }

    lin = z.lin;
    col = z.col;

    v = new Complex*[lin];
    for (int i = 0; i < lin; i++)
        v[i] = new Complex[col];

    for(int i =0 ; i < lin; i++)
        for(int j = 0; j < col; j++)
            v[i][j] = z.v[i][j];
    return *this;
}

bool Matrice_oarecare::Matrice_Triunghiulara_Diagonala(int lin, Complex **v)
{
    Complex zero(0,0);
    for(int i = 0; i < lin ; i++)
        for(int j = 0; j < i; j++)
            if(v[i][j] != zero)
                return 0;
    return 1;
}
