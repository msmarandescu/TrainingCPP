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

Automobil::Automobil(const Automobil &obj) //copy constructor
{
    std::cout << "Automobil(copy constructor)" << std::endl;
    Caroserie = new string(*obj.Caroserie);
    Combustibil = new string(*obj.Combustibil);
    Tractiune = new string(*obj.Tractiune);
    Putere = new int(*obj.Putere);
    Echipare = new string(*obj.Echipare);
    VIN_NR = new string(*obj.VIN_NR);
}

Automobil& Automobil::operator=(const Automobil &obj) // Copy assignment operator
{
    std::cout << "Automobil(Copy assignment operator)" << std::endl;
    if(this != &obj)
    {    
        delete Caroserie;
        delete Combustibil;
        delete Tractiune;
        delete Putere;
        delete Echipare;
        delete VIN_NR;

        Caroserie = new string(*obj.Caroserie);
        Combustibil = new string(*obj.Combustibil);
        Tractiune = new string(*obj.Tractiune);
        Putere = new int(*obj.Putere);
        Echipare = new string(*obj.Echipare);
        VIN_NR = new string(*obj.VIN_NR);
    }
    return *this;
}

Automobil::Automobil (Automobil &&obj) noexcept// move constructor
{
    std::cout << "Automobil(move constructor)" << std::endl;
    Combustibil = obj.Combustibil;
    Caroserie = obj.Caroserie;
    Tractiune = obj.Tractiune;
    Putere = obj.Putere;
    Echipare = obj.Echipare;
    VIN_NR = obj.VIN_NR;

    obj.Combustibil = nullptr;
    obj.Caroserie = nullptr;
    obj.Tractiune = nullptr;
    obj.Putere = nullptr;
    obj.Echipare = nullptr;
    obj.VIN_NR = nullptr;
}

Automobil& Automobil::operator=( Automobil &&obj) // move assignment operator
{
    std::cout << "Automobil(move assignment operator)" << std::endl;
    if(this != &obj)
    {
        delete Caroserie;
        delete Combustibil;
        delete Tractiune;
        delete Putere;
        delete Echipare;
        delete VIN_NR;

        Combustibil = obj.Combustibil;
        Caroserie = obj.Caroserie;
        Tractiune = obj.Tractiune;
        Putere = obj.Putere;
        Echipare = obj.Echipare;
        VIN_NR = obj.VIN_NR;

        obj.Combustibil = nullptr;
        obj.Caroserie = nullptr;
        obj.Tractiune = nullptr;
        obj.Putere = nullptr;
        obj.Echipare = nullptr;
        obj.VIN_NR = nullptr;
    }
    return *this;
}

Automobil::~Automobil()
{
    std::cout << "~Automobil()" << std::endl;
    delete Combustibil;
    delete Caroserie;
    delete Tractiune;
    delete Putere;
    delete Echipare;
    delete VIN_NR;
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