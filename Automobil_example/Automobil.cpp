#include "Automobil.h"
#include <string.h>


Automobil::Automobil(std::string combustibil, std::string caroserie,
                     std::string tractiune, int putere,
                     std::string echipare, std::string vinNr)
    : Combustibil(std::make_unique<std::string>(std::move(combustibil))),
      Caroserie(std::make_unique<std::string>(std::move(caroserie))),
      Tractiune(std::make_unique<std::string>(std::move(tractiune))),
      Putere(std::make_unique<int>(putere)),
      Echipare(std::make_unique<std::string>(std::move(echipare))),
      VIN_NR(std::make_unique<std::string>(std::move(vinNr)))
{
    std::cout << "Automobil()" << std::endl;
}

Automobil::Automobil(const Automobil &obj) //copy constructor
{
    std::cout << "Automobil(copy constructor)" << std::endl;
    Combustibil = std::make_unique<std::string>(*obj.Combustibil);
    Caroserie = std::make_unique<std::string>(*obj.Caroserie);
    Tractiune = std::make_unique<std::string>(*obj.Tractiune);
    Putere = std::make_unique<int>(*obj.Putere);
    Echipare = std::make_unique<std::string>(*obj.Echipare);
    VIN_NR = std::make_unique<std::string>(*obj.VIN_NR);
}

Automobil& Automobil::operator=(const Automobil &obj) // Copy assignment operator
{
    std::cout << "Automobil(Copy assignment operator)" << std::endl;
    if(this != &obj)
    {    
        Combustibil = std::make_unique<std::string>(*obj.Combustibil);
        Caroserie = std::make_unique<std::string>(*obj.Caroserie);
        Tractiune = std::make_unique<std::string>(*obj.Tractiune);
        Putere = std::make_unique<int>(*obj.Putere);
        Echipare = std::make_unique<std::string>(*obj.Echipare);
        VIN_NR = std::make_unique<std::string>(*obj.VIN_NR);
    }
    return *this;
}

Automobil::Automobil(Automobil &&obj) noexcept
    : Combustibil(std::move(obj.Combustibil)),
      Caroserie(std::move(obj.Caroserie)),
      Tractiune(std::move(obj.Tractiune)),
      Putere(std::move(obj.Putere)),
      Echipare(std::move(obj.Echipare)),
      VIN_NR(std::move(obj.VIN_NR))
{
    std::cout << "Automobil(move constructor)" << std::endl;
}

Automobil& Automobil::operator=( Automobil &&obj) // move assignment operator
{
    std::cout << "Automobil(move assignment operator)" << std::endl;
    if(this != &obj)
    {
        Combustibil = std::move(obj.Combustibil);
        Caroserie = std::move(obj.Caroserie);
        Tractiune = std::move(obj.Tractiune);
        Putere = std::move(obj.Putere);
        Echipare = std::move(obj.Echipare);
        VIN_NR = std::move(obj.VIN_NR);
    }
    return *this;
}

Automobil::~Automobil()
{
    std::cout << "~Automobil()" << std::endl;
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