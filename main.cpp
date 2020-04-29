/**
Tema 7. matrice de numere complexe reprezentate ca tablouri bidimensionale Se dau urmatoarele clase:
    - Clasa Complex(float,float)
    - Matrice( Complex **v) – clasa abstracta
    - Matrice_oarecare (int lin, int col) : Matrice
    - Matrice_patratica (int dim): Matrice
Clasele derivate trebuie sa contina metoda care sa verifice daca o matrice triunghiulara este diagonala. Pentru matricile patratice,
functia de afisare sa conțină și determinantul acestora.
*/




#include <iostream>
#include <Complex.h>
#include <Matrice.h>
#include <Matrice_oarecare.h>
#include <Matrice_patratica.h>
using namespace std;

int main()
{
    Complex z(1, 2), z1;
    z1 = z;
    cout << z1;

    Matrice_patratica dim(2);
    Matrice_patratica *p = new Matrice_patratica;
    *p = dim;
    p->afisare(cout);
    return 0;
}
