#pragma once

#include "Automobil.h"

class Mercedes:Automobil
{
private:
    std::unique_ptr<std::string> Suspensie;
public:
    Mercedes( string combustibil, string caroserie, string tractiune, int putere, string echipare, string vinNr, string suspensie); //parameterized constructor

    Mercedes (const Mercedes &obj); // copy Constructor

    Mercedes& operator=(const Mercedes &obj); // Copy assignment operator

    Mercedes (Mercedes &&obj)noexcept; //move constructor

    Mercedes& operator=(Mercedes &&obj); //move assignment operator

    ~Mercedes();
    
    const void PrintDetail()const;

    void setSuspensie(string s);
};

