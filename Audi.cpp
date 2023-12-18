#include "Audi.h"


Audi::Audi( string combustibil, string caroserie, string tractiune, int putere, string echipare, string vinNr, string marca, string model) //parameterized constructor
              :Automobil(combustibil, caroserie, tractiune, putere, echipare, vinNr)
{
    std::cout << "Audi()" << std::endl;
    Marca = new string(marca);
    Model = new string(model);

}

Audi::~Audi()
{
    std::cout << "~Audi()" << std::endl;
    delete Marca;
    Marca = nullptr;
    delete Model;
    Model = nullptr;
}

const void Audi::PrintDetail()const
{
    Automobil::PrintDetail();
    std::cout << "Marca: " <<  *Marca << std::endl;
    std::cout << "Model: " <<  *Model << std::endl;
}