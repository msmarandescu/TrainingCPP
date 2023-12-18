#pragma once

#include "Automobil.h"

class Mercedes:Automobil
{
private:
    string* Suspensie;
public:
    Mercedes( string combustibil, string caroserie, string tractiune, int putere, string echipare, string vinNr, string suspensie); //parameterized constructor

    Mercedes (const Mercedes &obj); // copy Constructor

    Mercedes& operator=(const Mercedes &obj); // Copy assignment operator

    ~Mercedes();
    
    const void PrintDetail()const;
    void setSuspensie(string s);
};

