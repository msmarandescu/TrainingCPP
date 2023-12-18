#pragma once

#include "Automobil.h"
using namespace std;


class Audi:Automobil
{
private:
    string* Marca;
    string* Model;
  
public:
    Audi( string combustibil, string caroserie, string tractiune, int putere, string echipare, string vinNr, string marca, string model); //parameterized constructor

    ~Audi(); //Distructor

    const void PrintDetail()const;
    const void printNrOfObjects()const;
};
