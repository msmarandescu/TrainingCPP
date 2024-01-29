#pragma once

#include "Automobil.h"
using namespace std;


class Audi:Automobil
{
private:
    std::unique_ptr<std::string> Marca;
    std::unique_ptr<std::string> Model;
  
public:
    Audi( string combustibil, string caroserie, string tractiune, int putere, string echipare, string vinNr, string marca, string model); //parameterized constructor

    Audi (const Audi &obj); // copy Constructor

    Audi& operator=(const Audi &obj); //copy assignment operator

    Audi (Audi &&obj)noexcept; //move constructor

    Audi& operator=(Audi &&obj); //move assignment operator

    ~Audi(); //Distructor

    const void PrintDetail()const;
    const void printNrOfObjects()const;
};
