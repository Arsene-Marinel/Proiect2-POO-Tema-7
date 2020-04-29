#ifndef DIMENSIUNE_H
#define DIMENSIUNE_H
#include <iostream>
using namespace std;

class dimensiune: public exception
{
public:
    const char* what()
    {
        return "Dimensiunea trebuie sa fie numar intreg pozitiv\n";
    }
};

#endif // DIMENSIUNE_H
