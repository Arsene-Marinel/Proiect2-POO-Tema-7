#include "Matrice_patratica.h"
#include <iostream>
#include <Complex.h>
#include <Matrice.h>
#include <dimensiune.h>
using namespace std;

Matrice_patratica::Matrice_patratica(): Matrice()
{
    dim = 0;
}

Matrice_patratica::Matrice_patratica(int d): Matrice(d, d)
{
    cout << "Clasa baza\n";
}

Matrice_patratica::Matrice_patratica(const Matrice_patratica& ob)
{
    dim = ob.dim;
    v = new Complex*[dim];
    for(int i = 0; i < dim; i++)
    {
        v[i] = new Complex[dim];
        for(int j = 0; j < dim; j++)
            v[i][j] = ob.v[i][j];
    }

}

Matrice_patratica::~Matrice_patratica()
{
    for(int i = 0; i < dim; i++)
        delete[] v[i];
    delete[] v;
}

void Matrice_patratica::set_dim(int a)
{
    dim = a;
}

int Matrice_patratica::get_dim()
{
    return dim;
}

istream& Matrice_patratica::citire(istream& in)
{
    if(v != NULL)
    {
        for(int i = 0; i < dim; i++)
            delete[] v[i];
        delete[] v;
    }

    try
    {
        cout << "Dimensiune: ";
        in >> dim;
        if(dim <=0)
            throw dimensiune();
    }
    catch(dimensiune x)
    {
        cout << x.what();
        in >> dim;
        while(dim <= 0)
            in >> dim;
    }

    v = new Complex*[dim];
    for(int i = 0; i < dim; i++)
        v[i] = new Complex[dim];

    for(int i = 0; i < dim; i++)
        for(int j = 0; j < dim; j++)
            in >> v[i][j];
    return in;
}

ostream& Matrice_patratica::afisare(ostream& out) const
{
    if(dim == 0)
    {
        out << "Matrice nula\n";
        return out;
    }
    for(int i = 0; i <dim; i++) //daca e nenula, parcurge matricea si o afiseaza
    {
        for(int j = 0; j < dim; j++)
            out << v[i][j] << ' ';
        out << '\n';
    }
    return out;
}

istream& operator>>(istream& in, Matrice_patratica& M)
{
    return M.citire(in);
}

ostream& operator<<(ostream& out, const Matrice_patratica& M)
{

    return M.afisare(out);
}

Matrice_patratica& Matrice_patratica::operator=(const Matrice_patratica& M)
{
    if(this != NULL)           ///daca este nenula, dezaloca memoria
    {
        for(int i = 0; i < dim; i++)
            delete[] v[i];
        delete[] v;
    }

    dim = M.dim;
    v = new Complex*[dim];
    for(int i = 0; i < dim; i++)
        v[i] = new Complex[dim];

    for(int i = 0; i < dim; i++)
        for(int j = 0; j < dim; j++)
            v[i][j] = M.v[i][j];
    return *this;
}

bool Matrice_patratica::Matrice_Triunghiulara_Diagonala(int dim, Complex **v)
{
    Complex zero(0,0);
    for(int i = 0; i < dim ; i++)
        for(int j = 0; j < i; j++)
            if(v[i][j] != zero)
                return 0;
    return 1;
}

Complex Matrice_patratica::determinant(int dim, Complex **v)
{
    Complex det(0, 0);
    if (dim == 2)
    {
        return v[0][0] * v[1][1] - v[0][1] * v[1][0];
    }
    for (int i = 0; i < dim; i++)
    {
        int x = 0, y = 0;
        Complex **B;
        B = new Complex*[dim - 1];
        for (int j = 0; j < dim - 1; j++)
            B[j] = new Complex[dim - 1];
        for (int j = 0; j < dim; j++)
            for (int k = 0; k < dim; k++)
                if (j != 0 && k != i)
                {
                    B[x][y] = v[j][k];
                    if (y < dim - 2)
                        y++;
                    else
                    {
                        x++;
                        y = 0;
                    }
                }
        if (i % 2 == 0)
            det = det + v[0][i] * determinant(dim - 1, B);
        else
            det = det - v[0][i] * determinant(dim - 1, B);
    }
    return det;
}
