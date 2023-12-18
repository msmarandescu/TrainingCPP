#include "Automobil.h"
#include <string.h>


Automobil::Automobil( string combustibil, string caroserie, 
                      string tractiune,   int putere,
                      string echipare,    string vinNr)//parameterized constructor
{
    std::cout << "Automobil()" << std::endl;
    Combustibil = new string (combustibil);
    Caroserie = new string (caroserie);
    Tractiune = new string (tractiune);
    Putere = new int (putere);
    Echipare = new string(echipare);
    VIN_NR = new string(vinNr);
}

Automobil::~Automobil()
{
    std::cout << "~Automobil()" << std::endl;
    delete Combustibil;
    Combustibil = nullptr;
    delete Caroserie;
    Caroserie = nullptr;
    delete Tractiune;
    Tractiune = nullptr;
    delete Putere;
    Putere = nullptr;
    delete Echipare;
    Echipare = nullptr;
    delete VIN_NR;
    VIN_NR = nullptr;
}

const void Automobil::PrintDetail()const
{
    using namespace std;
    cout << "Tip combustibil: " << *Combustibil << endl;
    cout << "Tip Caroserie: "   << *Caroserie   << endl;
    cout << "Tractiune: "       << *Tractiune   << endl;
    cout << "Putere: "          << *Putere      << endl;
    cout << "Tip echipare: "    << *Echipare    << endl;
    cout << "VIN Number: "      << *VIN_NR      << endl;
}