#pragma once

#include <memory>
#include <iostream>
using namespace std;


class Automobil
{
protected:
    std::unique_ptr<std::string> Combustibil;
    std::unique_ptr<std::string> Caroserie;
    std::unique_ptr<std::string> Tractiune;
    std::unique_ptr<int> Putere;
    std::unique_ptr<std::string> Echipare;
    std::unique_ptr<std::string> VIN_NR;
    
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
