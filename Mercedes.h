#pragma once

#include "Automobil.h"

class Mercedes:Automobil
{
private:
    string* Suspensie;
public:
    Mercedes( string combustibil, string caroserie, string tractiune, int putere, string echipare, string vinNr, string suspensie); //parameterized constructor

    ~Mercedes();
    
    const void PrintDetail()const;
};

