#pragma once

#include <memory>
#include <iostream>
using namespace std;


enum CombustibilType { benzina, motorina, hibrid, electric };
enum CaroserieType { hatchback, combi, SUV, berlina, sedan };
enum TractiuneType { fata, spate, integrala };
enum EchipareType { standard, extended, full };

class Automobil
{
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
    
    ~Automobil(); //Distructor

    const void PrintDetail()const; //Print all the Automobil class atributs
};
