#include "Audi.h"

static int objNr = 0;

Audi::Audi( string combustibil, string caroserie, string tractiune, int putere, string echipare, string vinNr, string marca, string model) //parameterized constructor
              :Automobil(combustibil, caroserie, tractiune, putere, echipare, vinNr)
{
    // std::cout << "Audi()" << std::endl;
    if(objNr < 1)
    {
        std::cout << "Audi()" << std::endl;
        Marca = new string(marca);
        Model = new string(model);
        objNr++;
    }else
    {
         throw string("Error: Audi class can have only one obj created!");
    }
}

Audi::~Audi()
{
    std::cout << "~Audi()" << std::endl;
    delete Marca;
    Marca = nullptr;
    delete Model;
    Model = nullptr;
    objNr--;
}

const void Audi::PrintDetail()const
{
    Automobil::PrintDetail();
    std::cout << "Marca: " <<  *Marca << std::endl;
    std::cout << "Model: " <<  *Model << std::endl;
}

const void Audi::printNrOfObjects()const{
    cout << "Number of objects of type Audi :" << objNr;
}