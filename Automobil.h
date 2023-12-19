#pragma once

#include <memory>
#include <iostream>
using namespace std;


class Automobil
{
protected:
    string* Combustibil;
    string* Caroserie;
    string* Tractiune;
    int* Putere;
    string* Echipare;
    string* VIN_NR;
    
public:
    Automobil( string combustibil, string caroserie,
               string tractiune, int putere,
               string echipare, string vinNr ); //parameterized constructor

    Automobil (const Automobil &obj); // copy Constructor

    Automobil& operator=(const Automobil &obj); // Copy assignment operator

    Automobil (Automobil &&obj)noexcept; // move constructor

    Automobil& operator=(Automobil &&obj); // move assignment operator

    ~Automobil(); //Distructor

    const void PrintDetail()const; //Print all the Automobil class atributs
};
