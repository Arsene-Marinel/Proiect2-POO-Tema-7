#include "Matrice.h"

#include <iostream>
#include <Complex.h>
using namespace std;

Matrice::Matrice()        ///constructor de initializare
{
    v = NULL;
}

Matrice::Matrice(int lin, int col)       ///constructor de initializare cu parametri
{
    v = new Complex*[lin];
    for(int i = 0; i < lin; i++)
    {
        v[i] = new Complex[col];
        for(int j = 0; j < col; j++)
            cin >> this->v[i][j];
    }
    for(int i = 0; i < lin; i++)
    {
        for(int j = 0; j < col; j++)
            cout << this->v[i][j] << ' ';
        cout << '\n';
    }
}

Matrice::~Matrice()
{
    cout << "Matrice a fost disptrusa/n";
}
